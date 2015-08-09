#ifndef __LINK_H__
#define __LINK_H__
#include "config.h"


// 链表所有数据封装
struct stu_list_data
{
    uint32 num;
	char name[20];
};


// 链表的结构体声明
struct stu_list
{
	uint32 pos;
    struct stu_list_data list_data;   // 数据封装到结构体，方便扩充
    struct stu_list *next, *prew;
};

// 提前做好大小，方便后续使用
#define SIZE_LIST_DATA   sizeof(struct stu_list_data) 
#define SIZE_LIST    sizeof(struct stu_list)  

// 判定链表是否存在
int list_exist(void);

// 初始化链表
struct stu_list *list_creat(struct stu_list *list_head, struct stu_list_data *list_data);

// 链表插入
uint32 list_insert(struct stu_list *list_head, struct stu_list_data *list_data, uint32 pos);

// 删除链表
uint32  list_delete(uint32 pos);

// 链表空间释放
void list_release(struct stu_list *list_head);

// 链表数据打印
void list_print(struct stu_list *list_head, struct stu_list *list_start);

#endif
