#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Dairy.h"

#define MAXLEN 10000

int main(){
	int date;
	cin >> date;
	dairy D;
	D.read_dates();
	if(D.find_date(date) == 0){
		cout << -1 << endl;
	}
	else{
		D.skip(date);
		cout << 0 << endl;
	}
	return 0;
}