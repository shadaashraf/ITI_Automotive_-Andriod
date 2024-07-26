calculate.h
c
Copy code
int add(int x, int y);
Compiling and Running
Using a Static Library
Compile calculate.c into an object file:

sh
Copy code
gcc -c calculate.c -o calculate.o
Create a static library (libcalculate.a):

sh
Copy code
ar rcs libcalculate.a calculate.o
Compile main.c and link it with the static library:

sh
Copy code
gcc main.c -L. -lcalculate -o main_static
Run the executable:

sh
Copy code
./main_static
Using a Dynamic Library
Compile calculate.c into a position-independent object file:

sh
Copy code
gcc -fPIC -c calculate.c -o calculate.o
Create a dynamic library (libcalculate.so):

sh
Copy code
gcc -shared -o libcalculate.so calculate.o
Compile main.c and link it with the dynamic library:

sh
Copy code
gcc main.c -L. -lcalculate -o main_dynamic
Set the library path environment variable to the current directory:

sh
Copy code
export LD_LIBRARY_PATH=.
Run the executable:

sh
Copy code
./main_dynamic
	
