#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Dairy.h"

#define MAXLEN 10000

int main(int argc, char *argv[]){
	dairy D;
	FILE* fp;
	D.read_dates();
	vector<int> dates = D.access();
	if(argc == 1){
		for(int i = 0; i < dates.size(); i++){
			if((fp = fopen("dairy.txt","a+")) == NULL){
				printf("Cannot open Personal Dairy, strike any key exit!");
				exit(1);
			}
			int flag = 0;
			char temp[MAXLEN];
			while(fgets(temp, MAXLEN, fp) != NULL){
				int d = atoi(temp);
				if(strlen(temp) == 9 && d == dates[i]){
					flag = 1;
				}
				if(flag == 1){
					fputs(temp, stdout);
					if(temp[0] == '.')
						break;
				}
			}
		}
		fclose(fp);
	}
	else if(argc == 2){
		int start = atoi(argv[1]);
		for(int i = 0; i < dates.size(); i++){
			if((fp = fopen("dairy.txt","a+")) == NULL){
				printf("Cannot open Personal Dairy, strike any key exit!");
				exit(1);
			}
			int flag = 0;
			char temp[MAXLEN];
			while(fgets(temp, MAXLEN, fp) != NULL){
				int d = atoi(temp);
				if(strlen(temp) == 9 && d == dates[i] && d >= start){
					flag = 1;
				}
				if(flag == 1){
					fputs(temp, stdout);
					if(temp[0] == '.')
						break;
				}
			}
		}
		fclose(fp);		
	}
	else{
		int start = atoi(argv[1]);
		int end = atoi(argv[2]);
		if(end < start){
			printf("Time Error");
			exit(1);
		}
		for(int i = 0; i < dates.size(); i++){
			if((fp = fopen("dairy.txt","a+")) == NULL){
				printf("Cannot open Personal Dairy, strike any key exit!");
				exit(1);
			}
			int flag = 0;
			char temp[MAXLEN];
			while(fgets(temp, MAXLEN, fp) != NULL){
				int d = atoi(temp);
				if(strlen(temp) == 9 && d == dates[i] && d >= start && d <= end){
					flag = 1;
				}
				if(flag == 1){
					fputs(temp, stdout);
					if(temp[0] == '.')
						break;
				}
			}
		}
		fclose(fp);			
	}
}