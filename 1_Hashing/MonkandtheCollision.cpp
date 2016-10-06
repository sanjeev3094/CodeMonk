#include <iostream>
using namespace std;

int main() {
	
	int t, n, x;
	cin >> t;
	while(t--)
	{
			cin >> n;
			int cnt = 0;
			bool isPresent[10] = { false };
			
			for(int i=1; i<=n; ++i)
			{
				cin >> x;
				int lastDigit = x % 10;
				if(isPresent[lastDigit])
					++cnt;
				else
					isPresent[lastDigit] = true;
			}
			cout << cnt << endl;
	}
	
	return 0;
}
