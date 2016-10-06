
#include<cstdio>
#include<iostream>
#define MAX 100010

using namespace std;

int ft[26][MAX];

void update(int n, int idx, char ch, int val)
{
	for(;idx <= n; idx += (idx&-idx))
		ft[ch-97][idx] += val;
}

bool checkPalindrome(int l, int r)
{
	int n = r - (l-1);
	int sum1[26] = {0}, sum2[26] = {0};
	
	for(; r; r -= r&-r)
	{
		for(int i=0; i<26; ++i)
			sum1[i] += ft[i][r];
	}
	
	if(l > 1)
	{
		--l;
		for(; l; l -= l&-l)
		{
			for(int i=0; i<26; ++i)
				sum2[i] += ft[i][l];
		}
	}
	
	// check if palindrome or not
	int cntOdd = 0;
	for(int i=0; i<26; ++i)
	{
		int diff = sum1[i] - sum2[i];   // diff for every character
		if(diff%2 != 0)
			++cntOdd;					
	}
	
	if(cntOdd <= 1)
		return true;	
	else
		return false;
}

int main()
{
	int n, q;
	string a;
	
	scanf("%d %d", &n, &q);
	cin >> a;
		
	for(int i=0; i<n; ++i)
		update(n, i+1, a[i], 1);
	
	while(q--)
	{
		int type, index, l, r;
		char ch;
		scanf("%d", &type);
		switch(type)
		{
			case 1: 
				scanf("%d %c", &index, &ch);
				update(n, index, a[index-1], -1);
				update(n, index, ch, 1);		
				a[index-1] = ch;
				break;
			case 2:
				scanf("%d %d", &l, &r);
				(checkPalindrome(l, r) ? printf("yes\n") : printf("no\n"));				
				break;
		}
	}
	
	return 0;
}

