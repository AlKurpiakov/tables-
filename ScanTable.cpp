<<<<<<< HEAD
#include"ScanTable.h"
PDataValue ScanTable::FindRecord(Key key){
    int i = 0;
    for(i; i < _dataCount; i++){
        if(key == _records[i]->_key){
            break;
        }
=======
#include "ScanTable.h"

PDataValue ScanTable::FindRecord(const Key& key){
    size_t i = 0;
    for (i; i < _dataCount; i++){
        if(key == _records[i]->_key) break;
>>>>>>> a853707 (21)
    }
    _efficiency = i+1;
    if(i < _dataCount){
        _curPos = i;
        return _records[i]->_data;
    }
    return nullptr;
}
void ScanTable::DelRecotd(Key key){
    if(FindRecord(key) == nullptr) throw "!!!";
    delete _records[_curPos];
    _records[_curPos] = _records[_dataCount - 1];
    _records[--_dataCount] = nullptr;
    Reset();
}
<<<<<<< HEAD
void ScanTable::InsRecord(Key key, PDataValue data){
    if(IsFull()){
        throw "Table is Full";
    }
    _records[_dataCount++] = new TabRecord(key, data);
=======

void ScanTable::InsRecord(Key key, PDatValue data){
    if (IsFull()) { throw "Table is Full"; }
    _records[_dataCount++] = new PTabRecord(key, data);
>>>>>>> a853707 (21)
}