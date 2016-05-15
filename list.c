#include <stdlib.h>
#include <string.h>

#include "list.h"

static ListItem * ListItem_init(char data) {
    ListItem *item = malloc(sizeof(ListItem));
    item->data = malloc(sizeof(char));

    memcpy(item->data, &data, sizeof(char));

    return item;
}

List * List_init() {
    List *list = malloc(sizeof(List));
    list->head = list->tail = NULL;
    list->count = 0;
    return list;
}

ListItem * List_unshift(List *self, char data) {
    ListItem *item = ListItem_init(data);

    item->next = NULL;

    if (self->count == 0) {
        self->head = self->tail = item;
    } else {
        self->tail->next = item;
        self->tail = item;
    }
    self->count++;
    return item;
}

ListItem * List_push(List *self, char data) {
    ListItem *item = ListItem_init(data);

    if (self->count == 0) {
        self->head = self->tail = item;
    } else {
        item->next = self->head;
        self->head->next = item;
    }
    self->count++;

    return item;
}

