#include<stdio.h>
#include<stdlib.h>

int main(int argc, char**argv)
{
    int ind;
    
    printf("Printing command-line arguments:\n");
    for (ind = 0; ind < argc; ind++){
        printf("argv[%d] = '%s'\n",ind, argv[ind]);
    }
    printf("Done!\n");
    return EXIT_SUCCESS;
}


