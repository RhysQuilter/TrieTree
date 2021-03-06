#pragma once
#include <iostream>
#include "TrieTreeEntry.h"
#include "TrieTreeNode.h"


using namespace std;

typedef char Key[MAXLENGTH];

class TrieType
{
public:
	TrieType();
	~TrieType();
	TrieType(TrieType& originalTree);
	void operator=(TrieType& originalTree);
	void MakeEmpty();
	void InsertTrie(Key newkey, EntryType* newentry);
	EntryType* TrieSearch(Key target);
	bool DeleteTrie(Key delkey);
	void PrintTrie(ostream& outfile) const;
private:
	Trienode* root;
};
EntryType* TrieType::TrieSearch(Key target)
{
	int i;
	Trienode* current = root;
	for (i = 0; i < MAXLENGTH && current; i++)
		if (target[i] == '\0')
			break;
		else
			current = current->branch[target[i] - 'a'];
	if (!current)
		return NULL;
	else
		if (!current->ref)
			return NULL;

	return current->ref;
}
Trienode* CreateNode()
{
	int ch;
	Trienode* newnode = new Trienode;
	for (ch = 0; ch < LETTERS; ch++)
		newnode->branch[ch] = NULL;

	newnode->ref = NULL;

	return newnode;
}
void TrieType::InsertTrie(Key newkey, EntryType* newentry)
{
	int i;
	Trienode* current;
	if (!root)
		root = CreateNode();
	current = root;
	for (i = 0; i < MAXLENGTH; i++)
		if (newkey[i] == '\0')
			break;
		else
		{
			if (!current->branch[newkey[i] - 'a'])
				current->branch[newkey[i] - 'a'] = CreateNode();
			current = current->branch[newkey[i] - 'a'];
		}
	if (current->ref != NULL)
		cout << "\nTried to insert a duplicate key." << endl;
	else
		current->ref = newentry;
}