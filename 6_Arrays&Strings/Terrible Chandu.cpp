
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int t, l, r;
    char str[31];
   	cin >> t;
    while(t--)
   	{
    	cin >> str;
    	int n = strlen(str);
    	for(l=0,r=n-1; l < r; ++l,--r)
    	{
    	    char tmp = str[l];
    	    str[l] = str[r];
    	    str[r] = tmp;
    	}    	
    	cout<<str<<endl;
   	}
   	
    return 0;
}