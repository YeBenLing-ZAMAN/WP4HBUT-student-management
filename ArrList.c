#include "ArrList.h"
#include <stdlib.h>
#include <stdio.h>

#define INIT_CAPACITY 4

ArrList* new_ArrList(void){
    ArrList* list = (ArrList*)malloc(sizeof(ArrList));
    list->data = (STUDENT*)malloc(sizeof(STUDENT) * INIT_CAPACITY);
    list->size = 0;
    list->capacity = INIT_CAPACITY;
    return list;
}

void del_ArrList(ArrList* list){
    free(list->data);
    free(list);
}

void ArrList_push_back(ArrList* list, STUDENT elem){
    ArrList_insert(list, list->size, elem);
}

void ArrList_insert(ArrList* list, int index, STUDENT elem){
    if(index < 0 || index > list->size){
        printf("Error: Bad index! list->size = %d, index = %d\n", list->size, index);
        exit(1);
    }

    if(list->size == list->capacity){
        list->data = (STUDENT*)realloc(list->data, sizeof(STUDENT) * list->capacity * 2);
        list->capacity *= 2;
    }

    for(int i = list->size; i > index; --i){
        list->data[i] = list->data[i-1];
    }
    list->data[index] = elem;
    list->size++;
}

STUDENT ArrList_get(ArrList* list, int index){
    if(index < 0 || index > list->size - 1){
        printf("Error: Bad index! list->size = %d, index = %d\n", list->size, index);
        exit(1);
    }
    return list->data[index];
}

void ArrList_erase(ArrList* list, int index){
    if(index < 0 || index > list->size - 1){
        printf("Error: Bad index! list->size = %d, index = %d\n", list->size, index);
        exit(1);
    }

    for(int i = index; i < list->size - 1; ++i){
        list->data[i] = list->data[ i + 1 ];
    }
    list->size--;
}

void ArrList_set(ArrList* list, int index, STUDENT elem){
    if(index < 0 || index > list->size - 1){
        printf("Error: Bad index! list->size = %d, index = %d\n", list->size, index);
        exit(1);
    }
    list->data[index] = elem;
}
void ArrList_update(ArrList* list,int index, int a){
      if(index < 0 || index > list->size - 1){
        printf("Error: Bad index! list->size = %d, index = %d\n", list->size, index);
        exit(1);
    }
    list->data[index].book_id = a;
}

void ArrList_clear(ArrList* list){
    list->size = 0;
}

void ArrList_shrink_to_fit(ArrList* list){
    if(list->size > 1){
        list->data = (STUDENT*)realloc(list->data, sizeof(STUDENT) * list->size);
        list->capacity = list->size;
    }else{
        list->data = (STUDENT*)realloc(list->data, sizeof(STUDENT));
        list->capacity = 1;
    }
}

int ArrList_size(ArrList* list){
    return list->size;
}
int ArrList_capacity(ArrList* list){
    return list->capacity;
}