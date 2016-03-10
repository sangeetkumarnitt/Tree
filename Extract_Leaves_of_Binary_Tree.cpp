#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
};
struct Node* extractLeafList(struct Node *root, struct Node **head_ref)
{
   if (root == NULL)  return NULL;

   if (root->left == NULL && root->right == NULL)
   {
      root->right=*head_ref;
      if(*head_ref!=NULL) (*head_ref)->left=root;

      *head_ref=root;
      return NULL;

   }
   root->right = extractLeafList(root->right, head_ref);
   root->left  = extractLeafList(root->left, head_ref);

   return root;
}
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void print(struct Node *root)
{
    if (root != NULL)
    {
         print(root->left);
         printf("%d ",root->data);
         print(root->right);
    }
}

void printList(struct Node *head)
{
     while (head)
     {
         printf("%d ", head->data);
         head = head->right;
     }
}
int Sum(struct Node *root,int sum)
{
    if(root==NULL)
        return 0;
    sum=sum*10+root->data;
    if(!root->left&&!root->right)
        return sum;
    return Sum(root->left,sum) +
    Sum(root->right,sum);

}

int main()
{
     struct Node *head = NULL;
     struct Node *root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     root->right->right = newNode(6);
     root->left->left->left = newNode(7);
     root->left->left->right = newNode(8);
     root->right->right->left = newNode(9);
     root->right->right->right = newNode(10);

     printf("Inorder Trvaersal of given Tree is:\n");
     print(root);

     root = extractLeafList(root, &head);

     printf("\nExtracted Double Linked list is:\n");
     printList(head);

     printf("\nInorder traversal of modified tree is:\n");
     print(root);
     return 0;
}
