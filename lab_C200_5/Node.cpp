#include "Node.h"

Node::Node():pPrev(nullptr),pNext(nullptr){}

Node::Node(const Circle& data):pPrev(nullptr),pNext(nullptr),m_Data(data) {}

Node::~Node()
{
    if (pNext)
        pNext->pPrev = pPrev;
    if (pPrev)
        pPrev->pNext = pNext;
}
