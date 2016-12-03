#include "Adventure.h"
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib> 
using namespace std;

#define left  0
#define right 1
#define up    2
#define down  3

int is_get_princess = 0;
int is_dead = 0;
int is_out = 0;

room::~room(){}
princess_room::~princess_room(){}	
monster_room::~monster_room(){}
OUT::~OUT(){}

room::room(string _name){
	int i;
	for(i = 0; i < 4; i++)
		exits[i] = NULL;
	info.push_back(_name);
}

void room::show(){
	cout << "Welcome to the " << info[0] << ". "
		 << "There are " << (info.size()-1) << " " << "exits as:";
	int i;
	for(i = 1; i <= info.size()-1; i++){
		cout << " " << info[i];
	}
	cout << "." << endl;
	cout << "Enter your command:" << endl;
}

room* room::move(){
	string omitted, exit_name;
	cin >> omitted >> exit_name;
	if(exit_name == "left")
		return exits[left];
	else if(exit_name == "right")
		return exits[right];
	else if(exit_name == "up") 
		return exits[up];
	else if(exit_name == "down")
		return exits[down];
}

void princess_room::show(){
	is_get_princess = 1;
	cout << "Welcome to the " << info[0] << ". " << endl;
	cout << "You have to take her outside the castle" << endl;
	cout << "There are " << (info.size()-1) << " " << "exits as:";
	int i;
	for(i = 1; i <= info.size()-1; i++){
		cout << " " << info[i];
	}
	cout << "." << endl;
	cout << "Enter your command:" << endl;
}

void monster_room::show(){
	is_dead = 1;
	cout << "Welcome to the " << info[0] << ". " << "YOU ARE DEAD! Game over."
	<< endl;
}

void OUT::show(){
	is_out = 1;
	if(is_get_princess == 1)
		cout << "YOU WIN!" << endl;
	else 
		cout << "You didn't save princess. YOU LOSE" << endl;
	cout << "Game over" << endl;
}

room::connect_rooms(room* _left, room* _right, room* _up, room* _down)
{
	exits[0] = _left;
	exits[1] = _right;
	exits[2] = _up;
	exits[3] = _down;
	int i;
	for(i = 0; i < 4; i++){
		if(exits[i] != NULL){
			switch(i){
				case left: info.push_back("left"); break;
				case right: info.push_back("right"); break;
				case up: info.push_back("up"); break;
				case down: info.push_back("down"); break;
			}
		}
	}	
}

void show(room* p){
	p->show();
}

void adventure(){
	room lobby("Lobby");
	OUT out("outside");
	room a("Normal Room");
	room b("Normal Room");
	room c("Normal Room");
	room d("Normal Room");
	room e("Normal Room");
	
	lobby.connect_rooms(&b, &out, &e, &a);
	b.connect_rooms(&d, &lobby, &c, NULL);
	d.connect_rooms(NULL, &b, NULL, NULL);
	e.connect_rooms(&c, NULL, NULL, &lobby);
	a.connect_rooms(NULL, NULL, &lobby, NULL);
	c.connect_rooms(NULL, &e, NULL, &b);
	
	room* princess_chosen;
	room* monster_chosen;
	princess_room princess("Princess Room");
	monster_room monster("Monster Room");
	room* Room[5] = {&a, &b, &c, &d, &e};
	srand((unsigned)time(NULL));
	int temp1, temp2;
	while(1){
		temp1 = rand()%5;
		temp2 = rand()%5;
		if(temp1 != temp2) break;
	}
  	princess_chosen = Room[temp1];
	monster_chosen = Room[temp2];
	room** R = princess_chosen->f();
	princess.connect_rooms(R[0], R[1], R[2], R[3]);
	
	room* p = &lobby;
	while(1){
		if(p == princess_chosen){
			show(&princess);
		}else if(p == monster_chosen){
			show(&monster);
		}else{
			show(p);
		}
		if(is_dead || is_out) break;
		p = p->move();
	}
	is_get_princess = 0;
	is_dead = 0;
	is_out = 0;
}
