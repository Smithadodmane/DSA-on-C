#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *L,*R;
};
typedef struct node *Node;

Node newnode(int data)
{
    Node node=(Node)malloc(sizeof(struct node));
    node->data=data;
    node->L=node->R=0;
    return node;
    
}
Node insert(Node root,int data)
{
    if(root==0)
     return newnode(data);
    if(data<root->data)
      root->L=insert(root->L,data);
     if(data>root->data)
       root->R=insert(root->R,data);
     return root;  

}

Node search(Node root,int key)
{
    if(root==0 || root->data==key)
     return root;
     if(key<root->data)
       return search(root->L,key);
     else
        return search(root->R,key);
}
void inorder(Node root)
{
    if(root==0)
        return;
     inorder(root->L);
     printf("%d",root->data);
     inorder(root->R);
}

void preorder(Node root)
{
    if(root==0)
     return;
     printf("%d",root->data);
     preorder(root->L);
     
     preorder(root->R);
}

void postorder(Node root)
{
    if(root==0)
     return;
     postorder(root->L);
     
     postorder(root->R);
     printf("%d",root->data);
}
int count(Node root)
{
    if(root==0)
     return 0;
    return 1+count(root->L)+count(root->R);
}
int height(Node root)
{
    if(root==0)
     return -1;
    int left=height(root->L);
     int right=height(root->R);
     return 1+(left>right?left:right);
}
void max(Node root)
{
    if(root==0){
     printf("empty");
     return;}
     
     Node parent=0;
     Node cur=root;
     while(cur->R!=0)
     {
         parent=cur;
         cur=cur->R;
         
     }
     if(parent)
      printf("node %d \n parent %d",cur->data,parent->data);
     else{
          printf("node %d \n parent no",cur->data);
     }
}

void display(Node root,int key)
{
     if(root==0){
     printf("empty");
     return;}
     
     Node parent=0;
     Node cur=root;
     while(cur!=0)
     {
        if(cur->data==key)
         {
     if(parent)
      printf("node %d \n parent %d",cur->data,parent->data);
     else{
          printf("node %d \n parent no",cur->data);
     }
     return;
             
         }
         parent=cur;
         if(key<cur->data)
         cur=cur->L;
         else
         cur=cur->R;
     }
     printf("key not found");
}
int main()
{
    Node root=0;
    int choice,data,key;
    for(;;)
    {
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the vslue:");
                   scanf("%d",&data);
                   root=insert(root,data);
                   break;
            case 2:printf("enter the key to be searched:");
                   scanf("%d",&key);
                   Node result=search(root,key);
                   if(result)
                      printf("key found");
                 else
                 printf("key not found");
                 break;
            case 3:inorder(root);
                    break;
            case 4:preorder(root);
                    break;
            case 5:postorder(root);
                    break;
            case 6:printf("%d",count(root));
                  break;
            case 7:printf("%d",height(root));
                  break;
            case 8:max(root);
                  break;
             case 9:printf("enter the key to be searched:");
                  scanf("%d",&key);
                  display(root,key);
                  break;
            default:printf("invalid");
            
        }
    }
    return 0;
}