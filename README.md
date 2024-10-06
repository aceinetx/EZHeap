# EZHeap
Easy heap with no need to free, eliminating all memory leaks
## This is not a heap implementation
This acts like a provider to ```malloc()```/```free()```
## Example
```c
#include <ezheap.h>
#include <stdio.h>

void func()
{
  // as ezheap is initalized, you can use it anywhere
  int *y = new (int);
  *y = 69;
  printf("%d\n", *y);
}

void hello_world()
{
  // you can also allocate strings!
  char *str = new_str("Hello, world!");
  printf("%s\n", str);
}

void alloc_bytes()
{
  // if you really need it, you can allocate raw bytes
  void *bytes = new (char[5]); // acts the same as malloc(5)
}

int main()
{
  ezheap_init();

  int *x = new (int);
  *x = 123;
  printf("%d\n", *x);

  func();
  hello_world();
  alloc_bytes();

  // this free's all allocated variables, so no need to do free()
  ezheap_destruct();
}
```
## Notice
Do not use malloc() if you want to use ezheap, ezheap will not be able to free it
Do not use free() on ezheap allocated variable, this will result in a double free when ezheap_destruct() is called
## Macros
- ```ezheap_init()```: initalizes ezheap
- ```new(x)```: basically ```malloc(N)```, but expands to ```malloc(sizeof(N))```
- ```new_str(x)```: basically ```new```, but copies ```x``` to a newly allocated variable
- ```ezheap_destruct()```: destructs ezheap and free's all heap allocated variables (that are created using ```new``` or ```new_str```)
- ```__ezheap_stdmalloc(x, y)```: basically ```malloc(x)```, but increments ```y->allocs```, needed for debug info
- ```__ezheap_stdfree(x, y)```: basically ```free(x)```, but increments ```y->free```, needed for debug info
- ```ezheap_dbg_info()```: prints debug info (can only be called if EZHEAP_DBG is defined)
## Checking for memory leaks
You can use valgrind, but if you have EZHEAP_DBG defined, you can use the ```ezheap_dbg_info()``` macro after ```ezheap_destruct()```, this will print all ```malloc()``` and ```free()``` usages
## Why
- Just because
- ... because I can
