#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
char *left(char *str, int N){
    if (N <= 0) return nullptr;
    if (strlen(str) > (long unsigned) N) str[N] = 0;
    return str;
}

unsigned long left(unsigned long num, int N){
    if (N <= 0) return 0;
    unsigned long num1 = num;
    int digits = 0;
    while (num1 > 0) {digits++; num1 /= 10;}
    if (digits <= N) return num;
    return num / pow(10, (digits - N));
}

int main(){
    const char len_first = 8;
    const char len_next = 101;
    char command[len_first];
    cin.getline(command, len_first);
    if (!strcmp(command, "string")){
        char str[len_next];
        int n;
        cin.getline(str, len_next);
        cin >> n;
        char *ptr = left(str, n);
        cout << ptr;
    }
    else if (!strcmp(command, "number")){
        long unsigned int num;
        int n;
        cin >> num;
        cin >> n;
        cout << left(num,n);
    }
    return 0;
}