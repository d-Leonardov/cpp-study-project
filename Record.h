#pragma once
#include <string>
using namespace std;

class Record {
private:
    string column1;
    string column2;
    string column3;
    string column4;
    string column5;
    string column6;
    string column7;
    string column8;
    string column9;
    string column10;
    string column11;
    string column12;
    string column13;
    string column14;
    string column15;
    string column16;

public:
    Record(const string& col1, const string& col2, const string& col3,
        const string& col4, const string& col5, const string& col6,
        const string& col7, const string& col8, const string& col9,
        const string& col10, const string& col11, const string& col12,
        const string& col13, const string& col14, const string& col15,
        const string& col16)
        : column1(col1), column2(col2), column3(col3), column4(col4), column5(col5),
        column6(col6), column7(col7), column8(col8), column9(col9), column10(col10),
        column11(col11), column12(col12), column13(col13), column14(col14), column15(col15),
        column16(col16) {}

    const string& getColumn1() const { return column1; }
    const string& getColumn2() const { return column2; }
    const string& getColumn3() const { return column3; }
    const string& getColumn4() const { return column4; }
    const string& getColumn5() const { return column5; }
    const string& getColumn6() const { return column6; }
    const string& getColumn7() const { return column7; }
    const string& getColumn8() const { return column8; }
    const string& getColumn9() const { return column9; }
    const string& getColumn10() const { return column10; }
    const string& getColumn11() const { return column11; }
    const string& getColumn12() const { return column12; }
    const string& getColumn13() const { return column13; }
    const string& getColumn14() const { return column14; }
    const string& getColumn15() const { return column15; }
    const string& getColumn16() const { return column16; }
};

