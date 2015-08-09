#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "config.h"
#include "list.h"
#include "color_print.h"


#include <stdio.h>
#include <unistd.h>
	
	
// ѡ�������״̬
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


// ������
void *thread_list_run(void *arg)
{
	(void*)arg;
	
	uint32 input_sel = 0;
	uint32 input_num = 0;
	struct stu_list *head_list;
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
									
			head_list = list_creat(head_list, &list_data);
        }
        else if(input_sel == LINK_MODE_INSERT)
        {	
			memset(&list_data, 0, SIZE_LIST_DATA);
			printf("Input number and name: ");
			scanf("%d %s", &list_data.num, list_data.name);
			CPRINTF(1,"====");
			list_insert(head_list, &list_data, 0);
			CPRINTF(1,"====");
        }
        else if(input_sel == LINK_MODE_DELETE)
        {			
			printf("Input delete position: ");
			scanf("%d", &input_num);
			if(list_delete(head_list, input_num) == FALSE)
			{
				CPRINTF(1, "Delete Data Fail ");
			}
			else
			{
				CPRINTF(1, "Delete Data Success ");
			}
        }
        else if(input_sel == LINK_MODE_RELEASE)
        {			
			list_release(head_list);
        }
        else if(input_sel == LINK_MODE_PRINT)
        {	
			CPRINTF(2,"LINK_MODE_PRINT");
			list_print(head_list);
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


// �����ʼ��
/*************************************************************************
* ����: list_creat
* ����: �����ʼ��
* ����: rxp
* ����: list_head: �����ʼ��������
* 		list_data: �����ʼ��������
* ����: ���س�ʼ������������
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
* ����: list_insert
* ����: ����Ĳ���
* ����: rxp
* ����: list_head: �����������
* 		list_data: �¼�������������
* 		pos		 : <��δ����>
* ����: ���ؼ����Ƿ�ɹ�
*************************************************************************/
uint32 list_insert(struct stu_list *list_head, struct stu_list_data *list_data, uint32 pos)
{
	(void)pos;
	struct stu_list *list = list_head;
	CPRINTF(1,"====");
	
	if(NULL == list_head)
	{
		CPRINTF(1,"====");
		list_head = list_creat(list_head, list_data);
		if(NULL == list_head)
			return FALSE;
	}
	else
	{
		CPRINTF(1,"====");
		list = (struct stu_list *)malloc(SIZE_LIST);
		if(NULL == list)
		{
			CPRINTF(1,"Add false");
			return FALSE;
		}
		
		CPRINTF(1,"====");
	    memcpy(&list->list_data, list_data, SIZE_LIST_DATA);

		list->prew = list_head->prew;
		list->next = list_head;
		list_head->prew->next = list;
		list_head->prew = list;
		CPRINTF(1,"====");
	}
	CPRINTF(1,"====");
	
	return TRUE;
}


// ɾ������
uint32  list_delete(struct stu_list *list_head, uint32 num)
{
	struct stu_list *list = list_head;

	CPRINTF(1,"num=%d", num);
	if(list->next == list_head)
	{
		CPRINTF(1,"num=%d", num);
		if(list->list_data.num == num)
		{
			free(list_head);
			list_head = NULL;
			return TRUE;
		}
	}
	else
	{
		CPRINTF(1,"num=%d", num);
		
		do
		{
			CPRINTF(2,"==list:%d, %s===", list->list_data.num, list->list_data.name);
			if(list->list_data.num == num)
			{
				if(list == list_head)
				{
					list_head = list_head->next;
				}
				
				list->prew->next = list->next;
				list->next->prew = list->prew;
				CPRINTF(1,"==list:%d, %s===", list->list_data.num, list->list_data.name);
				free(list);
				list = NULL;
				return TRUE;
			}
			else
			{
				list = list->next;
			}
		}while(list != list_head);
	}

	return FALSE;
}


// ����ռ��ͷ�
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
		headlist = NULL;
		headlist = list;
		
		if(list_head == list)
			break;
	}
	list_head = NULL;
	CPRINTF(1,"list_release success");
}


// �������ݴ�ӡ
void list_print(struct stu_list *list_head)
{
	struct stu_list *listhead = list_head;

	if(listhead == NULL)
	{
		CPRINTF(2,"list NULL");
		return;
	}
	
	CPRINTF(2, "list print :num:%d, name:%s", list_head->list_data.num, list_head->list_data.name);

	if(listhead->next != list_head)
		list_print(list_head->next, list_start);

}

