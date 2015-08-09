#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "config.h"
#include "link.h"
#include "color_print.h"


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
* 		pos		 : �¼���������������λ��(0Ϊ��ʼ����������ʵ�����)
* ����: ���ؼ����Ƿ�ɹ�
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


// ɾ������
uint32  list_delete(uint32 pos)
{
	
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
void list_print(struct stu_list *list_head, struct stu_list *list_start)
{
	if(list_head == NULL)
	{
		CPRINTF(2,"list NULL");
		return;
	}
	
	CPRINTF(2, "list print :num:%d, name:%s", list_head->list_data.num, list_head->list_data.name);

	if(list_head->next != list_start)
		list_print(list_head->next, list_start);

}

