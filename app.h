#include "defines.h"

#ifndef __APP__
#define __APP__

void app_push_view(app_s *app, basic_view_s *view);
void app_pop_view(app_s *app);
app_s* app_get_data(void);
void app_init(void);
void app_free(void);

#endif
