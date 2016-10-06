#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() 
{
	int t, n;	
	cin >> t;
	
	while(t--)
	{		
		cin >> n;
		
		set<string> nameSet;
		set<string>::iterator it;
		string name;
		for(int i=0; i<n; ++i) 
		{ 
			cin >> name;  
			it = nameSet.find(name);
			if(it == nameSet.end())
				nameSet.insert(name);			
		}		
		
		for(it=nameSet.begin(); it != nameSet.end(); ++it)
			cout << *it << endl;
	}
	
	return 0;
}