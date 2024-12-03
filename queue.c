#include<stdio.h>
#include<stdlib.h>
typedef struct node * Node;
typedef struct queue * Queue;
struct node {
    int data;
    Node prevNode;
    Node nextNode;
};


struct queue{
    Node frontNode;
    Node rearNode;
};


Node createNode(int input)
{
    Node newNode=(Node)malloc(sizeof(Node));
    newNode->data=input;

    newNode->prevNode=NULL;
    newNode->nextNode=NULL;
    return newNode;
}


Queue createQueue()
{
    Queue newQueue=(Queue)malloc(sizeof(Queue));
    newQueue->frontNode=NULL;
    newQueue->rearNode=NULL;
    return newQueue;
}

void enQueue(Queue queue,int input)
{
    Node newNode=createNode(input);
    if(queue->rearNode==NULL){
        queue->frontNode=newNode;
        queue->rearNode=newNode;

    }
    else
    {
        newNode->prevNode=queue->rearNode;
        queue->rearNode->nextNode=newNode;
        queue->rearNode=newNode;
    }

}
void dequeue(Queue queue)
{
    if(queue->frontNode!=NULL)
    {
        Node firstQueue=queue->frontNode;
        queue->frontNode=firstQueue->nextNode;
        queue->frontNode->prevNode=NULL;
        free(firstQueue);
    }
}


int main()
{
    Queue queue=createQueue();
    enQueue(queue,1);
    enQueue(queue,2);
    enQueue(queue,3);
    enQueue(queue,4);
    printf("front of queue:%d\n",queue->frontNode->data);
    printf("rear of queue:%d\n",queue->rearNode->data);
    printf("\n");

    dequeue(queue);
    printf("after dequeue \n");
    printf("front of queue:%d\n",queue->frontNode->data);
    printf("rear of queue:%d\n",queue->rearNode->data);
    printf("\n");

    dequeue(queue);
    printf("after dequeue \n");
    printf("front of queue:%d\n",queue->frontNode->data);
    printf("rear of queue:%d\n",queue->rearNode->data);
    printf("\n");

    dequeue(queue);
    printf("after dequeue \n");
    printf("front of queue:%d\n",queue->frontNode->data);
    printf("rear of queue:%d\n",queue->rearNode->data);
    return EXIT_SUCCESS;
}
