#include <iostream>
#include <cstdio>
#define NOT_ON_BOARD (letter_1 > 'h' || letter_1 < 'a' || num_1 > 8 || num_1 < 1 || letter_2 > 'h' || letter_2 < 'a' || num_2 > 8 || num_2 < 1)
using namespace std;

class Figure
{
	public:
		virtual bool move(char letter_1, int num_1, char letter_2, int num_2) = 0;
};

class King : public Figure //король
{
	public:
		virtual bool move(char letter_1, int num_1, char letter_2, int num_2);
};

class Queen : public Figure //королева
{
	public:
		virtual bool move(char letter_1, int num_1, char letter_2, int num_2);
};

class Rook : public Figure //ладья 
{
	public:
		virtual bool move(char letter_1, int num_1, char letter_2, int num_2);
};

class Knight : public Figure //конь
{
 public:
		virtual bool move(char letter_1, int num_1, char letter_2, int num_2);
};

class Bishop : public Figure //лось
{
 public:
		virtual bool move(char letter_1, int num_1, char letter_2, int num_2);
};

class ChessChecker
{
	char figure_name;
	char letter_1, letter_2;
	int num_1, num_2;
    enum {K, Q, R, B, N};
	Figure *variants[5];

	public:
		ChessChecker();
		bool Give_answer() const;
};

ChessChecker::ChessChecker() {
	cin >> figure_name >> letter_1 >> num_1 >> letter_2 >> num_2;
    variants[K] = new King;
    variants[Q] = new Queen;
    variants[R] = new Rook;
    variants[N] = new Knight;
    variants[B] = new Bishop;
}

bool ChessChecker::Give_answer() const 
{
	if NOT_ON_BOARD return false;
	switch(figure_name) {
		case 'K': return variants[K] -> move(letter_1, num_1, letter_2, num_2);
		case 'Q': return variants[Q] -> move(letter_1, num_1, letter_2, num_2);
		case 'R': return variants[R] -> move(letter_1, num_1, letter_2, num_2);
		case 'N': return variants[N] -> move(letter_1, num_1, letter_2, num_2);
		case 'B': return variants[B] -> move(letter_1, num_1, letter_2, num_2);
	}
	return false;
}

bool King::move(char letter_1, int num_1, char letter_2, int num_2)
{
	int hor = abs(letter_1 - letter_2), ver = abs(num_1 - num_2);
	if (hor == 1 && ver == 0 || ver == 1 && hor == 0 || ver == 1 && hor == 1) return true; return false;
}

bool Queen::move(char letter_1, int num_1, char letter_2, int num_2)
{
	int hor = abs(letter_1 - letter_2), ver = abs(num_1 - num_2);
	if (hor == 0 || ver == 0 || ver == hor) return true; return false;
}

bool Rook::move(char letter_1, int num_1, char letter_2, int num_2)
{
	if (abs(letter_1 - letter_2) == 0 || abs(num_1 - num_2) == 0) return true; return false;
}

bool Knight::move(char letter_1, int num_1, char letter_2, int num_2)
{
	int hor = abs(letter_1 - letter_2), ver = abs(num_1 - num_2);
	if (ver == 2 && hor == 1 || hor == 2 && ver == 1) return true; return false;
}

bool Bishop::move(char letter_1, int num_1, char letter_2, int num_2)
{
	if (abs(letter_1 - letter_2) == abs(num_1 - num_2)) return true; return false;
}

int main() 
{
	ChessChecker x;
	cout << (x.Give_answer() > 0 ? "YES" : "NO") << endl;
	return 0;
}