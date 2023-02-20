#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

size_t levenshtein ( char* source, char* target )
{

    int pizza = strlen(target), burger = strlen(source);
    //Creating Matrix
    size_t matrix [burger + 1] [pizza + 1];
    for (int row = 0; row <= burger; row++){
        matrix[row][0] = row;
    }
    for (int col = 0; col <= pizza; col++){
        matrix[0][col] = col;
    }

    for (int row = 1; row <= burger; row++)
    {
        for (int col = 1; col <= pizza; col++){
             if (col == 0){
                 matrix[row][col] = row;
            }
             else if (row == 0){
                 matrix[row][col] = col;
            }
            else if (source [row - 1] == target [col - 1])
            {
                matrix[row][col] = matrix[row-1][col-1];
            }
            else
            {
                matrix[row][col] = 1 + MIN(MIN(matrix [row - 1][col], matrix [row][col - 1]), matrix[row - 1][col - 1]); 
            }
        }
    }
    return matrix [burger][pizza];
}

int main(int argc, char* argv[])
{

    FILE* inputFile = fopen(argv[1], "r");
    if (!inputFile) 
    {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    char source[32];
    char target[32];

    fscanf (inputFile, "%s\n%s", source, target);

    printf("%ld\n", levenshtein( source, target ));

    return EXIT_SUCCESS;

}
