#include "Node.h"

Node::Node():pPrev(nullptr),pNext(nullptr){}

Node::Node(Node* prev, const Circle& data):m_Data(data)
{
    pPrev = prev;
    pNext = pPrev->pNext;
    pPrev->pNext = this;
    pNext->pPrev = this;
}

Node::~Node()
{
    if (pNext)
        pNext->pPrev = pPrev;
    if (pPrev)
        pPrev->pNext = pNext;
}

Node* Node::Get_pPrev()const
{
    return pPrev;
}

Node* Node::Get_pNext()const
{
    return pNext;
}

Circle Node::Get_m_Data() const
{
    return m_Data;
}



