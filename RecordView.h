#ifndef RECORD_VIEW_H
#define RECORD_VIEW_H

#include <vector>
#include "Record.h"

using namespace std;

class RecordView {

public:
    void displayOneRecord(const Record& record, const string& username);
    void displayRecord(const Record& record);
    void displayRecords(const vector<Record>& records, const string& username);
    Record createRecord();
    int selectRecordIndex();
};

#endif  // RECORD_VIEW_H