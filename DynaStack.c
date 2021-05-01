// �ڼ��� 
// 2020011843

#include <stdio.h>        //������� ����  
#include <stdlib.h>
#define MAXSIZE 64

typedef struct _Stack {   
   int top;
   int capacity;
   int *array;     //int �� �迭�� ����Ʈ������ ������. (�����޸� ����� ����)    * 2-(1) ���� 
}Stack;

Stack* CreateStack() {       
   Stack* S = (Stack*)malloc(sizeof(Stack));
   S->capacity = MAXSIZE;
   S->top = -1; 
   S->array = (int*)malloc(sizeof(int) * S->capacity);   //S->array�� int�� �迭�� �����޸𸮷� ���� 
   return S;             
}

int isEmptyStack(Stack* S) {

   return(S->top == -1);            
}

int isFullStack(Stack* S) {            // 2-(3) ����  
	
	if(S->top == MAXSIZE-1){               // ���� Stack�� ��ȭ�����̸� �Ʒ��� �ڵ� �۵� 
		S->capacity = S->capacity * 2;                                       //MAXSIZE���� S->capacity�� 2��� ����.    
		S->array = (int *)realloc(S->array, S->capacity * sizeof(int));    //S->array�� �����޸𸮸� �������ϴ� realloc�Լ��� �̿��ؼ�, ũ��� S->capacity�� int�� �޸� ��ŭ �� �� �ֵ��� ũ�⸦ �� ������.  * 2-(2) ����. 
		return ;
	}
}

void PushStack(Stack* S, int data) {

	isFullStack(S);        //isFullStack �Լ��� �����ؼ�, ũ�⸦ ������ �� �ֵ�����. 
	S->top++;
    S->array[(S->top)] = data;       
}

void PopStack(Stack* S) {                     // 2-(4)����  
	
   if (isEmptyStack(S)) {
      fprintf(stderr, "���� ���� ����");
      return;
   }
   
   else if(S->capacity * (0.5) >= S->top){        							//S->capacity�� 1/2 ���� S->top�� ����Ű�� ���� ���ų� ũ�� �Ʒ��� �ڵ� ����. (�������� 'POP ���ۿ��� ���� ������ �� ���Ϸ� �پ��� ' ��� ����Ͽ���) 
		S->capacity = S->capacity * (0.5);         							//S->capacity�� �������� ���� ��Ŵ. 
		S->array = (int*)realloc(S->array, sizeof (int) * S->capacity);     //�������� ���ҽ�Ų ���� realloc�Լ��� �̿��� S->array�� ���� �����迭��. 
   }
   
    printf("���ÿ� %d �� �����ϴ� \n", Top(S));
    S->top--;
   
   return;
}

int Top(Stack* S) {
   return S->array[S->top];        
}

void DeleteStack(Stack* S) {
    if (S) {
		if (S->array)
        	free(S->array);          //���ο� S->array�� �����޸� �Ҵ��Ͽ����Ƿ� free�Լ��� ����������. 
    free(S);    
   }
}

int main(void) {
   Stack* S = CreateStack();          
   int i;
   for (i = 0; i < MAXSIZE; i++) {         
    	PushStack(S, i * 10);
        printf("���ÿ� %d �� �ֽ��ϴ�.\n", Top(S));     //�ݺ����� �����ҋ����� top�� �ִ� ���� �ȳ����� �Բ� �����. 
            	printf("size of Stack: %d\n", S->capacity);  
	}
   int j;
   for (j = 0; j < MAXSIZE; j++) {
    	PopStack(S);            
    	printf("size of Stack: %d\n", S->capacity);   //S->capacity�� �̿��ؼ� ������ ���� �޸� ũ�⸦ �� �� ����. 
   }
   DeleteStack(S);    
}


