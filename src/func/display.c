#include"../../inc/phone.h"

void show_item(phone *head)    //显示全部信息
{
   // printf("\033[0;33m\tid = %d\033[0m\n",head->next->id);
    printf("\033[0;33m\t姓名： %s\033[0m\n",head->next->name);
    printf("\033[0;33m\t电话号码： %s\033[0m\n",head->next->phone_number);
    printf("\033[0;33m\t家庭地址: %s\033[0m\n",head->next->home_address);
    printf("\033[0;33m\t公司电话: %s\033[0m\n",head->next->company_number);
}

int display(phone *head)
{
    phone *p = head;
	int num = 0;
    
    if(head == NULL)
    {
		printf("\33[0;31m  No this people！	\33[0m\n");
		return -1;
    }
    while(head->next != NULL)
    {

		printf("\033[0;33m+----------------------[%d]----------------------+\033[0m\n",num++);
		show_item(head);
		
		head = head->next;
    }
	printf("\033[0;33m+-----------------------end----------------------+\033[0m\n");
	getchar();
	
	getchar();
    head = p;    //返回头节点
}