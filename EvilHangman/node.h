#pragma once
#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class node {
public:
	node(string target, node* next);

	void update_mask(char letter);

	void set_next(node* next) // TODO: Implement this method inline
	{
		nextNode = next;
	}

	string word() const { return mWord; }
	string mask() const { return mMask; }
	node* next() const  { return nextNode;}

	int get_mask(char letter) const;

	bool is_guessed() const { return mWord == mMask; }

private:
	string mWord;
	string mMask;
	node* nextNode;
};

#endif