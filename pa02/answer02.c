#include "answer02.h"

size_t my_strlen(const char * str)
{
   int n = 0;
   while (*str != '\0')
   {
        str++;
	n++;
   }
    return n;
}

int my_countchar(const char * str, char ch)
{
   int strlen;
   int i;
   int count = 0;
   strlen = my_strlen(str);
   for (i = 0; i < strlen; i++)
   {
      if (str[i] == ch)
      {
         count++;
      }
   }
   return count;
}

char * my_strchr(const char * str, int ch)
{
   int strlen;
   int i;
   strlen = my_strlen(str);
   if (ch == '\0')
      return strlen + (char*)str;
   for (i = 0; i < strlen; i++)
   {
      if (str[i] == ch)
      {
         return i + (char*)str;
      }
   }
   return NULL;
}

char * my_strrchr(const char * str, int ch)
{
   int strlen;
   int i;
   strlen = my_strlen(str);
   if (ch == '\0')
      return strlen + (char*)str;
   for (i = strlen; i >= 0; i--)
   {
      if (str[i] == ch)
      {
         return i + (char*)str;
      }
   }
   return NULL;
}


char * my_strstr(const char * haystack, const char * needle)
{
   int strlen;
   int i;
   char* addr;
   if (*needle == '\0')
      return (char*)haystack;
   strlen = my_strlen(needle);
   while (*haystack != '\0')
   {
      i = 0;
      addr = (char*)haystack;
      while ((i < strlen) && (needle[i] == *haystack))
      {
         haystack++;
         i++;
      }
      if (i == strlen)
      return addr;
      haystack = addr + 1;
   }
   return NULL;

}


char * my_strcpy(char * dest, const char * src)
{
   int strlen;
   int i;
   strlen = my_strlen(src);
   for (i = 0; i <= strlen; i++)
   dest[i] = src[i];
   return dest;
}


char * my_strcat(char * dest, const char * src)
{
   int strlen1;
   int strlen2;
   int i;
   strlen1 = my_strlen(dest);
   strlen2 = my_strlen(src) + 1;
   for (i = 0; i <= strlen2; i++)
   {
      dest[strlen1 + i] = src[i];
   }
   return dest;
}


int my_isspace(int ch)
{
   if ((int)ch == 9||(int)ch == 10||(int)ch == 11||(int)ch == 12||(int)ch == 13||(int)ch == 32)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}


int my_atoi(const char * str)
{
   int num = 0;
   int neg = 1;
   while (my_isspace((char)str[0]))
   str++;
   if ((char)str[0] == 45)
   {
      neg = -1;
      str++;
   }
   else if ((char)str[0] == 43)
   {
      str++;
   }
   while((int)str[0] > 48 && (int)str[0] < 57  && (char)str[0]!='\0')
   {
      num = num*10 + ((int)str[0] - 48);
      str++;
   }
   num = num * neg;
   return num;
}


