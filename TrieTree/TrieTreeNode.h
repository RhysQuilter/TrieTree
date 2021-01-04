#pragma once
#include "TrieTreeEntry.h"
#pragma once

const int LETTERS = 26;
struct Trienode
{
	Trienode* branch[LETTERS];
	EntryType* ref;
};