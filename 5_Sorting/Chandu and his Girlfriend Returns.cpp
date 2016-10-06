#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	int t, n, m, i, j, x;
	
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m;
		int a[50000], b[50000];
		for(i=0; i<n; ++i) { cin >> a[i];  }
		for(i=0; i<m; ++i) { cin >> b[i];  }
		
		for(i=0, j=0; i<n && j<m;)
		{
			if(a[i] >= b[j])
			{	cout << a[i] << " "; ++i; }
			else 
			{	cout << b[j] << " "; ++j; }
		}
		
		while(i<n) { cout << a[i]<<" "; ++i; }
		while(j<m) { cout << b[j]<<" "; ++j; }
		cout<<endl;
	}
	
	return 0;
}