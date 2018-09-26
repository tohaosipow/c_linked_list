#include <stdlib.h>
#include <stdio.h>
#include <mem.h>
#include "list.h"


int Count(struct List *list)
{
    int i = 0;
    struct Item *item;
    for(item=list->head; item != NULL; item = item->next) i++;
    return i;
}

int GetIndex(struct Item *itemM, struct List *list)
{
    struct Item *item;
    int i = 0;
    for(item=list->head; item != NULL; item = item->next, i++)
    {
        if(itemM == item) return i;
    }
    return -1;
}
void Add(struct Item *item, struct List *list)
{
    if(list->tail == NULL)
    {
        list->head = item;
        list->tail = item;
        item->prev = NULL;
        item->next = NULL;
    }
    else
    {
        item->prev = list->tail;
        list->tail->next = item;
        list->tail = item;
        item->next = NULL;
    }
}

void Clear(struct List* list)
{
    struct Item *item;
    for(item=list->head; item != NULL; item = item->next)
    {
        free(item->prev);
    }
    free(list->tail);
    list->head = NULL;
    list->tail = NULL;
}

void PrintItem(struct Item* item, struct List* list) {
    if(item != NULL) printf("%p\t%p\t%p\t%d\t%d\n", item->prev, item, item->next, item->field, GetIndex(item, list));
}

void PrintList(struct List* list){
    struct Item *item;
    printf("HEAD %p\t TAIL %p\n", list->head, list->tail);
    for(item=list->head; item != NULL; item = item->next)
    {
        PrintItem(item, list);
    }
    printf("COUNT: %d\n",Count(list));
}
struct Item* Get(int pos, struct List *list)
{
    int i = 0;
    struct Item *item;
    for(item=list->head; item != NULL; item = item->next)
    {
        if(i == pos) return item;
        i++;
    }
    return NULL;
}

void RemoveItem(int pos, struct List *list){
    struct Item *item;
    item = Get(pos, list);
    if(item == NULL) return;
    if(item == list->head) list->head = item->next;
    if(item == list->tail) list->tail = item->prev;
    if(item->next) item->next->prev = item->prev;
    if(item->prev) item->prev->next = item->next;

}

void DelItem(int pos, struct List *list){
    struct Item *item;
    item = Get(pos, list);
    if(item == NULL) return;
    RemoveItem(pos, list);
    free(item);
}
void Insert(int position,  struct Item *item, struct List *list)
{
    if(position < 0) return;
    else if(position == 0)
    {
        if(list->head == NULL){
            Add(item, list);
            return;
        }
        else{
            list->head->prev = item;
            item->next = list->head;
            item->prev = NULL;
            list->head = item;
        }
    }
    else if(position >= Count(list)){
        Add(item, list);
    }
    else
    {
        struct Item *itemG = Get(position, list);
        itemG->prev->next = item;
        item->next = itemG;
        item->prev = itemG->prev;
        itemG->prev = item;

    }

}


struct Item* factoryItem(int field){
    struct Item *item;
    item = malloc(sizeof(struct Item));
    item->field  = field;
    item->next = NULL;
    item->prev = NULL;
    return item;
}




struct List* factoryList(){
    struct List *list;
    list = malloc(sizeof(struct List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}



