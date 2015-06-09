#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "view-manager.h"
#include "app.h"

static int _supplier_view_activate(basic_view_s *basic_view)
{
	supplier_view_s *supplier_view = (supplier_view_s*)basic_view;
	printf("Supplier (%s , %s) View activated.\n", supplier_view->supplier_name, supplier_view->supplier_id);
	return 1;
}

static int _supplier_view_destroy(basic_view_s *basic_view)
{
	supplier_view_s *supplier_view = (supplier_view_s*)basic_view;
	printf("Supplier (%s, %s) View destroyed.\n", supplier_view->supplier_name, supplier_view->supplier_id);
	free(supplier_view->supplier_name);
	free(supplier_view->supplier_id);
	free(supplier_view);
	return 1;
}


static int _supplier_view_init(basic_view_s *basic_view)
{
	supplier_view_s *supplier_view = (supplier_view_s*)basic_view;
	printf("Supplier View initialized with: ");
	printf("%s %s\n", supplier_view->supplier_name, supplier_view->supplier_id);
	app_push_view(app_get_data(), basic_view);
	return 1;
}

basic_view_s* create_supplier_view(char *name, char *id)
{
	supplier_view_s *customer_data = (supplier_view_s*)malloc(sizeof(supplier_view_s));
	customer_data->supplier_name = (char*)malloc(sizeof(char)* 100 + 1);
	customer_data->supplier_id = (char*)malloc(sizeof(char)* 100 + 1);
	strncpy_s(customer_data->supplier_name, 100, name, 100);
	strncpy_s(customer_data->supplier_id, 100, id, 100);


	basic_view_s *basic_view = (basic_view_s*)customer_data;
	basic_view->view_id = SUPPLIER_VIEW;
	basic_view->func.Init = _supplier_view_init;
	basic_view->func.Activate = _supplier_view_activate;
	basic_view->func.Destroy = _supplier_view_destroy;

	printf("Created supplier view. View Id - %d\n", basic_view->view_id);
	return basic_view;
}
