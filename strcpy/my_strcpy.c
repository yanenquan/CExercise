#include <stdio.h>
#include <assert.h>

void * my_memcpy(void *dst,const void *src,unsigned int count)
{
     assert(dst);
     assert(src);
     void * ret = dst;
     if (dst <= src || (char *)dst >= ((char *)src + count))//源地址和目的地址不重叠，低字节向高字节拷贝
	 {
		 while(count--)
		 {
			 *(char *)dst = *(char *)src;
			 dst = (char *)dst + 1;
			 src = (char *)src + 1;
		 }
	 }
	 else //源地址和目的地址重叠，高字节向低字节拷贝
	 { 
		 dst = (char *)dst + count - 1;
		 src = (char *)src + count - 1; 
		 while(count--) 
		 {
			 *(char *)dst = *(char *)src;
			 dst = (char *)dst - 1;
			 src = (char *)src - 1;
		 }
    }
	return ret;
}

char *my_strcpy(char *dst,const char *src)
{
	assert(dst != NULL);
	assert(src != NULL);
	char *ret = dst;
	while((* dst++ = * src++) != '\0') 
		;
	return ret;
}


int main()
{
	char dest[10] = "";
	char *src = "hello";
	printf("%s\n",my_strcpy(dest,src));
	return 0;
}
