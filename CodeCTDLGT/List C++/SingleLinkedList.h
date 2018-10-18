#pragma once

typedef int Data;

typedef struct Node
{
	Data Info;
	Node *Next;
};

typedef struct List
{
	Node *Head;
	Node *Tail;
};

class LinkedList
{
public:
	void CreateList(List &L);//Khoi tao danh sach
	Node *CreateNode(Data iNum);//Khoi tao node
	void PrintList(List L);//In danh sach
	void EnterList(List &L);//Nhap danh sach
	void RemoveList(List &L);//Xoa danh sach

	void AddHead(List &L, Node *p);//Them node dau danh sach
	void AddTail(List &L, Node *p);//Them nut cuoi danh sach

	void ThemDau(List &L);
	void ThemCuoi(List &L);

	void CountNode(List L);//Dem so nut
	void SeachNode(List L);//Tim nut co gia tri X

	void RemoveHead(List &L);//Xoa node dau tien
	void RemoveTail(List &L);//Xoa node cuoi cung
	void RemoveX(List &L);//Xoa node co gia tri X

	void QuickSort(List &L);//Sap xep tang dan
	void InsertNum(List &L);//Chen them node danh bao tinh sap xep
};