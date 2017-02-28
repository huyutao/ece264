#include <stdio.h>
#include <string.h>

#include "answer02.h"

#define BUFFER_LEN 1024

int main(int argc, char * * argv)
{
    printf("Welcome to PA02.\n"
	   "\n"
	   "You are encouraged to edit this file in order to test\n"
	   "the behavior of the functions you write in answer02.c\n"
	   "\n"
	   "This file will not be marked, and should not be\n"
	   "submitted.\n"
	   "\n"
	   "Don't forget to post questions on Blackboard, and ask\n"
	   "the TAs and your classmates for help.\n"
	   "\n");
	   
    const char * s1 = "Hello World!";
    const char * s2 = "";
    const char * s3 = "foo";
    const char * ss1 = "0";
    const char * ss2 = "-12";
    const char * ss3 = "15th of March would be the ides.";

	
	// -- my_strlen, should be: 12, 0, and 3
    printf("my_strlen(\"%s\") = %d\n", s1, (int) my_strlen(s1));
    printf("my_strlen(\"%s\") = %d\n", s2, (int) my_strlen(s2));
    printf("my_strlen(\"%s\") = %d\n", s3, (int) my_strlen(s3));
    printf("my_strlen(\"%s\") = %d\n", ss1, (int) my_strlen(ss1));
    printf("my_strlen(\"%s\") = %d\n", ss2, (int) my_strlen(ss2));
    printf("my_strlen(\"%s\") = %d\n", ss3, (int) my_strlen(ss3));

	
	// -- my_countchar, should be: 3, 0, and 2
    printf("my_countchar(\"%s\", 'l') = %d\n", s1, (int) my_countchar(s1, 'l'));
    printf("my_countchar(\"%s\", 'o') = %d\n", s2, (int) my_countchar(s2, 'o'));
    printf("my_countchar(\"%s\", 'o') = %d\n", s3, (int) my_countchar(s3, 'o'));
    printf("my_countchar(\"%s\", '0') = %d\n", ss1, (int) my_countchar(ss1, '0'));
    printf("my_countchar(\"%s\", '0') = %d\n", ss2, (int) my_countchar(ss2, '0'));
    printf("my_countchar(\"%s\", '0') = %d\n", ss3, (int) my_countchar(ss3, '0'));

	
	// -- my_strchr, should be: "llo World!", "(null)", and ""
    printf("my_strchr(\"%s\", 'l') = %s\n", s1, my_strchr(s1, 'l'));
    printf("my_strchr(\"%s\", 'o') = %s\n", s2, my_strchr(s2, 'o'));
    printf("my_strchr(\"%s\", '\\0') = %s\n", s3, my_strchr(s3, '\0'));

	// -- my_strrchr, should be: "orld!", "(null)", and ""
    printf("my_strrchr(\"%s\", 'o') = %s\n", s1, my_strrchr(s1, 'o'));
    printf("my_strrchr(\"%s\", 'z') = %s\n", s2, my_strrchr(s2, 'z'));
    printf("my_strrchr(\"%s\", '\\0') = %s\n", s3, my_strrchr(s3, '\0'));

	
	// -- my_strstr, should be: "World!", "Hello World!", "(null)"
    printf("my_strstr(\"%s\", \"World\") = %s\n", s1, my_strstr(s1, "World"));
    printf("my_strstr(\"%s\", \"\") = %s\n", s1, my_strstr(s1, ""));
    printf("my_strstr(\"%s\", \"hello\") = %s\n", s1, my_strstr(s1, "hello"));
	
	// -- my_strcpy. For this function you need a buffer where you
    // copy the string to. 
    char buffer[BUFFER_LEN];
    my_strcpy(buffer, s1);
    printf("my_strcpy(buffer, \"%s\"), buffer = \"%s\"\n", s1, buffer);
    my_strcpy(buffer, s2);
    printf("my_strcpy(buffer, \"%s\"), buffer = \"%s\"\n", s2, buffer);
    my_strcpy(buffer, s3);
    printf("my_strcpy(buffer, \"%s\"), buffer = \"%s\"\n", s3, buffer);
	
	// -- my_strcat. You will have to do this yourself.
    // Look at my_strcpy for an example, and go from there.
    my_strcpy(buffer, s1);
    printf("%s\n", my_strcat(buffer, "Zippy!"));
    my_strcpy(buffer, s2);
    printf("%s\n", my_strcat(buffer, "Zippy!"));
    my_strcpy(buffer, s3);
    printf("%s\n", my_strcat(buffer, "Zippy!"));


    // -- my_isspace. You will have to do this for yourself.
    printf("my_isspace,%d\n", my_isspace(' '));
    printf("my_isspace,%d\n", my_isspace('\f'));
    printf("my_isspace,%d\n", my_isspace('\n'));
    printf("my_isspace,%d\n", my_isspace('\r'));
    printf("my_isspace,%d\n", my_isspace('\t'));
    printf("my_isspace,%d\n",  my_isspace('\v'));
    char ch;
    for(ch = 'A'; ch <= 'Z'; ++ch)
       printf("my_isspace,%c, is %d\n", ch, my_isspace(ch)); // always 0

    // -- my_atoi. You will have to do this for yourself..
    printf("my_atoi,%d\n", my_atoi(ss1)); // 0
    printf("my_atoi,%d\n", my_atoi(ss2)); // -12
    printf("my_atoi,%d\n", my_atoi(ss3)); // 15
    printf("my_atoi,%d\n", my_atoi("4 months to Summer.")); // 4
    printf("my_atoi,%d\n", my_atoi("\n\f\t\v\r 6 white space characters handled correctly.")); // 6
    printf("my_atoi,%d\n", my_atoi("garbage, instead of a number like 73 for example, should yield a zero")); // 0
	return EXIT_SUCCESS;
}
