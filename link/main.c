/*****************************************
* Feature: 数据结构的相关练习
* Author: rxp
* Date:2005.08.08
*****************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "color_print.h"
#include "config.h"
#include "list.h"
#include "thread.h"


// 主函数
void main(int argc, char **argv)
{
	(void)argc;
	(void **)argv;
	
	uint32 count = 0;
	
	// 创建tcp数据线程
	if (-1 == thread_tcp ())
	{
		printf("Create Thread Fail");
	    exit (-1);
	}

	// 创建链表数据线程
	if (-1 == thread_list ())
	{
		printf("Create Thread Fail");
	    exit (-1);
	}
	
	while(1)
    {
//		CPRINTF(1, "main thread count:%d", ++count);
		sleep(10);
    }
    CPRINTF(1, "GoodBye");
}


