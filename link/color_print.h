#ifndef	__DPRINTF_H__
#define	__DPRINTF_H__

#include <stdio.h>
#define CPRINTF(enable, ...) cprintf_impl (__FILE__, __LINE__, __FUNCTION__, enable, ## __VA_ARGS__)
void cprintf_impl (const char *filename, int linenum, const char *funcname, int enable, const char *fmt, ...);

#endif	// __DPRINTF_H__
