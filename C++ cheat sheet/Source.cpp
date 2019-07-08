#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<sstream>

using namespace std;



//The one about Null-Terminated-Charactor-Array
int main() {
	// Null terminated charactor array:
	char arr1[10] = "bob";
	char arr2[10] = "bob";
	char arr3[10] = "Bob";

	//For comparing two array of char
	cout << strcmp(arr1, arr2) << endl; // 0  : When they are equal it will return 0
	cout << strcmp(arr1, arr3) << endl; // 1  : When the ASCII code first one is greater than second one (b: 98, B: 55) it returns 1 
	cout << strcmp(arr3, arr1) << endl; //-1 : When the ASCII code of the first one is lass than the second one it returns -1

										//Getting the lenght of arrray
	cout << strlen(arr1) << endl;  // 3

								   //Copying to char arrray
	strcpy_s(arr1, "Milad"); // while using this you should be careful about the size of the array

							 //concatination 
	strcat_s(arr1, arr2);  //Again carefull about overfollowig 
	cout << strlen(arr1) << endl;

	system("pause");
	return 0;
}

//Typecasting of Char Int and String
int main6() {

	// ASCII code of  a char
	char myChar = 'a';
	int myInt = int(myChar);

	//Char of an ASCII code
	myInt = 99;
	myChar = char(myInt);

	//Turning a char to int
	myChar = '1';
	myInt = int(myChar) - int('0');

	//Char to String 
	myChar = 's';
	string myString(1, myChar);

	//Char array to String
	char chararr[] = "This is lots of chars";
	myString = string(chararr);

	//String to char
	myString = "S";
	myChar = myString.at(0);

	//String to int
	myString = "123";
	istringstream  ssr(myString);
	ssr >> myInt;

	myString = "45";
	myInt = std::stoi(myString);  //Second method

								  //int to String
	myInt = 50;
	myString = to_string(myInt);

	myInt = 77;
	stringstream ssr2;
	ssr2 << myInt;
	myString = ssr2.str();

	system("pause");
	return 0;
}

//Tokenizing a String line
int main5() {
	//Tokenizing a String 
	//String to Vector of string 

	string line = "Milad is here tokenizing a string";
	string s;
	vector<string> token;

	//Method one Using strinstream
	stringstream check(line);

	while (getline(check, s, ' ')) {
		token.push_back(s);

	}
	for (int i = 0; i < token.size(); i++)
		cout << token[i] << '\n';
	//-----------------------------------------------//

	// Second way is to use find and itterators:

	line = "tokenizing the second string";
	size_t pos = 0;

	while ((pos = line.find(" ")) != std::string::npos) {
		s = line.substr(0, pos);
		cout << s << endl;
		line.erase(0, pos + 1);
	}

	/// IMP :we should add the last word finally
	cout << line << endl;

	system("pause");
	return 0;
}

//String Function 
int main4() {
	// String functions

	string myString = "This is my string";

	string::iterator it = myString.begin() + 2;
	//auto it=myString.end();

	cout << myString.size() << endl;         // Returns the size of string
	cout << myString.length() << endl;     // Returns the size of string 
	cout << myString.max_size() << endl;  // Return the max size of the string 
	cout << myString.capacity() << endl; // Returns the capacity which has been reserved for string 

	myString.clear();
	cout << myString.empty() << endl;  // output is : 1
	myString = "This a a new string";
	cout << myString.empty() << endl;  // output is : 0

	myString.at(2); // == myString[2]

	cout << myString.back() << endl; //Access to the last char of a string (Only char)
									 //myString.back()='d';             
									 //myString.front()='M';         // Access to the front char of a string (Only char )	

									 //Appending a char or a string to a string using "+"
	myString += " that I made ";
	myString += '!';
	cout << myString << endl; //output:  This a a new string that I made!

							  //Adding a string or a char to a string
	myString.append(myString, 1, 3); //Appending a string
	myString.push_back('?');      //Adding to the end of string

	myString.assign("new content has been assigend"); //Remove pervius content and add new content
	myString.insert(myString.end(), '!');            // Inserting a char or a string at a specific location of a string 

	myString.erase(myString.begin(), myString.begin() + 4);
	myString.replace(myString.begin(), myString.begin() + 7, "Heeey!");

	//Swapping two string
	myString = "This is string 2.";
	string myString2 = "This is string 1.";
	myString.swap(myString2);

	//Removing last char of a string
	myString.pop_back();

	//getting substring of an string 
	myString = myString.substr(8, 6);

	system("pause");
	return 0;

}

//Writing to a file
int main3() {

	//Writing to a file 
	ofstream file;
	file.open("list2.txt", ios::binary);

	//If the file is open
	if (file.is_open()) {
		file << "The first line" << endl;
		file << "The second line" << endl;
		file << "The theird line";

		cout << "writing was succesfull" << endl;
	}
	else { cout << "Writing failed !" << endl; }

	file.close();
	system("pause");
	return 0;
}

//Reading from a file
int main2() {

	//Reading a file 
	fstream file;

	//file.open("list.txt") to append file 
	file.open("list.txt", ios::app);

	file << "I am milad";
	file.close();

	file.open("list.txt");
	string mystring;

	if (file.fail()) cerr << "Failed to open file!" << endl;

	else {

		// while(!infile.eof())
		// while(file >> mystring)
		while (getline(file, mystring))

			cout << mystring << endl;

	}
	file.close();

	system("pause");
	return 0;
}

//Writing to a file CSV
int main1() {
	//Making a CSV file
	fstream output;
	output.open("personel.csv", ios::app);
	string name;
	int birth, age, income;

	for (int i = 0; i < 4; i++) {
		cin >> name >> birth >> age >> income;
		output << name << " ; " << birth << " ; " << age << " ; " << income << "\n";
	}
	output.close();
	system("pause");
	return 0;

}
