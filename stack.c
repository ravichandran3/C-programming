#include<stdio.h>
#include<stdlib.h>

typedef struct node * Node;
typedef struct stack * Stack;
struct node {

    int data;
    Node  nextNode;

};

struct stack{


    int maxSize;//adding size
    int count; //finding How many elements in stack
    Node topNode;

};



Node createNode(int input)
{
    Node newNode=(Node)malloc(sizeof(Node));
    newNode->data=input;
    newNode->nextNode=NULL;
    return newNode;
}


Stack createStack(int size)
{
    Stack newStack=(Stack)malloc(sizeof(Stack));
    newStack->maxSize=size; //assigning the size to stack
    newStack->count=0;
    newStack->topNode=NULL;
    return newStack;
}


void push(Stack stack,int input)
{
    if(stack->count==stack->maxSize)
    {

        printf("stack overflow :)!!! stack is full\n");
    }

    else
    {

        Node newNode=createNode(input);
        newNode->nextNode=stack->topNode;
        stack->topNode=newNode;
        stack->count++;

        /*Node newNode=createNode(input);
        newNode->nextNode=stack->topNode;
        stack->topNode=newNode;*/

    }
}

void pop(Stack stack)
{
    if(stack->topNode==NULL)
    {
        printf("The stack does not have any data :) stack underflow");
    }
    else
    {

        Node topNode=stack->topNode;
        stack->topNode=topNode->nextNode;
        stack->count--;
        free(topNode);

        /*Node topNode=stack->topNode;
        stack->topNode=topNode->nextNode;
        free(topNode);*/
    }
}

int main()
{
    Stack stack=createStack(5);

    push(stack,10);
    printf("Top value:%d\n",stack->topNode->data);
    push(stack,20);
    push(stack,30);
    pop(stack);



    printf("Top value:%d ",stack->topNode->data);
    return EXIT_SUCCESS;
}
