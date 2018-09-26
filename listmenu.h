typedef void (*MenuItemI)(struct List* list);
typedef  struct MenuItem
{
    MenuItemI call;
    char name[25];

} MenuItem;

typedef  struct MenuItems
{
    MenuItem* items;
    int count;

} MenuItems;

void MenuItemGetIndex(struct List* list);
void MenuItemClear(struct List* list);
void MenuItemGet(struct List* list);
void MenuItemCount(struct List* list);
void MenuItemIns(struct List* list);
void MenuItemDel(struct List* list);
void MenuItemRem(struct List* list);
void MenuItemAdd(struct List* list);
void MenuItemAll(struct List* list);
void printMenu(MenuItems *menuitems, struct List* list);