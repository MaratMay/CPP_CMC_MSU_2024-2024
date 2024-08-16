#include <iostream>
#include <cstring>
template <typename T>
T summa(T* array, int n)
{
    T sum = 0;
    for(int i=0; i < n; i++) sum += array[i];
    return sum;
}

char* summa(char** str, int n)
{
    int size=8, count=1;
    char* sum = new char(size);
    sum[0] = 0;
    for(int i=0; i < n; i++) {
        if (size <= strlen(str[i]) + count) {
            size *= 2;
            char* tmp = new char(size);
            strcpy(tmp, sum);
            delete [] sum;
            sum = tmp;
        }
        strcat(sum, str[i]);
    }
    return sum;
}