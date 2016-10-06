
#include<iostream>
using namespace std;

int main()
{
	int n, x;
	cin >> n;
	
	while(n--)
	{
		cin >> x;
		int cnt = 0;
		
		for(int i=1; i*i <= x; ++i)
		{
			if(x%i == 0)
			{
				if(i == x/i)
					++cnt;
				else
					cnt += 2;
				if(cnt >= 4)
					break;
			}
		}
		if(cnt >= 4)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
	
	
	return 0;
}