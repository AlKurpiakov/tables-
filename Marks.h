#include "DatValue.h"

class Marks : public DatValue
{
private:
    uint8_t _math;
    uint8_t _chem;
    uint8_t _zov;
    uint8_t _diffurs;
    uint8_t _linal;
public:
    Marks(uint8_t math,
    uint8_t chem,
    uint8_t zov,
    uint8_t diffurs,
    uint8_t linal){
     _math = math;
    _chem = chem;
   _zov = zov;
    _diffurs = diffurs;
    _linal = linal;
    }

    PDataValue GetCopy(){
    PDataValue tmp = new Marks(_math);
    return tmp;
}

const void Print(std::ostream& os){
    os << "hello)";
    return;
}
    ~Marks();
};


