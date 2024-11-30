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
void DanhSachSach<Sach>::updateFile() {
	ofstream os("Sach.txt", ios::out);
	if (!os.is_open()) {
		cout << "Khong mo duoc file!!!" << endl;
		return;
	}
	Node<Sach>* node = LinkedList<Sach>::getHead();
	if (node == NULL) {
		os.close();
		return;
	}
	while (node != NULL) {
		os << node->_data.toString() << endl;
		node = node->_pNext;
	}
	os.close();
}

/***********************************************************************************************
* @Description     Ghi nối thêm sách vào cuối file Sach.txt
* @parameter       Tên file txt
*************************************************************************************************/

template<class Sach>
void DanhSachSach<Sach>::themVaoFile(Node<Sach>* sachMoi) {
	ofstream os("Sach.txt", ios::app);
	if (!os.is_open()) {
		cout << "Khong mo duoc file!!!" << endl;
		return;
	}
	if (sachMoi != NULL) {
		os << sachMoi->_data.toString() << endl;
	}
	os.close();
}

/***********************************************************************************************
* @Description     Thêm sách vào danh sách
* @parameter       Sách cần thêm
*************************************************************************************************/

template<class Sach>
void DanhSachSach<Sach>::themSach(Sach sachMoi) {
	LinkedList<Sach>::addTail(sachMoi);
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
			cout << "+---------+-----------------+-------------------+------------------+---------------+------------------+----------+------------------+-----------------+" << endl;
		}
	}
}

/***********************************************************************************************
* @Description     Tìm sách trong danh sách sách theo mã sách
* @parameter       Mã sách cần tìm
* @return          Trả về địa chỉ của Sách nếu tìm thấy, NULL nếu không tìm thấy
*************************************************************************************************/

template<class Sach>
Sach* DanhSachSach<Sach>::timSach(string masach) {
	Node<Sach>* node = LinkedList<Sach>::getHead();
	while (node != NULL) {
		if (node->_data.getMaSach() == masach) {
			return &(node->_data);
		}
		node = node->_pNext;
	}
	return NULL;
}

/***********************************************************************************************
* @Description     Xóa sách trong danh sách sách theo mã sách
* @parameter       Mã sách cần xóa
* @attention       Nếu Danh sách sách rỗng hoặc sách đang được mượn thì thông báo ngoại lệ
*************************************************************************************************/

template<class Sach>
void DanhSachSach<Sach>::xoaSach(string masach) {
	Node<Sach>* pNode = LinkedList<Sach>::getHead();
	while (pNode != NULL) {
		if (pNode->_data.getMaSach() == masach) {
			LinkedList<Sach>::remove(pNode);
			setColor(2);
			return;
		}
		pNode = pNode->_pNext;
	}
	cout << "\t\tKhong co sach trong danh sach!" << endl;
}