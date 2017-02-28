#include <stdlib.h>
#include <string.h>
#include "answer03.h"

char * strcat_ex(char * * dest, int * n, const char * src)
{
    char *buffer;
    if (*dest == NULL)
    {
        *dest = malloc(1 + 2*strlen(src));
        *n = 1 + 2 * strlen(src);
        strcpy(*dest,src);
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
    int result_len = 0;

    char *result = NULL;

    
    for (i=0; i<len-1; i++)
    {   
        result_len = 0;
        result = strcat_ex(&result, &result_len, strArr[i]);
        result_len = 0;
        result = strcat_ex(&result, &result_len, glue);
    }
    result = strcat_ex(&result, &result_len, strArr[i]);
    return result;
}

int compareStrings(const void * a, const void * b){
    return strcmp( * (char * const *) a, * (char * const *) b);
}

int compareChars(const void * a, const void* b){
	return (*(char*)a - *(char*)b);
}

void sortStringArray(char * * arrString, int len)
{
    qsort(arrString, len, sizeof(char *), compareStrings);
}

void sortStringCharacters(char * str)
{
    int len = strlen(str);
    qsort(str, len, sizeof(char), compareChars);
}

void destroyStringArray(char * * strArr, int len)
{
    if (len != 0)
    {
        int i;
        for (i=0; i<len; i++)
        {
            free(strArr[i]);
        }
        free(strArr);
    }
}








