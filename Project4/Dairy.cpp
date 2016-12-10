#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "Dairy.h"

#define MAXLEN 10000

using namespace std;

bool cmp(int a,int b){
	return a < b;
}

void dairy::date_sort(void){
	sort(dates.begin(), dates.end(),cmp);
}

int dairy::read_dates(void){
	FILE* fp;
	if((fp = fopen("dairy.txt","r")) == NULL){
		printf("Cannot open Personal Dairy, strike any key exit!");
		exit(1);
	}
	char temp[MAXLEN];
	while(fgets(temp, MAXLEN, fp) != NULL){
		int d = atoi(temp);
		if(strlen(temp) == 9 && d > 0){
			dates.push_back(d);
		}
	}
	if(dates.size() == 0){
		fclose(fp);
		return 0;
	}
	dairy::date_sort();
	fclose(fp);
	return 1;
}

vector<int> dairy::access(void){
	return dates;
}

void dairy::skip(int date){
	FILE* fp;
	FILE* fp_temp;
	if((fp = fopen("dairy.txt","w+")) == NULL){
		printf("Cannot open Personal Dairy, strike any key exit!");
		exit(1);
	}
	char temp[MAXLEN];
	int flag = 1;
	fp_temp = fopen("temp.txt","a");
	
	while(fgets(temp, MAXLEN, fp) != NULL){
		int d = atoi(temp);
		if(strlen(temp) == 9 && d == date)
			flag = 0;
		if(flag == 1){
			fputs(temp, fp_temp);
		}
		if(temp[0] == '.')
			flag = 1;
	}
	fclose(fp);
	fclose(fp_temp);
	remove("dairy.txt");
	rename("temp.txt" ,"dairy.txt");
}

int dairy::find_date(int date){
	vector<int>::iterator iter;
	iter = std::find(dates.begin(), dates.end(), date);
	if(iter == dates.end()) return 0;
	else return 1;
}

