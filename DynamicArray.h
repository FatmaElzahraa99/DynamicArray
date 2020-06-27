#include <stdexcept>
#include <string>
#include <algorithm> //sort 
#include <iostream>
using namespace std;
class Dynamic_Array
{
private:
	int size = 0, cap = 6;
	int* arr = new int[cap];
public:
	//add a new element in array
	void push_back(int num) {
		if (size == cap)
			cap *= 2;
		arr[size] = num;
		size++;
	}
	//control of the size of array smaller than before
	void shrink() {
		int* temp = new int[size];
		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		cap = size;
		delete[] arr;
		arr = temp;
	}
	//remove the last element
	void pop_back() {
		int* temp = new int[size - 1];
		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		delete[size - 1] arr;
		--size;
		arr = temp;
	}
	//add a new element with spcial index
	void insert(int index, int element) {
		int* temp = new int[size + 1];
		for (int i = 0; i < index; i++) {
			temp[i] = arr[i];
		}
		temp[index] = element;
		for (int i = index + 1; i <= size; i++) {
			temp[i] = arr[i - 1];
		}
		++size;
		delete[]arr;
		arr = temp;
	}
	//copy subarray 
	int* copy(int FromIndex, int Toindex) {
		int* temp = new int[Toindex - FromIndex];
		for (int i = Toindex; i <= FromIndex; i++)
		{
			temp[i] = arr[i];
		}
		return temp;
	}
	//copy all elements in array
	int* copy() {
		int* temp = new int[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		return temp;
	}
	//update any index
	void update(int index, int element) {
		arr[index] = element;
	}
	//get the value of this index
	int getValue(int index)
	{
		return arr[index];
	}
	//get the capacity of array
	int capacity() {
		return cap;
	}
	//get the size of array
	int length() {
		return size;
	}
	//compare this array with another
	bool equals(int* array) {
		return (array == arr) ? true : false;
	}
	//control of the size of array (bigger or smaller) than before
	void resize(int num) {
		int* temp = new int[num];
		for (int i = 0; i < num; i++) {
			temp[i] = arr[i];
		}
		size = size;
		cap = num;
		delete[] arr;
		arr = temp;
	}
	//reverse array
	void reverse() {
		int* temp = new int[size];
		int x = size;
		for (int i = 0; i <= size; i++)
		{
			x--;
			temp[i] = arr[x];
		}
		delete[] arr;
		arr = temp;
	}
	//delete the array
	void clear() {
		delete[] arr;
		size = 0;
	}
	//delete an index
	void erase(int index) {
		int* temp = new int[size - 1];
		for (int i = 0; i < size; i++)
		{
			if (index == i) continue;
			if (i > index)
				temp[i - 1] = arr[i];
			temp[i] = arr[i];
		}
		size--;
		delete[] arr;
		arr = temp;
	}
	//check this element in array
	bool contains(int element) {
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == element) return true;
		}
		return false;
	}
	//sort the array by linear search (defult sort)
	int linearsearch(int element) {
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == element) return i;
		}
		throw new exception("Is Not Contains");
	}
	//sort the array by Binary (sort array and return the new index of  element)
	int Binarysearch(int element) {
		int left = 0, rigth = 0;
		insertionSort(); //sort array
		while (left <= rigth)
		{
			int med = size / 2 + 1; //to get mediam
			if (element == arr[med]) return med;
			if (arr[med] < element) left = med + 1;
			if (arr[med] > element) rigth = med - 1;
		}
		return -1;
	}
	//sort the array by insertion (get the elements and compare at less)
	void insertionSort() {
		int x;
		for (int i = 1; i < size; i++) {
			for (int j = 0; j < i; j++)
			{
				if (arr[i] < arr[j])
				{
					x = arr[i];
					arr[i] = arr[j];
					arr[j] = x;
				}
			}
		}
	}
	//to get the number bigger than numbers between it
	int findPeak() {
		int max;
		for (int i = 1; i < size - 2; i++)
			if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
				max = arr[i];
		return max;
	}
	//get first element in array
	int front() {
		return (size != 0) ? arr[0] : throw new exception("Is Empty");
	}
	//get last element in array
	int back() {
		return (size != 0) ? arr[size - 1] : throw new exception("Is Empty");
	}
	//Display array
	void print() {
		if (size == 0) cout << "is empty";
		else
		{
			for (int i = 0; i < size; i++) cout << arr[i] << ",";
			cout << endl;
		}
	}
	//to check the list is empty or not
	bool IsEmpty() {
		return (size == 0);
	}
	//convert tostring
	string toString() {
		string str;
		for (int i = 0; i < size; i++)
		{
			str += to_string(arr[i]);
		}
		return str;
	}
};
