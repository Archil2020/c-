#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

class String {
private:
	size_t length;
	char* str = nullptr;
	char* temparr = nullptr;
public:
	char s;
	String() = default;
	String(char* arr) {
		Copy(arr);
	}

	void operator=(String& other) {
		Copy(other.str);
	}

	void operator=(char* newstr) {
		Copy(newstr);
	}

	char &operator[](int index) {
		return str[index];
	}

	void operator<=(String& other) {
		if (str == nullptr) {
			Copy(other.string());
		}
		else
		{
			char* newstr = other.string();
			int sumcount = length + other.length;
			temparr = new char[length];
			for (int i = 0; str[i] != '\0'; i++)
			{
				temparr[i] = str[i];
			}
			temparr[length] = '\0';
			delete[] str;
			str = nullptr;
			str = new char[sumcount+1];
			int i = 0;
			while (temparr[i]!='\0')
			{
				str[i] = temparr[i];
				i++;
			}
			str[length] = '\0';

			int k = length;
			for (int j = 0; newstr[j]!='\0';j++)
			{
				str[k] = other[j];
				k++;
			}
			str[sumcount] = '\0';
			length = sumcount;
		}
	}


	void Copy(const char* arr) {
		if (str != nullptr)
		{
			delete[] str;
		}
		int count = 0;
		for (int i = 0; arr[i] != '\0'; i++) {
			count++;
		}
		str = new char[count + 1];
		for (int k = 0; k <= count; k++) {
			str[k] = arr[k];
		}
		str[count] = '\0';
		length = count;
	}

	int strlength() {
		return length;
	}

	char* string() {
		return str;
	}

	~String()
	{
		delete[] str;
		str = nullptr;
	}
};

ostream& operator<<(ostream& os, String& str) {
	for (size_t i = 0; i < str.strlength(); i++)
	{
		os << str[i];
	}
	return os;
}

istream& operator >> (istream& is, String& str) {
	char* arr = new char[1000000];
	is.getline(arr, 1000000);
	str = arr;
	delete[] arr;
	return is;
}

int main(){
	String test[4];

	for each (String item in test)
	{
		item = "Hello";
		test[0] <= item;
	}
	cout << test[0] << endl;
	

	return 0;
}