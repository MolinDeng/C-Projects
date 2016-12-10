#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#ifndef _Dairy_h
#define _Dairy_h

class dairy{
private:
	vector<int> dates;
public:
	dairy(){}
	~dairy(){}
	void date_sort(void);
	int read_dates(void);
	vector<int> access(void);
	void skip(int date);
	int find_date(int date);
};
#endif