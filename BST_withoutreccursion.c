#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *rchild;
    struct node *lchild;   
};
struct node *root=NULL;

void inorder_non(struct node*);
void preorder_non(struct node*);
void postorder_non(struct node*);
 void push(struct node*);
 struct node* pop();
struct node *stack[20];
int top=-1;

struct node *create(int);
struct node *insert_node(struct node*,int);
struct node *binarysearchtree_non(struct node*,int);
void delete_node(struct node*,int);
struct node *successor(struct node *ptr);
int main()
{
    int ch,key;
    while(1)
    {
        printf("\n");
        printf("1. insert node:\n");
        printf("2. search in BST:\n");
        printf("3. exit: \n");
        printf("4. delete node.\n");
        printf("5. Inorder non recursive\n");
        printf("6. preorder non recursive\n");
        printf("7. postorder non recursive\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {

            case 1:printf("Enter the item to be inserted: ");
                    scanf("%d",&key);
                    root=insert_node(root,key);
                    break;
            case 2: printf("Enter the key to  search in BST: ");
                    scanf("%d",&key);
                    binarysearchtree_non(root,key);
                    if(root==0)
                    {
                        printf("key not found\n");
                    }
                    else
                    {
                        printf("key found\n");
                    }
                    break;
            case 3: printf(".......................program terminated.........................");
                    exit(0);
            case 4: printf("Enter the node to  delete: ");
                    scanf("%d",&key);
                    delete_node(root,key);
                    printf("deleted element: %d\n",key);
                    break;
            case 5: inorder_non(root);
                    break;
            case 6: preorder_non(root);
                    break;
            case 7: postorder_non(root);
                    break;
    
            default: printf("Invalid choise..");
            
        }
    }
    return 0; 
}
struct node *create(int data)
{
    
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=data;

     newnode->lchild=NULL;
     newnode->rchild=NULL;
    return newnode;
    
}
struct node *insert_node(struct node *ptr,int key)
{
    if(ptr==NULL)
    {
        ptr=create(key);

    }
    else if(ptr->data==key)
    {
        printf("data already exist.\n");
        return ptr;

    }
    else if(key<ptr->data)
    {
        ptr->lchild=insert_node(ptr->lchild,key);
    }
    else if(key>ptr->data)
    {
        ptr->rchild=insert_node(ptr->rchild,key);
    }
    return ptr;
}
struct node *binarysearchtree_non(struct node *root,int key)
{
    while(root!=NULL)
    {
        if(key>root->data)
        {
            root=root->rchild;

        }
        else if(key<root->data)
        {
            root=root->lchild;
        }
        else
        {
            return root;
        }
    }
    return NULL;
}
// struct node* binarysearchtree(struct node *ptr,int key)  follow this search
//  {
//      if(ptr==NULL)
//      {
//          return ptr;
//      }
//      else if(ptr->data==key)
//      {
//          printf("node found.");
//          return ptr;
//      }
//      else if(key<ptr->data)
//      {
//          return binarysearchtree(ptr->lchild,key);
//      }
//      else if(key>ptr->data)
//      {
//          return binarysearchtree(ptr->rchild,key);
//      }
//      return ptr;
//  }
 void delete_node(struct node*root,int item)
{
    struct node*ptr,*ptr1,*parent ;
    int flag=0 ;
    ptr = root ;

    while(flag==0 && ptr!=NULL)
    {
        if(item<ptr->data)
        {
            parent = ptr ; 
            ptr = ptr->lchild ;
        }
        else if(item>ptr->data)
        {
            parent = ptr ;
            ptr = ptr->rchild ;
        }
        else
        {
            flag = 1 ;
            break ;
        }
    }
    if(flag==0)
    {
        printf("Node not found\n") ;
        return ; 
    }
    int option ;
    if(ptr->lchild==NULL && ptr->rchild==NULL)
    {
        option =1 ;
    }
    else if(ptr->lchild!=NULL && ptr->rchild!=NULL)
    {
        option =3 ;
    }
    else
    {
        option =2 ;
    }

    if(option==1)
    {
        if(parent->lchild==ptr)
        {
            parent->lchild = NULL ; 
        }
        else
        {
            parent->rchild = NULL ; 
        }
        free(ptr) ;
    }
    else if(option==2)
    {
        if(parent->lchild==ptr)
        {
            if(ptr->lchild==NULL)
            {
                parent->lchild = ptr->rchild ;
            }
            else
            {
                parent->lchild = ptr-> lchild ;
            }
        }
        else
        {
            if(ptr->lchild==NULL)
            {
                parent->rchild = ptr->rchild ;
            }
            else
            {
                parent->rchild = ptr->lchild ;
            }
        }
        free(ptr) ;
    }
    else //option 3
    {
        ptr1 = successor(ptr) ;
        int item1  = ptr1->data ;
        delete_node(root,item1) ;
        ptr->data = item1 ;
    }
}
 //inorder sucessor
struct node *successor(struct node *ptr)
 {
    struct node *ptr1=ptr->rchild;
    if(ptr1!=NULL)
    {
        while(ptr1->lchild!=NULL)
        {
            ptr1=ptr1->lchild;
        }
    }
    return ptr1;
 }
 //push function
 void push(struct node* ptr)
 {
    if(top==20)
    {
        printf("Over flow");
        return;
    }
    top++;
    stack[top]=ptr;
 }
 struct node *pop()
 {
    struct node *ptr;
    if(top==-1)
    {
        printf("Under flow");
        return NULL;
    }
    ptr=stack[top];
    top--;
    return ptr;
 }
 void inorder_non(struct node *ptr)
 {
    while(1)
    {
        if(ptr!=NULL)
        {
            push(ptr);
            ptr=ptr->lchild;
        }
        else
        {
            if(top==-1)
                break;
            ptr=pop();
            printf("%d ",ptr->data);
            ptr=ptr->rchild;
        
        }
    }
 }
 void preorder_non(struct node *ptr)
 {
    //struct node* prev=NULL;
    while(1)
    {
        if(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            push(ptr);
            ptr=ptr->lchild;
        }
        else
        {
            if(top==-1)
                break;
            ptr=pop();
            ptr=ptr->rchild;
    
        }
    }
 }
 void postorder_non(struct node *ptr)
 {
    struct node* prev=NULL;
    while(ptr!=NULL||top!=-1)
    {
        if(ptr!=NULL)
        {
            push(ptr);
            ptr=ptr->lchild;
        }
        else
        {
            ptr=stack[top];
            if(ptr->rchild==NULL||ptr->rchild==prev)
            {
                printf("%d ",ptr->data);
                prev=pop();
                ptr=NULL;
            }
            else
            {
                ptr=ptr->rchild;
            }
        }
    }
 }
