#include <iostream>
class Shape
{
	public:
		virtual void move(int dx, int dy, int dz) = 0;
		virtual double volume() = 0;
		virtual void print() = 0;
};

class Ppd : public Shape
{
	int x1, y1, z1, x2, y2, z2;
	public:
		virtual void move(int dx, int dy, int dz);
		virtual double volume();
		virtual void print();
};

class Ball : public Shape
{
	int x, y, z, r;
	public:
		virtual void move(int dx, int dy, int dz);
		virtual double volume();
		virtual void print();
};

void Ppd::move(int dx, int dy, int dz)
{
	x1 += dx; x2 += dx;
	y1 += dy; y2 += dy;
	z1 += dz; z2 += dz;
}

double Ppd::volume()
{
	return abs((x1 - x2) * (y1 - y2) * (z1 - z2));
}

void Ppd::print()
{
	std::cout << "(" << x1 << ", " << y1 << ", " << z1 << ") (" << x2 << ", " << y2 << ", " << z2 << ")" << std::endl;
}

void Ball::move(int dx, int dy, int dz)
{
	x += dx;
	y += dy;
	z += dz;
}

double Ball::volume()
{
	return (4./3) * 3.14 * r * r * r;
}

void Ball::print()
{
	std::cout << "(" << x << ", " << y << ", " << z << ") r = " << r << std::endl;
}

void move_scene(Shape *array_of_shapes[], int num_of_shapes, int delta_x, int delta_y, int delta_z)
{
	for(int i=0; i < num_of_shapes; i++) array_of_shapes[i] -> move(delta_x, delta_y, delta_z);
}