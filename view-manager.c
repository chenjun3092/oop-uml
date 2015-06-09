#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "view-manager.h"


view_manager_s* create_view_manager(void)
{
	view_manager_s *view_mgr = (view_manager_s*)malloc(sizeof(view_manager_s));
	return view_mgr;
}

void view_mgr_register_view(view_manager_s *view_mgr, int view_id, create_view_func create_func)
{
	view_mgr->create_view_func_array[view_id] = create_func;
}

void view_mgr_create_view(view_manager_s *view_mgr, int view_id, char *name, char *id)
{
	printf("Creating view - %d\n", view_id);
	basic_view_s *basic_view = view_mgr->create_view_func_array[view_id](name, id);
	basic_view->func.Init(basic_view);
}
