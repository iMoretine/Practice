#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
bool hasCycle(ListNode *head) 
{
    ListNode *fast,*slow;
    if(head==NULL) 
        return false; 
    slow=head;
    fast=head->next;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        if(slow==fast) 
            return true;
        slow=slow->next;
        fast=fast->next->next;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = list1->next; // make a cycle.
    if(hasCycle(list1))
        cout<<"List 1 has a cycle."<<endl;
    else
        cout<<"List 1 has no cycle."<<endl;

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(2);
    if(hasCycle(list2))
        cout<<"List 2 has a cycle."<<endl;
    else
        cout<<"List 2 has no cycle."<<endl;
    return 0;
}