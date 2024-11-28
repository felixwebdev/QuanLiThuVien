#pragma once
#include "Header.h"

class BanDoc {
private:
	string _strMaBanDoc;
	string _strTenBanDoc;
	string _strTime;
public:
	BanDoc();
	BanDoc(string maBanDoc, string tenBanDoc);
	string getMaBanDoc();
	string getTenBanDoc();
	string getTime();

	void setMaBanDoc(string MaBanDoc);
	void setTenBanDoc(string TenBanDoc);
	void setTime(string strTime);
};