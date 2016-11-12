#ifndef _Student_h
#define _Student_h

#include<vector>
#include<string>
using namespace std;

class student {
public:
  student():No(0){};
  ~student(){};
  float st_aver(void);
  void st_print(void);
  void st_scanf(void);
  float getscore(int sco_n);
  int getN(void);
  	
private:
  int No;
  string name;
  vector<int> scores;
};

void cour_aver(vector<student> st);

//void min(student *pstd);
//
//void max(student *pstd);

void init_OUTPUT(void);

#endif
