#pragma once

#define FOLDER_LIMIT 100
#define FOLDERNAME_LIMIT 100
#define FILE_LIMIT 100
#define FILENAME_LIMIT 100

class FileSystem
{
public:
	FileSystem();
	~FileSystem();

	char display();
	void readFileSystem();

	void createFile(char *sourcefolder, char *file);
	void deleteFile(char *sourcefolder, char *file);
	void renameFile(char *sourcefolder, char *file, char *newfile);
	void copyFile(char *sourcefolder, char *file, char *destfolder, char *newfile);
	void moveFile(char *sourcefolder, char *file, char *destfolder, char *newfile);
	void searchFile(char *query);
	void saveFileSystem();

private:
	bool compare(char *str1, char *str2);
	bool contain(char *str, char *substr);
	int findfolderindex(char *folder);
	int findfileindex(int folderindex, char *file);

private:
	char foldername[FOLDER_LIMIT][FOLDERNAME_LIMIT];
	char filename[FOLDER_LIMIT][FILE_LIMIT][FILENAME_LIMIT];
	int foldercount;
	int filecount[FOLDER_LIMIT];
};

