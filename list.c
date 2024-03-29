#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List * list = (List *)malloc(sizeof(List));
    list->head = NULL;
    list->current = NULL;
    return list;
}

void * firstList(List * list){
    list->current = list->head;
    if(list->current) 
      return list->current->data;
    else
      return NULL;
}

void * nextList(List * list) {
  if(list->current != NULL)
    list->current = list->current->next;
  if(list->current != NULL)
    return list->current->data;
  else
    return NULL;
}

void * lastList(List * list) 
{
  list->current = list->tail;
  if(list->current)
    return list->current->data;
  else
    return NULL;
}

void * prevList(List * list) {
  if(list->current != NULL)
    list->current = list->current->prev;
  if(list->current != NULL)
    return list->current->data;
  else
    return NULL;
}

void pushFront(List * list, void * data) {
    Node * node = createNode(data);
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    Node * node = createNode(data);
    if (list->current == NULL)
    {
        pushFront(list,data);
    }
    else
    {
        node->next = list->current->prev;
        node->prev = list->current;
        if (list->current->next == NULL)
            list->tail = node;
        else
        {
            list->current->next->prev = node;
            list->current->next = node;
        }
    }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}