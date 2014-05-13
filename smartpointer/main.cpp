/******************************************************************************
*  author: yanenquan
*  version: 1.0
*  description: ����ָ�� 
*  date: 2014-05-13
*  other: ��
******************************************************************************/

#include <iostream>
#include <string>
#include "runtime_error.h"
#include "smartpointer.h"

using namespace std;  
 
//һ����������ָ�����  
class CMyTestClass  
{  
public:  
    CMyTestClass() { cout << "A CMyTestClass Object was created." << endl; }  
    virtual void Print(void) { cout << "CMyTestClass Print()." << endl; }  
    virtual void Show(void) { cout << "CMyTestClass Show()." << endl; }  
    ~CMyTestClass() { cout << "A CMyTestClass Object was destroied." << endl; }  
};  
 
class CMyTestSubClass : public CMyTestClass  
{  
public:  
    CMyTestSubClass() { cout << "A CMyTestSubClass Object was created." << endl; }  
    virtual void Print(void) { cout << "CMyTestSubClass Print()." << endl; }  
    void SubShow(void) { cout << "Sub Show()." << endl; }  
    ~CMyTestSubClass() { cout << "A CMyTestSubClass Object was destroied." << endl; }  
};  
 
int main(int argc, char* argv[])  
{  
    try 
    {  
        TSmartPtr<CMyTestClass> t;    //��Ϊû�и�t����CMyTestClass�����ָ�������ȥ�����Ի���쳣��  
        t->Print();  
    }  
    catch(const runtime_error& err)  
    {  
        cout << err.get_error_str() << endl;  
    }  
    //��������Ѿ�����ͨ���ˡ������ȷ��  
    //--------------------------------------  
    TSmartPtr<CMyTestClass> t1(new CMyTestClass);  
    t1->Print();  
    //�����������->���صĲ���������ȷ�ԡ����Խ������ȷ�ġ�  
    TSmartPtr<CMyTestClass> t2(t1);  
    t2->Print();  
    //����������Կ������캯������ȷ�ԡ����Խ������ȷ�ġ�  
    TSmartPtr<CMyTestClass> t3(new CMyTestClass);  
    t3 = t2;  
    (*t3).Print();  
    //�����������=���صĲ���������ȷ�ԡ����Խ��Ҳ����ȷ�ġ�  
 
    TSmartPtr<CMyTestSubClass> ts4(new CMyTestSubClass);  
    ts4->Print();  
    ts4->SubShow();  
    ts4->Show();  
    TSmartPtr<CMyTestSubClass> ts5(ts4);  
    ts5->SubShow();  
    TSmartPtr<CMyTestSubClass> ts6 = ts5;  
    ts6->Print();  
    //�������һ�´��м̳й�ϵ����ָ����������ָ��ʹ�á����Խ��Ҳ����ȷ�ġ�  
 
    system("pause");  
    return 0;  
} 
