#include<iostream>

using namespace std;

char* my_strcpy(char* dest, const char* src) {

	char* start = dest;

	while (*src != NULL) {
		*dest = *src;
		dest++;
		src++;

	}
	*dest = '\0';
	return start;

}
int my_strcmp(const char* p1, const char* p2) {
	const char* s1 = (const char*)p1;
	const char* s2 = (const char*)p2;
	char c1, c2;
	do {
		c1 = (char)*s1++;
		c2 = (char)*s2++;
		if (c1 == '\0') {
			return c1 - c2;
		}
	} while (c1 == c2);
	return c1 - c2;
}
class Person {
public:
	int et;
	char name[11];
	int pri;
	Person() :et{ 0 }, name{ 0 }, pri{ 0 }
	{

	}
	Person(const char* name, int et, int pri) {
		my_strcpy(this->name, name);
		this->et = et;
		this->pri = pri;
	}

	bool operator>(Person const& person) {
		//TODO
		if (this->pri > person.pri) {
			return true;
		}
		else if (this->pri < person.pri) {
			return false;
		}
		
		if (my_strcmp(this->name, person.name)<0) {
			return true;
		}
		else if (my_strcmp(this->name, person.name) > 0) {
			return false;
		}

		if (this->et < person.et) {
			return true;
		}
		return false;
	}
	bool operator < (Person const& person) {
		
		if (this->pri < person.pri) {
			return true;
		}
		else if (this->pri > person.pri) {
			return false;
		}

		if (my_strcmp(this->name, person.name) > 0) {
			return true;
		}
		else if (my_strcmp(this->name, person.name) < 0) {
			return false;
		}

		if (this->et > person.et) {
			return true;
		}
		return false;
	}
};


class Heap {
public:
	Person arr[1000];
	int size;

	Heap() : size{ 0}
	{

	}
	Heap(Person arr[], int N) { // assume values passed in const in zero indexed array

		for (int i = 1; i <= N; i++) {
			this->arr[i] = arr[i-1];
		}
		this->size = N;
		build_heap();
	}
	void swap(Person* x, Person* y) {
		Person temp = *x;
		*x = *y;
		*y = temp;
	}
	void max_heapify( int i) {
		int left = 2 * i;
		int right = 2 * i + 1;
		int largest = i;

		if (left <= size && arr[left] > arr[largest]) {
			largest = left;
		}
		if (right <= size && arr[right] > arr[largest]) {
			largest = right;
		}

		if (largest != i) {
			swap(&arr[i], &arr[largest]);
			max_heapify(largest);
		}
	}
	void build_heap() {
		for (int i = size / 2; i >= 1; i--) {
			max_heapify(i);
		}
	}
	void increase_value(int i, Person value)
	{
		//assume value > arr[i]
		arr[i] = value;
		while (i > 1 && arr[i / 2] < arr[i]) {
			swap(&arr[i / 2], &arr[i]);
			i /= 2;
		}

	}
	void insert_value(Person value) {
		//len++;
		//arr[len] = -1;
		this->size++;
		increase_value(this->size,value);
	}
	Person extract_max() {
		if (size == 0) {
		
			return *(new Person);
		}
		Person max = arr[1];
		arr[1] = arr[size];
		size--;
		//max_heapify(1);
		return max;
	}

};
int main()
{

	Person *p1 = new Person("randeep", 1, 1);
	Person* p2 = new Person("Sandeep", 2, 2);
	Person* p3 = new Person("Tandeep", 3, 3);
	Person* p4 = new Person("Andeep", 4, 4);


	Person parry[4];
	parry[0] = *p1;
	parry[1] = *p2;
	parry[2] = *p3;
	parry[3] = *p4;


	//Heap h(parry,4);
	Heap h;
	h.insert_value(*p1);
	h.insert_value(*p2);
	h.insert_value(*p3);
	h.insert_value(*p4);


	
	while (h.size > 0) {
		cout << h.extract_max().name << endl;
	}


	return 0;
}