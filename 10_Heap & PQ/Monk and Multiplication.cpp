#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

struct comparator {
 bool operator()(ll i, ll j) {
 return i > j;
 }
};

int main() {
	
	priority_queue<ll, std::vector<ll>, comparator> minPQ;
	ll prod = 1;
	int n, x;
	
	cin >> n;
	for(int i=1; i<=n; ++i)
	{
		cin >> x;
		if(i <= 3)
		{
			minPQ.push(x);
			prod *= x;
		}
		else if(x >= minPQ.top())
		{
			ll v = minPQ.top();
			minPQ.pop();
			minPQ.push(x);
			prod = prod/v * x;
		}
		
		if(minPQ.size() < 3)
			cout << -1 <<endl;
		else
			cout << prod << endl;
		
	}
	
	return 0;
}