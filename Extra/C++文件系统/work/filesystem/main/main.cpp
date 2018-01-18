// main.cpp : 定义控制台应用程序的入口点。
//

#include "FileSystem.h"
#include <iostream>
using namespace std;

int main()
{
	FileSystem fs;
	fs.readFileSystem();

	char sfolder[100], file[100], dfolder[100], nfile[100];
	while (1) {
		switch (fs.display()) {
		case 'n':
			memset(sfolder, '\0', 100);
			memset(file, '\0', 100);
			cout << "Input the source folder:" << endl;
			cin >> sfolder;
			cout << "Input the file name:" << endl;
			cin >> file;
			fs.createFile(sfolder, file);
			break;
		case 'd':
			memset(sfolder, '\0', 100);
			memset(file, '\0', 100);
			cout << "Input the source folder:" << endl;
			cin >> sfolder;
			cout << "Input the file name:" << endl;
			cin >> file;
			fs.deleteFile(sfolder, file);
			break;
		case 'r':
			memset(sfolder, '\0', 100);
			memset(file, '\0', 100);
			memset(nfile, '\0', 100);
			cout << "Input the source folder:" << endl;
			cin >> sfolder;
			cout << "Input the file name:" << endl;
			cin >> file;
			cout << "Input the new file name:" << endl;
			cin >> nfile;
			fs.renameFile(sfolder, file, nfile);
			break;
		case 'c':
			memset(sfolder, '\0', 100);
			memset(file, '\0', 100);
			memset(dfolder, '\0', 100);
			memset(nfile, '\0', 100);
			cout << "Input the source folder:" << endl;
			cin >> sfolder;
			cout << "Input the file name:" << endl;
			cin >> file;
			cout << "Input the destination folder:" << endl;
			cin >> dfolder;
			cout << "Input the new file name:" << endl;
			cin >> nfile;
			fs.copyFile(sfolder, file, dfolder, nfile);
			break;
		case 'm':
			memset(sfolder, '\0', 100);
			memset(file, '\0', 100);
			memset(dfolder, '\0', 100);
			memset(nfile, '\0', 100);
			cout << "Input the source folder:" << endl;
			cin >> sfolder;
			cout << "Input the file name:" << endl;
			cin >> file;
			cout << "Input the destination folder:" << endl;
			cin >> dfolder;
			cout << "Input the new file name:" << endl;
			cin >> nfile;
			fs.moveFile(sfolder, file, dfolder, nfile);
			break;
		case 's':
			char query[100];
			cout << "Input the query:" << endl;
			cin >> query;
			fs.searchFile(query);
			break;
		case 'S':
			fs.saveFileSystem();
			break;
		case 'q':
			exit(0);
			break;
		}
		cout << "press enter to countinue." << endl;
		char temp[100];
		cin.getline(temp, 100);
		cin.getline(temp, 100);
	}
    return 0;
}

