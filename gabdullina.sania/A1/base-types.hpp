#ifndef A1_BASE_TYPES
#define A1_BASE_TYPES

struct point_t 
{
	double x;
	double y;
};

struct rectangle_t 
{
	double width;
	double height;
	point_t pos;
};

#endif