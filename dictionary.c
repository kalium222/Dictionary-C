#include "dictionary.h"
#include <stdlib.h>

struct dictionary *initializer()
{
    struct dictionary *dict = malloc(sizeof(struct dictionary));
    dict->head = NULL;
    dict->tail = NULL;
    return dict;
}

struct node *search(struct dictionary * dict, int key)
{
    struct node *curr = dict->head;
    while (curr != NULL)
    {
        if (curr->key<key) {
            curr = curr->succ;
        } else if (curr->key==key) {
            return curr;
        } else {
            break;
        }
    }
    return NULL;
}

void insert(struct dictionary *dict, int key, int value)
{
    struct node *curr = dict->head;
    while (curr != NULL) {
        if (curr->key<key) {
            curr = curr->succ;
        } else if (curr->key==key) {
            curr->value = value;
            return;
        } else {
            break;
        }
    }
    struct node *new = malloc(sizeof(struct node));
    new->key = key;
    new->value = value;
    new->succ = curr;
    if (curr != NULL) {
        new->pred = curr->pred;
        curr->pred = new;
    } else {
        new->pred = dict->tail;
        dict->tail = new;
    }
    if (new->pred != NULL) new->pred->succ = new;
    else dict->head = new;
}

void delete(struct dictionary *dict, int key)
{
    struct node *target = search(dict, key);
    if (target == NULL) return;
    if (target->pred != NULL) {
        target->pred->succ = target->succ;
    } else {
        dict->head = target->succ;
    }
    if (target->succ != NULL) {
        target->succ->pred = target->pred;
    } else {
        dict->tail = target->pred;
    }
    free(target);
}

struct node *minimum(struct dictionary *dict)
{
    return dict->head;
}

struct node *maximum(struct dictionary *dict)
{
    return dict->tail;
}

struct node *predecessor(struct dictionary *dict, int key)
{
    struct node *target = search(dict, key);
    if (target == NULL) return NULL;
    return target->pred;
}

struct node *successor(struct dictionary *dict, int key)
{
    struct node *target = search(dict, key);
    if (target == NULL) return NULL;
    return target->succ;
}


int getkey(struct node *element)
{
    return element->key;
}

int getvalue(struct node *element)
{
    return element->value;
}

void free_dict(struct dictionary *dict)
{
    struct node *curr = dict->head;
    while (curr != NULL) {
        struct node *next = curr->succ;
        free(curr);
        curr = next;
    }
    free(dict);
}

