#include <stdio.h>
#include <stdlib.h>

#define size 3 //defines the 3x3 square

//function prototype
void printSquare(int square[size][size]);

int main() {

    printf("Lo Shu Magic Square\n");

    //temp to test if print function works
    int test[size][size] = {
        {8, 1, 6},
        {3, 5, 7},
        {4, 9, 2}
    };

    printSquare(test);

    return 0;
    
}

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