
#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 100000

bool isPossible(int pos[], int n, int k, int en)
{
	int i, cnt = 1, monkPos = pos[0] + en;
	for(i=0; i<n; )
	{
		if(abs(pos[i] - monkPos) <= en)
			++i;
		else if(cnt < k)
		{
			monkPos = pos[i] + en;
			++cnt;
		}
		else
			break;
	}
	if(i != n)
		return false;
		
	return true;
}

int main()
{
	int n, k, pos[100000];
	cin >> n >> k;
	for(int i=0;i<n; ++i) cin>>pos[i];
	sort(pos, pos+n);
	int lo, hi, mid, en = 0;
	lo = 0;
	hi = pos[n-1];
	while(lo <= hi)
	{
		mid = (lo + hi)/2;
		
		if(isPossible(pos,n,k,mid))
		{
			en = mid;
			hi = mid-1;
		}
		else
			lo = mid + 1;
	}
	
	cout << en << endl;
	
	return 0;
}