
#include<cstdio>
#include<iostream>
#define MAX 200010

using namespace std;

int ft[MAX];

inline bool idRoundNumber(long long n)
{
	if(n < 0)
		return false;
	
	int lastDigit = n%10; 
	for(;n>9;n/=10);

	return (n == lastDigit) ? true : false;
}

void update(int n, int idx, int val)
{
	for(;idx <= n; idx += (idx&-idx))
		ft[idx] += val;
}

int getSum(int idx)
{
	int sum = 0;
	for(;idx; idx -= (idx&-idx))
		sum += ft[idx];
	
	return sum;
}

int main()
{
	int n, q;
	bool a[MAX];
	long long m;

	scanf("%d %d", &n, &q);

	for(int i=0; i<n; ++i)
	{
		scanf("%lld", &m);
		a[i] = idRoundNumber(m);
		update(n, i+1, a[i]);
	}
	
	while(q--)
	{
		int type, index, l, r, ans;
		bool v;
		
		scanf("%d", &type);
		switch(type)
		{
			case 1:
				scanf("%d %d", &l, &r);
				ans = getSum(r) - ((l > 1) ? getSum(l-1) : 0);			
				printf("%d\n", ans);
				break;
			case 2: 
				scanf("%d %lld", &index, &m);
				v = idRoundNumber(m);
				if(a[index-1]  == 1 && v == 0)
					update(n, index, -1);
				if(a[index-1] == 0 && v == 1)
					update(n, index, 1);		
				a[index-1] = v;
		}
	}
	
	return 0;
}

