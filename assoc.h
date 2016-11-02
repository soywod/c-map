#ifndef ASSOC_H
#define ASSOC_H

typedef struct Assoc Assoc;
struct AssocItem;

Assoc* assocNew();
void assocAdd(char* key, void* val, Assoc* assoc);
void* assocGet(char* key, Assoc* assoc);
void assocClose(Assoc* assoc);

#endif
