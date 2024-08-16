#include <iostream>
class Event
{
	int st_min, end_min, st_hour, end_hour;
	public:
		Event(int a, int b, int c, int d) : st_hour(a), st_min(b), end_hour(c), end_min(d) {}
		Event& operator++();
		Event operator++(int);
		Event& operator--();
		Event operator--(int);
		friend std::ostream& operator<<(std::ostream& out, Event op);
};

Event& Event::operator++()
{
	st_hour = (st_hour + 1) % 24;
	end_hour = (end_hour + 1) % 24;
	return *this;
}

Event Event::operator++(int)
{
	Event tmp(st_hour, st_min, end_hour, end_min);
	++*this;
	return tmp;
}

Event& Event::operator--()
{
	if (st_min == 0) {
		st_min = 59;
		st_hour = (st_hour == 0) ? 23 : --st_hour;
	} else st_min--;
	if (end_min == 0) {
		end_min = 59;
		end_hour = (end_hour == 0) ? 23 : --end_hour;
	} else end_min--;
	return *this;
}

Event Event::operator--(int)
{
	Event tmp(st_hour, st_min, end_hour, end_min);
	--*this;
	return tmp;
}

std::ostream& operator<<(std::ostream& out, Event op)
{
	out << "begin:";
	if (op.st_hour < 10) out << "0";
	out << op.st_hour << "h:";
	if (op.st_min < 10) out << "0";
	out << op.st_min << "m end:";
	if (op.end_hour < 10) out << "0";
	out << op.end_hour << "h:";
	if (op.end_min < 10) out << "0";
	out << op.end_min << "m";
	return out;
}

int main()
{
	Event ev(9, 15, 17, 0);
	std::cout << ev << std::endl;
	std::cout << ev++ << std::endl;
	std::cout << ev << std::endl;
	std::cout << --ev << std::endl;
	Event ev2(0, 0, 0, 0);
	std::cout << --ev2 << std::endl;
	std::cout << ++ev2 << std::endl;
}