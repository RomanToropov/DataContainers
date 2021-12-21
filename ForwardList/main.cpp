#include<iostream>
using namespace std;
#define tab "\t"

class Element
{
	int Data;  // Значение элемента
	Element* pNext;  //Адрес следующего элемента
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}

	friend class ForwardList;
};

class ForwardList
{
	Element* Head;
public:
	ForwardList()
	{
		Head = nullptr;
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

		// Adding Elements:
	void push_front(int Data)
	{
		//1) Создаем новый элемент
		Element* New = new Element(Data);
		//2) Привязываем элемент к началу списка
		New->pNext = Head;
		//3) Делаем новый элемент началом списка
		Head = New;
	}

	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = New;

	}

	void insert(int Data, int Index)
	{
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)Temp = Temp->pNext;
		Element* New = new Element(Data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;
	}


			//Removing Elements:
	void pop_front()
	{
		Element* Temp = Head;
		Head = Head->pNext;
		delete Temp;
	}

	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
	}

			//Methods:
	void print()const
	{
		Element* Temp = Head;  //итератор - указатель при помощи которого можно получить доступ к структуре
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;  // Переходим на следующий элемент
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}

	list.push_back(123);
	list.print();

	list.pop_front();
	list.print();

	list.pop_back();
	list.print();

	int value;
	int index;
	cout << "Введите индекс элемента: "; cin >> index;
	cout << "Введите значение индекса элемента: "; cin >> value;
	list.insert(value, index);
	list.print();

}