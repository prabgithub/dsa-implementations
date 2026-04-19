#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data){
    struct node* node1 = (struct node*)malloc(sizeof(struct node));
    node1->data = data;
    node1->left = node1->right = NULL;
    return node1;
}

struct node* search_node(struct node* root, int data){
    if (root==NULL)
        return NULL;
    if (root->data == data)
        return root;
    struct node* left = search_node(root->left, data);
    struct node* right = search_node(root->right, data);
    if (left!=NULL)
        return left;
    else return right;
}

int height(struct node* root){
    if (root==NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    if (left>right)
        return left+1;
    else
        return right+1;
}

int count(struct node* root){
    if (root==NULL)
        return 0;
    int left = count(root->left);
    int right = count(root->right);
    int count_total = left+right+1;
    return count_total;
}

int sum(struct node* root){
    if (root==NULL)
        return 0;
    int data = root->data;
    int left = sum(root->left);
    int right = sum(root->right);
    return data + left + right;
}

int maxim(struct node* root){
    if (root==NULL)
        return 0;
    int data = root->data;
    int left = maxim(root->left);
    int right = maxim(root->right);
    return data>(left>right?left:right)?data:(left>right?left:right);
}


int isbalance(struct node* root, int* height){
    if (root==NULL){
        *height = 0;
        return 1;
    }
    int lh = 0, rh = 0;
    int lb = isbalance(root->left, &lh);
    int rb = isbalance(root->right, &rh);
    *height = 1 + (lh>rh?lh:rh);
    if ((abs(lh-rh)<=1) && lb && rb){
        return 1;
    }
    else 
        return 0;
}

int max(int a, int b){
    return (a>b)?a:b;
}



int diameter(struct node* root, int* height){
    if (root==NULL){
        *height = 0;
        return 0;
    }
    int lh=0, rh=0;
    int ld = diameter(root->left, &lh);
    int rd = diameter(root->right, &rh);
    *height = 1 + (lh>rh?lh:rh);
    int dia = max(max(ld,rd),(lh+rh));
    return dia;

}

struct node* LCA(struct node* root, int p, int q){
    if (root==NULL){
        return NULL;
    }
    if (root->data==p)
        return root;
    else if (root->data==q)
        return root;

    struct node* left_node;
    struct node* right_node;
    left_node = LCA(root->left, p, q);
    right_node = LCA(root->right, p, q);

    if ((left_node!=NULL) && (right_node!=NULL))
        return root;
    else if (left_node!=NULL)
        return left_node;
    else if (right_node!=NULL)
        return right_node;
    else return NULL;
}

int main(){

    struct node* new_node = create_node(1);
    new_node->left = create_node(2);
    new_node->right = create_node(3);
    new_node->left->left = create_node(4);
    new_node->left->right = create_node(5);
    new_node->right->left = create_node(6);
    new_node->right->right= create_node(7);
    int data = 6;
    struct node* found = search_node(new_node, data);
    if (found==NULL)
        printf("value %d not found\n",data);
    else
        printf("value found %d in node\n",found->data);

    printf("sum is %d\n",sum(new_node));
    printf("count is %d\n",count(new_node));
    printf("height is %d\n",height(new_node));
    printf("maxim is %d\n",maxim(new_node));
    //checking balance 
    int height;
    if (isbalance(new_node,&height))
        printf("balanced with height %d\n",height);
    else 
        printf("not balanced\n");

    //finding diameter 
    height = 0;
    int dia = diameter(new_node,&height);
    printf("diameter is %d\n", dia);

    //finding LCA
    struct node* lca_out;
    lca_out = LCA(new_node, 4,5);
    printf("output node for LCA(4,5) is %d\n",lca_out->data);
    lca_out = LCA(new_node, 6,7);
    printf("output node for LCA(6,7) is %d\n",lca_out->data);

    return 0;
}
