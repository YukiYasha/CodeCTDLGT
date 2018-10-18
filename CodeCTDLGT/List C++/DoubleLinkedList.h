#pragma once

typedef struct Node
{
	int Info;
	Node *Next;
	Node *Pre;
};

typedef struct DoubleList
{
	Node *Head;
	Node *Tail;
};

class LinkedList
{
public:

	void CreateList(DoubleList &L);//Khoi tao danh sach
	Node *CreateNode(int iNum);//Khoi tao node
	void EnterList(DoubleList &L);//Nhap danh sach
	void PrintList(DoubleList L);//In danh sach
	void RemoveList(DoubleList &L);//Xoa danh sach

	void AddHead(DoubleList &L, Node *p);//Them node dau danh sach
	void ThemDau(DoubleList &L);
	void AddTail(DoubleList &L, Node *p);//Them nut cuoi danh sach
	void ThemCuoi(DoubleList &L);

	void RemoveHead(DoubleList &L);//Xoa phan tu dau list
	void RemoveTail(DoubleList &L);//Xoa phan tu cuoi list
	void RemoveBeforeQ(DoubleList &L, Node *q);//Xoa phan tu truoc phan tu q
	void DeleteBeforeQ(DoubleList &L);
	void RemoveAfterQ(DoubleList &L, Node *q);//Xoa phan tu sau phan tu q
	void DeleteAfterQ(DoubleList &L);
	void RemoveX(DoubleList &L);//Xoa node co gia tri X

	void CountNode(DoubleList L);//Dem so nut
	void SeachNode(DoubleList L);//Tim nut co gia tri X

	void SelectionSort(DoubleList &L);//Sap xep tang dan
	void InsertNum(DoubleList &L);//Chen them node danh bao tinh sap xep
};