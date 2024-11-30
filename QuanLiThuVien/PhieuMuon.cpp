#include "PhieuMuon.h"


PhieuMuon::PhieuMuon(string MBD, string MS)
    : MaBanDoc(MBD), MaSach(MS), TinhTrangPhieuMuon(1) {
    NgayMuon = getCurrentDate(); 
    int day, month, year;
    int result = sscanf(NgayMuon.c_str(), "%d/%d/%d", &day, &month, &year);

    if (result != 3) {
        cerr << "Lỗi: Ngày mượn không hợp lệ! Đặt ngày mượn về giá trị mặc định." << endl;
        NgayMuon = "01/01/2000";
        day = 1;
        month = 1;
        year = 2000;
    }

    NgayTra = addDaysToDate(day, month, year, 7); 
    SoPhieuMuon = MaPhieuMuon;
    MaPhieuMuon++;
}

int PhieuMuon::MaPhieuMuon = 1;
int PhieuMuon::getSoPhieuMuon() { return SoPhieuMuon; }
int PhieuMuon::getMaPhieuMuon() { return MaPhieuMuon; }
string PhieuMuon::getMaBanDoc() { return MaBanDoc; }
string PhieuMuon::getMaSach() { return MaSach; }
string PhieuMuon::getNgayMuon() { return NgayMuon; }
string PhieuMuon::getNgayTra() { return NgayTra; }
int PhieuMuon::getTinhTrangPhieuMuon() { return TinhTrangPhieuMuon; }

void PhieuMuon::setMaBanDoc(string s) { MaBanDoc = s; }
void PhieuMuon::setMaSach(string s) { MaSach = s; }
void PhieuMuon::setNgayMuon(string ngayMuon) { NgayMuon = ngayMuon; }
void PhieuMuon::setNgayTra(string ngayTra) { NgayTra = ngayTra; }
void PhieuMuon::setTinhTrangPhieu(int i) { TinhTrangPhieuMuon = i; }
void PhieuMuon::traSach() { TinhTrangPhieuMuon = 0; }  
void PhieuMuon::xuat() {
    int dayMuon, monthMuon, yearMuon;
    int resultMuon = sscanf(NgayMuon.c_str(), "%d/%d/%d", &dayMuon, &monthMuon, &yearMuon);

    int dayTra, monthTra, yearTra;
    int resultTra = sscanf(NgayTra.c_str(), "%d/%d/%d", &dayTra, &monthTra, &yearTra);

   
    if (resultMuon != 3) {
        cerr << "Lỗi: Ngày mượn không hợp lệ!" << endl;
        return; 
    }

    if (resultTra != 3) {
        cerr << "Lỗi: Ngày trả không hợp lệ!" << endl;
        return; 
    }
    cout << "| " << setw(14) << left << SoPhieuMuon
        << "| " << setw(14) << left << MaBanDoc
        << "| " << setw(14) << left << MaSach
        << "| " << setw(2) << right << dayMuon
        << "/" << setw(2) << right << monthMuon
        << "/" << setw(4) << right << yearMuon
        << "" << setw(4) << left << ""
        << "| " << setw(1) << right << dayTra
        << "/" << setw(2) << right << monthTra
        << "/" << setw(4) << right << yearTra
        << "" << setw(5) << left << ""
        << "| " << setw(14) << left;
    if (TinhTrangPhieuMuon == 1) {
        setColor(4);
        cout << "Dang muon";
    }
    else {
        setColor(2);
        cout << "Da tra";
    }
    setColor(2);
    cout << "|" << endl;
}
