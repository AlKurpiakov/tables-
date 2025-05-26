#include "TabRecord.h"

using PTreeNode = TreeNode*;


class TreeNode : TabRecord
{
protected:
    PTreeNode _right;
    PTreeNode _left;

public:
    TreeNode(Key key = "", PDataValue value = nullptr, PTreeNode right =nullptr, PTreeNode left =nullptr): TabRecord(key, value){
        _right = right;
        _left = left;
    }

    PTreeNode GetRight() const{
        return _right;
    }
    
    PTreeNode GetLeft() const{
        return _left;
    }

    virtual PDataValue GetCopy() override {
        PTreeNode s = new TreeNode(_key, _data, nullptr, nullptr);
        return s;
    }

    friend class TreeTable;
    friend class BalancedTreeTable;
    

    ~TreeNode();
};
