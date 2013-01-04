//Administrator Created
#ifndef _16112012_SkeletonDef
#define _16112012_SkeletonDef

#include "Tools/tinyxml.h"
#include <vector>
#include <map>
#include <string>


template<class TV>
struct RVector 
{
	typedef std::vector<TV> T;
};

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > RString;

struct Skel_Matrix2D
{
	union{
		float a;
		float _11;
	};
	union{
		float b;
		float _21;
	};
	union{
		float c;
		float _12;
	};
	union{
		float d;
		float _22;
	};
	union{
		float tx;
		float _13;
	};
	union{
		float ty;
		float _23;
	};
	Skel_Matrix2D(void){}
	Skel_Matrix2D(float a_,float b_,float c_,float d_,float tx_,float ty_)
		:a(a_),b(b_),c(c_),d(d_),tx(tx_),ty(ty_){

	}
	void concat(const Skel_Matrix2D& t2){
		Skel_Matrix2D ret;
		ret._11 = _11*t2._11+_21*t2._12;
		ret._21 = _11*t2._21+_21*t2._22;

		ret._12 = _12*t2._11+_22*t2._12;
		ret._22 = _12*t2._21+_22*t2._22;

		ret._13 = _13*t2._11+_23*t2._12+t2._13;
		ret._23 = _13*t2._21+_23*t2._22+t2._23;
		*this=ret;
		return;

		Skel_Matrix2D t1=*this;
		a=t1.a * t2.a + t1.b * t2.c;
		b=t1.a * t2.b + t1.b * t2.d; //a,b
		c=t1.c * t2.a + t1.d * t2.c;
		d=t1.c * t2.b + t1.d * t2.d; //c,d
		tx=t1.tx * t2.a + t1.ty * t2.c + t2.tx;                  //tx
		ty=t1.tx * t2.b + t1.ty * t2.d + t2.ty;   
		*this=t1;
	}
	void Rotate(float rad)
	{
		float fc = cos(rad);
		if(fc*fc<1e-6) fc = 0;
		float fs = sin(rad);
		if(fs*fs<1e-6) fs = 0;
		_11 = fc;
		_12 = -fs;
		_21 = fs;
		_22 = fc;
	}

	//���� //����֤
	void invert(void){
		Skel_Matrix2D out;
		out._11 = _11;
		out._12 = _21;

		out._21 = _12;
		out._22 = _22;

		out._13 =( -_13*out._11)+(-_23*out._12);
		out._23 = (-_13*out._21)+(-_23*out._22);
		*this=out;
		return;
		float determinant = 1 / (a*d - b*c);
		*this = Skel_Matrix2D(determinant * d, -determinant * b, -determinant * c, determinant * a,
			determinant * (c * ty - d * tx), determinant * (b * tx - a * ty) );
	}
	void deltaTransformPoint(float& x,float& y){
		float px = (float)((double)this->a * x + (double)this->c * y);
		float py = (float)((double)this->b * x + (double)this->d * y);
		x=px;
		y=py;
	}
	void transform(float& x,float& y)
	{
		float px = (float)((double)this->a * x + (double)this->c * y + this->tx);
		float py = (float)((double)this->b * x + (double)this->d * y + this->ty);
		x=px;
		y=py;
	}
};

#define _Skeleton2D_Debug_
#define _Skeleton2D_Sin_ sinf
#define _Skeleton2D_Cos_ cosf
#define _Skeleton2D_Atan2_ atan2f
#define _Skeleton2D_Sqrt_ sqrtf

#ifndef M_PI
#define M_PI       3.14159265358979323846
#endif
#define HALF_PI (M_PI * 0.5f)
#define _Skeleton2D_IsNAN(a) (a==FLT_MAX)

//!������ȡ��
inline float FLoatMod(float v,float modBase,int valueMax){
	int vInt=v*valueMax;
	int vBase=modBase*valueMax;
	int vMod=vInt%vBase;
	return (float)vMod/(float)valueMax;
}

#define _Skeleton2D_Assert_

#endif
