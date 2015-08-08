#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "config.h"
#include "link.h"
#include "color_print.h"

struct struct_link *stu_link = NULL;

// 链表判定
int link_exist(void)
{
	if(stu_link == NULL)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

// 链表初始化
int link_creat(struct stu_link_data *data)
{
	if(link_exist() == TRUE)
	{
		CPRINTF(1,"Link Create is already exist, Create fail");
		return FALSE;
	}
	
    stu_link = (struct struct_link *)malloc(SIZE_STRUCT_LINK);
	if(NULL == stu_link)
	{
		CPRINTF(1,"Link Create is already exist, Create fail");
		return FALSE;
	}
	
    memcpy(&stu_link->link_data, data, SIZE_STRUCT_LINK_DATA);
    stu_link->prew = NULL;
    stu_link->next = NULL; 
	
    CPRINTF(1,"link_init OK:data:%d", stu_link->link_data.data);
	
	return TRUE;
}


// 链表空间释放
void link_release(void)
{
	if(link_exist() == FALSE)
	{
		CPRINTF(1,"Link struct no exist");
		return;
	}
	
	free(stu_link);
	CPRINTF(1,"link_release success");
}

