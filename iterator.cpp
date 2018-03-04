#include "iterator.h"
#include <iostream>
#include <sstream>

#include <string>
#include <stack>
#include <math.h>
using namespace std;

class Base;



OperatorIterator::OperatorIterator(Base* ptr): Iterator(ptr) {};

void OperatorIterator::first() {
	this->current_ptr = this->self_ptr->get_left();
}

void OperatorIterator::next(){
    if(this->current_ptr == this->self_ptr->get_left()) {
        this->current_ptr = this->self_ptr->get_right();
    }
    else if(this->current_ptr == this->self_ptr->get_right()) {
        this->current_ptr = NULL;
    }
}

bool OperatorIterator::is_done(){
    if(this->current_ptr == NULL){
        return true;
    }
    return false;
}
Base* OperatorIterator::current() {
return this->current_ptr;

}


NullIterator::NullIterator(Base* ptr) : Iterator(ptr) {};
void NullIterator::first() {return;}
void NullIterator::next() {return;}
bool NullIterator::is_done() {return true;}
Base* NullIterator::current() {return NULL;}

PreorderIterator::PreorderIterator(Base* ptr) : Iterator(ptr) {};

void PreorderIterator::first() {
    // Empty the stack (just in case we had something leftover from another run)
    // Create an iterator for the Base* that we built the iterator for
    // Initialize that iterator and push it onto the stack
    if(!iterators.empty())
   {
       while(!iterators.empty())
       {
          iterators.pop();
       }
   }
   Iterator* temp = this->self_ptr->create_iterator();
   temp->first();
   iterators.push(temp);
   return;
}

void PreorderIterator::next() {
    // Create an iterator for the item on the top of the stack
    // Initialize the iterator and push it onto the stack
    // As long as the top iterator on the stack is_done(), pop it off the stack and then advance whatever iterator is now on top of the stack
	Iterator* temp  = this->iterators.top()->current()->create_iterator();
    temp->first();
    this->iterators.push(temp);
    while(this->iterators.size() > 0 && this->iterators.top()->is_done())
    {
       this-> iterators.pop();
        if(!iterators.empty())
        {
            this->iterators.top()->next();
        }
    }

}

bool PreorderIterator::is_done() {
    // Return true if there are no more elements on the stack to iterate
	if(iterators.empty()) {
	return true;
}
return false;

}

Base* PreorderIterator::current() {
    // Return the current for the top iterator in the stack
	if(this->iterators.size() > 0) {
		return iterators.top()->current();
}
	else {
		return NULL;
}

}


UnaryIterator::UnaryIterator(Base* ptr) : Iterator(ptr) {};

void UnaryIterator::first() {
this->current_ptr = this->self_ptr->get_left();
}

void UnaryIterator::next() {
    if(this->current_ptr == this->self_ptr->get_left()){
        this->current_ptr = NULL;
    }
}

bool UnaryIterator::is_done() {
    if(this->current_ptr == NULL) {
        return true;
    }
    return false;
}
Base* UnaryIterator::current() {
return this->current_ptr;
}

