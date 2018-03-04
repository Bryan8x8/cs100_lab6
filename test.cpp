#include <iostream>
#include <vector>
#include "composite.h"

using namespace std;

int main() {

	Op* op3 = new Op(3);
	Op* op4 = new Op(4);
	Op* op2 = new Op(2);
	Add* add = new Add(op3, op4);
	Sqr* sqr = new Sqr(op2);
	Sub* sub = new Sub(add, sqr);
	Root* root = new Root(sub);

	cout << "--- PreOrder Iteration ---" << endl;
	PreorderIterator* pre_itr = new PreorderIterator(root);
	for(pre_itr->first(); !pre_itr->is_done(); pre_itr->next()) {
		pre_itr->current()->print();
		cout << endl;
	}
Op* op1 = new Op(5);
	Op* op0 = new Op(10);
	Op* op5 = new Op(2);
	Op* op6 = new Op(1);
	Mult* multiply = new Mult(op1, op5);
	Sub* Subtract = new Sub(multiply, op0);
	Add* addition = new Add(Subtract, op6);
	Root* r = new Root(addition);
	cout << "Second test" << endl;
	PreorderIterator* temp = new PreorderIterator(r);
	for(temp->first(); !temp->is_done(); temp->next())
	{
		temp->current()->print();
		cout << endl;
	}
};
