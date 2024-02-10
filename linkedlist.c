#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"

list_t *create_list ()
{
    list_t *list = malloc (sizeof(list_t)); 

    list->first = NULL; //this is head?
    list->last = NULL; //this is tail?
    list->size = 0;

    return list;
}


void free_list (list_t *list)
{
	free (list);
}

int list_size (list_t *list)
{
	
	return list->size;
}

void list_append (list_t *list, int item)
{
	node_t *newNode = malloc (sizeof(node_t));
	newNode->data = item;
	newNode->next = NULL;

	if (list->last == NULL) {
		list->first = newNode;
		list->last = newNode;
	}
	else
	{
		list->last->next = newNode;
		list->last = newNode;
	}
	list->size++;

}

bool list_insert (list_t *list, int item, int index)
{
    	if (index < 0 || index > list->size) 
	{
		return false;
	}
	
	node_t *newNode = malloc(sizeof(node_t));

	newNode->data = item;

	if (index == 0) 
	{
		newNode->next = list->first;
		list->first = newNode;
		if (list->last = NULL)
		{
			list->last = newNode;
		}
	}
	else
	{
		node_t *current = list->first;
		for (int i = 0; i < index - 1; i++)
		{
			current = current->next;
		}

		newNode->next = current->next;
		current->next = newNode;
	}
	list->size++;
	return true;
}

bool list_remove (list_t *list, int index)
{
	if (index < 0 || index >= list->size)
	{
		return false;
	}

	node_t *current = list->first;
	node_t *previous = NULL;

	for (int i = 0; i < index; i++)
	{
		previous = current;
		current = current->next;
	}
	if (previous == NULL)
	{
		list->first = current->next;
		if (list->first == NULL)
		{
			list->last = NULL;
		}
	}
	else
	{
		previous->next = current->next;
		if (previous->next == NULL)
		{
			list->last = previous;
		}
	}
	free(current);
	list->size--;
	return true;

}

int list_find (list_t *list, int item)
{
    int index = 0;
    node_t *current = list->first;

    while (current != NULL)
    {
	    if (current->data == item)
	    {
		    return index;
	    }
	    current = current->next;
	    index++;
    }
    return -1;
}

int list_get (list_t *list, int index)
{
    if (index < 0 || index >= list->size)
    {
	    return -1;
    }
    node_t *current = list->first;
    for (int i = 0; i < index; i++) 
    {
	    current = current->next;
    }
    return current->data;
}

