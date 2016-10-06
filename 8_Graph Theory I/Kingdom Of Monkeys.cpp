
#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100001

typedef long long ll;
int parent[MAX];

void makeSet(int n)
{
	for(int i=1; i<=n; ++i)
		parent[i] = i;
}

int findSet(int x)
{
	if(parent[x] == x)
		return x;
	return (parent[x] = findSet(parent[x]));
}

void unionSet(int x, int y)
{
	int py = findSet(y);
	int px = findSet(x);
	parent[py] = px;
}

int main()
{
	int t, n, m, p, q;
	
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		makeSet(n);
		for(int i=1; i<=m; ++i)
		{
			cin >> p >> q;
			unionSet(p, q);			
		}
		ll sum[MAX], ban;
		memset(sum, 0, sizeof(sum));
		for(int i=1; i<=n; ++i)
		{
			cin >> ban;
			int fs = findSet(i);
			sum[fs] += ban;
		}
		ll mx = sum[1];
		for(int i=2; i<=n; ++i)
		{
			if(mx < sum[i])
				mx = sum[i];
		}
		
		cout << mx << endl;
	}
		
	return 0;
}