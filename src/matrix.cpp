#include "matrix.h"

/*****************************************************************************/
/*                        Rotation Matrix Methods                            */
/*****************************************************************************/
rotMat::rotMat()
{
    this->xyz    = new Point(0, 0, 0);
    this->theta  = 0;
}

rotMat::rotMat(float x, float y, float z, float t)
{
    this->xyz   = new Point(x, y, z);
    this->theta = t;
}

rotMat::rotMat(Point *p, float t)
{
    this->xyz = p;
    this->theta = t;
}

Point * rotMat::apply(Point * p)
{
    float r1  = this->xyz->X();
    float r2  = this->xyz->Y();
    float r3  = this->xyz->Z();
    float Cos = cos(this->theta);
    float Sin = sin(this->theta);

    float M11 = r1 * r1 + Cos * (1 - r1 * r1);
    float M21 = r2 * r1 - Cos * r2 * r1 + r3 * Sin;
    float M31 = r3 * r1 - Cos * r3 * r1 - r2 * Sin;

    float M12 = r1 * r2 - Cos * r1 * r2 - r3 * Sin;
    float M22 = r2 * r2 + Cos * (1 - r2 * r2);
    float M32 = r3 * r2 - Cos * r3 * r2 + r1 * Sin;

    float M13 = r1 * r3 - Cos * r1 * r3 + r2 * Sin;
    float M23 = r2 * r3 - Cos * r2 * r3 - r1 * Sin;
    float M33 = r3 * r3 + Cos * (1 - r3 * r3);

    float new_x, new_y, new_z;
    new_x = M11 * p->X() + M21 * p->Y() + M31 * p->Z();
    new_y = M12 * p->X() + M22 * p->Y() + M32 * p->Z();
    new_z = M13 * p->X() + M23 * p->Y() + M33 * p->Z();

    Point * result = new Point(new_x, new_y, new_z);

    return result;
}

Point * rotMat::unapply(Point * p)
{
    float r1  = this->xyz->X();
    float r2  = this->xyz->Y();
    float r3  = this->xyz->Z();
    float Cos = cos(-1.0 * this->theta);
    float Sin = sin(-1.0 * this->theta);

    float M11 = r1 * r1 + Cos * (1 - r1 * r1);
    float M21 = r2 * r1 - Cos * r2 * r1 + r3 * Sin;
    float M31 = r3 * r1 - Cos * r3 * r1 - r2 * Sin;

    float M12 = r1 * r2 - Cos * r1 * r2 - r3 * Sin;
    float M22 = r2 * r2 + Cos * (1 - r2 * r2);
    float M32 = r3 * r2 - Cos * r3 * r2 + r1 * Sin;

    float M13 = r1 * r3 - Cos * r1 * r3 + r2 * Sin;
    float M23 = r2 * r3 - Cos * r2 * r3 - r1 * Sin;
    float M33 = r3 * r3 + Cos * (1 - r3 * r3);

    float new_x, new_y, new_z;
    new_x = M11 * p->X() + M21 * p->Y() + M31 * p->Z();
    new_y = M12 * p->X() + M22 * p->Y() + M32 * p->Z();
    new_z = M13 * p->X() + M23 * p->Y() + M33 * p->Z();

    Point * result = new Point(new_x, new_y, new_z);

    return result;
}

/*****************************************************************************/
/*                         Scaling Matrix Methods                            */
/*****************************************************************************/
scaMat::scaMat()
{
    this->xyz = new Point(1, 1, 1);
}

scaMat::scaMat(float x, float y, float z)
{
    this->xyz = new Point(x, y, z);
}

scaMat::scaMat(Point * p)
{
    this->xyz = p;
}
Point * scaMat::apply(Point * p)
{
    float new_x = p->X() * this->xyz->X();
    float new_y = p->Y() * this->xyz->Y();
    float new_z = p->Z() * this->xyz->Z();
    return new Point(new_x, new_y, new_z);;
}

Point * scaMat::unapply(Point * p)
{
    float new_x = p->X() / this->xyz->X();
    float new_y = p->Y() / this->xyz->Y();
    float new_z = p->Z() / this->xyz->Z();
    return new Point(new_x, new_y, new_z);;
}

/*****************************************************************************/
/*                        Translating Matrix Methods                         */
/*****************************************************************************/
traMat::traMat()
{
    this->xyz = new Point(0, 0, 0);
}

traMat::traMat(float x, float y, float z)
{
    this->xyz = new Point(x, y, z);
}

traMat::traMat(Point * p)
{
    this->xyz = p;
}
Point * traMat::apply(Point * p)
{
    float new_x = p->X() + this->xyz->X();
    float new_y = p->Y() + this->xyz->Y();
    float new_z = p->Z() + this->xyz->Z();
    return new Point(new_x, new_y, new_z);;
}

Point * traMat::unapply(Point * p)
{
    float new_x = p->X() - this->xyz->X();
    float new_y = p->Y() - this->xyz->Y();
    float new_z = p->Z() - this->xyz->Z();
    return new Point(new_x, new_y, new_z);;
}