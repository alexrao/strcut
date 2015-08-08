/*****************************************
* Feature: 数据结构的相关练习
* Author: rxp
* Date:2005.08.08
*****************************************/

#include <stdio.h>
#include <string.h>
#include "color_print.h"
#include "config.h"
#include "link.h"


// 选择输入的状态
enum
{
    LINK_MODE_NULL = 0,
    LINK_MODE_INIT,
    LINK_MODE_INSERT,
    LINK_MODE_DELET,
    LINK_MODE_RELEASE,
    LINK_MODE_COUNT,
}link_mode;


// 主函数
void main(int argc, char **argv)
{
	(void)argc;
	(void **)argv;
	
	uint32 input_sel = 0;
	uint32 input_data = 0;
	struct stu_link_data link_data;

    while(1)
    {
    	CPRINTF(1,"Please input mode:  1: init link  2: insert new data;  3: delete one data;  4: release link ");
		scanf("%d", &input_sel);
		
        if(input_sel == LINK_MODE_INIT)
        {
			printf("Input init data: ");
			scanf("%d", &input_data);
			
			link_data.data = input_data;
			
			CPRINTF(1,"get data:%d ", link_data.data);
			
			link_creat(&link_data);
        }
        else if(input_sel == LINK_MODE_RELEASE)
        {			
			link_release();
			break;
        }
		else
		{
			CPRINTF(1,"Select Error mode:%d", input_sel);
		}
		
    }
    CPRINTF(1, "GoodBye");
}
