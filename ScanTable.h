#pragma once 
#include"ArrayTable.h"

<<<<<<< HEAD
class ScanTable: public ArrayTable{
    public:
    ScanTable():ArrayTable(){}
    ScanTable(size_t size):ArrayTable(size){}
    virtual PDataValue FindRecord(Key key);
    virtual void DelRecotd(Key key);
    virtual void InsRecord(Key key, PDataValue value);
};
=======
class ScanTable : public ArrayTable
{
public:
    ScanTable(size_t size) : ArrayTable(size){}
    virtual PDataValue FindRecord(const Key& key);
    virtual void InsRecord(Key key, PDatValue data);
    virtual void DelRecord(Key key);
};
>>>>>>> a853707 (21)
