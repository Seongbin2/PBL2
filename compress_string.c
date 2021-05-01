//�ڼ���
//2020011843 

#define _CRT_SECURE_NO_WARNINGS   //scanf�� visual studio���� ����� �� �ֵ��� ��ó���Ѵ�. 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXSIZE 100


typedef struct _Stack {
    int top;
    int capacity;
    char array[MAXSIZE];
}Stack;

Stack* CreateStack() {
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->capacity = MAXSIZE;
    S->top = -1;

    return S;
}

int isEmptyStack(Stack* S) {

    return(S->top == -1);
}

int isFullStack(Stack* s) {

    return(s->top == (MAXSIZE - 1));
}

void PushStack(Stack* S, char data) {
    if (isFullStack(S)) {
        fprintf(stderr, "���� ��ȭ ����");
        return;
    }
    else
        S->array[++(S->top)] = data;
}

char peek(Stack* S) {
    return S->array[S->top];
}

void PopStack(Stack* S) {
    if (isEmptyStack(S)) {
        fprintf(stderr, "���� ���� ����");
        return;
    }
    else {
        S->top--;
    }
    return;
}

void DeleteStack(Stack* S) {
    if (S) {
        free(S);
    }
}

int main()
{
    int letter_count =1 ;          //
    char top;
    char line[100];

    Stack* S = CreateStack();            //���� ������ ������ �����ϴ� �Լ�.  ������ S�� ������. 

    printf("Input string to compress: ");
    scanf("%s", line);


    for (int i = 0; line[i]; i++) {

        line[i] = tolower(line[i]);     //line �迭�� ���θ� ��� �ҹ��ڷ� ����. 

    }

    PushStack(S, line[0]);             // �Ʒ� �ݺ��������� ���� ���� ���� ���� ���ð��� ���ؾ� �ϹǷ�, ���� ���� ó�� ���� ���� push���ش�. 
    top = peek(S);                     // �� ���� peek() �� top�� �����ؼ� �Ʒ� �ݺ������� ���Ѵ�. 


    for (int j = 1; j < strlen(line); j++) {    //strlen ���ڿ� ���� �Լ��� �̿��ؼ�, ���ڿ��� ���� - 1 (�ռ� line[0]�� �����Ͽ����Ƿ�) ��ŭ �ݺ����ش�. 

        if (line[j] != top) {					//���� ���� ���ÿ� ���� ������ ���� ���� ������ top�� �ִ� ���� ���ٸ� �Ʒ��� �����Ѵ�. 

            for (int k = 0; k < letter_count; k++) { 
                PopStack(S);               //letter_count���� ������Ҵ� ����ŭ�� pop���־� �׵��� �׾Ƴ��� ���� ���ڵ��� ��� �����Ѵ�. 
            }
            printf("%d%c", letter_count, top);    //letter_count �� �� = ���� ���ڿ��� ���� Ƚ�� , top �� �� = �� ����  
            letter_count = 0;                  //����� ������ �ٸ� ���ڵ��� �ٽ� ������ �� �ֵ���, letter_count�� ���� 0���� �������ش� 
        }

        PushStack(S, line[j]);                //�ռ� ������ �ƴҰ��� ���� ���ڿ��� ������ ����̹Ƿ�, pushStack�� ���ְ�, letter_count�� �ϳ� ����, top �� �������� ���� ������ ���� �����Ѵ�. 
        top = peek(S);
        letter_count++;

    }
    printf("%d%c", letter_count, top);       //���ڿ��� �������� ���Ƿ� ������������ ���� ����� �ش�. 

    return 0;
}
