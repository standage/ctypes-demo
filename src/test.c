#include <stdio.h>
#include "mylib.h"

void print_gizmo(MyGizmo *g)
{
  printf("%s: %u\n", my_gizmo_get_label(g), my_gizmo_get_gcount(g));
}

void print_data(MyData *d)
{
  printf("%s\n", my_data_description(d));
}

int main()
{
  MyGizmo *g1 = my_gizmo_create(15, "Gizmo 1", NULL);
  MyGizmo *g2 = my_gizmo_create(20, "Gizmo 2", NULL);
  MyData  *d1 = my_data_create(NULL, "Empty data", "useless=true;level=9000", g2);
  print_gizmo(g1);
  print_gizmo(g2);
  print_data(d1);
  my_gizmo_delete(g1);
  my_gizmo_delete(g2);
  my_data_delete(d1);
  return 0;
}
