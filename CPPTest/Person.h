#pragma once
#include <string>
using namespace std;

class Person
{
public:
	Person(void);
	~Person(void);
	string name;
	int age;
	bool isAlive;
	void talk();
	void sleep();
};

