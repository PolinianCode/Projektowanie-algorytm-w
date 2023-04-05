#include <iostream>
#include <fstream>


using namespace std;

const int maxNumberOfElements = 1000;
string palList[maxNumberOfElements];
int palListIndexe = 0;

//ZADANIE 1
void insertToList(int** list, int rows, int cols, int x) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			list[i][j] = rand() % x;
		}
	}
}
void printList(int** list, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << list[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void maxNumber(int** list, int rows, int cols) {
	int maxVal = list[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (list[i][j] > maxVal) {
				maxVal = list[i][j];
			}
		}
	}
	cout << "Maximum value: " << maxVal << endl;
}
void zadanie1(int rows, int cols) {

	int** list = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		list[i] = new int[cols];
	}

	char option = 0;
	int maxValue = 0;

	do {
		std::cout << "MENU" << std::endl;
		std::cout << "1. Insert random values to list" << std::endl;
		std::cout << "2. Print list" << std::endl;
		std::cout << "3. Maximum value in list" << std::endl;
		std::cout << "4. Exit" << std::endl;
		std::cout << "Option: ";
		std::cin >> option;

		switch (option)
		{
		case '1':
			system("cls");
			cout << "Enter the max value for inserting: ";
			cin >> maxValue;
			insertToList(list, rows, cols, maxValue);
			break;
		case '2':
			system("cls");
			printList(list, rows, cols);
			break;
		case '3':
			system("cls");
			maxNumber(list, rows, cols);
			break;
		case '4':
			exit(0);
		default:
			system("cls");
			cout << "Incorrect option" << endl;
			break;
		}

	} while (option != 4);
}

//ZADANIE 2


void saveToFile(int* arr, int size, const char* fileName) {
	ofstream outFile(fileName);
	if (outFile.is_open()) {
		for (int i = 0; i < size; i++)
		{
			outFile << arr[i] << " ";
		}
		outFile.close();
		cout << "Saved to file" << endl;
	}
	else {
		cout << "Open file error" << endl;
	}
}
void saveToBinaryFile(int* arr, int size, const char* fileName) {
	ofstream outFile(fileName, std::ios::binary);
	if(outFile.is_open()) {
		for (int i = 0; i <= size; i++) {
			outFile.write((char*)arr[i], size);
		}
		outFile.close();
		cout << "Saved to binary file" << endl;
	}
	else {
		cout << "File error" << endl;
	}
}
void loadTextFile(int* arr, int size, const char* fileName) {
	ifstream file(fileName);
	if (file.is_open()) {
		for (int i = 0; i < size; i++)
		{
			file >> arr[i];
		}
		file.close();
	}
}
void loadBinaryFile(int* arr, int size, const char* fileName) {
	ifstream file(fileName, std::ios::binary);
	if (file.is_open()) {
		file.read((char*)arr, size);
		file.close();
	}
}
void printTextData(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void zadanie2() {
	int arr[] = { 1,2,3,4,5 };

	const int arrSize = sizeof(arr) / sizeof(int);
	int dataFromTextFile[arrSize];
	int dataFromBinaryFile[arrSize];
	const char* textFile = "TextArray.txt";
	const char* binaryFile = "BinaryArray.bin";

	char option = 0;

	do {
		std::cout << "MENU" << std::endl;
		std::cout << "1. Save to text file" << std::endl;
		std::cout << "2. Save to binary file" << std::endl;
		std::cout << "3. Load text file" << std::endl;
		std::cout << "4. Load binary file" << std::endl;
		std::cout << "5. Exit" << std::endl;
		std::cout << "Option: ";
		std::cin >> option;

		switch (option)
		{
		case '1':
			system("cls");
			saveToFile(arr, arrSize, textFile);
			break;
		case '2':
			system("cls");
			saveToFile(arr, arrSize, binaryFile);
			break;
		case '3':
			system("cls");
			loadTextFile(dataFromTextFile, arrSize, textFile);
			printTextData(dataFromTextFile, arrSize);
			break;
		case '4':
			system("cls");
			loadBinaryFile(dataFromBinaryFile, arrSize, binaryFile);
			printTextData(dataFromBinaryFile, arrSize);
			break;
		case '5':
			exit(0);
		default:
			break;
		}
	} while (option != 5);

	

}

//ZADANIE 3
int Silnia(int x) {
	if (x == 1) {
		return 1;
	}
	else {
		return x * Silnia(x - 1);
	}
	
}
int Potega(int x, int p) {
	if (p == 0) {
		return 1;
	}
	else {
		return x * Potega(x, p - 1);
	}
}


//ZADANIE 4
bool jestPal(string word, int start = 0, int end = -1) {
	if (end == -1) {
		end = word.length() - 1;
	}

	if (start >= end) {
		return true;
	}

	if (word[start] != word[end]) {
		return false;
	}

	
	return jestPal(word, start + 1, end - 1);
}

//ZADANIE 5
void permutacje(string lancuch, int start = 0) {
	if (start == lancuch.length()) {
		if (jestPal(lancuch)) {
			palList[palListIndexe++] = lancuch;
		}
	}
	else {
		for (int i = start; i < lancuch.length(); i++)
		{
			swap(lancuch[start], lancuch[i]);
			permutacje(lancuch, start + 1);
			swap(lancuch[start], lancuch[i]);
		}
	}
}
void showAllPermPal() {
	for (int i = 0; i < palListIndexe + 1; i++)
	{
		cout << palList[i] << endl;
	}

	palListIndexe = 0;
}


//ZADANIE 8

class Node {
public:
	int data;
	Node* next;

	Node(int val) {
		data = val;
		next = nullptr;
	}
};

class LinkedList
{
public:
	Node* head;

	LinkedList() {
		head = nullptr;
	}
	
	void addElem(int value) {
		Node* newNode = new Node(value);

		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	void printList() {
		if (head == nullptr) {
			cout << "Lista jest pusta" << endl;
			return;
		}
		Node* temp = head;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}


	void removeAll() {
		Node* temp = head;
		while (temp != nullptr) {
			Node* next = temp->next;
			delete temp;
			temp = next;
		}
		head = nullptr;
	}
};




int main()
{
	LinkedList arr;
	arr.addElem(5);
	arr.addElem(6);
	arr.printList();
	arr.removeAll();
	arr.printList();
}


