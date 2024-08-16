#include <iostream>
std::string Parser()
{
    enum {Start, D, B, S};
    char cur_num, c, cur_pos = Start;;
    std::string ans;
    scanf("%c", &c);
    do {
        switch(cur_pos) {
            case Start:
                if (c == 'a') {cur_pos = D; ans += c; std::cin.get(c);}
                else throw c;
                break;
            case D:
                if (c == 'a') {cur_pos = B; ans += c; std::cin.get(c);}
                else if (c == 'd') {ans += c; std::cin.get(c);}
                else throw c;
                break;
            case B:
                if (c == 'a') {cur_pos = D; ans += c; std::cin.get(c);}
                else if (c == '\n') {ans += c; return ans;}
                else throw c;
                break;
        }
    }
    while(true);
}

int main()
{
    try {
        std::cout << Parser();
        return 0;
    }
    catch(char error_c) {std::cerr << "Error in Lexcem: " << error_c;}
}