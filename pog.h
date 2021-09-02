#ifndef __RESOURCE_pog_H__
#define __RESOURCE_pog_H__

#include <gio/gio.h>

extern GResource *pog_get_resource (void);

extern void pog_register_resource (void);
extern void pog_unregister_resource (void);

#endif
