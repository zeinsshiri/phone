#ifndef _LIST_H
#define _LIST_H


typedef struct phone_date{
    struct phone_date* next;
    char id;
    char name[20];
    char phone_number[20];
    char home_address[30];
    char company_number[20];
}phone;




#endif