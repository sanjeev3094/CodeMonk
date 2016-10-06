#include<iostream>
#include<set>
using namespace std;

int main()
{
    int t,e,x,y;
    cin >> t;
    while(t--)
    {
        set<int> citySet;
        set<int>:: iterator it;
        cin >> e;
        while(e--)
        {
            cin >> x >> y;
            it = citySet.find(x);
            if(it == citySet.end())
                citySet.insert(x);
            it = citySet.find(y);
            if(it == citySet.end())
                citySet.insert(y);
        }

        cout << citySet.size() << endl;
    }

    return 0;
}

