#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *title;
    char *date;		//four digits as valid
    char *director;
    int id;		//invalid id are ids not exists
    struct node * next;
}node;

typedef struct date_struct{
    int years;
    int month;
    int day;
    int id;
}date_struct;

// global variable
node * head;
node * tail;

// function declaration
void read_database(char * filename);
node * create_node(char * str);
void read_commands(char * filename, char * output_file);
void run_command(char * str, FILE * output_ptr);
void add_node(node * new_node, int id);
void free_node(node * node);
void edit_node(char * feature, char * data, int id);
void remove_node(int id);
void lookup_node(char * feature, char * data, FILE * output_ptr);
int match(char * str, char * data);
void display_node(char * feature, int order, int max, FILE * output_ptr);
int count_link_length();
int date_cmp(void const * date1, void const * date2);
int str_cmp(void const * data1, void const * data2);
void print_to_file(int order, int max, int link_length, node * data, FILE * output_ptr);
void print_date_to_file(int order, int max, int link_length, date_struct * dates, FILE * output_ptr);
void update_database(char * database);
