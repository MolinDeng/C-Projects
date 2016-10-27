#include "Student.h"
#include <iomanip>
#include <iostream>
using namespace std;

#define MAX_NAME_LEN 10
#define COUR_NUM 3
#define SETW_LEN 8
#define STD_N 10
student::student() {
  No = 0;
  name = new char[MAX_NAME_LEN];
  scores = new int[COUR_NUM];
}

student::~student() {
  No = 0;
  name = NULL;
  scores = NULL;
}

float student::st_aver(void) {
  float ave = 0;
  int i;
  for (i = 0; i < COUR_NUM; i++) {
    ave += (float)scores[i] / COUR_NUM;
  }
  return ave;
}

void student::st_print(void) {
  cout.flags(ios::left);
  cout << setw(SETW_LEN) << No;
  cout << setw(SETW_LEN) << name;
  int i;
  for (i = 0; i < COUR_NUM; i++) {
    cout << setw(SETW_LEN) << scores[i];
  }
  cout << setw(SETW_LEN) << student::st_aver();
  cout << endl;
}
void student::st_scanf(void) {
  cin >> No >> name >> scores[0] >> scores[1] >> scores[2];
}
float student::getscore(int sco_n){
	return scores[sco_n];
}

void cour_aver(student *pstd) {
  float av[COUR_NUM] = {0};
  int i,j;
  for(i = 0; i< COUR_NUM; i++){
  	for(j = 0; j < STD_N; j++){
  		av[i] += pstd[j].getscore(i)/STD_N;
	}
  }

  cout.flags(ios::left);
  cout << setw(SETW_LEN) << "";
  cout << setw(SETW_LEN) << "average";
  for(i = 0; i< COUR_NUM; i++){
  	cout << setw(SETW_LEN) << av[i];
  }
  cout << endl;
}
void init_OUTPUT(void) {
  cout.flags(ios::left);
  cout << setw(SETW_LEN) << "no";
  cout << setw(SETW_LEN) << "name";
  cout << setw(SETW_LEN) << "score1";
  cout << setw(SETW_LEN) << "score2";
  cout << setw(SETW_LEN) << "score3";
  cout << setw(SETW_LEN) << "average";
  cout << endl;
}
void min(student *pstd) {
  int min[COUR_NUM] = {
      5, 5, 5,
  };
  int i, j;
  for (i = 0; i < COUR_NUM; i++) {
    for (j = 0; j < STD_N; j++) {
      if (pstd[j].getscore(i) <= min[i])
        min[i] = pstd[j].getscore(i);
    }
  }
  cout.flags(ios::left);
  cout << setw(SETW_LEN) << "";
  cout << setw(SETW_LEN) << "min";
  for (i = 0; i < COUR_NUM; i++) {
    cout << setw(SETW_LEN) << min[i];
  }
  cout << endl;
}
void max(student *pstd) {
  int max[COUR_NUM] = {
      0, 0, 0,
  };
  int i, j;
  for (i = 0; i < COUR_NUM; i++) {
    for (j = 0; j < STD_N; j++) {
      if (pstd[j].getscore(i) >= max[i])
        max[i] = pstd[j].getscore(i);
    }
  }
  cout.flags(ios::left);
  cout << setw(SETW_LEN) << "";
  cout << setw(SETW_LEN) << "max";
  for (i = 0; i < COUR_NUM; i++) {
    cout << setw(SETW_LEN) << max[i];
  }
  cout << endl;
}
