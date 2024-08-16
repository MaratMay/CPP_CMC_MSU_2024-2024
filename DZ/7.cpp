#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::cerr;
class Player
{
	enum commands{ZENIT, CSKA};
	char my_command;
	int my_number;
	static int n_zenit_players;
	static int n_cska_players;
	static int zenit_numbers[11];
	static int cska_numbers[11];
	public:
		Player(string command, int number);
		~Player();
		void Print() const;
		static void Print_teams();
};

class Exc {
    string error;
    string command;
    int number; 
    public:
    	Exc();
	    Exc(string error_, string command_, int number_) : error(error_), command(command_), number(number_) {}
	    void print() const;
};

int Player::n_zenit_players=0;
int Player::n_cska_players=0;
int Player::zenit_numbers[11]={0};
int Player::cska_numbers[11]={0};

Player::Player(string command, int number)
{
	if (command == "Zenit") my_command = ZENIT;
	else if (command == "CSKA") my_command = CSKA;
	else throw(Exc("Wrong name", command, -1));
	if (n_cska_players >= 11 && my_command == CSKA || n_zenit_players >= 11 && my_command == ZENIT) throw(Exc("Too many players", command, -1));

	if (number < 1) throw(Exc("Wrong number", command, number));
	char nul_i;
	my_number = number;
	if (my_command == ZENIT) {
		for(int i=0; i < 11; i++) {
			if (zenit_numbers[i] == number) throw(Exc("Double number", command, number));
			if (zenit_numbers[i] == 0) nul_i = i;
		}
		n_zenit_players++;
		zenit_numbers[nul_i] = number;
	} else {
		for(int i=0; i < 11; i++) {
			if (cska_numbers[i] == number) throw(Exc("Double number", command, number));
			if (cska_numbers[i] == 0) nul_i = i;
		}
		n_cska_players++;
		cska_numbers[nul_i] = number;
	}
}

Player::~Player()
{
	if (my_command == ZENIT) {
		n_zenit_players--;
		for(int i=0; i < 11; i++) if (zenit_numbers[i] == my_number) zenit_numbers[i] = 0;
	} else {
		n_cska_players--;
		for(int i=0; i < 11; i++) if (cska_numbers[i] == my_number) cska_numbers[i] = 0;
	}
}

void Player::Print() const
{
	cout << ((my_command == ZENIT) ? "Zenit " : "CSKA ") << my_number << endl;
}

void Player::Print_teams()
{
	if (n_zenit_players) {
		cout << "Zenit:";
		for(int i=10; i >= 0; i--) {
			if (zenit_numbers[i]) cout << " " << zenit_numbers[i];
		}
		cout << endl;
	}
	if (n_cska_players) {
		cout << "CSKA:";
		for(int i=10; i >= 0; i--) {
			if (cska_numbers[i]) cout << " " << cska_numbers[i];
		}
		cout << endl;
	}
}

void Exc::print() const 
{
	cerr << "Exception: " << error << " in team " << command;
	if (number != -1) {
		cerr << " Error number: " << number;
	}
	cerr << endl;
}

Exc::Exc()
{
	error = "Why would I even write this?";
	command = "Nevertheless, it must be necessary."; 
	number = -1;
}

int main (){
    try{
        test_players();
    }
    catch(Exc &e) {e.print();}
    catch (...) {
        Exc e;
        e.print();
    }
    return 0;
}