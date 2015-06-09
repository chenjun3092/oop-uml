#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "view-manager.h"
#include "app.h"

static int _admin_view_activate(basic_view_s *basic_view)
{
	admin_view_s *admin_view = (admin_view_s*)basic_view;
	printf("Admin (%s , %s) View activated.\n", admin_view->admin_name, admin_view->admin_id);
	return 1;
}

static int _admin_view_destroy(basic_view_s *basic_view)
{
	admin_view_s *admin_view = (admin_view_s*)basic_view;
	printf("Admin (%s, %s) View destroyed.\n", admin_view->admin_name, admin_view->admin_id);
	free(admin_view->admin_name);
	free(admin_view->admin_id);
	free(admin_view);
	return 1;
}


static int _admin_view_init(basic_view_s *basic_view)
{
	admin_view_s *admin_view = (admin_view_s*)basic_view;
	printf("Admin View initialized with: ");
	printf("%s %s\n", admin_view->admin_name, admin_view->admin_id);
	app_push_view(app_get_data(), basic_view);
	return 1;
}

basic_view_s* create_admin_view(char *name, char *id)
{
	admin_view_s *customer_data = (admin_view_s*)malloc(sizeof(admin_view_s));
	customer_data->admin_name = (char*)malloc(sizeof(char)* 100 + 1);
	customer_data->admin_id = (char*)malloc(sizeof(char)* 100 + 1);
	strncpy_s(customer_data->admin_name, 100, name, 100);
	strncpy_s(customer_data->admin_id, 100, id, 100);


	basic_view_s *basic_view = (basic_view_s*)customer_data;
	basic_view->view_id = ADMIN_VIEW;
	basic_view->func.Init = _admin_view_init;
	basic_view->func.Activate = _admin_view_activate;
	basic_view->func.Destroy = _admin_view_destroy;

	printf("Created admin view. View Id - %d\n", basic_view->view_id);
	return basic_view;
}
