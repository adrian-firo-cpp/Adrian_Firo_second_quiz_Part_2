#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

//function to generate 3x3
void generateSquare(int square[size][size]) {

    int used[10] = {0}; //tracks used numbers

    int count = 0;

    //generate until all 9 positions filled
    while (count < 9) {

        int num = rand() % 9 + 1; //generates rand # from 1-9

        //when # is unused
        if (!used[num]) {

            square [count / 3][count % 3] = num; //fill rows

            used[num] = 1; //mark # as used
            count ++;

        }

    }

}

int main() {

    srand(time(NULL)); //seed RNG

    printf("Lo Shu Magic Square\n");

    int square[size][size];

    //gen square
    generateSquare(square);
    printSquare(square);

    //temp test checkNumbers
    if (checkNumbers(square)) {
        printf("numbers valid\n");
    }
    else {
        printf("numbers invalid\n");
    }

    //temp test checkSums
    if (checkSums(square)) {
        printf("sums valid\n");
    }
    else {
        printf("sums invalid\n");
    }

    //temp test isSquare
    if (isSquare(square)) {
        printf("square valid\n");
    }
    else {
        printf("square invalid\n");
    }

    return 0;
    
}
