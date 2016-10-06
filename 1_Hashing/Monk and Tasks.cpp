#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100000

int count1s(int x)
{
	int cnt;
	for(cnt = 0; x != 0; ++cnt, x=(x&(x-1)));
	
	return cnt;
}

int main() {
	
	int t, n;
	int b[MAX], c[100];
	long long a[MAX], out[MAX];
	
	cin >> t;
	while(t--)
	{
			cin >> n;
			memset(c, 0, sizeof(c));
			int max = 0;
			
			// count sort
			for(int i=0; i<n; ++i) 
			{  
				cin >> a[i];
				b[i] = count1s(a[i]);
				if(b[i] > max)
					max = b[i];
				c[b[i]]++;
			}
			
			for(int i=1; i<=max; ++i)
				c[i] = c[i] + c[i-1];
			
			for(int i=n-1; i>=0; --i)
			{
				out[c[b[i]]-1] = a[i];
				c[b[i]]--;
			}
			
			for(int i=0; i<n; ++i)
				cout << out[i] << " ";
			cout << endl;
	}
	
	return 0;
}