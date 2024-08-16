#include <iostream>
class PositiveIntegerSet
{
    unsigned int *array;
    long int count=0;
    long int size=8;
    enum errors{ADD_ERR, ERASE_ERR};
    public:
        PositiveIntegerSet() {array = new unsigned int (size);}
        void add(int x);
        void erase(int x);
        bool there_is(unsigned int x) const;
        void print();
        ~PositiveIntegerSet() {delete [] array;}
};

class Exception
{
    int exc;
    enum errors{ADD_ERR, ERASE_ERR};
    public:
        Exception(int a) : exc(a) {}
        void what() const;
};

bool PositiveIntegerSet::there_is(unsigned int x) const
{
    for(int i=0; i < count; i++) if (array[i] == x) return true;
    return false;
}

void PositiveIntegerSet::add(int x)
{
    if (x < 0) throw Exception(ADD_ERR);
    if (there_is(x)) return;
    if (count == size) {
        size *= 2;
        unsigned int *tmp = new unsigned int (size);
        for(int i=0; i < count; i++) tmp[i] = array[i];
        delete [] array;
        array = tmp;
    }
    array[count++] = x;
}

void PositiveIntegerSet::erase(int x)
{
    if (x < 0) throw Exception(ERASE_ERR);
    if (!there_is(x)) throw Exception(ERASE_ERR);
    unsigned int *tmp = new unsigned int (size);
    for(int i=0; i < count; i++) if (array[i] != x) tmp[i] = array[i];
    delete [] array;
    array = tmp;
    count--;
}

void PositiveIntegerSet::print()
{
    if (!count) {std::cout << "Empty" << std::endl; return;}
    unsigned int tmp;
    for(int i=0; i < count - 1; i++) {
        for(int j=0; j < count - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
    for(int i=0; i < count; i++) std::cout << array[i] << " ";
    std::cout << std::endl;
}

void Exception::what() const
{
    std::cout << ((exc == ADD_ERR) ? "Wrong add\n" : "Wrong delete\n"); //тута нужно выводить в cerr
}

int main()
{
    try {
        PositiveIntegerSet set;
        set.add(5);
        set.add(100);
        set.add(0);
        set.print();
    }
    catch(Exception &e) {e.what();}
    try {
        PositiveIntegerSet set;
        set.add(-1);
    }
    catch(Exception &e) {e.what();}
    try {
        PositiveIntegerSet set;
        set.add(5);
        set.erase(1);
    }
    catch(Exception &e) {e.what();}
}