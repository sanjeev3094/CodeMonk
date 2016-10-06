
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int t, a, b, c, k;
	
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> c >> k;
		
		long long lo = 0, hi = 100000, mid, x0 = 0;
		while(lo <= hi)
		{
			long long mid = (lo + hi)/2;
			if(a*mid*mid + b*mid + c >= k)
			{
				x0 = mid;
				hi = mid - 1;
			}
			else
				lo = mid + 1;
		}
		
		cout << x0 <<endl;
	}	

	return 0;
}