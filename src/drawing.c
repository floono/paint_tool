/* STD Headers */
#include <string.h>

/* SRC Headers */
#include <point.h>

/* STB Headers */
#include <stb_ds.h>

int drawing = 0;
Point* points = NULL;

int num_interpolated_points = 10;

Point point_lerp(Point p1, Point p2, float t)
{
    Point p;
    p.x = (1 - t) * p1.x + t * p2.x;
    p.y = (1 - t) * p1.y + t * p2.y;
    return p;
}

void start_stroke(Point point)
{
    if(!drawing)
    {
        arrput(points, point);
        drawing = 1;
    }
}

void add_to_stroke(Point point)
{
    if(drawing)
    {
        Point prev_point = points[arrlen(points) - 1];
        for(int i = 1; i <= num_interpolated_points; i++)
        {
            float t = i / (float)(num_interpolated_points + 1);
            Point interpolated_point = point_lerp(prev_point, point, t);
            arrput(points, interpolated_point);
        }

        arrput(points, point);
    }
}

void stop_stroke()
{
    if(drawing)
    {
        drawing = 0;
    }
}