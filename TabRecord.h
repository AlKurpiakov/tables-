#pragma once
#include "DatValue.h"

using Key = std::string;
using PDataValue = DatValue*;

class TabRecord: public DatValue{
protected:
    Key _key;
    PDataValue _data;
public:
    TabRecord(Key key="", PDataValue data = nullptr);
    void SetKey(Key key);
    Key GetKey() const{
        return _key;
    }
    void SetData(PDataValue data);
    PDataValue GetData() const{
        return _data;
    }
    virtual PDataValue GetCopy();
    const virtual void Print(std::ostream& os) ;
    TabRecord& operator=(const TabRecord& tr);

    bool operator==(const TabRecord& tr) const;
    bool operator<(const TabRecord& tr) const;
    bool operator>(const TabRecord& tr) const;

    friend class ScanTable;
    friend class ArrayTable;
    friend class SortTable;
};