#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* difference(ListNode *listA, ListNode *listB)
{
    ListNode *resultList = new ListNode(0);
    ListNode *resultIndex = resultList;
    listA = listA->next;
    listB = listB->next;
    while(listA)
    {
        if(listB == NULL || listA->val < listB->val)
        {
            resultIndex->next = new ListNode(listA->val);
            listA = listA->next;
            resultIndex = resultIndex->next;
        }
        else if(listA->val > listB->val)
        {
            listB = listB->next;
        }
        else
        {
            listA = listA->next;
            listB = listB->next;
        }
    }
    return resultList;
}

int main()
{
    ListNode *listA = new ListNode(0);
    listA->next = new ListNode(1);
    listA->next->next = new ListNode(2);
    listA->next->next->next = new ListNode(3);

    ListNode *listB= new ListNode(0);
    listB->next = new ListNode(3);
    listB->next->next = new ListNode(3);
    listB->next->next->next = new ListNode(4);
    
    ListNode *r = difference(listA,listB);
    r = r->next;
    while(r)
    {
        cout<<r->val<<endl;
        r = r->next;
    }
    return 0;
}