#pragma once
#include "Header.h"


class PhieuMuon {
private:
	int MaPhieu;
	string MaBanDoc;
	string MaSach;
	string NgayMuon;
	string NgayTra;
	int TinhTrangPhieuMuon;
public:
	PhieuMuon(const PhieuMuon& p);
	PhieuMuon(string mabandoc = "", string masach = "", int sophieumuon = 1, int tinhtrangphieumuon = 1);
	int getMaPhieu();
	string getMaBanDoc();
	string getMaSach();
	string getNgayMuon();
	string getNgayTra();
	int getTinhTrangPhieuMuon();

	void setMaBanDoc(string mabandoc);
	void setMaSach(string masach);
	void setNgayMuon(string ngayMuon);
	void setNgayTra(string ngayTra);
	void setTinhTrangPhieuMuon(int tinhtrangsach);
	void traSach();
	void xuat();
};
