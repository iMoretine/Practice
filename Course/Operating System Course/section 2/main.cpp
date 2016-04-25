#include <iostream>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

struct Page
{
    int address;
    bool exist;
    Page(int _address) : address(_address), exist(false) {}
};

struct Segment
{
    int process;
    int address;
    int length;
    bool exist;
    vector<Page*> pageTable;
    list<Page*> PageLRU;
    Segment(int _address, int _length) : address(_address), length(_length), exist(false) {}
};

struct Process
{
    vector<Segment*> segTable;
};

class MemoryManage
{
public:
    MemoryManage()
    {
        initMemory();
    }
    ~MemoryManage()
    {

    }
    void initMemory()
    {
        int address = 0;
        ifstream in;
        in.open("init.txt");

        if(!in)
            cout<<"Open file error !"<<endl;

        string temp;
        while(!in.eof())
        {
            in >> temp;
            if(temp == "Process:")
            {
                Process *tProcess = new Process();
                processTable.push_back(tProcess);
                int tInt;
                in >> tInt;
                int tempProcess = tInt;
                while(1)
                {
                    in >> temp;
                    if(temp == ".")
                        break;
                    in >> temp;
                    if (temp == "Segment:")
                        in >> tInt;
                    in >> temp;
                    if (temp == "Length(KB):")
                    {
                        in >> tInt;
                        if( address*1024 > 64*1024)
                        {
                            segTable.push_back(new Segment(0,0));
                            segTable.back()->exist = false;
                            for(int i=0;i<tInt;i++)
                            {
                                segTable.back()->pageTable.push_back(new Page(i*1024));
                            }
                        }
                        else if( address*1024+tInt*1024 > 64*1024)
                        {
                            segTable.push_back(new Segment(address*1024,(64-address)*1024));
                            segTable.back()->exist = true;
                            for(int i=0;i<tInt;i++)
                                segTable.back()->pageTable.push_back(new Page(i*1024));
                            for(int i=0;i<64-address;i++)
                            {
                                segTable.back()->pageTable[i]->exist = true;
                                segTable.back()->PageLRU.push_front(segTable.back()->pageTable[i]);
                            }
                        }
                        else
                        {
                            segTable.push_back(new Segment(address*1024,tInt*1024));
                            segTable.back()->exist = true;
                            for(int i=0;i<tInt;i++)
                            {
                                segTable.back()->pageTable.push_back(new Page(i*1024));
                                segTable.back()->pageTable.back()->exist = true;
                                segTable.back()->PageLRU.push_front(segTable.back()->pageTable.back());
                            }
                        }
                        segTable.back()->process = tempProcess;
                        processTable.back()->segTable.push_back(segTable.back());
                        address += tInt;
                    }
                }
            }
        }
    }
    list<Segment*> segTable;
    vector<Process*> processTable;
private:
};

int main(int argc, char const *argv[])
{
    MemoryManage memManage;
    for(int i=0;i<memManage.processTable[i]->segTable.size();i++)
        for(int j=0;j<memManage.processTable[i]->segTable.size();j++)
        {
            cout<<memManage.processTable[i]->segTable[j]->address<<" "<<memManage.processTable[i]->segTable[j]->length<<" "<<memManage.processTable[i]->segTable[j]->exist<<endl;
            for(int k=0;k<memManage.processTable[i]->segTable[j]->pageTable.size();k++)
            {
                cout<<memManage.processTable[i]->segTable[j]->pageTable[k]->address<<" "<<memManage.processTable[i]->segTable[j]->pageTable[k]->exist<<endl;
            }
        }
    return 0;
}