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
## Checking for memory leaks
You can use valgrind, but if you have EZHEAP_DBG defined, you can use the ```ezheap_dbg_info()``` macro after ```ezheap_destruct()```, this will print all ```malloc()``` and ```free()``` usages
## Why
- Just because
- ... because I can
