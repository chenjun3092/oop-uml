#include "app.h"

app_s *g_app_data = NULL;

void app_push_view(app_s *app, basic_view_s *view)
{
	app->top++;
	app->view_stack[app->top] = view;
	view->func.Activate(view);
}

void app_pop_view(app_s *app)
{
	if (app->top >= 0)
	{
		app->view_stack[app->top]->func.Destroy(app->view_stack[app->top]);
		app->top--;
	}
	if (app->top >= 0)
	{
		app->view_stack[app->top]->func.Activate(app->view_stack[app->top]);
	}
}

app_s* app_get_data(void)
{
	return g_app_data;
}

void app_init(void)
{
	g_app_data = (app_s*)malloc(sizeof(app_s));
	g_app_data->application_name = (char*)malloc(sizeof(char)* 100 + 1);
	g_app_data->device_id = (char*)malloc(sizeof(char)* 100 + 1);
	g_app_data->top = -1;
	strncpy_s(g_app_data->application_name, 100, "test_app", 8);
	strncpy_s(g_app_data->device_id, 100, "1234567890", 10);
}

void app_free(void)
{
	free(g_app_data->application_name);
	free(g_app_data->device_id);
	free(g_app_data);
}
