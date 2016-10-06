
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int t, l, i;
    char str[31];
   	cin >> t;
    while(t--)
   	{
    	cin >> str;
    	int n = strlen(str);
    	for(l=0,i=1; i<n; ++i)
    	{
    	    if(str[i] != str[l])
    	    {
    	        ++l;
    	        str[l] = str[i];    	        
    	    }
    	}
    	str[l+1] = '\0';
    	cout<<str<<endl;
   	}
   	
    return 0;
}