#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"




genericlistElement* createEl(char* data, size_t size) {
	genericlistElement* e = malloc(sizeof(genericlistElement));
	if (e == NULL) {
		return NULL; //return NULL to indicate an error.
	}
	char* dataPointer = malloc(sizeof(char)*size);
	if (dataPointer == NULL) {
		//malloc has had an error
		free(e); //release the previously allocated memory
		return NULL; //return NULL to indicate an error.
	}
	strcpy(dataPointer, data);
	e->data = dataPointer;
	e->size = size;
	e->next = NULL;
	return e;
}

void printChar(void* data) 
{
	printf("%c\n",*(char*)data);
}


//Prints out each element in the list
void traverse(genericlistElement* start) {
	genericlistElement* current = start;
	while (current != NULL) 
	{
		current-> printChar(current-> data);
	}
}

//Inserts a new element after the given el
//Returns the pointer to the new element
genericlistElement* insertAfter(genericlistElement* el, char* data, size_t size) {
	genericlistElement* newEl = createEl(data, size);
	genericlistElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}


//Delete the element after the given el
void deleteAfter(genericlistElement* after) {
	genericlistElement* delete = after->next;
	genericlistElement* newNext = delete->next;
	after->next = newNext;
	//need to free the memory because we used malloc
	free(delete->data);
	free(delete);
}
int length(genericlistElement* list)
{
	int x = 0;
	genericlistElement* current = list;
	while (current != NULL) {
		x++;
		current = current->next;
	}
	return x;
}

void push(genericlistElement** list, char* data, size_t size)
{
	genericlistElement** *temp = createEl(data, size);
	temp->next = list;
	list = temp;

}
genericlistElement* pop(genericlistElement** list)
{
	genericlistElement** temp = list->next;
	list = temp;

}
void enqueue(genericlistElement** list, char* data, size_t size)
{
	genericlistElement *newE = createEl(data, size);
	newE->next = *list;
	*list = newE;

}
genericlistElement* dequeue(genericlistElement* list)
{
	genericlistElement *temp = list;
	while ((temp->next)->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = NULL;
	return temp;
}