#ifndef ACOUNT_H_
#define ACOUNT_H_
#include <string>
#include <iostream>

class Acount
{
private:
	std::string name;
	std::string acount;
	double savings;
public:
	Acount();
	Acount(std::string name,std::string acount,double savings);
	int in(double in);
	int out(double out);
	int showInfo();
	~Acount();
};
#endif