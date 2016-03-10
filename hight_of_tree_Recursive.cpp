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
int Higth_Recursive(tree *start)
{
    int Left_Higth;
    int Right_Hight;
    if(start==NULL)
        return 0;
    else
    {
        Left_Higth=Higth_Recursive(start->lc);
        Right_Hight=Higth_Recursive(start->rc);
        if(Left_Higth>Right_Hight)
            return Left_Higth +1;
        else
            return Right_Hight +1;
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
    cout <<"Hight of tree Recursive : ";
   cout  <<Higth_Recursive(start) <<endl;
   cout << Sum(start);
    return 0;
}
