 #include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * findReciprocal(ListNode *list, int k)
{
    ListNode *temp = list;
    while(k-- && temp != NULL)
        temp = temp->next;
    
    while(temp != NULL)
    {
        list = list->next;
        temp = temp->next;
    }
    return list;
}

int main()
{
    ListNode *list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);
    list->next->next->next->next->next = new ListNode(6);
    list->next->next->next->next->next->next = new ListNode(7);

    cout<<"The reciprocal 3th: ";
    ListNode* r = findReciprocal(list,3);
    if(r == NULL)
        cout<<"NULL"<<endl;
    else
        cout<<r->val<<endl;
    return 0;
}