#include "linkedList.h"
#include "listUtils.h"


LinkedList * linkedList()
{
    LinkedList * newList = (LinkedList*)calloc(1, sizeof(LinkedList));
    newList->head =(Node*)calloc(1,sizeof(Node));
    newList->size = 0;
    return newList;
}// end linkedList


void clearList(LinkedList * theList, void (*removeData)(void *))
{
	Node *cur = theList->head->next;
	Node *temp = NULL;
	
	while(cur != NULL) {
		temp = cur;
		cur = cur->next;
		
		removeData(temp->data);
		free(temp);
		temp = NULL;
	}
	
	free(theList->head);
	free(cur);
	theList->head = NULL;
    
}// end clearList

void printList(const LinkedList * theList, void (*convertData)(void *))
{
    if(theList->size == 0)
    {
        printf("empty list");
    }
    Node * curr = theList->head->next;
    int x = 0;
    while(x < theList->size)
    {
        convertData(curr->data);
        curr = curr->next;
        x++;
    }

}// end printList

void addLast(LinkedList * theList, Node * nn)
{
    if (theList->size > 0) {
        Node *curr = theList->head;
        int x = 0;
        while (x < theList->size) {
            curr = curr->next;
            x++;
        }
        curr->next = nn;
        nn->prev = curr;
        theList->size++;
    } else {
        theList->head->next = nn;
        nn->prev = theList->head;
        theList->size++;
    }
}// end addLast

void addFirst(LinkedList * theList, Node * nn)
{
    if(theList->size == 0)
    {
        theList->head->next = nn;
        nn->prev = theList->head;
    }
    else {
        Node* oldNode = theList->head->next;
        oldNode->prev = nn;
        nn->next = oldNode;
        nn->prev = theList->head;
        theList->head->next = nn;
    }
    theList->size++;

}// end addFirst

void removeFirst(LinkedList * theList, void (*removeData)(void *))
{
    Node* nodeToRemove = theList->head->next;
    Node * first = nodeToRemove->next;
    theList->head->next = first;
    first->prev = theList->head;
    removeData(nodeToRemove->data);
    free(nodeToRemove);
    theList->size--;



}// end removeFirst

void removeLast(LinkedList * theList, void (*removeData)(void *))
{
    if(theList->size == 0) {
        removeFirst(theList,removeData);
    }
    Node* curr = theList->head->next;
    Node* prev = theList->head;
    while(curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;

    }
    prev->next = curr->next;
    removeData(curr->data);
    free(curr);
    theList->size--;
}// end removeLast


void removeItem(LinkedList * theList, void * (*buildType)(FILE * stream), void (*removeData)(void *), int (*compare)(const void *, const void *))
{
    void * data = buildType(stdin);
    Node * curr = theList->head->next;
    Node * prev = theList->head;

    while(compare(curr->data,data) != 0)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    prev->next->prev = prev;
    curr->next = NULL;
    free(curr);
    curr = NULL;
    removeData(data);
    free(data);
    data = NULL;
    theList->size--;


}// end removeItem

