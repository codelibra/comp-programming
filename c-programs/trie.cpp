//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
struct Node
{
	int count;
	Node* children[26];
	Node()
	{
		count=0;
		for(int i=0;i<26;++i)
		children[i]=NULL;
	}
};

struct Trie
{
	int counter;
	Node *root;
	Trie()
	{
		counter=0;
		root=new Node();
	}
};

void insert(Trie *t,string &str)
{
	t->counter+=1;
	Node *temp=t->root;
	for(int i=0;i<str.length();++i)
	{
		int index=str[i]-'a';
		if(temp->children[index]==NULL)
		{
			temp->children[index]=new Node();
		}
		temp=temp->children[index];
	}
	temp->count+=t->counter;
}

bool search(Trie *t,string &str)
{
	Node *temp=t->root;
	for(int i=0;i<str.length();++i)
	{
		int index=str[i]-'a';
		if(temp->children[index]==NULL)
		{
			return 0;
		}
		temp=temp->children[index];
	}
	if(temp==NULL || temp->count==0)
	return 0;
	else
	return 1;
}

int main()
{
	Trie t;
	vector<string> vi;
	vi.push_back("shivi");vi.push_back("noopur");
	vi.push_back("spandy");vi.push_back("soumy");
	
	for(int i=0;i<vi.size();++i)
	insert(&t,vi[i]);
	
	string str;
	while(1)
	{
		cin>>str;
		if(str=="exit") break;
		if(search(&t,str))
		cout<<"Found!!!!\n";
		else
		cout<<"Not Found!!\n";
	}
}
