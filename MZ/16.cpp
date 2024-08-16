#include <iostream>
class Parser
{
    char c;
    public:
        bool analyze();
        void gc();
        void B();
        void A();
};
void Parser::gc()
{
    std::cin.get(c);
}

bool Parser::analyze()
{
    gc();
    try 
    {
        if (c == 'a') {gc(); A(); B(); if (c == '\n') gc(); else throw c;}
        else if (c == 'b') {gc(); B(); if (c == '\n') gc(); else throw c;}
        else throw c;
        return true;
    }
    catch(char c) {return false;}
}
void Parser::A()
{
    if (c == 'a') {gc(); A();}
    else if (c == 'b') {gc();}
    else throw c;
}
void Parser::B()
{
    if (c == 'b') {gc(); B();}
}
int main()
{
    Parser x;
    std::cout << (x.analyze() ? "YES" : "NO") << std::endl;
}