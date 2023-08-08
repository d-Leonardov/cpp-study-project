/**
* This program allows the user to manage records represented by a collection of columns
* It provides functionality to load data from a file, display records, add new records,
* edit existing records, delete records, and save the records to a file
* The program ensures data integrity and handles exceptions when loading or saving files
* It also includes a view for displaying records and interacting with the user
* The program aims to provide a user-friendly interface for managing and manipulating records data.
* 
* Note: CSV file is stored in the same project folder as this program.
* 
* @author Leonardo_Villalobos
* @version 1
*/


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include <cstdio>

using namespace std;

/**
 * @class Record.
 * Represents a record with multiple columns.
 */
class Record {
private:

    string column1; // First column.
    string column2; // Second column.
    string column3; // Third column.
    string column4; // Fourth column.
    string column5; // Fifth column.
    string column6; // Sixth column.
    string column7; // Seventh column.
    string column8; // Eighth column.
    string column9; // Ninth column.
    string column10; // Tenth column
    string column11; // Eleventh column.
    string column12; // Twelfth column.
    string column13; // Thirteenth column.
    string column14; // Fourteenth column.
    string column15; // Fifteenth column.
    string column16; // Sixteenth column.

public:

    /**
     * Constructs a new Record object with the specified column values.
     *
     * @param col1 The value of the first column.
     * @param col2 The value of the second column.
     * @param col3 The value of the third column.
     * @param col4 The value of the fourth column.
     * @param col5 The value of the fifth column.
     * @param col6 The value of the sixth column.
     * @param col7 The value of the seventh column.
     * @param col8 The value of the eighth column.
     * @param col9 The value of the ninth column.
     * @param col10 The value of the tenth column.
     * @param col11 The value of the eleventh column.
     * @param col12 The value of the twelfth column.
     * @param col13 The value of the thirteenth column.
     * @param col14 The value of the fourteenth column.
     * @param col15 The value of the fifteenth column.
     * @param col16 The value of the sixteenth column.
     */
    Record(string col1, string col2, string col3, string col4, string col5, string col6,
        string col7, string col8, string col9, string col10, string col11, string col12,
        string col13, string col14, string col15, string col16)
        : column1(col1), column2(col2), column3(col3), column4(col4), column5(col5),
        column6(col6), column7(col7), column8(col8), column9(col9), column10(col10),
        column11(col11), column12(col12), column13(col13), column14(col14), column15(col15),
        column16(col16) {}

    /**
     * Gets the value of the first column.
     * @return The value of the first column.
     */
    string getColumn1() const { return column1; }

    /**
     * Gets the value of the second column.
     * @return The value of the second column.
     */
    string getColumn2() const { return column2; }

    /**
     * Gets the value of the third column.
     * @return The value of the third column.
     */
    string getColumn3() const { return column3; }

    /**
     * Gets the value of the fourth column.
     * @return The value of the fourth column.
     */
    string getColumn4() const { return column4; }

    /**
     * Gets the value of the fifth column.
     * @return The value of the fifth column.
     */
    string getColumn5() const { return column5; }

    /**
     * Gets the value of the sixth column.
     * @return The value of the sixth column.
     */
    string getColumn6() const { return column6; }

    /**
     * Gets the value of the seventh column.
     * @return The value of the seventh column.
     */
    string getColumn7() const { return column7; }

    /**
     * Gets the value of the eighth column.
     * @return The value of the eighth column.
     */
    string getColumn8() const { return column8; }

    /**
     * Gets the value of the ninth column.
     * @return The value of the ninth column.
     */
    string getColumn9() const { return column9; }

    /**
     * Gets the value of the tenth column.
     * @return The value of the tenth column.
     */
    string getColumn10() const { return column10; }

    /**
     * Gets the value of the eleventh column.
     * @return The value of the eleventh column.
     */
    string getColumn11() const { return column11; }

    /**
     * Gets the value of the twelfth column.
     * @return The value of the twelfth column.
     */
    string getColumn12() const { return column12; }

    /**
     * Gets the value of the thirteenth column.
     * @return The value of the thirteenth column.
     */
    string getColumn13() const { return column13; }

    /**
     * Gets the value of the fourteenth column.
     * @return The value of the fourteenth column.
     */
    string getColumn14() const { return column14; }

    /**
     * Gets the value of the fifteenth column.
     * @return The value of the fifteenth column.
     */
    string getColumn15() const { return column15; }

    /**
     * Gets the value of the sixteenth column.
     * @return The value of the sixteenth column.
     */
    string getColumn16() const { return column16; }
};

/**
 * @class RecordModel.
 * Represents a model for managing records and performing operations on them.
 */
class RecordModel {
private:

    vector<Record> records;  // A collection of records.
    string filename;        // The filename associated with the records.
    
public:

    /**
     * Retrieves the filename associated with the records.
     * @return The filename.
     */
    string getFilename() {
        return filename;
    }

    /**
     * Counts the number of records in a given file.
     * @param filename The name of the file.
     * @return The count of records in the file.
     */
    int countRecords(const string& filename) {
        ifstream file(filename); // Creates an object named file of type ifstream, 
                                 // which is used for input operations on files.

        string line;
        int count = -1; // Initialize count to -1 to exclude the header line
        while (getline(file, line)) {
            count++;
        }

        file.close();
        return count;
    }

    /**
     * Counts the total number of records in a given file, handling exceptions.
     * @param filename The name of the file.
     * @return The count of records in the file.
     *         Returns -1 if an exception occurs.
     */
    int countTotalRecords(const string& filename) {
        try {
            ifstream file(filename);
            if (!file.is_open()) {
                throw runtime_error("File could not be opened.");
            }

            string line;
            int count = -1; // Initialize count to -1 to exclude the header line
            while (getline(file, line)) {
                count++;
            }

            file.close();
            return count;
        }

        catch (const exception& e) {
            cout << "Error while opening the file: " << e.what() << endl;
            return -1; // Return -1 to indicate an error
        }
    }

    /**
     * Loads data from a file, and populates the collection of records.
     */
    void loadData() {
        int maxRecords; // Holds the maximum number of records to read from the file.
        bool fileAvailable = false; // Indicates whether a valid file is available for reading.
        ifstream file; // Creates an object named 'file' that can be used to open and read data 
                       // from a file in subsequent code.
        
        while (!fileAvailable) {
            try {
                cout << "Enter the filename to load data (filename followed by '.csv'): ";
                cin >> filename;

                file.open(filename);
                if (!file.is_open()) {
                    throw runtime_error("Error opening the file. Try again.");
                }

                cout << "Number of records in the file: " << countTotalRecords(filename) << endl;
                if (countTotalRecords(filename) > 100) {
                    maxRecords = 100;
                }
                else {
                    maxRecords = countTotalRecords(filename);
                }

                records.clear(); // Clears existing records

                string line;
                getline(file, line); // Skips the header line

                int count = 0;
                while (getline(file, line) && count < maxRecords) {
                    stringstream ss(line);
                    string col1, col2, col3, col4, col5, col6, col7, col8, col9, col10,
                        col11, col12, col13, col14, col15, col16;

                    getline(ss, col1, ',');
                    getline(ss, col2, ',');
                    getline(ss, col3, ',');
                    getline(ss, col4, ',');
                    getline(ss, col5, ',');
                    getline(ss, col6, ',');
                    getline(ss, col7, ',');
                    getline(ss, col8, ',');
                    getline(ss, col9, ',');
                    getline(ss, col10, ',');
                    getline(ss, col11, ',');
                    getline(ss, col12, ',');
                    getline(ss, col13, ',');
                    getline(ss, col14, ',');
                    getline(ss, col15, ',');
                    getline(ss, col16, ',');

                    Record record(col1, col2, col3, col4, col5, col6, col7, col8, col9, col10,
                        col11, col12, col13, col14, col15, col16);
                    records.push_back(record);

                    count++;
                }
                cout << "File " << filename << " was loaded successfully with " << count 
                    << " records." << endl;

                /*
                * By modifying the value of the 'filename' variable, any actions performed during the 
                * program's execution will be recorded in this new file, ensuring that the original 
                * files remain unaffected by unexpected updates.
                */
                filename = "-" + filename + "-";
                fileAvailable = true; // Break the loop if the file was successfully loaded.
                file.close(); // Closes the file associated with the object 'file'.
                cin.clear(); // Clears the error state flags of the standard input stream.
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            catch (const exception& ex) {
                cout << ex.what() << endl;
            }
        }
    }

    /**
     * Saves the records to a file.
     * @param filename The name of the file to save.
     */
    void saveData(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error saving the file.Try again." << endl;
            cout << endl;
            return;
        }

        // Write header line
        file << "REF_DATE,GEO,DGUID,TYPE_PRODUCT,TYPE_STORAGE,UOM,UOM_ID,SCALAR_FACTOR,"
            "SCALAR_ID,VECTOR,COORDINATE,VALUE,STATUS,SYMBOL,TERMINATED,DECIMALS\n";

        // Write record data
        for (const auto& record : records) {
            file << record.getColumn1() << ",";
            file << record.getColumn2() << ",";
            file << record.getColumn3() << ",";
            file << record.getColumn4() << ",";
            file << record.getColumn5() << ",";
            file << record.getColumn6() << ",";
            file << record.getColumn7() << ",";
            file << record.getColumn8() << ",";
            file << record.getColumn9() << ",";
            file << record.getColumn10() << ",";
            file << record.getColumn11() << ",";
            file << record.getColumn12() << ",";
            file << record.getColumn13() << ",";
            file << record.getColumn14() << ",";
            file << record.getColumn15() << ",";
            file << record.getColumn16() << "\n";
        }
        file.close();
    }

    /**
     * Retrieves the records collection.
     * @return The vector of records.
     */
    const vector<Record>& getRecords() const {
        return records;
    }

    /**
     * Adds a new record to the collection.
     * @param record The record to add.
     */
    void addRecord(const Record& record) {
        records.push_back(record);
    }

    /**
     * Edits an existing record in the collection.
     * @param index The index of the record to edit.
     * @param record The updated record.
     * @return True if the record was successfully edited, false otherwise.
     */
    bool editRecord(int index, const Record& record) {
        if (index >= 0 && index < records.size()) {
            records[index] = record;
            return true;
        }
        return false;
    }

    /**
     * Deletes a record from the collection.
     * @param index The index of the record to delete.
     * @return True if the record was successfully deleted, false otherwise.
     */
    bool deleteRecord(int index) {
        if (index >= 0 && index < records.size()) {
            records.erase(records.begin() + index);
            return true;
        }
        return false;
    }
};

/**
 * @class RecordView.
 * Represents a view for displaying records and interacting with the user.
 */
class RecordView {

public:

    /**
     * Displays a single record along with the username.
     * @param record The record to display.
     * @param username The username to display along with the record.
     */
    void displayOneRecord(const Record& record, const string& username) {
        cout << "REF_DATE: " << record.getColumn1() << endl;
        cout << "GEO: " << record.getColumn2() << endl;
        cout << "DGUID: " << record.getColumn3() << endl;
        cout << "TYPE_PRODUCT: " << record.getColumn4() << endl;
        cout << "TYPE_STORAGE: " << record.getColumn5() << endl;
        cout << "UOM: " << record.getColumn6() << endl;
        cout << "UOM_ID: " << record.getColumn7() << endl;
        cout << "SCALAR_FACTOR: " << record.getColumn8() << endl;
        cout << "SCALAR_ID: " << record.getColumn9() << endl;
        cout << "VECTOR: " << record.getColumn10() << endl;
        cout << "COORDINATE: " << record.getColumn11() << endl;
        cout << "VALUE: " << record.getColumn12() << endl;
        cout << "STATUS: " << record.getColumn13() << endl;
        cout << "SYMBOL: " << record.getColumn14() << endl;
        cout << "TERMINATED: " << record.getColumn15() << endl;
        cout << "DECIMALS: " << record.getColumn16() << endl;
        cout << "Program by: " << username << endl;
        cout << endl;
    }

    /**
     * Displays a record without the 'Program by:' row.
     * @param record The record to display.
     */
    void displayRecord(const Record& record) {
        cout << "REF_DATE: " << record.getColumn1() << endl;
        cout << "GEO: " << record.getColumn2() << endl;
        cout << "DGUID: " << record.getColumn3() << endl;
        cout << "TYPE_PRODUCT: " << record.getColumn4() << endl;
        cout << "TYPE_STORAGE: " << record.getColumn5() << endl;
        cout << "UOM: " << record.getColumn6() << endl;
        cout << "UOM_ID: " << record.getColumn7() << endl;
        cout << "SCALAR_FACTOR: " << record.getColumn8() << endl;
        cout << "SCALAR_ID: " << record.getColumn9() << endl;
        cout << "VECTOR: " << record.getColumn10() << endl;
        cout << "COORDINATE: " << record.getColumn11() << endl;
        cout << "VALUE: " << record.getColumn12() << endl;
        cout << "STATUS: " << record.getColumn13() << endl;
        cout << "SYMBOL: " << record.getColumn14() << endl;
        cout << "TERMINATED: " << record.getColumn15() << endl;
        cout << "DECIMALS: " << record.getColumn16() << endl;
        cout << endl;
    }

    /**
     * Displays a collection of records along with the username, with formatting
     * that shows the username every 10 records.
     * @param records The collection of records to display.
     * @param username The username to display along with the records.
     */
    void displayRecords(const vector<Record>& records, const string& username) {
        int recordCount = 0; // Counter variable to keep track of the number of records

        for (const auto& record : records) {
            displayRecord(record);
            recordCount++;

            if (recordCount % 10 == 0)
            {
                cout << "Program by: " << username << endl;
                cout << endl;
            }
         }
        
        if (recordCount < 10)
        {
            cout << "Program by: " << username << endl;
            cout << endl;
            }
    }

    /**
     * Creates a new record based on user input.
     * @return The created record.
     */
    Record createRecord() {
        string col1, col2, col3, col4, col5, col6, col7, col8, col9, col10, col11, col12, 
            col13, col14, col15, col16;

        cout << "Enter value for column REF_DATE: ";
        getline(cin, col1);
        cout << "Enter value for column GEO: ";
        getline(cin, col2);
        cout << "Enter value for column DGUID: ";
        getline(cin, col3);
        cout << "Enter value for column Type of product: ";
        getline(cin, col4);
        cout << "Enter value for column Type of storage: ";
        getline(cin, col5);
        cout << "Enter value for column UOM: ";
        getline(cin, col6);
        cout << "Enter value for column UOM_ID: ";
        getline(cin, col7);
        cout << "Enter value for column SCALAR_FACTOR: ";
        getline(cin, col8);
        cout << "Enter value for column SCALAR_ID: ";
        getline(cin, col9);
        cout << "Enter value for column VECTOR: ";
        getline(cin, col10);
        cout << "Enter value for column COORDINATE: ";
        getline(cin, col11);
        cout << "Enter value for column VALUE: ";
        getline(cin, col12);
        cout << "Enter value for column STATUS: ";
        getline(cin, col13);
        cout << "Enter value for column SYMBOL: ";
        getline(cin, col14);
        cout << "Enter value for column TERMINATED: ";
        getline(cin, col15);
        cout << "Enter value for column DECIMALS: ";
        getline(cin, col16);

        return Record(col1, col2, col3, col4, col5, col6, col7, col8, col9, col10, col11, col12,
            col13, col14, col15, col16);
    }

    /**
     * Prompts the user to select a record by its index.
     * @return The selected index.
     */
    int selectRecordIndex() {
        int index;
        cout << "Enter the index of the record (Records read in the current file - [1]): ";
        cin >> index;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        return index;
    }
};

/**
 * @class RecordController.
 * Handles the control flow and interaction between the RecordModel and RecordView.
 */
class RecordController {
private:

    RecordModel model;
    RecordView view;

public:

    /**
     * Loads data from a file using the RecordModel.
     */
    void loadData() {
        model.loadData();
    }

    /**
     * Saves data to a file using the RecordModel.
     * @param filename The name of the file to save the data.
     */
    void saveData(const string& filename) {
        model.saveData(filename);
    }

    /**
     * Retrieves the filename associated with the data.
     * @return The filename.
     */
    string getFilename() {
        return model.getFilename();
    }

    /**
     * Displays a single record based on the user's input.
     * @param username The username of the current user.
     */
    void displayRecord(const string& username) {
        const vector<Record>& records = model.getRecords();
        int index = view.selectRecordIndex();
        if (index >= 0 && index < records.size()) {
            view.displayOneRecord(records[index], username);
        }
        else {
            cout << "Invalid record index. Try again." << endl;
            cout << endl;
        }
    }

    /**
     * Displays all records using the RecordView.
     * @param username The username of the current user.
     */
    void displayRecords(const string& username) {
        const vector<Record>& records = model.getRecords();
        view.displayRecords(records, username);
    }

    /**
     * Adds a new record to the RecordModel.
     */
    void addRecord() {
        Record record = view.createRecord();
        model.addRecord(record);
        cout << "Record added successfully." << endl;
    }

    /**
     * Edits a record by getting the reference to the vector of records and the index of the 
     * record from the view.
     */
    void editRecord() {
        const vector<Record>& records = model.getRecords();
        int index = view.selectRecordIndex();
        if (index >= 0 && index < records.size()) {
            Record record = view.createRecord();
            if (model.editRecord(index, record)) {
                cout << "Record edited successfully." << endl;
            }
            else {
                cout << "Invalid record index.Try again." << endl;
            }
        }
        else {
            cout << "Invalid record index.Try again." << endl;
        }
    }

    /**
     * Deletes a record by getting the reference to the vector of records and the 
     * index of the record from the view.
     */
        void deleteRecord() {
            const vector<Record>& records = model.getRecords(); // Get the reference to the vector of 
                                                                // records from the model.
            int index = view.selectRecordIndex(); // Get the index of the record to be deleted from the view.
            if (index >= 0 && index < records.size()) {
                if (model.deleteRecord(index)) {
                    cout << "Record deleted successfully." << endl;
                }
                else {
                    cout << "Invalid record index.Try again." << endl;
                }
            }
            else {
                cout << "Invalid record index.Try again." << endl;
            }
        }

    /**
     * Runs the menu-driven program flow.
     * Displays a menu, receives user input, and performs corresponding actions.
     */
    void runMenu() {
        int choice; // Variable to store the user's menu choice.
        bool validInput = false; // Flag to indicate if the user input is valid.
        string filename; // Variable to store the filename entered by the user.
        string username; // Variable to store the username entered by the user.

        cout << "Enter your ACSIS name (no blank entries or numbers allowed): ";
        getline(cin, username);
        
        // Validates the username input by checking for empty string or presence of digits.
        while (username.empty() || containsDigits(username)) {
            cout << "Invalid input. Please enter your ACSIS name (no blank entries or numbers allowed): ";
            getline(cin, username);
        }
        
        cout << endl;
        saveData(getFilename());

        // Display the menu and handle user input until the user chooses to exit.
        while (true) {
            cout << "Menu:" << endl;
            cout << "1. Display all records" << endl;
            cout << "2. Display one record" << endl;
            cout << "3. Add one record" << endl;
            cout << "4. Edit one record" << endl;
            cout << "5. Delete one record" << endl;
            cout << "6. Save data" << endl;
            cout << "7. Reload data" << endl;
            cout << "0. Exit" << endl;
            cout << "Program by: " << username << endl;
            cout << "Enter your choice: ";

            // Read the user's choice from input and handle different cases.
            if (cin >> choice) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                validInput = true;

                switch (choice) {
                case 1:
                    cout << endl << "Displaying all records..." << endl;
                    cout << endl;
                    displayRecords(username);
                    break;
                case 2:
                    cout << endl << "Displaying one record..." << endl;
                    cout << model.countRecords(getFilename()) << 
                        " Records read in the current file." << endl;
                    displayRecord(username);
                    break;
                case 3:
                    cout << endl << "Adding one record..." << endl;
                    addRecord();
                    saveData(getFilename());
                    cout << "Program by: " << username << endl << endl;
                    break;
                case 4:
                    cout << endl << "Editing one record..." << endl;
                    cout << model.countRecords(getFilename()) << 
                        " Records read in the current file." << endl;
                    editRecord();
                    saveData(getFilename());
                    cout << "Program by: " << username << endl << endl;
                    break;
                case 5:
                    cout << endl << "Deleting one file.." << endl;
                    cout << model.countRecords(getFilename()) << 
                        " Records read in the current file." << endl;
                    deleteRecord();
                    saveData(getFilename());
                    cout << "Program by: " << username << endl << endl;
                    break;
                case 6:
                    cout << endl << "Enter the filename to save data (followed by .csv): ";
                    cin >> filename;
                    saveData(filename);
                    cout << "Data saved to file: " << filename << endl;
                    cout << "Program by: " << username << endl << endl;
                    break;
                case 7:
                    cout << endl;
                    // Removes temp filename from disk.(Refer to lines 294 to 299).
                    remove(getFilename().c_str());
                    loadData();
                    saveData(getFilename());
                    cout << "Program by: " << username << endl << endl;
                    break;
                case 0:
                    // Removes temp filename from disk.(Refer to lines 294 to 299). 
                    remove(getFilename().c_str()); 
                    cout << "Exiting..." << endl;
                    return;
                default:
                    cout << endl << "Invalid choice. Please try again." << endl;
                    cout << endl;
                    validInput = false;
                }
            }
            else {
                // Invalid input is a non-integer.
                cout << endl << "Invalid input. Please enter a valid integer choice." << endl;
                cout << endl;
                cin.clear();
                // Clears the input buffer after reading an integer input
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    /**
     * Checks if a string contains any digits.
     * @param str The string to check.
     * @return True if the string contains digits, false otherwise.
     */
    bool containsDigits(string& str) {
        for (char c : str) {
            if (isdigit(c)) {
                return true;
            }
        }
        return false;
    }
};

/**
 * @class RecordMVC.
 * Represents the Model-View-Controller (MVC) structure for the Record management system.
 * The RecordMVC class acts as the entry point for the MVC application. It consists of a private
 * RecordController object that handles the control flow and interactions between the Model and View.
 * The run() method is responsible for running the application by invoking the necessary methods
 * in the controller.
 */
class RecordMVC {

private:
    RecordController controller;

public:

    /**
     * Runs the application by invoking necessary methods in the controller.
     * It first calls the loadData() method in the controller to load any existing data.
     * Then, it calls the runMenu() method to start the main menu and user interaction loop.
     */
    void run() {
        controller.loadData();
        controller.runMenu();
    }
};

/**
 * The main function creates an instance of the RecordMVC class and invokes its run() method
 * to start the application.
 */
int main() {
    RecordMVC mvc;
    mvc.run();
    return 0;
}

