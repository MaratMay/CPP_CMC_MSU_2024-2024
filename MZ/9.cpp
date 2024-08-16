#include<iostream>
#include<cstring>
using namespace std;
class Vector_2d
{
	private:
		unsigned int x, y;
	public:
		Vector_2d(int x_=0, int y_=0) : x(x_), y(y_) {}
		friend ostream& operator<<(ostream& os, const Vector_2d& op);
	    friend istream& operator>>(istream& is, Vector_2d& op);
};

class error 
{
	public:
		void print() const {std::cout << "Exception: one coordinate" << std::endl;}
};
class error_negative : error
{
	int x;
	public:
		error_negative(int x_) : x(x_) {}
		void print() {std::cout << "Exception: negative coordinate:" << x << std::endl;}
};

ostream& operator<<(ostream& os, const Vector_2d& op)
{
    os << "(" << op.x << "," << op.y << ")";
    return os;
}

istream& operator>>(istream& is, Vector_2d& op)
{
	int x, y;
	char result = scanf("%d %d", &x, &y);
	if (result == 2) {
		if (x < 0) throw(error_negative(x));
		if (y < 0) throw(error_negative(y));
		op.x = x;
		op.y = y;
	} else if (result == 1) throw(error());
	return is;
}

int main()
{
	try {
		Vector_2d v;
		cin >> v;
		cout << v << endl;
	}
	catch(error_negative &e) {e.print();}
	catch(error &e) {e.print();}
	catch(...) {std::cout << "Unknown_Error\n";} 
	return 0;
}