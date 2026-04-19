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

//
//void preorder(struct node* root){
//
//    if (root==NULL){
//    return;
//    }
//
//    //node first
//    printf("%d",root->data);
//    preorder(root->left);
//    preorder(root->right);
//
//
//};
//
//
//void inorder(struct node* root){
//
//    if (root==NULL){
//    return;
//    }
//
//
//    //node first
//    inorder(root->left);
//    printf("%d",root->data);
//    inorder(root->right);
//
//
//};
//
//
//void postorder(struct node* root){
//
//
//    if (root==NULL){
//    return;
//    }
//
//
//    //node first
//    postorder(root->left);
//    postorder(root->right);
//    printf("%d",root->data);
//
//};
//

int find_height(struct node* root){

    if (root==NULL){
    return 0;
    }

    int left = find_height(root->left);
    int right = find_height(root->right);

    int height;
    if (left>right)
        height = left+1 ;
    else 
        height = right+1 ;
return height;

}


int count_node(struct node* root){

    if (root==NULL){
    return 0;
    }

    int left = count_node(root->left);
    int right = count_node(root->right);

    int count = left + right +1;
    return count;

}


struct node* search_node(struct node* root, int key){

    if (root== NULL || root->data==key)
        return root;

    struct node* left_search = search_node(root->left, key);
    
    if (left_search != NULL){
        return left_search;
    }
    else{
        struct node* right_search = search_node(root->right, key);
        return right_search;
    }
}




void main(){

    struct node* apple = create_node(1);
    apple->left = create_node(2);
    apple->right = create_node(3);

    apple->left->left = create_node(4);
    apple->left->right = create_node(5);

    apple->right->left = create_node(6);
    apple->right->right = create_node(7);

    // preoder
    printf("height\n");
    printf("%d",find_height(apple));

    printf("\n");
    printf("total nodes\n");
    printf("%d\n",count_node(apple));

//
//    printf("\n");
//    printf("postorder traversal\n");
//    postorder(apple);

    printf("size of struct node %ld\n", sizeof(struct node));
    printf("size of struct node* %ld\n", sizeof(struct node*));
    printf("size of int %ld\n", sizeof(int));
    printf("size of int* %ld\n", sizeof(int*));
    
    struct node* s_node = search_node(apple,6);
    if (s_node==NULL)
        printf("key not found");
    else
        printf("search results for 6 --> %d\n", s_node->data);
}
