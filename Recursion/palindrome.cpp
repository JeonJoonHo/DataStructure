#include <iostream>
#include <string>
using namespace std;

bool palindrome(const string &str) {
	int strSize = str.size();

	if (strSize <= 1) {
		return true;
	}

	if (str.at(0) == str.at(strSize - 1)) {
		string nextStr = str.substr(1, strSize - 1);
		palindrome(nextStr);
	}
	else {
		return false;
	}
}

int main() {
	string str;

	cout << "문자열 입력 : ";
	getline(cin, str);
	if (str.size() == 0) {
		cout << "다시 입력 하세요." << endl;
		getline(cin, str);
	}

	cout << boolalpha << palindrome(str) << endl;
}
