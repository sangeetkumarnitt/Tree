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
int Deepest_Node(tree *start)
{
    int Dnode;
    tree *temp;
    queue <tree *> Q;
    Q.push(start);
    while(!Q.empty())
     {
            temp=Q.front();
            Q.pop();
            if(temp->lc)
                Q.push(temp->lc);
            if(temp->rc)
                Q.push(temp->rc);
     }
     return temp->data;
}

void Print_Arr(int path[],int pathlen)
{
    int i;
    for(i=0;i<pathlen;i++)
        cout <<path[i]<<" ";
    cout <<"\n";
}

void Print_Path_Rec(tree *root,int path[],int pathlen)
{
    if(root!=NULL)
    {
         path[pathlen++]=root->data;
     if(root->lc==NULL&&root->rc==NULL)
         Print_Arr(path,pathlen);
     else
     {
        Print_Path_Rec(root->lc,path,pathlen);
        Print_Path_Rec(root->rc,path,pathlen);
     }
   }
}
int main()
{
    int n,data,path[10000],pathlen=0;
    tree *start=NULL;
    cout <<"Enter the No of Nodes ";
    cin >> n;
    cout << "Entre Tree data ";
    while(n--){
    cin >> data;
    start=insert(start,data);
    }
    display(start);
    cout <<"Deepest Node : ";
   cout  <<Deepest_Node(start) <<endl;

   Print_Path_Rec(start,path,pathlen);// <<endl;
    return 0;
}
