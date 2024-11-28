#include "DanhSachBanDoc.h"

/********************************************
* @Description Hàm tìm kiếm bạn đọc theo mã bạn đọc
* @parameter Chuỗi mã bạn đọc cần tìm
* @return Trả về node lưu bạn độc tìm thấy, nếu không trả về NULL
********************************************/
template <class BanDoc>
BanDoc* DanhSachBanDoc<BanDoc>::timkiemBanDoc(string maBanDoc) {
	if (listBanDoc.getSize() == 0) {
		return NULL;
	}
	Node<BanDoc>* pWalker = listBanDoc.getHead();
	while (pWalker != NULL) {
		if (pWalker->_data.getMaBanDoc() == maBanDoc) {
			return &(pWalker->_data);
		}
		pWalker = pWalker->_pNext;
	}
	return NULL;
}

/********************************************
* @Description Hàm thêm bạn đọc
* @parameter Bạn đọc mới cần thêm
********************************************/
template <class BanDoc>
void DanhSachBanDoc<BanDoc>::themBanDoc(BanDoc newBanDoc) {
	listBanDoc.addTail(newBanDoc);
}

/********************************************
* @Description Hàm xóa bạn đọc
* @parameter Chuỗi là mã bạn đọc cần xóa 
********************************************/
template <class BanDoc>
void DanhSachBanDoc<BanDoc>::xoaBanDoc(string maBanDoc) {
	if (listBanDoc.getSize() == 0) {
		return;
	}
	Node<BanDoc>* pWalker = listBanDoc.getHead();
	while (pWalker != NULL) {
		if (pWalker->_data.getMaBanDoc() == maBanDoc) {
			listBanDoc.remove(pWalker);
			return;
		}
		pWalker = pWalker->_pNext;
	}
	cout << "Ban doc khong ton tai!!";
}

/********************************************
* @Description Hàm trả về số lượng bạn đọc đã đăng kí
* @return trả về số nguyên là số lượng bạn đọc đã đăng kí
********************************************/
template <class BanDoc>
int DanhSachBanDoc<BanDoc>::getSoBanDoc() {
	return listBanDoc.getSize();
}

/********************************************
* @Description Hàm xử lí đọc file danh sách bạn đọc
********************************************/
template <class BanDoc>
void DanhSachBanDoc<BanDoc>::xuLyDocFile() {
	ifstream inFile("BanDoc.txt");
	if (!inFile) {
		cout << "Khong mo duoc file BanDoc.txt!!" << endl;
		exit(1);
		return;
	}
	string s;
	while (getline(inFile, s)) {
		stringstream ss(s);
		string stmp;
		vector<string> vtData;
		while (getline(ss, stmp, '|')) {
			vtData.push_back(stmp);
		}
		BanDoc newItem = BanDoc();
		if (vtData.size() != 3) continue;
		newItem.setMaBanDoc(vtData[0]);
		newItem.setTenBanDoc(vtData[1]);
		newItem.setTime(vtData[2]);

		listBanDoc.addTail(newItem);
	}
	inFile.close();
}

/********************************************
* @Description Hàm xử lí cập nhật file danh sách bạn đọc
********************************************/
template <class BanDoc>
void DanhSachBanDoc<BanDoc>::updateFile() {
	ofstream ofFile;
	ofFile.open("BanDoc.txt", ios::out);
	Node<BanDoc>* pWalker;
	for (pWalker = listBanDoc.getHead(); pWalker != NULL; pWalker = pWalker->_pNext) {
		ofFile << pWalker->_data.getMaBanDoc() << '|' << pWalker->_data.getTenBanDoc() << "|" 
			 << pWalker->_data.getTime() << endl;
	}
	ofFile.close();
}

/********************************************
* @Description Hàm in ra danh sách thông tin bạn đọc
********************************************/
template <class BanDoc>
void DanhSachBanDoc<BanDoc>::thongKeBanDoc() {
	setColor(14);
	cout << "\t+--------------------+-----------------------------------+---------------------+" << endl;
	cout << "\t|     Ma Ban Doc     |          Ten Ban Doc              |     Ngay Dang Ky    |" << endl;
	cout << "\t+--------------------+-----------------------------------+---------------------+" << endl;

	Node<BanDoc>* pWalker;
	for (pWalker = listBanDoc.getHead(); pWalker != NULL; pWalker = pWalker->_pNext) {
		cout << "\t| ";
		setColor(7);
		cout << left << setw(18) << pWalker->_data.getMaBanDoc();
		setColor(14);
		cout << " | ";
		setColor(7);
		cout << left << setw(34) << pWalker->_data.getTenBanDoc();
		setColor(14);
		cout << "| ";
		setColor(7);
		cout << left << setw(20) << pWalker->_data.getTime();
		setColor(14);
		cout << "|" << endl;
		cout << "\t+--------------------+-----------------------------------+---------------------+" << endl;
	}
}