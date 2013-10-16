#include <iostream>
using namespace std;

//class Point{
//public:
//	Point(float x = 0.0f):_x(x){}
//
//	float x(){ return _x; }
//	void x(float xval){ _x = xval;}
//private:
//	float _x;
//};
//
//class Point2D:public Point{
//public:
//	Point2D(float x = 0.0f, float y = 0.0f):Point(x), _y(y){}
//
//	float y(){ return _y; }
//	void y(float y){ _y = y; }
//private:
//	float _y;
//};
//
//class Point3D:public Point2D{
//public:
//	Point3D(float x = 0.0f, float y = 0.0f, float z = 0.0f):Point2D(x, y), _z(z){}
//
//	float z(){ return _z; }
//	void z(float zval){ _z = zval;}
//private:
//	float _z;
//};

template <class type, int dim>
class Point{
public:
	Point();
	Point(type coords[dim])
	{
		for (int index = 0; index < dim; ++index)
		{
			_coords[index] = coords[index];
		}
	}

	type& operator[](int index)const 
	{
		assert (index < dim && index >= 0);
		return _coords[index];
	}

private:
	type _coords[dim];
};

inline template <class type, int dim> ostream&  operator << (ostream& os, Point<type, dim>&pt)
{
	os << "( ";
	for (int ix = 0; ix < dim-1; ix++)
		os << pt[ix] << ", ";
	os << pt[dim -1];
	os << " )";
}