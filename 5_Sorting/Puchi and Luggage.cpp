#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int> myMap;
int c[200000];

void modMerge(int a[], int l, int m, int r)
{
	int n = r-l+1, k, i, j;
	
	for(i=m, j=r, k=n-1; i>=l && j>m; )
	{
		if(a[i] > a[j])
		{
			map<int, int>::iterator it = myMap.find(a[i]);			
			it->second += j-m;
			c[k] = a[i];
			--k;--i;
		}
		else
		{
			c[k] = a[j];
			--k;--j;
		}
	}
	
	while(i>=l) { c[k] = a[i]; --i; --k; }	
	while(j>m) {  c[k] = a[j]; --j; --k; }
	
	// copy into the original 
	for(i=0; i<n; ++i)
		a[l+i] = c[i];
}

void modMergeSort(int a[], int l, int r)
{
	if(l >= r)
		return;
	int mid = l + (r-l)/2;
	modMergeSort(a, l, mid);
	modMergeSort(a, mid+1, r);
	modMerge(a, l, mid, r);
}

int main() 
{
	int t, n, m, i, j, x;
	int a[100000], b[100000];
	
	cin >> t;	
	while(t--)
	{
		cin >> n;	
		myMap.clear();
		for(i=0; i<n; ++i) 
		{ 
			cin >> a[i]; 
			myMap[a[i]] = 0;
			b[i] = a[i];
		}
		
		modMergeSort(a, 0, n-1);
		
		for(i=0; i<n; ++i)
		{
			cout<<myMap.find(b[i])->second<<" ";
		}
		
		cout<<endl;
	}
	
	return 0;
}