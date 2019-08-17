#include <stdio.h>

typedef struct node Node;
struct node{
    int data;
    Node *parent;
    Node *left;
    Node *right;
};

Node *create_node(int item){
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error! Could Not Create A New Node\n");
        exit(1);
    }
    
    new_node->data = item;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return new_node;
}

void add_left_child(Node *node, Node *child){
    node->left = child;
    if (child != NULL) {
        child->parent = node;
    }
}

void add_right_child(Node *node, Node *child){
    node->right = child;
    if (child != NULL) {
        child->parent = node;
    }
}

/*
         _10_
        /   \
       5    17
     / \   /  \
    3   7 12   19
   / \      \
  1   4     13
 
 */

Node *bst_insert(Node *root, Node *node){
    
    Node *parent_node, *current_node;
    
    if (root == NULL) {
        root = node;
        return root;
    }
    
    parent_node = NULL;
    
    current_node = root;
    
    while (current_node != NULL) {
        parent_node = current_node;
        
        if (node->data < current_node->data) {
            current_node = current_node->left;
        }else{
            current_node = current_node->right;
        }
    }
    
    if (node->data < parent_node->data) {
        add_left_child(parent_node, node);
    }else{
        add_right_child(parent_node, node);
    }
    
    return root;
    
}

Node *create_bst(){
    Node *root, *node;

    int ara[] = {5, 17, 3, 7, 12, 19, 1, 4};
    
    //create root node by 10
    root = create_node(10);
    
    for (int i = 0; i < 8; i++) {
        node = create_node(ara[i]);
        
        root = bst_insert(root, node);
    }
    
    return root;
}

Node *bst_search(Node *root, int item){
    
    Node *node = root;
    while (node != NULL) {
        if (node->data == item) {
            return node;
        }
        
        if (item < node->data) {
            node = node->left;
        }else{
            node = node->right;
        }
    }
    
    return node;
}

Node *bst_minimum(Node *root, int item){
    
    Node *node = root;
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

Node *bst_maximum(Node *root, int item){
    
    Node *node = root;
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}

int main(int argc, const char * argv[]) {
    
    Node *root = create_bst();
    
    Node *node;
    
    node = bst_search(root, 7);
    if (node != NULL) {
        printf("%d is found!\n", node->data);
    }else{
        printf("%d is not found!\n", 7);
    }
    
    node = bst_search(root, 8);
    if (node != NULL) {
        printf("%d is found!\n", node->data);
    }else{
        printf("%d is not found!\n", 8);
    }
    
    printf("\n");
    
    
    return 0;
}
