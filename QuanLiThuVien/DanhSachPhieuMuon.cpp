#pragma once
#include "DanhSachPhieuMuon.h"
#include "LinkedList.h"
#include "Header.h"


/***********************************************************************************************
* @Description     Lấy dữ liệu file txt
* @parameter       Tên file txt
*************************************************************************************************/
template<class PhieuMuon>
void DanhSachPhieuMuon<PhieuMuon>::docFile(string fn) {
	ifstream is(fn);
	if (!is.is_open()) {
		cout << "Khong mo duoc file!!!" << endl;
		return;
	}
	string s;
	while (getline(is, s)) {
		stringstream ss(s);
		vector<string> v;
		string tmp;
		while (getline(ss, tmp, '|')) {
			v.push_back(tmp);
		}
		if (v.size() < 6) continue; 
		int maPhieu = stoi(v[0]);
		string maBanDoc = v[1];
		string maSach = v[2];
		string ngayMuon = v[3];
		string ngayTra = v[4];
		int tinhTrangPhieuMuon = stoi(v[5]);

		PhieuMuon phieuMuon(maBanDoc, maSach, maPhieu, tinhTrangPhieuMuon);
		phieuMuon.setNgayMuon(ngayMuon);
		phieuMuon.setNgayTra(ngayTra);


		LinkedList<PhieuMuon>::addTail(phieuMuon);
	}
	is.close();
}

/***********************************************************************************************
* @Description     Ghi đè lên file txt
* @parameter       Tên file txt
*************************************************************************************************/
template<class PhieuMuon>
void DanhSachPhieuMuon<PhieuMuon>::xuatFile(string fn) {
	ofstream os(fn);
	if (!os.is_open()) {
		cout << "Khong mo duoc file!!!" << endl;
		return;
	}

	Node<PhieuMuon>* node = LinkedList<PhieuMuon>::getHead();
	while (node != NULL) {
		os << node->_data.getMaPhieu() << "|"
			<< node->_data.getMaBanDoc() << "|"
			<< node->_data.getMaSach() << "|"
			<< node->_data.getNgayMuon() << "|"
			<< node->_data.getNgayTra() << "|"
			<< node->_data.getTinhTrangPhieuMuon() << endl;
		node = node->_pNext;
	}
	os.close();
}

/***********************************************************************************************
* @Description     Xuất Danh Sach Sach ra màn hình
*************************************************************************************************/
template<class PhieuMuon>
void DanhSachPhieuMuon<PhieuMuon>::xuatConsole() {
	system("cls");
	Node<PhieuMuon>* tmp = LinkedList<PhieuMuon>::getHead();
	if (tmp == NULL) {
		setColor(7);
		cout << "Danh sach phieu muon rong!" << endl;
	}
	else {
		setColor(14);
		cout << "+---------------+---------------+---------------+---------------+---------------+---------------+" << endl;
		cout << "| So phieu muon | Ma ban doc    | Ma sach       | Ngay muon     | Ngay tra      | Tinh trang    |" << endl;
		cout << "+---------------+---------------+---------------+---------------+---------------+---------------+" << endl;
		while (tmp != NULL) {
			tmp->_data.xuat();
			tmp = tmp->_pNext;
		}
		setColor(14);
		cout << "+---------------+---------------+---------------+---------------+---------------+---------------+" << endl;
	}
	xuatFile("PhieuMuon.txt");
	system("pause");
	system("cls");
}

/***********************************************************************************************
* @Description     Kiểm tra dữ liệu nhập vào đạt chuẩn hay không
* @parameter       chuỗi cần kiểm tra
* @return          Trả về true nếu chuỗi đúng chuẩn và false nếu chuỗi không đúng chuẩn
*************************************************************************************************/
template<class PhieuMuon>
bool DanhSachPhieuMuon<PhieuMuon>::kiemTra(const string& st) {
	for (char c : st) {
		if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))) {
			return false;
		}
	}
	return true;
}


/***********************************************************************************************
* @Description     Xử lí tháo tác mượn sách và tạo phiếu mượn
*************************************************************************************************/
template<class PhieuMuon>
void DanhSachPhieuMuon<PhieuMuon>::muon() {
	Node<PhieuMuon>* tmp = LinkedList<PhieuMuon>::getHead();
	string maSach, maBanDoc;
	int cnt =0;
	do {
		setColor(7);
		cout << "\n\n\t\t\t\tNhap ma sach (MSxxxx):  ";
		setColor(7);
		getline(cin, maSach);
		if (!kiemTra(maSach)) {
			setColor(7);
			cout << "Ma sach chi duoc nhap chu va so! Vui long nhap lai." << endl;
		}
		if (maSach.substr(0, 2) != "MS" || !isDigit(maSach.substr(2, 4))) {
			setColor(4);
			cout << "\t\t\t\tMa Sach phai theo dinh dang (MSxxxx)  " << endl;
			setColor(7);
			continue;
		}
		if (maSach.length() == 6) {
			break;
		}

		setColor(4);
		cout << "\t\t\t\tVui long nhap Ma Sach voi du 6 ki tu!" << endl;
		setColor(7);
	} while (!kiemTra(maSach));


	if (!kiemTraSachTonTai(maSach)) {
		cout << "\t\t\t\tMa sach khong ton tai!" << endl;
		return;
	}
	do {
		setColor(7);
		cout << "\t\t\t\tNhap ma ban doc:  ";
		setColor(7);
		getline(cin, maBanDoc);
		if (!kiemTra(maBanDoc)) {
			setColor(4);
			cout << "\t\t\t\tMa ban doc chi duoc nhap chu va so! Vui long nhap lai." << endl;
		}
	} while (!kiemTra(maBanDoc));
	if (!kiemTraBanDocTonTai(maBanDoc)) {
		cout << "\t\t\t\tMa ban doc khong ton tai!" << endl;
		return;
	}
	bool sachDaMuon = false;
	while (tmp != NULL) {
		if (tmp->_data.getMaSach() == maSach && tmp->_data.getTinhTrangPhieuMuon() == 1) {
			sachDaMuon = true;
			break;
		}
		tmp = tmp->_pNext;
	}
	if (sachDaMuon) {
		setColor(7);
		cout << "\t\t\t\tSach da duoc muon boi nguoi khac!" << endl;
	}
	else {
		PhieuMuon phieuMuon(maBanDoc, maSach, LinkedList<PhieuMuon>::getSize() + 1);
		LinkedList<PhieuMuon>::addTail(phieuMuon);
		setColor(7);
		cout << "\t\t\t\tMuon sach thanh cong!" << endl;

		DanhSachSach<Sach> dsSach;
		dsSach.docFile();
		Sach* sach = dsSach.timSach(maSach);
		if (sach != NULL) {
			sach->setTinhTrangSach(1); 
			dsSach.updateFile();
		}
		dsSach.docFile();

		xuatFile("PhieuMuon.txt");
	}
}

/***********************************************************************************************
* @Description     Xử lí tháo tác trả sách và xóa phiếu mượn
*************************************************************************************************/
template<class PhieuMuon>
void DanhSachPhieuMuon<PhieuMuon>::tra() {
	string soPhieuMuon;
	setColor(7);
	cout << "\n\t\t\t\tNhap so phieu muon: ";
	getline(cin, soPhieuMuon);
	if (soPhieuMuon.empty() || !all_of(soPhieuMuon.begin(), soPhieuMuon.end(), isdigit)) {

		cout << "\t\t\t\tSo phieu muon khong hop le!" << endl;
		system("pause");
		system("cls");
		return;
	}
	bool found = false;
	Node<PhieuMuon>* tmp = LinkedList<PhieuMuon>::getHead();
	int SPM = stoi(soPhieuMuon);
	while (tmp != NULL) {
		if (tmp->_data.getMaPhieu() == SPM) {
			if (tmp->_data.getTinhTrangPhieuMuon() == 0) {
				cout << "\t\t\t\tSach dang khong ai muon!" << endl;
				system("pause");
				system("cls");
				return;
			}
			tmp->_data.setTinhTrangPhieuMuon(0);
			DanhSachSach<Sach> dsSach;
			dsSach.docFile(); 
			Sach* sach = dsSach.timSach(tmp->_data.getMaSach());
			if (sach != NULL) {
				sach->setTinhTrangSach(0); 
				dsSach.updateFile();     
			}
			cout << "\t\t\t\tTra sach thanh cong!" << endl;
			dsSach.docFile();
			found = true;
			break;
		}
		tmp = tmp->_pNext;
	}
	if (!found) {

		cout << "\t\t\t\tSo phieu muon khong ton tai!" << endl;
	}
	else{
		cout << tmp->_data.getTinhTrangPhieuMuon();
		xuatFile("PhieuMuon.txt");
	}
	system("pause");
	system("cls");
}


