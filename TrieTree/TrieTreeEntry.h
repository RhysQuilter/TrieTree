
#pragma once
#include <iostream>

using namespace std;
const int MAXLENGTH = 10;
class EntryType
{
public:
	EntryType();
	EntryType(char* key);
	EntryType(EntryType& entry);
	friend istream& operator>> (istream& is, EntryType& item);
	friend ostream& operator<< (ostream& os, EntryType item);
	bool operator== (const EntryType& item) const;
	bool operator!= (const EntryType& item) const;
private:
	char entryKey[MAXLENGTH];
};