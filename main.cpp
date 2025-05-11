#include <iostream>
#include "ArrayTable.h"
#include "DatValue.h"
#include "Marks.h"
#include "ScanTable.h"
#include "Table.h"
#include "TableTestKit.h"
#include "SortTable.h"
#include "TabRecord.h"

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