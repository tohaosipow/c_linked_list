#include <malloc.h>
#include <mem.h>
#include <stdio.h>
#include "list.h"
#include "listmenu.h"

MenuItems* factoryMenuItems(){
    MenuItems* menuItems = malloc(sizeof(menuItems));
    menuItems->items = malloc(sizeof(MenuItem)*9);
    menuItems->count = 9;
    strcpy(menuItems->items[0].name, "Add element");
    menuItems->items[0].call = MenuItemAdd;

    strcpy(menuItems->items[1].name, "Remove element from list");
    menuItems->items[1].call = MenuItemRem;

    strcpy(menuItems->items[2].name, "Insert element in list");
    menuItems->items[2].call = MenuItemIns;

    strcpy(menuItems->items[3].name, "Delete element from list");
    menuItems->items[3].call = MenuItemDel;

    strcpy(menuItems->items[4].name, "Count element in list");
    menuItems->items[4].call = MenuItemCount;

    strcpy(menuItems->items[5].name, "Clear list");
    menuItems->items[5].call = MenuItemClear;

    strcpy(menuItems->items[6].name, "Get index element in list");
    menuItems->items[6].call = MenuItemGetIndex;

    strcpy(menuItems->items[7].name, "Get element by index");
    menuItems->items[7].call = MenuItemGet;

    strcpy(menuItems->items[8].name, "Show all");
    menuItems->items[8].call = MenuItemAll;
    return menuItems;
}

void MenuRun(MenuItems *menuitems, struct List *list){
    int pos = 0;
    while(1) {
        printMenu(menuitems, list);
        scanf("%d", &pos);
        if(pos == -1){
            printf("By!\n");
            break;
        }
        menuitems->items[pos].call(list);
        printf("\n\n\n\n");
    }

}


int main()
{

    struct List* list= factoryList();
    MenuItems* menuitems = factoryMenuItems();
    MenuRun(menuitems, list);
    return 0;
}




