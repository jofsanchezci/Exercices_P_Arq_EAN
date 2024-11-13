
# Project Overview

This repository contains four C programs that demonstrate various aspects of process creation and management in Unix-like systems. Each file serves a specific purpose and illustrates different techniques, such as forking, creating process trees, and using `exec` functions for executing external applications. Below is a description of each program:

### 1. P6.c
- **Description**: This program demonstrates the creation of a process hierarchy through nested loops. Each process prints its current level in the hierarchy, its PID, and values for loop counters `i` and `j`.
- **Key Features**:
  - Uses `fork()` to create new processes.
  - Implements a two-level nested loop, where each level controls process forking based on the loop indices.
  - Helps visualize process creation through printed statements with depth levels.
- **Usage**: Run the program directly in a Unix-like terminal.

### 2. P8_dot.c
- **Description**: This program generates a process tree based on user-defined depth and width, saving the tree structure to a DOT file (`arbol.dot`) for visualization with graph tools like Graphviz.
- **Key Features**:
  - Accepts command-line arguments for specifying the depth and width of the tree.
  - Uses recursive function calls and `fork()` to simulate breadth and depth expansion at different levels.
  - Outputs relationships between processes to a DOT file for graphical representation.
- **Usage**: Compile and run with two arguments for depth and width: `./P8_dot <depth> <width>`

### 3. P8.c
- **Description**: Similar to `P8_dot.c`, this program creates a process tree with specified depth and width but directly prints each process's PID and parent PID information to the console.
- **Key Features**:
  - Command-line arguments specify the tree's depth and width.
  - Displays information about each process directly in the console.
  - Useful for understanding process creation patterns in Unix-like systems without graphical tools.
- **Usage**: Run with arguments for depth and width: `./P8 <depth> <width>`

### 4. P11.c
- **Description**: This program spawns two separate processes to execute external applications (`kcalc` and `xload`), commonly available in Unix-like environments.
- **Key Features**:
  - Uses `fork()` to create child processes and `execvp()` to execute external applications.
  - The parent process waits for both child processes to complete before printing their exit statuses.
  - Demonstrates process control and external application execution.
- **Usage**: Run directly in the terminal. Ensure `kcalc` and `xload` are installed on your system.
