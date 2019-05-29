#pragma once
#include "Node.h"

class Operator : public Node
{
private:

protected:
	Node* m_ptr_left;
	Node* m_ptr_right;

	virtual bool GetResult() =0;
};