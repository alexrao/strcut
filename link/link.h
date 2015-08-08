#ifndef __LINK_H__
#define __LINK_H__
#include "config.h"


// 链表所有数据封装
struct stu_link_data
{
    uint32 data;
};


// 链表的结构体声明
struct struct_link
{
    struct stu_link_data link_data;   // 数据封装到结构体，方便扩充
    struct struct_link *next, *prew;
};

// 提前做好大小，方便后续使用
#define SIZE_STRUCT_LINK_DATA   sizeof(struct stu_link_data) 
#define SIZE_STRUCT_LINK    sizeof(struct struct_link)  

// 判定链表是否存在
int link_exist(void);

// 初始化链表
int link_creat(struct stu_link_data *data);

// 链表空间释放
void link_release(void);

#endif
