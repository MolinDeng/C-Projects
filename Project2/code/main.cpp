#include "Student.h"
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main() {
  cout << "Please input student's information:" << endl;
  vector<student> st;
  string f;
  while(1){
  	student *p = new student;
  	p->st_scanf();
  	st.push_back(*p);
  	cin >> f;
  	if(f == "done")
  	  break;
  }
  init_OUTPUT();
  vector<student>::iterator p;
  for (p = st.begin(); p < st.end(); p++) {
    p->st_print();
  }
  cour_aver(st);
//  min(st);
//  max(st);
  return 0;
}
