#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include <iterator>
#include <unistd.h>
using namespace std;

enum Status
{
    IDLE,
    READY,
    RUNNING,
    BLOCKED,
    COMPLETED,
};

struct PCB
{
    int PID;
    Status status;
    int runTime;
    int runningTime;
    vector<pair<int,int> > IOlist; 
};

class processSimulation
{
public:
    processSimulation()
    {
        processInit();
    }
    ~processSimulation()
    {

    }
    
    void processCreation()
    {
        while(!idleQueue.empty())
        {
            readyQueue.push_back(idleQueue.front());
            idleQueue.pop_front();
            readyQueue.back()->status = READY;
            printPCB(readyQueue.back());
        }
    }

    void processScheduling() 
    {
        while(!readyQueue.empty() || !runningQueue.empty() || !blockingQueue.empty())
        {
            sleep(1);

            bool moveOutFlag = false;

            if(!readyQueue.empty())
            {
                runningQueue.push_back(readyQueue.front());
                runningQueue.back()->status = RUNNING;
                readyQueue.pop_front();
            }
            if(!runningQueue.empty())
                runningQueue.back()->runningTime ++;
            printAll();
            
            if(!runningQueue.empty()
                && !runningQueue.back()->IOlist.empty() 
                && runningQueue.back()->runningTime == runningQueue.back()->IOlist[0].first)
            {
                processBlocking(runningQueue.back());
                runningQueue.pop_front();
                moveOutFlag = true;
            }
            else if(!runningQueue.empty()
                && runningQueue.back()->runningTime == runningQueue.back()->runTime)
            {
                completedQueue.push_back(runningQueue.front());
                completedQueue.back()->status = COMPLETED;
                runningQueue.pop_front();
                moveOutFlag = true;
            }
            
            if(!runningQueue.empty() && !moveOutFlag)
            {
                readyQueue.push_back(runningQueue.front());
                readyQueue.back()->status = READY;
                runningQueue.pop_front();
            }

            deque<PCB *>::iterator it = blockingQueue.begin();
            while(it != blockingQueue.end())
            {
                (*it)->IOlist[0].second --;
                if((*it)->IOlist[0].second <= 0)
                {
                    (*it)->IOlist.erase((*it)->IOlist.begin());
                    processWakeUp(*it);
                    it = blockingQueue.erase(it);
                }
                else
                    it++;
            }
        }
        sleep(1);
        printAll();
    }

    void processBlocking(PCB *pcb)
    {
        blockingQueue.push_back(pcb);
        blockingQueue.back()->status = BLOCKED;
    }

    void processWakeUp(PCB *pcb)
    {
        readyQueue.push_back(pcb);
        readyQueue.back()->status = READY;
    }

private:
    void processInit()
    {
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
                PCB *p = new PCB();
                in >> p->PID;
                
                in >> temp;
                if (temp == "run_time:")
                {
                     in >> p->runTime;
                     p->runningTime = 0;
                }
                in >> temp;
                if(temp == "I/O_time:") 
                {
                    char c;
                    int first,second;
                    
                    while(1)
                    {
                        in >> c;
                        if(c == '.')
                            break;
                        switch(c)
                        {
                            case '<': in >> first; break;
                            case ',': in >> second;break;
                            case '>': p->IOlist.push_back(pair<int,int>(first,second));break;
                        }   
                    }
                }
                idleQueue.push_back(p);
            }
        }
    }

    void printPCB(const PCB *pcb)
    {
        cout<<"PID: "<<pcb->PID<<"  Run Time: "<<pcb->runTime<<"  Running Time: "<<pcb->runningTime<<"  ";
        printStatus(pcb);
        cout<<"\n";
    }

    void printStatus(const PCB *pcb)
    {
        cout<<"Status: ";
        switch(pcb->status)
        {
            case IDLE:cout<<"idle";break;
            case READY:cout<<"ready";break;
            case RUNNING:cout<<"running";break;
            case BLOCKED:cout<<"blocked";break;
            case COMPLETED:cout<<"completed";break;
        }
        cout<<"  ";
    }

    void printAll()
    {
        cout<<"\033[1H\033[2J";
        
        cout<<"\nIdle Queue: "<<endl;
        if(idleQueue.size() == 0)
        cout<<" Empty."<<endl;
        for(int i=0;i<idleQueue.size();i++)
            printPCB(idleQueue[i]);

        cout<<"\nReady Queue: "<<endl;
        if(readyQueue.size() == 0)
        cout<<" Empty."<<endl;
        for(int i=0;i<readyQueue.size();i++)
            printPCB(readyQueue[i]);

        cout<<"\nRunning Queue: "<<endl;
        if(runningQueue.size() == 0)
        cout<<" Empty."<<endl;
        for(int i=0;i<runningQueue.size();i++)
            printPCB(runningQueue[i]);

        cout<<"\nBlocking Queue: "<<endl;
        if(blockingQueue.size() == 0)
        cout<<" Empty."<<endl;
        for(int i=0;i<blockingQueue.size();i++)
            printPCB(blockingQueue[i]);

        cout<<"\nCompleted Queue: "<<endl;
        if(completedQueue.size() == 0)
        cout<<" Empty."<<endl;
        for(int i=0;i<completedQueue.size();i++)
            printPCB(completedQueue[i]);
    }

    deque<PCB *> idleQueue;
    deque<PCB *> readyQueue;
    deque<PCB *> runningQueue;
    deque<PCB *> blockingQueue;
    deque<PCB *> completedQueue;
};

int main(int argc, char const *argv[])
{
    processSimulation *P = new processSimulation();
    P->processCreation();
    P->processScheduling();
    return 0;
}