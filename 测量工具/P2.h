// P2.h: interface for the CP2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_P2_H__87AA394E_CA6B_4955_88BB_FCB10AFA09C6__INCLUDED_)
#define AFX_P2_H__87AA394E_CA6B_4955_88BB_FCB10AFA09C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CP2  
{
public:
	CP2();
	virtual ~CP2();
	CP2(double x, double y);
	friend CP2 operator +(const CP2 &p0, const CP2 &p1);//‘ÀÀ„∑˚÷ÿ‘ÿ
	friend CP2 operator -(const CP2 &p0, const CP2 &p1);
	friend CP2 operator -(double scalar, const CP2 &p);
	friend CP2 operator -(const CP2 &p, double scalar);
	friend CP2 operator *(const CP2 &p, double scalar);
	friend CP2 operator *(double scalar, const CP2 &p);
	friend CP2 operator /(const CP2 &p0, CP2 &p1);
	friend CP2 operator /(const CP2 &p, double scalar);
	friend CP2 operator+=(CP2 &p0, CP2 &p1);
	friend CP2 operator-=(CP2 &p0, CP2 &p1);
	friend CP2 operator*=(CP2 &p, double scalar);
	friend CP2 operator/=(CP2 &p, double scalar);
public:
	double x;
	double y;
};

#endif // !defined(AFX_P2_H__87AA394E_CA6B_4955_88BB_FCB10AFA09C6__INCLUDED_)
