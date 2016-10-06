#include <iostream>
using namespace std;

int main()
{
	int n, sod = 0, deg;
    cin >> n;
    for(int i=0; i<n; ++i){ cin >> deg; sod += deg; }
    if(sod > 2*(n-1))
    	cout << "No\n";
    else
    	cout << "Yes\n";
    	
    return 0;
}
