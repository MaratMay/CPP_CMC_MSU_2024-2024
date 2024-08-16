#include <algorithm>
#include <iostream>
#include <list>
#include <limits.h>
#include <cstring>
using std::cout;
using std::list;
using std::endl;
using std::stoi;
using std::cin;
int main(int argc, char *argv[])
{
	list <int> l;
	int x;
	while(scanf(" %d ", &x) > 0) l.push_back(x);
	int num1, num2;
	if (argc >= 3) num1 = stoi(argv[2]);
	if (argc == 4) num2 = stoi(argv[3]);
	switch(argc)
	{
		case 2:
			if (l.empty()) break;
			if (!strcmp(argv[1], "-me")) 
			{
				auto max_it = l.begin();
                int max = *max_it;
				for (auto it=l.begin(); it != l.end(); it++) {
	                if(*it > max) {
	                    max_it = it;
	                    max =* it;
	                }
            	}
           	 	l.erase(max_it);
            	l.push_back(max);
			}
			else if (!strcmp(argv[1], "-mf"))
			{
				auto max_it = l.begin();
                int max = *max_it;
				for (auto it=l.begin(); it != l.end(); it++) {
	                if(*it > max) {
	                    max_it = it;
	                    max =* it;
	                }
            	}
           	 	l.erase(max_it);
            	l.push_front(max);
			}
			else if (!strcmp(argv[1], "-sd"))
			{
				l.sort();
				l.reverse();
			}
			else if (!strcmp(argv[1], "-sa"))
			{
				l.sort();
			}
			break;
		case 3:
			if (!strcmp(argv[1], "-d")) 
			{
				for(auto it=l.begin(); it != l.end(); it++)
				{
	                if(*it == num1) {
	                    l.erase(it);
	                    break;
                	}
				}
			}
			else if (!strcmp(argv[1], "-ae"))
			{
				l.push_back(num1);
			}
			else if (!strcmp(argv[1], "-af"))
			{
				l.push_front(num1);
			}
			break;
		case 4:
			if (!strcmp(argv[1], "-ia"))
			{
				for(auto it=l.begin(); it != l.end(); it++)
				{
	                if(*it == num2) {
	                    l.insert(++it, num1);
	                    break;
                	}
				}
			}
			else if (!strcmp(argv[1], "-ib"))
			{
				for(auto it = l.begin(); it != l.end(); it++)
				{
	                if(*it == num2) {
	                    l.insert(it, num1);
	                    break;
                	}
				}
			}
	}
	for (int n : l)
        cout << n << " ";
    cout << endl;
    return 0;
}