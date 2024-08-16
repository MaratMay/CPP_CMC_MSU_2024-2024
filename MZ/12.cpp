#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class Flower
{
	enum colors{WHITE=1, PINK=2};
	char type;
	public:
		Flower();
		Flower(string str, int n_petals);
		Flower(string str);
		Flower(Flower &op);
		~Flower();
		static void Print_flowers();
};

static int n_pink_flowers=0;
static int n_white_flowers=0;

Flower::Flower()
{
	if (n_pink_flowers > n_white_flowers) type = WHITE;
	else type = PINK; 
	if (type == PINK) n_pink_flowers++; else n_white_flowers++;
}

Flower::Flower(string str, int n_petals)
{
	if (str == "pink") type = PINK;
	else if (str == "white") type = WHITE;
	else if (n_pink_flowers > n_white_flowers) type = WHITE;
	else if (n_white_flowers > n_pink_flowers) type = PINK; 
	else if (n_petals % 2) type = WHITE;
	else type = PINK;
	if (type == PINK) n_pink_flowers++; else n_white_flowers++;
}

Flower::Flower(string str)
{
	if (str == "pink") type = PINK;
	else if (str == "white") type = WHITE;
	else if (n_pink_flowers > n_white_flowers) type = WHITE;
	else type = PINK; 
	if (type == PINK) n_pink_flowers++; else n_white_flowers++;
}

Flower::Flower(Flower &op)
{
	type = op.type;
	if (type == PINK) n_pink_flowers++; else n_white_flowers++;
}

Flower::~Flower()
{
	if (type == PINK) n_pink_flowers--; else n_white_flowers--;
}

void Flower::Print_flowers()
{
	cout << "White: " << n_white_flowers << " Pink: " << n_pink_flowers << endl;
}