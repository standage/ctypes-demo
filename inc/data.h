/*
 (c) 2014 Daniel Standage <daniel.standage@gmail.com>
     This is free and unencumbered software released into the public domain.
*/

#ifndef MY_LIB_DATA_H
#define MY_LIB_DATA_H

#include "gizmo.h"

typedef struct MyData MyData;
typedef int (*MyDataHandlerFunc)(void *, const char *, void *);

// Constructor
MyData *my_data_create(void *payload, const char *description,
                       const char *meta, MyGizmo *target);
// Destructor
void my_data_delete(MyData *data);

// Getter function(s)
char *my_data_description(MyData *data);

// Callback function for processing the data
int my_data_process(MyData *data, MyDataHandlerFunc func, void *supp);

#endif
