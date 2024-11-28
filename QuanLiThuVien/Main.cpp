#include "Header.h"
#include "BanDoc.h"
#include "NhanVien.h"
#include "Sach.h"
#include "Node.h"
#include "Node.cpp"
#include "LinkedList.cpp"
#include "DanhSachBanDoc.cpp"
#include "DanhSachNhanVien.cpp"
#include "DanhSachSach.cpp"
#include "DanhSachPhieuMuon.h"
#include "PhieuMuon.h"
#include "DanhSachPhieuMuon.cpp"

int main() {
	DanhSachBanDoc<BanDoc> dsBanDoc;
	DanhSachNhanVien<NhanVien> dsNhanVien;
	DanhSachSach<Sach> dsSach;
	DanhSachPhieuMuon<PhieuMuon> dsPhieuMuon;

	dsBanDoc.xuLyDocFile();
	dsNhanVien.xuLyDocFile();
	dsSach.docFile();
	dsPhieuMuon.docFile("PhieuMuon.txt");

	NhanVien* nhanVienHienTai = NULL;
    // ========================= Xu li chuc nang dang nhap ==================================
 	system("cls");
	string strUsername, strPassword;
	int iCount = 0;
	setColor(4);
	cout << "-> ";
	setColor(7);
	setColor(14);
	char c;
	do {
		system("cls");
		//Menu chuc nang dang nhap nhan vien
		DangNhap(strUsername, strPassword);
		//Tim kiem nhan vien theo username va password
		NhanVien* timKiemNhanVien = dsNhanVien.timKiemNhanVien(strUsername, strPassword);
		if (strUsername.length() == 0) {
			system("cls");
			setColor(4);
			cout << endl << "\t\t\tUsername khong duoc bo trong. \n \t\t\tNhan phim ESC de thoat hoac phim bat ki de tiep tuc dang nhap!" << endl;
			setColor(7);
			//Lay du lieu khi nguoi dung nhan phim bat ki
			c = getch();
		}
		else if (strPassword.length() == 0) {
			system("cls");
			setColor(4);
			cout << endl << "\t\t\tPassword khong duoc bo trong. \n \t\t\tNhan phim ESC de thoat hoac phim bat ki de tiep tuc dang nhap!" << endl;
			setColor(7);
			//Lay du lieu khi nguoi dung nhan phim bat ki
			c = getch();
		}
		else if (checkContainsSpacing(strUsername)) {
			system("cls");
			setColor(4);
			cout << endl << "\t\t\tUsername khong duoc chua khoang trang. \n \t\t\tNhan phim ESC de thoat hoac phim bat ki de tiep tuc dang nhap!" << endl;
			setColor(7);
			//Lay du lieu khi nguoi dung nhan phim bat ki
			c = getch();
		}
		else if (timKiemNhanVien == NULL) {
			//Dang nhap that bai
			iCount++;
			system("cls");
			setColor(4);
			cout << endl << "\t\t\tSai tai khoan hoac mat khau! Ban con " << 3 - iCount << " lan nhap. \n \t\t\tNhan phim ESC de thoat hoac phim Enter 2 lan de tiep tuc dang nhap!" << endl;
			setColor(7);
			//Lay du lieu khi nguoi dung nhan phim bat ki
			c = getch();
		}
		else {
			//Luu thong tin dang nhap cua nhan vien hien tai
			nhanVienHienTai = timKiemNhanVien;
			break;
		}
		if (c == 27) {
			//Neu nguoi dung nhap phim ESC thi thoat chuong trinh
			exit(1);
			break;
		}
		if (iCount == 3) {
			//Neu nguoi dung nhap sai 3 lan thi thoat chuong trinh
			exit(1);
			break;
		}
		cout << endl;
	} while (iCount < 3 && c != 27);
	cout << endl;
	cout << "\t\t\t\tDANG NHAP THANH CONG." << endl;
	system("pause");
	//=========================== Ket thuc dang nhap ==============================

	//===================== Menu chuc nang chinh cua chuong trinh =================
	while (true) {
		switch (mainMenu())
		{
		case 1: // Quan li sach
			while (true) {
				int iOption = subMenuSach();
				if (iOption == 4) break;
				switch (iOption)
				{
				case 1:
					//Them sach...
					break;
				case 2:
				{
					system("cls");
					cout << "2. Xoa Sach." << endl;
					cout << "\t\t";
					cout << "Nhap ma sach cua sach muon xoa: ";
					string masach;
					getline(cin,masach);
					if (masach.length() != 6 || masach.substr(0, 2) != "MS" || !isDigit(masach.substr(2, 4))) {
						setColor(4);
						cout << "\t\tMa sach khong hop le\n";
					}
					else {
						dsSach.xoaSach(masach);
					}
					setColor(7);
					if (!isContinue("\t\t")) return 0;
					break;
				}
				case 3:
					system("cls");
					setColor(7);
					cout << "3. Hien thi thong tin sach." << endl;
					cout << "Thoi gian hien tai: " << getCurrentDate() << endl;
					cout << "\t\t\t\t\t\t\t\t";
					setColor(2);
					cout << "THONG KE THONG TIN SACH: " << endl;

					dsSach.display();
					if (!isContinue("")) return 0;
					break;
				case 4:
					exit(1);
					break;
				case 0:
					if (XacNhan("\t\t\t\t","Thoat chuong trinh")) return 0;
					break;
				default:
					exit(1);
					break;
				}
			}
			break;
		case 2://Quan li phieu muon
			while (true) {
				int iOption = subMenuPhieuMuon();
				if (iOption == 4) break;
				switch (iOption)
				{
				case 1:
					//Them phieu muon...
					system("cls");
					setColor(4);
					dsPhieuMuon.muon();
					system("pause");
					system("cls");
					break;
				case 2:
					//Xoa phieu muon....
					system("cls");
					dsPhieuMuon.tra();
					break;
				case 3:
					//Thong ke phieu muon....
					system("cls");
					setColor(4);
					dsPhieuMuon.xuatConsole();
					break;
				case 4:
					exit(1);
					break;
				case 0:
					if (XacNhan("\t\t\t\t", "Thoat chuong trinh")) return 0;
					break;
				default:
					exit(1);
					break;
				}
			}
			break;
		case 3: // Quan li ban doc
			while (true) {
				int iOption = subMenuBanDoc();
				if (iOption == 4) break;
				switch (iOption)
				{
				case 1:
				{
					system("cls");
					cout << "1. Them ban doc." << endl;
					cout << "\t\t\t\t\t";
					setColor(2);
					cout << "NHAP THONG TIN BAN DOC: " << endl;
					string maBanDoc, hoTen, thoiGianDangKi;
					cout << "\t\t\t";
					setColor(7);
					cout << "Nhap CCCD hoac MSSV: ";
					while (getline(cin, maBanDoc)) {
						//Kiem tra khoang trang
						if (checkContainsSpacing(maBanDoc)) {
							setColor(4);
							cout << "\t\t\t";
							cout << "CCCD hoac MSSV khong duoc co khoang trang, vui long nhap lai!" << endl;
							setColor(7);
							cout << "\t\t\t";
							cout << "Nhap CCCD hoac MSSV: ";
							continue;
						}
						//Kiem tra chuoi co phai so khong
						if (!isDigit(maBanDoc)) {
							setColor(4);
							cout << "\t\t\t";
							cout << "CCCD hoac MSSV phai la so, vui long nhap lai! " << endl;
							setColor(7);
							cout << "\t\t\t";
							cout << "Nhap CCCD hoac MSSV: ";
							continue;
						}
						//Kiem tra CCCD du 12 so, MSSV du 10 so
						if (maBanDoc.length() == 12 || maBanDoc.length() == 10) {
							break;
						}
						setColor(4);
						cout << "\t\t\t";
						cout << "Vui long nhap du 12 so voi CCCD va 10 so voi MSSV!"<< endl;
						setColor(7);
						cout << "\t\t\t";
						cout << "Nhap CCCD hoac MSSV: ";
					}
					//Kiem tra xem ban doc da dang ki truoc do chua
					BanDoc* pReader = dsBanDoc.timkiemBanDoc(maBanDoc);

					if (pReader == NULL) {
						cout << "\t\t\t";
						cout << "Nhap ho ten: ";
						while(getline(cin, hoTen)) {
							if (hoTen.length() >= 2) {
								break;
							}
							setColor(4);
							cout << "\t\t\t";
							cout << "Ho Ten khong hop le, vui long nhap lai!" << endl;
							setColor(7);
							cout << "\t\t\t";
							cout << "Nhap Ho Ten: ";
						}
						hoTen = convertUpperCase(hoTen);
						thoiGianDangKi = getCurrentDate();
						BanDoc *newReader = new BanDoc();
						newReader->setMaBanDoc(maBanDoc);
						newReader->setTenBanDoc(hoTen);
						newReader->setTime(thoiGianDangKi);
						dsBanDoc.themBanDoc(*newReader);
						setColor(2);
						cout << "\t\t\t";
						cout << "Da dang ki thanh cong vao luc " << getCurrentDate() << " !" << endl;
						dsBanDoc.updateFile();
					}
					else {
						setColor(4);
						cout << "\t\t\t";
						cout << "Ban doc da dang ki !" << endl;
						cout << endl;
						setColor(2);
						cout << "\t\t\t";
						cout << "Thong tin ban doc:  " << endl;
						setColor(7);
						cout << "\t\t\tMa ban doc   :" << pReader->getMaBanDoc() << endl;
						cout << "\t\t\tHo ten       :" << pReader->getTenBanDoc() << endl;
						cout << "\t\t\tNgay dang ki :" << pReader->getTime() << endl;
					}
					if (!isContinue("\t\t\t")) return 0;
					break;
				}
				case 2:
				{
					system("cls");
					cout << "2. Xoa thong tin ban doc." << endl;
					cout << "\t\t\t\t\t";
					setColor(2);
					cout << "NHAP THONG TIN BAN DOC: " << endl;
					string maBanDoc, hoTen, thoiGianDangKi;
					cout << "\t\t\t";
					setColor(7);
					cout << "Nhap CCCD hoac MSSV: ";
					while (getline(cin, maBanDoc)) {
						//Kiem tra khoang trang
						if (checkContainsSpacing(maBanDoc)) {
							setColor(4);
							cout << "\t\t\t";
							cout << "CCCD hoac MSSV khong duoc co khoang trang, vui long nhap lai!" << endl;
							setColor(7);
							cout << "\t\t\t";
							cout << "Nhap CCCD hoac MSSV: ";
							continue;
						}
						//Kiem tra chuoi co phai so khong
						if (!isDigit(maBanDoc)) {
							setColor(4);
							cout << "\t\t\t";
							cout << "CCCD hoac MSSV phai la so, vui long nhap lai! " << endl;
							setColor(7);
							cout << "\t\t\t";
							cout << "Nhap CCCD hoac MSSV: ";
							continue;
						}
						//Kiem tra CCCD du 12 so, MSSV du 10 so
						if (maBanDoc.length() == 12 || maBanDoc.length() == 10) {
							break;
						}
						setColor(4);
						cout << "\t\t\t";
						cout << "Vui long nhap du 12 so voi CCCD va 10 so voi MSSV!" << endl;
						setColor(7);
						cout << "\t\t\t";
						cout << "Nhap CCCD hoac MSSV: ";
					}
					//Kiem tra xem ban doc da dang ki truoc do chua
					BanDoc* pReader = dsBanDoc.timkiemBanDoc(maBanDoc);

					if (pReader == NULL) {
						cout << "\t\t\t";
						setColor(4);
						cout << "Ban doc khong ton tai hoac chua dang ki, vui long kiem tra lai!" << endl;
					}
					else {
						setColor(2);
						cout << "\t\t\t";
						cout << "Thong tin ban doc tim duoc: " << endl;
						setColor(7);
						cout << "\t\t\tMa ban doc   :" << pReader->getMaBanDoc() << endl;
						cout << "\t\t\tHo ten       :" << pReader->getTenBanDoc() << endl;
						cout << "\t\t\tNgay dang ki :" << pReader->getTime() << endl;
						setColor(12);
						if (XacNhan("\t\t\t", "Ban co chac muon xoa")) {
							dsBanDoc.xoaBanDoc(maBanDoc);
							setColor(2);
							cout << "\t\t\t";
							cout << "Da xoa thanh cong vao luc " << getCurrentDate() << " !" << endl;
							dsBanDoc.updateFile();
						}
					}
					if (!isContinue("\t\t\t")) return 0;
					break;
				}
				case 3:
				{
					system("cls");
					setColor(7);
					cout << "3. Thong ke thong tin." << endl;
					cout << "Thoi gian hien tai: " << getCurrentDate() << endl;
					if (dsBanDoc.getSoBanDoc() == 0) {
						setColor(4);
						cout << dsBanDoc.getSize() << endl;
						cout << "\t\t\t\t\tChua co ban doc nao dang ki!" << endl;
					}
					else {
						cout << "\t\t\t\t\t";
						setColor(2);
						cout << "THONG KE THONG TIN BAN DOC: " << endl;

						dsBanDoc.thongKeBanDoc();
					}
					
					setColor(7);
					if (!isContinue("")) return 0;
					break;
				}
				case 0:
					if (XacNhan("\t\t\t\t", "Thoat chuong trinh")) return 0;
					break;
				default:
					break;
				}
			}
			break;
		case 0:
			if (XacNhan("\t\t\t\t","Thoat chuong trinh")) return 0;
			break;
		default:
			return 0;
			break;
		}
	}
	return 0;
}

