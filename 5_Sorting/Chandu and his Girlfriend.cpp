#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct greater1
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

int main() 
{
	int t, n, i, x;
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		vector<int> a;
		for(i=0; i<n; ++i) { cin >> x; a.push_back(x); }
		
		sort(a.begin(), a.end(), greater1());
		
		for(i=0; i<n; ++i) cout << a[i] << " ";
		cout << endl;
	}
	
	return 0;
}



