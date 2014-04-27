#include <iostream>
using namespace std;

template<class Type>
void permute(Type a[], int start, int end)
{
    if(start == end)
    {
        for(int i = 0; i <= end; ++i)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        for(int i = start; i <= end; ++i)
        {
            swap(a[i],a[start]);
            permute(a,start+1,end);
            swap(a[i],a[start]);
        }
    }
}

template<class Type>
void combine(Type a[], bool b[], int start, int end)
{
    if(start > end)
    {
        for(int i = 0; i <= end; ++i)
        {
            if(b[i])
                cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        b[start] = true;
        combine(a,b,start+1,end);
        b[start] = false;
        combine(a,b,start+1,end);
    }
}

int main()
{
    int p[3]={1,2,3};
    int N = 3;
    cout<<"permute:"<<endl;
    permute(p,0,N-1);
	
    cout<<"combine:"<<endl;
    bool b[3];
    combine(p,b,0,N-1);

    return 0;
}
