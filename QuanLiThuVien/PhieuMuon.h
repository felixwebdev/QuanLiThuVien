#pragma once
#include "Header.h"


class PhieuMuon {
private:
	int SoPhieuMuon;
	static int MaPhieuMuon;
	string MaBanDoc;
	string MaSach;
	string NgayMuon;
	string NgayTra;
	int TinhTrangPhieuMuon;
public:
	PhieuMuon(string MBD = "", string MS = "");
	int getSoPhieuMuon();
	static int getMaPhieuMuon();
	string getMaBanDoc();
	string getMaSach();
	string getNgayMuon();
	string getNgayTra();
	int getTinhTrangPhieuMuon();

	void setMaBanDoc(string s);
	void setMaSach(string s);
	void setNgayMuon(string ngayMuon);
	void setNgayTra(string ngayTra);
	void setTinhTrangPhieu(int i);
	void traSach();
	void xuat();
};
