#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
  void *data;
  Node *next;
  Node *prev;
};

struct List {
  Node *head;
  Node *tail;
  Node *current;
};

typedef List List;

Node *createNode(void *data) {
  Node *new = (Node *)malloc(sizeof(Node));
  assert(new != NULL);
  new->data = data;
  new->prev = NULL;
  new->next = NULL;
  return new;
}

List *createList() {
  List *list = malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;
  list->current = NULL;
  return list;
}

void *firstList(List *list) {
  if (list->head == NULL) return NULL;
  list->current = list->head; // actualizo el current
  return list->current->data; // retorno el dato que estaba en head
}

void *nextList(List *list) {
  if (list->current == NULL) return NULL;
  if (list->current->next == NULL) return NULL;// condiciones
  list->current = list->current->next; // ocurre cambio
  return list->current->data;
}

void *lastList(List *list) {
  if (list->tail == NULL) return NULL; // condicion
  list->current = list->tail;
  return list->tail->data;
}

void *prevList(List *list) {
  if (list->current == NULL) return NULL;
  if (list->current->prev == NULL) return NULL;
  list->current = list->current->prev;
  return list->current->data;
}

void pushFront(List *list, void *data) 
{
  Node *nuevo = createNode(data);
  nuevo->next = list->head;
  if(list->head != NULL) // si existe alguno
  {
     list->head->prev = nuevo; 
  }
  if( list->head == NULL) // seria el ultimo termino
  {
    list->tail = nuevo;
  }
  
  list->head = nuevo;
  nuevo->prev = NULL;
}

void pushBack(List *list, void *data) {
  list->current = list->tail;
  pushCurrent(list, data);
}

void pushCurrent(List *list, void *data) 
{
  Node *aux = createNode(data);
  aux->next = list->current->next; 
  aux->prev = list->current;
  
  if (list->current->next == NULL) // por si es el ultimo
  { 
    list->tail = aux;
  }
  list->current->next = aux; // dato en el siguiente de current
}

void *popFront(List *list) {
  list->current = list->head;
  return popCurrent(list);
}

void *popBack(List *list) {
  list->current = list->tail;
  return popCurrent(list);
}

void *popCurrent(List *list) // eliminar nodo de posicion 
{
  if(list->head == NULL) return NULL;
  
  Node *aux = list->current->prev;
  
  aux->next = list->current->next;
  
  void *data = list->current->data;
  list->current = list->head;
  return data; 
  return 0;
}

void cleanList(List *list) {
  while (list->head != NULL) {
    popFront(list);
  }
}