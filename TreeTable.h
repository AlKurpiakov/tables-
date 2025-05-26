#include "TreeNode.h"
#include "Table.h"
#include <stack>
#include <string>

class TreeTable : public Table
{
protected:
    PTreeNode _pRoot;
    PTreeNode *_ppRef;
    PTreeNode _pCurrent;
    size_t _curPos;
    std::stack<PTreeNode> _st;

    std::string s[20];
    size_t _size[20];

    size_t pos;

    void PrintTreeTable(std::ostream& os, PTreeNode root);
    void DrawTreeTable(PTreeNode root, size_t lvl);
    void DeleteTreeTable(PTreeNode node);

    void PutValues();
public:
    TreeTable() : Table() {
        _curPos = 0;
        _pCurrent = nullptr;
        _pRoot = nullptr;
        _ppRef = nullptr;
    }

    bool IsFull() const override;

    bool Reset() override;
    bool IsTabEnded() const override;
    bool GoNext() override;

    Key GetKey() const;
    PDataValue GetValue() const override;

    PDataValue FindRecord(Key key) override;
    void DelRecotd(Key key) override;
    void InsRecord(Key key, PDataValue value) override; 
    
    friend std::ostream operator<<(std::ostream & os, TreeTable);
    void Draw() const;
    void Show() const;

    ~TreeTable(){
        DeleteTreeTable(_pRoot);
    }
};
