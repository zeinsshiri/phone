#include"../../inc/com/init.h"

int init(phone** head){
    phone* node = malloc(sizeof(phone));
    if(node == NULL){
        perror("malloc");
        return -1;
    }
    node->next = NULL;
    
    *head = node;
    
    return 0;
}

phone *destroy(phone *head)
{
    while(head->next != NULL)
    {
		phone *ptr = head;
		head = head->next;
		free(ptr);
    }
    free(head);
    head = NULL;
    return head;
}