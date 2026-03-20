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

int main() {

    printf("Lo Shu Magic Square\n");

    //temp to test printSquare
    int test[size][size] = {
        {8, 1, 6},
        {3, 5, 7},
        {4, 9, 9}
    };

    printSquare(test);

    //temp to test checkNumbers
    if (checkNumbers(test)) {
        printf("Numbers valid\n");
    }
    else {
        printf("Numbers invlid\n");
    }

    return 0;
    
}
