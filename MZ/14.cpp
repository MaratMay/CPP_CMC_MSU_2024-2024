#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
int Parser()
{
	enum {Start, Finish, dot_1, dot_2, dot_3, dot_4, dash_1, dash_2, dash_3, dash_4, \
			dot_2a, dot_3a, dot_4a, dash_2a, dash_3a, dash_4a};
	char cur_num, c, cur_pos = Start;
	int ans = 0;
	c = cin.get();
	do{
		switch(cur_pos)
		{
			case Start: 
				if ((c == '.') || (c == '-'))
				{
					cur_num = (c == '.') ? 1 : 6;
					cur_pos = (c == '.') ? dot_1 : dash_1;
					c = cin.get();
				}
				else throw c;
				break;
			case dot_1:
				if ((c == '.') || (c == '-'))
				{
					if (c == '.') {cur_num += 1; cur_pos = dot_2;}
					else cur_pos = dot_2a;
					c = cin.get();
				}
				else throw c;
				break;
			case dash_1:
				if ((c == '.') || (c == '-'))
				{
					if (c == '-') {cur_num += 1; cur_pos = dash_2;}
					else cur_pos = dash_2a;
					c = cin.get();
				}
				else throw c;
				break;
			case dot_2:
				if ((c == '.') || (c == '-'))
				{
					if (c == '.') {cur_num += 1; cur_pos = dot_3;}
					else cur_pos = dot_3a;
					c = cin.get();
				}
				else throw c;
				break;
			case dash_2:
				if ((c == '.') || (c == '-'))
				{
					if (c == '-') {cur_num += 1; cur_pos = dash_3;}
					else cur_pos = dash_3a;
					c = cin.get();
				}
				else throw c;
				break;
			case dot_3:
				if ((c == '.') || (c == '-'))
				{
					if (c == '.') {cur_num += 1; cur_pos = dot_4;}
					else cur_pos = dot_4a;
					c = cin.get();
				}
				else throw c;
				break;
			case dash_3:
				if ((c == '.') || (c == '-'))
				{
					if (c == '-') {cur_num += 1; cur_pos = dash_4;}
					else cur_pos = dash_4a;
					c = cin.get();
				}
				else throw c;
				break;
			case dot_4:
				if ((c == '.') || (c == '-'))
				{
					if (c == '.') cur_num += 1;
					cur_pos = Finish;
					c = cin.get();
				}
				else throw c;
				break;
			case dash_4:
				if ((c == '.') || (c == '-'))
				{
					if (c == '-') cur_num += 1;
					cur_pos = Finish;
					c = cin.get();
				}
				else throw c;
				break;
			case Finish:
				if ((c == '\n') || (c == ' '))
				{
					if (cur_num == 10) cur_num = 0;
					ans = ans * 10 + cur_num;
					if (c == '\n') return ans;
					cur_pos = Start;
					c = cin.get();
				}
				else throw c;
				break;
			case dot_2a:
				if (c == '-') {cur_pos = dot_3a; c = cin.get();}
				else throw c;
				break;
			case dash_2a:
				if (c == '.') {cur_pos = dash_3a; c = cin.get();}
				else throw c;
				break;
			case dot_3a:
				if (c == '-') {cur_pos = dot_4a; c = cin.get();}
				else throw c;
				break;
			case dash_3a:
				if (c == '.') {cur_pos = dash_4a; c = cin.get();}
				else throw c;
				break;
			case dot_4a:
				if (c == '-') {cur_pos = Finish; c = cin.get();}
				else throw c;
				break;
			case dash_4a:
				if (c == '.') {cur_pos = Finish; c = cin.get();}
				else throw c;
				break;
		}
	} while(true);
}


int main()
{
	try {
		cout << Parser() << endl;
	}
	catch(char c)
	{
		cerr << "Error in Lexeme: " << c << endl;
	}
	return 0;
}