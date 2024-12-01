#pragma once
#include "LinkedList.h"
#include "PhieuMuon.h"
#include"Node.h"
#include "Sach.h"

template<class PhieuMuon>
class DanhSachPhieuMuon : public LinkedList<PhieuMuon> {
public:
	void docFile(string fn);
	void xuatFile(string fn);
	void xuatConsole();
	bool kiemTra(const string& st);
	void muon(DanhSachSach<Sach>& dsSach);
	void tra(DanhSachSach<Sach>& dsSach);
};
