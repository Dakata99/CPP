#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
#include <string.h>
#include <stdlib.h>

enum ElementType{LIST, BTREE, INT};

// ���������� ��� ������� �� ���������
class AbstractElement
{ 
public:
    // ������������ ���������� ��� �� ��������
    virtual int getType() const = 0;
    // �������� �� ������������ � ������� �����
    // ������� ������ �� ����� �������� ����, �� ����
    // ���� ���� ��� ���������� �� ��������������
    // �� ���� �� ������� ���������� ��
    virtual ostream& write(ostream&) const = 0;
    // ��������, ����� ������ �� ������� ����� ��
    // ����������� �� �����, �������� �� ��������� <<
    virtual istream& read(istream&) = 0;
    // ������� ����� �� ����� �� �����������
    // ���������� �� �bstractElement ������
    // ������� ���, ������� ���� ����������
    static AbstractElement* elementFactory(int type);
    // ������� ����� �� ������� �������. ������� � ��������
    // ����� � ��������� ����������. ������� �� ������������
    // �� �������� �� ���������� ����
    static AbstractElement* copyElement(AbstractElement*);
};

// ���� �� ����������� �� �������� � ���� �����
class IntElement : public AbstractElement
{ 
public:
    IntElement(int value) : i(value)
    {}

    int getType() const
    { 
        return INT;
    }

    ostream& write(ostream& out) const
    { 
        out << i << " ";
        return out;
    }

    istream& read(istream& in) 
    {
        in >> i;
        return in;
    }

private:
    int i;
};

// ������ ����� �� ��������� ����������� ������
struct DListNode
{ 
    DListNode(AbstractElement* _data, DListNode* _next)
              : data(_data), next(_next)
    {};
    AbstractElement *data;
    DListNode *next;
};

//���������, �������� ���� �� �������
const int listEnd = -1;

// ������ ����������� ������
class DList : public AbstractElement
{ 
public:
    DList() : first(NULL), count(0)
    {};

    // ����������� �� ��������
    DList(const DList& l) : first(NULL), count(0)
    { 
        copy(l);
    }

    // �������� �� �����������
    DList& operator=(const DList& l)
    { 
        if(this == &l)
            return *this;
        clearAll();
        copy(l);
        return *this;
    }

    int getType() const
    { 
        return LIST;
    }

    // ������ ������� �� ���������� ������� � �������, �
    // ��� index == listEnd, � ���� ��.
    // ��� ������� ����� ������ �� ���������� � �������,
    // ������ ���� � ���� ��.
    bool addElementAt(AbstractElement *element, int index)
    { 
        if(!first || index == 0)
            return addFirst(element);
        DListNode* previous = first;
        // ������ �������� ��� ��������, ���� ����� �� ������ ����� �������
        index--;
        while(previous->next != NULL && index != 0)
        { 
            previous = previous->next;
            index--;
        }
        return insertAfter(previous, element);
    }

    // ����� �������� �� ���������� ������� � ������� � NULL, ��� ���� �����
    AbstractElement* getElementAt(int index) const
    { 
        if(!first || index < 0 || index >= count)
            return NULL;
        DListNode* current = first;
        while(current && index != 0)
        { 
            current = current->next;
            index--;
        }
        return current->data;
    }

    // ������ ����� ���� �� ������� �� �����
    void print() const
    { 
        DListNode* current = first;
        while(current)
        { 
            current->data->write(cout);
            current = current->next;
        }
    }

    ostream& write(ostream& out) const
    { 
        // ������� ����� ���� �� ����������
        out << count << " ";
        // �������������� ������������ ����� �������
        DListNode* current = first;
        while(current)
        {
            // ������� ���� �� �������� �������
            out << current->data->getType() << " ";
            // � ����� �������
            current->data->write(out);
            current = current->next;
        }
        return out;
    }

    istream& read(istream& in)
    { 
        clearAll();
        int newCount, newElementType;
        AbstractElement* newElement;
        in >> newCount;
        // �������������� ����� �� ���������� ��������
        for(; newCount > 0; newCount--)
        { 
            // ����� � ����� �� ���� �������?
            in >> newElementType;
            // ��������� �� ������������ �� ������� �� ���� ���
            newElement = AbstractElement::elementFactory(newElementType);
            if(newElement == NULL)
            { 
                cout << "������! �������� ���!";
                return in;
            }
            // ������� ������ �� ����� �����, �����
            // �� ������� ������������ �� �� ���
            newElement->read(in);
            addElementAt(newElement, listEnd);
        }
        return in;
    }

    ~DList()
    { 
        clearAll();
    }

private:
    DListNode *first;
    int count;
    // ������� ������ ��������
    void clearAll()
    { 
        if(!first)
            return;
        DListNode* current = first,
                 * next = first->next;
        while(current)
        { 
            delete current->data;
            delete current;
            current = next;
            if(current != NULL)
                next = current->next;
        }
    }

    // ������ ��� ������� ���� ������� ������ ��, �� previous � ��������
    bool insertAfter(DListNode* previous, AbstractElement* element)
    { 
        previous->next = new DListNode(element, previous->next);
        count++;
        return previous->next != NULL;
    }

    // ������� ������ ������� �� �������
    bool addFirst(AbstractElement *element)
    { 
        first = new DListNode(element, first);
        count++;
        return first != NULL;
    }

    // ������ ���������� �� ������� src
    void copy(const DList& src)
    { 
        DListNode* current = src.first;
        while(current != NULL)
        { 
            addElementAt(AbstractElement::copyElement(current->data), listEnd);
            current = current->next;
        }  
    }
};


// ���� �� ������� �����
struct BTreeNode
{ 
    BTreeNode(AbstractElement *_data, BTreeNode *_left, BTreeNode *_right) 
              : data(_data), left(_left), right(_right)
    {};
    AbstractElement* data;
    BTreeNode *left, *right;
};

class BTree;

// ������� ���� �� ��������� �� ������� �����
class BTreeIterator
{ 
public:
    // ��� ���������, ����������
    // ���� ������ �� �������
    BTreeIterator(BTree* _tree);
    // ����� �������� ��� ������ ��������
    // ��� ������� � ������, ����� ����� �� ����� ��������
    BTreeIterator left();
    // ����� �������� ��� ������� ��������
    // ��� ������� � ������, ����� ����� �� ����� ��������
    BTreeIterator right();
    // ����� ���������� �� ������ �� ����������
    AbstractElement* root();
    // ������� ���������� �� ������
    // ��� ���������� � ������, � �������
    // �� ������ ��� ���� � ���� ��������
    bool changeRoot(AbstractElement* data);
    // �������� �� ������ �����
    bool empty();

private:
    // ����� ��������, �� �� ���� �� ���� ��������� ����������
    // �� ���� ������������ ��������� � ����������� ��
    // �������, �������� ��� �������� �� ��� �������
    BTreeNode **currentNode;
    BTree *tree;
};

// ������, ���������� ������� ����� ����
// ���� �� ���� ������� �� ���������
class BTree : public AbstractElement
{ 
public:
    BTree() : root(NULL)
    {}

    // ����������� �� ��������
    BTree(const BTree& tree) : root(NULL)
    { 
        copy(tree);
    }

    // �������� �� �����������
    BTree& operator=(const BTree& tree)
    { 
        if(this != &tree)
            copy(tree);
        return *this;
    }  

    // ����� �������� ��� �������
    BTreeIterator iterator()
    { 
        return BTreeIterator(this);
    }

    int getType() const
    { 
        return BTREE;
    }

    ostream& write(ostream& out) const
    { 
        writeNode(root, out);
        return out;
    }

    istream& read(istream& in)
    { 
        clearAll(root);
        root = NULL;
        readNode(root, in);
        return in;
    }

    // ������ ����� ���� �� ������� �� �����
    void print()
    { 
        prettyPrint(root);
    }

    ~BTree()
    { 
        clearAll(root);
    }

    friend class BTreeIterator;

private:
    BTreeNode *root;

    // ������ ����� ���� �� ������� �� �����
    void prettyPrint(BTreeNode *root, int level=0)
    { 
        if(!root)
            return;
        prettyPrint(root->left, level+1);
        cout << setw(level*3) << " ";
        root->data->write(cout);
        cout << endl;
        prettyPrint(root->right, level+1);
    }

    void clearAll(BTreeNode *root)
    { 
        if(!root)
            return;
        clearAll(root->left);
        clearAll(root->right);
        delete root->data;
        delete root;
    }

    void writeNode(BTreeNode* root, ostream& out) const
    { 
        if(!root)
        { 
            out << "() ";
            return;
        }
        out << "( ";
        writeNode(root->left, out);
        out << root->data->getType() << " ";
        root->data->write(out);
        writeNode(root->right, out);
        out << ") ";
    }

    void readNode(BTreeNode*& root, istream& in)
    { 
        char c;
        // ���������� �� ���������� �����
        in >> c;
        // ��� ������� ������ ��������� �����, ������� � ������
        if(in.peek() == ')')
        { 
            // ���������� �� ����������� �����
            in >> c;
            return;
        }
        BTreeNode * newLeft  = NULL,
                  * newRight = NULL;
        // ��������� �� ������ ��������
        readNode(newLeft, in);
        int type;
        // ������� �� �����, ������������� ���� ��
        // ������������ �� ������. ������� �� ������
        // ����� �� ���� ��� � �� �������� read ��
        // ��������� �� ������������ ��
        in >> type;
        AbstractElement* data = AbstractElement::elementFactory(type);
        data->read(in);
        // ��������� �� ������� ��������
        readNode(newRight, in);
        // ���������� �� ����������� �����
        in >> c;
        // ��������� �� ����� ����
        root = new BTreeNode(data, newLeft, newRight);
        return;
    }

    // ������� �������� ����� � ������� ��������� ����� �� ������� tree
    void copy(const BTree& tree)
    {
        clearAll(root);
        root = copyNode(tree.root);
    }

    // �������� �� �� copy
    BTreeNode* copyNode(BTreeNode* node)
    { 
        if(node == NULL)
            return NULL;
        return new BTreeNode (AbstractElement::copyElement(node->data),
                              copyNode(node->left),
                              copyNode(node->right));
    }
};

BTreeIterator::BTreeIterator(BTree *_tree)
{ 
    tree = _tree;
    currentNode = &tree->root;
}

BTreeIterator BTreeIterator::left()
{ 
    BTreeIterator it = *this;
    if(*currentNode)
        it.currentNode = &(*currentNode)->left;
    return it;
}

BTreeIterator BTreeIterator::right()
{ 
    BTreeIterator it = *this;
    if(*currentNode)
        it.currentNode = &(*currentNode)->right;
    return it;
}

AbstractElement *BTreeIterator::root()
{ 
    if(*currentNode)
        return (*currentNode)->data;
    return NULL;
}

bool BTreeIterator::changeRoot(AbstractElement *data)
{ 
    if(*currentNode)
    {
        delete (*currentNode)->data;
        (*currentNode)->data = data;
    } 
    else
    {
        (*currentNode) = new BTreeNode(data, NULL, NULL);
    }
    // �� ����� �� ����� ��������� �� �������, �����
    // � ��������� ��������� �� ��� �������
    return *currentNode != NULL;
}

bool BTreeIterator::empty()
{ 
    return *currentNode == NULL;
}

AbstractElement* AbstractElement::elementFactory(int type)
{ 
    switch(type)
    { 
    case INT: return new IntElement(0);
    case LIST: return new DList;
    case BTREE: return new BTree;
    }
    return NULL;
}

AbstractElement* AbstractElement::copyElement (AbstractElement* element)
{ 
    switch (element->getType())
    { 
    case INT: return new IntElement(*(IntElement*)element);
    case LIST: return new DList(*(DList*)element);
    case BTREE: return new BTree (*(BTree*)element);
    }
    return NULL;
}

void writeDemo()
{ 
    //��������� �� ������ � �������� 1, 2 � 3
    DList *l1 = new DList;
    l1->addElementAt(new IntElement(1), listEnd);
    l1->addElementAt(new IntElement(2), listEnd);
    l1->addElementAt(new IntElement(3), listEnd);
    // ��������� �� ������ � �������� 4, 5 � 6
    DList *l2 = new DList;
    l2->addElementAt(new IntElement(4), listEnd);
    l2->addElementAt(new IntElement(5), listEnd);
    l2->addElementAt(new IntElement(6), listEnd);
    // ��������� �� ������� �����
    BTree *t = new BTree;
    t->iterator().changeRoot(new IntElement(7));
    t->iterator().left().changeRoot(new IntElement(8));
    // �������� �� �������� l1 ���� ������� �� �������
    t->iterator().left().left().changeRoot(l1);
    t->iterator().right().changeRoot(new IntElement(9));
    // ��������� �� ������ � ��������: ������, �����, �����
    DList theList;
    theList.addElementAt(l1, listEnd);
    theList.addElementAt(new IntElement(10), listEnd);
    theList.addElementAt(t, listEnd);
    // ��������� �� ����, � ����� �� �� ������ ��������
    ofstream file("data.txt");
    theList.write(file);
}

void readDemo()
{ 
    DList l;
    // ������� �������, ������� �� writeDemo
    ifstream file("data.txt");
    // ��������! ��������� �������, �� ���� ���� � ��������
    // �� writeDemo. � �������� ������ ����������
    // �������������� ���� �� �� �� ��������
    l.read(file);
    // ������� writeDemo ������� ������� ����� ���� �����
    // ������� �� �������
    // ����������� �� ������������ ������� �� ����������
    // ���� BTree, �� �� �� ������� ������ �� ������
    // print, ����� � ���������� �� ����� �� �������
    ((BTree*)l.getElementAt(2))->print();
}

int main()
{ 
    writeDemo();
    readDemo();
    return 0;
}
