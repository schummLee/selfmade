#include <stdio.h> // WE will be using printf | fprintf
#include <stdlib.h> // WE will be using malloc | realloc | free

/* Arrays in C */
/* What is ArrayList and what can i do about it */
//c++ vector Java ArrayList<>
/* The runtime complexity of an ArrayList */
//append O(1) insert mid first O(n) length - positon to end
/* How does ArrayList work in CPU and Memory */
//atomic thread 1 2 3 4  [1,2,3,4,5,6] single thread 3 :
// code -------------------------------------------------------
typedef struct { 
  int* array; 
  size_t size; 
  size_t capacity; 
} ArrayList;
// Initialize an empty ArrayList 
void initialize(ArrayList* list ,size_t initial_capacity) {
  list->array = (int*)malloc(initial_capacity * sizeof(int));
  if (list->array == NULL){
    fprintf(stderr, "ops out of mem");
    exit(1);
  }
  list->size = 0;
  list->capacity = 0;
}
// Append an element to the end of the ArrayList
void append(ArrayList* list, int value){
  if(list->size >= list->capacity){
    list->capacity *= 2;
    list->array = (int*)realloc(list->array, list->capacity * sizeof(int));
    if(list->array == NULL) {
      fprintf(stderr, "ops out of mem");
      exit(1);
    }
  }
  list->array[list->size++] = value;
}
// Retrieve the value at index in the ArrayList
int get(const ArrayList* list, size_t index){
  if(index<list->size){
    return list->array[index];
  }
  else {
    fprintf(stderr, "ops out of mem");
    exit(1);
  }
}
// Update the value at a specific index in the ArrayList.
void set(ArrayList* list, size_t index, int value){
  if(index<list->size){
    list->array[index] = value;
  }
  else {
    fprintf(stderr, "ops out of mem");
    exit(1);
  }
}
// Get the current number of elements in the ArrayList.
size_t size(const ArrayList* list){
  return list->size;
}
// Get the current capacity of the ArrayList.
size_t capacity(const ArrayList* list){
  return list->capacity;
}
// Insert an element at a specific index.
void insert(ArrayList* list,size_t index, int value){
  if(index<=list->size){
    if(list->size >= list->capacity){
      list->capacity *= 2;
      list->array = (int*)realloc(list->array,list->capacity * sizeof(int));
      if(list->array == NULL){
        fprintf(stderr, "ops out of mem");
        exit(1);
      }
    }
    for(size_t i = list->size; i > index; i--){
      list->array[i] = list->array[i - 1];
    }
    list->array[index] = value;
    list->size++;
  }
  else fprintf(stderr, "ops out of mem");
    exit(1);
}
// RemoveAt an element at a specific index.
void removeAt(ArrayList* list ,size_t index){
  if(index<list->size){
    for(size_t i = index; i < list->size - 1; i++) {
      list->array[i] = list->array[i + 1];
      
    }
    list->size--;
  }
  else {
    fprintf(stderr, "ops out of mem");
    exit(1);
  }
}
// Free the memory used by the ArrayList.
void freeArrayList(ArrayList* list){
  free(list->array);
  list->size =0;
  list->capacity=0;
}
// code -------------------------------------------------------

// main (arg,args[])

int main() {
    ArrayList myArrayList;
    initialize(&myArrayList, 10);
    for (int i = 1; i<20 ; i++ ){
      append(&myArrayList,i * 10);
    }
    for ( size_t i =0; i <size(&myArrayList); i++){
      printf("%zu: %d\n", get(&myArrayList,i));
    }
    set(&myArrayList,5 ,999);
    insert(&myArrayList,3 ,777);
    removeAt(&myArrayList,8);
    printf("\n\nupdate\n");
    for(size_t i = 0; i < size(&myArrayList); i++){
      printf("%zu: %d\n", get(&myArrayList,i));
    }
    freeArrayList(&myArrayList);
    return 0;
}











