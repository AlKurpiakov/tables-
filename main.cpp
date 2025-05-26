#include <iostream>
#include "ArrayTable.h"
#include "DatValue.h"
#include "Marks.h"
#include "ScanTable.h"
#include "Table.h"
#include "TableTestKit.h"
#include "SortTable.h"
#include "TabRecord.h"

void merge (int *a, int left, int mid,int right){
    int it1 = 0,  it2 = 0;
    int res[right - left];

    while (left + it1 < mid && mid + it2 < right){
        if (a[left + it1] < a[mid + it2]) {
            res[it1 + it2] = a[left + it1];
            it1++;
        }
        else {
            res[it1 + it2] = a[mid + it2];
            it2++;
        }
    }

    while (mid + it2 < right){
        res[it1 + it2] = a[mid + it2];
        it2++;
    }

    while (left + it1  < right){
        res[it1 + it2] = a[left + it1];
        it1++;
    }

    for (int i = 0; i < it1+it2; i++){
        a[i + left] = res[i]; 
    }

}


void mergeSort(int *a, int left , int right){
    if (left + 1 >= right) return;

    int mid = (left + right) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);

}

void swap(int* x, int* y){
    int *cup = x;
    x = y;
    y = cup;
}

int partition(int *a, int l, int r){
    int val = a[(l + r) / 2];
    int i = l, j = r;

    while (i <= j){
        while (val > a[i])
        {
            i++;
        }
        while (val < a[j])
        {
            j--;
        }
        if (i >= j) break;

        swap( a + i, a + j);
    }

    return j;

}


void qSort(int *a, int l, int r){
    int p;
    if (l < r){
        p = partition(a, l, r);
        qSort(a, l, p);
        qSort(a, p, r);
    }
}



int main(){
    ScanTable table(10);  
    TableTestKit tester(table);
    tester.InitRandom();
    
    tester.FillTable(10);  

    std::cout << "Initial table:\n";
    tester.PrintTable();

    std::cout << "\nSearching for records:\n";
    tester.FindRecord();

    std::cout << "\nRemoving records:\n";
    tester.RemoveRecord();

    std::cout << "\nTable after removals:\n";
    tester.PrintTable();

    std::cout << "\nFinal table metrics:\n";
    tester.PrintMetrics();

    
//     SortTable table(10); 

//     //table.SetSortMethod(SortMethod::Insert);

//         table.InsRecord("A", new Marks(5, 4, 3, 5, 4));
//         table.InsRecord("B", new Marks(3, 5, 4, 3, 5));
//         table.InsRecord("C", new Marks(4, 4, 4, 4, 4));
//         table.InsRecord("D", new Marks(5, 5, 5, 5, 5));
//         table.InsRecord("E", new Marks(3, 3, 4, 4, 3));

//     std::cout << "Before sorting:\n";
//     for (size_t i = 0; i < table.GetDataCount(); i++) {
//         std::cout << table.GetKey() << ": " << *table.GetValue() << std::endl;
//         table.GoNext();
//     }

//     table.SetSortMethod(SortMethod::Insert);
//     table.SortData();

//     std::cout << "\nAfter sorting:\n";
//     table.Reset();
//     for (size_t i = 0; i < table.GetDataCount(); i++) {
//         std::cout << table.GetKey() << ": " << *table.GetValue() << std::endl;
//         table.GoNext();
//     }

//     std::cout << "\nSearching for record with key 'C':\n";
//     PDataValue foundValue = table.FindRecord("C");
//     if (foundValue != nullptr) {
//         std::cout << "Found: " << *foundValue << std::endl;
//     } else {
//         std::cout << "Record not found!" << std::endl;
//     }

//         std::cout << "\nDeleting record with key 'B':\n";
//         table.DelRecotd("B");

//     std::cout << "\nAfter deletion:\n";
//     table.Reset();
//     for (size_t i = 0; i < table.GetDataCount(); i++) {
//         std::cout << table.GetKey() << ": " << *table.GetValue() << std::endl;
//         table.GoNext();
//     }

    return 0;
}