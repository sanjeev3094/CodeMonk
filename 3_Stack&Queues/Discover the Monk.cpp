
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int x, n, q, a[100000];
	cin >> n >> q;
	for(int i=0;i<n; ++i) cin>>a[i];
	
	sort(a, a+n);
	
	for(int i=0; i<q; ++i)
	{
		cin >> x;
		int lo, hi, mid;
		lo = 0;
		hi = n-1;
		bool isPresent = false;
		while(lo <= hi)
		{
			mid = (lo + hi)/2;
			
			if(a[mid] == x)
			{
				isPresent = true;
				break;
			}
			else if(a[mid] > x)
				hi = mid - 1;
			else
				lo = mid + 1;
		}
		
		if(isPresent)
			cout << "YES" << endl;
		else
			cout<<"NO"<<endl;
	}
	
	return 0;
}