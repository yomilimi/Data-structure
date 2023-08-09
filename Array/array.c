#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void print(char arr[], int cur){
  int j;
  for (j = 0; j < strlen(arr); j++) {
          if (j == cur) { printf("(%c) ", arr[j]); }
          else { printf("%c ", arr[j]); }
          }
}
int insert(char arr[], char m[], int cur) {
	int i,k;
    for(i=0;i<strlen(m);i++){
            if(m[i]=='+'){
              cur+=1;
              for (k = strlen(arr); k > cur; k--) {
              arr[k] = arr[k - 1];
              }
              arr[cur] = m[i+1];
            }
          }
    return cur;
}

int traverse_front(char arr[], char m[], int cur) {
    cur = 0;
    int nc = 0;
    int i;
    for(i=0;i<strlen(m);i++){
      if(m[i]=='N'){
        nc+=1;}
    }
    cur = cur + nc;
    return cur;
}

int traverse_rear(char arr[], char m[], int cur) {
    cur = strlen(arr) - 1;
    int nc = 0;
    int i;
    for(i=0;i<strlen(m);i++){
      if(m[i]=='P'){
        nc+=1;}
    }
    cur = cur - nc;
    return cur;
}

int deletethelast(char arr[], int cur) {
    int i;
    cur = strlen(arr) - 1;
    for (i = cur; i < strlen(arr); i++) {
        arr[i] = arr[i + 1];
    }
    cur = 0;
    return cur;
}

int Delete(char arr[], int cur) {
    int i;
    for (i = cur; i < strlen(arr); i++) {
        arr[i] = arr[i + 1];
    }
    if (cur == strlen(arr)){
        cur = 0;
    }
    return cur;
}

int get_data(char arr[], int cur) {
    printf("Return %c", arr[cur]);
    return cur;
}

int replace(char arr[], char m[], int cur) {
    arr[cur] = m[1];
    return cur;
}

int empty(char arr[], int cur) {
    memset(arr, 0, strlen(arr));
    printf("empty array");
    cur = -1;
    return cur;
}

int move(char arr[], int new_position, int cur) {
    char carry;
    int i;
    carry = arr[cur];
    if (cur < new_position) {
        for (i = cur + 1; i <= new_position; i++) {
            arr[i - 1] = arr[i];
        }
    }
    if (cur > new_position) {
        for (i = cur - 1; i >= new_position; i--) {
            arr[i + 1] = arr[i];
        }
    }
    cur = new_position;
    arr[cur] = carry;
    return cur;
}

int data_count(char arr[]) {
    int n;
    n = strlen(arr) - 1;
    return n;
}

void view_menu() {
    printf("----------MENU----------\n");
    printf("INSERT               : +(data)\n");
    printf("TRAVERSE_FRONT       : <(N)\n"); 
    printf("TRAVERSE_REAR        : >(P)\n");
    printf("DELETE               : -\n");
    printf("DELETE THE LAST      : > -(띄어쓰세요)\n");
    printf("GET_DATA             : @\n");
    printf("REPLACE              : =(data)(붙여쓰세요)\n");
    printf("EMPTY                : E\n");
    printf("TRAVERSE_FRONT&&MOVE : < M(POSITION)\n");
    printf("<과 M은 띄어쓰고 M과 POSITION은 붙여쓰세요\n");
    printf("MOVE                 : M(POSITION)(붙여쓰세요)\n");
    printf("MOVE END             : Mn(붙여쓰세요)\n");
    printf("MOVE PREV            : Mp(붙여쓰세요)\n");
    printf("MOVE NEXT            : MN(붙여쓰세요)\n");
    printf("PRINT                : L\n");
    printf("VIEW                 : V\n");
    printf("UPPER CASE           : U\n");
    printf("LOWER CASE           : l\n");
    printf("END                  : B\n");
}

void upper(char arr[], int cur) {
    arr[cur] -= 32;
    print(arr,cur);
}

void Lower(char arr[], int cur) {
    arr[cur] += 32;
    print(arr,cur);
}

int main() {
    char arr[30] = {};
    int cur = -1;
    view_menu();

    while (1) {
    	char m[30]={};
        gets(m);
        if (m[0] == '+') {
            cur = insert(arr, m, cur);
            print(arr,cur);
        }
        if (m[0]== '<') {
          
          if(m[2]=='M'){
            int np;
            np = atoi(&m[3]);
            cur = traverse_front(arr, m, cur);
            cur = move(arr, np, cur);
            print(arr,cur);
          }
          else{
            cur = traverse_front(arr, m, cur);
            print(arr,cur);
          }
        }
        if (m[0] == '>') {
          if(m[2]=='-'){cur = deletethelast(arr, cur);}
          else {cur = traverse_rear(arr, m,cur);}
          print(arr,cur);
            }
        if (m[0] == '-') {
            cur = Delete(arr, cur);
            print(arr,cur);
        }
        if (m[0] == '@') {
            cur = get_data(arr, cur);
        }
        if (m[0] == '=') {
            cur = replace(arr, m, cur);
            print(arr,cur);
        }
        if (m[0] == 'E') {
            cur = empty(arr, cur);
        }
        if (m[0] == 'M') {
          int np;
            if (m[1]=='n') {
                np = data_count(arr);
                cur = move(arr, np, cur);
            }
            else if (m[1]=='P') {
                np = cur - 1;
                cur = move(arr, np, cur);
            }
            else if (m[1]=='N') {
                np = cur + 1;
                cur = move(arr, np, cur);
            }
            else {
                np = atoi(&m[2]);
                cur = move(arr, np, cur);
            }
          print(arr,cur);
        }
        if (m[0] == 'L') {
            print(arr, cur);
        }
        if (m[0] == 'V') {
            view_menu();
        }
        if (m[0] == 'U') {
            upper(arr, cur);
        }
        if (m[0] == 'l') {
            Lower(arr, cur);
        }
        if (m[0]=='B'){
        	break;
		}
        }
	}
