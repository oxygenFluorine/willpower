#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode *addtwonumbers(ListNode *l1, ListNode *l2);
int main()
{
    //创建链表
    ListNode *l1 = new ListNode(2);
    l1->next=new ListNode(4);
    l1->next->next = new ListNode(3);
    l1->next->next->next=new ListNode(8);
    ListNode *l2  = new ListNode(5);
    l2->next=new ListNode(6);
    l2->next->next=new ListNode(7);
    ListNode *result=addtwonumbers(l1,l2);
    //遍历链表
    while (result!=nullptr)
    {
        cout<<result->val<<" ";
        result=result->next;
        /* code */
    }
    return 0;
}
    

ListNode *addtwonumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head=new ListNode(0);
    ListNode *p=head;
    int carry=0;  //进位
    while(l1!=NULL||l2!=NULL)
    {
        int sum = carry;
        if(l1!=NULL)
        {
            sum+=l1->val;
            l1=l1->next;
        }
        if (l2 !=NULL)
        {
            sum+=l2->val;
            l2=l2->next;
            /* code */
        }
        carry = sum /10;
        p->next = new ListNode(sum%10);
        p = p->next;
    }
    if (carry>0)
    {
        p->next = new ListNode(carry);
    }
   
     return head->next;   
}
    
