
#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int n,i,x;
	
	cin >> n;
	queue<int> q;
	queue<int> s;
		
	for(i=0; i<n; ++i)
	{
		cin >> x;
		q.push(x);
	}
	for(i=0; i<n; ++i) 
	{	
		cin >> x;
		s.push(x);
	}
	
	int unit = 0;
	while(!s.empty())
	{
		if(s.front() == q.front())
		{
			s.pop();
			q.pop();
		}
		else
		{	
			int f = q.front();
			q.pop();
			q.push(f);
		}
		++unit;
	}
	
	cout<<unit<<endl;
	
	return 0;
}