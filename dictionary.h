#ifndef DICTIONARY_DICTIONARY_H
#define DICTIONARY_DICTIONARY_H

struct node {
    int key;
    int value;
    struct node *pred;
    struct node *succ;
};

struct dictionary {
    struct node *head;
    struct node *tail;
};

struct dictionary *initializer();
// EFFECT: Initialize an empty dictionary

struct node *search(struct dictionary *dict, int key);
// EFFECT: Given a dictionary, return the pointer to the element(key-value pair) specified by the key, return NULL if not found.

void insert(struct dictionary *dict, int key, int value);
// EFFECT: If the key does not exist, insert an element(a key-value pair) to this dictionary. If key already exists, update the value.

void delete(struct dictionary *dict,int key);
// EFFECT: Delete an element(key-value pair) specified by the key. If it does not exist, do nothing

struct node *minimum(struct dictionary* dict);
// EFFECT: return the element(key-value pair) with the smallest key

struct node *maximum(struct dictionary* dict);
// EFFECT: return the element(key-value pair) with the largest key

struct node *predecessor(struct dictionary* dict, int key);
// EFFECT: retrieve the pointer to the element(key-value pair) just before a given key

struct node *successor(struct dictionary* dict, int key);
// EFFECT: retrieve the pointer to the element(key-value pair) just after a given key

void free_dict(struct dictionary* dict);
// EFFECT: free the memory allocated for this dictionary

int getkey(struct node* element);
// EFFECT: Given a pointer to the element, return the key

int getvalue(struct node* element);
// EFFECT: Given a pointer to the element, return the value

#endif //DICTIONARY_DICTIONARY_H
