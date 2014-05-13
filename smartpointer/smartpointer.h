/******************************************************************************
*  author: yanenquan
*  version: 1.0
*  description: 智能指针
*  date: 2014-03-16
*  other: 无
******************************************************************************/

#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

template <class T>  
class TSmartPtr  
{  

	private:  
	    
	    T* m_pTObject;  
	    int* m_pCount; 
		
		//引用计数减1  
	    void DoDecUseCount(void)  
	    {  
	        if (0 == --*m_pCount)  
	        {  
	            if (NULL != m_pTObject)  
	            {  
	                delete m_pTObject;  
	                m_pTObject = NULL;  
	            }  
	            delete m_pCount;  
	            m_pCount = NULL;  
	        }  
	    }   
    
	public:  
	    //默认构造函数  
	    TSmartPtr(T* pTObject = NULL) : m_pTObject(pTObject), m_pCount(new int(1)) {}  
	    
	    //拷贝构造函数  
	    TSmartPtr(const TSmartPtr& src) : m_pTObject(src.m_pTObject), m_pCount(src.m_pCount) { ++(*m_pCount); } 
		 
	    //析构函数  
	    virtual ~TSmartPtr()  
	    {  
			#ifdef TEST_SMARTPTR  
			        cout << "SmartPtr Object Free." << endl;  
			#endif  
	        DoDecUseCount();  
	    } 
		 
	    //=重载  
	    TSmartPtr& operator = (const TSmartPtr& rhs)  
	    {  
	        // self-assigning is also right  
	        ++*rhs.m_pCount;    //源智能指针的引用计数增1  
	        DoDecUseCount();    //目标智能指针的引用计数减1。此非常有必要。因为该指针既然要指向rhs，  
	                            //则说明它就不再想去管理自身原本的指针对象了。因此需要减1()  
	                            //在自身引用计数减1后，有可能自身原本维护的指针对象会被释放掉，也有可能不会。  
	                            //(因为，先前所管理的对象，有可能还有其他的智能指针对象在维护着了。)  
	                            //因此，上面这两句才是精髓。  
	        m_pTObject = rhs.m_pTObject;  
	        m_pCount = rhs.m_pCount;  
	        return *this;  
	    } 
		 
	    //->重载  
	    T* operator -> ()  
	    {  
	        if (NULL != m_pTObject)  
	            return m_pTObject;  
	        throw runtime_error("access through NULL pointer");  
	    } 
		 
	    const T* operator -> () const 
	    {  
	        if (NULL != m_pTObject)  
	            return m_pTObject;  
	        throw runtime_error("access through NULL pointr");  
	    }  
	    
	    //*重载  
	    T& operator * ()  
	    {  
	        if (NULL != m_pTObject)  
	            return *m_pTObject;  
	        throw runtime_error("dereference of NULL pointer");  
	    }
		  
	    const T& operator * () const 
	    {  
	        if (NULL != m_pTObject)  
	            return &m_pTObject;  
	        throw runtime_error("dereference of NULL pointer");  
	    }  
};

#endif

