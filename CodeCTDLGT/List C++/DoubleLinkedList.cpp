#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

void LinkedList::CreateList(DoubleList &L)
{
	L.Head = L.Tail = NULL;
}

Node *LinkedList::CreateNode(int iNum)
{
	Node *p;

	p = new Node;
	if (p == NULL)
	{
		cout << "\t\t\t***KHONG DU BO NHO***";
		exit(1);
	}

	else
	{
		p->Info = iNum;
		p->Next = p->Pre = NULL;
	}

	return p;
}

void LinkedList::EnterList(DoubleList &L)
{
	Node *p;
	int iNum = 0;
	int i = 1;

	cout << "\t\t\tNHAP DANH SACH\n";
	cout << "\n*** Viec nhap danh sach dung khi nhap gia tri am ***\n\n";

	while (iNum >= 0)
	{
		cout << "Nhap nut thu " << i++ << ": ";
		cin >> iNum;

		//Gia tri nut am thi khong nhan va dung nhap
		if (iNum < 0) goto Stop;

		p = CreateNode(iNum);

		AddTail(L, p);
	}

Stop:;
}

void LinkedList::PrintList(DoubleList L)
{
	Node *p;

	p = L.Head;

	while (p != NULL)
	{
		cout << " " << p->Info;
		p = p->Next;
	}
}

void LinkedList::RemoveList(DoubleList &L)
{
	Node *p;

	while (L.Head != NULL)//Con phan tu trong List
	{
		p = L.Head;
		L.Head = p->Next;
		delete p;
	}
}

void LinkedList::AddHead(DoubleList &L, Node *p)
{
	if (L.Head == NULL)
	{
		L.Head = p;
		L.Tail = L.Head;
	}
	else
	{
		p->Next = L.Head;
		L.Head->Pre = p;
		L.Head = p;
	}
}

void LinkedList::ThemDau(DoubleList &L)
{
	int iNum;

	cout << "\n\nNhap gia tri nut chen vao dau list: ";
	cin >> iNum;

	AddHead(L, CreateNode(iNum));

	PrintList(L);
}

void LinkedList::AddTail(DoubleList &L, Node *p)
{
	if (L.Head == NULL)
	{
		L.Head = p;
		L.Tail = L.Head;
	}

	else
	{
		p->Pre = L.Tail;
		L.Tail->Next = p;
		L.Tail = p;
	}
}

void LinkedList::ThemCuoi(DoubleList &L)
{
	int iNum;

	cout << "\n\nNhap gia tri nut chen vao cuoi list: ";
	cin >> iNum;

	AddTail(L, CreateNode(iNum));

	PrintList(L);
}

void LinkedList::CountNode(DoubleList L)
{
	Node *p;
	int iCount = 0;

	p = L.Head;

	while (p != NULL)
	{
		iCount++;
		p = p->Next;
	}

	cout << "\n\nDanh sach co " << iCount << " nut";
}

void LinkedList::SeachNode(DoubleList L)
{
	Node *p;
	int iNum = 0;
	int iCount = 1;

	cout << "\n\nNhap gia tri nut muon tim: ";
	cin >> iNum;

	p = L.Head;
	cout << "Gia tri " << iNum << " o nut so: ";

	while (p != NULL)
	{
		if (p->Info == iNum)
			cout << iCount << "  ";

		p = p->Next;
		iCount++;
	}
}

void LinkedList::RemoveHead(DoubleList &L)
{
	Node *p;

	if (L.Head != NULL)
	{
		p = L.Head;
		L.Head = L.Head->Next;
		L.Head->Pre = NULL;
		delete p;

		if (L.Head == NULL)
			L.Tail = NULL;
	}
}

void LinkedList::RemoveTail(DoubleList &L)
{
	Node *p;

	if (L.Head != NULL)
	{
		p = L.Tail;
		L.Tail = L.Tail->Pre;
		L.Tail->Next = NULL;
		delete p;

		if (L.Tail == NULL)
			L.Head = NULL;
	}
}

void LinkedList::RemoveBeforeQ(DoubleList &L, Node *q)
{
	Node *p;//Nut xoa

	p = q->Pre->Pre;
	p->Next = q;
	p = q->Pre;
	q->Pre = p->Pre;
	delete p;
}

void LinkedList::DeleteBeforeQ(DoubleList &L)
{
	Node *q = L.Head->Next->Next;
	int iNum;

	cout << "\n\nNhap gia tri phan tu muon xoa phan tu dung truoc: ";
	cin >> iNum;

	if (L.Head->Info == iNum)
	{
		cout << "\nDay la phan tu dau list, truoc no khong co phan tu\n";
		goto Stop;
	}

	if (q->Pre->Info == iNum)
		RemoveHead(L);

	else
		while (q != NULL)
		{
			if (q->Info == iNum)
			{
				RemoveBeforeQ(L, q);
				break;
			}

			q = q->Next;
		}

Stop:;
}

void LinkedList::RemoveAfterQ(DoubleList &L, Node *q)
{
	Node *p;//Nut xoa

	p = q->Next->Next;
	p->Pre = q;
	p = q->Next;
	q->Next = p->Next;
	delete p;
}

void LinkedList::DeleteAfterQ(DoubleList &L)
{
	Node *q = L.Head->Next;
	int iNum;

	cout << "\n\nNhap gia tri phan tu muon xoa phan tu dung sau: ";
	cin >> iNum;

	if (L.Tail->Info == iNum)
	{
		cout << "\nDay la phan tu cuoi list, sau no khong co phan tu\n";
		goto Stop;
	}

	if (L.Tail->Pre->Info == iNum)
		RemoveTail(L);

	else
		while (q != NULL)
		{
			if (q->Info == iNum)
			{
				RemoveAfterQ(L, q);
				break;
			}

			q = q->Next;
		}

Stop:;
}

void LinkedList::RemoveX(DoubleList &L)
{
	Node *p;
	Node *q = NULL;
	int iNum;

	cout << "\n\nNhap gia tri nut muon xoa: ";
	cin >> iNum;

	//Phan tu o cuoi list
	while (L.Tail->Info == iNum)
	{
		RemoveTail(L);
	}

	//Phan tu o dau list
	while (L.Head->Info == iNum)
	{
		RemoveHead(L);
	}

	//Phan tu giua list
	p = L.Head->Next;

	while (p != L.Tail)
	{
	cont:;
		if (p->Info == iNum)
		{
			q = p->Next;
			q->Pre = p->Pre;
			q = p->Pre;
			q->Next = p->Next;
			delete p;
			p = q;
			goto cont;
		}
		p = p->Next;
	}

	cout << "Danh sach sau khi xoa nut co gia tri " << iNum << ": ";
	PrintList(L);
}

void LinkedList::SelectionSort(DoubleList &L)
{
	Node *p, *q;

	p = L.Head;

	while (p != L.Tail)
	{
		q = p->Next;

		while (q != NULL)
		{
			if (p->Info > q->Info)
			{
				int Temp = p->Info;
				p->Info = q->Info;
				q->Info = Temp;
			}

			q = q->Next;
		}
		p = p->Next;
	}
}

void LinkedList::InsertNum(DoubleList &L)
{
	Node *p, *q;
	int iNum;

	cout << "\n\nNhap gia tri node muon chen: ";
	cin >> iNum;

	p = CreateNode(iNum);

	q = L.Head;

	//Neu list rong thi Head = Tail = new node
	if (L.Head == NULL)
	{
		L.Head = L.Tail = p;
	}

	//Chen vao dau list
	else
		if (p->Info <= L.Head->Info)
		{
			p->Next = L.Head;
			L.Head->Pre = p;
			L.Head = p;
		}

	//Chen cuoi list
		else
			if (p->Info >= L.Tail->Info)
			{
				L.Tail->Next = p;
				p->Pre = L.Tail;
				L.Tail = p;
			}

	//Chen sau 1 node
			else
			{
				while (q != NULL)
				{
					if ((p->Info >= q->Info) && (p->Info < q->Next->Info))
					{
						p->Next = q->Next;
						p->Pre = q;
						q->Next = p;
						q = p->Next;
						q->Pre = p;
						break;
					}

					q = q->Next;
				}
			}

	cout << "Danh sach sau khi chen:";
	PrintList(L);
}
