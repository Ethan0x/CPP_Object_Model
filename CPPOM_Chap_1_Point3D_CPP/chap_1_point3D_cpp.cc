#include <iostream>
using namespace std;

//class Point{
//public:
//	Point(float x = 0.0f):_x(x){}
//
//	float x(){ return _x; }const
//	void x(float xval){ _x = xval;}
//private:
//	float _x;
//};
//
//class Point2D:public Point{
//public:
//	Point2D(float x = 0.0f, float y = 0.0f):Point(x), _y(y){}
//
//	float y(){ return _y; }const
//	void y(float y){ _y = y; }
//private:
//	float _y;
//};
//
//class Point3D:public Point2D{
//public:
//	Point3D(float x = 0.0f, float y = 0.0f, float z = 0.0f):Point2D(x, y), _z(z){}
//
//	float z(){ return _z; }const
//	void z(float zval){ _z = zval;}
//private:
//	float _z;
//};


class Point3D{
public:
	Point3D(float x = 0.0f, float y = 0.0f, float z = 0.0f):_x(x), _y(y), _z(z){}
	float x()const { return _x; }
	float y()const { return _y; }
	float z()const { return _z; } 

	void x(float xval) { _x = xval; }
	void y(float yval) { _y = yval; }
	void z(float zval) { _z = zval; }
private:
	float _x;
	float _y;
	float _z;

};

inline ostream& operator<<(ostream &os, const Point3D &pt)
{
	os << "(" << pt.x() << ", " << pt.y() << ", " << pt.z() << ")" ;
	return os;
}

int main(int argc, const char **argv)
{
	Point3D pt;

	cout << pt << endl;

	return 0;
}