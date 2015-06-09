#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "view-manager.h"
#include "app.h"


static int _customer_view_activate(basic_view_s *basic_view)
{
	customer_view_s *customer_view = (customer_view_s*)basic_view;
	printf("Customer (%s , %s) View activated.\n", customer_view->customer_name, customer_view->customer_user_name);
	return 1;
}

static int _customer_view_destroy(basic_view_s *basic_view)
{
	customer_view_s *customer_view = (customer_view_s*)basic_view;
	printf("Customer (%s, %s) View destroyed.\n", customer_view->customer_name, customer_view->customer_user_name);
	free(customer_view->customer_name);
	free(customer_view->customer_user_name);
	free(customer_view);
	return 1;
}


static int _customer_view_init(basic_view_s *basic_view)
{
	customer_view_s *customer_view = (customer_view_s*)basic_view;
	printf("Customer View initialized with: ");
	printf("%s %s\n", customer_view->customer_name, customer_view->customer_user_name);
	app_push_view(app_get_data(), basic_view);
	return 1;
}

basic_view_s* create_customer_view(char *name, char *id)
{
	customer_view_s *customer_data = (customer_view_s*)malloc(sizeof(customer_view_s));
	customer_data->customer_name = (char*)malloc(sizeof(char)* 100 + 1);
	customer_data->customer_user_name = (char*)malloc(sizeof(char)* 100 + 1);
	strncpy_s(customer_data->customer_name, 100, name, 100);
	strncpy_s(customer_data->customer_user_name, 100, id, 100);

	
	basic_view_s *basic_view = (basic_view_s*)customer_data;
	basic_view->view_id = CUSTOMER_VIEW;
	basic_view->func.Init = _customer_view_init;
	basic_view->func.Activate = _customer_view_activate;
	basic_view->func.Destroy = _customer_view_destroy;
	
	printf("Created customer view. View Id - %d\n", basic_view->view_id);
	return basic_view;
}
