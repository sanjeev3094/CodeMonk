#include <iostream>
using namespace std;

void initialize(int parent[], int size[], int n)
{
	for(int i=1; i<=n; ++i)
	{
		parent[i] = i;
		size[i] = 1;
	}
}

int findSet(int parent[], int x)
{
	if(parent[x] == x)
		return x;
	return (parent[x] = findSet(parent, parent[x]));	
}

void unionSet(int parent[], int size[], int u, int v)
{
	int rootU = findSet(parent, u);
	int rootV = findSet(parent, v);
	
	if(size[rootU] <= size[rootV])
	{
		parent[rootU] = rootV;
		size[rootV] += size[rootU];
	}
	else
	{
		parent[rootV] = rootU;
		size[rootU] += size[rootV];
	}
}

int main() {
	
	int n, k;
	
	cin>>n;
	int parent[n], size[n];
	
	initialize(parent, size, n);
	cin >> k;
	int cnt = n;
	while(k--)
	{
		int i, j;
		cin >> i >> j;
		if(findSet(parent, i) != findSet(parent, j))
		{
			--cnt;
			unionSet(parent, size, i, j);
		}		
	}
	
	cout << cnt;
	
	return 0;
}