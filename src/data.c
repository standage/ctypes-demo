/*
 (c) 2014 Daniel Standage <daniel.standage@gmail.com>
     This is free and unencumbered software released into the public domain.
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

struct MyData
{
  void *payload;
  char *description;
  char *meta;
  MyGizmo *target;
};

MyData *my_data_create(void *payload, const char *description,
                       const char *meta, MyGizmo *target)
{
  MyData *data = malloc( sizeof(MyData) );
  data->payload = payload;
  data->description = NULL;
  data->meta = NULL;
  data->target = NULL;

  if (description != NULL)
    data->description = strdup(description);
  if (meta != NULL)
    data->meta = strdup(meta);
  if (target != NULL)
    data->target = my_gizmo_incref(target);

  return data;
}

void my_data_delete(MyData *data)
{
  assert(data != NULL);
  if (data->description != NULL) {
    free(data->description);
    data->description = NULL;
  }
  if (data->meta != NULL) {
    free(data->meta);
    data->meta = NULL;
  }
  if (data->target != NULL) {
    my_gizmo_delete(data->target);
    data->target = NULL;
  }
  free(data);
}

char *my_data_description(MyData *data)
{
  assert(data != NULL);
  return data->description;
}

int my_data_process(MyData *data, MyDataHandlerFunc func, void *supp)
{
  assert(data != NULL);
  return func(data->payload, data->meta, supp);
}

