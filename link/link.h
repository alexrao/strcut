#ifndef __LINK_H__
#define __LINK_H__
#include "config.h"


// �����������ݷ�װ
struct stu_link_data
{
    uint32 data;
};


// ����Ľṹ������
struct struct_link
{
    struct stu_link_data link_data;   // ���ݷ�װ���ṹ�壬��������
    struct struct_link *next, *prew;
};

// ��ǰ���ô�С���������ʹ��
#define SIZE_STRUCT_LINK_DATA   sizeof(struct stu_link_data) 
#define SIZE_STRUCT_LINK    sizeof(struct struct_link)  

// �ж������Ƿ����
int link_exist(void);

// ��ʼ������
int link_creat(struct stu_link_data *data);

// ����ռ��ͷ�
void link_release(void);

#endif
