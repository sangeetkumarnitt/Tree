
#include<iostream>
#include<algorithm>
#include<queue>
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
        display(start->lc);
        cout <<start->data <<"-";
        display(start->rc);
    }
}
void Level_Order_Traversal(tree *start)
{
    int Dnode;
    tree *temp;
    queue <tree *> Q;
    Q.push(start);
    while(!Q.empty())
     {
            temp=Q.front();
            cout << temp->data <<"-";
            Q.pop();
            if(temp->lc)
                Q.push(temp->lc);
            if(temp->rc)
                Q.push(temp->rc);
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
    cout <<"\n\t\t Level Order Traversal\t\t  : "<<endl;
    Level_Order_Traversal(start);
    return 0;
}
