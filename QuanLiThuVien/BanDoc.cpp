#include "BanDoc.h"

BanDoc::BanDoc() {
	_strMaBanDoc = "";
	_strTenBanDoc = "";
	_strTime = "";
}

BanDoc::BanDoc(string maBanDoc, string tenBanDoc) {
	_strMaBanDoc = maBanDoc;
	_strTenBanDoc = tenBanDoc;
}

string BanDoc::getMaBanDoc() { return _strMaBanDoc; }
string BanDoc::getTenBanDoc() { return _strTenBanDoc; }
string BanDoc::getTime() { return _strTime; }

void BanDoc::setMaBanDoc(string MaBanDoc) {
	_strMaBanDoc = MaBanDoc;
}
void BanDoc::setTenBanDoc(string TenBanDoc) {
	_strTenBanDoc = TenBanDoc;
}
void BanDoc::setTime(string strTime) {
	_strTime = strTime;
}