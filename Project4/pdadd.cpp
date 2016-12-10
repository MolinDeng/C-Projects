#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include "Dairy.h"

#define MAXLEN 10000

int main(){
	FILE *fp;
	dairy D;
	char temp[MAXLEN];
	int flag = 0;
	while(fgets(temp, MAXLEN, stdin) != NULL){
		if(flag == 0){
			int d = atoi(temp);
			D.skip(d);
			if((fp = fopen("dairy.txt","a+")) == NULL){
				printf("Cannot open Personal Dairy");
				exit(1);
			}
			flag = 1;
		}
		fputs(temp, fp);
		if(temp[0] == '.') break;
	}
	fclose(fp);
}