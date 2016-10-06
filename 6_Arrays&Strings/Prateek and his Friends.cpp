
#include<iostream>
#define MAX 1000000
using namespace std;

int main()
{
    int t, n, i, l, sum, X;
    int a[MAX];
    bool flag;
    cin>>t;
    while(t--)
    {
        cin>>n>>X;
        for(i=0; i<n; ++i)
            cin>>a[i];
        for(flag=false,sum=0,l=0,i=0; i<n;)
        {
        	if(sum < X)
        	{
        		sum += a[i];         		
        	}
            else if(sum > X)
            {
                sum -= a[l];
                ++l;
            }
            
            if(sum == X)
            {
                flag = true;
                break;
            }
            else if(sum < X)
                ++i;
        }
        
        (flag == true) ? cout<<"YES\n" : cout<<"NO\n";
    }

    return 0;
}