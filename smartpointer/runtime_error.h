/******************************************************************************
*  author: yanenquan
*  version: 1.0
*  description: 智能指针
*  date: 2014-05-13
*  other: 无
******************************************************************************/

#ifndef RUNTIME_ERROR_H
#define RUNTIME_ERROR_H

class runtime_error
{
	private:
		std::string error_str;
	
	public:
		runtime_error(const char* error_str):error_str(error_str){}
		
		~runtime_error(){}
		
		const std::string& get_error_str() const
		{
			return this->error_str;
		}		
};

#endif
