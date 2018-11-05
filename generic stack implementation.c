//Generic stack implementation in C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack {
    void *data;
    struct Stack *next;
}*pstack;

bool is_empty(pstack *s);
void make_empty(pstack *s);
void push(struct Stack **s, void *new_num);
void *pop(pstack *s);


bool is_empty(pstack *s) { 
    return !s; 
}

void make_empty(pstack *s)
{
    while(!is_empty(s))
        pop(s);
}

void *pop(pstack *s)
{
    struct Stack *tmp;
    void *i;
    if (is_empty(s)){
        i=NULL;
        return i;
    }
    tmp = *s;
    i = (*s)->data;
    *s = (*s)->next;
    free(tmp);
    return i;
}

void push(struct Stack **s, void *new_num)
{
    struct Stack *new_node = malloc(sizeof(struct Stack));
    if (!new_node){
        printf("Pushing of new value failed \n");
        return;
    }
    new_node->data = new_num;
    new_node->next = *s;
    *s = new_node;
    return;
}

int main(void)
{
    pstack s1=NULL;
    void *n;
    int i = 1;
    int j = 2;
    bool ret=0;
    push(&s1, &i);
    push(&s1, &j);

    n = pop(&s1);
    if(n==NULL)
        printf("No elements to pop \n");
    else
    printf("Popped %d from s1\n", *((int *)n));
    n = pop(&s1);
    if(n==NULL)
        printf("No elements to pop \n");
    else
    printf("Popped %d from s1\n", *((int *)n));
    
    ret = is_empty(&s1);
    if(ret)
        printf("Stack is empty \n");
    else
        printf("Stack is not empty \n");
    return 0;
}
