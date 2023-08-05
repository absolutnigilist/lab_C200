#include "List.h"

List::List() :m_size(0)
{
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
};

List::~List()
{
	while (Head.pNext != &Tail)
	{
		delete Head.pNext;
	}
}
List::List(const List& other) :m_size(other.m_size)
{

	Head.pNext = &Tail;
	Tail.pPrev = &Head;

	Node* pThis = &Head;
	Node* pOther = other.Head.pNext;
	while (pOther != &other.Tail)
	{
		pThis->pNext = new Node(pThis, pOther->m_Data);
		pOther = pOther->pNext;
		pThis = pThis->pNext;

	}
}
List::List(List&& other) :m_size(other.m_size)
{

	if (other.m_size == 0)
	{
		Head.pNext = &Tail;
		Tail.pPrev = &Head;
	}
	else
	{
		Head.pNext = other.Head.pNext;
		Head.pNext->pPrev = &Head;
		Tail.pPrev = other.Tail.pPrev;
		Tail.pPrev->pNext = &Tail;

		other.Head.pNext = &other.Tail;
		other.Tail.pPrev = &other.Head;
		other.m_size = 0;
	}
}

//List& List::operator=(const List& other)
//{
//	/*if (this!=&other)
//	{
//		MakeEmpty();
//		Node* current = other.Head.pNext;
//		while (current!=&other.Tail)
//		{
//			AddLast(current->m_Data);
//			current = current->pNext;
//		}
//	}
//	return *this;
//	*/
//	
//	if (this!=&other)									//альтерантива
//	{
//		Node* pThis = Head.pNext;
//		Node* pOther = other.Head.pNext;
//
//		if (m_size==other.m_size)
//		{
//			while (pOther!=&other.Tail)
//			{
//				pThis->m_Data = pOther->m_Data;
//				pThis = pThis->pNext;
//				pOther = pOther->pNext;
//			}
//		}
//		else if (m_size>other.m_size)
//		{
//			while (pOther != &other.Tail)
//			{
//				pThis->m_Data = pOther->m_Data;
//				pThis = pThis->pNext;
//				pOther = pOther->pNext;
//			}
//	
//			while (pThis!=&Tail)
//			{
//				
//				Node* tmp = pThis->pNext;
//				delete pThis;
//				pThis = tmp;
//			}
//		}
//		else //(m_size<other.m_size)
//		{
//			while (pThis!=&Tail)
//			{
//				pThis->m_Data = pOther->m_Data;
//				pThis = pThis->pNext;
//				pOther = pOther->pNext;
//			}	
//			
//			while (pOther!=&other.Tail)
//			{
//				AddLast(pOther->m_Data);
//				pOther = pOther->pNext;
//			}
//		}
//	}
//	return *this;
//}
List& List::operator=(const List& other) {

	if (this != &other)
	{
		size_t size = (m_size < other.m_size) ? m_size : other.m_size;
		Node* pThis = Head.pNext;
		Node* pOther = other.Head.pNext;
		for (size_t i = 0; i < size; i++)
		{
			pThis->m_Data = pOther->m_Data;
			pThis = pThis->pNext;
			pOther = pOther->pNext;
		}
		for (size_t i = other.m_size; i < m_size; i++)
		{
			delete Tail.pPrev;
		}
		for (size_t i = m_size; i < other.m_size; i++)
		{
			AddLast(pOther->m_Data);
			pOther = pOther->pNext;
		}
		m_size = other.m_size;
	}
	return *this;
}

List& List::operator=(List&& other)
{
	if (this != &other)
	{
		MakeEmpty();
		Head.pNext = other.Head.pNext;
		Tail.pPrev = other.Tail.pPrev;
		Head.pNext->pPrev = &Head;
		Tail.pPrev->pNext = &Tail;
		m_size = other.m_size;

		other.Head.pNext = &other.Tail;
		other.Tail.pPrev = &other.Head;
		other.m_size = 0;
	}
	return *this;
};

void List::AddFirst(const Circle& data)
{
	Node* NewNode = new Node(&Head, data);
	m_size++;
};

void List::AddLast(const Circle& data)
{
	Node* NewNode = new Node(Tail.pPrev, data);
	m_size++;
};

bool List::RemoveFirst(const Circle& data)
{
	Node* current = Head.pNext;
	while (current != &Tail) {
		if (current->m_Data == data)
		{
			delete current;
			m_size--;
			return true;
		}
		current = current->pNext;
	}
	return false;
};

int List::RemoveAll(const Circle& data)
{
	Node* current = Head.pNext;
	size_t count = 0;
	while (current != &Tail)
	{
		Node* tmp = current->pNext;
		if (current->m_Data == data)
		{
			delete current;
			m_size--;
			count++;
		}
		
		current = tmp;
	}
	return count;
};

void List::MakeEmpty()
{
	Node* current = Head.pNext;
	while (current != &Tail)
	{
		Node* tmp = current->pNext;
		delete current;
		current = tmp;
	}
	m_size = 0;

};

void List::ListSort()
{
	if (m_size <= 1)
		return;

	for (Node* current = Head.pNext; current != &Tail; current = current->pNext)
	{
		for (Node* next = current->pNext; next != &Tail; next = next->pNext)
		{
			if (current->m_Data.GetRadius() > next->m_Data.GetRadius())
			{
				Circle tmp = std::move(current->m_Data);
				current->m_Data = std::move(next->m_Data);
				next->m_Data = std::move(tmp);
			}
		}
	}
}

void List::WriteToFile(const std::string& filename)
{
	std::ofstream output_File(filename);
	if (output_File.is_open())
	{
		output_File << *this;
		/*Node* current = Head.pNext;
		while (current != &Tail)
		{
			output_File << current->m_Data << std::endl;
			current = current->pNext;
		}*/
		output_File.close();
		std::cout << "List written to file successfully." << std::endl;
	}
	else
	{
		std::cout << "Unable to open the file." << std::endl;
	}
}

void List::ReadFromFile(const std::string& filename)
{
	std::ifstream input_File(filename);
	if (input_File.is_open())
	{
		MakeEmpty();
		Circle tmp;
		while (input_File >> tmp)
		{
			AddLast(tmp);
		}
		input_File.close();
		std::cout << "List read from file successfully." << std::endl;
	}
	else
	{
		std::cout << "Unable to open the file." << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const List& other)
{
	Node* current = other.Head.Get_pNext();
	for (current; current != &other.Tail; current = current->Get_pNext())
	{
		os << "Content:" << current->Get_m_Data();
	}
	os << "List_size: " << other.m_size << std::endl;
	return os;
}

std::istream& operator>>(std::istream& in, List& other)
{
	other.MakeEmpty();
	Circle tmp;
	while (in >> tmp)
	{
		other.AddLast(tmp);
	}return in;
}
