struct Item
{
    struct Item* next;
    struct Item* prev;
    int field;
};

struct List
{
    struct Item *head;
    struct Item *tail;
};

int GetIndex(struct Item *itemM, struct List *list);
int Count(struct List *list);
void Add(struct Item *item, struct List *list);
void Clear(struct List* list);
void PrintItem(struct Item* item, struct List* list);
void PrintList(struct List* list);
struct Item* Get(int pos, struct List *list);
void RemoveItem(int pos, struct List *list);
void DelItem(int pos, struct List *list);
void Insert(int position,  struct Item *item, struct List *list);
struct Item* factoryItem(int field);
struct List* factoryList();