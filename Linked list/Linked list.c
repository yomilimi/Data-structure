#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node{
	char data;
	struct Node* next;
	struct Node* prev;
};

struct Node* start=NULL;
struct Node* cur = NULL;
struct Node* new_node = NULL;
struct Node* tail=NULL;
int i;

void print(struct Node* n){
	while(n!=NULL){
    if(n==cur){
      printf("(%c) ",n->data);}
    else{
		printf("%c ",n->data);}
		n=n->next;
	}
	if(start==NULL){
		printf("리스트가 비었습니다.");
	}
}

void addTail(char ip[]){
  for(i=1;i<strlen(ip);i++){
	if(ip[i]=='+'){
		if(start==NULL){
        new_node=(struct Node*)malloc(sizeof(struct Node));
        new_node->data=ip[i+1];
		new_node->next=NULL;
		new_node->prev=NULL;
		cur=new_node;
        start=new_node;
      }
    	else{
      	for(cur=start;cur->next!=NULL;cur=cur->next);
      	new_node=(struct Node*)malloc(sizeof(struct Node));
      	new_node->data=ip[i+1];
      	cur->next=new_node;
      	new_node->prev=cur;
      	new_node->next=NULL;
      	cur=new_node;
	  }
	}		
	}
	print(start);
}

void add(char ip[]){
  i=0;
			while(i<strlen(ip)){
				if(i==0){
					if(ip[i]=='+'){
						if(start==NULL){
							new_node=(struct Node*)malloc(sizeof(struct Node));
							new_node->data=ip[i+1];
							new_node->next=NULL;
							new_node->prev=NULL;
							start=new_node;
							cur=new_node;
						}
						else if(cur->prev==NULL){
							new_node=(struct Node*)malloc(sizeof(struct Node));
							new_node->data=ip[i+1];
							cur->prev=new_node;
							new_node->next=cur;
							new_node->prev=NULL;
							cur=new_node;
							start=new_node;
						}
						else{
							new_node=(struct Node*)malloc(sizeof(struct Node));
							new_node->data=ip[i+1];
							cur->prev->next=new_node;
							new_node->next=cur;
							new_node->prev=cur->prev;
							cur->prev=new_node;
							cur=new_node;
						}
					}
				}
				if(i>0){
					if(ip[i]=='+'){
						
						if(cur->next==NULL){
							new_node=(struct Node*)malloc(sizeof(struct Node));
							new_node->data=ip[i+1];
							cur->next=new_node;
							new_node->prev=cur;
							new_node->next=NULL;
							cur=new_node;
						}
						else{
							new_node=(struct Node*)malloc(sizeof(struct Node));
							new_node->data=ip[i+1];
							cur->next->prev=new_node;
							new_node->prev=cur;
							new_node->next=cur->next;
							cur->next=new_node;
							cur=new_node;
						}
					}
					}
				i+=1;
			}
			print(start);
}

void Nextadd(char ip[]){
  for(i=0;i<strlen(ip);i++){
				if(ip[i]=='+'){
				if(start==NULL){
							new_node=(struct Node*)malloc(sizeof(struct Node));
							new_node->data=ip[i+1];
							new_node->next=NULL;
							new_node->prev=NULL;
							start=new_node;
							cur=new_node;
						}
				else if(cur->next==NULL){
							new_node=(struct Node*)malloc(sizeof(struct Node));
							new_node->data=ip[i+1];
							cur->next=new_node;
							new_node->prev=cur;
							new_node->next=NULL;
							cur=new_node;
						}
				else{
							new_node=(struct Node*)malloc(sizeof(struct Node));
							new_node->data=ip[i+1];
							cur->next->prev=new_node;
							new_node->prev=cur;
							new_node->next=cur->next;
							cur->next=new_node;
							cur=new_node;
							}
			}
		}
			print(start);
}

void get_data(char ip[]){
	if(start==NULL){
		printf("리스트가 비어있습니다.");
	}
	else{
	 printf("%c",cur->data);}
  }

void traverse_front_add(char ip[]){
  cur=start;
  start=cur;
  if(start==NULL){
  	printf("리스트가 비어있습니다.");
  }
  else{
  for(i=0;i<strlen(ip);i++){
    if(ip[i]=='N'){
      cur=cur->next;
    }

    if(i==2){
      if(ip[i]=='+'){
        new_node=(struct Node*)malloc(sizeof(struct Node));
        new_node->data=ip[i+1];
        cur->prev=new_node;
        new_node->next=cur;
        new_node->prev=NULL;
        cur=new_node;
        start=new_node;
      }}
    if(i>2){
      if(ip[i]=='+'){
         new_node=(struct Node*)malloc(sizeof(struct Node));
					new_node->data=ip[i+1];
					cur->next->prev=new_node;
					new_node->prev=cur;
					new_node->next=cur->next;
					cur->next=new_node;
					cur=new_node;
      }
    }
	}}
  print(start);
}

void delete(){
if(is_empty()){
  	printf("리스트가 비어있습니다.");
  }
  else{
 if(cur->next==NULL&&cur->prev!=NULL){
    cur->prev->next=NULL;
    cur=start;
    start=cur;
  }
  else if(cur->prev==NULL&&cur->next!=NULL){
    cur->next->prev=NULL;
    cur=cur->next;
    start=cur;
    cur=start;
  }
  else if(cur->next==NULL&&cur->prev==NULL){
  	cur=NULL;
    start=NULL;
  }
  else{
    cur->prev->next=cur->next;
    cur->next->prev=cur->prev;
    cur=cur->next;
  }
  print(start);}
}

void traverse_rear_delete(char ip[]){
  for(cur=start;cur->next!=NULL;cur=cur->next);
  for(i=0;i<strlen(ip);i++){
    if(ip[i]=='-'){
      cur->prev->next=NULL;
      cur=start;
    }
  }
  print(start);
}

void replace(char ip[]){
	if(is_empty()){
  	printf("리스트가 비어있습니다.");
  }
  else if(cur->prev==NULL){
    new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=ip[1];
    cur->next->prev=new_node;
    new_node->next=cur->next;
    new_node->prev=NULL;
    cur=new_node;
    start=new_node;
  }
  else if(cur->next==NULL){
    new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=ip[1];
    cur->prev->next=new_node;
    cur->prev=new_node->prev;
    new_node->next=NULL;
    cur=new_node;
  }
  else{
    new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=ip[1];
    cur->prev->next=new_node;
    new_node->prev=cur->prev;
    new_node->next=cur->next;
    cur->next->prev=new_node;
    cur=new_node;
  }
  print(start);
}

int data_count(){
	int c=1;
	if(start==NULL){
		printf("0");
	}
	else{
	for(cur=start;cur->next!=NULL;cur=cur->next){
		c+=1;
	}
	printf("%d",c);}
}

void is_member(char ip[]){
  if(is_empty()){
  	printf("리스트가 비어있습니다.");
  }
  else{
  int m=1;
  cur=start;
  start=cur;
	while(1){
    if(start->data==ip[1]){
      m=0;
      printf("1");
      break;
    }
    else if(cur->data==ip[1]){
      printf("%d",m);
      break;
    }
    if(cur->next==NULL){
      if(cur->data==ip[1]){
      printf("%d",m);
      break;
      }
      else{
        printf("리스트에 %c 없음",ip[1]);
        break;
      }
    }
    cur=cur->next;
    m+=1;
  }}
}

void clear(){
 	if(is_empty()){
  	printf("리스트가 비어있습니다.");
  }
	else{start=NULL;
  	 if(cur->next==NULL&&cur->prev!=NULL){
    cur->prev->next=NULL;
    cur=start;
    start=cur;
  }
  else if(cur->prev==NULL&&cur->next!=NULL){
    cur->next->prev=NULL;
    cur=cur->next;
    start=cur;
    cur=start;
  }
  else if(cur->next==NULL&&cur->prev==NULL){
  	cur=NULL;
    start=NULL;
  }
  else{
    cur->prev->next=cur->next;
    cur->next->prev=cur->prev;
    cur=cur->next;
  }
printf("리스트를 비웠습니다.");} 
}

int is_empty(){
	if(start==NULL){
		return 1;
	}
	else{
		return 0;
	}
}

void trverse_front_get(char ip[]){
  if(is_empty()){
  	printf("리스트가 비어있습니다.");
  }
  else{
  int id,y;
  y=1;
  id=atoi(&ip[0])-1;
  cur=start;
  while(cur->next!=NULL){
  	y+=1;
  	cur=cur->next;
  }
  if(id+1>y){
  	printf("인덱스 범위가 초과되었습니다.");
  }
  if(id<0){
  	printf("인덱스가 범위보다 작습니다.");
	    }
  if(id+1<=y&&id>=0){
  cur=start;
  for(i=0;i<id;i++){
    cur=cur->next;
  } 
	printf("%c",cur->data);}}
}

void traverse_front_replace(char ip[]){
  if(is_empty()){
  	printf("리스트가 비어있습니다.");
  }
  else{
  int rid,u;
  u=1;
  rid=atoi(&ip[0])-1;
  cur=start;
  while(cur->next!=NULL){
  	u+=1;
  	cur=cur->next;
  }
  if(rid+1>u){
  	printf("인덱스 범위가 초과되었습니다.");
  }
  if(rid<0){
  	printf("인덱스가 범위보다 작습니다.");
  }
  if(rid+1<=u&&rid>=0){
  cur=start;
  for(i=0;i<rid;i++){
    cur=cur->next;
  }
  if(cur->prev==NULL){
    new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=ip[2];
    cur->next->prev=new_node;
    new_node->next=cur->next;
    new_node->prev=NULL;
    cur=new_node;
    start=new_node;
  }
  else if(cur->next==NULL){
    new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=ip[2];
    cur->prev->next=new_node;
    cur->prev=new_node->prev;
    new_node->next=NULL;
    cur=new_node;
  }
  else{
    new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=ip[2];
    cur->prev->next=new_node;
    new_node->prev=cur->prev;
    new_node->next=cur->next;
    cur->next->prev=new_node;
    cur=new_node;
  }
  print(start);}}
}

void upper(){
	printf("%c",cur->data-=32);
}

void lower(){
	printf("%c",cur->data+=32);
}

void Menu(){
	printf("========================menu========================\n");
	printf("addTail                          : t +(data)\n");
	printf("print                            : L\n");
	printf("get data                         : G\n");
	printf("traverse front                   : <(N)\n");
	printf("N은 다음 인덱스로 한 칸 이동을 뜻\n");
	printf("delete                           : -\n");
	printf("add current position             : +(data)\n");
	printf("add next position                : N +(data)\n");
	printf("delete last                      : > -\n");
	printf("add first position               : < +(data)\n");
	printf("replace current position         : =(data)\n");
	printf("get designated position data     : (index)G\n");
	printf("data count                       : #\n");
	printf("is member                        : ?(data)\n");
	printf("replace designated position data : (index)=(data)\n");
	printf("clear the list                   : C\n");
	printf("is empty                         : E\n");
	printf("upper case                       : U\n");
	printf("lower case                       : l\n");
	printf("view menu                        : M\n");
	printf("Quit                             : Q\n");
}
int main() {
	Menu();
	while(1){
		char ip[30]={};
		gets(ip);
		if(ip[0]=='t'){	
	    addTail(ip);
		}
		else if(ip[0]=='+'){
			add(ip);
		}
		else if(ip[0]=='N'){
			Nextadd(ip);
		}
		else if(ip[0]=='L'){
			print(start);
		}
	    else if(ip[0]=='G'){
	      get_data(ip);
	    }
	    else if(ip[0]=='<'){
	      traverse_front_add(ip);
	    }
	    else if(ip[0]=='-'){
	      delete();
	    }
	    else if(ip[0]=='>'){
	      traverse_rear_delete(ip);
	    }
	    else if(ip[0]=='='){
	      replace(ip);
	    }
	    else if(ip[0]=='#'){
	    	data_count();
		}
		else if(ip[0]=='?'){
			is_member(ip);
		}
		else if(ip[0]=='C'){
			clear();
		}
		else if(ip[0]=='E'){
			if(is_empty()){
				printf("TRUE");
			}
			else{
				printf("FALSE");
			}
		}
		else if(ip[0]=='U'){
			upper();
		}
		else if(ip[0]=='l'){
			lower();
		}
		else if(ip[0]=='V'){
			Menu();
		}
		else if(ip[0]=='Q'){
			break;
		}
    else{
      if(ip[1]=='G'){
        trverse_front_get(ip);
      }
      if(ip[1]=='='){
        traverse_front_replace(ip);
      }
    }
	}
}