#include"../../inc/phone.h"

int delete(phone *head)
{
    phone *p = head;
    char name[32];
    int count = 0;
    printf("please input your want delete one name:\n");
    scanf("%s",name);

    printf("will delete user:%s\n",name);
    while(p->next != NULL)
    {
        if(strcmp(p->next->name,name) == 0)
        {
            count++;
            phone* tem = p->next;
            p->next = p->next->next;
            free(tem);
            break;
        }
        p = p->next;
    }

    if(count == 0)
    {
		printf("No this one name!\n");
		return -1;
    }
    else
    {
		printf("\33[0;32m  delete is ok!\33[0m\n");
    }

    printf("\n");
    return 0;
    
}