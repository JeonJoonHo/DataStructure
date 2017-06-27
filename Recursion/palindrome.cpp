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

	cout << "���ڿ� �Է� : ";
	getline(cin, str);
	if (str.size() == 0) {
		cout << "�ٽ� �Է� �ϼ���." << endl;
		getline(cin, str);
	}

	cout << boolalpha << palindrome(str) << endl;
}
