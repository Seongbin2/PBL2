//�ڼ���
//2020011843

#include <stdio.h>        //������� ����  
#include <stdlib.h>
#define MAXSIZE 10

typedef struct _Stack {   //struct _Stack �� Stack���� ����ϱ� ���� typedef ���� 
   int top;
   int capacity;
   int array[MAXSIZE];
}Stack;

Stack* CreateStack() {      //typedef�� ����Ͽ����Ƿ�, Struct _Stack ��� Stack ��� & strcut -> struct ö�� ���� 
   Stack* S = (Stack*)malloc(sizeof(Stack));
   S->capacity = MAXSIZE;
   S->top = -1; 
   // �迭�� �̹� ũ��� �Բ� ���� �Ǿ� �����Ƿ� malloc ����  
   return S;             //*S -> S 
}

int isEmptyStack(Stack* S) {

   return(S->top == -1);            //������ top �� -1�ϰ�� ��ȯ : ������ ����ִ��� �˻� 
}

int isFullStack(Stack* s) {

   return(s->top == (MAXSIZE - 1));  //������ top�� ���� ��ü ũ�� MAXSIZE�� -1 ���� ��� ��ȯ : ������ �� �� �ִ� �������� �˻� 
}

void PushStack(Stack* S, int data) {
   if (isFullStack(S)) {
      fprintf(stderr, "���� ��ȭ ����");   //pushStack�Լ����� ������ �� ���ִ� ��� ���� ���  
      return;
   }
   else
   		S->top++;
        S->array[(S->top)] = data;       //ȭ��ǥ �����ڸ� �̿��� �����ͷ� ����� Stack�� data���� ����.  ���������� ++�� �̿���, S->top�� ���� ���� ��Ų �� ���� stack�� ���� 
}

void PopStack(Stack* S) {
   if (isEmptyStack(S)) {
      fprintf(stderr, "���� ���� ����");   //popstack�Լ����� ������ ������� ��� ���� ��� 
      return;
   }
   else {
      printf("���ÿ� %d �� �����մϴ�.\n", Top(S));         
      S->top--;					//Stack���� pop�Ͽ����Ƿ�, S->top �� ���� -1 �ϴ� ���� 
   }
   return;               //�Լ� ���� 
}

int Top(Stack* S) {
   return S->array[S->top];        //Top �Լ��� stack�� top�� �ִ� ���� ��ȯ�ؾ��Ѵ�. 
}

void DeleteStack(Stack* S) {
   if (S) {
      free(S);    //������ S->array�� �����޸𸮰� �ƴ� �����޸𸮷� �̹� �����Ͽ����Ƿ�, malloc �����Ͽ���. free�Լ��� ����. 
   }
}

int main(void) {
   Stack* S = CreateStack();          //CreateStack() ����� ��������� S�� typedef�� ������ Stack�� ������������ ������. 
   int i;
   for (i = 0; i < MAXSIZE; i++) {         // '<=' -> '<' : Stack�� MAXSIZE�� 10���� �־������Ƿ� ��ȣ�� �����Ѵ�. 
    	PushStack(S, i * 10);
        printf("���ÿ� %d �� �ֽ��ϴ�.\n", Top(S));     //�ݺ����� �����ҋ����� top�� �ִ� ���� �ȳ����� �Բ� �����. 
	}
   int j;
   for (j = 0; j < MAXSIZE; j++) {
    	PopStack(S);             //�׵��� ���ÿ� �־��� ���� ���ʴ�� popstack�� �̿��� �����. 
   }
   DeleteStack(S);    //���� ����� ������ S�� ����. 
}
