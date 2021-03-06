#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string Cae(string text, int shift) {
	for (int i = 0; i < text.length(); i++) {
		if ((unsigned char)text[i] >= 'a' && (unsigned char)text[i] <= 'z') {
			text[i] = (unsigned char)text[i] + shift;
			if ((unsigned char)text[i] > 'z') {
				text[i] = (unsigned char)text[i] - 26;
			}
			else if ((unsigned char)text[i] < 'a') {
				text[i] = (unsigned char)text[i] + 26;
			}
		}
		else {
			continue;
		}
	}
	return text;
}
string Tran(string text) {
	char buffer;
	for (int i = 0; i < text.length(); i++) {
		if (i % 2 != 0) {
			text[i - 1] = text[i];
			text[i] = buffer;
		}
		else {
			buffer = text[i];
		}
	}
	return text;
}

int main()
{
	cout << "\nGive a text to cipher: ";
	string text = "";
	getline(cin, text);
	cout << "\nChoose cipher (cae, tran, both, dec): ";
	string cif = "oba";
	getline(cin, cif);
	int shift = 0;
	if (cif == "cae") {
		cout << "Please give the shift: ";
		cin >> shift;
		shift = shift % 26;
		cout << Cae(text, shift) << endl;
	}
	else if (cif == "tran") {
		cout << Tran(text) << endl;
	}
	else if (cif == "both") {
		cout << "Please give the shift: ";
		int shift = 0;
		cin >> shift;
		shift = shift % 26;
		cout << Tran(Cae(text, shift)) << endl;
	}
	else if (cif == "dec") {
		cout << "Which cipher do you want to be deciphered? (cae, tran, both): ";
		string decif = "both";
		getline(cin, decif);
		if (decif == "cae") {
			cout << "What is the shift?: ";
			cin >> shift;
			shift = -(shift % 26);
			cout << Cae(text, shift) << endl;
		}
		else if (decif == "tran") {
			cout << Tran(text) << endl;
		}
		else if (decif == "both") {
			cout << "What is the shift?: ";
			cin >> shift;
			shift = -(shift % 26);
			cout << Cae(Tran(text), shift) << endl;
		}
		else {
			cout << "Invalid ciphering method given. Please try again: ";
		}
	}
	else {
		cout << "Invalid ciphering method given. Please try again: ";
	}
}