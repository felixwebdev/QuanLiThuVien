#pragma once
#include "Header.h"
#include "LinkedList.h"

template<class Sach>
class DanhSachSach : public LinkedList<Sach> {
public:
	void docFile();
	void updateFile();
	void themVaoFile(Node<Sach>* sachMoi);
	void themSach(Sach sachMoi);
	void display();
	Sach* timSach(string masach);
	void xoaSach(string masach);
};