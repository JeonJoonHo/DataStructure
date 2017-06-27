#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE	30000
	
long partition(string* text, int left, int right)
{
    string pivot_element = text[left];
    int lb = left, ub = right;
    string temp;

    while (left < right)
    {
        while(text[left] <= pivot_element && left < ub)
            left++;
        while(text[right] > pivot_element )
            right--;
        if (left < right)
        {
            temp        = text[left];
            text[left]  = text[right];
            text[right] = temp;
        }
    }
    text[lb] = text[right];
    text[right] = pivot_element;
    return right;
}

void quickSort(string* text, int left, int right)
{
	static int call_counter = 0;
	if (left < right)
	{
		int pivot = partition(text, left, right);
		quickSort(text, left, pivot - 1);
		quickSort(text, pivot + 1, right);
	}
}

void makeChunks(string location, string* result, int start, int end) {
	ofstream outFile1;
	outFile1.open(location);

	quickSort(result, start, end - 1);

	for (int i = start; i < end; i++) {
		outFile1 << result[i] << endl;
	}

	outFile1.close();
}

void externalSort(string inputText, string outputText, int chunksLine , string chunks) {
	string inputdata;
	string text[MAX_SIZE];
	int index = 0;
	int textLine = 0;

	ifstream inFile(inputText);

	while (!inFile.eof()) {
		getline(inFile, inputdata);
		text[index] = inputdata;
		index++;
		textLine++;
	}
	inFile.close();

	double chunksNumber = (double)textLine / (double)chunksLine;
	int ceil_number = ceil(chunksNumber);
	for (int i = 0; i < ceil_number; i++) {
		string number = to_string(i + 1);
		if (i + 1 > textLine / chunksLine) {
			makeChunks(chunks + "chunks0000" + number, text, i*chunksLine, textLine);
		}
		else {
			makeChunks(chunks + "chunks0000" + number, text, i*chunksLine, (i + 1)*chunksLine);
		}
	}

	quickSort(text, 0, textLine - 1);

	ofstream outFile(outputText);
	for (int i = 0; i < textLine; i++) {
		outFile << text[i] << endl;
	}
	outFile.close();
}

int  main() {
	string inputText;
	string outputText;
	string chunks;
	string chunksNum;

	getline(cin, inputText, ' ');
	getline(cin, outputText, ' ');
	getline(cin, chunksNum, ' ');
	getline(cin, chunks, '\n');

	externalSort(inputText, outputText, atoi(chunksNum.c_str()) , chunks);
}