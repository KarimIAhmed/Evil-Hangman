#pragma once
#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <string>
#include <cassert>


using namespace std;

class list
{
public:
	list() { firstNode = NULL; mlength = 0; }

	list(string file);

	~list();

	bool split(char alpha);

	node* first() { return firstNode; }

	size_t length() { return mlength; }

	string word();

	string mask() {
		assert(firstNode != NULL);
		return firstNode->mask();
	}

	bool is_guessed() {
		assert(firstNode != NULL);
		return firstNode->is_guessed();
	}
private:
	node* firstNode;
	size_t mlength;
};

#endif