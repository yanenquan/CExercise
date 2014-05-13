/******************************************************************************
*  author: yanenquan
*  version: 1.0
*  description: ����ָ��
*  date: 2014-03-16
*  other: ��
******************************************************************************/

#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

template <class T>  
class TSmartPtr  
{  

	private:  
	    
	    T* m_pTObject;  
	    int* m_pCount; 
		
		//���ü�����1  
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
	    //Ĭ�Ϲ��캯��  
	    TSmartPtr(T* pTObject = NULL) : m_pTObject(pTObject), m_pCount(new int(1)) {}  
	    
	    //�������캯��  
	    TSmartPtr(const TSmartPtr& src) : m_pTObject(src.m_pTObject), m_pCount(src.m_pCount) { ++(*m_pCount); } 
		 
	    //��������  
	    virtual ~TSmartPtr()  
	    {  
			#ifdef TEST_SMARTPTR  
			        cout << "SmartPtr Object Free." << endl;  
			#endif  
	        DoDecUseCount();  
	    } 
		 
	    //=����  
	    TSmartPtr& operator = (const TSmartPtr& rhs)  
	    {  
	        // self-assigning is also right  
	        ++*rhs.m_pCount;    //Դ����ָ������ü�����1  
	        DoDecUseCount();    //Ŀ������ָ������ü�����1���˷ǳ��б�Ҫ����Ϊ��ָ���ȻҪָ��rhs��  
	                            //��˵�����Ͳ�����ȥ��������ԭ����ָ������ˡ������Ҫ��1()  
	                            //���������ü�����1���п�������ԭ��ά����ָ�����ᱻ�ͷŵ���Ҳ�п��ܲ��ᡣ  
	                            //(��Ϊ����ǰ������Ķ����п��ܻ�������������ָ�������ά�����ˡ�)  
	                            //��ˣ�������������Ǿ��衣  
	        m_pTObject = rhs.m_pTObject;  
	        m_pCount = rhs.m_pCount;  
	        return *this;  
	    } 
		 
	    //->����  
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
	    
	    //*����  
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

