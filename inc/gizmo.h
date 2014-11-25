/*
 (c) 2014 Daniel Standage <daniel.standage@gmail.com>
     This is free and unencumbered software released into the public domain.
*/

#ifndef MY_LIB_GIZMO_H
#define MY_LIB_GIZMO_H

typedef struct MyGizmo MyGizmo;

// Constructor
MyGizmo *my_gizmo_create(unsigned int c, const char *label, MyGizmo *model);

// Increase reference count
MyGizmo *my_gizmo_incref(MyGizmo *g);

// Destructor
void my_gizmo_delete(MyGizmo *g);

// Getter methods
unsigned int my_gizmo_get_gcount(MyGizmo *g);
const char *my_gizmo_get_label(MyGizmo *g);
MyGizmo *my_gizmo_get_model(MyGizmo *g);

#endif
