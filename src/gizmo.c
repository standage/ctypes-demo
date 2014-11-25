/*
 (c) 2014 Daniel Standage <daniel.standage@gmail.com>
     This is free and unencumbered software released into the public domain.
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "gizmo.h"

struct MyGizmo
{
  unsigned int gcount;
  char *label;
  MyGizmo *model;
  unsigned int refcount;
};

MyGizmo *my_gizmo_create(unsigned int c, const char *label, MyGizmo *model)
{
  MyGizmo *g = malloc( sizeof(MyGizmo) );
  g->gcount = c;
  g->label = strdup(label);
  g->refcount = 1;
  g->model = NULL;
  if (model != NULL)
    g->model = my_gizmo_incref(model);
  return g;
}

MyGizmo *my_gizmo_incref(MyGizmo *g)
{
  assert(g != NULL);
  g->refcount += 1;
  return g;
}

void my_gizmo_delete(MyGizmo *g)
{
  assert(g != NULL);
  if (g->refcount == 1) {
    if (g->model) {
      my_gizmo_delete(g->model);
      g->model = NULL;
    }
    free(g->label);
    g->label = NULL;
    free(g);
  }
  else
    g->refcount -= 1;
}

unsigned int my_gizmo_get_gcount(MyGizmo *g)
{
  assert(g != NULL);
  return g->gcount;
}

const char *my_gizmo_get_label(MyGizmo *g)
{
  assert(g != NULL);
  return g->label;
}

MyGizmo *my_gizmo_get_model(MyGizmo *g)
{
  assert(g != NULL);
  return g->model;
}
