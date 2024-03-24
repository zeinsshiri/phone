#include"../../inc/phone.h"

int search(phone *head){
    phone *p =  head;
    int count = 0;
    char name[32];

    printf("please input you want search name:\n ");
    scanf("%s",name);
    while(head->next != NULL){
        if(strcmp(head->next->name,name) == 0){
            count++;
            show_item(head);
        }
        head = head->next;
    }
    if(count == 0)
    {
		printf("No search this people!\n");
		printf("Search error!\n");
    }
    printf("\n");
    head = p;

}