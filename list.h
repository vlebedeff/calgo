#ifndef _LIST_H
#define _LIST_H

typedef struct ListItem {
    char *data;
    struct ListItem *next;
} ListItem;

typedef struct {
    ListItem *head;
    ListItem *tail;
    unsigned count;
} List;

List * List_init();

ListItem * List_unshift(List *, char);

ListItem * List_push(List *, char);

#endif
