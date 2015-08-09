#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "config.h"
#include "color_print.h"
#include "tcp_server.h"
#include "list.h"

// TCP服务线程
int thread_tcp (void)
{
	int ret;
	pthread_attr_t thread;
	pthread_t inputthreadid;
	
	pthread_attr_init (&thread);
	pthread_attr_setschedpolicy (&thread, SCHED_RR);
	
	ret=pthread_create (&inputthreadid, &thread, thread_tcp_run, NULL);
	pthread_attr_destroy(&thread);

	if (ret)
	{
		printf ("Can't create thread\n");
		fprintf(stderr, "[%s,%d]", __FILE__, __LINE__);
		perror("");
		return -1;
	}
	return 0;
}


// 链表服务线程
int thread_list (void)
{
	int ret;
	pthread_attr_t thread;
	pthread_t inputthreadid;
	
	pthread_attr_init (&thread);
	pthread_attr_setschedpolicy (&thread, SCHED_RR);
	
	ret=pthread_create (&inputthreadid, &thread, thread_list_run, NULL);
	pthread_attr_destroy(&thread);

	if (ret)
	{
		printf ("Can't create thread\n");
		fprintf(stderr, "[%s,%d]", __FILE__, __LINE__);
		perror("");
		return -1;
	}
	return 0;
}

