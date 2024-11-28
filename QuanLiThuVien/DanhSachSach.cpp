#include "DanhSachSach.h"
#include "LinkedList.h"


/***********************************************************************************************
* @Description     Lấy dữ liệu file txt
* @parameter       Tên file txt
*************************************************************************************************/

template<class Sach>
void DanhSachSach<Sach>::docFile() {
	ifstream is("Sach.txt");
	if (!is.is_open()) {
		cout << "Khong mo duoc file!!!" << endl;
		exit(1);
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
		if (v.size() != 9) continue;
		Sach sach(v[0], v[1], v[2], v[3], stoi(v[4]), stoi(v[5]), stoi(v[6]), v[7], stoi(v[8]));
		LinkedList<Sach>::addTail(sach);

	}
	is.close();
}

/***********************************************************************************************
* @Description     Ghi đè lên file txt
* @parameter       Tên file txt
*************************************************************************************************/

template<class Sach>
void DanhSachSach<Sach>::xuatFile() {
	ofstream os("Sach.txt");
	if (!os.is_open()) {
		cout << "Khong mo duoc file!!!" << endl;
		return;
	}
	Node<Sach>* node = LinkedList<Sach>::getHead();
	while (node != NULL) {
		os << node << endl;
		node = node->_pNext;
	}
	os.close();
}

/***********************************************************************************************
* @Description     Xuất Danh Sach Sach ra màn hình
*************************************************************************************************/

template<class Sach>
void DanhSachSach<Sach>::display() {
	Node<Sach>* sach = LinkedList<Sach>::getHead();
	if (sach == NULL) return;
	else {
		setColor(14);
		cout << "+---------+-----------------+-------------------+------------------+---------------+------------------+----------+------------------+-----------------+" << endl;
		cout << "| Ma Sach | Ten Sach        | Ten Tac Gia       | Nha Xuat Ban     | Gia Sach      | Nam Phat Hanh    | So Trang | Ngay Nhap Kho    | Tinh Trang Sach |" << endl;
		cout << "+---------+-----------------+-------------------+------------------+---------------+------------------+----------+------------------+-----------------+" << endl;
		while (sach != NULL) {
			sach->_data.display();
			sach = sach->_pNext;
		}
		cout << "+---------+-----------------+-------------------+------------------+---------------+------------------+----------+------------------+-----------------+" << endl;
	}
}

/***********************************************************************************************
* @Description     Tìm sách trong danh sách sách theo mã sách
* @parameter       Mã sách cần tìm
* @return          Trả về địa chỉ của Sách nếu tìm thấy, NULL nếu không tìm thấy
*************************************************************************************************/

template<class Sach>
Node<Sach>* DanhSachSach<Sach>::timSach(string masach) {
	Node<Sach>* node = LinkedList<Sach>::getHead();
	while (node != NULL && node->_data.getMaSach() != masach) {
		node = node->_pNext;
	}
	return node;
}

/***********************************************************************************************
* @Description     Tìm sách đứng trước sách cần tìm trong danh sách sách
* @parameter       Node của sách cần tìm
* @return          Trả về địa chỉ của Sách nếu tìm thấy, NULL nếu không tìm thấy
*************************************************************************************************/

template<class Sach>
Node<Sach>* DanhSachSach<Sach>::timSachPre(Node<Sach>* sach) {
	Node<Sach>* node = LinkedList<Sach>::getHead();
	if (sach == node) return NULL;
	while (node->_pNext != NULL && node->_pNext != sach) {
		node = node->_pNext;
	}
	return node;
}

/***********************************************************************************************
* @Description     Xóa sách trong danh sách sách theo mã sách
* @parameter       Mã sách cần xóa
* @attention       Nếu Danh sách sách rỗng hoặc sách đang được mượn thì thông báo ngoại lệ
*************************************************************************************************/

template<class Sach>
void DanhSachSach<Sach>::xoaSach(string masach) {
	Node<Sach>* sach = timSach(masach);
	setColor(4);
	if (sach->_data.getTinhTrangSach() != 0) {
		cout << "\t\tKhong the xoa sach do sach dang duoc muon!" << endl;
		return;
	}
	if (sach == NULL) {
		cout << "\t\tKhong co sach trong danh sach!" << endl;
		return;
	}
	LinkedList<Sach>::remove(sach);
	setColor(2);
	cout << "\t\tDa xoa sach thanh cong." << endl;
}