//박성빈
//2020011843 

#define _CRT_SECURE_NO_WARNINGS   //scanf를 visual studio에서 사용할 수 있도록 전처리한다. 
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
        fprintf(stderr, "스택 포화 에러");
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
        fprintf(stderr, "스택 공백 에러");
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

    Stack* S = CreateStack();            //위의 선언한 스택을 생성하는 함수.  스택을 S라 정의함. 

    printf("Input string to compress: ");
    scanf("%s", line);


    for (int i = 0; line[i]; i++) {

        line[i] = tolower(line[i]);     //line 배열의 내부를 모두 소문자로 변경. 

    }

    PushStack(S, line[0]);             // 아래 반복문에서는 앞의 스택 값과 넣을 스택값을 비교해야 하므로, 먼저 제일 처음 스택 값은 push해준다. 
    top = peek(S);                     // 그 떄의 peek() 을 top에 저장해서 아래 반복문에서 비교한다. 


    for (int j = 1; j < strlen(line); j++) {    //strlen 문자열 길이 함수를 이용해서, 문자열의 길이 - 1 (앞서 line[0]을 대입하였으므로) 만큼 반복해준다. 

        if (line[j] != top) {					//만약 새로 스택에 넣을 예정일 값이 현재 스택의 top에 있는 값과 같다면 아래를 실행한다. 

            for (int k = 0; k < letter_count; k++) { 
                PopStack(S);               //letter_count에서 세어놓았던 값만큼을 pop해주어 그동안 쌓아놓은 같은 문자들을 모두 삭제한다. 
            }
            printf("%d%c", letter_count, top);    //letter_count 의 값 = 같은 문자열이 나온 횟수 , top 의 값 = 그 문자  
            letter_count = 0;                  //출력이 끝나면 다른 문자들을 다시 시행할 수 있도록, letter_count의 값을 0으로 설정해준다 
        }

        PushStack(S, line[j]);                //앞선 조건이 아닐경우는 같은 문자열이 나오는 경우이므로, pushStack을 해주고, letter_count를 하나 증가, top 에 다음값과 비교할 현재의 값을 저장한다. 
        top = peek(S);
        letter_count++;

    }
    printf("%d%c", letter_count, top);       //문자열이 끝날때는 임의로 끝날때까지의 값을 출력해 준다. 

    return 0;
}
