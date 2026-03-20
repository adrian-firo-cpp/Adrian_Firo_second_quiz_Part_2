#include <stdio.h>
#include <stdlib.h>

#define size 3 //defines the 3x3 square

//function prints formatted 3x3 square
void printSquare(int square[size][size]) {

    for (int i = 0; i < size; i++) {

        printf("["); //starts row

        for (int j = 0; j < size; j++) {
            
            printf("%d", square[i][j]); //print numbers

            if (j < size - 1) printf(" "); //add space between numbers except last one of row

        }

        printf("]\n"); //ends row

    }

}

//function to put numbers between 1 and 9 and no number repeats
int checkNumbers(int square[size][size]) {

    int used[10] = {0}; //tracks which numbers have been used

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            int num = square[i][j];

        //check if number is invalid/already used
        if (num < 1 || num > 9 || used[num]) {

            return 0; //option not valid

            }

        used[num] = 1; //mark number as used

        }

    }

    return 1; //marks number as valid and unique

}

//function to check if all rows, columns, and diagonals sum to 15
int checkSums(int square[size][size]) {

    int sum = 15; //constant for 3x3

    //check rows
    for (int i = 0; i < size; i++) {

        int rowSum = 0;

        for (int j = 0; j < size; j++) {

            rowSum += square[i][j];

        }

        if (rowSum != sum) return 0; //invalid row

    }

    //check columns
    for (int j = 0; j < size; j++) {

        int colSum = 0;

        for (int i = 0; i < size; i++) {

            colSum += square[i][j];

        }

        if (colSum != sum) return 0; //invalid column

    }

    //check diags
    int diag1 = square[0][0] + square[1][1] + square[2][2];
    int diag2 = square[0][2] + square[1][1] + square[2][0];

    if (diag1 != sum || diag2 != sum) return 0;

    return 1; //all sums valid

}

//function to combine both checks
int isSquare(int square[size][size]) {

    return checkNumbers(square) && checkSums(square); //so must satisfy number and sum checks

}

int main() {

    printf("Lo Shu Magic Square\n");

    //temp to test printSquare
    int test[size][size] = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 7}
    };

    printSquare(test);

    //temp to test checkNumbers
    if (checkNumbers(test)) {
        printf("Numbers valid\n");
    }
    else {
        printf("Numbers invlid\n");
    }

    //temp to test checkSums

    printf("\nsums test\n\n");

    int valid [size][size] = {
        {8, 1, 6},
        {3, 5, 7},
        {4, 9, 2}
    };

    printf("valid square:\n");
    printSquare(valid);
    printf("%s\n\n", checkSums(valid) ? "Valid sums" : "Invalid sums");


    //invalid row
    int invalidRow[size][size] = {
        {8, 1, 6},
        {3, 5, 7},
        {4, 9, 3} 
    };

    printf("invalid row:\n");
    printSquare(invalidRow);
    printf("%s\n\n", checkSums(invalidRow) ? "Valid sums" : "Invalid sums");


    //invalid column
    int invalidCol[size][size] = {
        {8, 1, 6},
        {3, 5, 7},
        {4, 8, 2}  
    };

    printf("invalid row:\n");
    printSquare(invalidCol);
    printf("%s\n\n", checkSums(invalidCol) ? "Valid sums" : "Invalid sums");


    //invalid diag
    int invalidDiag[size][size] = {
        {8, 1, 6},
        {3, 9, 7}, 
        {4, 9, 2}
    };

    printf("invalid diag:\n");
    printSquare(invalidDiag);
    printf("%s\n\n", checkSums(invalidDiag) ? "Valid sums" : "Invalid sums");

    //temp to test isSquare
    if (isSquare(test)) {
        printf("isSquare valid\n");
    }
    else {
        printf("isSquare invalid");
    }

    return 0;
    
}
