#include <stdio.h>
#include "list.h"
#include "listmenu.h"



void printMenu(MenuItems *menuitems, struct List* list){
    printf("MAIN MENU\tC:%d\tH:%p\tT:%p\n", Count(list), list->head, list->tail);
    int i = 0;
    for(i; i < menuitems->count; i++){
        printf("[%d]\t%s\n", i, menuitems->items[i].name);
    }
    printf("\n\nEnter number of menu list and press ENTER, ENTER -1 for escape\n");
}

void MenuItemAll(struct List* list){
    PrintList(list);
}

void MenuItemAdd(struct List* list){
    int value = 0;
    printf("Enter value to add in list\n");
    scanf("%d", &value);
    Add(factoryItem(value), list);
}

void MenuItemRem(struct List* list){
    int pos = 0;
    printf("Enter pos which you want remove\n");
    scanf("%d", &pos);
    RemoveItem(pos, list);
}

void MenuItemDel(struct List* list){
    int pos = 0;
    printf("Enter pos which you want delete\n");
    scanf("%d", &pos);
    DelItem(pos, list);
}

void MenuItemIns(struct List* list){
    int pos, value;
    printf("Enter pos and value which you want insert to list\n");
    scanf("%d %d", &pos, &value);
    Insert(pos, factoryItem(value), list);
}

void MenuItemCount(struct List* list){
    printf("COUNT: %d\n", Count(list));
}


void MenuItemGet(struct List* list){
    int pos = 0;
    printf("Enter pos which you want get\n");
    scanf("%d", &pos);
    PrintItem(Get(pos, list), list);
}


void MenuItemClear(struct List* list){
    Clear(list);
    printf("List cleared!\n");
}

void MenuItemGetIndex(struct List* list){
    struct Item* item;
    printf("Enter address item\n");
    scanf("%p", &item);
    printf("INDEX OF %p : %d", item, GetIndex(item, list));
}
