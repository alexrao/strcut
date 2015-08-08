#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "color_print.h"

//==================================================
// Function Name : cprintf_impl
// 說明: 在console打印出有颜色的讯息，内容为:文件名/行号/函数 以及传入的参数内容
// Author: rxp
// Date: 2015.08.08
// Input Key: 
//			filename:文件名字
//			linenum:行号
//			funcname:函数名称
//			enable:小于0的时候不显示(release 版本的时候不需要打印)
//			fmt:传入的参数
// Return 值: 无
//==================================================
void cprintf_impl (const char *filename, int linenum, const char *funcname, int enable, const char *fmt, ...)
{
	//return;
	if (enable < 0)
		return;
	else
	{
		va_list ap;
		if (enable == 0)	// White
			fprintf (stderr, "\033[1;37m[%s] %d (%s): ", filename, linenum, funcname);
		if (enable == 1)	// red
			fprintf (stderr, "\033[1;31m[%s] %d (%s): ", filename, linenum, funcname);
		else if (enable == 2)	// blue
			fprintf (stderr, "\033[0;34m[%s] %d (%s): ", filename, linenum, funcname);
		else if (enable == 3)	// cyan
			fprintf (stderr, "\033[0;36m[%s] %d (%s): ", filename, linenum, funcname);
		else if (enable == 4)	// yellow
		{
			fprintf (stderr, "\033[1;33m[%s] %d (%s): ", filename, linenum, funcname);
		}
		va_start (ap, fmt);
		vfprintf (stderr, fmt, ap);
		va_end (ap);
		fprintf (stderr, "\033[0m");	// none
		fflush (stderr);
		fprintf (stderr, "\n");
	}
}

/*
颜色如下:
none="\033[0m"
black="\033[0;30m"
dark_gray="\033[1;30m"
blue="\033[0;34m"
light_blue="\033[1;34m"
green="\033[0;32m"
light_green="\033[1;32m"
cyan="\033[0;36m"
light_cyan="\033[1;36m"
red="\033[0;31m"
light_red="\033[1;31m"
purple="\033[0;35m"
light_purple="\033[1;35m"
brown="\033[0;33m"
yellow="\033[1;33m"
light_gray="\033[0;37m"
white="\033[1;37m"
*/
