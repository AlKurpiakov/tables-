#include "TabRecord.h"

PDataValue TabRecord::GetCopy(){
    PDataValue tmp = new TabRecord(_key, _data);
    return tmp;
}

const void TabRecord::Print(std::ostream& os){
    os << "hello)";
    return;
}