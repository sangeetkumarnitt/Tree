#include<iostream>
using namespace std;
struct node{
int data;
struct node *next;
};
typedef struct node Node;

Node* Create_(Node *head,int data)
{
    Node *temp = new Node();
    temp->data=data;
    if(head==NULL)
    {
        head=temp;
        head->next=NULL;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
    return head;
}
void print(Node*head)
{
    while(head)
    {
        cout <<head->data <<" ";
        head=head->next;
    }
}
Node *rev(Node *head)
{
    Node *prev=NULL,*cur,*next;
    cur=head;
    while(cur)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}
int main()
{
    Node *head=NULL;
    int n,data;
    cin >> n;
    while(n--)
    {
        int data;
        cin >> data;
        head=Create_(head,data);
    }
    print(head);
    cout <<"\n";
   head= rev(head);
    print(head);
    return 0;
}
