// the c type of Point3D_Print
#include <iostream>
using namespace std;

#define Point3D_Print(pd) printf("%g, %g, %g", pd->x, pd->y, pd->z) 
#define Set_X(p, xval) (p.x) = xval
#define Set_Y(p, yval) (p.y) = yval
#define Set_Z(p, zval) (p.z) = zval

typedef struct point3d{
	float x;
	float y;
	float z;
}Point3D;

int main(int argc, const char **argv)
{
	Point3D mypoint;
	Set_X(mypoint, 1.0f);
	Set_Y(mypoint, 2.0f);
	Set_Z(mypoint, 3.0f);

	Point3D *pPoint3D = &mypoint;
	Point3D_Print(pPoint3D);

	/*Point3D *pPoint3D = new Point3D;
	pPoint3D->x = 1.0f;
	pPoint3D->y = 2.0f;
	pPoint3D->z = 3.0f;

	Point3D_Print(pPoint3D);

	delete []pPoint3D;*/
	return 0;
}