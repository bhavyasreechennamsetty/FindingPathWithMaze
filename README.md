# FindingPathWithMaze
# Maze Solver in C

This project implements a maze-solving algorithm in C using Depth-First Search (DFS). The program takes a dynamically sized maze as input and finds a path from the top-left corner to the bottom-right corner if one exists.

## Features

- Handles dynamic input for maze size and values.
- Uses DFS to find a path through the maze.
- Prints the solution path if it exists.
- Handles memory allocation and deallocation to prevent memory leaks.

## Getting Started

### Prerequisites

- GCC compiler

### Compilation

To compile the program, use the following command:

```sh
gcc maze_solver.c -o maze_solver



EXAMPLE :-
INPUT:
Enter the size of the maze (n x n): 4
Enter the maze (1 for path, 0 for wall):
1 0 0 0
1 1 0 1
0 1 0 0
1 1 1 1

OUTPUT:-
1 0 0 0
1 1 0 0
0 1 0 0
0 1 1 1

Explanation
1 represents a path.
0 represents a wall.
The program finds a path from the top-left corner (0,0) to the bottom-right corner (n-1,n-1) if it exists, and prints the solution matrix.
Code Structure
main(): Handles input and initiates the maze-solving process.
solveMaze(): Prepares the solution matrix and calls the utility function.
solveMazeUtil(): Recursive function implementing DFS to find the path.
isSafe(): Checks if a given cell is a valid move.
printSolution(): Prints the solution matrix.
License
This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgments
Inspired by common maze-solving algorithms and educational materials on Depth-First Search.

### Additional Notes

- Ensure your project directory contains the `LICENSE` file if you mention it in the README.
- Adjust the compilation and usage instructions based on your specific setup and environment.
