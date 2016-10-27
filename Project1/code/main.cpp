#include "Student.h"
#include <iostream>
using namespace std;
#define STD_N 10

int main() {
  cout << "Please input student's information:" << endl;
  student *st;
  st = new student[STD_N];
  int i;
  for (i = 0; i < STD_N; i++) {
    st[i].st_scanf();
  }
  init_OUTPUT();
  for (i = 0; i < STD_N; i++) {
    st[i].st_print();
  }
  cour_aver(st);
  min(st);
  max(st);
  delete[] st;
  return 0;
}
