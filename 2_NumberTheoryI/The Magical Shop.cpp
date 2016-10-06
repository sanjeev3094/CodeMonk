
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	long long a, b, total = 0;
	char visit[100001];
	
	cin >> a >> b;
	cin >> visit;
	int l = strlen(visit);
	for(int i=0; i<l; ++i)
	{
		if(visit[i] == '1')
			total = (total%b + a%b)%b;
		
		a = ((a%b)*(a%b)) % b;
	}
	
	cout<<total<<endl;
	
	return 0;
}