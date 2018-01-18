#include "FileSystem.h"
#include <iostream>

using namespace std;

FileSystem::FileSystem()
{
	for (int i = 0; i<FOLDER_LIMIT; i++)
		for (int j = 0; j < FOLDERNAME_LIMIT; j++)
			this->foldername[i][j] = '\0';
	this->foldercount = 0;

	for (int i = 0; i<FOLDER_LIMIT; i++)
		for (int j = 0; j < FILE_LIMIT; j++)
			for (int k = 0; k < FILENAME_LIMIT; k++)
				this->filename[i][j][k] = '\0';
	for (int i = 0; i<FOLDER_LIMIT;i++)
		this->filecount[i] = 0;
}

FileSystem::~FileSystem()
{
}

char FileSystem::display()
{
	cout << "---------------------------" << endl;
	cout << "FILE SYSTEM" << endl;
	cout << "---------------------------" << endl;
	for (int i = 0; i < this->foldercount; i++){
		cout << "<FOLDER " << i << ": " << this->foldername[i] << ">" << endl;
		for (int j = 0; j < this->filecount[i]; j++)
			cout << this->filename[i][j] << endl;
		cout << "----------------" << endl;
	}
	cout << "n: create a new file" << endl;
	cout << "d: delete an existing file" << endl;
	cout << "r: rename an existing file" << endl;
	cout << "c: copy an existing file" << endl;
	cout << "m: move an existing file" << endl;
	cout << "s: search for an existing file" << endl;
	cout << "S: save the system" << endl;
	cout << "q: quit the system" << endl;
	cout << "---------------------------" << endl;
	cout << "enter an option:" << endl;
	char temp[100];
	cin.getline(temp,100);
	return temp[0];
}

void FileSystem::readFileSystem()
{
	char temp[FOLDERNAME_LIMIT] = { 0 };

	// Read the folderName
	FILE *fp = fopen("../folderName", "r");
	if (NULL == fp)
	{
		cout << "failed to open folderName." << endl;
		return;
	}

	int index = 0;
	while (!feof(fp) && index < FOLDER_LIMIT)
	{
		memset(temp, 0, sizeof(temp));
		fgets(temp, sizeof(temp) - 1, fp); // 包含了\n 
		cout << temp[0] << endl;
		if (strlen(temp) > 0 && temp[strlen(temp) - 1] == '\n')
			temp[strlen(temp) - 1] = '\0';
		memcpy(this->foldername[index], temp, sizeof(temp));
		index++;
		this->foldercount++;
	}
	fclose(fp);

	//
	for (int i = 0; i < this->foldercount; i++)
	{
		char folderfile[FOLDERNAME_LIMIT + 3] = "../";
		strcat(folderfile, this->foldername[i]);
		fp = fopen(folderfile, "r");
		if (NULL == fp)
		{
			cout << "failed to open folder: " << this->foldername[i] << endl;
			return;
		}

		for (int j = 0; j < FILE_LIMIT && !feof(fp); j++)
		{
			memset(temp, 0, sizeof(temp));
			fgets(temp, sizeof(temp) - 1, fp); // 包含了\n 
			if (strlen(temp) > 0 && temp[strlen(temp) - 1] == '\n')
				temp[strlen(temp) - 1] = '\0';
			memcpy(this->filename[i][j], temp, sizeof(temp));
			this->filecount[i]++;
		}
		fclose(fp);
	}
}


void FileSystem::createFile(char * sourcefolder, char * file)
{
	int folderindex = this->findfolderindex(sourcefolder);
	if (folderindex == -1){
		cout << "source folder " << sourcefolder << " doesn't exists." << endl;
		return;
	}

	int fileindex = this->findfileindex(folderindex, file);
	if (fileindex != -1){
		cout << "file " << file << " already exists." << endl;
		return;
	}
	
	if (this->filecount[folderindex] >= FILE_LIMIT){
		cout << "cannot create the file." << endl;
		return;
	}

	strcpy(this->filename[folderindex][this->filecount[folderindex]], file);
	this->filecount[folderindex]++;
	cout << "create the file success." << endl;
	return;
}

void FileSystem::deleteFile(char * sourcefolder, char * file)
{
	int folderindex = this->findfolderindex(sourcefolder);
	if (folderindex == -1) {
		cout << "source folder " << sourcefolder << " doesn't exists." << endl;
		return;
	}

	int fileindex = this->findfileindex(folderindex, file);
	if (fileindex == -1) {
		cout << "file " << file << "doesn't exists." << endl;
		return;
	}

	for (fileindex; fileindex < this->filecount[folderindex]-1; fileindex++)
		memcpy(this->filename[folderindex][fileindex], this->filename[folderindex][fileindex + 1], 
			sizeof(this->filename[folderindex][fileindex]));
	memset(this->filename[folderindex][fileindex], '\0', sizeof(this->filename[folderindex][fileindex]));
	this->filecount[folderindex]--;
	cout << "delete the file success." << endl;
	return;
}

void FileSystem::renameFile(char * sourcefolder, char * file, char * newfile)
{
	int folderindex = this->findfolderindex(sourcefolder);
	if (folderindex == -1) {
		cout << "source folder " << sourcefolder << " doesn't exists." << endl;
		return;
	}

	int fileindex = this->findfileindex(folderindex, file);
	if (fileindex == -1) {
		cout << "file " << file << "doesn't exists." << endl;
		return;
	}

	strcpy(this->filename[folderindex][fileindex], newfile);
	cout << "rename the file success." << endl;
	return;
}

void FileSystem::copyFile(char * sourcefolder, char * file, char * destfolder, char * newfile)
{
	int sourcefolderindex = this->findfolderindex(sourcefolder);
	if (sourcefolderindex == -1) {
		cout << "source folder " << sourcefolder << " doesn't exists." << endl;
		return;
	}

	int sourcefileindex = this->findfileindex(sourcefolderindex, file);
	if (sourcefileindex == -1) {
		cout << "source file " << file << "doesn't exists." << endl;
		return;
	}

	int destfolderindex = this->findfolderindex(destfolder);
	if (destfolderindex == -1) {
		cout << "destination folder " << destfolder << " doesn't exists." << endl;
		return;
	}

	int destfileindex = this->findfileindex(destfolderindex, newfile);
	if (destfileindex != -1) {
		cout << "destination file" << newfile << "already exists." << endl;
		return;
	}

	if (this->filecount[destfolderindex] >= FILE_LIMIT) {
		cout << "cannot copy the file." << endl;
		return;
	}

	strcpy(this->filename[destfolderindex][this->filecount[destfolderindex]], newfile);
	this->filecount[destfolderindex]++;

	cout << "copy the file success." << endl;
	return;
}

void FileSystem::moveFile(char * sourcefolder, char * file, char * destfolder, char * newfile)
{
	int sourcefolderindex = this->findfolderindex(sourcefolder);
	if (sourcefolderindex == -1) {
		cout << "source folder " << sourcefolder << " doesn't exists." << endl;
		return;
	}

	int sourcefileindex = this->findfileindex(sourcefolderindex, file);
	if (sourcefileindex == -1) {
		cout << "source file " << file << "doesn't exists." << endl;
		return;
	}

	int destfolderindex = this->findfolderindex(destfolder);
	if (destfolderindex == -1) {
		cout << "destination folder " << destfolder << " doesn't exists." << endl;
		return;
	}

	int destfileindex = this->findfileindex(destfolderindex, newfile);
	if (destfileindex != -1) {
		cout << "destination file" << newfile << "already exists." << endl;
		return;
	}

	if (this->filecount[destfolderindex] >= FILE_LIMIT) {
		cout << "cannot move the file." << endl;
		return;
	}

	strcpy(this->filename[destfolderindex][this->filecount[destfolderindex]], newfile);
	this->filecount[destfolderindex]++;

	for (sourcefileindex; sourcefileindex < this->filecount[sourcefolderindex] - 1; sourcefileindex++) {
		memcpy(this->filename[sourcefolderindex][sourcefileindex], this->filename[sourcefolderindex][sourcefileindex + 1],
			sizeof(this->filename[sourcefolderindex][sourcefileindex]));
	}
	memset(this->filename[sourcefolderindex][sourcefileindex], '\0',
		sizeof(this->filename[sourcefolderindex][sourcefileindex]));
	this->filecount[sourcefolderindex]--;
	cout << "move the file success." << endl;
	return;
}

void FileSystem::searchFile(char * query)
{
	for (int i = 0; i < this->foldercount; i++){
		for (int j = 0; j < this->filecount[i]; j++){
			if (this->contain(this->filename[i][j], query)) {
				cout << this->foldername[i] << ": " << this->filename[i][j] << endl;
			}
		}
	}
	return;
}

void FileSystem::saveFileSystem()
{
	char temp[FOLDERNAME_LIMIT] = { 0 };

	// Write the folderName
	FILE *fp = fopen("../folderName", "w");
	if (NULL == fp)
	{
		cout << "failed to open folderName." << endl;
		return;
	}

	for (int i = 0; i < this->foldercount; i++) {
		fputs(this->foldername[i], fp);
		if (i + 1 < this->foldercount) 
			fputs("\n", fp);
	}
	fclose(fp);
	
	// Write the files.
	for (int i = 0; i < this->foldercount; i++)
	{
		char folderfile[FOLDERNAME_LIMIT + 3] = "../";
		strcat(folderfile, this->foldername[i]);
		fp = fopen(folderfile, "w");
		if (NULL == fp)
		{
			cout << "failed to open folder: " << this->foldername[i] << endl;
			return;
		}

		for (int j = 0; j < this->filecount[i]; j++)
		{
			fputs(this->filename[i][j], fp);
			if (j + 1 < this->filecount[i])
				fputs("\n", fp);
		}
		fclose(fp);
	}
}

bool FileSystem::compare(char * str1, char * str2)
{
	if (strlen(str1) != strlen(str2))
		return false;
	for (int i = 0; i < strlen(str1); i++)
		if (str1[i] != str2[i])
			return false;
	return true;
}

bool FileSystem::contain(char * str, char * substr)
{
	int len1 = strlen(str);
	int len2 = strlen(substr);
	for (int m = 0; m < len1 - len2 + 1; m++) {
		for (int n = 0; n < len2; n++) {
			if (str[m + n] != substr[n]) break;
			if (n + 1 == len2) return true;
		}
	}
	return false;
}

int FileSystem::findfolderindex(char * folder)
{
	for (int i=0; i < this->foldercount; i++)
		if (this->compare(folder, this->foldername[i]))
			return i;
	return -1;
}

int FileSystem::findfileindex(int folderindex, char * file)
{
	for (int i=0; i < this->filecount[folderindex]; i++)
		if (this->compare(file, this->filename[folderindex][i]))
			return i;
	return -1;
}
