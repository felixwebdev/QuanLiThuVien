#pragma once
#include "Header.h"
#include "LinkedList.h"

template<class Sach>
class DanhSachSach : public LinkedList<Sach> {
public:
	void docFile();
	void xuatFile();
	void display();
	Node<Sach>* timSach(string masach);
	Node<Sach>* timSachPre(Node<Sach>* sach);
	void xoaSach(string masach);
};