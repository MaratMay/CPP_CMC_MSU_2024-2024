#include <iostream>
using namespace std;
class Parser
{
    char c;
    public:
        void analyze();
        void gc();
        void F();
};
void Parser::gc()
{
    std::cin.get(c);
}
void Parser::analyze()
{
    gc();
    try 
    {
        if (c == 'a') {cout << "2"; gc(); F(); cout << "a";}
        else if (c == 'b') {gc(); F(); cout << "b";}
        else throw c;
    }
    catch(char c) {cerr << "Error in: " << c << endl;}
}
void Parser::F()
{
    if (c == 'a') {cout << "2"; gc(); F(); cout << "a";}
    else if (c == 'b') {gc(); F(); cout << "b";}
    else if (c == '\n') return;
    else throw c;
}
int main()
{
    Parser x;
    x.analyze();
    cout << endl;
}