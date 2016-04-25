#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* &P)
{
    ListNode *node = P;
    if(node == NULL)
        return;
    if(node->next == NULL)
    {
        delete node;
        P = NULL;
        return;
    }
    ListNode *temp = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    delete temp;
}

int main()
{
    ListNode *list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);
    deleteNode(list->next);
    for(ListNode *i = list;i != NULL;i = i->next)
        cout<<i->val<<" ";
    cout<<endl;
    return 0;
}