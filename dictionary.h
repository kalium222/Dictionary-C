#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Dictionary {
    struct Node* head;
} Dictionary;

/**
 * @brief search a key in the dictionary.
 * O(log n)
 * @param dict pointer to the dictionary
 * @param key the key to search
 * @return Node* 
 */
Node* search(const Dictionary* dict, const int key);
/**
 * @brief insert a key-value pair into the dictionary.
 * O(n)
 * @param dict pointer to the dictionary
 * @param key
 * @param value 
 */
void insert(Dictionary* dict, const int key, const int value);
/**
 * @brief delete a key-value pair from the dictionary.
 * O(n)
 * @param dict the pointer to the dictionary
 * @param key the key to delete
 */
void delete(Dictionary* dict, const int key);
/**
 * @brief get the predecessor of a key
 * O(1)
 * @param dict the pointer to the dictionary
 * @param key 
 * @return Node* 
 */
Node* predecessor(const Dictionary* dict, const int key);
/**
 * @brief get the successor of a key
 * O(1)
 * @param dict 
 * @param key 
 * @return Node* 
 */
Node* successor(const Dictionary* dict, const int key);
/**
 * @brief get the maximum key in the dictionary
 * O(1)
 * @param dict 
 * @return Node* 
 */
Node* minimum(const Dictionary* dict);
/**
 * @brief get the minimum key in the dictionary
 * O(1)
 * @param dict 
 * @return Node* 
 */
Node* maximum(const Dictionary* dict);

#endif // _DICTIONARY_H_