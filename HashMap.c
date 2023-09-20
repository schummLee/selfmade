#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHMAP_SIZE 100
//-- code ----------------------------------------
struct KeyValuePair{
  char* key;
  int value;
  struct KeyValuePair* next;
};

struct HashMap{
  struct KeyValuePair* buckets[HASHMAP_SIZE];
};

struct HashMap* createHashMap() {
  struct HashMap* hashmap = (struct HashMap*)malloc(sizeof(struct HashMap));
  if(hashmap){
    for( int i =0;i < HASHMAP_SIZE; i++) {
      hashmap->buckets[i] = NULL;
    }
  }
  return hashmap;
}

unsigned int hash(char* key){
  unsigned int hash = 0;
  while(*key){
    hash = (hash * 31) + (*key++);
  }
  return hash % HASHMAP_SIZE;
}
//unsigned short char all mem 
void insert(struct HashMap* hashmap,char* key, int value){
  unsigned int index = hash(key);
  struct KeyValuePair* newPair = (struct KeyValuePair*)malloc(sizeof(struct KeyValuePair));
  if(newPair){
    newPair->key = strdup(key);
    newPair->value = value;
    newPair->next = hashmap->buckets[index];
    hashmap->buckets[index] = newPair;
  }  
}

int get(struct HashMap* hashmap, char* key){
  unsigned int index = hash(key);
  struct KeyValuePair* current = hashmap->buckets[index];
  while(current){
    if(strcmp(current->key, key) == 0) {
      return current->value;
    }
    current = current->next;
  }
  return -1;
}

void freeHashMap(struct HashMap* hashmap){
  for (int i = 0; i< HASHMAP_SIZE; i++ ){
    struct KeyValuePair* current = hashmap->buckets[i];
    while(current){
      struct KeyValuePair* temp = current;
      current = current->next;
      free(temp->key);
      free(temp);
    }
  }
      free(hashmap);
}

//-- code ---------------------------------------

int main() {
  struct HashMap* hashmap = createHashMap();
  insert(hashmap,"www", 1);
  insert(hashmap,"eee", 2);
  insert(hashmap,"ttt", 3);
  printf("1: %d\n", get(hashmap,"www"));
  printf("2: %d\n", get(hashmap,"eee"));
  printf("3: %d\n", get(hashmap,"ttt"));
  freeHashMap(hashmap);
  
}
