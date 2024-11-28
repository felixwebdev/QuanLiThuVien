#pragma once
#include "Header.h"
#include "LinkedList.h"

template <class BanDoc>
class DanhSachBanDoc :public LinkedList<BanDoc> {
private:
	LinkedList<BanDoc> listBanDoc;
public:
	int getSoBanDoc();
	BanDoc* timkiemBanDoc(string maBanDoc);
	void themBanDoc(BanDoc newBanDoc);
	void xoaBanDoc(string tenBanDoc);
	void xuLyDocFile();
	void updateFile();
	void thongKeBanDoc();
};