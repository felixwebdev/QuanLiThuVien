#include "Header.h"
#include "BanDoc.h"
#include "NhanVien.h"
#include "Sach.h"
#include "Node.h"
#include "PhieuMuon.cpp"
#include "Node.cpp"
#include "LinkedList.cpp"
#include "DanhSachBanDoc.cpp"
#include "DanhSachNhanVien.cpp"
#include "DanhSachSach.cpp"
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
			if (3 - iCount > 0) {
			 cout << endl << "\t\t\tSai tai khoan hoac mat khau! Ban con " << 3 - iCount << " lan nhap. \n \t\t\tNhan phim ESC de thoat hoac phim bat ki de tiep tuc dang nhap!" << endl;
			}
			else {
			 cout << endl << "\t\t\tSai tai khoan hoac mat khau! Ban da het luot dang nhap!. \n \t\t\tNhan phim phim bat ki de thoat!" << endl;
			}
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
				case 1: //Them sach...
				{
					system("cls");
					cout << "1. Them Sach." << endl;
					cout << "\t\t\t\t\t";
					setColor(2);
					cout << "NHAP THONG TIN SACH: " << endl;
					cout << "\t\t\t";
					setColor(7);

					string maSach, tenSach, tenTacGia, nhaXuatBan, ngayNhapKho = getCurrentDate(), giaSach, namPhatHanh, soTrang;
					int tinhTrangSach = 0;

					// Nhập mã sách
					cout << "Ma sach (MSxxxx): ";
					while (getline(cin, maSach)) {
						// Kiem tra khoang cach trong maSach
						if (checkContainsSpacing(maSach)) {
							setColor(4);
							cout << "\t\t\t";
							cout << "Ma Sach khong duoc co khoang trang, vui long nhap lai!" << endl;
							setColor(7);
							cout << "\t\t\t";
							cout << "Ma Sach (MSxxxx): ";
							continue;
						}
						// Kiem tra tinh hop le cua ma sach
						if (maSach.substr(0, 2) != "MS" || !isDigit(maSach.substr(2, 4))) {
							setColor(4);
							cout << "\t\t\t";
							cout << "Ma Sach phai theo dinh dang (MSxxxx) \n\t\t\tVoi xxxx la 4 so tu nhien! " << endl;
							setColor(7);
							cout << "\t\t\t";
							cout << "Ma Sach (MSxxxx): ";
							continue;
						}
						// Kiem tra ma sach du 6 ki tu
						if (maSach.length() == 6) {
							break;
						}
						setColor(4);
						cout << "\t\t\t";
						cout << "Vui long nhap Ma Sach voi du 6 ki tu!" << endl;
						setColor(7);
						cout << "\t\t\t";
						cout << "Ma Sach (MSxxxx): ";
					}

					// Kiem tra ma sach da ton tai chua
					Sach* SachTonTai = dsSach.timSach(maSach);

					if (SachTonTai == NULL) {
						cout << "\t\t\t";
						cout << "Ten sach: ";
						while (getline(cin, tenSach)) {
							if (tenSach.length() != 0) {
								break;
							}
							setColor(4);
							cout << "\t\t\t";
							cout << "Ten Sach khong duoc de trong!!!\n";
							setColor(7);
							cout << "\t\t\t";
							cout << "Ten sach: ";
						}
						cout << "\t\t\tTen tac gia: ";
						while (getline(cin, tenTacGia)) {
							if (tenTacGia.length() != 0) {
								break;
							}
							setColor(4);
							cout << "\t\t\t";
							cout << "Ten Tac Gia khong duoc de trong!!!\n";
							setColor(7);
							cout << "\t\t\t";
							cout << "Ten tac gia: ";
						}
						cout << "\t\t\tNha xuat ban: ";
						while (getline(cin, nhaXuatBan)) {
							if (nhaXuatBan.length() != 0) {
								break;
							}
							setColor(4);
							cout << "\t\t\t";
							cout << "Nha Xuat Ban khong duoc de trong!!!\n";
							setColor(7);
							cout << "\t\t\t";
							cout << "Nha xuat ban: ";
						}
						cout << "\t\t\tGia sach: ";
						while (getline(cin, giaSach)) {
							if (giaSach.length() == 0)
							{
								setColor(4);
								cout << "\t\t\t";
								cout << "Gia sach khong duoc de trong!!!\n";
								setColor(7);
								cout << "\t\t\t";
								cout << "Gia sach: ";
								continue;
							}
							if (checkContainsSpacing(giaSach)) {
								setColor(4);
								cout << "\t\t\t";
								cout << "Gia sach khong duoc co khoang trang, vui long nhap lai!" << endl;
								setColor(7);
								cout << "\t\t\tGia sach: ";
								continue;
							}
							if (isDigit(giaSach)) {
								break;
							}
							setColor(4);
							cout << "\t\t\t";
							cout << "Gia sach phai la so! Vui long nhap lai!" << endl;
							setColor(7);
							cout << "\t\t\tGia sach: ";
						}
						cout << "\t\t\tNam phat hanh: ";
						while (getline(cin, namPhatHanh)) {
							if (namPhatHanh.length() == 0) {
								setColor(4);
								cout << "\t\t\t";
								cout << "Nam phat hanh khong duoc de trong!!!" << endl;
								setColor(7);
								cout << "\t\t\tNam phat hanh: ";
								continue;
							}
							if (checkContainsSpacing(namPhatHanh)) {
								setColor(4);
								cout << "\t\t\t";
								cout << "Nam phat hanh khong duoc co khoang trang, vui long nhap lai!" << endl;
								setColor(7);
								cout << "\t\t\tNam phat hanh: ";
								continue;
							}
							if (isDigit(namPhatHanh)) {
								break;
							}
							setColor(4);
							cout << "\t\t\t";
							cout << "Nam phat hanh phai la so! Vui long nhap lai!" << endl;
							setColor(7);
							cout << "\t\t\tNam phat hanh: ";
						}
						cout << "\t\t\tSo trang sach: ";
						while (getline(cin, soTrang)) {
							if (soTrang.length() == 0) {
								setColor(4);
								cout << "\t\t\t";
								cout << "So trang sach khong duoc de trong!!!" << endl;
								setColor(7);
								cout << "\t\t\tSo trang sach: ";
								continue;
							}
							if (checkContainsSpacing(soTrang)) {
								setColor(4);
								cout << "\t\t\t";
								cout << "So trang sach khong duoc co khoang trang, vui long nhap lai!" << endl;
								setColor(7);
								cout << "\t\t\tSo trang sach: ";
								continue;
							}
							if (isDigit(soTrang)) {
								break;
							}
							setColor(4);
							cout << "\t\t\t";
							cout << "So trang sach phai la so! Vui long nhap lai!" << endl;
							setColor(7);
							cout << "\t\t\tSo trang sach: ";
						}
						cout << "\t\t\tNgay nhap kho: " << ngayNhapKho << endl;
						cout << "\t\t\tTinh trang sach: " << tinhTrangSach << endl;

						Sach sachMoi(maSach, tenSach, tenTacGia, nhaXuatBan, stoi(giaSach), stoi(namPhatHanh), stoi(soTrang), ngayNhapKho, tinhTrangSach);
						dsSach.themSach(sachMoi);
						setColor(2);
						cout << "\t\t\tThem sach moi thanh cong!" << endl;
						Node<Sach>* NodeSachMoi = new Node<Sach>(sachMoi);
						dsSach.themVaoFile(NodeSachMoi);

					}
					else {
						setColor(4);
						cout << "\t\t\t";
						cout << "Ma Sach da ton tai, vui long nhap lai!" << endl;
					}

					if (!isContinue("\t\t\t")) return 0;
					break;
				}
				case 2:
				{
					system("cls");
					cout << "2. Xoa Sach." << endl;
					cout << "\t\t\t\t\t";
					setColor(2);
					cout << "NHAP THONG TIN SACH: " << endl;
					setColor(7);

					cout << "\t\t\t";
					cout << "Ma Sach: ";
					string masach;
					getline(cin, masach);
					if (masach.length() != 6 || masach.substr(0, 2) != "MS" || !isDigit(masach.substr(2, 4))) {
						setColor(4);
						cout << "\t\t\tMa sach khong hop le. vui long nhap lai!\n";
					}
					else {
						Sach* sach = dsSach.timSach(masach);
						if (sach != NULL) {
							setColor(2);
							cout << "\t\t\tThong tin sach tim duoc: " << endl;
							setColor(7);
							cout << "\t\t\tTen Sach: " << sach->getTenSach() << endl;
							cout << "\t\t\tTac Gia: " << sach->getTenTacGia() << endl;
							cout << "\t\t\tNha Xuat Ban: " << sach->getNhaXuatBan() << endl;
							cout << "\t\t\tGia sach: " << sach->getGiaSach() << endl;
							cout << "\t\t\tNam phat hanh: " << sach->getNamPhatHanh() << endl;
							cout << "\t\t\tSo trang: " << sach->getSoTrang() << endl;
							cout << "\t\t\tNgay nhap kho: " << sach->getNgayNhapKho() << endl;
							if (XacNhan("\t\t\t", "Ban co chac muon xoa")) {
								dsSach.xoaSach(masach);
								setColor(2);
								cout << "\t\t\t";
								cout << "Da xoa thanh cong vao luc " << getCurrentDate() << " !" << endl;
								dsSach.updateFile();
							}
						}
						else {
							setColor(4);
							cout << "\t\t\tKhong tim thay sach trong danh sach. Vui long kiem tra lai!" << endl;
						}
					}
					setColor(7);
					if (!isContinue("\t\t\t")) return 0;
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
					if (XacNhan("\t\t\t\t", "Thoat chuong trinh")) return 0;
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
						cout << "Vui long nhap du 12 so voi CCCD va 10 so voi MSSV!" << endl;
						setColor(7);
						cout << "\t\t\t";
						cout << "Nhap CCCD hoac MSSV: ";
					}
					//Kiem tra xem ban doc da dang ki truoc do chua
					BanDoc* pReader = dsBanDoc.timkiemBanDoc(maBanDoc);

					if (pReader == NULL) {
						cout << "\t\t\t";
						cout << "Nhap ho ten: ";
						while (getline(cin, hoTen)) {
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
						BanDoc* newReader = new BanDoc();
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
			if (XacNhan("\t\t\t\t", "Thoat chuong trinh")) return 0;
			break;
		default:
			return 0;
			break;
		}
	}
	return 0;
}

