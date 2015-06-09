#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "defines.h"
#include "app.h"
#include "view-manager.h"

int main(void)
{
	view_manager_s *view_mgr = create_view_manager();
	view_mgr_register_view(view_mgr, CUSTOMER_VIEW, create_customer_view);
	view_mgr_register_view(view_mgr, ADMIN_VIEW, create_admin_view);
	view_mgr_register_view(view_mgr, SUPPLIER_VIEW, create_supplier_view);
	
	app_init();
	app_get_data()->view_manager = view_mgr;
	view_mgr->app_data = app_get_data();

	view_mgr_create_view(app_get_data()->view_manager, CUSTOMER_VIEW, "customer1", "customer1_id");
	view_mgr_create_view(app_get_data()->view_manager, ADMIN_VIEW, "admin1", "admin_id");
	view_mgr_create_view(app_get_data()->view_manager, SUPPLIER_VIEW, "supplier1", "supplier_id");

	printf("\n =========Now Popping views from stack==========\n");

	app_pop_view(app_get_data());
	app_pop_view(app_get_data());
	app_pop_view(app_get_data());

	free(view_mgr);
	app_free();
	return 0;
}

