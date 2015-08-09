#include <stdio.h>
#include <unistd.h>

#include "config.h"
#include "color_print.h"


void *thread_tcp_run(void *arg)
{
	(void *)arg;
	
	CPRINTF(3,"data_tcp_server Start");
	int count = 0;
	while(1)
	{
//		CPRINTF(3,"tcp server count:%d",++count);
		sleep(10);
	}
	CPRINTF(3,"data_tcp_server END");
	
}

