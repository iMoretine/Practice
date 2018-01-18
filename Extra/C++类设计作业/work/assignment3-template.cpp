#include <iostream>
#include <string>
using namespace std;

//你编写的各种类的定义放在这里

//用于乐队“演奏”的全局函数
//参数说明：
//band: 包含乐器指针的数组
//musiNum: 数组中的乐器件数
//musicLen: 乐谱的长度，即音符的个数
string bandPlay(musi *band[], size_t musiNum, size_t musicLen)
{
	string music;

	//你编写的代码放在这里
	//因为无法用程序代码同时“演奏”，因此只有按顺序来
	//因此，你编写的代码应该是在循环（也许是多重）中按顺序
	//调用band数组中的乐器去“演奏”，得到当前音符，
	//然后将这些音符添加到music中
	
	return music;
}

int main()
{
	string m1, m2, m3, m4, m5;
	cin >> m1 >> m2 >> m3 >> m4 >> m5; //all string has the same length

	guitar leadguitar(m1), guitar2(m2);
	bass bass1(m3);
	esynthesizer syn(m4);
	drum drums(m5);

	musi *band[] = {&leadguitar, &guitar2, &bass1, &syn, &drums};

	cout << bandPlay(band, 5, m1.size());

	return 0;
}