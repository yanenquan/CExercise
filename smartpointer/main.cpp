/******************************************************************************
*  author: yanenquan
*  version: 1.0
*  description: 智能指针 
*  date: 2014-05-13
*  other: 无
******************************************************************************/

#include <iostream>
#include <string>
#include "runtime_error.h"
#include "smartpointer.h"

using namespace std;  
 
//一个测试智能指针的类  
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
        TSmartPtr<CMyTestClass> t;    //因为没有给t传个CMyTestClass对象的指针参数进去。所以会出异常。  
        t->Print();  
    }  
    catch(const runtime_error& err)  
    {  
        cout << err.get_error_str() << endl;  
    }  
    //上面这个已经测试通过了。结果正确。  
    //--------------------------------------  
    TSmartPtr<CMyTestClass> t1(new CMyTestClass);  
    t1->Print();  
    //上面这个测试->重载的操作符的正确性。测试结果是正确的。  
    TSmartPtr<CMyTestClass> t2(t1);  
    t2->Print();  
    //上面这个测试拷贝构造函数的正确性。测试结果是正确的。  
    TSmartPtr<CMyTestClass> t3(new CMyTestClass);  
    t3 = t2;  
    (*t3).Print();  
    //上面这个测试=重载的操作符的正确性。测试结果也是正确的。  
 
    TSmartPtr<CMyTestSubClass> ts4(new CMyTestSubClass);  
    ts4->Print();  
    ts4->SubShow();  
    ts4->Show();  
    TSmartPtr<CMyTestSubClass> ts5(ts4);  
    ts5->SubShow();  
    TSmartPtr<CMyTestSubClass> ts6 = ts5;  
    ts6->Print();  
    //上面测试一下带有继承关系的类指针对象的智能指针使用。测试结果也是正确的。  
 
    system("pause");  
    return 0;  
} 
