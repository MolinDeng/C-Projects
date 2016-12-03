#include <string>
#include <vector>
using namespace std;

#ifndef _Adventure_h
#define _Adventure_h

class room{
public:
	room(string _name);
	room(const room&);
	virtual ~room();
	virtual void show();
	room* move();
	connect_rooms(room* _left, room* _right, room* _up, room* _down);
	room** f(){return exits;}
protected:
	vector<string> info;
	room* exits[4];
};

class OUT : public room{
public:
	OUT(string _name):room(_name){}
	OUT(const OUT&);
	virtual ~OUT();
	virtual void show();
};

class princess_room : public room{
public:
	princess_room(string _name):room(_name){}
	princess_room(const princess_room&);
	virtual ~princess_room(); 
	virtual void show();
};

class monster_room : public room{
public:
	monster_room(string _name):room(_name){}
	monster_room(const monster_room&);
	virtual ~monster_room();
	virtual void show();
};

void show(room* p);
void adventure();
#endif
