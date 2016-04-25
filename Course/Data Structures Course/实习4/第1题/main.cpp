#include <iostream>
using namespace std;

struct ListNode
{
    char val;
    ListNode *next;
    ListNode(char x) : val(x), next(NULL) {}
};

ListNode * findSuffix(ListNode *str1, ListNode *str2)
{
    ListNode *pointer1= str1;
    ListNode *pointer2 = str2;
    while(pointer1 != NULL && pointer2 != NULL)
    {
        pointer1 = pointer1->next;
        pointer2 = pointer2->next;
    }

    ListNode *temp = NULL;
    if(pointer1 == NULL)
    {
        temp = pointer2;
        pointer2 = str2;
        while(temp != NULL)
        {
            temp = temp->next;
            pointer2 = pointer2->next;
        }
        pointer1 = str1;
    }
    else
    {
        temp = pointer1;
        pointer1 = str1;
        while(temp != NULL)
        {
            temp = temp->next;
            pointer1 = pointer1->next;
        }
        pointer2 = str2;
    }
    
    ListNode *result = pointer1;
    while(pointer1 != NULL)
    {
        if(pointer1->val != pointer2->val)
            result = pointer1->next;
        pointer1 = pointer1->next;
        pointer2 = pointer2->next;
    }
    return result;
}

int main()
{
    ListNode *str1 = new ListNode('l');
    str1->next = new ListNode('o');
    str1->next->next = new ListNode('a');
    str1->next->next->next = new ListNode('d');
    str1->next->next->next->next = new ListNode('i');
    str1->next->next->next->next->next = new ListNode('n');
    str1->next->next->next->next->next->next = new ListNode('g');

    ListNode *str2 = new ListNode('b');
    str2->next = new ListNode('e');
    str2->next->next = new ListNode('i');
    str2->next->next->next = new ListNode('n');
    str2->next->next->next->next = new ListNode('g');

    cout<<"String 1 : ";
    for(ListNode *i=str1;i != NULL;i = i->next)
        cout<<i->val<<" ";
    cout<<endl;

    cout<<"String 2 : ";
    for(ListNode *i=str2;i != NULL;i = i->next)
        cout<<i->val<<" ";
    cout<<endl;
    
    ListNode* r = findSuffix(str1,str2);
    cout<<"Suffix : ";
    if(r == NULL)
        cout<<"NULL"<<endl;
    else
    {
        for(ListNode *i=r;i != NULL;i = i->next)
            cout<<i->val<<" ";
        cout<<endl;
    }
    return 0;
}