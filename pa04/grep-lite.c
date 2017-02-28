#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char** argv){
	int ind = 1;
	while(ind<argc){ 	// this while loop test if there is a --help
		if(strcmp(argv[ind],"--help") == 0){
			printf("Usage: grep-lite [OPTION]... PATTERN \nSearch for PATTERN in standard input. PATTERN is a string. grep-lite will search standard input line by line, and (by default) print out those lines which contain pattern as a substring.\n\n  -v, --invert-match     print non-matching lines\n  -n, --line-number      print line numbers with output\n  -q, --quiet            suppress all output\n\nExit status is 0 if any line is selected, 1 otherwise;\nif any error occurs, then the exit status is 2.\n");
			return EXIT_SUCCESS;
		}
		ind++;
	}
	
	// following deal option.
	int v = 0;     //invert match
	int n = 0;     //line number
	int q = 0;    //quite
	for(ind = 1; ind < argc - 1;ind++)
    {
        if(strcmp(argv[ind],"--invert-match") == 0 || strcmp(argv[ind],"-v") == 0)
        {
            v = 1;
        }
        else if(strcmp(argv[ind],"--line-number") == 0 ||strcmp(argv[ind],"-n") == 0)
        {
            n = 1;
        }
        else if(strcmp(argv[ind],"--quiet") == 0 ||strcmp(argv[ind],"-q") == 0)
        {
            q = 1;
        }
        else{
            fprintf(stderr,"Bogus option %s are passed, program is aborted",argv[ind]);
            return 2;
        }
	}
	if(argv[argc-1][0] =='-'){
	    fprintf(stderr,"Pattern is wrong, pattern cannot start with '-'. program is aborted");
        return 2;
	}
	char* pattern = argv[argc-1];
	
    //following read the stdin
	char *str = malloc(sizeof(char) * 2000);
	int lineNumber = 1;
	int match = 1;    //no match set 1 
	while(!feof(stdin)){     // while(fgets(str,2000,stdin) != NULL)
	    fgets(str,2000,stdin);
	    if(feof(stdin)){
	        break;
	    }
	    if(strstr(str,pattern) != NULL){
	        match = 0;      //match set 0
	    }
	    if(q){
	        free(str);
	        return 0;
	    }
	    else{
	        if(!v && strstr(str,pattern) != NULL){
	                if(n){
	                    fprintf(stdout,"%d:%s",lineNumber,str); 
	                }
	                else{
	                    fprintf(stdout,"%s",str);
	                }
            }
            else if(v && strstr(str,pattern) == NULL){
	                if(n){
	                    fprintf(stdout,"%d:%s",lineNumber,str); 
	                }
	                else{
	                    fprintf(stdout,"%s",str);
	                }
	            }
	    }
	    lineNumber++;
	}
	free(str);
	return match;
}
