#pragma once
#include "Header.h"


class Sach {
private:
    string _strMaSach;
    string _strTenSach;
    string _strTenTacGia;
    string _strNhaXuatBan;
    int _iGiaSach;
    int _iNamPhatHanh;
    int _iSoTrang;
    string _strNgayNhapKho;
    int _iTinhTrangSach;
public:
    Sach();
    Sach(string masach, string tensach, string tacgia, string nhaxuatban, int giasach, int namphathanh,
        int sotrang, string ngaynhapkho, int tinhtrangsach);
    ~Sach();
    string getMaSach();
    string getTenSach();
    string getTenTacGia();
    string getNhaXuatBan();
    int getGiaSach();
    int getNamPhatHanh();
    int getSoTrang();
    string getNgayNhapKho();
    int getTinhTrangSach();

    void setMaSach(string masach);
    void setTenSach(string tensach);
    void setTenTacGia(string tentacgia);
    void setNhaXuatBan(string nhaxuatban);
    void setGiaSach(int giasach);
    void setNamPhatHanh(int namphathanh);
    void setSoTrang(int sotrang);
    void setNgayNhapKho(string ngaynhapkho);
    void setTinhTrangSach(int tinhtrangsach);
    void display();
};