
#include<iostream>
#include<stack>

using namespace std;

int main()
{
	int q,cost,qType;
	
	cin >> q;
	stack<int> s;
	
	while(q--)
	{
		cin >> qType;
		switch(qType)
		{
			case 1:
					if(s.empty())
						cout << "No Food\n";
					else
					{
						cout << s.top() << endl;
						s.pop();
					}
					break;
			case 2:
					cin >> cost;
					s.push(cost);					
		}
	}
	
	return 0;
}