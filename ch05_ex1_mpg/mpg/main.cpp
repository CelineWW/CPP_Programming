#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
	// print name of program
	cout << "Miles Per Gallon\n\n";

	char another_entry = 'y';
	while (tolower(another_entry) == 'y') {

		// get miles driven
		double miles = 0;
		while (true) {
			cout << "Enter miles driven:        ";
			cin >> miles;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            //check for a valid number
            if (cin.fail()){
                cout << "That's not a valid number. Try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

			// check the range of the number
			if (miles <= 0) {
				cout << "Miles driven must be greater than zero. Please try again.\n";
			}
			else {
				break;
			}
		}

		// get gallons of gas used
		double gallons = 0;
		while (true) {
			cout << "Enter gallons of gas used: ";
			cin >> gallons;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            //check for a valid number
            if (cin.fail()){
                cout << "That's not a valid number. Try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

			// check the range of the number
			if (gallons <= 0) {
				cout << "Gallons used must be greater than zero. Please try again.\n";
			}
			else {
				break;
			}
		}

		// calculate miles per gallon
		double mpg = miles / gallons;
		mpg = round(mpg * 100) / 100;
		cout << "Miles per gallon:          " << mpg << endl << endl;

//        // set a full path to the correct file
//        const char* home = getenv("HOME");
//        string user_home = "";
//        if (home) {
//            user_home = home;
//        }
//        else {
//            // if home isn't found, edit 'username' so it's correct for your system
//            user_home = "/Users/username";
//        }
//        string file_path = "/Documents/murach/cpp/files/";
//        string filename = user_home + file_path + "trips.txt";
        
        //write entry to file
        string filename = "trips.txt";
        ofstream output_file;
        output_file.open(filename, ios::app);
        output_file << fixed << setprecision(1);
        output_file << miles << '\t' << gallons <<'\t' << '\n';
        output_file.close();
        
		// see if the user wants to enter more data
		cout << "Get entries for another trip? (y/n): ";
		cin >> another_entry;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
	}

	cout << "Bye!\n\n";
}
