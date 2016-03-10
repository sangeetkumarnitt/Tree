#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
struct node{
    int data;
    struct node *lc,*rc;
};
typedef struct node tree;
tree * insert(tree * start,int data)
{
    tree *p,*q;
    tree *temp;
    temp=new tree;
    temp->data=data;
    temp->lc=temp->rc=NULL;
     p=start;
      while(p)
      {
          q=p;
          if(p->data>=data)
            p=p->lc;
          else
            p=p->rc;
      }
      if(start==NULL)
        start=temp;
      else
      {
          if(q->data>=temp->data)
          {
              q->lc=temp;
          }
          else
              q->rc=temp;
      }
      return start;

}
void display(tree * start)
{
    if(start!=NULL)
    {
        cout <<start->data <<"-";
        display(start->lc);

        display(start->rc);
    }
}
void PreOrder_NonRecursive_Traversal(tree *start)
{
    int Dnode;
    tree *temp;
    stack <tree *> S;
    while(1)
    {
        while(start)
         {
             cout << start->data <<"-";
             S.push(start);
             start=start->lc;
         }
         if(S.empty())
            break;

         start=S.top();
            S.pop();
         start=start->rc;
    }
}
int main()
{
    int n,data;
    tree *start=NULL;
    cout <<"Enter the No of Nodes ";
    cin >> n;
    cout << "Entre Tree data ";
    while(n--){
    cin >> data;
    start=insert(start,data);
    }
    display(start);
    cout <<"\n\t\t PreOrder_NonRecursive_Traversal  : "<<endl;
    PreOrder_NonRecursive_Traversal(start);
    return 0;
}
