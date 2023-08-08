#pragma once
#include "Record.h"
#include <vector>

using namespace std;

class RecordModel {

private:
    vector<Record> records;
    string filename;

public:
    void loadData();
    string getFilename();
    int countRecords(const string& filename);
    int countTotalRecords(const string& filename);
    void saveData(const string& filename);
    void addRecord(const Record& record);
    bool editRecord(int index, const Record& record);
    bool deleteRecord(int index);
    const vector<Record>& getRecords() const;
};

