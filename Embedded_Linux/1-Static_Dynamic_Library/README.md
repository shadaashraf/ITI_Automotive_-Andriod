# Dynamic & Static Library

This project demonstrates how to compile and use a simple C library for addition, both as a static and a dynamic library.

## Files

- `calculate.h`: Header file containing the function declaration.
- `calculate.c`: Source file containing the function definition.
- `main.c`: Main program to test the library.

## Function

**Calcualate.c**
`
int add(int x, int y);`

Adds two integers and returns the result.

## Compiling and Running

### Using a Static Library

1.  **Compile `calculate.c` into an object file:**
    

    
    `gcc -c calculate.c -o calculate.o` 
    
2.  **Create a static library (`libcalculate.a`):**
    
    `ar rcs libcalculate.a calculate.o` 
    
3.  **Compile `main.c` and link it with the static library:**
    
    `gcc main.c -L. -lcalculate -o main_static` 
    
4.  **Run the executable:**
    
    `./main_static` 
 5.  **Output:**   

### Using a Dynamic Library

1.  **Compile `calculate.c` into a position-independent object file:**
    
    `gcc -fPIC -c calculate.c -o calculate.o` 
    
2.  **Create a dynamic library (`libcalculate.so`):**
    
    `gcc -shared -o libcalculate.so calculate.o` 
    
3.  **Compile `main.c` and link it with the dynamic library:**
    
    `gcc -o dynamic_program main.c -L. calculate -Wl,-rpath=~/study 
` 
   
    
4.  **Run the executable:**
   
    `./main_dynamic`

    
4.  **Output:**
   
