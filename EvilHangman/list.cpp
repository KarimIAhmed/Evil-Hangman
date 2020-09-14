#include <fstream>
#include <cstdlib>
#include <iostream>
#include <random>
#include <time.h>
#include "list.h"

using namespace std;

list::list(string file) {
	ifstream inputFile;
	inputFile.open(file);

	size_t count;
	inputFile >> count;

	firstNode = NULL;
	for (int i = 0; i < count; i++) {
		string word;
		inputFile >> word;
		node* new_node = new node(word, firstNode);
		firstNode = new_node;
		mlength++;

	}
}

list::~list() {
	node* p = firstNode;
	while (p != NULL) {
		node* q = p->next();
		delete p;
		p = q;
	}
}

string list::word() {

	//srand(time(NULL));

	assert(firstNode != NULL);
	srand((unsigned)time(0));
	int n = rand() % length();
	node* p = firstNode;
	for (int o = 0; o < n; o++) {
		p = p->next();
	}
	return p->word();
}


bool list::split(char guess) {
	list* lists[64];

	for (int i = 0; i < 64; i++) {
		lists[i] = new list();
	}

	while (firstNode != NULL) {
		node *q = firstNode;
		firstNode = firstNode->next();
		q->update_mask(guess);
		int index = q->get_mask(guess);
		q->set_next(lists[index]->first());
		lists[index]->firstNode = q;
		lists[index]->mlength++;
	}

	int best = 0;
	for (int i = 1; i < 64; i++) {
		if (lists[i]->length() > lists[best]->length()) {
			best = i;
		}
	}

	for (int i = 0; i < 64; i++) {
		if (i != best) {
			delete lists[i];
			lists[i] = NULL;
		}
	}
	firstNode = lists[best]->first();
	mlength = lists[best]->length();

	return (firstNode->mask().find(guess) != string::npos);
}