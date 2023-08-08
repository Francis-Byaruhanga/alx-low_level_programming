# malloc and free

In C programming, `malloc` and `free` are functions used for dynamic memory allocation and deallocation, respectively. They allow you to allocate memory on the heap at runtime and release it when it's no longer needed, providing more flexibility compared to automatic (stack) memory allocation.

Here's how you can use `malloc` and `free` in C:

1. **malloc (Memory Allocation):**
The `malloc` function is used to allocate a block of memory on the heap. It takes the size of the memory block you want to allocate as an argument and returns a pointer to the allocated memory.
    
    ```c
    #include <stdio.h>
    #include <stdlib.h>
    
    int main() {
        int *ptr;
        int num_elements = 5;
    
        // Allocate memory for an array of integers
        ptr = (int *)malloc(num_elements * sizeof(int));
    
        if (ptr == NULL) {
            printf("Memory allocation failed\\n");
            return 1;
        }
    
        // Now 'ptr' points to a block of memory for 5 integers
    
        // Don't forget to free the allocated memory when done
        free(ptr);
    
        return 0;
    }
    
    ```
    
2. **free (Memory Deallocation):**
The `free` function is used to release memory that was previously allocated using `malloc`. This ensures that the memory can be used for other purposes and prevents memory leaks.
    
    ```c
    #include <stdio.h>
    #include <stdlib.h>
    
    int main() {
        int *ptr;
    
        // Allocate memory for an integer
        ptr = (int *)malloc(sizeof(int));
    
        if (ptr == NULL) {
            printf("Memory allocation failed\\n");
            return 1;
        }
    
        // Use the allocated memory
        *ptr = 42;
        printf("Value: %d\\n", *ptr);
    
        // Free the allocated memory when it's no longer needed
        free(ptr);
    
        return 0;
    }
    
    ```
    

It's important to note a few things:

- The `malloc` function returns a pointer to the allocated memory. Make sure to typecast it to the appropriate data type.
- Always check if the memory allocation was successful (i.e., if the returned pointer is not `NULL`) before using the allocated memory.
- After calling `free`, the memory is no longer accessible, and trying to access it can lead to undefined behavior. Therefore, make sure you only access the memory before calling `free`.
- Using `free` on a pointer that has already been freed or on a pointer that was not obtained through dynamic memory allocation can also lead to undefined behavior.

By using `malloc` and `free`, you can dynamically manage memory for your data structures, arrays, and other objects, providing flexibility in your C programs. Just be sure to properly allocate and deallocate memory to avoid memory leaks and undefined behavior.

The syntax for `malloc()` is as follows:

```c
ptr = (cast-type*) malloc(byte-size)
```

For example, if you want to allocate memory for an array of 100 integers, you would use:

```c
ptr = (int*) malloc(100 * sizeof(int));
```

This statement will allocate 400 bytes of memory (assuming the size of int is 4 bytes), and the pointer `ptr` will hold the address of the first byte in the allocated memory [geeksforgeeks.org](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/).

On the other hand, `free()` is a function that is used to dynamically deallocate the memory that was previously allocated by `malloc()`. The syntax for `free()` is:

```c
free(ptr);
```

This function does not change the value of the pointer, meaning it still points to the same memory location. However, the block of memory it points to is freed and can be used for future memory allocation requests [tutorialspoint.com](https://www.tutorialspoint.com/how-do-malloc-and-free-work-in-c-cplusplus).

Here is an example of how to use `malloc()` and `free()`:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5, i, *p, sum = 0;
    p = (int*) malloc(n * sizeof(int));

    if(p == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }

    printf("Enter elements of array: ");
    for(i = 0; i < n; ++i) {
        scanf("%d", p + i);
        sum += *(p + i);
    }

    printf("Sum: %d", sum);
    free(p);

    return 0;
}
```

In this example, memory is dynamically allocated for an array of 5 integers. The user is asked to input the elements of the array, and the sum of the elements is calculated and printed. Finally, the allocated memory is deallocated using `free(p)` [tutorialspoint.com](https://www.tutorialspoint.com/how-do-malloc-and-free-work-in-c-cplusplus).

Remember, it's crucial to deallocate any dynamically allocated memory after its use to prevent memory leaks. If you forget to call `free()`, the memory remains allocated until the program exits, which can lead to significant memory waste when the allocation size is large or when allocation is done inside a loop
