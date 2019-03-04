//Implement a program to check whether parenthesis are balanced:

//Check if balanced {} [] ()
//Input example: [{({})])]
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    struct _node* next;
} node;
typedef struct _stack {
    struct _node* head;
    int nitems;
} stack;

stack *newStack(void);
int isEmpty(stack *s); 
void freeStack(stack *s);
void push(stack *s);
void pop(stack *s);

int main(int argc, char *argv[]) {
    char *string = malloc(sizeof(char)*250);
    memset(string, 0, 250);
    fgets(string, 250, stdin);
    //scanf("%s", string);
    
    char open1[] = {'(',')'};
    char open2[] = {'{','}'};
    char open3[] = {'[',']'};
    
    //initiate stack
    stack *s1 = newStack();
    stack *s2 = newStack();
    stack *s3 = newStack();

    int i = 0;
    while(string[i] != '\0') {
        if (string[i] == open1[0]) {
            push(s1);
            printf("Push %c\n\n", string[i]);
        } else if (string[i] == open2[0]) {
            push(s2);
            printf("Push %c\n\n", string[i]);
        } else if (string[i] == open3[0]) {
            push(s3);
            printf("Push %c\n\n", string[i]);
        } else if (string[i] == open1[1]) {
            pop(s1);
            printf("Pop %c\n\n", string[i]);
        } else if (string[i] == open2[1]) {
            pop(s2);
            printf("Pop %c\n\n", string[i]);
        } else if (string[i] == open3[1]) {
            pop(s3);
            printf("Pop %c\n\n", string[i]);
        }
        i++;
    }

    if((isEmpty(s1)) && (isEmpty(s2)) && (isEmpty(s3))) {
        printf("Parentheses are balanced! Congrats~ ^ w ^!\n\n");
    } else {
        printf("Parentheses are not balanced! T____T Shorrey\n");
    }
    free(string);
    free(s1);
    free(s2);
    free(s3);
    return 0;
}

// Helper functions

stack *newStack(void) {
    stack *s = malloc(sizeof(stack));
    s->head = NULL;
    s->nitems = 0;
    return s;
}

int isEmpty(stack *s) {
    return (s->nitems == 0);
}

void freeStack(stack *s) {
    if (!s->nitems) {
        free(s);
        return;
    }

    while(s->head != NULL) {
        pop(s);    
    }
}

void push(stack *s) {
    node *new = malloc(sizeof(node));
    if(s->head == NULL) {
        s->head = new;
        new->next = NULL;
        s->nitems++;
        return;
    }
    new->next = s->head;
    s->head = new;
    s->nitems++;
    return;
}
void pop(stack *s) {
    if(s->head == NULL) {
        printf("No corresponding open parenthesis!\n");
        printf("Parentheses are not balanced! T____T Shorrey\n");
        exit(1);
    }
    node *tmp = s->head;
    s->head = s->head->next; 
    s->nitems--;
    free(tmp);
}
