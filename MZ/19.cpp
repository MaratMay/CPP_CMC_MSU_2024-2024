#include <iostream>
class Parser
{
    char c;
    int skobochki;
    void gc();
    void A();
    void B();
    void C();
    void D();
    void E();
    void S();
    public:
		void analyze();
};
void Parser::gc() 
{
	c = std::cin.get();
}
void Parser::C()
{
    D();
    B();
}
void Parser::A()
{
    if (c == '+') {
        gc();
        C();  
        std::cout << '+';
        A();
    }
    else if (c != ')' && c != '\n' || (c == ')' && skobochki <= 0)) throw c;    
}
void Parser::B()
{
    if (c == '*') {
        gc();
        D();
        std::cout << '*';
        B();
    } else if (c != '+' && c != ')' && c != '\n' || (c == ')' && skobochki <= 0)) throw c;
}
void Parser::D()
{
    if (c == '(') {
    	skobochki++;
        gc();
        S();
        if (c == ')' && skobochki > 0) {gc(); skobochki--;}
        else throw c;
    }
    else if (isdigit(c) || 'a' <= c && c <= 'z') E();
    else throw c;
}
void Parser::E()
{
    if (isdigit(c) || 'a' <= c && c <= 'z') {
        std::cout << c;
        gc();
    }
    else if (c != '\n') throw c;
}
void Parser::S()
{
    C();
    A();
}
void Parser::analyze()
{
	skobochki=0;
	gc();
	if (c == '\n') std::cout << std::endl;
	else S();
}

int main()
{
	Parser x;
    try{
        x.analyze();
    }
    catch(char &c) {std::cerr << "Error in: " << c;}  
    return 0;
}