#include <iostream>
#include <cstring>
#include <set>
using namespace std;
#define MAX 1000001

int main() {
	
	int t, n, a, b;
	cin >> t;
	while(t--)
	{
			cin >> n;
			int cnt = 0;			
			int p[MAX];
			memset(p, 0, sizeof(p));
			for(int i=1; i<=n; ++i)
			{
				cin >> a >> b;
				p[a]++;
				if(p[b] >= 1)
					p[b]--;
				else
					++cnt;
			}
			cout << cnt << endl;
	}
	
	return 0;
}