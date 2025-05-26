#include "TreeTable.h"

bool TreeTable::IsFull() const{
    try {
        PTreeNode node = new TreeNode;
    }
    catch (const char*){
        return true;
    }
    return false;

}