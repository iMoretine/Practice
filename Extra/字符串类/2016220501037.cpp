#include <iostream>
using namespace std;

const int MAX_STRLEN = 128;//字符串的最大长度

class cstring
{
private:
	char *str;
public:
	cstring()
	{
		str = new char[MAX_STRLEN];
		str[0] = '\0';
	}
	cstring(char c)
	{
		str = new char[MAX_STRLEN];
		str[0] = c;
		str[1] = '\0';
	}
	cstring(const char* temp)
	{
		str = new char[MAX_STRLEN];
		int length = _strlen(temp);
		for (int i = 0; i < length; i++)
		{
			str[i] = temp[i];
		}
		str[length] = '\0';
	}
	cstring(const cstring& other)
	{
		str = new char[MAX_STRLEN];
		int length = other.size();
		for (int i = 0; i<length; i++)
		{
			str[i] = other.get_str()[i];
		}
		str[length] = '\0';
	}
	~cstring()
	{
		if (str != NULL)
		{
			delete[]str;
			str = NULL;
		}
	}
	size_t size() const
	{
		size_t i = 0;
		while (str[i] != '\0')
		{
			i++;
		}
		return i;
	}
	bool isEmpty()
	{
		return get_str() == NULL;
	}
	void empty()
	{
		delete[]str;
		str = NULL;
	}
	cstring& concate(const cstring& temp)
	{
		char* src = temp.get_str();
		_strcat(get_str(), src);
		return *this;
	}
	cstring& concate(const char* temp)
	{
		_strcat(get_str(), temp);
		return *this;
	}
	char* get_str() const
	{
		return str;
	}
	size_t _strlen(const char* str)
	{
		size_t i = 0;
		while (str[i] != '\0')
		{
			i++;
		}
		return i;
	}
	char* _strcpy(char* dest, const char* src)
	{
		int length = _strlen(src);
		for (size_t i = 0; i < length; i++)
		{
			dest[i] = src[i];
		}
		dest[length] = '\0';
		return dest;
	}
	char* _strcat(char* dest, const char* src)
	{
		int destLength = _strlen(dest);
		int srcLength = _strlen(src);
		int totalLength = destLength + srcLength;
		for (size_t i = 0; i < srcLength; i++)
		{
			dest[destLength + i] = src[i];
		}
		dest[totalLength] = '\0';
		return dest;
	}

	// 运算符重载

	cstring& operator=(const cstring& other)
	{
		str = new char[MAX_STRLEN];
		int length = other.size();
		for (int i = 0; i<length; i++)
		{
			str[i] = other.get_str()[i];
		}
		str[length] = '\0';
		return *this;
	}

	cstring& operator=(const char* temp)
	{
		str = new char[MAX_STRLEN];
		int length = _strlen(temp);
		for (int i = 0; i < length; i++)
		{
			str[i] = temp[i];
		}
		str[length] = '\0';
		return *this;
	}

	cstring& operator+=(const cstring& temp)
	{
		char* src = temp.get_str();
		_strcat(get_str(), src);
		return *this;
	}
	cstring& operator+=(const char* temp)
	{
		_strcat(get_str(), temp);
		return *this;
	}

	char operator[](const int index)
	{
		return str[index];
	}

	friend cstring operator+(const cstring& str1, const cstring& str2)//友元函数
	{
		cstring nStr(str1);
		return nStr += str2;
	}
	friend cstring operator+(const cstring& str1, const char* str2)//友元函数
	{
		cstring nStr(str1);
		return nStr += str2;
	}
	friend cstring operator+(const char* str1, const cstring& str2)//友元函数
	{
		cstring nStr(str1);
		return nStr += str2;
	}

	friend ostream& operator<<(ostream& out, const cstring& str)
	{
		out << str.get_str();
		return out;
	}

	friend istream& operator>>(istream& in, cstring& str)
	{
		char name[128] = { 0 };
		in >> name;
		str._strcpy(str.str, name);
		return in;
	}
};
void puts(const cstring& s)
{
    cout << s.get_str();
}

cstring f(const char *s)
{
    return cstring(s);
}

int main()
{
    // char b1[128], b2[128];
    // cin >> b1 >> b2;

    // cstring s1(b1), s2(s1);

    // puts(s2.concate(f(b2)));
    cstring s1, s2;
    char buf1[128], buf2[128];

    cin >> s1 >> buf1 >> buf2;

    cstring s3(buf2);
    s2 = s1;
    s2 += f(buf1);
    s1 = s3[5] + s2;
    cout << s1 << endl;

    return 0;
}