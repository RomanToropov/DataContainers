#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

class Tree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class Tree;
	}*Root;

public:
	Element* getRoot()const
	{
		return Root;
	}
	Tree()
	{
		Root = nullptr;
		cout << "TConstructor:\t" << this << endl;
	}
	Tree(const std::initializer_list<int>& il) : Tree()
	{
		for (int const* it = il.begin(); it != il.end(); it++)
			insert(*it,Root);
	}
	~Tree()
	{
		clear(Root);
		cout << "TDestructor:\t" << this << endl;
	}

	void clear()
	{
		clear(Root);
	}

	void insert(int Data)
	{
		insert(Data, Root);
	}

	void print()const
	{
		print(this->Root);
		cout << endl;
	}

	int minValue()const
	{
		return minValue(Root);
	}

	int maxValue()const
	{
		return maxValue(Root);
	}

	int count()const
	{
		return count(this->Root);
	}

	int sum()const
	{
		return sum(Root);
	}

	int depth()const
	{
		return depth(Root);
	}

	int depth(Element* Root)const
	{
		if (Root == nullptr)return 0;
		else return depth(Root->pLeft)+1 > depth(Root->pRight) ?
			depth(Root->pLeft) + 1 : depth(Root->pRight) + 1;
	}

	double avg()const
	{
		return(double)sum(Root)/count(Root);
	}


	void clear(Element*& Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
		Root = nullptr;
	}
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
		//insert(Data, Root);
	}

	int minValue(Element* Root)const
	{
		//if (Root->pLeft==nullptr)return Root->Data;
		//else return minValue(Root->pLeft);
		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
	}

	int maxValue(Element* Root)const
	{
		return Root->pRight ? maxValue(Root->pRight) : Root->Data;

	}

	int count(Element* Root)const
	{
		//if (Root==nullptr)return 0;
		//else return count(Root->pLeft)+count(Root->pRight)+1;
		return Root == nullptr ? 0 : count(Root->pLeft) + count(Root->pRight) + 1;
	}

	int sum(Element* Root)const
	{
		return Root == nullptr ? 0 : (Root->Data) + sum(Root->pLeft) + sum(Root->pRight);
	}

	

	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << tab;
		print(Root->pRight);
	}
};

//#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "������� ���������� ���������: "; cin >> n;

	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	tree.print();

	cout << "Min Value: " << tree.minValue() << endl;

	cout << "Max Value: " << tree.maxValue() << endl;

	cout << "count: " << tree.count() << endl;

	cout << "sum: " << tree.sum() << endl;

	tree.clear();
	tree.print();

	cout << "�������: " << tree.depth() << endl;
#endif // BASE_CHECK

	Tree tree = { 50,25,75,16,32,48,64,80,85,77 };
	tree.print();
	cout << "������� ������: " << tree.depth() << endl;
}