// LinkedList.cpp
// Michael Bullinger
// September 24, 2017

#include "LinkedList.h"

#include <utility>


List::List()
	: first_(NULL)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}


const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}

	return *this;
}


bool List::empty() const
{
	return first_ == NULL;
}


void List::insertAsFirst(double x)
{
	first_ = new Node(x, first_);
}


double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;
}

//Added the getSize function in order to check the size of the list
int List::getSize()
{
	int size = 0;
	Node * tempPtr = first_;
	while (tempPtr != NULL)
	{
		size++;
		tempPtr = tempPtr->next_;
	}
	return size;
}

//Added the sum function in order to take all the numbers in the list and add them together
double List::sum()
{
	double sum = 0;
	Node * tempPtr = first_;
	while (tempPtr != NULL)
	{
		sum = sum + tempPtr->entry_;
		tempPtr = tempPtr->next_;
	}
	return sum;
}

//Added the insertAsLast function in order to insert a new item on a list and put it at the end of the list
void List::insertAsLast(double x)
{
	Node * tempPtr = first_;
	if (tempPtr == NULL)
	{
		first_ = new Node(x, first_);
	}
	else
	{
		while (tempPtr->next_ != NULL)
		{
			tempPtr = tempPtr->next_;

		}
		Node * temp = new Node(x, NULL);
		tempPtr->next_ = temp;

	}
}



void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}


// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}

