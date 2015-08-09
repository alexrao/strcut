#ifndef __LINK_H__
#define __LINK_H__
#include "config.h"


// �����������ݷ�װ
struct stu_list_data
{
    uint32 num;
	char name[20];
};


// ����Ľṹ������
struct stu_list
{
	uint32 pos;
    struct stu_list_data list_data;   // ���ݷ�װ���ṹ�壬��������
    struct stu_list *next, *prew;
};

// ��ǰ���ô�С���������ʹ��
#define SIZE_LIST_DATA   sizeof(struct stu_list_data) 
#define SIZE_LIST    sizeof(struct stu_list)  

// �ж������Ƿ����
int list_exist(void);

// ��ʼ������
struct stu_list *list_creat(struct stu_list *list_head, struct stu_list_data *list_data);

// �������
uint32 list_insert(struct stu_list *list_head, struct stu_list_data *list_data, uint32 pos);

// ɾ������
uint32  list_delete(uint32 pos);

// ����ռ��ͷ�
void list_release(struct stu_list *list_head);

// �������ݴ�ӡ
void list_print(struct stu_list *list_head, struct stu_list *list_start);

#endif
