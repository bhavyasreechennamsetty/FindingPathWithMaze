#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print the solution path
void printSolution(int** sol, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", sol[i][j]);
        }
        printf("\n");
    }
}

// Function to check if x, y is valid index for n*n maze
bool isSafe(int** maze, int x, int y, int n) {
    // If x, y is within maze boundaries and maze[x][y] is 1, then it is a valid move
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1);
}

// Function to solve the maze using DFS
bool solveMazeUtil(int** maze, int x, int y, int** sol, int n) {
    // If x, y is the bottom-right corner, return true
    if (x == n - 1 && y == n - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is a valid move
    if (isSafe(maze, x, y, n)) {
        // Mark x, y as part of the solution path
        sol[x][y] = 1;

        // Move forward in the x direction
        if (solveMazeUtil(maze, x + 1, y, sol, n)) {
            return true;
        }

        // If moving in x direction doesn't give solution, move down in the y direction
        if (solveMazeUtil(maze, x, y + 1, sol, n)) {
            return true;
        }

        // If neither forward nor down works, backtrack: unmark x, y as part of the solution path
        sol[x][y] = 0;
        return false;
    }

    return false;
}

// Function to solve the maze
bool solveMaze(int** maze, int n) {
    // Allocate memory for solution array
    int** sol = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        sol[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            sol[i][j] = 0;
        }
    }

    if (!solveMazeUtil(maze, 0, 0, sol, n)) {
        printf("No solution exists\n");
        // Free allocated memory for solution array
        for (int i = 0; i < n; i++) {
            free(sol[i]);
        }
        free(sol);
        return false;
    }

    printSolution(sol, n);

    // Free allocated memory for solution array
    for (int i = 0; i < n; i++) {
        free(sol[i]);
    }
    free(sol);
    return true;
}

int main() {
    int n;
    printf("Enter the size of the maze (n x n): ");
    scanf("%d", &n);

    // Allocate memory for maze
    int** maze = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        maze[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter the maze (1 for path, 0 for wall):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    solveMaze(maze, n);

    // Free allocated memory for maze
    for (int i = 0; i < n; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}
