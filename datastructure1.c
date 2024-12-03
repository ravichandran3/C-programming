#include<stdio.h>
#include<stdlib.h>

typedef struct node * Node;
typedef struct LinkedList * LinkedList;
struct node{

    int data;
    Node nextNode;
    Node prevNode;
};
struct LinkedList{

    Node headNode;
    Node tailNode;

};


 Node createnode(int input){

     Node newNode=(Node *)malloc(sizeof(Node*));
     newNode->data=input;
     newNode->prevNode=NULL;
     newNode->nextNode=NULL;
     return newNode;


 }

 LinkedList createLinkedlist()
 {
     LinkedList newList =(LinkedList* )malloc(sizeof(LinkedList *));
     newList->headNode=NULL;
     newList->tailNode=NULL;
     return newList;
 }

 void add_element_at_the_end(LinkedList list,int input)
 {
    Node newNode=createnode(input);
    if(list->headNode==NULL)
    {
        list->headNode=newNode;
        list->tailNode=newNode;
    }
    else
    {
      ////////////////////////////////////////
      ////new step                       /////
        newNode->prevNode=list->tailNode;/////
      ////end of new step                /////
      ////////////////////////////////////////

        list->tailNode->nextNode=newNode;
        list->tailNode=newNode;
    }

}

void add_element_at_the_start(LinkedList list,int input)
{
    Node newNode=createnode(input);
    if(list->headNode==NULL)
    {
        list->headNode=newNode;
        list->tailNode=newNode;
    }
    else
    {
      ///////////////////////////////////////
      //new step                    ////////
        list->headNode->prevNode=newNode;//
       //new step end               //////
      ///////////////////////////////////
        newNode->nextNode=list->headNode;
        list->headNode=newNode;

    }
}



void remove_element_at_the_first(LinkedList list)
{
    if(list->headNode!=NULL)
    {
        Node firstNode=list->headNode;
        if(firstNode->nextNode==NULL)
        {

            list->headNode=NULL;
            list->tailNode=NULL;
        }
        else
        {

            list->headNode=firstNode->nextNode;

            ////////////////////////////////////
            //new step                /////////
                                      ////////
            list->headNode->prevNode=NULL;////
                                      //////
            //new step end         ////////
           ///////////////////////////////
        }
        free(firstNode);
    }
}

void remove_element_at_the_end(LinkedList list)
{
    if(list->tailNode!=NULL)
    {
            Node lastNode=list->tailNode;
            if(lastNode->prevNode==NULL)
            {
               list->headNode=NULL;

               list->tailNode=NULL;
            }
            else
            {
                list->tailNode=lastNode->prevNode;
                list->tailNode->nextNode=NULL;

            }
            free(lastNode);

    }

}





int main()
{
    LinkedList list=createLinkedlist();

    add_element_at_the_end(list,10);
    add_element_at_the_end(list,20);
    add_element_at_the_start(list,9);
    add_element_at_the_start(list,8);
    remove_element_at_the_first(list);
    remove_element_at_the_end(list);
    printf("%d",list->headNode->data);
    printf("%d",list->headNode->prevNode);

    printf("%d",list->tailNode->data);
    printf("%d",list->tailNode->prevNode->data);
    printf("%d",list->tailNode->nextNode);


return EXIT_SUCCESS;
}
