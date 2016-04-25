#include "Acount.h"

using namespace std;
 Acount::Acount(std::string name,std::string acount,double savings)
 {
 	this->name = name;
 	this->acount = acount;
 	this->savings = savings;
 }

 Acount::Acount()
 {
 	this->name = "unknown";
 	this->acount = "unknown";
 	this->savings = 0;
 }

 int Acount::in(double in)
 {
 	using namespace std;
 	this->savings+=in;
 	cout<<"Operation completed.\n";
 	return 0;
 }

 int Acount::out(double out)
 {
 	using namespace std;
 	this->savings-=out;
 	cout<<"Operation completed.\n";
 	return 0;
 }

 int Acount::showInfo()
 {
 	using namespace std;
 	cout<<"Infomation:\n";
 	cout<<"Name: "<<this->name;
 	cout<<"acount: "<<this->acount;
 	cout<<"savings: "<<this->savings;
 	return 0;
 }