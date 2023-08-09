#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    char data;
    struct Node *left;
    struct Node *right;
} NODE;

void init_node(NODE* node){
    if (node==NULL){
        return;
    }
    node->left=NULL;
    node->right=NULL;
}

void insert_node(NODE *parent, char input){
    NODE * node =(NODE*)malloc(sizeof(NODE));
    node->right=NULL;
    node->left=NULL;
    node->data=input;

    if (parent->left==NULL){
        parent->left=node;
        return;
    }
    else{
        NODE * cur =parent->left;
        while (cur->right!=NULL){
            cur=cur->right;
        }
        cur->right=node;
    }
}

void insert_sibling(NODE *si, char input){
    NODE * node=(NODE*)malloc(sizeof(NODE));
    node->right=NULL;
    node->left=NULL;
    node->data=input;
    NODE *cur=si;
    while (cur->right!=NULL){
        cur=cur->right;
    }
    cur->right=node;
}

void print(NODE *n1, NODE *n2){
    NODE *cur=n2->left;
    if (n1==n2){
        printf("%c",n1->data);
    }
    if (n1->left==NULL){
        printf("\n");
        return;
    }
    printf("(");
    while (cur!=NULL){
        printf("%c",cur->data);
        if (cur->left!=NULL)
            print(n1,cur);
        if (cur->right!=NULL)
            printf(",");
        cur=cur->right;   
    }
    printf(")");
    if (n1==n2){
        printf("\n");
    }
}

NODE* search_node(NODE* root, char input){
    if (root==NULL)
        return NULL;
    if (root->data==input)
        return root;

    NODE *cur;
    cur=search_node(root->left,input);
    if (cur!=NULL)
        return cur;
    cur = search_node(root->right,input);
    if (cur!=NULL)
        return cur;
    return NULL;
}   

int is_leftchild(NODE* parent, NODE* node){
    if (parent->left==node)
        return 1;
    else
        return 0;
}

int is_rightchild(NODE* parent, NODE* node){
    if (parent->right==node)
        return 1;
    else 
        return 0;
}

NODE* get_bparent(NODE *root, NODE *node){
    if (root == NULL)
        return NULL;
    if (root->left==node || root->right==node)
        return root;
    NODE *cur;
    cur=get_bparent(root->left,node);
    if (cur!=NULL)
        return cur;
    cur = get_bparent(root->right,node);
    if (cur!=NULL)
        return cur;
    return NULL;
}

NODE* get_parent(NODE* root, NODE* node){
    if (get_bparent(root,node)==NULL)
        return NULL;
    NODE *cur = node;
    while (is_leftchild(get_bparent(root, cur),cur)!=1){
        cur = get_bparent(root,cur);
    }
    return get_bparent(root,cur);
}

void get_child(NODE* parent){

    if (parent->left==NULL){
        printf("NO CHILD\n");
        return;
    }
    NODE* cur=parent->left;
    printf("{");
    int st=0;
    while (cur != NULL){
        
            if(st!=0) 	printf(",");
			else 		st+=1;
            printf("%c", cur->data);
		
        cur = cur->right;
    }
    printf("}\n");
}

void get_sibling(NODE* root, NODE* node){
    NODE* cur = get_parent(root, node);
    if (cur == NULL){
        printf("%c IS ROOT NODE\n", node->data);
        return;
    }
    cur = cur->left;
	printf("{");
    int st=0;
    while (cur != NULL){
        if (cur->data != node->data)
		{
            if(st!=0) 	printf(",");
			else 		st+=1;
            printf("%c", cur->data);
		}
        cur = cur->right;
    }
    printf("}\n");
}

int level_of_node(NODE* root, NODE* node){
    int l=0;
    NODE* cur=node;
    while (cur!=root){
        cur=get_parent(root,cur);
        l++;
    }
    return l;
}

void level_of_tree(NODE* root, NODE* node, int* l){
    if (node != NULL){
        level_of_tree(root, node->left, l);
        level_of_tree(root, node->right, l);
        if (level_of_node(root, node) > *l)
            *l = level_of_node(root, node);
    }
    return;
}

void delete_node(NODE* root, NODE *node){
    if (node->left!=NULL){
        printf("%c IS PARENT NODE. CANT DELETE.\n",node->data);
        return;
    }

    NODE* parent=get_bparent(root, node);
    if (node->right==NULL){ 
        if(is_leftchild(parent,node)){
            parent->left=NULL;
        }
        else{
            parent->right=NULL;
        }
        free(node);
    }
    else{ 
        NODE *child=node->right;
        if (is_leftchild(parent,node)){
            parent->left=child;
        }
        else{
            parent->right=child;
        }
        free(node);
    }
}

void get_ancestors(NODE* root, NODE* node){
    if (root == node){
        printf("NO ANCESTORS\n");
        return;
    }
    NODE* cur=node;
    while (cur!=root){
        cur=get_parent(root,cur);
        printf("%c ",cur->data);
    }
    printf("\n");
}

void get_descendants(NODE* node){
    char temp = node->data;
    node->data = 8; 
    print(node,node);
    node->data =temp;
}

int degree_of_node(NODE* node){
    int d=0;
    NODE* cur=node->left;
    while(cur!=NULL){
        d++;
        cur = cur->right;
    }
    return d;
}

void degree_of_tree(NODE* root, int* d){
    if (root != NULL){
        degree_of_tree(root->left, d);
        degree_of_tree(root->right, d);
        if (degree_of_node(root) > *d){
            *d =degree_of_node(root);
        }
    }
    return;
}

int count_child(NODE* node){
    if (node==NULL)
        return -1;
    else if (node->left==NULL)
        return 0;
    else{
        int num=0;
        NODE* cur=node->left;
        while (cur!=NULL){
            cur=cur->right;
            num++;
        }
        return num;
    }
}

int count_node(NODE* root){
    if (root!=NULL){
        return 1 + count_node(root->left) + count_node(root->right);
    }
    return 0;
}

NODE* copy_tree(NODE* root){
    if (root != NULL){
        NODE* node = (NODE*)malloc(sizeof(NODE));
        node->data = root->data;
        node->left = copy_tree(root->left);
        node->right = copy_tree(root->right);
        return node;
    }
    return NULL;
}

NODE* join_trees(NODE* newroot, NODE* root1, NODE* root2){
    NODE* node1 = copy_tree(root1);
    NODE* node2 = copy_tree(root2);
    newroot->left = node1;
    node1->right = node2;
    return newroot;
}

void clear(NODE** root, NODE* node){ 
    if (node!=NULL){
        clear(root,node->left);
        clear(root,node->right);
        free(node);
    }
    return;
}

void gt_to_bt(NODE* root) {
  if (root == NULL)
		return;
	if (root->right == NULL && root->left == NULL)
		return;
	printf("(");
	if (root->left != NULL)
		printf("%c", root->left->data);
	gt_to_bt(root->left);
	printf(",");
	if (root->right != NULL)
		printf("%c", root->right->data);
	gt_to_bt(root->right);
	printf(")");
}

void menu(){
  	printf("+data: make root node\n");
    printf("+data(data): insert child node\n");
    printf("-data: delete node\n");
    printf("=+data(data): insert sibling\n");
    printf("P(data): get parent\n");
    printf("C(data): get child\n");
    printf("S(data): get sibling\n");
    printf("A(data): get ancestors\n");
    printf("D(data): get descendants\n");
    printf("L: level of tree\n");
    printf("L(data): level of data\n");
    printf("G: degree of tree\n");
    printf("G(data): degree of data\n");
    printf("#: count node\n");
    printf("J(newrootrootroot): join tree\n");
    printf("K: clear tree\n");
    printf("T: print tree\n");
    printf("Q: QUIT\n");
    printf("B: Change to binary tree\n");
    
}

int main(){
    NODE* roots[10];
    int idx=-1;
    int len=0;
    int ib=0;
    menu();
    printf("choose binary tree 1/ genaral tree 0: ");
    scanf("%d",&ib);
    getchar();
    while (1){
        char input[30];
        printf(">>");
        gets(input);
        if (input[0]=='Q'){
            break;
        }
        int i;
        for (i = 0;input[i]!='\0';i++){
          if(input[i]=='+'){
            if (input[i+2]=='('){
                    NODE* node=search_node(roots[idx], input[i+1]);
                    if (node==NULL){
                        printf("%c is not exist\n",input[i+1]);
                    }
                    else{
                        i += 3;
                        while (input[i]!=')'){
                            if (ib==1&&count_child(node)==2){
                                printf("error\n");
                                break;
                            }
                            insert_node(node,input[i]);
                            i++;
                        }
                    }
                    while (input[i]!=')')
                        i++;
                }
            else{
                    NODE* root = (NODE*)malloc(sizeof(NODE));
                    init_node(root);
                    root->data=input[i+1];
                    idx=len;
                    roots[idx]=root;
                    len++;
                    i += 2;
                }
          }
            else if (input[i]=='T'){
                if (idx==-1){
                    printf("NO TREE\n");
                }
                else{
                    print(roots[idx],roots[idx]);
                }
            }
            else if (input[i]=='-'){
                NODE* node=search_node(roots[idx],input[i+1]);
                if (node==NULL){
                    printf("%c is not exist\n",input[i+1]);
                }
                else{
                    delete_node(roots[idx],node);
                }
                i++;
            }
            else if (input[i]=='='&&input[i+1]=='+'){
                NODE* node=search_node(roots[idx],input[i+2]);
                if (node==NULL){
                    printf("%c is not exist\n",input[i+2]);
                }
                else{
                    i += 4;
                    while (input[i] !=')'){
                        if (ib== 1&&count_child(get_parent(roots[idx],node))==2){
                            printf("error\n");
                            break;
                        }
                        insert_sibling(node,input[i]);
                        i++;
                    }
                }
                while (input[i]!=')')
                    i++;
            }
            else if (input[i]=='P'){
                NODE* parent = get_parent(roots[idx],search_node(roots[idx],input[i+2]));
                if (parent==NULL){
                    printf("error\n");
                }
                else{
                    printf("%c\n",parent->data);
                }
                i += 3;
            }
            else if (input[i]=='C'){
                if (search_node(roots[idx],input[i+2])==NULL){
                    printf("%c is not exist\n",input[i+2]);
                }
                else
                    get_child(search_node(roots[idx],input[i+2]));
                i += 3;
            }
            else if (input[i] == 'S'){
                NODE* node=search_node(roots[idx],input[i+2]);

                if (node == NULL){
                    printf("%c is not exist\n",input[i+2]);
                }
                else{
                    get_sibling(roots[idx],node);
                }
                i += 3;
            }
            else if (input[i]=='A'){
                NODE* node=search_node(roots[idx],input[i+2]);
                
                if (node==NULL){
                    printf("%c is not exist\n",input[i+2]);
                }
                else{
                    get_ancestors(roots[idx],node);
                }
                i += 3;
            }
            else if (input[i]=='D'){
                NODE* node=search_node(roots[idx],input[i+2]);

                if (node==NULL){
                    printf("%c is not exist\n",input[i+2]);
                }
                else{
                    get_descendants(node);
                }
                i += 3;
            }

          else if (input[i]=='L'){
                if (input[i+1]=='('){
                    NODE *node=search_node(roots[idx],input[i+2]);
                    if (node==NULL){
                        printf("%c is not exist\n",input[i+2]);
                    }
                    else{
                        printf("level of node: %d\n",level_of_node(roots[idx],node));
                    }
                    i += 3;
                }
                else{
                    int level=0;
                    level_of_tree(roots[idx],roots[idx],&level);
                    printf("level of tree: %d\n",level);
                }
            }
           else if (input[i]=='G'){
                if (input[i+1]=='('){
                    NODE* node=search_node(roots[idx],input[i+2]);
                    if (node==NULL){
                        printf("%c is not exist\n",input[i+2]);
                    }
                    else{
                        printf("degree: %d\n",degree_of_node(node));
                    }
                    i += 3;
                }
                else{
                    int degree=0;
                    degree_of_tree(roots[idx],&degree);
                    printf("degree: %d\n",degree);
                }
            } 
            else if (input[i]=='#'){
                printf("%d\n",count_node(roots[idx]));
                
            }
            else if (input[i] == 'J'){
                int idx1 = -1;
                int idx2 = -1;
                int j;
                for(j = 0; j < len; j++){
                    if (roots[j]->data == input[i+3])
                        idx1 = j;
                    else if (roots[j]->data == input[i+4])
                        idx2 = j;
                }
                if (idx1 == -1 || idx2 == -1){
                    printf("ERROR\n");
                }
                else{
                    idx = len;
                    NODE* newroot = (NODE*)malloc(sizeof(NODE));
                    init_node(newroot);
                    newroot->data = input[i+2];
                    roots[idx] = join_trees(newroot, roots[idx1], roots[idx2]);
                    len++;
                }
                i += 5;
            }
            else if (input[i]=='K'){
                if (idx==-1){
                    printf("tree is not exist\n");
                }
                else{
                    clear(&roots[idx],roots[idx]);
                    int j;
                    for (j=idx;j < len;j++){
                        roots[j]=roots[j + 1];
                    }
                    len--;
                    if (len==idx){
                        idx--;
                    }
                }    
            }
		//일반트리의 sibling끼리 right로 연결되어 있어 이미 binnary tree형태이기 때문에 출력만 다르게 함 
          else if(input[i]=='B'){//binary tree로 전환
            if(ib==1){
              printf("Already binary tree\n");
            }
            else{
              printf("(%c",roots[idx]->data);
              gt_to_bt(roots[idx]);
              printf(")\n");
            }
          }
        }//for
    }//while
}//main