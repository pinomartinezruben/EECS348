/*
Name: Ruben Pino-Martinez
Lab 5: IDE, compiled programs (C programming with arrays), Git
Date: 10/13/24
Objective: In the program, we'll define two 5x5 matrices, add and multiply them, and then find their transposes
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
// C requires that function prototypes are top of the file for compiler
void sum_matrix(int first_matrix[SIZE][SIZE], int second_matrix[SIZE][SIZE], int final_matrix[SIZE][SIZE]);
void multiply_matrix(int first_matrix[SIZE][SIZE], int second_matrix[SIZE][SIZE], int final_matrix[SIZE][SIZE]);
void trans_matrix(int matrix[SIZE][SIZE], int final_matrix[SIZE][SIZE]);
void print_matrix(int matrix[SIZE][SIZE]);
int main() {
    int first_matrix[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int second_matrix[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    printf("First Matrix:\n");
    print_matrix(first_matrix);
    printf("Second Matrix:\n");
    print_matrix(second_matrix);
    
    // adding the matricies
    int final_matrix[SIZE][SIZE];
    sum_matrix(first_matrix, second_matrix, final_matrix);
    printf("Addition of both Matrices:\n");
    print_matrix(final_matrix);

    // multipling the matrices
    multiply_matrix(first_matrix, second_matrix, final_matrix);
    printf("Multiplication of both Matrices:\n");
    print_matrix(final_matrix);

    // transposing first matrix
    trans_matrix(first_matrix, final_matrix);
    printf("Transpose of the first matrix:\n");
    print_matrix(final_matrix);
    
    // transposing second matrix
    trans_matrix(second_matrix, final_matrix);
    printf("Transpose of the second matrix:\n");
    print_matrix(final_matrix);
    return 0;
}


// add both matrices
void sum_matrix(int first_matrix[SIZE][SIZE], int second_matrix[SIZE][SIZE], int final_matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // sum of each element
            final_matrix[i][j] = first_matrix[i][j] + second_matrix[i][j];
        }
    }
}

// multiply both matrices
void multiply_matrix(int first_matrix[SIZE][SIZE], int second_matrix[SIZE][SIZE], int final_matrix[SIZE][SIZE]) {
    // initialize final matrix to zero
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            final_matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                // multiply then add
                final_matrix[i][j] += first_matrix[i][k] * second_matrix[k][j];
            }
        }
    }
}

// transpose either matrix
void trans_matrix(int matrix[SIZE][SIZE], int final_matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // switch row and column indexes
            final_matrix[j][i] = matrix[i][j];
        }
    }
}
// print matrix
void print_matrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        // Print each element
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
