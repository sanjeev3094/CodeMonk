
#include<iostream>
using namespace std;
#define MAX 1000000007

int gcd(int a, int b)
{
	return ((b==0) ? a : gcd(b, a%b));
}

int exp(int a, int n)
{
	if(n == 0)
		return 1;
	if(n == 1)
		return a;
	long long v = exp(a,n/2);
	long long v2 = (v * v) % MAX;
	if(n%2 == 0)
		return v2;
	else
		return (a*v2)%MAX;
}

int main()
{
	int n, dupN, a[50], dupA[50], g[50], cnt;
	cin >> n;
	dupN = n;
	for(int i=0; i<n; ++i) 
	{	
		cin >> a[i];
		dupA[i] = a[i];
	}
	
	do
	{
		cnt = 0;
		for(int i=0; i<n; i+=2)
		{
			if(i+1 < n)
			{
				if(a[i] >= a[i+1])
					g[cnt++] = gcd(a[i], a[i+1]);
				else
					g[cnt++] = gcd(a[i+1], a[i]);
			}
			else
				g[cnt++] = a[i];
		}
		for(int i=0; i<cnt; ++i)
			a[i] = g[i];
			
		n = cnt;
	}while(n > 1);
	
	long long finalVal = 1;
	for(int i=0; i<dupN; ++i)
	{
		int ai = exp(dupA[i], g[0]);
		finalVal = (finalVal*ai)%MAX;
	}
	
	cout << finalVal <<endl;
		
	return 0;
}