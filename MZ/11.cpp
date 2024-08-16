#include <iostream>
#include <cmath>
using namespace std;
template <typename T>
class Vec{
    T *v;
    int len;
    enum err{LENGTH_ERR, GET_ERR, SET_ERR, ADD_ERR, INDEX_ERR, MULT_ERR};
	public:
	    explicit Vec(int len_inp, T *arr=nullptr);
	    Vec(const Vec<T> &a);
	    ~Vec();
	    void set(T arg, int coord);
	    T get(int coord) const;
	    T max_norm() const;
	    void print() const;
	    const Vec<T>& operator=(const Vec<T>& op);
	    Vec<T> operator+(const Vec<T> & op) const;
        Vec<T> operator-(const Vec<T> & op) const;
        Vec<T> operator*(double a) const;
        Vec<T>& operator+=(const Vec<T> & op);
        T& operator[](int index) const;
        T operator^(const Vec<T> & op) const;
        template<typename V>
        friend Vec<V> operator*(double a, const Vec<V> & op);
        template<typename V>
		friend bool operator==(const Vec<V>& op1, const Vec<V>& op2);
		template<typename V>
		friend ostream& operator<<(ostream& os, const Vec<V>& op);
};

class test{
    int type, x, y;
    enum err{LENGTH_ERR, GET_ERR, SET_ERR, ADD_ERR, INDEX_ERR, MULT_ERR};
    public:
	    test(int type_ = 0, int x_ = 0, int y_ = 0) : type(type_), x(x_), y(y_) {};
	    void print() const;
};

void test::print() const 
{
    switch(type) {
        case LENGTH_ERR: cerr << "Exception: length error" << endl; break;
        case GET_ERR: cerr << "Exception: coordinate error in get()" << endl; break;
        case SET_ERR: cerr << "Exception: coordinate error in set()" << endl; break;
        case ADD_ERR: cerr << "Exception: addition of vectors of different lengths: " << x << " " << y << endl; break;
        case INDEX_ERR: cerr << "Exception: incorrect indexing: " << x << endl; break;
        case MULT_ERR: cerr <<  "Exception: multiplication of vectors of different lengths: " << x << " " << y << endl; break;
        default: cerr << "Exception: unknown error" << endl;
    }
}

template <typename T>
Vec<T>& Vec<T>::operator+=(const Vec<T> & op)
{
    if (len != op.len) throw test(ADD_ERR, len, op.len);
    for (int i=0; i < len; i++) v[i] += op.v[i];
    return *this;
}

template <typename T>
T Vec<T>::operator^(const Vec<T> & op) const
{
    if (len != op.len) throw test(MULT_ERR, len, op.len);
    T sum = 0;
    for (int i = 0; i < len; i++){
        sum += op.v[i] * v[i];
    }
    return sum;
}

template <typename T>
T& Vec<T>::operator[](int index) const
{
    if (index < 0 || index >= len) {throw test(INDEX_ERR, index);}
    return v[index];
}

template <typename T>
T Vec<T>::get(int coord) const 
{
	if ((coord>=len) || (coord<0)) throw test(GET_ERR);
	return v[coord];
}

template <typename T>
const Vec<T>& Vec<T>::operator= (const Vec<T>& op)
{
	if (*this == op) return *this;
	delete []v;
	v = new T[op.len];
	len = op.len;
	int i;
	for(i=0; i < len; i++) v[i] = op.v[i];
	return *this;
}

template <typename T>
Vec<T> Vec<T>::operator+(const Vec<T> & op) const
{
	if (len != op.len) {throw test(ADD_ERR, len, op.len);}
    Vec<T> tmp(len);
    for (int i = 0; i < len; i++) tmp.v[i] = v[i] + op.v[i];
    return tmp;
}

template <typename T>
Vec<T> Vec<T>::operator-(const Vec<T> & op) const
{
	if (len != op.len) {throw test(ADD_ERR, len, op.len);}
    Vec<T> tmp(len);
    for (int i = 0; i < len; i++) tmp.v[i] = v[i] - op.v[i];
    return tmp;
}

template <typename T>
Vec<T> Vec<T>::operator*(double a) const
{
    Vec<T> tmp(len);
    for (int i = 0; i < len; i++) tmp.v[i] = v[i] * a;
    return tmp;
}

template<typename V>
Vec<V> operator*(double a, const Vec<V>& op)
{
    Vec<V> tmp(op.len);
    for (int i = 0; i < op.len; i++) tmp.v[i] = op.v[i] * a;
    return tmp;
}

template<typename V>
bool operator==(const Vec<V>& op1, const Vec<V>& op2)
{
	if (op1.len != op2.len) return false;
	int i;
	for (i=0; i < op1.len; i++) if (op1.v[i] != op2.v[i]) return false;
	return true;
}

template<typename V>
ostream& operator<<(ostream& os, const Vec<V>& op)
{
	int i=0;
	os << "(";
	for(i=0; i < op.len - 1; i++) os << op.v[i] << ",";
	os << op.v[op.len-1] << ")";
	return os;
}

template <typename T>
Vec<T>::Vec(int len_inp, T *arr)
{
	if (len_inp < 0) {throw test(LENGTH_ERR);}
    len = len_inp;
    v = new T[len];
    int i;
    if (arr == nullptr) 
    	for (i=0; i < len; i++) v[i] = 0; 
    else
        for (i=0; i < len; i++) v[i] = arr[i];
}

template <typename T>
Vec<T>::Vec(const Vec<T> &a)
{
    len = a.len;
    v = new T[len];
    for (int i = 0; i < len; i++) v[i] = a.v[i];
}

template <typename T>
Vec<T>::~Vec() {delete []v;}

template <typename T>
void Vec<T>::set(T arg, int coord)
{
    if ((coord >= len) || (coord < 0)) throw test(SET_ERR);
    v[coord] = arg;
}

template <typename T>
T Vec<T>::max_norm() const
{ 
    T max =- 1;
    for (int i = 0; i < len; i++) {if (abs(v[i]) > max) max = abs(v[i]);}
    return max;
}

template <typename T>
void Vec<T>::print() const{
    cout << "(";
    for (int i = 0; i < len - 1; i++) cout << v[i] << ",";
    cout << v[len-1] << ")" << endl;
}

int main(){
    try {Vector();}
    catch(test &e) { e.print(); }
    catch(...) {test e; e.print();}
    return 0;
}