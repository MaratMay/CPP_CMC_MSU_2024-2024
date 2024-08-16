#include <cstring>
#include <iostream>
template <typename T>
T maxn(T array[], int size) 
{
	int ans = 0, i = 0;
	for (; i < size; i++) if (array[ans] < array[i]) ans = i;
	return array[ans];
}

template<>
const char* maxn<const char*>(const char* array[], int size)
{
	int ans = 0, i = 0;
	for (; i < size; i++) if (strlen(array[ans]) < strlen(array[i])) ans = i;
	return array[ans];
}

int main()
{
    using namespace std;
    int arri[6] = {1, 2, 5, 3, 1, -1};
    double arrd[4] = {2.3, -1.3, 8.7, 4.5};
    const char * arrc[5] = {"first", "second", "third", "long string", "another string"};

    cout << "max of integer = " << maxn(arri, 6) << endl;
    cout << "max of double = " << maxn(arrd, 4) << endl;
    cout << "max string is " << maxn(arrc, 5) << endl;

    return 0;
}