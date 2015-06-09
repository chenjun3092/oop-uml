#include <stdlib.h>

#ifndef __MY_DEFINES__
#define __MY_DEFINES__

#define MAX_VIEWS 100

struct _app;

typedef enum _views_e
{
	CUSTOMER_VIEW = 0,
	ADMIN_VIEW,
	SUPPLIER_VIEW,
	MAX_VIEW
}view_e;

struct _basic_view;

typedef struct _basic_view
{
	int view_id;
	// function pointers to Init, Activate and Destroy.
	struct _func
	{
		int(*Init) (struct _basic_view*);
		int(*Activate) (struct _basic_view*);
		int(*Destroy) (struct _basic_view*);
	}func;
} basic_view_s;

typedef struct _customer_view
{
	basic_view_s basic_view;
	char *customer_name;
	char *customer_user_name;
} customer_view_s;

typedef struct _admin_view
{
	basic_view_s basic_view;
	char *admin_name;
	char *admin_id;
} admin_view_s;

typedef struct _supplier_view
{
	basic_view_s basic_view;
	char *supplier_name;
	char *supplier_id;
} supplier_view_s;

// Function pointer definition to create a view
typedef basic_view_s*(*create_view_func)(char*, char*);

typedef struct _view_manager
{
	// Array of function pointers. Index corresponds to view id.
	create_view_func create_view_func_array[MAX_VIEW];
	struct _app *app_data;
}view_manager_s;

typedef struct _app
{
	char *application_name;
	char *device_id;
	view_manager_s *view_manager;
	basic_view_s *view_stack[MAX_VIEWS];
	int top;
} app_s;

#endif
