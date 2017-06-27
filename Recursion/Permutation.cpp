#include <iostream>
#include <string>
using namespace std;

void permute(char str[], int first, int last) {
	int cur;

	if (first == last) {
		cout << str << endl;
	}
	else {
		for (cur = first; cur <= last; cur++)
		{
			swap(str[first], str[cur]);
			permute(str, first + 1, last);
			swap(str[first], str[cur]);
		}
	}

}

int main() {
	char str[] = "ABC";

	permute(str, 0, 2);

}