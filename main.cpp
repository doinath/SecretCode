#include "linkedlist.h"
int main(int argc, char** argv) {
	
	list* l = new linkedlist();
	l->addNum(9);
	l->print();
	l->addNum(1);
	l->addNum(2);
	l->addNum(3);
	l->addNum(4);
	l->print();
	l->removeTail();
	l->print();
	l->removeHead();
	l->print();
	l->flip();
	l->print();
	l->addNum(69);
	l->print();
	
	delete l;
}
