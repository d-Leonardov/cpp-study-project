#ifndef RECORD_CONTROLLER_H
#define RECORD_CONTROLLER_H

#include <iostream>
#include "RecordModel.h"
#include "RecordView.h"

using namespace std;

class RecordController {
    RecordModel model;
    RecordView view;

public:
    void loadData();
    void saveData(const string& filename);
    void displayRecord(const string& username);
    void displayRecords(const string& username);
    void addRecord();
    void editRecord();
    void deleteRecord();
    void runMenu();

private:
    bool containsDigits(string& str);
};

#endif  // RECORD_CONTROLLER_H
