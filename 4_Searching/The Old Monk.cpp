#include<iostream>
#include<algorithm>
using namespace std;
 
#define MAX 100000
 
int main()
{
	int i,j,t,n;
	long long int a[MAX], b[MAX];
	
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(i=0; i<n; ++i) cin >> a[i];
		for(i=0; i<n; ++i) cin >> b[i];
		
		int mx = 0;
		for(i=n-1, j=n-1; i>=0 && j>=0; )
		{
			if(a[i] <= b[j])
			{
				mx = max(mx, j-i);
				--i;
			}
			else
				--j;
		}
		
		cout<<mx<<endl;
	}
	
	return 0;
}