#include <stdio.h>
#include <stdlib.h>


//define node 
struct node {
    int data;
    struct node* left;
    struct node* right;

};

struct node* create_node(int data){

    struct node* new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
};


void preorder(struct node* root){

    if (root==NULL){
    return;
    }

    //node first
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);


};


void inorder(struct node* root){

    if (root==NULL){
    return;
    }


    //node first
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);


};


void postorder(struct node* root){


    if (root==NULL){
    return;
    }


    //node first
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);

};



void main(){

    struct node* apple = create_node(1);
    apple->left = create_node(2);
    apple->right = create_node(3);

    apple->left->left = create_node(4);
    apple->left->right = create_node(5);

    apple->right->left = create_node(6);
    apple->right->right = create_node(7);

    // preoder
    printf("preorder traversal\n");
    preorder(apple);

    printf("\n");
    printf("inorder traversal\n");
    inorder(apple);


    printf("\n");
    printf("postorder traversal\n");
    postorder(apple);


}
