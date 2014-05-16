/******************************************************************************
*  author: yanenquan
*  version: 1.0
*  description: 委托模式
*  date: 2014-05-16
*  other: 无
******************************************************************************/

#include<iostream>

using namespace std;

class PrinterDelegate {
  public:
	virtual ~ PrinterDelegate() {
	} // why virtual function , see Effective c++ Item 7.
	
	virtual void print() = 0;
};

class RealPrinter:public PrinterDelegate {	// the "delegate"
  public:
	void print() {
		cout<<"Real Printer"<<endl;
	}
};

class Printer {
  public:
	Printer():delegate(new RealPrinter) {} 
	
	void print() {
		if (NULL != delegate) {
			delegate->print();
		}
	}
	
	~Printer() {
		if (NULL != delegate) {
			delete delegate;
			delegate = NULL;
		}
	}
	
  private:
	PrinterDelegate * delegate;
};

int main()
{
	Printer *p = new Printer;
	p->print();					//client don’t know the exists of delegate class
	delete p;
}
