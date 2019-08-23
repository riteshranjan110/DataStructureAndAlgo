#include <stdio.h>
#include <stdlib.h>

// structure of node.
struct node{
    int data;
    struct node *left;
    struct node *right;
};

// This will create new Node 
struct node* newNode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// This will insert node into a binary tree.
struct node* insert(struct node *root, int data){
    if(!root){
        return newNode(data);
    }

    if(data <= root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to find whether a tree is unival or not
int isUnival(struct node *root, int val){
    // If node is null return 1.
    if(!root){
        return 1;
    }
    if(root->data == val){
        return (isUnival(root->left, val) && isUnival(root->right, val));
    }
    // Else return 0.
    return 0;
}

// This functiuon will count the number of unival subtrees.
int countUnival(struct node *root, int *count){
    if(!root){
        return 0;
    }
    // checking if all nodes in left subtree has same value as parent node.
    int left = isUnival(root->left, root->data);
    // checking if all nodes in right subtree has same value as parent node.
    int right = isUnival(root->right, root->data);
    // If root is unival then increment the count.
    if(left && right){
        //*count  = *count+1;
        *count += 1;
    }

    countUnival(root->left, count);// checking id left subtree is unival or not.
    countUnival(root->right, count);// checking if right subtree is unival or not.
    return *count;
}

// Function to print tree.
void printTree(struct node *root){
    if(!root){
        return;
    }
    printTree(root->left);
    printf("%d\n",root->data);
    printTree(root->right);
}

int main(){
    struct node *root = insert(NULL,10);
    insert(root, 10);
    insert(root, 11);
    insert(root, 11);
    insert(root, 12);
    //printTree(root);
    int count = 0;
    printf("Number of unival subtrees are : %d\n",countUnival(root, &count));
    return 0;
}

