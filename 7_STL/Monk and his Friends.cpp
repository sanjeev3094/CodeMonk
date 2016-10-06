#include <iostream>
#include <set>

using namespace std;
typedef long long ll;
#define MAX 100000

int main() 
{
	int t, n, m;	
	cin >> t;
	
	while(t--)
	{		
		cin >> n >> m;
		
		set<ll> candySet;
		set<ll>::iterator it;
		ll candy;
		for(int i=0; i<n; ++i) 
		{ 
			cin >> candy;  
			candySet.insert(candy);
		}
		for(int i=0; i<m; ++i) 
		{ 
			cin >> candy;
			it = candySet.find(candy);
			if(it != candySet.end())
				cout << "YES\n";
			else
			{
				cout << "NO\n";
				candySet.insert(candy);
			}
		}
	}
	
	return 0;
}