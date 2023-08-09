#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}NODE;

void init_node(NODE* node, int n){
	node->left=NULL;
	node->right=NULL;
	node->data=n;
}

NODE* find_node(NODE* cur, int n){
	while (cur != NULL) {
		if (cur->data == n) {
			return cur;
		}
		else if (cur->data > n)
			cur = cur->left;
		else
			cur = cur->right;
	}
  return NULL;
}

int search_node(NODE* cur, int n){
	while (cur != NULL) {
		if (cur->data == n) {
			return 1;
		}
		else if (cur->data > n)
			cur = cur->left;
		else
			cur = cur->right;
	}
  return 0;
}
int get_height(NODE* node){
	if(node==NULL){
		return 0;
	}
	int leftheight;
	int rightheight;
	leftheight=get_height(node->left);
	rightheight=get_height(node->right);
	if(leftheight>rightheight)
		return leftheight+1;
	else
		return rightheight+1;
}

int balancing_factor(NODE* node){
	return get_height(node->left)-get_height(node->right);
}

void print_tree(NODE* root) {
	if (root == NULL)
		return;
	if (root->right == NULL && root->left == NULL)
		return;
	printf("(");
	if (root->left != NULL)
		printf("%d", root->left->data);
	print_tree(root->left);
	printf(",");
	if (root->right != NULL)
		printf("%d", root->right->data);
	print_tree(root->right);
	printf(")");
}

NODE* rotate_LL(NODE* parent) { 
	NODE* child = parent->left;
	parent->left = child->right; 
	child->right = parent; 
	return child;
}

NODE* rotate_RR(NODE* parent) { 
	NODE* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

NODE* rotate_LR(NODE* parent) { 
	NODE* child = parent->left;
	parent->left = rotate_RR(child); 
	return rotate_LL(parent); 
}

NODE* rotate_RL(NODE* parent) { 
	NODE* child = parent->right;
	parent->right = rotate_LL(child);
	return rotate_RR(parent);
}

NODE* balance_tree(NODE** node) { 
	int height =  balancing_factor(*node); 
	if (height > 1) { 
		if (balancing_factor((*node)->left) > 0) { 
			*node = rotate_LL(*node); 
		}
		else {
			*node = rotate_LR(*node); 
		}
	}
	else if (height < -1) {
		if (balancing_factor((*node)->right) < 0) { 
			*node = rotate_RR(*node); 
		}
		else {
			*node = rotate_RL(*node); 
		}
	}
	return *node;
}

NODE* insert(NODE** node, int key) {
	if (*node == NULL) {
		*node = (NODE*)malloc(sizeof(NODE));
		init_node(*node,key);
	}
	else if (key < (*node)->data) {
		(*node)->left = insert(&(*node)->left, key); 
		(*node) = balance_tree(node); 
	}
	else if (key > (*node)->data) {
		(*node)->right = insert(&(*node)->right, key); 
		(*node) = balance_tree(node); 
	}
	else {
		printf("Data exist\n");
	}
	return *node; 
}

void inorder_traversal(NODE* root){
  if(root!=NULL){
    inorder_traversal(root->left);
    printf("%d ",root->data);
    inorder_traversal(root->right);
  } 
}

void right_root_left_traversal(NODE* root){
  if(root!=NULL){
  right_root_left_traversal(root->right);
  printf("%d ",root->data);
  right_root_left_traversal(root->left);
  } 
}

void print_find_node(NODE* cur, int n){
	printf("Root ");
	while(1){
		if(cur->data<n){
			cur=cur->right;
			printf("Right ");
		}
		if(cur->data>n){
			cur=cur->left;
			printf("Left ");
		}
		if(cur->data==n){
			break;
		}
	}
	printf("\n");
}

void get_min(NODE* root){
  NODE* cur=root;
  while(cur->left!=NULL){
    cur=cur->left;
  }
  printf("%d\n", cur->data);
}

void get_max(NODE* root){
  NODE* cur=root;
  while(cur->right!=NULL){
    cur=cur->right;
  }
  printf("%d\n", cur->data);
}

int count_node(NODE* root){
	if(root==NULL){
		return 0;
	}
	int leftcount;
	int rightcount;
	leftcount=count_node(root->left);
	rightcount=count_node(root->right);
	return leftcount+rightcount+1;
}

void get_right_child(NODE* root, int n){
	NODE* cur=root;
	while((cur!=NULL)&&(cur->data!=n)){
		if(cur->data<n){
			cur=cur->right;
		}
		else{
			cur=cur->left;
		}
	}
	if(cur==NULL){
		printf("Not exist\n");
	}
	else{
		if(cur->right==NULL){
			printf("NULL\n");
		}
		else{
			printf("%d\n",cur->right->data);
		}
	}
}

void get_left_child(NODE* root, int n){
	NODE* cur=root;
	while((cur!=NULL)&&(cur->data!=n)){
		if(cur->data<n){
			cur=cur->right;
		}
		else{
			cur=cur->left;
		}
	}
	if(cur==NULL){
		printf("Not exist\n");
	}
	else{
		if(cur->left==NULL){
			printf("NULL\n");
		}
		else{
			printf("%d\n",cur->left->data);
		}
	}
}

void clear (NODE* root){
    if (root != NULL){
        clear(root->left);
        clear(root->right);
        free(root);
    }
    return;
}

NODE * minValueNode(NODE* node)
{
    NODE* current = node;
    while (current->right != NULL)
        current = current->right;
    return current;
}

NODE* deleteNode(NODE* root, int key)
{
    if (root == NULL)
        return root;
    if ( key < root->data )
        root->left = deleteNode(root->left, key);
    else if( key > root->data )
        root->right = deleteNode(root->right, key);
    else
    {	if( (root->left == NULL) ||(root->right == NULL) )
        {
            NODE *temp = root->left ?root->left : root->right;
 
            if (temp == NULL)//자식x 
            {
                temp = root;
                root = NULL;
            }
            else//자식 1개 
            *root = *temp;
            free(temp);
        }
        else//자식 2개 
        {
            NODE* temp = minValueNode(root->left);//왼쪽 서브 트리중 가장 큰거 
            root->data = temp->data;
            root->left = deleteNode(root->left,temp->data);
        }
    }
    if (root == NULL)
    return root;
 
    root=balance_tree(&root);//rotation
 
    return root;
}

void menu(){
	printf("AVL Tree ADT\n");
	printf("+data: insert node\n");
    printf("-data: delete node\n");
    printf("P: print tree\n");
    printf("I: inorder traversal\n");
    printf("R: right->root->left traversal\n");
    printf("X: get max\n");
    printf("N: get min\n");
    printf("Fdata: find node\n");
    printf("T: get tree's height\n");
    printf("Hdata: get height\n");
    printf("Gdata: get right child\n");
    printf("Ldata: get left child\n");
    printf("#: count node\n");
    printf("C: clear tree\n");
	printf("Q: quit\n");
	printf("V: view menu\n");
}

int main(){
	NODE* root=NULL;
	menu();
	while(1){
    char input[3];
    char c;
	  int num;
		printf(">>");
    scanf("%c",&c);
		gets(input);
    num=atoi(input);
		if(c=='+'){
			root=insert(&root,num);
		}
		
		else if(c=='T'){
			printf("%d\n",get_height(root)-1);
		}
		
		else if(c=='H'){
			if(search_node(root,num)==1){
				printf("%d\n",get_height(find_node(root,num))-1);
			}
      else{
        printf("Not exist\n");
      }
		}
		
    else if(c=='B'){
      if(search_node(root,num)==1){
				printf("%d\n",balancing_factor(find_node(root,num)));
			}
      else{
        printf("Not exist\n");
      }
    }
    
	else if(c=='P'){
		if (root == NULL){
				printf("Tree is empty\n");
			}
		else{
				printf("(%d", root->data);
				print_tree(root);
				printf(")\n");
			}
		}
		
	else if(c=='I'){
		if (root == NULL){
				printf("Tree is empty\n");
			}
		else{
			inorder_traversal(root);
			printf("\n");
		}
	}
	
	else if(c=='R'){
		if (root == NULL){
				printf("Tree is empty\n");
			}
		else{
			right_root_left_traversal(root);
			printf("\n");
		}
	}
	
	else if(c=='F'){
		if (root == NULL){
				printf("Tree is empty\n");
			}
		else{
		if(search_node(root,num)==1){
			print_find_node(root,num);
		}
		else{
			printf("Not exist\n");
		}
		}
	}
	
	else if(c=='N'){
		if(root==NULL){
			printf("Tree is empty\n");
		}
		else{
			get_min(root);
		}
	}
	
	else if(c=='X'){
		if(root==NULL){
			printf("Tree is empty\n");
		}
		else{
			get_max(root);
		}
	}
	
	else if(c=='#'){
		if(root==NULL){
			printf("Tree is empty\n");
		}
		else{
			printf("%d\n",count_node(root));
		}
	}
	
	else if(c=='G'){
  	if(root==NULL){
      printf("Tree is empty\n");
    }
    else{
    	get_right_child(root,num);
	}
  }

  else if(c=='L'){
  	if(root==NULL){
      printf("Tree is empty\n");
    }
    else{
    	get_left_child(root,num);
	}
  }
  
  else if(c=='C'){
  	if(root==NULL){
      printf("Tree is empty\n");
    }
    else{
    	clear(root);
    	root=NULL;
	}
  }
  
  else if(c=='-'){
  	if(root==NULL){
  		printf("Tree is empty\n");
	  }
	else{
		root=deleteNode(root,num);
	}
  }
  
  else if(c=='Q'){
  	break;
  }
  
  else if(c=='V'){
  	menu();
  }
	}
}