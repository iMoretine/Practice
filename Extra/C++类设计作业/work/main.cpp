#include <iostream>
#include <string>
using namespace std;


// ����
// ������
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

// ��������
// ������
class pstring : public musi
{
public:
	pstring(const string& m) : musi(m) {};
	virtual ~pstring() {};
	virtual string play() = 0;
};

// ����
// ������
class keyboard : public musi
{
public:
	keyboard(const string& m) : musi(m) {};
	virtual ~keyboard() {};
	virtual string play() = 0;
};

// �������
// ������
class percussion : public musi
{
public:
	percussion(const string& m) : musi(m) {};
	virtual ~percussion() {};
	virtual string play() = 0;
};

// ����
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

// ��˾
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

// �ϳ���
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

// ��
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

//�����ֶӡ����ࡱ��ȫ�ֺ���
//����˵����
//band: ��������ָ�������
//musiNum: �����е���������
//musicLen: ���׵ĳ��ȣ��������ĸ���
string bandPlay(musi *band[], size_t musiNum, size_t musicLen)
{
	string music;

	for (size_t i = 0; i < musicLen; i++)
		for (size_t j = 0; j < musiNum; j++)
			music += band[j]->play();
	//��Ϊ�޷��ó������ͬʱ�����ࡱ�����ֻ�а�˳����
	//��ˣ����д�Ĵ���Ӧ������ѭ����Ҳ���Ƕ��أ��а�˳��
	//����band�����е�����ȥ�����ࡱ���õ���ǰ������
	//Ȼ����Щ������ӵ�music��

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