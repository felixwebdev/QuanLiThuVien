#include "Header.h"

/********************************************
* @Description Hàm đổi màu chữ console
* @parameter Mã màu muốn đổi
*
0 = Black         8 = Gray
1 = Blue          9 = Light Blue
2 = Green         10 = Light Green
3 = Aqua          11 = Light Aqua
4 = Red           12 = Light Red
5 = Purple        13 = Light Purple
6 = Yellow        14 = Light Yellow
7 = White         15 = Bright White

********************************************/
void setColor(int color)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

/********************************************
* @Description Hàm đổi màu background và chữ console
* @parameter Mã màu muốn đổi
********************************************/
void setColor(int backgound_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}

/********************************************
* @Description Hàm lấy timestamp hiện tại
* @return Trả về timestamp hiện tại
********************************************/
long getCurrentTimestamp() {
	time_t now = time(0);
	return now;
}

/********************************************
* @Description Hàm chuyển đổi ngày tháng sang timestamp
* @parameter Ngày, tháng, năm, giờ, phút, giây
* @return Trả về timestamp của ngày tháng đó
********************************************/
long convertDateToTimestamp(int day, int month, int year, int hour = 0, int min = 0, int sec = 0) {
	struct tm  tm;
	time_t rawtime;
	time(&rawtime);
	tm = *localtime(&rawtime);
	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_hour = hour;
	tm.tm_min = min;
	tm.tm_sec = sec;
	tm.tm_mday = day;
	return mktime(&tm);
}

/********************************************
* @Description Hàm lấy ngày tháng hiện tại
* @return Trả về chuỗi ngày tháng hiện tại
********************************************/
string getCurrentDate() {
	string result = "";
	time_t now = time(0);
	tm* ltm = localtime(&now);
	string day, month, year, hour, min;
	stringstream days;
	days << ltm->tm_mday;
	days >> day;
	stringstream months;
	months << (1 + ltm->tm_mon);
	months >> month;
	stringstream years;
	years << (1900 + ltm->tm_year);
	years >> year;
	stringstream hours;
	hours << ltm->tm_hour;
	hours >> hour;
	stringstream mins;
	mins << ltm->tm_min;
	mins >> min;
	if (1 + ltm->tm_mon < 10) {
		month = "0" + month;
	}
	if (ltm->tm_mday < 10) {
		day = "0" + day;
	}
	if (ltm->tm_hour < 10) {
		hour = "0" + hour;
	}
	if (ltm->tm_min < 10) {
		min = "0" + min;
	}
	result = day + "/" + month + "/" + year + " " + hour + ":" + min;
	return result;
}


/********************************************
* @Description Hàm xóa khoảng trắng và chuyển thành chữ UpperCase
* @parameter Một chuỗi cần chuyển
* @return Trả về chuỗi sau khi thực hiện
********************************************/
string convertUpperCaseAndDeleteSpace(string x) {
	string result = "";
	for (int i = 0; i < x.size(); i++) {
		if (x[i] >= 'a' && x[i] <= 'z') {
			x[i] = x[i] - 32;
		}
		if (x[i] != ' ') {
			result = result + x[i];
		}
	}
	return result;
}

/********************************************
* @Description Hàm chuyển thành chữ UpperCase
* @parameter Một chuỗi cần chuyển
* @return Trả về chuỗi sau khi thực hiện
********************************************/
string convertUpperCase(string x) {
	for (int i = 0; i < x.size(); i++) {
		if (x[i] >= 'a' && x[i] <= 'z') {
			x[i] = x[i] - 32;
		}
	}
	return x;
}

/********************************************
* @Description Hàm mã hóa chuỗi thành dấu "*"
* @parameter Độ dài của chuỗi tối đa
* @return Trả về chuỗi gốc nhưng hiển thị màn hình thành dấu "*"
********************************************/
string passwordInput(int maxLength) {
	string pw = "";
	for (char c; (c = getch()); )
	{
		if (c == '\n' || c == '\r') {
			cout << "\n";
			break;
		}
		else if (c == '\b') {
			if (!pw.empty()) {
				pw.erase(pw.size() - 1);
				cout << "\b \b";
			}
		}
		else if (isprint(c) && pw.size() < maxLength) {
			cout << '*';
			pw += c;
		}
	}
	return pw;
}

/********************************************
* @Description Hàm kiểm tra chuỗi có chứa khoảng trắng hay không
* @parameter Một chuỗi cần kiểm tra
* @return Trả về true nếu chuỗi có khoảng trắng, ngược lại trả về false
********************************************/
bool checkContainsSpacing(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			return true;
		}
	}
	return false;
}

/********************************************
* @Description Hàm kiểm tra chuỗi có bao gồm các kí tự số hay không
* @parameter Một chuỗi cần kiểm tra
* @return Trả về true nếu chuỗi toàn kí tự số, ngược lại trả về false
********************************************/
bool checkIsNumberString(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] < '0' || s[i] > '9') {
			return false;
		}
	}
	return true;
}


/********************************************
* @Description Hàm hiển thị menu đăng nhập
* @parameter Chuỗi username và password
********************************************/
void DangNhap(string& username, string& password) {
	setColor(6);
	cout << setfill('*');
	cout << "\t\t\t\t";
	cout << setw(50) << "*" << endl;
	cout << setfill(' ');
	setColor(7);
	setColor(6);
	cout << "\t\t\t\t";
	cout << "*";
	setColor(7);

	setColor(2);
	cout << "              DANG NHAP HE THONG                ";
	setColor(7);
	setColor(6);
	cout << "*" << endl;
	setColor(7);
	setColor(6);
	cout << setfill('*');
	cout << "\t\t\t\t";
	cout << setw(50) << "*" << endl;
	cout << setfill(' ');
	setColor(7);
	setColor(2);
	cout << "\t\t\t\t";
	cout << "     User";
	setColor(7);
	cout << ":     ";
	getline(cin, username);
	cout << endl;
	setColor(2);
	cout << "\t\t\t\t";
	cout << "     Password";
	setColor(7);
	cout << ": ";
	password = passwordInput(10);
}


/********************************************
* @Description Hàm hiển thị menu chức năng của nhân viên
* @return Trả về số nguyên là lựa chọn của người dùng
********************************************/
int mainMenu() {
	system("cls");
	setColor(2);
	cout << "\t\t\t\t\t";
	cout << "MENU CHUC NANG" << endl;

	setColor(7);
	cout << setfill('-');
	cout << "\t\t\t +";
	setColor(14);
	cout << setw(47) << "+" << endl;
	cout << setfill(' ');
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "1. Quan li Sach.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "2. Quan li phieu muon.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "3. Quan li ban doc.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "0. Thoat chuong trinh.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "Moi ban chon thao tac:";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << setfill('-');
	cout << "\t\t\t +";
	setColor(7);
	setColor(14);
	cout << setw(47) << "+" << endl;
	cout << setfill(' ');

	setColor(7);
	string choose;
	cout << "\t\t\t\tNhap thao tac muon chon: ";
	getline(cin, choose);
	while (choose.length() == 0) {
		cout << "\t\t\t\tVui long nhap thao tac: ";
		getline(cin, choose);
	}
	while (!isDigit(choose) || stoi(choose) < 0 || stoi(choose) > 3) {
		setColor(4);
		cout << "\t\t\t\tVui long chon nhung muc co trong menu ( 0 - > 3 )!\n";
		setColor(7);
		cout << "\t\t\t\tNhap thao tac muon chon: ";
		getline(cin, choose);
	}
	return stoi(choose);
}

/********************************************
* @Description Hàm hiển thị menu chức năng quản lí sách của nhân viên
* @return Trả về số nguyên là lựa chọn của người dùng
********************************************/
int subMenuSach() {
	system("cls");
	setColor(2);
	cout << "\t\t\t\t\t";
	cout << "QUAN LI SACH" << endl;

	setColor(7);
	cout << setfill('-');
	cout << "\t\t\t +";
	setColor(14);
	cout << setw(47) << "+" << endl;
	cout << setfill(' ');
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "1. Them 1 cuon sach.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "2. Xoa 1 cuon sach.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "3. Thong ke sach.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "4. Quay lai menu chinh.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "0. Thoat chuong trinh.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "Moi ban chon thao tac:";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << setfill('-');
	cout << "\t\t\t +";
	setColor(7);
	setColor(14);
	cout << setw(47) << "+" << endl;
	cout << setfill(' ');

	setColor(7);
	string choose;
	cout << "\t\t\t\tNhap thao tac muon chon: ";
	getline(cin, choose);
	while (choose.length() == 0) {
		cout << "\t\t\t\tVui long nhap thao tac: ";
		getline(cin, choose);
	}
	while (!isDigit(choose) || stoi(choose) < 0 || stoi(choose) > 4) {
		setColor(4);
		cout << "\t\t\t\tVui long chon nhung muc co trong menu ( 0 - > 4 )!\n";
		setColor(7);
		cout << "\t\t\t\tNhap thao tac muon chon: ";
		getline(cin, choose);
	}
	return stoi(choose);
}

/********************************************
* @Description Hàm hiển thị menu chức năng quản lí phiếu mượn của nhân viên
* @return Trả về số nguyên là lựa chọn của người dùng
********************************************/
int subMenuPhieuMuon() {
	system("cls");
	setColor(2);
	cout << "\t\t\t\t\t";
	cout << "QUAN Li PHIEU MUON" << endl;

	setColor(7);
	cout << setfill('-');
	cout << "\t\t\t +";
	setColor(14);
	cout << setw(47) << "+" << endl;
	cout << setfill(' ');
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "1. Muon sach.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "2. Tra sach.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "3. Thong ke phieu muon.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "4. Quay lai menu chinh.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "0. Thoat chuong trinh.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "Moi ban chon thao tac:";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << setfill('-');
	cout << "\t\t\t +";
	setColor(7);
	setColor(14);
	cout << setw(47) << "+" << endl;
	cout << setfill(' ');

	setColor(7);
	string choose;
	cout << "\t\t\t\tNhap thao tac muon chon: ";
	getline(cin, choose);
	while (choose.length() == 0) {
		cout << "\t\t\t\tVui long nhap thao tac: ";
		getline(cin, choose);
	}
	while (!isDigit(choose) || stoi(choose) < 0 || stoi(choose) > 4) {
		setColor(4);
		cout << "\t\t\t\tVui long chon nhung muc co trong menu ( 0 - > 4 )!\n";
		setColor(7);
		cout << "\t\t\t\tNhap thao tac muon chon: ";
		getline(cin, choose);
	}
	return stoi(choose);
}

/********************************************
* @Description Hàm hiển thị menu chức năng quản lí bạn đọc của nhân viên
* @return Trả về số nguyên là lựa chọn của người dùng
********************************************/
int subMenuBanDoc() {
	system("cls");
	setColor(2);
	cout << "\t\t\t\t\t";
	cout << "QUAN LI BAN DOC" << endl;

	setColor(7);
	cout << setfill('-');
	cout << "\t\t\t +";
	setColor(14);
	cout << setw(47) << "+" << endl;
	cout << setfill(' ');
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "1. Them ban doc.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "2. Xoa ban doc. ";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "3. Thong ke ban doc.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "4. Quay lai menu chinh.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "0. Thoat chuong trinh.";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << "\t\t\t";
	cout << " |";
	cout << "\t";

	setColor(7);
	cout << "Moi ban chon thao tac:";
	setColor(14);
	cout << "\t\t\t";
	cout << "|";
	cout << endl;
	cout << setfill('-');
	cout << "\t\t\t +";
	setColor(7);
	setColor(14);
	cout << setw(47) << "+" << endl;
	cout << setfill(' ');

	setColor(7);
	string choose;
	cout << "\t\t\t\tNhap thao tac muon chon: ";
	getline(cin, choose);
	while (choose.length() == 0) {
		cout << "\t\t\t\tVui long nhap thao tac: ";
		getline(cin, choose);
	}
	while (!isDigit(choose) || stoi(choose) < 0 || stoi(choose) > 4) {
		setColor(4);
		cout << "\t\t\t\tVui long chon nhung muc co trong menu ( 0 - > 4 )!\n";
		setColor(7);
		cout << "\t\t\t\tNhap thao tac muon chon: ";
		getline(cin, choose);
	}
	return stoi(choose);
}

/********************************************
* @Description Hàm xử lí các tác vụ quyết định của người dùng
* @parameter số lần tab, nội dung cần xác nhận
* @return True nếu người dùng chọn yes, ngược lại là false
********************************************/
bool XacNhan(string tab, string mess) {
	string strB;
	setColor(4);
	cout << tab << mess << " (yes / no) ? " << " ";
	setColor(7);
	getline(cin, strB);
	while (strB.length() == 0 || convertUpperCase(strB) != "YES" && convertUpperCase(strB) != "NO") {
		setColor(4);
		cout << tab << "Vui long nhap dung (yes / no) ";
		setColor(7);
		getline(cin, strB);
	}
	if (convertUpperCase(strB) == "YES") return 1;
	return 0;
}

/********************************************
* @Description Hàm kiểm tra một chuỗi có phải là số không
* @parameter Một chuỗi cần kiẻm tra
* @return True nếu là số, False nếu không phải
********************************************/
bool isDigit(string strInt) {
	if (strInt.empty()) return false;
	for (auto x : strInt) {
		if (!isdigit(x)) return false;
	}
	return true;
}

/********************************************
* @Description Hàm xử lí các tác vụ xác nhận của người dùng
* @parameter số lần thụt lề
* @return True nếu người dùng bấm phím bất kì, false nếu bấm ESC
********************************************/
bool isContinue(string ntab) {
	char c;
	setColor(2);
	cout << ntab << "Nhan phim ESC de thoat hoac phim bat ki de tiep tuc!";
	setColor(7);
	c = getch();
	if (c == 27) return 0;
	return 1;
}

/********************************************
* @Description Hàm thêm một số ngày vào một ngày cụ thể.
* @parameter day Ngày ban đầu.
* @parameter month Tháng ban đầu.
* @parameter year Năm ban đầu. 
* @parameter daysToAdd Số ngày cần thêm vào.
* @return Trả về một chuỗi biểu diễn ngày mới dưới định dạng "dd/mm/yyyy".
********************************************/

string addDaysToDate(int day, int month, int year, int addDays) {
	tm date = { 0 };
	date.tm_mday = day;
	date.tm_mon = month - 1; 
	date.tm_year = year - 1900;

	time_t rawTime = mktime(&date);
	rawTime += addDays * 24 * 3600; 

	tm* newDate = localtime(&rawTime);
	stringstream result;
	result << setfill('0') << setw(2) << newDate->tm_mday << "/"
		<< setfill('0') << setw(2) << (newDate->tm_mon + 1) << "/"
		<< (newDate->tm_year + 1900);
	return result.str();
}

/********************************************
* @Description Hàm kiểm tra xem mã sách có tồn tại trong file Sach.txt hay không
* @parameter maSach: Một chuỗi chứa mã sách cần kiểm tra
* @return Trả về true nếu mã sách tồn tại, ngược lại trả về false
********************************************/

bool kiemTraSachTonTai(const string& maSach) {
	ifstream file("Sach.txt"); 
	string line;

	while (getline(file, line)) {
		
		stringstream ss(line);
		string maSachTu ;
		getline(ss, maSachTu, '|'); 

		if (maSachTu == maSach) { 
			file.close();
			return true; 
		}
	}
	file.close();
	return false; 
}

/********************************************
* @Description Hàm kiểm tra xem mã bạn đọc có tồn tại trong file BanDoc.txt hay không
* @parameter maBanDoc: Một chuỗi chứa mã bạn đọc cần kiểm tra
* @return Trả về true nếu mã bạn đọc tồn tại, ngược lại trả về false
********************************************/

bool kiemTraBanDocTonTai(const string& maBanDoc) {
	ifstream file("BanDoc.txt"); 
	string line;

	while (getline(file, line)) {
		stringstream ss(line);
		string maBanDocTuDòng;
		getline(ss, maBanDocTuDòng, '|'); 

		if (maBanDocTuDòng == maBanDoc) { 
			file.close();
			return true; 
		}
	}
	file.close();
	return false; 
}
