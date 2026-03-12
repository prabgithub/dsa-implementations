#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {

    int data;
    struct node* left;
    struct node* right;

};

struct node* create_node(int value){

    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
};

struct node* insert(struct node* root, int value){

    if (root==NULL)
        return create_node(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);


    return root;

}

void inorder(struct node* root){

    if (root==NULL)
        return;

    inorder(root->left);
    printf("%d", root->data);
    printf("->");
    inorder(root->right);

}

void main(){
    struct node* newwn = create_node(10);
    for(int i=0;i<100;i++){
        int value = rand()%100;
        newwn = insert(newwn, value);
        printf("%d\n",value);
    }

    inorder(newwn);

    printf("\nfinish\n");
}


