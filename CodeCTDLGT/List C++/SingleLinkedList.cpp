#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

void LinkedList::CreateList(List &L)
{
	L.Head = L.Tail = NULL;
}

Node *LinkedList::CreateNode(Data iNum)
{
	Node *p;

	p = new Node;
	if (p == NULL) exit(1);

	p->Info = iNum;
	p->Next = NULL;

	return p;
}

void LinkedList::PrintList(List L)
{
	Node *p;

	p = L.Head;

	while (p != NULL)
	{
		cout << " " << p->Info;
		p = p->Next;
	}
}

void LinkedList::RemoveList(List &L)
{
	Node *p;

	while (L.Head != NULL)//con phan tu trong List
	{
		p = L.Head;
		L.Head = p->Next;
		delete p;
	}
}

void LinkedList::AddHead(List &L, Node *p)
{
	if (L.Head == NULL)
	{
		L.Head = p;
		L.Tail = L.Head;
	}
	else
	{
		p->Next = L.Head;
		L.Head = p;
	}
}

void LinkedList::AddTail(List &L, Node *p)
{
	if (L.Head == NULL)
	{
		L.Head = p;
		L.Tail = L.Head;
	}

	else
	{
		L.Tail->Next = p;
		L.Tail = p;
	}
}

void LinkedList::EnterList(List &L)
{
	Node *p;
	int iNum = 0;
	int i = 1, j = 0;

	cout << "\t\t\tNHAP DANH SACH\n";
	cout << "\n***Chu y 2 gia tri ke nhau bang nhau chi lay 1 gia tri***\n\n";
	while (iNum >= 0)
	{
	Start:;

		cout << "Nhap nut thu " << i++ << ": ";
		cin >> iNum;

		//Gia tri nut am thi khong nhan va dung nhap
		if (iNum < 0) goto Stop;

		//Dam bao list k rong
		if (j == 0) goto Cont;

		else
		{
			if (iNum == L.Tail->Info)
				goto Start;
		}

	Cont:;
		j = 1;

		p = CreateNode(iNum);

		AddTail(L, p);
	}

Stop:;
}

void LinkedList::ThemDau(List &L)
{
	int iNum;

	cout << "\n\nNhap gia tri nut chen vao dau list: ";
	cin >> iNum;

	AddHead(L, CreateNode(iNum));

	PrintList(L);
}

void LinkedList::ThemCuoi(List &L)
{
	int iNum;

	cout << "\n\nNhap gia tri nut chen vao cuoi list: ";
	cin >> iNum;

	AddTail(L, CreateNode(iNum));

	PrintList(L);
}

void LinkedList::CountNode(List L)
{
	Node *p;
	int iDem = 0;

	p = L.Head;
	while (p != NULL)
	{
		iDem++;
		p = p->Next;
	}

	cout << "\n\nDanh sach co " << iDem << " nut";
}

void LinkedList::SeachNode(List L)
{
	Node *p;
	int iNum = 0;
	int iDem = 1;

	cout << "\n\nNhap gia tri nut muon tim: ";
	cin >> iNum;

	p = L.Head;
	cout << "Gia tri " << iNum << " o nut so: ";
	while (p != NULL)
	{
		if (p->Info == iNum)
			cout << iDem << "  ";

		p = p->Next;
		iDem++;
	}
}

void LinkedList::RemoveHead(List &L)
{
	Node *p;

	if (L.Head != NULL)
	{
		p = L.Head;
		L.Head = L.Head->Next;
		delete p;
		if (L.Head == NULL)
			L.Tail = NULL;
	}
	cout << "\n\nList sau khi xoa node dau tien: ";
	PrintList(L);
}

void LinkedList::RemoveTail(List &L)
{
	Node *p, *q;
	q = L.Head;
	p = q->Next->Next;

	while (p != NULL)
	{
		p = p->Next;
		q = q->Next;
	}

	p = q->Next;
	q->Next = NULL;
	L.Tail = q;
	delete p;

	cout << "\n\nList sau khi xoa node cuoi cung:";
	PrintList(L);
}

void LinkedList::RemoveX(List &L)
{
	Node *p, *q;
	int iNum;

	cout << "\n\nNhap gia tri nut muon xoa: ";
	cin >> iNum;

	p = L.Head;

	//Xoa phan tu dau list
	if (iNum == L.Head->Info)
	{
		L.Head = L.Head->Next;
		delete p;
	}

	//Xoa phan tu vi tri khac
	else
	{
		while ((p != NULL) && (iNum != p->Info))
		{
			q = p;//Nut truoc nut can xoa
			p = p->Next;//Tim nut co gia tri X can xoa
		}

		if (p != NULL)
		{
			q->Next = p->Next;
			delete p;
		}

		if (p == NULL)
			cout << "Gia tri " << iNum << " khong ton tai" << endl;
	}

	cout << "Danh sach sau khi xoa nut co gia tri " << iNum << ":";
	PrintList(L);
}

void LinkedList::QuickSort(List &L)
{
	Node *p, *X;//X Luu dia chi phan tu cam canh
	List L1, L2;

	if (L.Head == L.Tail) return;//Da co thu tu

	CreateList(L1);
	CreateList(L2);

	X = L.Head;
	L.Head = X->Next;

	while (L.Head != NULL)//Tach L = L1 va L2
	{
		p = L.Head;
		L.Head = p->Next;
		p->Next = NULL;

		if (p->Info <= X->Info)
			AddHead(L1, p);
		else
			AddHead(L2, p);
	}

	QuickSort(L1);//Goi de quy sap xep L1
	QuickSort(L2);//Goi de quy sap xep L2

	if (L1.Head != NULL)//noi L1, L2 va X vao L
	{
		L.Head = L1.Head;
		L1.Tail->Next = X;//noi X vao
	}

	else
		L.Head = X;

	X->Next = L2.Head;

	if (L2.Head != NULL) //L2 co tren mot phan tu
		L.Tail = L2.Tail;

	else  //L2 khong co phan tu nao 
		L.Tail = X;

	L.Tail->Next = NULL;
}

void LinkedList::InsertNum(List &L)
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
			L.Head = p;
		}

	//Chen cuoi list
		else
			if (p->Info >= L.Tail->Info)
			{
				L.Tail->Next = p;
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
						q->Next = p;
						break;
					}

					q = q->Next;
				}
			}

	cout << "Danh sach sau khi chen:";
	PrintList(L);
}
