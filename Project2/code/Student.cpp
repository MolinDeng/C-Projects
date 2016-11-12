#include "Student.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define SETW_LEN 8
int N;

float student::st_aver(void) {
  float ave = 0;
  vector<int>::iterator p;
  for (p = scores.begin(); p < scores.end(); p++) {
    ave += (float)(*p) / scores.capacity();
  }
  return ave;
}

void student::st_print(void) {
  cout.flags(ios::left);
  cout << setw(SETW_LEN) << No;
  cout << setw(SETW_LEN) << name;
  vector<int>::iterator p;
  for (p = scores.begin(); p < scores.end(); p++) {
    cout << setw(SETW_LEN) << *p;
  }
  cout << setw(SETW_LEN) << student::st_aver();
  cout << endl;
}
void student::st_scanf(void) {
  cin >> No >> name;
  int i;
  while(cin >> i){
  	if(i == -1)
  	  break;
  	scores.push_back(i);
  }
  	
}
float student::getscore(int sc_num){
	return scores[sc_num];
}

void cour_aver(vector<student> st) {
  N = st[0].getN();
  float av[N] = {0};
  int i;
  vector<student>::iterator p;
  for(i = 0; i< N; i++){
  	for(p = st.begin(); p < st.end(); p++){
  		av[i] += p->getscore(i)/st.capacity();
	}
  }

  cout.flags(ios::left);
  cout << setw(SETW_LEN) << "";
  cout << setw(SETW_LEN) << "average";
  for(i = 0; i< N; i++){
  	cout << setw(SETW_LEN) << av[i];
  }
  cout << endl;
}
void init_OUTPUT(void) {
  cout.flags(ios::left);
  cout << setw(SETW_LEN) << "no";
  cout << setw(SETW_LEN) << "name";
  cout << setw(SETW_LEN) << "scores";
  cout << setw(SETW_LEN) << "The last one is average score";
  //cout << setw(SETW_LEN) << "average";
  cout << endl;
}
int student::getN(void){
  return scores.capacity();
}
//void min(student *pstd) {
//  int min[COUR_NUM] = {
//      5, 5, 5,
//  };
//  int i, j;
//  for (i = 0; i < COUR_NUM; i++) {
//    for (j = 0; j < STD_N; j++) {
//      if (pstd[j].getscore(i) <= min[i])
//        min[i] = pstd[j].getscore(i);
//    }
//  }
//  cout.flags(ios::left);
//  cout << setw(SETW_LEN) << "";
//  cout << setw(SETW_LEN) << "min";
//  for (i = 0; i < COUR_NUM; i++) {
//    cout << setw(SETW_LEN) << min[i];
//  }
//  cout << endl;
//}
//void max(student *pstd) {
//  int max[COUR_NUM] = {
//      0, 0, 0,
//  };
//  int i, j;
//  for (i = 0; i < COUR_NUM; i++) {
//    for (j = 0; j < STD_N; j++) {
//      if (pstd[j].getscore(i) >= max[i])
//        max[i] = pstd[j].getscore(i);
//    }
//  }
//  cout.flags(ios::left);
//  cout << setw(SETW_LEN) << "";
//  cout << setw(SETW_LEN) << "max";
//  for (i = 0; i < COUR_NUM; i++) {
//    cout << setw(SETW_LEN) << max[i];
//  }
//  cout << endl;
//}
