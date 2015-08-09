/*****************************************
* Feature: 数据结构的相关练习
* Author: rxp
* Date:2005.08.08
*****************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "color_print.h"
#include "config.h"
#include "link.h"


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


// 延迟ms
void msleep(int32 usec)
{
	usleep(1000*usec);
}
// 主函数
void main(int argc, char **argv)
{
	(void)argc;
	(void **)argv;
	
	uint32 input_sel = 0;
	uint32 pos = 0;
	struct stu_list_data list_data;
	struct stu_list *head_list;

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
			printf("Input position/number and name: ");
			scanf("%d %d %s", &pos, &list_data.num, list_data.name);
			CPRINTF(1,"====");
			list_insert(head_list, &list_data, pos);
			CPRINTF(1,"====");
        }
        else if(input_sel == LINK_MODE_DELETE)
        {			
			printf("Input delete position: ");
			scanf("%d", &pos);
			list_delete(pos);
        }
        else if(input_sel == LINK_MODE_RELEASE)
        {			
			list_release(head_list);
        }
        else if(input_sel == LINK_MODE_PRINT)
        {			
			list_print(head_list, head_list);
        }
		else
		{
			CPRINTF(1,"Select Error mode:%d", input_sel);
		}
		input_sel = 0;

    }
    CPRINTF(1, "GoodBye");
}
