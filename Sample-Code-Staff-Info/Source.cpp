#include <iostream>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
//Globals
class PERSON {

public:
	PERSON() { cout << "\n\tBuilding a PERSON"; }
	~PERSON() { cout << "\n\tRebuilding a PERSON"; }

	//Accessor Methods
	void SetPersonName(string X) { PersonName = X; }
	void SetOccupatoin(string X) { Occupation = X; }
	void SetLocation(string X) { Location = X; }
	void SetRefrences(string X) { Refrences = X; }
	string GetPersonName() { return PersonName; }
	string GetOccupatoin() { return Occupation; }
	string GetLocation() { return Location; }
	string GetRefrences() { return Refrences; }

private:
	string PersonName;
	string Occupation;
	string Location;
	string Refrences;

};
//------------------------------------------------------------------------------------------------//

//Function prototype
void CreatePerson();
void EditPerson();
void DisplayPerson();
void LoadPerson();
void SavePerson();

//------------------------------------------------------------------------------------------------//

PERSON *CG;
int main() {

	CG = new PERSON();
	char CHOICE[10];
	cout << "\n\tPesonell Database 1.0\n";

	while (CHOICE[0] != 'q')
	{
		cout << "\n\t-----------------------Main Menu------------------";
		cout << "\n\t|                                                |";
		cout << "\n\t|         (C)reate a PERSON                      |";
		cout << "\n\t|         (E)dit Infromation for PERSON          |";
		cout << "\n\t|         (D)isplay a PERSON                     |";
		cout << "\n\t|         (S)ave a PERSON                        |";
		cout << "\n\t|         (L)oad a PERSON                        |";
		cout << "\n\t|         (Q)uit                                 |";
		cout << "\n\t|                                                |";
		cout << "\n\t------------------------------------------------\n\n\t";

		cin >> CHOICE;

		switch (CHOICE[0])
		{
		case 'c': CreatePerson(); break;
		case 'e': EditPerson(); break;
		case 'd': DisplayPerson(); break;
		case 's': SavePerson(); break;
		case 'l': LoadPerson(); break;
		case 'q': cout << "\n\tEXit Main Menu\n\n"; break;
		default:" \n\t Invalid Input !";
		}


	}

	system("pause");
	return 0;
}
//---------------------------------------------------------------------------------------//

void CreatePerson() {
	CG = new PERSON();
};
//--------------------------------------------------------------------------------------//
void EditPerson() {
	system("CLS");
	string TEMP;
	cout << "\n\t-------------------Edit Person-------------------------";

	cout << "\n\tName: ";
	cin.ignore(); // Buffer bugger// we just put it at the first time to remove the bugieness of the cin command
	getline(cin, TEMP);
	CG->SetPersonName(TEMP);

	cout << "\n\tOccupatoin: ";
	getline(cin, TEMP);
	CG->SetOccupatoin(TEMP);

	cout << "\n\tLocation: ";
	getline(cin, TEMP);
	CG->SetLocation(TEMP);

	cout << "\n\tRefrences: ";
	getline(cin, TEMP);
	CG->SetRefrences(TEMP);
};
//--------------------------------------------------------------------------------------//
void DisplayPerson() {
	system("CLS");
	cout << "\n\t-----------------PERSON INFORMATION------------------";
	cout << "\n\tName: " << CG->GetPersonName();
	cout << "\n\tOccupation: " << CG->GetOccupatoin();
	cout << "\n\tLocation: " << CG->GetLocation();
	cout << "\n\tRefreces: " << CG->GetRefrences();
	cout << "\n\t-----------------------------------------------------\n\n";

};
//--------------------------------------------------------------------------------------//
void LoadPerson() {

	try
	{
		string TEMP;
		ifstream DATAFILE;
		DATAFILE.open("DATA1.txt", ios::in);

		getline(DATAFILE, TEMP);
		CG->SetPersonName(TEMP);

		getline(DATAFILE, TEMP);
		CG->SetOccupatoin(TEMP);

		getline(DATAFILE, TEMP);
		CG->SetLocation(TEMP);

		getline(DATAFILE, TEMP);
		CG->SetRefrences(TEMP);



		DATAFILE.close();

		cout << "\n\tSuccess! Data was loaded";



	}
	catch (exception X) { cout << "\n\tFile Error! Unable to load data."; }
};
//--------------------------------------------------------------------------------------//
void SavePerson()
{
	try
	{
		ofstream DATAFILE;
		DATAFILE.open("DATA1.txt", ios::app);

		DATAFILE << CG->GetPersonName() << "\n";
		DATAFILE << CG->GetOccupatoin() << "\n";
		DATAFILE << CG->GetLocation() << "\n";
		DATAFILE << CG->GetRefrences() << "\n";

		DATAFILE.close();

		cout << "\n\tSuccess! DATA was saved to file.";
	}
	catch (exception X)
	{
		cout << "\n\tFile Error! Could not SAVE PERSON.";
	}


};