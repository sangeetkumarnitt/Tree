#include<iostream>
#include<queue>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct Node
{
	int data;
	struct Node *left, *right;
};
struct Node *newNode(int item)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}
/*
  12
 /  \
10  30
/    \
25   40 
*/

void RightView_Rec(struct Node *root,int level,int *max_level)
{
	if(root==NULL) return ;
	if(level >*max_level)
	{
		cout << root->data <<'\n';
		*max_level=level;
	}
	RightView_Rec(root->right,level+1,max_level);
	RightView_Rec(root->left,level+1,max_level);
}
void LeftView(struct Node *root)
{
	queue<struct Node *>q;
	q.push(root);
	struct Node *indicator =NULL;
	struct Node *temp;
	q.push(indicator);
	cout <<root ->data <<'\n';
	while(!q.empty())
	{
		temp=q.front();
		
		
		if(!q.empty()&&temp!=indicator) 
		{
			   if(temp->left)
			   q.push(temp->left);
			   if(temp->right)
			   q.push(temp->right); 
		}
	   if (temp==indicator&&!q.empty())
		{
			q.pop();
			struct Node *t=q.front();
			 	cout << t->data <<'\n';
			 
			if (!q.empty())
				q.push(indicator);
		}
		q.pop();
	} 
}

void RightView(struct Node *root)
{
	queue<struct Node *>q;
	q.push(root);
	struct Node *indicator =NULL;
	struct Node *temp;
	q.push(indicator);
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		if(temp->left)
		q.push(temp->left);
		if(temp->right)
		q.push(temp->right); 
		if(q.front()==indicator)
		{
			cout << temp->data <<'\n';
			q.pop(); 
			if (!q.empty())
				q.push(indicator);
		}	 
	} 
}


int main()
{
struct Node *root = newNode(1);
root->left = newNode(2);
root->right = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5);
root->right->left = newNode(6);
root->right->right = newNode(7);
int max_level=0;
RightView_Rec(root,1,&max_level);
cout <<'\n';
RightView(root);
cout <<'\n';
LeftView(root);
return 0;
}
