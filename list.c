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
  Nodo nuevo = createNode(data);
  list->tail->next = nuevo;
  list->head->prev = nuevo;
}

void pushBack(List *list, void *data) {
  list->current = list->tail;
  pushCurrent(list, data);
}

void pushCurrent(List *list, void *data) {}

void *popFront(List *list) {
  list->current = list->head;
  return popCurrent(list);
}

void *popBack(List *list) {
  list->current = list->tail;
  return popCurrent(list);
}

void *popCurrent(List *list) { return NULL; }

void cleanList(List *list) {
  while (list->head != NULL) {
    popFront(list);
  }
}