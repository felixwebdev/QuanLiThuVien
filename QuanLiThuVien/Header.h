#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <conio.h>
#include<stdlib.h>
#include <ctime>
#pragma warning(disable:4996)
const int MAX_SIZE = 100;
const int MAX_SO_LUONG_VE = 100;
using namespace std;

void setColor(int color);
void setColor(int backgound_color, int text_color);

long getCurrentTimestamp();
long convertDateToTimestamp(int day, int month, int year, int hour, int min, int sec);
string getCurrentDate();
string convertUpperCaseAndDeleteSpace(string x);
string convertUpperCase(string x);
string passwordInput(int maxLength);
bool checkContainsSpacing(string x);
bool checkIsNumberString(string x);

bool isDigit(string strInt);
void DangNhap(string& username, string& password);
int mainMenu();
int subMenuSach();
int subMenuPhieuMuon();
int subMenuBanDoc();
bool XacNhan(string tab, string mess);
bool isContinue(string ntab);
string addDaysToDate(int day, int month, int year, int addDays);
