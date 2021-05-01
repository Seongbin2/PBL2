// 박성빈 
// 2020011843

#include <stdio.h>        //헤더파일 선언  
#include <stdlib.h>
#define MAXSIZE 64

typedef struct _Stack {   
   int top;
   int capacity;
   int *array;     //int 형 배열을 포인트형으로 선언함. (동적메모리 사용을 위해)    * 2-(1) 조건 
}Stack;

Stack* CreateStack() {       
   Stack* S = (Stack*)malloc(sizeof(Stack));
   S->capacity = MAXSIZE;
   S->top = -1; 
   S->array = (int*)malloc(sizeof(int) * S->capacity);   //S->array에 int형 배열을 동적메모리로 선언 
   return S;             
}

int isEmptyStack(Stack* S) {

   return(S->top == -1);            
}

int isFullStack(Stack* S) {            // 2-(3) 조건  
	
	if(S->top == MAXSIZE-1){               // 만약 Stack이 포화상태이면 아래의 코드 작동 
		S->capacity = S->capacity * 2;                                       //MAXSIZE였던 S->capacity를 2배로 만듦.    
		S->array = (int *)realloc(S->array, S->capacity * sizeof(int));    //S->array를 동적메모리를 재지정하는 realloc함수를 이용해서, 크기는 S->capacity가 int형 메모리 만큼 들어갈 수 있도록 크기를 재 조정함.  * 2-(2) 조건. 
		return ;
	}
}

void PushStack(Stack* S, int data) {

	isFullStack(S);        //isFullStack 함수를 실행해서, 크기를 조정할 수 있도록함. 
	S->top++;
    S->array[(S->top)] = data;       
}

void PopStack(Stack* S) {                     // 2-(4)조건  
	
   if (isEmptyStack(S)) {
      fprintf(stderr, "스택 공백 에러");
      return;
   }
   
   else if(S->capacity * (0.5) >= S->top){        							//S->capacity의 1/2 값이 S->top이 가리키는 값과 같거나 크면 아래의 코드 실행. (문제에서 'POP 동작에서 공간 사용률이 반 이하로 줄어들면 ' 라고 언급하였음) 
		S->capacity = S->capacity * (0.5);         							//S->capacity를 절반으로 감소 시킴. 
		S->array = (int*)realloc(S->array, sizeof (int) * S->capacity);     //절반으로 감소시킨 값을 realloc함수를 이용해 S->array에 새로 동적배열함. 
   }
   
    printf("스택에 %d 를 뺴냅니다 \n", Top(S));
    S->top--;
   
   return;
}

int Top(Stack* S) {
   return S->array[S->top];        
}

void DeleteStack(Stack* S) {
    if (S) {
		if (S->array)
        	free(S->array);          //새로운 S->array를 동적메모리 할당하였으므로 free함수도 재정의해줌. 
    free(S);    
   }
}

int main(void) {
   Stack* S = CreateStack();          
   int i;
   for (i = 0; i < MAXSIZE; i++) {         
    	PushStack(S, i * 10);
        printf("스택에 %d 를 넣습니다.\n", Top(S));     //반복문을 시행할떄마다 top에 있는 수를 안내문과 함께 출력함. 
            	printf("size of Stack: %d\n", S->capacity);  
	}
   int j;
   for (j = 0; j < MAXSIZE; j++) {
    	PopStack(S);            
    	printf("size of Stack: %d\n", S->capacity);   //S->capacity를 이용해서 스택의 현재 메모리 크기를 알 수 있음. 
   }
   DeleteStack(S);    
}


