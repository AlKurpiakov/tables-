#pragma once
#include "ScanTable.h"

class TableTestKit
{
private:
    Table& _table;
    //добавить переменные
public:
    TableTestKit(Table& table): _table(table) {}

    void GenerateData();
    void PrintTable();
    void FillTable();
    void RemoveRecord(); //100 запусков
    void FindRecord(); //100
    void PrintMetrics();
};

