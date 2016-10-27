#ifndef _Student_h
#define _Student_h

class student {
public:
  student();
  ~student();
  float st_aver(void);
  void st_print(void);
  void st_scanf(void);
  float getscore(int sco_n);
private:
  int No;
  char *name;
  int *scores;
};

void cour_aver(student *pstd);

void min(student *pstd);

void max(student *pstd);

void init_OUTPUT(void);

#endif
