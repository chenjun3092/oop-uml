#include "defines.h"

#ifndef __VIEW_MGR__
#define __VIEW_MGR__

view_manager_s* create_view_manager(void);
void view_mgr_register_view(view_manager_s *view_mgr, int view_id, create_view_func create_func);
void view_mgr_create_view(view_manager_s *view_mgr, int view_id, char *name, char *id);

basic_view_s* create_supplier_view(char *name, char *id);
basic_view_s* create_customer_view(char *name, char *id);
basic_view_s* create_admin_view(char *name, char *id);

#endif
