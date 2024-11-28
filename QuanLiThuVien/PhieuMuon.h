#pragma once
#include "Header.h"

class PhieuMuon {
private:
	int SoPhieuMuon;
	static int MaPhieuMuon;
	string MaBanDoc;
	string MaSach;
	long NgayMuon;
	long NgayTra;
	int TinhTrangPhieuMuon;
public:
	PhieuMuon(string MBD = "", string MS = "");
	int getSoPhieuMuon();
	static int getMaPhieuMuon();
	string getMaBanDoc();
	string getMaSach();
	long getNgayMuon();
	long getNgayTra();
	int getTinhTrangPhieuMuon();

	//void setSoPhieuMuon(int i);
	void setMaBanDoc(string s);
	void setMaSach(string s);
	void setNgayMuon(long dt);
	void setNgayTra(long dt);
	void setTinhTrangPhieu(int i);
	void traSach();
	void xuat();
};
