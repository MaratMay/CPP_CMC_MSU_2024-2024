#include <cstdio>
#include <iostream>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
class mstring
{
	char* str;
	long unsigned int my_size=0;
	public:
		mstring() {str = new char[1]; str[0] = 0;}
		mstring(const char* x) {my_size = strlen(x) + 1; str = new char[my_size]; strcpy(str, x);}
		mstring(const mstring& op) {my_size = strlen(op.str) + 1; str = new char[my_size]; strcpy(str, op.str);}
		~mstring() {delete[] str;}
		int length() const;
	    bool isempty() const;
	    void add(char c);
	    void add(const char* c);
	    void insert(char c,int i);
	    void insert(const char* c,int i);
	    void print() const;
	    void del(int i);
	    void del(int i, int j);
	    int search(const char* str) const;
	    void replace(const char* sub_str, const char *new_str);
	    const mstring& operator=(const mstring& op);
	    mstring operator+(const mstring& op) const;
	    mstring operator+(const char* x) const;
	    friend mstring operator+(const char* x, const mstring& op);
	    mstring operator*(int x) const;
	    friend mstring operator*(int x, const mstring& op);
	    bool operator>(const mstring& op) const;
	    bool operator<(const mstring& op) const;
	    bool operator>=(const mstring& op) const;
	    bool operator<=(const mstring& op) const;
	    bool operator==(const mstring& op) const;
	    char& operator[](int index) const;
	    friend ostream& operator<<(ostream& os, const mstring& op);
	    friend istream& operator>>(istream& is, mstring& op);

};

const int str_plus_size = 128;

int mstring::length() const {return strlen(str);}
bool mstring::isempty() const {return !strlen(str);}
void mstring::add(char c)
{
	if (my_size <= strlen(str) + 1) 
	{
		my_size += str_plus_size;
		char* temp = new char[my_size];
		strcpy(temp, str);
		delete[] str;
    	str = temp;
	}
	str[strlen(str) + 1] = 0;
	str[strlen(str)] = c;
}
void mstring::add(const char* c)
{
	if (my_size <= strlen(str) + strlen(c))
	{
		my_size += str_plus_size + strlen(c);
		char* temp = new char[my_size];
		strcpy(temp, str);
		delete[] str;
    	str = temp;
	}
	strcat(str, c);
}
void mstring::insert(char c, int i) {
	if (my_size <= strlen(str) + 1) my_size += str_plus_size;
	char *temp = new char[my_size];
	strcpy(temp, str);
	temp[i + 1] = 0;
    temp[i] = c;
    strcat(temp, &str[i]);
    delete[] str;
    str = temp;
}
void mstring::insert(const char* c,int i) {
	if (my_size <= strlen(str) + strlen(c))	my_size += str_plus_size + strlen(c);
	char *temp = new char[my_size];
	strcpy(temp, str);
	temp[i] = 0;
    strcat(temp, c);
    strcat(temp, &str[i]);
    delete[] str;
    str = temp;
}
void mstring::print() const {cout << str << endl;}
void mstring::del(int i)
{
    char *temp = new char[my_size];
    strcpy(temp, str);
    temp[i] = 0;
    strcat(temp, &str[i + 1]);
    delete[] str;
    str = temp;
}
void mstring::del(int i, int j)
{
    char *temp = new char[my_size];
    strcpy(temp, str);
    temp[i] = 0;
    strcat(temp, &str[j + 1]);
    delete[] str;
    str = temp;
}
int mstring::search(const char* x) const {return strstr(str, x) == nullptr ? -1 : strstr (str, x) - str;}
void mstring::replace(const char* sub_str, const char *new_str){ //добить 
    int res = strstr(str, sub_str)==nullptr ? -1 : strstr (str, sub_str) - str;
    if (res == -1) return;
    char *temp = new char[strlen(str) + strlen(new_str) - strlen(sub_str) + 1];
    strcpy(temp, str);
    temp[res] = 0;
    strcat(temp, new_str);
    temp[res + strlen(new_str)] = 0;
    if (strlen(temp) < strlen(str)) strcat(temp, &str[res + strlen(sub_str)]);
    delete[] str;
    str = temp;
}
const mstring& mstring::operator=(const mstring& op)
{
	if (this == &op) return *this;
	delete []str;
	my_size = op.my_size;
	str = new char[my_size];
	strcpy(str, op.str);
	return *this;
}
mstring mstring::operator+(const mstring& op) const
{
	mstring ans;
	ans.my_size = my_size + op.my_size;
	char* temp = new char[ans.my_size];
	strcpy(temp, str);
	strcat(temp, op.str);
	ans.str = temp;
	return ans;
}
mstring mstring::operator+(const char* x) const
{
	mstring ans(x);
	ans = *this; 
	ans.add(x);
	return ans;
}
mstring operator+(const char* x, const mstring& op)
{
	mstring ans(x);
	ans.add(op.str);
	return ans;
}
mstring mstring::operator*(int x) const
{
	mstring ans;
	if (x == 0) return ans;
	for(int i=0; i < x; i++) ans.add(str);
	return ans;
}
mstring operator*(int x, const mstring& op)
{
	mstring ans;
	ans = op;
	return ans * x;
}
bool mstring::operator<(const mstring& op) const
{
    return strcmp(str, op.str)<0?true:false;
}
bool mstring::operator>(const mstring& op) const
{
	return strcmp(str, op.str)>0?true:false;
}
bool mstring::operator>=(const mstring& op) const
{
	return strcmp(str, op.str)>=0?true:false;
}
bool mstring::operator<=(const mstring& op) const
{
	return strcmp(str, op.str)<=0?true:false;
}
bool mstring::operator==(const mstring& op) const
{
    return strcmp(str, op.str)==0?true:false;
}
char& mstring::operator[](int index) const 
{
    return str[index];
}
ostream& operator<<(ostream& os, const mstring& op)
{
    os << op.str;
    return os;
}
istream& operator>>(istream& is, mstring& op) {
    char c;
    delete[] op.str;
    op.my_size = str_plus_size;
    op.str = new char[op.my_size];
    unsigned int i = 0;
    while (is.get(c) && (c != '\n') && (!is.eof())) 
    {
        op.str[i++] = c;
        if (i >= op.my_size) {
        	op.my_size += str_plus_size;
            char* tmp = new char[op.my_size];
            strcpy(tmp, op.str);
            delete[] op.str;
            op.str = tmp;
        }
    }
    op.str[i] = 0;
    return is;
}