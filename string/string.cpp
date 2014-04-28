#include<iostream>
#include<cstring>

using namespace std;

//编写字符串类(String)，其属性为char*，
//至少实现构造、拷贝构造、析构函数及=、+操作符 

class String
{
	public:
		String()
		{
			m_str = new char [1];
			*m_str = '\0';
		}
		String(const char *str);
		~String();
		String(const String &str);
		String & operator = (const String &str);
		String operator + (const String &str);
	private:
		char *m_str;
};

String::String(const char *str)
{
	if(str == NULL)
	{
		m_str = new char [1];
		*m_str = '\0';
	}
	else
	{
		m_str = new char [ strlen(str)+1];
		strcpy(m_str,str);

	}
}

String::~String()
{
	delete [] m_str;
	m_str = NULL;
}
String::String(const String& str)
{
	m_str = new char [strlen(str.m_str)+1];
	strcpy(m_str,str.m_str);
}
String & String::operator = (const String &str)
{
	if(m_str == str.m_str)
	{
		return *this;
	}
	delete [] m_str;
	m_str = new char [strlen(str.m_str)+1];
	strcpy(m_str,str.m_str);
	return *this;
}
String String::operator + (const String &str)
{
	char *p = new char [strlen(m_str)+strlen(str.m_str)+1];
	strcpy(p,m_str);
	strcat(p,str.m_str);
	delete [] m_str;
	m_str= p;
	return *this;
}


int main()
{
	char *p = "abcd";
	char *q = "efgh";
	String a1(p);
	String a2(q);
	String a3;
	a3 = a1+a2;
	return 0;
}

