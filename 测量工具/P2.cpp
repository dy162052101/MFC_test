// P2.cpp: implementation of the CP2 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Test.h"
#include "P2.h"
#include <math.h>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CP2::CP2()
{

}

CP2::~CP2()
{

}

CP2::CP2(double x, double y)
{
	this->x = x;
	this->y = y;
}

CP2 operator +(const CP2 &p0, const CP2 &p1)//和
{
	CP2 result;
	result.x = p0.x + p1.x;
	result.y = p0.y + p1.y;
	return result;
}

CP2 operator -(const CP2 &p0, const CP2 &p1)//差
{
	CP2 result;
	result.x = p0.x - p1.x;
	result.y = p0.y - p1.y;
	return result;
}
CP2 operator -(double scalar, const CP2 &p)//常量和点的差
{
	CP2 result;
	result.x = scalar - p.x;
	result.y = scalar - p.y;
	return result;
}
CP2 operator -(const CP2 &p, double scalar)//点和常量的差
{
	CP2 result;
	result.x = p.x - scalar;
	result.y = p.y - scalar;
	return result;
}

CP2 operator *(const CP2 &p, double scalar)//对象和常量的积
{
	return CP2(p.x * scalar, p.y * scalar);
}

CP2 operator *(double scalar, const CP2 &p)//常量和对象的积
{	
	return CP2(p.x * scalar, p.y * scalar);
}

CP2 operator /(const CP2 &p0, CP2 &p1)//对象的商
{
	if(fabs(p1.x)<1e-6)
		p1.x = 1.0;
	if(fabs(p1.y)<1e-6)
		p1.y = 1.0;
	CP2 result;
	result.x = p0.x / p1.x;
	result.y = p0.y / p1.y;
	return result;
}

CP2 operator /(const CP2 &p, double scalar)//数除
{
	if(fabs(scalar)<1e-6)
		scalar = 1.0;
	CP2 result;
	result.x = p.x / scalar;
	result.y = p.y / scalar;
	return result;
}

CP2 operator+=(CP2 &p0, CP2 &p1)
{
	p0.x += p1.x;
	p0.y += p1.y;
	return p0;
}

CP2 operator-=(CP2 &p0, CP2 &p1)
{
	p0.x -= p1.x;
	p0.y -= p1.y;
	return p0;
}

CP2 operator*=(CP2 &p, double scalar)
{
	p.x *= scalar;
	p.y *= scalar;
	return p;
}

CP2 operator/=(CP2 &p, double scalar)
{
	if(fabs(scalar)<1e-6)
		scalar = 1.0;
	p.x /= scalar;
	p.y /= scalar;
	return p;
}