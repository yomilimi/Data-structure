#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_Size 10
typedef struct Stack{
  char arr[Max_Size];
  int top;
}Stack;

void init(Stack *stack){
  stack->top=-1;
}

void print(Stack *stack){
  if(is_empty(stack)){
  	printf("STACK IS EMPTY\n");
  }
  else{
  int i;
  for(i=0;i=stack->top;i++){
  	if(i==stack->top){
  		printf("(%c)",stack->arr[i]);
	  }
	else{
    printf("%c ",stack->arr[i]);}
  }
  printf("\n");}
}

int is_empty(Stack *stack){
  if(stack->top==-1)
    return 1;
  else
    return 0;
}

int is_full(Stack *stack){
  if((stack->top)+1==Max_Size)
    return 1;
  else
    return 0;
}

void push(Stack *stack, char ip[]){
  int i;
  if(is_full(stack)){
    printf("STACK IS FULL\n");
  }
  else{
  for(i=0;i<strlen(ip);i++){
    if(ip[i]=='+'){
      (stack->top)+=1;
      stack->arr[stack->top]=ip[i+1];
    }
  }
  print(stack);
  }
}

char peek(Stack *stack){
	if(is_empty(stack))
		return 0;
	else
		return stack->arr[stack->top];
}

void pop(Stack *stack, char ip[]){
	if(is_empty(stack))
		printf("STACK IS EMPTY\n");
	else{
		int i;
		for(i=0;i<strlen(ip);i++){
			if(ip[i]=='-'){
				printf("reurn %c\n",stack->arr[stack->top]);
				(stack->top)-=1;
			}
		}
	if(stack->top==0){
			stack->top==-1;
			printf("STACK IS CLEAR");
	}
	else{
		print(stack);
	}
	}
}

int element_count(Stack *stack){
	if(is_empty(stack)){
		return 0;
	}
	int i=0;
	while(i<=stack->top){
		i+=1;
	}
	return i;
}

char cntpop(Stack *stack){
	return stack->arr[(stack->top)--];
	
}

void is_member(Stack *stack, char ip[]){
	int i=0;
	int n=0;
	while(i<strlen(stack->arr)){
		if(stack->arr[i]==ip[1]){
			break;
		}
		else{
			n+=1;
		}
		i+=1;
	}
	if(n==strlen(stack->arr)){
		printf("FALSE\n");
	}
	else{
		printf("TRUE\n");
	}
}

void replace(Stack *stack, char ip[]){
	(stack->arr[stack->top])=ip[1];
	print(stack);
}

void clear(Stack *stack){
	stack->top=-1;
	printf("STACK IS CLEAR");
}

void upper(Stack *stack){
	(stack->arr[stack->top])-=32;
}

void lower(Stack *stack){
	(stack->arr[stack->top])+=32;
}

void menu(){
	printf("----------------stack Menu----------------\n");
	printf("+(data): push data\n");
	printf("L: print stack\n");
	printf("P: peek data\n");
	printf("-: pop one data\n");
	printf("F: is full?\n");
	printf("#: element count\n");
	printf("T: peek top of stack\n");
	printf("(number)-: pop number of data\n");
	printf("?(data): is member?\n");
	printf("=(data): replace data\n");
	printf("C: clear stack\n");
	printf("M: veiw menu\n");
	printf("U: upper case\n");
	printf("l: lower case\n");
	printf("Q: Quit\n");
	printf("E: is empty?\n");
}

int main() {
  menu();
  Stack *stack = (Stack*)malloc(sizeof(Stack));
  init(stack);
  while(1){
    char ip[10];
    gets(ip);
    if(ip[0]=='+'){
      push(stack,ip);
    }
    
    else if(ip[0]=='L'){
    	print(stack);
	}
	
	else if(ip[0]=='P'){
		if(peek(stack)==0){
			printf("STACK IS EMPTY\n");
		}
		else{
		printf("%c",peek(stack));}
	}
	
	else if(ip[0]=='-'){
		pop(stack,ip);
	}
	
	else if(ip[0]=='#'){
		if(element_count(stack)==0){
			printf("STACK IS EMPTY\n");
		}
		else{
		printf("%d\n",element_count(stack));}
	}
	
	else if(ip[0]=='T'){
		if(is_empty(stack)){
			printf("STACK IS EMPTY\n");
		}
		else{
		printf("(%d, %c)\n",element_count(stack),peek(stack));}
	}
	
    else if(ip[0]=='F'){
      if(is_full(stack))
        printf("TRUE\n");
      else
        printf("FALSE\n");
    }

    else if(ip[0]=='E'){
      if(is_empty(stack))
        printf("TRUE\n");
      else 
        printf("FALSE\n");
    }
    
    else if(ip[0]=='?'){
    	if(is_empty(stack)){
    		printf("STACK IS EMPTY\n");
		}
		else{
			is_member(stack,ip);
		}
	}
	
	else if(ip[0]=='='){
		if(is_empty(stack)){
			printf("STACK IS EMTPY\n");
		}
		else{
			replace(stack,ip);
		}
	}
	
	else if(ip[0]=='C'){
		if(is_empty(stack)){
    		printf("STACK IS EMPTY\n");
		}
		else{
			clear(stack);
		}	
	}
	
	else if(ip[0]=='U'){
		if(is_empty(stack)){
			printf("STACK IS EMPTY");
		}
		else{
		upper(stack);
		print(stack);
		}
	}
	
	else if(ip[0]=='l'){
		if(is_empty(stack)){
			printf("STACK IS EMPTY");
		}
		else{
		lower(stack);
		print(stack);
	}
		}

	
	else if(ip[0]=='Q'){
		break;
	}
	
	else if(ip[0]=='M'){
		menu();
	}
    else{if(ip[1]=='-'){
    	if(is_empty(stack)){
    		printf("STACK IS EMPTY\n");
		}
		else{
			int n,i;
			n=atoi(&ip[0]);
			for(i=0;i<n;i++){
				printf("return %c\n",cntpop(stack));
			}
			if(stack->top==0){
				stack->top==-1;
				printf("STACK IS EMPTY");
			}
			else{
				print(stack);
			}
    	}
    }
	}
  }
}