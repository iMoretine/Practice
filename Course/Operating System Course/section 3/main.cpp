#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;

#define DirectoryFile 0x08
#define RegularFile 0x04
#define SystemFile 0x02
// #define ReadOnlyFile 0x01

enum OperationType
{
    READ,
    WRITE,
};

struct OpenFile
{
    string filename;
    char* dirEntry;
    // OperationType type;
    char readPosition;
    char readOffset;
    char writePosition;
    char writeOffset;
};

vector<OpenFile> OpenfileList;

int readDisk();
int saveDisk();
int init();

bool isFile(string filename);
bool isDirectory(string directory);

char bufferBlock[64] = {0};
void getBlock(int position); //char* length 64 bytes.
void setBlock(int position); //char* length 64 bytes.

int getFAT(int position);// return value.
void setFAT(int position, int value);

void displayFile(int position);

char* findDirectory(string directory); // return the directory entry, length 8 bytes.
char* findDirEntry(string filename);

int createfile(string filename, char length, char attribute);
int openfile(string filename);
int closefile(string filename);
char* readfile(string filename);
int writefile(string filename);
int deletefile(string filename);
int typefile(string filename);
int change(string filename);

int md(string filename);
int dir(string filename);
int rd(string filename);

char Disk[8192] = {0};

int readDisk()
{
    fstream fin;
    fin.open("disk.bin",ios::in | ios::binary);
    if(!fin)
    {
        ofstream fout;
        fout.open("disk.bin", ios::out | ios::binary);
        char t = 0;
        for(int i=0;i<8192;i++)
            fout.write((char*)&t, sizeof(char));
        fout.close();
    }
    else
    {
        //Exist.
        fin.seekg(0, ios::end);
        streampos pos = fin.tellg();
        if(pos != 8192)
        {
            cout<<"File Error."<<endl;
            return -1;
        }
    }
    fin.seekg(0, ios::beg);
    for(int i=0;i<8192;i++)
        fin.read((char*)&Disk[i], sizeof(char));
    fin.close();
    return 0;
}

int saveDisk()
{
    ofstream fout;
    fout.open("disk.bin", ios::out | ios::binary | ios::trunc);
    for(int i=0;i<8192;i++)
        fout.write((char*)&Disk[i], sizeof(char));
    fout.close();
    return 0;
}

int init()
{
    readDisk();
    if(Disk[0] == 0) // Not exist.
    {
        setFAT(0,-1); // Root directory
        int n = createfile("/FAT.sy",2,SystemFile);
    }
    saveDisk();
    return 0;
}

bool isFile(string filename)
{
    if(filename.size() < 7)
        return false;
    
    string tempString;
    tempString = filename.substr(filename.size()-6,filename.size());
    for(int i=0;i<=6;i++)
    {
        if(tempString[i] == '/')
            return false;
    }
    if(tempString[3] != '.')
        return false;
    return isDirectory(filename.substr(0,filename.size()-6));
}

bool isDirectory(string directory)
{
    for(int i=0;i<directory.size();i++)
    {
        if(i%4 == 0 )
        {
            if(directory[i] != '/')
                return false;
        }
        else
        {
            if(directory[i] == '.' || directory[i] == '/')
                return false;
        }
    }
    return true;
}

void getBlock(int position)
{
    for(int i=0;i<64;i++)
        bufferBlock[i] = Disk[position+i];
}

void setBlock(int position)
{
    for(int i=0;i<64;i++)
        Disk[position+i] = bufferBlock[i];
}

int getFAT(int position)
{
    return Disk[64 + position];
}

void setFAT(int position, int value)
{
    Disk[64 + position] = value;
}

void displayFile(int position = 0)
{
    getBlock(position);
    for(int i=0;i<64;i+=8)
    {
        if(bufferBlock[i+5] & DirectoryFile)
        {
            cout<<bufferBlock[i+0]<<bufferBlock[i+1]<<bufferBlock[i+2]<<" ";
            cout<<"[Directory] "<<endl;
            displayFile((int)bufferBlock[i+6]);
        }
        else if(bufferBlock[i])
        {
            cout<<bufferBlock[i+0]<<bufferBlock[i+1]<<bufferBlock[i+2]<<"."<<bufferBlock[i+3]<<bufferBlock[4]<<" ";
            switch(bufferBlock[i+5])
            {
                case SystemFile: cout<<"[System File] ";break;
                case RegularFile: cout<<"[Regular File] ";break;
            }
            cout<<"Size : "<<bufferBlock[i+7]*64<<"B"<<endl;
        }
    }
    cout<<endl;
}

char* findDirectory(string directory)
{
    if(!isDirectory(directory))
        return NULL;

    vector<string> namelist;
    string tempname;
    for(int i=1;i<directory.size();i++)
    {
        if(directory[i] != '/')
            tempname.push_back(directory[i]);
        else
        {
            namelist.push_back(tempname);
            tempname.resize(0);
        }
    }

    int currentBlock = 0;
    int lastBlock = 0;
    int position = 0;
    string temp;
    for(int i=0;i<namelist.size();i++)
    {
        getBlock(currentBlock);
        for(int j=0;j<64;j+=8)
        {
            temp.push_back(bufferBlock[j]);
            temp.push_back(bufferBlock[j+1]);
            temp.push_back(bufferBlock[j+2]);
            if(temp == namelist[i])
            {
                lastBlock = currentBlock;
                currentBlock = (int)bufferBlock[j+6];
                position = lastBlock*64 + j;
            }
        }
        if(lastBlock == currentBlock)
            return NULL;
    }
    return &Disk[position];
}

char* findDirEntry(string filename)
{
    if(!isFile(filename))
        return NULL;
    char *temp = findDirectory(filename.substr(0,filename.size()-6));
    if(temp == NULL)
        return NULL;

    string name = filename.substr(filename.size()-6,filename.size());
    for(int i=0;i<8;i++)
    {
        if(temp[i*8] == name[0]
            && temp[i*8+1] == name[1]
            && temp[i*8+2] == name[2]
            && temp[i*8+3] == name[4]
            && temp[i*8+4] == name[5])
            return &temp[i*8];
    }
    return NULL;
}

int createfile(string filename, char length, char attribute = RegularFile)
{
    if(!isFile(filename))
        return -1; //Filename Error.
    char* dirEntry = findDirectory(filename.substr(0,filename.size()-6));
    if(dirEntry == NULL)
        return -2; //Directory Error.
    //
    int countSpace = 0;
    for(int i=0;i<128;i++)
        if(getFAT(i) == 0)
            countSpace++;
    if(countSpace<length)
        return -3; // Out of memory.

    //
    int i;
    for(i=0;i<8;i++)
    {
        if(dirEntry[i*8] == 0)
        {
            dirEntry += i*8;
            break;
        }
    }
    if( i == 8)
        return -4;

    string tempFilename = filename.substr(filename.size()-6,filename.size());

    //name
    dirEntry[0] = tempFilename[0];
    dirEntry[1] = tempFilename[1];
    dirEntry[2] = tempFilename[2];
    //type
    dirEntry[3] = tempFilename[4];
    dirEntry[4] = tempFilename[5];
    //attributes
    dirEntry[5] = attribute;
    //length
    dirEntry[7] = length;
    //position
    for(int i=0;i<128;i++)
    {
        if(0 == getFAT(i))
        {
            dirEntry[6] = i;
            length -= 1;
            break;
        }
    }

    int last = dirEntry[6];
    for(int i=last+1;i<128&&length>0;i++)
    {
        if(0 == getFAT(i))
        {
            setFAT(last,i);
            last = i;
            length -= 1;
        }
    }
    setFAT(last,-1);
    saveDisk();
    return 0;
}

int openfile(string filename)
{
    if(!isFile(filename))
        return -1; // file name error;

    OpenFile of;
    of.filename = filename;
    of.dirEntry = findDirEntry(of.filename);

    if(of.dirEntry == NULL)
        return -2; // Do not exist; 

    if( (of.dirEntry[5] == SystemFile) || (of.dirEntry[5] == DirectoryFile) )
        return -3;
    of.readPosition = of.writePosition = of.dirEntry[6];
    of.readOffset = of.writeOffset = 0;
    OpenfileList.push_back(of);
    return 0;
}

int closefile(string filename)
{
    vector<OpenFile>::iterator ite;
    for(ite=OpenfileList.begin();ite!=OpenfileList.end();)
    {
        if((*ite).filename == filename)
            ite=OpenfileList.erase(ite);
        else
            ++ite;
    }
    saveDisk();
    return 0;
}

char* readfile(string filename)
{
    bool flag = false;
    vector<OpenFile>::iterator ite;
    for(ite=OpenfileList.begin();ite!=OpenfileList.end();)
        if(ite->filename == filename)
        {
            flag = true;
            break;
        }
    if(!flag)
        return NULL;
    if( ite->readOffset+1 > 63)
    {
        ite->readOffset = 0;
        ite->readPosition = getFAT(ite->readPosition);
        if (ite->readPosition < 0 || ite->readPosition > 127)
            return NULL;
    }
    else
        ite->readOffset++;
    return &Disk[ite->readPosition*64+ite->readOffset];
}

int writefile(string filename,char val)
{
    bool flag = false;
    vector<OpenFile>::iterator ite;
    for(ite=OpenfileList.begin();ite!=OpenfileList.end();)
        if(ite->filename == filename)
        {
            flag = true;
            break;
        }
    if(!flag)
        return -1;

    if( ite->writeOffset+1 > 63)
    {
        ite->writeOffset = 0;
        ite->writePosition = getFAT(ite->writePosition);
        if (ite->writePosition < 0 || ite->writePosition > 127)
            return -3;
    }
    else
        ite->writeOffset++;
    Disk[ite->writePosition*64+ite->writeOffset] = val;
    saveDisk();
    return 0;
}

int deletefile(string filename)
{
    bool flag = false;
    vector<OpenFile>::iterator ite;
    for(ite=OpenfileList.begin();ite!=OpenfileList.end();)
        if(ite->filename == filename)
        {
            flag = true;
            break;
        }
    if(flag)
        return -1;//It's open. cannot delete.

    char* dirEntry = findDirectory(filename.substr(0,filename.size()-6));
    if(dirEntry == NULL) // Dir not exist.
        return -2;

    for(int i = dirEntry[6];getFAT(i) != -1;i = getFAT(i))
        memset(&Disk[i*64],0,64);

    memset(dirEntry,0,8);
    return 0;
}

int test()
{
    int t;
    char i;
    char *r;
    string str;
    while(1)
    {
        cout<<"==============================="<<endl;
        cout<<"1.Create file."<<endl;
        cout<<"2.Open file."<<endl;
        cout<<"3.Read file."<<endl;
        cout<<"4.Write file."<<endl;
        cout<<"5.Close file."<<endl;
        cout<<"6.Type file."<<endl;
        cout<<"7.Change file attributes."<<endl;
        cout<<"----------------------------------------------"<<endl;
        cout<<"8.Create directory."<<endl;
        cout<<"9.Display directory."<<endl;
        cout<<"10.Delelte directory."<<endl;
        cout<<"==============================="<<endl;

        cout << "\n\n\n\n\n";
        cout<<endl;
        cout<<"Option: ";
        cin >> t;
        switch(t)
        {
            case 1: 
                cout<<"Input filename: ";
                cin >> str;
                cout<<"Input Size: ";
                cin >> t;
                t = createfile(str,t);
                if(t != 0)
                    cout <<"Create failed : "<<t<<endl;
                else
                    cout<<"Create success."<<endl;
                cout << "\n\n\n\n\n";
                break;
            case 2:
                cout<<"Input filename: ";
                cin >> str;
                t = openfile(str);
                if(t != 0)
                    cout <<"Open failed : "<<t<<endl;
                else
                    cout<<"Open success."<<endl;
                cout << "\n\n\n\n\n";
                break;
            case 3: break;
                cout<<"Input filename: ";
                cin >> str;
                r = readfile(str);
                if(r == NULL)
                    cout <<"Create failed : "<<t<<endl;
                else
                    cout<<r[0]<<endl;
                cout << "\n\n\n\n\n";
                break;
            case 4: break;
            case 5: break;
            case 6: break;
            case 7: break;
            case 8: break;
            case 9: 
                displayFile();
                cout << "\n\n\n\n\n";
                break;
            case 10: break;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    init();
    test();
    return 0;
}