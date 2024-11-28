#include "DanhSachNhanVien.h"

/********************************************
* @Description Hàm xử lý đọc file cho Danh Sách Nhân Viên
********************************************/
template <class NhanVien>
void DanhSachNhanVien<NhanVien>::xuLyDocFile() {
	ifstream ifile("Admin.txt");
	if (!ifile) {
		cout << "Khong mo duoc file Admin.txt!" << endl;
		exit(1);
		return;
	}
	string s;
	while (getline(ifile, s)) {
		stringstream ss(s);
		string temp;
		vector<string> dataTemp;
		while (getline(ss, temp, '|')) {
			dataTemp.push_back(temp);
		}
		if (dataTemp.size() != 2) {
			continue;
		}
		NhanVien* newItem = new NhanVien(dataTemp[0], dataTemp[1]);
		LinkedList<NhanVien>::addTail(*newItem);
	}
	ifile.close();
}

/********************************************
* @Description Hàm tìm kiếm Nhân Viên cho Danh Sách Nhân Viên
* @parameter Chuỗi username và chuỗi password cần tìm
* @return Trả về giá trị địa chỉ của Nhân Viên tìm thấy, nếu không tìm thấy thì trả về NULL
********************************************/
template <class NhanVien>
NhanVien* DanhSachNhanVien<NhanVien>::timKiemNhanVien(string username, string password) {
	Node<NhanVien>* pWalker = LinkedList<NhanVien>::getHead();
	while (pWalker != NULL) {
		if (pWalker->_data.getUsername() == username && pWalker->_data.getPassword() == password) {
			return &(pWalker->_data);
		}
		pWalker = pWalker->_pNext;
	}
	return NULL;
}