#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {

  // Open the filename given as the first command line argument for reading
  FILE* fp = fopen(argv[1], "r");
  if (!fp) {
    perror("fopen failed");
    return EXIT_FAILURE;
  }

  char buf[256];

  char* stringx = fgets(buf, 256, fp);
    int x = atoi(stringx);
  char* stringy = fgets(buf, 256, fp);
    int i = atoi(stringy);

  int pythagorean1 = pow(x, 2) + pow(i, 2);
  int pythagorean2 = abs (pow(x, 2) - pow(i, 2));

  double root1 = sqrt( pythagorean1 );
  double root2 = sqrt( pythagorean2 );
  int error = -1;
  int rootx = (int) root1;
  int rooty = (int) root2;
    
    if ( root1 == rootx)
    {    
      printf( "%d\n" , rootx);
    }
    else if ( root2 == rooty)
    {    
      printf( "%d\n" , rooty);
    }
    else 
    {
      printf("%d\n" , error);
    }

  // Printing in C.
  // %d is the format specifier for integer numbers.
  // \n is the newline character
  return EXIT_SUCCESS;

}
