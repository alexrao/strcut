#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "config.h"
#include "list.h"
#include "color_print.h"


#include <stdio.h>
#include <unistd.h>
	
	
// 选择输入的状态
enum
{
    LINK_MODE_NULL = 0,
    LINK_MODE_INIT,
    LINK_MODE_INSERT,
    LINK_MODE_DELETE,
	LINK_MODE_RELEASE,
	LINK_MODE_PRINT,
    LINK_MODE_COUNT,
}list_mode;


// 主函数
void *thread_list_run(void *arg)
{
	(void*)arg;
	
	uint32 input_sel = 0;
	uint32 input_num = 0;
	struct stu_list *list_head;
	struct stu_list_data list_data;

	while(1)
    {
    	CPRINTF(1,"Please input mode:  1: init  2: insert data;  3: delete one;  4: release; 5: print ");
		scanf("%d", &input_sel);
		
        if(input_sel == LINK_MODE_INIT)
        {
			memset(&list_data, 0, SIZE_LIST_DATA);
			printf("Input number and name: ");
			scanf("%d %s", &list_data.num, list_data.name);
									
			list_head = list_creat(list_head, &list_data);
        }
        else if(input_sel == LINK_MODE_INSERT)
        {	
			memset(&list_data, 0, SIZE_LIST_DATA);
			
			printf("Input number and name: ");
			scanf("%d %s", &list_data.num, list_data.name);
			
			list_insert(list_head, &list_data, 0);
        }
        else if(input_sel == LINK_MODE_DELETE)
        {			
			printf("Input delete position: ");
			scanf("%d", &input_num);
			
			list_head = list_delete(list_head, input_num));
        }
        else if(input_sel == LINK_MODE_RELEASE)
        {			
			list_release(list_head);
        }
        else if(input_sel == LINK_MODE_PRINT)
        {	
			list_print(list_head);
        }
		else
		{
			CPRINTF(1,"Select Error mode:%d", input_sel);
		}
		input_sel = 0;
		sleep(1);
    }
    CPRINTF(1, "GoodBye");
}	


// 链表初始化
/*************************************************************************
* 函数: list_creat
* 功能: 链表初始化
* 作者: rxp
* 参数: list_head: 所需初始化的链表
* 		list_data: 所需初始化的数据
* 返回: 返回初始化创建的链表
*************************************************************************/
struct stu_list *list_creat(struct stu_list *list_head, struct stu_list_data *list_data)
{
	if(list_head != NULL)
	{
		CPRINTF(1,"struct is already exist");
	}
	else
	{
	    list_head = (struct stu_list *)malloc(SIZE_LIST);
		if(NULL == list_head)
		{
			CPRINTF(1,"List Create fail");
			return NULL;
		}
		
	    memcpy(&list_head->list_data, list_data, SIZE_LIST_DATA);
	    list_head->prew = list_head;
	    list_head->next = list_head; 
		
	    CPRINTF(1,"list_init OK:num:%d, name:%s", list_head->list_data.num, list_head->list_data.name);
	}
	
	return list_head;
}


/*************************************************************************
* 函数: list_insert
* 功能: 链表的插入
* 作者: rxp
* 参数: list_head: 被插入的链表
* 		list_data: 新加入的链表的数据
* 		pos		 : <暂未开放>
* 返回: 返回加入是否成功
*************************************************************************/
uint32 list_insert(struct stu_list *list_head, struct stu_list_data *list_data, uint32 pos)
{
	(void)pos;
	struct stu_list *list = list_head;
	
	if(NULL == list_head)
	{
		list_head = list_creat(list_head, list_data);
		if(NULL == list_head)
			return FALSE;
	}
	else
	{
		list = (struct stu_list *)malloc(SIZE_LIST);
		if(NULL == list)
		{
			CPRINTF(1,"Add false");
			return FALSE;
		}
		
	    memcpy(&list->list_data, list_data, SIZE_LIST_DATA);

		list->prew = list_head->prew;
		list->next = list_head;
		list_head->prew->next = list;
		list_head->prew = list;
	}
	
	return TRUE;
}


// 删除链表
struct stu_list *list_delete(struct stu_list *list_head, uint32 num)
{
	struct stu_list *list;
	if(list_head == NULL)
	{
		CPRINTF(1,"list is NULL");
		return NULL;
	}
	
	list = list_head;

	if(list->next == list_head)
	{
		if(list->list_data.num == num)
		{
			free(list_head);
			list_head = NULL;
			return list_head;
		}
	}
	else
	{
		do
		{
			if(list->list_data.num == num)
			{
				list->prew->next = list->next;
				list->next->prew = list->prew;

				if(list == list_head)
				{
					list_head = list_head->next;
				}
				free(list);
				list = NULL;
				return list_head;
			}
			else
			{
				list = list->next;
			}
		}while(list != list_head);
	}

	CPRINTF(1,"list num not found");
	return list_head;
}


// 链表空间释放
void list_release(struct stu_list *list_head)
{	
	struct stu_list *headlist = list_head, *list;
	if(NULL == list_head)
	{
		CPRINTF(3,"List is already NULL");
		return;
	}
	
	while(headlist)
	{
	    CPRINTF(2,"list release :num:%d, name:%s", headlist->list_data.num, headlist->list_data.name);
		list = headlist->next;
		free(headlist);
		headlist = list;
		
		if(list_head == list)
			break;
	}
	list_head = NULL;
	CPRINTF(1,"list_release success");
}


// 链表数据打印
void list_print(struct stu_list *list_head)
{
	struct stu_list *list = list_head;

	if(list == NULL)
	{
		CPRINTF(2,"list NULL");
		return;
	}
	
	do
	{
		CPRINTF(2, "list print :num:%d, name:%s", list->list_data.num, list->list_data.name);
		list = list->next;
	}while(list != list_head);

}

