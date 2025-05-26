#include "ScanTable.h"

<<<<<<< HEAD
enum SortMethod {Insert, Merge, Quick};

class SortTable : public ScanTable
{
public:
    SortMethod _sortMethod;
    void InsertSort(PTabRecord *data, size_t count);
=======
enum SortMethod {Isert, Merge, Quick};
class SortTable : public ScanTable
{
protected:
    SortMethod _sortMethod;
    void InsertSort(PTabRecord *data, size_t count);
    
    void QuickSort(PTabRecord *data, size_t count);
    void QuickSplit(PTabRecord *data, size_t count, size_t &pivot);
>>>>>>> a853707 (21)

    void MergeSort(PTabRecord *data, size_t count);
    void MergeSorter(PTabRecord* &data, PTabRecord* &buffer, size_t size);
    void MergeData(PTabRecord* &data, PTabRecord* &buffer, size_t n1, size_t n2);

<<<<<<< HEAD
    void QuickSort(PTabRecord *data, size_t count);
    void QuickSplit(PTabRecord *data, size_t count, size_t& pivot);

    void SortData();

public:
    SortTable() : ScanTable(){
        _tabSize = 25;
    }

    SortTable(size_t tabSize) : ScanTable(tabSize){
        _tabSize = tabSize;
    }
    SortTable(const ScanTable& st);

    SortTable& operator=(const ScanTable& st);

    SortMethod GetSortMethod() const{
        return _sortMethod;
    }
    void SetSortMethod(SortMethod sortMethod) {
        _sortMethod = sortMethod;
    }

    virtual PDataValue FindRecord(Key key) override;
    virtual void DelRecotd(Key key) override;
    virtual void InsRecord(Key key, PDataValue value) override;
};
=======
    void SortData();

public:
    SortTable(size_t tabSize = 25) : ScanTable(tabSize) {}
    SortTable(const ScanTable& st) { *this = st; }

    SortTable& operator=(const ScanTable& st);

    SortMethod GetSortMethod() const {
        return _sortMethod;
    }

    void SetSortMethod(SortMethod sortMethod){
        _sortMethod = sortMethod;
    }

    virtual PDataValue FindRecord(Key key);
    virtual void DelRecotd(Key key);
    virtual void InsRecord(Key key, PDataValue value);

    ~SortTable();
};

>>>>>>> a853707 (21)
