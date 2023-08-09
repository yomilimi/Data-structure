#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_Size 7
typedef struct queue{
	char arr[Max_Size];
	int head;
	int tail;
	int len;
}Queue;

void init(Queue *queue){
	queue->head=-1;
	queue->tail=-1;
}

int is_full(Queue *queue){
	if(queue->tail==Max_Size-1)
		return 1;
	else
		return 0;
}

int is_empty(Queue *queue){
	if(queue->head==queue->tail)
		return 1;
	else
		return 0;
}

int check_blank(Queue *queue){
	if(is_full(queue)&&queue->head!=-1){
	return 1;
	}
	else
		return 0;
}

void shift(Queue *queue){
	int i;
	for(i=0;i<strlen(queue->arr);i++){
		queue->arr[i]=queue->arr[queue->head+1];
		(queue->head)+=1;
	}
	queue->head=-1;
	queue->tail=strlen(queue->arr)-1;
}
void print(Queue *queue){
	if(is_empty(queue)){
		printf("Queue is empty\n");
	}
	else{
  int i;
  for(i=(queue->head)+1;i<=queue->tail;i++){
    printf("%c ",queue->arr[i]);}
  printf("\n");}
}

void enqueue(Queue *queue, char input[]){
	int i;
	for(i=0;i<strlen(input);i++){
	if(input[i]=='+'){
	if(is_full(queue)&&is_empty(queue)){
		init(queue);
		(queue->tail)+=1;
		queue->arr[queue->tail]=input[i+1];
	}
	else if(is_full(queue)){
		if(check_blank(queue)){
					shift(queue);
					(queue->tail)+=1;
					queue->arr[queue->tail]=input[i+1];
				}
		else
			printf("Queue is full\n");
			return;
	}
	else{
		(queue->tail)+=1;
		queue->arr[queue->tail]=input[i+1];
	}
	}
	}
}

void peek(Queue *queue){
	printf("%c\n",queue->arr[queue->head+1]);
}

void dequeue(Queue *queue, char input[]){
	int i;
	for(i=0;i<strlen(input);i++){
		if(input[i]=='-'){
		 printf("return %c\n",queue->arr[queue->head+1]);
		 (queue->head)+=1;	
		}
	}
}

void cdequeue(Queue *queue){
	
	printf("return %c\n",queue->arr[queue->head+1]);
	(queue->head)+=1;
}
void data_count(Queue *queue){
	printf("%d\n",queue->tail-queue->head);
}

void head(Queue *queue){
	printf("%d\n",queue->head+2);
}

void tail(Queue *queue){
	printf("%d\n",queue->tail+1);
}

void is_member(Queue *queue, char input[]){
	int i=queue->head+1;
	int len=queue->tail-queue->head;
	int n=0;
	while(i<=queue->tail){
		if(queue->arr[i]==input[1]){
			break;
		}
		else{
			n+=1;
		}
		i+=1;
	}
	if(n==len){
		printf("FALSE\n");
	}
	else{
		printf("TRUE\n");
	}
}

void replace(Queue *queue, char input[]){
	queue->arr[queue->tail]=input[1];
}

void upper(Queue *queue){
	queue->arr[queue->tail]-=32;
}

void lower(Queue *queue){
	queue->arr[queue->tail]+=32;
}

void menu(){
	printf("----------------stack Menu----------------\n");
	printf("+(data): enqueue\n");
	printf("L: print queue\n");
	printf("P: peek data\n");
	printf("-: dequeue one data\n");
	printf("F: is full?\n");
	printf("#: data count\n");
	printf("T: tail\n");
	printf("H: head\n");
	printf("(number)-: dequeue number of data\n");
	printf("?(data): is member?\n");
	printf("=(data): replace data\n");
	printf("C: clear queue\n");
	printf("M: veiw menu\n");
	printf("U: upper case\n");
	printf("l: lower case\n");
	printf("Q: Quit\n");
	printf("E: is empty?\n");
}

int main(){
	menu();
	Queue *queue= (Queue*)malloc(sizeof(queue));
	init(queue);
	while(1){
		char input[10];
		gets(input);
		if(input[0]=='+'){
			if(is_full(queue)){
				if(check_blank(queue)){
					shift(queue);
					enqueue(queue,input);
					print(queue);
				}
				else
					printf("Queue is full\n");
				}
			else{
				enqueue(queue,input);
				print(queue);
				}
			}
		else if(input[0]=='P'){
			if(is_empty(queue)){
				printf("Queue is empty\n");
			}
			else{
				peek(queue);
			}
		}
		else if(input[0]=='-'){
			if(is_empty(queue)){
				printf("Queue is empty\n");
			}
			else{
				dequeue(queue,input);
				print(queue);}
			}
		else if(input[0]=='L'){
				print(queue);
			}
		else if(input[0]=='F'){
			if(is_full(queue)){
			if(check_blank(queue)){
				printf("False\n");
			}
			else{
				printf("True\n");
			}
			}
			else{
				printf("False\n");
			}
		}
		else if(input[0]=='E'){
			if(is_empty(queue)){
				printf("True\n");
			}
			else{
				printf("False\n");
			}
		}
		else if(input[0]=='#'){
			data_count(queue);
		}
		else if(input[0]=='H'){
			if(is_empty(queue)){
				printf("-1");
			}
			else{
				head(queue);
			}
		}
		else if(input[0]=='T'){
			if(is_empty(queue)){
				printf("-1");
			}
			else{
				tail(queue);
			}
		}
		else if(input[0]=='?'){
			if(is_empty(queue)){
				printf("Queue is empty\n");
			}
			else{
				is_member(queue,input);
			}
		}
		else if(input[0]=='='){
			if(is_empty(queue)){
				printf("Queue is empty\n");
			}
			else{
				replace(queue,input);
				print(queue);
			}
		}
		else if(input[0]=='C'){
			init(queue);
			printf("Queue is empty\n");
		}
		else if(input[0]=='U'){
			if(is_empty(queue)){
				printf("Queue is empty\n");
			}
			else{
				upper(queue);
				print(queue);
			}
		}
		else if(input[0]=='l'){
			if(is_empty(queue)){
				printf("Queue is empty\n");
			}
			else{
				lower(queue);
				print(queue);
			}
		}
		else if(input[0]=='Q'){
			break;
		}
		else if(input[0]=='M'){
			menu();
		}
		else{
			if(input[1]=='-'){
				int n,i;
				n=atoi(&input[0]);
				for(i=0;i<n;i++){
					if(is_empty(queue)){
						printf("Queue is empty");
						break;
					}
					else{
						cdequeue(queue);
					}
				}
				if(is_empty(queue)){
					printf("\n");
				}
				else{
					print(queue);
				}
			}
		}
		}
}