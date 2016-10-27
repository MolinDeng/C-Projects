1.本程序使用IDE为DEV C++。
2.运行程序时，请键入学生信息，学生数为10，键入格式为：no name score1 score2 score3<回车>
  例如：1 K.Weng 5 5 5 
        2 T.Dixon 4 3 2 
        3 V.Chu 3 4 5 
        4 L.Tson 4 3 4 
        5 L.Lee 3 4 3       
        6 I.Young 4 2 5       
        7 K.Hiro 4 2 1       
        8 G.Ping 4 4 4       
        9 H.Gu 2 34      
        10 J.Jon 5 4 3      
  键入完成后回车即可输入统计表。
  若要修改学生个数，请在main.cpp和Student.cpp中修改STD_N的值。
3.code文件夹中为源代码；
  makefile文件夹中为makefile文件。
4.题目如下
Write a program that asks you 10 records of students. Each record consists of a name (w/o space), and scores for three courses (in integer, 1 to 5). Output a list as the next page and calculate average score (in float) of each student and each course. Output the lowest and highest score for each course.

no      name    score1  score2  score3  average
1       K.Weng  5       5       5       5
2       T.Dixon 4       3       2       3
3       V.Chu   3       4       5       4
4       L.Tson  4       3       4       3.66667
5       L.Lee   3       4       3       3.33333
6       I.Young 4       2       5       3.66667
7       K.Hiro  4       2       1       2.33333
8       G.Ping  4       4       4       4
9       H.Gu    2       3       4       3
10      J.Jon   5       4       3       4
        average 3.8     3.4     3.6
        min     2       2       1
        max     5       5       5
