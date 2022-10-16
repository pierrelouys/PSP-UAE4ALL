#ifndef PSP_INCLUDES
#define PSP_INCLUDES

#include <pspkernel.h> 
#include <pspdebug.h> 
#include <psppower.h>
#include <pspsdk.h> 
#include <psputility.h> 
#include <pspmoduleinfo.h>
#include <pspnet_apctl.h> 
#include <pspnet_inet.h> 
#include <pspnet_resolver.h> 
#include <netinet/in.h> 
//#include "net_io.h"
#include <pspctrl.h>
#ifdef PSPSLIM
void psp2k_mem_init(void);
#endif
#endif

extern char progpath[256];
extern char disk_dir[256];
