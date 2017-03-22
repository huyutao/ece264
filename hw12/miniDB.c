#include "miniDB.h"

int main(int argc, char* argv[]) {
    char *database = argv[1];
	char *commands = argv[2];
	char *output_file = argv[3];
    read_database(database);
    read_commands(commands,output_file);
    update_database(database);
    return 0;
}

void read_database(char * filename){
    FILE* database_file = fopen(filename, "r");
    if(database_file == NULL){
        return;
    }
    while(!feof(database_file)) {
        char str[2000];
        fgets(str, 2000, database_file);
        node* node = create_node(str);
        if (node == NULL){
            return;
        }
        if(tail == NULL) {
            tail = node;
            head = node;
        }else {
            tail->next = node;
            tail = tail->next;
        }
    }
    fclose(database_file);
}

node * create_node(char * str){
    char * title = strtok(str,",");
    char * date = strtok(NULL,",");
    char * director = strtok(NULL,",");
    if(title != NULL && date != NULL && director != NULL){
        node* new_node = malloc(sizeof(node));
        new_node->title = strdup(title);
        new_node->date = strdup(date+1);
        new_node->director = strdup(director+1);
        char * str_id = strtok(NULL,"\n");
        int id = atoi(str_id+1);
        new_node->id = id;
        new_node->next = NULL;
        return new_node;
    }
    else{
        return NULL;
    }
}

void read_commands(char * filename, char * output_file){
    FILE* commands_file = fopen(filename, "r");
    FILE* output_ptr = fopen(output_file, "w");
    if(commands_file == NULL || output_ptr == NULL){
        return;
    }
    while(!feof(commands_file)) {
        char str[2000];
        if(fgets(str, 2000, commands_file) == NULL){
            break;
        }
        run_command(str,output_ptr);
    }
    fclose(commands_file);
}

void run_command(char * str, FILE * output_ptr){
    char * command = strdup(strtok(str,","));
    if(strcmp(command,"ADD") == 0){
        node* new_node = malloc(sizeof(node));
        new_node->title = strdup(strtok(NULL,",")+1);
        new_node->date = strdup(strtok(NULL,",")+1);
        new_node->director = strdup(strtok(NULL,",")+1);
        char * str_id = strtok(NULL,"\n");
        int id = atoi(str_id+1);
        new_node->id = id;
        new_node->next = NULL;
        add_node(new_node, id);
    }else if(strcmp(command,"EDIT") == 0){
        char * str_id = strtok(NULL,",");
        int id = atoi(str_id+1);
        char * feature = strdup(strtok(NULL,",")+1);
        char * data = strdup(strtok(NULL,"\n")+1);
        edit_node(feature,data,id);
    }else if(strcmp(command,"REMOVE") == 0){
        char * str_id = strtok(NULL,"\n");
        int id = atoi(str_id+1);
        remove_node(id);
    }else if(strcmp(command,"LOOKUP") == 0){
        char * feature = strdup(strtok(NULL,",")+1);
        char * data = strdup(strtok(NULL,"\n")+1);
        fprintf(output_ptr,"%s, %s, %s\n","LOOKUP",feature,data);
        lookup_node(feature,data,output_ptr);
        free(feature);
        free(data);
    }else if(strcmp(command,"DISPLAY") == 0){
        char * feature = strdup(strtok(NULL,",")+1);
        char * str_order = strtok(NULL,",");
        int order = atoi(str_order+1);
        char * str_max = strtok(NULL,"\n");
        int max = atoi(str_max+1);
        fprintf(output_ptr,"%s, %s, %s, %s\n","DISPLAY", feature, str_order,str_max);
        display_node(feature,order,max,output_ptr);
    }
}

void add_node(node * new_node, int id){
    node * temp = head;
    int exist = 0;
    while(temp != NULL){    //check if exist
        if(temp->id == id){
            exist = 1;
            break;
        }
        temp = temp->next;
    }
    if(exist == 0){
        if(tail == NULL){
            head = new_node;
            tail = new_node;
        }else{
            tail->next = new_node;
            tail = tail->next;
        }
    }else{
        free_node(new_node);
    }
}

void free_node(node * node){
    free(node -> title);
    free(node -> date);
    free(node -> director);
    free(node);
}

void edit_node(char * feature, char * data, int id){
    node * temp = head;
    while(temp != NULL){
        if(temp->id == id){
            if(strcmp(feature,"TITLE") == 0){
                free(temp->title);
                temp->title = data;
            }else if(strcmp(feature,"DATE") == 0){
                free(temp->date);
                temp->date = data;
            }else if(strcmp(feature,"DIRECTOR") == 0){
                free(temp->director);
                temp->director = data;
            }
            break;
        }
        temp = temp->next;
    }
    free(feature);
}

void remove_node(int id){
    node * temp = head;
    if (temp->id==id){
        head = head->next;
        free_node(temp);
    }else{
        while(temp->next != NULL){    //check if exist
            if(temp->next->id == id){
                node * save_temp = temp->next;
                temp->next = temp->next->next;
                free_node(save_temp);
                break;
            }
            temp = temp->next;
        }
    }
}

void lookup_node(char * feature, char * data, FILE * output_ptr){
    if(strcmp(feature,"TITLE") == 0){
        node * temp = head;
        while(temp != NULL){
            if(match(temp->title,data)==1){
                fprintf(output_ptr,"%s, %s, %s, %d\n",temp->title,temp->date,temp->director,temp->id);
            }
            temp = temp->next;
        }
    }else if(strcmp(feature,"DATE") == 0){
        node * temp = head;
        while(temp != NULL){
            if(match(temp->date,data)==1){
                fprintf(output_ptr,"%s, %s, %s, %d\n",temp->title,temp->date,temp->director,temp->id);
            }
            temp = temp->next;
        }
    }else if(strcmp(feature,"DIRECTOR") == 0){
        node * temp = head;
        while(temp != NULL){
            if(match(temp->director,data)==1){
                fprintf(output_ptr,"%s, %s, %s, %d\n",temp->title,temp->date,temp->director,temp->id);
            }
            temp = temp->next;
        }
    }else if(strcmp(feature,"ID") == 0){
        node * temp = head;
        while(temp != NULL){
            int data_id = atoi(data);
            if(temp->id == data_id){
                fprintf(output_ptr,"%s, %s, %s, %d\n",temp->title,temp->date,temp->director,temp->id);
            }
            temp = temp->next;
        }
    }
}

int match(char * str, char * data){
    if(*str == '\0' && *data == '\0'){
        return 1;
    }
    if(*str == *data){
        return match(str+1,data+1);
    }
    if(*data == '*'){
        return match(str,data+1)||match(str+1,data);
    }
    return 0;
}

void display_node(char * feature, int order, int max, FILE * output_ptr){
    int link_length = count_link_length();
    int i = 0;
    if(strcmp(feature,"TITLE") == 0){
        node * temp = head;
        node titles[link_length];
        while(temp != NULL){
            titles[i].title = temp->title;
            titles[i].id = temp->id;
            i++;
            temp = temp->next;
        }
        qsort(titles, link_length, sizeof(node), str_cmp);
        print_to_file(order, max, link_length, titles, output_ptr);
    }else if(strcmp(feature,"DATE") == 0){
        node * temp = head;
        date_struct dates[link_length];
        while(temp != NULL){
            dates[i].month = atoi(temp->date);
            dates[i].day = atoi(temp->date+3);
            dates[i].years = atoi(temp->date+6);
            dates[i].id = temp->id;
            i++;
            temp = temp->next;
        }
        qsort(dates, link_length, sizeof(date_struct), date_cmp);
        print_date_to_file(order, max, link_length, dates, output_ptr);
    }else if(strcmp(feature,"DIRECTOR") == 0){
        node * temp = head;
        node directors[link_length];
        while(temp != NULL){
            directors[i].title = temp->director;
            directors[i].id = temp->id;
            i++;
            temp = temp->next;
        }
        qsort(directors, link_length, sizeof(struct node), str_cmp);
        print_to_file(order, max, link_length, directors, output_ptr);
    }
    free(feature);
    return;
}

int count_link_length(){
    node * temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

int date_cmp(void const * date1, void const * date2){
    int year1 = ((date_struct * )date1)->years;
    int year2 = ((date_struct * )date2)->years;
    if(year1 != year2){
        return (year1 - year2);
    }else{
        int month1 = ((date_struct * )date1)->month;
        int month2 = ((date_struct * )date2)->month;
        if(month1 != month2){
            return (month1-month2);
        }else{
            int day1 = ((date_struct * )date1)->day;
            int day2 = ((date_struct * )date2)->day;
            return (day1 - day2);
        }
    }
}

int str_cmp(void const * data1, void const * data2){
    char * director11 = ((node *) data1)->title;
    char * director22 = ((node *) data2)->title;
    int result = 0;
    if((result = strcmp(director11,director22)) == 0){
        int id1 = ((node *) data1)->id;
        int id2 = ((node *) data2)->id;
        return (id1-id2);
    }
    else{
        return result;
    }
}

void print_to_file(int order, int max, int link_length, node * data, FILE * output_ptr){
    int i = 0;
    if(order == 1){     //first to last
        if(max > link_length ){
            max = link_length;
        }
        max = link_length - max;
        for(i = link_length - 1; i >= max; i--){
            char str_id [10];
            sprintf(str_id, "%d", ((data[i]).id));
            lookup_node("ID",str_id,output_ptr);
        }
    }else{
        if(max > link_length ){
            max = link_length;
        }
        for(i = 0; i < max; i++){
            char str_id [10];
            sprintf(str_id, "%d", ((data[i]).id));
            lookup_node("ID",str_id,output_ptr);
        }
    }
}

void print_date_to_file(int order, int max, int link_length, date_struct * dates, FILE * output_ptr){
    int i = 0;
    if(max > link_length ){
        max = link_length;
    }
    if(order == 1){     //first to last
        max = link_length - max;
        for(i = link_length - 1; i >= max; i--){
            char str_id [10];
            sprintf(str_id, "%d", ((dates[i]).id));
            lookup_node("ID",str_id,output_ptr);
        }
    }else{
        for(i = 0; i < max; i++){
            char str_id [10];
            sprintf(str_id, "%d", ((dates[i]).id));
            lookup_node("ID",str_id,output_ptr);
        }
    }
}

void update_database(char * database){
    FILE* database_file = fopen(database, "w");
    if(database_file == NULL){
        return;
    }
    node * link = head;
    while(link != NULL){
        fprintf(database_file,"%s, %s, %s, %d\n",link->title,link->date,link->director,link->id);
        link = link->next;
    }
}
