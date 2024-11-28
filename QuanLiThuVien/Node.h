#pragma once
template <class DataType>
class LinkedList;
template <class DataType>
class DanhSachNhanVien;
template <class DataType>
class DanhSachBanDoc;
template <class DataType>
class DanhSachSach;

template <class DataType>
class Node {
	friend class LinkedList<DataType>;
	friend class DanhSachBanDoc<DataType>;
	friend class DanhSachNhanVien<DataType>;
	friend class DanhSachSach<DataType>;
	DataType _data;
	Node* _pNext;
public:
	Node(DataType data);
	void display();
	void displayDetail();

};