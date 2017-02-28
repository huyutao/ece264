#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * strcat_ex(char * * dest, int * n, const char * src)
{
    char *buffer;
    if (*dest == NULL)
    {
        *dest = malloc(1 + 2*strlen(src));
        *n = 1 + 2 * strlen(src);
        strcat(*dest,src);
    }
    else
    {
        if(strlen(*dest) + strlen(src) + 1 > *n)
        {
            buffer = malloc(1 + 2 * (strlen(*dest) + strlen(src)) * sizeof(char));
            *n = 1 + 2 * (strlen(*dest) + strlen(src));
            strcpy(buffer,*dest);
            free(*dest);
            *dest = buffer;
            strcat(*dest,src);
        }
        else
        {
            strcat(*dest,src);
        }
    }
    
	return *dest;
}


char * * explode(const char * str, const char * delims, int * arrLen)
{
    int len_str = strlen(str);
    int N = 0;
    int i = 0;
    int arrInd = 0;
    int last = 0;
    int ind = 0;
    char * newstr;
    
    for(i=0; i<len_str;i++)
    {
        if(strchr(delims,str[i]) != NULL)
        N++;
    }
    * arrLen = N+1;
    char * * strArr = malloc((N+1) * sizeof(char *));
    for(ind=0; ind < len_str; ind++)
    {
        if(strchr(delims,str[ind]) != NULL)
        {
            newstr = malloc(sizeof(char)*(ind - last + 1));
            memcpy(newstr, str+last, ind-last);
            strArr[arrInd] = newstr;
            last = ind + 1;
            arrInd++;
        }
    }
    newstr = malloc(sizeof(char)*(ind - last + 1));
    memcpy(newstr, str+last, ind-last);
    strArr[arrInd] = newstr;
    return strArr;
}

char * implode(char * * strArr, int len, const char * glue)
{
    int i;
    int n1;
    int n2;
    char *buffer;
    char *newbuffer;
    newbuffer = NULL;

    for (i=0; i<len-1; i++)
    {
        n1 = strlen(strArr[i]);
        buffer = strcat_ex(&strArr[i],&n1,glue);
        n2 = strlen(strArr[i]);
        newbuffer = strcat_ex(&newbuffer,&n2,buffer);
        free(strArr[i]);
    }
    n2 = strlen(strArr[len-1]);
    newbuffer = strcat_ex(&newbuffer,&n2,strArr[len-1]);
    free(strArr[len-1]);
    free(buffer);
    return newbuffer;
}
int main(int argc, char * * argv)
{
    printf("Welcome to PA03.\n");
    int len;
    char * * strArr = explode("The\nTuring test", " \t\v\n\r\f", &len);
    printf("strArr[0] is %s\n",strArr[0]);
    printf("strArr[1] is %s\n",strArr[1]);
    printf("strArr[2] is %s\n",strArr[2]);
    
    //char * * strArr = explode("100 224 147 80", " ", &len);
    //printf("strArr[0] is %s\n",strArr[0]);
    //printf("strArr[1] is %s\n",strArr[1]);
    //printf("strArr[2] is %s\n",strArr[2]);
    char * str = implode(strArr, len, " ");
    printf("(%s)\n", str); // (100, 224, 147, 80)
    return EXIT_SUCCESS;
}
