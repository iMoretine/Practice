#include <iostream>
#include <string>
using namespace std;


// 乐器
// 抽象类
class musi
{
public:
	musi(const string& m) {
		this->music = m;
		this->curnote = 0;
	};
	virtual ~musi() {};
	virtual string play() = 0;

protected:
	string music;
	size_t curnote;
};

// 拨弦乐器
// 抽象类
class pstring : public musi
{
public:
	pstring(const string& m) : musi(m) {};
	virtual ~pstring() {};
	virtual string play() = 0;
};

// 键盘
// 抽象类
class keyboard : public musi
{
public:
	keyboard(const string& m) : musi(m) {};
	virtual ~keyboard() {};
	virtual string play() = 0;
};

// 打击乐器
// 抽象类
class percussion : public musi
{
public:
	percussion(const string& m) : musi(m) {};
	virtual ~percussion() {};
	virtual string play() = 0;
};

// 吉他
class guitar : public pstring
{
public:
	guitar(const string& m) : pstring(m) {};
	virtual ~guitar() {};
	string play() {
		char note = this->music[curnote];
		curnote++;
		return string("G") + note;
	};
};

// 贝司
class bass : public pstring
{
public:
	bass(const string& m) : pstring(m) {};
	virtual ~bass() {};
	string play() {
		char note = this->music[curnote];
		curnote++;
		return string("B") + note;
	};
};

// 合成器
class esynthesizer : public keyboard
{
public:
	esynthesizer(const string& m) : keyboard(m) {};
	virtual ~esynthesizer() {};
	string play() {
		char note = this->music[curnote];
		curnote++;
		return string("S") + note;
	};
};

// 鼓
class drum : public percussion
{
public:
	drum(const string& m) : percussion(m) {};
	virtual ~drum() {};
	string play() {
		char note = this->music[curnote];
		curnote++;
		return string("D") + note;
	};
};

//用于乐队“演奏”的全局函数
//参数说明：
//band: 包含乐器指针的数组
//musiNum: 数组中的乐器件数
//musicLen: 乐谱的长度，即音符的个数
string bandPlay(musi *band[], size_t musiNum, size_t musicLen)
{
	string music;

	for (size_t i = 0; i < musicLen; i++)
		for (size_t j = 0; j < musiNum; j++)
			music += band[j]->play();
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

	musi *band[] = { &leadguitar, &guitar2, &bass1, &syn, &drums };

	cout << bandPlay(band, 5, m1.size());
	return 0;
}