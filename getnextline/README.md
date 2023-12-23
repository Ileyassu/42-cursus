# Get Next Line Project

## Overview
This project, named "Get Next Line," is an implementation of a function that reads a line from a file descriptor. It is designed to provide a seamless way of retrieving and processing lines from various sources, such as files.

## Table of Contents
- [Features](#features)
- [Usage](#usage)
- [Building and Running](#building-and-running)
- [Concepts Learned](#concepts-learned)
- [Contributing](#contributing)
- [License](#license)

## Features
- Reads lines from a given file descriptor.
- Handles dynamic memory allocation to accommodate varying line lengths.
- Utilizes static variables for efficient data persistence between function calls.

## Usage
Provide instructions on how to use your "get next line" function. Include code snippets or examples to demonstrate its usage.

```c
// Example usage code
#include "get_next_line.h"

int main() {
    int file_descriptor = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(file_descriptor)) != NULL) {
        // Process the line as needed
        printf("Line: %s\n", line);
        free(line);
    }

    close(file_descriptor);
    return 0;
}

## Building and Running
 $gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c main.c -o gnl_demo
 $./gnl_demo

##Concepts Learned

-File I/O Operations

File Input/Output (I/O) operations involve reading from and writing to files. In your project, you interacted with the kernel using functions like open and read.
open Function: Used to open a file and obtain a file descriptor. It returns a non-negative integer (file descriptor) on success, which is then used for subsequent I/O operations.
read Function: Reads data from a file descriptor into a buffer. It returns the number of bytes read, allowing you to process the content.
-Memory Management

Dynamic memory allocation is crucial for handling data of varying sizes. In your project, you dynamically allocated memory for lines to ensure flexibility in accommodating different line lengths.
malloc Function: Allocates a specified number of bytes in the heap memory and returns a pointer to the allocated memory block.
free Function: Deallocates the memory previously allocated by malloc, preventing memory leaks.
Static Variables

Static variables maintain their values between function calls, providing a form of persistence. In your project, static variables were likely employed to keep track of the state between successive calls to the "get next line" function.
Data Segment and BSS

Understanding the memory layout of a program is essential. In C, the memory is organized into various segments, including the data segment and BSS.
Data Segment: Contains initialized global and static variables.
BSS (Block Started by Symbol): Contains uninitialized global and static variables that are set to zero by default.
Contributing
If you'd like to contribute to the project, please follow the guidelines in the CONTRIBUTING.md file.
