#include <stdio.h>
#include <stdlib.h>

// code
struct TreeNode {
  int data;
  struct TreeNode* left;
  struct TreeNode* right;
};

struct TreeNode* createNode(int data){
  struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  if(newNode ==NULL){
    exit(1);
  }  
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int data){
  if(root == NULL){
    return createNode(data);
  }
  if( data < root->data){
    root->left = insert(root->left,data);
  }
  else if(data > root->data){
    root->right = insert(root->right, data);
  }
  return root;
}

void inOrderTraversal(struct TreeNode* root){
  if(root == NULL){
    return;
  }
  inOrderTraversal(root->left);
  printf("%d", root->data);
  inOrderTraversal(root->right);
}

struct TreeNode* search ( struct TreeNode* root, int key){
  if( root ==NULL || root->data == key){
    return root;
  }
  if ( key < root->data){
    return search (root->left, key);

  }
  else {
    return search(root->right, key);
  }
}
//code

int main () {
  struct TreeNode* root = NULL;
  root = insert(root,50);
  insert(root , 30);
  insert(root , 70);
  insert(root , 20);
  insert(root , 40);
  insert(root , 60);
  insert(root , 80);
  inOrderTraversal(root);
  printf("\n");
  int key = 40;
  struct TreeNode* result = search(root ,key);
  if( result != NULL){
    printf("%d\n",key);
  }
  else {
    printf("exit\n");
  }
  free(root);
  return 0;
}
