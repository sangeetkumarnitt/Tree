#include<iostream>
#include<climits>
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
int max_Node(tree *start)
{
    int max_node,max=INT_MIN,l_max,r_max,root_val;
    tree *temp;
    l_max=r_max=root_val=max;
    if(start!=NULL)
     {
          root_val=start->data;
          l_max= max_Node(start->lc);
          r_max=max_Node(start->rc);
          if(l_max>r_max)
                max=l_max;
          else
                max=r_max;
          if(max<root_val)
            max=root_val;
     }

     return max;
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
    cout <<"Max  Node  using recursion: ";
   cout  <<max_Node(start) <<endl;
    return 0;
}

