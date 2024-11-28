#pragma once
#include "LinkedList.h"
#include "PhieuMuon.h"
#include"Node.h"

template<class PhieuMuon>
class DanhSachPhieuMuon : public LinkedList<PhieuMuon> {
public:
	void docFile(string fn);
	void xuatFile(string fn);
	void xuatConsole();
	bool kiemTra(const string& st);
	void muon();
	void tra();
};
