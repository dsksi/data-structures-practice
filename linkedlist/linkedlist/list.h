#ifndef LIST_H
#define LIST_H

#include <stdio.h>

typedef struct _node node;
typedef struct _list list;

//external view of list.c
    list *newlist(void);
    void push(int n, list *l);
    void addValueEnd(int n, list *l);
    int findN(list *l, int n);
    void printList(list *l);
    int pop(list *l);
#endif
