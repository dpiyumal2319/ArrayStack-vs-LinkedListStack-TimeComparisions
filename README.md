Stack Performance Comparison
This program compares the performance of two stack implementations, ArrayStack and LinkedListStack, by measuring the time taken for various operations such as push, pop, and display.

Prerequisites
C++ compiler
GNU Make (optional)
Compilation
Compile the program using the provided Makefile:

bash
Copy code
make
Alternatively, you can compile manually using a C++ compiler:

bash
Copy code
g++ -o stack_performance stack_performance.cpp
Running the Program
Run the compiled executable:

bash
Copy code
./stack_performance
This will generate an output.txt file containing the performance metrics for the stack operations.

Stack Implementations
ArrayStack
Uses a fixed-size array to store elements.
Supports operations like push, pop, stackTop, isEmpty, and isFull.
May encounter stack overflow if the array size is exceeded.
LinkedListStack
Uses a linked list to store elements.
Supports operations like push, pop, stackTop, and isEmpty.
Dynamically allocates memory for each element, avoiding stack overflow issues.
Performance Metrics
The program measures the time taken for the following operations:

Pushing elements into both stacks.
Popping elements from both stacks.
Displaying the contents of both stacks.
The time is measured using the chrono library in C++.