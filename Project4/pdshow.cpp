#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "Dairy.h"

#define MAXLEN 10000

int main(){
	int date;
	dairy D;
	cin >> date;
	D.read_dates();
	if(D.find_date(date) == 0){
		printf("No dairy of this date");
		exit(1);
	}
	FILE* fp;
	if((fp = fopen("dairy.txt","a+")) == NULL){
		printf("Cannot open Personal Dairy, strike any key exit!");
		exit(1);
	}
	int flag = 0;
	char temp[MAXLEN];
	while(fgets(temp, MAXLEN, fp) != NULL){
		if(flag == 1){
			if(temp[0] == '.')
				break;
			fputs(temp, stdout);
		}
		int d = atoi(temp);
		if(strlen(temp) == 9 && d == date){
			flag = 1;
		}
	}
	return 0;
}