#ifndef DRAWING_H
#define DRAWING_H

/* SRC Headers */
#include <point.h>

extern int drawing;
extern Point* points;

void start_stroke(Point point);
void add_to_stroke(Point point);
void stop_stroke();

#endif