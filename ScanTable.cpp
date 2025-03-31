#include "ScanTable.h"

PDataValue ScanTable::FindRecord(Key key){
    size_t i = 0;
    for (i; i < _dataCount; i++){
        if(key == _records[i]->_key) break;
    }
    _effiency = i + 1;
    if(i < _dataCount){
        _curPos = i;
        return _records[i]->_data;
    }
    return nullptr;
}

void ScanTable::DelRecord(Key key){
    if (FindRecord(key) == nullptr){
        throw "loshok";
    
    }
    delete _records[_curPos];
    _records[_curPos] = _records[_dataCount - 1];
    _record[--_dataCount] = nullptr;
    Reset();

}

void ScanTable::InsRecord(Key key, PDatValue data){
    if (IsFull()){ throw "Table is Full";}
    _records[_dataCount++] = new PTabRecord(key, data);
}