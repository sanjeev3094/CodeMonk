#include <iostream>
#include <cstdio>
using namespace std;

struct Node
{
	char ch;
	int priority;
	struct Node *child[26];
	bool isWord;
	int childPriority;
	struct Node *next;
};

void addToTrie(Node *root, string str, int priority)
{
	int l = str.length();
	struct Node *parent;
	for(int i=0; i<l; ++i)
	{
		int idx = str[i]-97;
		parent = root;
		if(root->child[idx] == NULL)
		{
			struct Node *tmp = (struct Node *)calloc(1, sizeof(Node));	
			tmp->ch = str[i];
			root->child[idx] = tmp;
		}
		
		root = root->child[idx];	
		root->priority = max(root->priority, priority);
		if(parent->childPriority < priority)
		{
			parent->childPriority = priority;
			parent->next = root;
		}
	}
	root->isWord = true;
}

int queryRes(struct Node *root, string str)
{
	int l = str.length();
	for(int i=0; i<l; ++i)
	{
		int idx = str[i]-97;
		if(root->child[idx] == NULL)
			return -1;
		
		root = root->child[idx];
	}
	
	if(root->isWord)
		return root->priority;
	
	return root->childPriority;
}

int main()
{
	int n,q;
    cin >> n >> q;
    
    struct Node *root = (struct Node *)calloc(1, sizeof(struct Node));
    string str;
    int priority;
    
    while(n--)
    {
    	cin>>str;
    	cin>>priority;
    	addToTrie(root, str, priority);
    }
    
    while(q--)
    {
    	cin >> str;
    	cout << queryRes(root, str) << endl;
    }
    return 0;
}
