#include<iostream>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<map>
using namespace std;
struct Node
{
	int data,hd;
	struct Node *left, *right;
};
struct Node *newNode(int item)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}
void BottomView(struct Node *root,map<int,int > &m)
{
	if(root==NULL) return ;
	queue<struct Node *>q;
	q.push(root);
	root->hd=0;
	int hd;
	while(!q.empty())
	{
		struct Node *temp=q.front();
		q.pop();
		hd=temp->hd;
		m[hd]=temp->data;
		if(temp->left)
		{
			temp->left->hd=hd-1;
			q.push(temp->left);
		}
		if(temp->right)
		{
			temp->right->hd=hd+1;
			q.push(temp->right);
		}
	}	  
}

int main()
{
struct Node *root = newNode(20);
root->left = newNode(8);
root->right = newNode(22);
root->left->left = newNode(5);
root->left->right = newNode(3);
root->right->left = newNode(4);
root->right->right = newNode(25);
root->left->right->left = newNode(10);
root->left->right->right = newNode(14);

map<int ,int >m;
BottomView(root,m);
map<int ,int >::iterator it;
for(it=m.begin();it!=m.end();it++)
   cout <<it->second <<' ';
return 0;
}
