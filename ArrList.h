#ifndef ArrList_h
#define ArrList_h

#include "student.h"

typedef struct{
    STUDENT* data;
    int size;
    int capacity;
}ArrList;

ArrList* new_ArrList(void);
void del_ArrList(ArrList* list);
void ArrList_push_back(ArrList* list, STUDENT elem);
void ArrList_insert(ArrList* list, int index, STUDENT elem);
STUDENT ArrList_get(ArrList* list, int index);
void ArrList_update(ArrList* list,int index, int a);
void ArrList_erase(ArrList* list, int index);
void ArrList_set(ArrList* list, int index, STUDENT elem);
void ArrList_clear(ArrList* list);
void ArrList_shrink_to_fit(ArrList* list);
int ArrList_size(ArrList* list);
int ArrList_capacity(ArrList* list);

#endif