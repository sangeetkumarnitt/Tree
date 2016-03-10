#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdlib>
using namespace std;
 struct node{
        int data;
        struct node *lc,*rc;
        };
 typedef struct node tree;


 tree *insert(tree *start )
 {
      int data;
      tree *p,*q;
      p=start;
      cout << "Entre the data = ";
      cin >> data;
      tree *temp;
      temp=(tree *)malloc(sizeof(tree));
      temp->data=data;
      temp->lc=temp->rc=NULL;
      while(p!=NULL)
      {
          q=p;
          if(p->data>=temp->data)
           p=p->lc;
           else
           p=p->rc;
      }
      if(start==NULL)
      {
         start=temp;
      }
      else
      {

         if(q->data>=temp->data)
         {
              q->lc = temp;
         }
         else
         {
           q->rc =temp;
         }
      }
         return start;
 }
 void display(tree *start)
 {

      if(start!=NULL)
      {

          display(start->lc);
            cout << start->data <<"-";
          display(start->rc);
      }

 }
 int findElementInTreeNonRecursive(tree * root, int num)
{
    int found = 0;
    queue < tree * > Q;
    // Level Order Traversal
    tree * temp = NULL;
    if(root == NULL)
        return 0;

    Q.push(root);

    while(!(Q.empty()))
    {
        temp =Q.front();
        //cout << "I m In " <<endl;
        Q.pop();
        cout << temp->data << endl;
        // Find the element
        if(temp -> data == num)
        {
            found = 1;
            break;
        }

        if(temp -> lc)
            Q.push(temp -> lc);
        if(temp -> rc)
            Q.push(temp -> rc);
    }

    // Return 1 if element was found
    return found;
}
  int main()
{
      tree *start='\0';
      int n,i,data;
       cout << "Entre the no of data = ";
       cin  >> n;
       for(i=0;i<n;i++)
       start = insert(start);
       cout << "\n";
       display(start);
       cout << "Enter the data for search ";
       cin >> data;
       cout << endl;
       if(findElementInTreeNonRecursive(start, data))
         cout << "data  Found " <<data <<endl;
        else
            cout <<"Data Not Found" ;
      return 0;
}
