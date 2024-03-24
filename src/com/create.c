#include"../../inc/phone.h"

int create(phone *head)
{
    phone *p = head;
    phone *newstudent = malloc(sizeof(phone));
    if(NULL == newstudent)
    {
		return -1;
    }
	printf("\33[0;34m请输入信息\33[0m\n");
    srand((unsigned)time(NULL));
    newstudent->id = rand() % 100;  // create one  suijishu
    printf("%d\n",newstudent->id);

	printf("\33[0;34m名字\33[0m\n");
    printf("name :\n");
    scanf("%s",newstudent->name);

	printf("\33[0;34m电话号码\33[0m\n");
    scanf("%s",newstudent->phone_number);

	printf("\33[0;34m家庭地址\33[0m\n");
    scanf("%s",newstudent->home_address);

	printf("\33[0;34m公司号码\33[0m\n");
    scanf("%s",newstudent->company_number);

    newstudent->next = NULL;

    while(head->next != NULL)
    {
		head = head->next;
    }
    head->next = newstudent;

    printf("\33[0;32m  create!  \33[0m\n");
	getchar();
	getchar();
    head = p;//变回头节点
    return 0;
}