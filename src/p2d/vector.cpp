#include "../../include/p2d/vector.h"
#include "../../include/extra/fuzzy_equal.h"
#define _USE_MATH_DEFINES
#include <math.h>

double p2d::modulo(const p2d::Vector & v)
{
	return sqrt(v.x() * v.x() + v.y() * v.y());
}

p2d::Vector p2d::basis() 
{
	return p2d::Vector(M_SQRT1_2, M_SQRT1_2);
}

p2d::Vector p2d::unit(const p2d::Vector & v)
{
	double modulo = p2d::modulo(v);
	if (non_fuzzy_zero(modulo)) 
		return v / modulo;
	else
		return p2d::basis();
}

p2d::Vector p2d::ortho(const p2d::Vector & v, OrthoVectorIndex i)
{
	p2d::Vector unit = p2d::unit(v);
	if (i == p2d::OVI_DEG_90) 
	{
		return p2d::Vector(v.y(), v.x());
	}
	return p2d::Vector(-1 * v.y(), v.x());
}

double p2d::scalar(const p2d::Vector & v1, const p2d::Vector &  v2)
{
	return v1.x() * v2.x() + v1.y() * v2.y();
}

