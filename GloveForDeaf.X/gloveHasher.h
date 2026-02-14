/* 
 * File:   hashmap.h
 * Author: Lenovo
 *
 * Created on December 5, 2025, 7:24 PM
 */

#ifndef HASHMAP_H
#define	HASHMAP_H

typedef char* Key;
typedef uint16_t Value;

typedef struct
{
  Key key;
  Value value;
}Node;

typedef struct
{
  Node* NodeArray;
  int size;
}Hashmap;

#endif	/* HASHMAP_H */

