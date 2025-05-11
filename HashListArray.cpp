#include "HashListArray.h"

bool HashListArray::IsFull() const{
    try{
        PTabRecord tmp = new TabRecord("", nullptr);
    }
    catch (const char* ) {
        return true;
    }
    return false;
}

HashListArray::HashListArray(size_t tabSize) {
    _tabSize = tabSize;
    _lists = new std::forward_list<PTabRecord>[tabSize];
    _efficiency = 0;
    _curList = 0;
}

HashListArray::~HashListArray(){
    for (size_t i = 0; i < _tabSize; i++){
        for (auto rec: _lists[i]) {
            delete rec;
        }
    }
    delete [] _lists;
}

bool HashListArray::IsTabEnded() const {
    return _curList == _tabSize;
}

bool HashListArray::Reset() {
    int _curList = 0;
    for (int i = 0; i < _tabSize; i++){
        for (auto rec: _lists[_curList]) {
            if (rec != nullptr && rec!= _mark){
                break;
            }
        }
        _curList += 1;
    }
    return IsTabEnded();
}


bool HashListArray::GoNext() {
    if (IsTabEnded()){
        return false;
    }

    while (++_curList < _tabSize){
        for (auto rec: _lists[_curList]) {
            if (rec != nullptr && rec!= _mark){
                break;
            }
        }
    }

    return IsTabEnded();
}

Key HashListArray::GetKey() const {
    if (_curList >= _tabSize) return "";
    for (auto rec : _lists[_curList])
        return rec->GetKey();
}

PDataValue HashListArray::GetValue() const {
    if (_curList >= _tabSize) return nullptr;
    for (auto rec : _lists[_curList])
        return rec->GetData();
    
}

PDataValue HashListArray::FindRecord(Key key) {

}

void HashListArray::DelRecotd(Key key) {

}

void HashListArray::InsRecord(Key key, PDataValue value) {

}