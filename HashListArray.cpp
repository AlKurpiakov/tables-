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
    _curList = 0;
    _listPos = 0;
    for (int i = 0; i < _tabSize; i++){
        for (auto rec: _lists[_curList]) {
            if (rec != nullptr && rec!= _mark){
                break;
            }
            _listPos += 1;
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
    int i = 0;
    for (auto rec : _lists[_curList]){
        if(i == _listPos){
            return rec;
        }
        i++;
    }
}

PDataValue HashListArray::FindRecord(Key key) {
    _efficiency = 0;
    PDataValue tmp = nullptr;
    _freePos[0] = -1;
    _curList = HashFunc(key) % _tabSize;
    size_t list_pos;
    for (auto rec : _lists[_curList]){
        _efficiency += 1;
        if (rec == nullptr) break;
        else{
            if (rec == _mark) {
                if (_freePos[0] == -1){
                    _freePos[0]= _curList;
                    _freePos[1] = list_pos;
                }
            }
            else{
                if (rec->GetKey() == key){
                    tmp = rec->GetData();
                    break;
                }
            }
        }
        _listPos += 1;
    }
    return tmp;
}

void HashListArray::DelRecotd(Key key) {
    if (!(FindRecord(key))) throw "No value";
    int i = 0;
    for (auto rec : _lists[_curList]){
        if(i == _listPos){
            delete rec;
            rec = _mark;
        }
        i++;
    }
    _dataCount--;
}

void HashListArray::InsRecord(Key key, PDataValue value) {
    if (IsFull()) throw "Table is Full";
    PDataValue tmp = FindRecord(key);
    if (tmp != nullptr) throw "Dublicate";
    if (_freePos[0] != -1) _curList = _freePos[0];
    size_t _cur_list_pos = ((_freePos[0] != -1) ? _freePos[1] : 0);
    int i = 0;
    for (auto rec : _lists[_curList]){
        if(i == _cur_list_pos){
            rec = new TabRecord(key, value);
        }
        i++;
    }
    _dataCount++;
}