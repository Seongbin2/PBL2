//박성빈
//2020011843

#include <stdio.h>        //헤더파일 선언  
#include <stdlib.h>
#define MAXSIZE 10

typedef struct _Stack {   //struct _Stack 을 Stack으로 사용하기 위해 typedef 선언 
   int top;
   int capacity;
   int array[MAXSIZE];
}Stack;

Stack* CreateStack() {      //typedef를 사용하였으므로, Struct _Stack 대신 Stack 사용 & strcut -> struct 철자 오류 
   Stack* S = (Stack*)malloc(sizeof(Stack));
   S->capacity = MAXSIZE;
   S->top = -1; 
   // 배열이 이미 크기와 함께 선언 되어 있으므로 malloc 삭제  
   return S;             //*S -> S 
}

int isEmptyStack(Stack* S) {

   return(S->top == -1);            //스택의 top 이 -1일경우 반환 : 스택이 비어있는지 검사 
}

int isFullStack(Stack* s) {

   return(s->top == (MAXSIZE - 1));  //스택의 top이 스택 전체 크기 MAXSIZE의 -1 값일 경우 반환 : 스택이 꽉 차 있는 상태인지 검사 
}

void PushStack(Stack* S, int data) {
   if (isFullStack(S)) {
      fprintf(stderr, "스택 포화 에러");   //pushStack함수에서 스택이 꽉 차있는 경우 에러 출력  
      return;
   }
   else
   		S->top++;
        S->array[(S->top)] = data;       //화살표 연산자를 이용해 포인터로 선언된 Stack에 data값을 저장.  증가연산자 ++을 이용해, S->top의 값을 증가 시킨 후 값을 stack에 저장 
}

void PopStack(Stack* S) {
   if (isEmptyStack(S)) {
      fprintf(stderr, "스택 공백 에러");   //popstack함수에서 스택이 비어있을 경우 에러 출력 
      return;
   }
   else {
      printf("스택에 %d 를 제거합니다.\n", Top(S));         
      S->top--;					//Stack에서 pop하였으므로, S->top 의 값을 -1 하는 과정 
   }
   return;               //함수 종료 
}

int Top(Stack* S) {
   return S->array[S->top];        //Top 함수는 stack의 top에 있는 값을 반환해야한다. 
}

void DeleteStack(Stack* S) {
   if (S) {
      free(S);    //위에서 S->array를 동적메모리가 아닌 정적메모리로 이미 선언하였으므로, malloc 삭제하였음. free함수도 삭제. 
   }
}

int main(void) {
   Stack* S = CreateStack();          //CreateStack() 실행시 만들어지는 S를 typedef로 선언한 Stack에 포인터형으로 선언함. 
   int i;
   for (i = 0; i < MAXSIZE; i++) {         // '<=' -> '<' : Stack의 MAXSIZE는 10으로 주어졌으므로 등호를 삭제한다. 
    	PushStack(S, i * 10);
        printf("스택에 %d 를 넣습니다.\n", Top(S));     //반복문을 시행할떄마다 top에 있는 수를 안내문과 함께 출력함. 
	}
   int j;
   for (j = 0; j < MAXSIZE; j++) {
    	PopStack(S);             //그동안 스택에 넣었던 수를 차례대로 popstack을 이용해 출력함. 
   }
   DeleteStack(S);    //스택 사용이 끝나면 S를 지움. 
}
