#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void readFile(char * fileName)
{
	int c =1;
	FILE *fptr;
	fptr = fopen(fileName,"r");
	if(fptr == NULL){
		fprintf(stderr,"cat cannot open %s\n",fileName);
	}
	else{
		while((c = fgetc(fptr))!=EOF)
		{
			printf("%c",c);
		}
	fclose(fptr);
	}
}

void readStdin()
{
	char c = 1;
	while ((c = fgetc(stdin))!=EOF)
	{
		printf("%c",c);
	}
}



int main(int argc, char** argv){
	int ind = 1;
	int showhelp = 0;

	// this while loop test if there is a --help
	while(ind<argc){
		if(strcmp(argv[ind],"--help") == 0){
		showhelp = 1;
		}
		ind++;
	}
	if (showhelp){
		printf("Usage: cat-lite [--help] [FILE]\n");
		printf("With no FILE, or when FILE is -, read standard input (can exit with CTRL+D, play around with ""cat"" to get a sense of how this works).");
		return EXIT_SUCCESS;
	}

	// following deal with file.
	if(argc == 1){
		readStdin();
	}
	for(ind=1; ind<argc; ind++){
		if(strcmp(argv[ind],"-") == 0){
			readStdin();
		}
		else{
			readFile(argv[ind]);
		}
	}
	
	return EXIT_SUCCESS;
}
