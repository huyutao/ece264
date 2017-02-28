#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * * argv)
{
    fprintf(stdout,"Printing normal stuff.\n");
    fprintf(stderr,"This is just a DEBUG statement that I want printed to stderr, and not stdout\n");
    return EXIT_SUCCESS;
}

