#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

int main() 
{
	int t, n, k;	
	cin >> t;
	
	while(t--)
	{		
		cin >> n >> k;
		
		priority_queue<ll> maxPQ;
		ll num;
		for(int i=0; i<n; ++i) 
		{ 
			cin >> num;  
			maxPQ.push(num);			
		}		
		
		ll tot = 0;
		for(int i=1; i<=k; ++i)
		{
			ll val = maxPQ.top();
			maxPQ.pop();
			tot += val;
			maxPQ.push(val/2);
		}
		
		cout << tot <<endl;
	}
	
	return 0;
}