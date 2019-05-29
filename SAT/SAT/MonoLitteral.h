#pragma once
#include "Node.h"

class MonoLitteral : public Node
{
private:

protected:
	Node* m_ptr_left;
	Node* m_ptr_right;

	virtual bool GetResult() =0;
	void AddNodeLeft(Node& _refNodeLeft);
	void AddNodeRight(Node& _refNodeRight);
};