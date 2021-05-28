#include <iostream.h>
#include <iomanip.h>

class IntSequence
{ 
public:
    // ��������� �� ������� �� ���������� ������� � ������
    virtual bool addElementAt(int value, int index) = 0;

    // ������� �� ������� �� ���������� ������� � ������
    // �������� ��:
    // �) ������� � ����� ������ � ������� � ��������
    // ��������� ����� ������ �
    // ������� � value ���������� �� ��������
    // �) ������� � ����� ������ �� � ������� � ��������
    // ��������� ����� ���� � ����������
    // �� value �� � ����������
    virtual bool getElementAt(int &value, int index) const = 0;

    // ���������� �� ������� �� ������ �������
    // ��� ������� � ����� ������ �� � �������,
    // ����� ����, � �������� ������ - ������.
    virtual bool removeElementAt(int index) = 0;

    // �������� �� ���� �� ���������� �� ������
    virtual int count() const = 0;

    // ��������� �����:
    // 1,  ��� ����� ������� ������� �� ������ �
    //     ��-����� �� ���������
    // -1, ��� ����� ������� ������� �� ������ �
    //     ��-����� �� ���������
    // 0,  ��� ������ �������� ������
    virtual int isMonotonous() const = 0;
};

class IntSet
{
public:

    // �������� ���� x ���������� �� ���������
    virtual bool element(int x) const = 0;

    // ��������� �� ������� � ���������
    virtual bool addElement(int x) = 0;

    // ���������� �� ������� �� ���������
    virtual bool removeElement(int x) = 0;

    // �������� ��������� �� ��� ���������
    virtual bool intersection(const IntSet& s) const = 0;

    // �������� ���� ��������� � ������������ �� ������ ���������
    virtual bool subset(const IntSet& s) const = 0;
};

// ������� ����, ���������� ����� ���������� �� ���������� �� ��������� �����
class ArrIndexProxy
{  
public:
    ArrIndexProxy(IntSequence *arr, int index) :
                  targetArr(arr),targetIndex(index)
    {}

    ArrIndexProxy(const ArrIndexProxy& p) :
                  targetArr(p.targetArr), targetIndex(p.targetIndex)
    {}

    // �������� �� ��������� �� ��������
    operator int() const
    { 
        int value;
        targetArr->getElementAt(value, targetIndex);
        return value;
    }

    ArrIndexProxy& operator=(int x)
    { 
        targetArr->addElementAt(x,targetIndex);
        return *this;
    }

    ArrIndexProxy& operator=(const ArrIndexProxy& p)
    {
        return *this = (int)p;
    }

private:
    IntSequence *targetArr;
    int targetIndex;
};

class DynArray : public IntSequence, public IntSet
{
public:
    // ������� �� ������������ � ������� ������ �� ������
    DynArray(int initialSize = 5) : size(initialSize)
    {
        data = new int[size];
        used = new bool[size];
        setUnused(used,size);
    }

    bool addElementAt(int value, int index)
    {
        if(size <= index && !resize(index+1))
            return false;
        data[index] = value;
        used[index] = true;
        return true;
    }

    bool getElementAt(int &value, int index) const
    {
        if(index >= size || !used[index])
            return false;
        value = data[index];
        return true;
    }

    bool removeElementAt(int index)
    {
        if(index >= size || !used[index])
            return false;
        used[index] = false;
        return true;
    }

    int count() const
    {
        int count = 0;
        for(int i = 0; i < size; i++)
            if(used[i]) count++;
        return count;
    }

    int isMonotonous() const
    {
        int a = getNextUsed(-1),
            b = getNextUsed(a);
        if(b < 0)
            return 0;
        int direction = 0;
        if(data[a] == data[b])
            return 0;
        if(data[a] > data[b])
            direction = 1;
        else
            direction = -1;
        // ��������� �� "������", ������ direction == -1
        while(b != -1 && direction*data[a] > direction*data[b])
        {
            a = b;
            b = getNextUsed(b);
        }
        // ������� � ������� ������ ���������� ����� � �� � ������� ������������
        if(b == -1)
            return direction;
        // ������������ � �������
        return 0;
    }

    bool element(int x) const
    {
        int a = getNextUsed(-1);
        while(a != -1 && data[a] != x)
            a = getNextUsed(a);
        return a != -1;
    }

    bool addElement(int x)
    {
        int freeSlot = 0;
        while(freeSlot < size && used[freeSlot])
            freeSlot++;
        if(freeSlot == size && !resize(size+1))
            return false;
        data[freeSlot] = x;
        used[freeSlot] = true;
        return true;
    }

    bool removeElement(int x)
    {
        bool found = false;
        int index = getNextUsed(-1);
        while(index != -1)
        {
            if(data[index] == x)
            {
                used[index] = false;
                found = true;
            }
            index = getNextUsed(index);
        }
        return found;
    }

    bool intersection(const IntSet& s) const
    {
        int index = getNextUsed(-1);
        while(index != -1 && !s.element(data[index]))
            index = getNextUsed(index);
        return index != -1;
    }

    bool subset(const IntSet& s) const
    {
        int index = getNextUsed(-1);
        while(index != -1 && s.element(data[index]))
            index = getNextUsed(index);
        return index == -1;
    }

    // ����� �������� � �������� ������. ���������� �
    // �����������, ��� �� ���� ������� �� � �������� �������.
    // ����� �� ��������� �� ��������� ��������� ����
    // ���� �������� �� ���� �� �� ��������, ��
    // � �� �� �������� ���������� �� �����
    // (����� ���� ArrIndexProxy)
    ArrIndexProxy operator[](int index) const
    {
        ArrIndexProxy proxy((IntSequence*)this,index);
        return proxy;
    }

    ~DynArray()
    {
        delete data;
        delete used;
    }

    // ����� ������� �� ��������� ���� �������
    // (���-������� ���� ������, ��-����� �� index)
    // � -1, ��� ���� �����
    int getNextUsed(int index) const
    {
        index++;
        while(index < size && (index < 0 || !used[index]))
            index++;
        if(index == size)
            return -1;
        return index;
    }

    // ����� ������� �� ��������� ������ �������
    // (���-������ ������ ������, ��-����� �� index)
    // � �� ������ �� ������, ��� ���� �����
    int getNextUnUsed(int index)
    {
        index++;
        while(index < size && (index < 0 || used[index]))
            index++;
        if(index == size  && !resize(index+1))
            return -1;
        return index;
    }

private:
    // ������ �� ��������� ����� (� ���� ��������)
    int size;
    // ����� ��� ���������
    int *data;
    // ��� ��������� � ������ �� ���������� � ��� - ��
    bool *used;

    // ���������� count �� ���� ����� � ������� ����� flags �� false
    void setUnused(bool *flags, int count)
    {
        for(int i = 0; i < count; i++)
            flags[i] = false;
    }

    // ��������� ������� �� ������ �� ����� �����, ��
    // �� ����� ��-����� ��� ����� �� minSize
    bool resize(int minSize)
    {
        int newSize = size;
        while(newSize < minSize)
            newSize *= 2;
        int *newData = new int[newSize];
        bool *newUsed = new bool[newSize];
        // �������� �� ������� ��� �������� �� �������
        if(!newData || !newUsed)
            return false;
        // ����������� �� ������� �����
        for(int i = 0; i < size; i++)
        {
            newData[i] = data[i];
            newUsed[i] = used[i];
        }
        setUnused(newUsed+size,newSize-size);
        int *saveData = data;
        bool *saveUsed = used;
        data = newData;
        used = newUsed;
        size = newSize;
        delete saveData;
        delete saveUsed;
        return true;
    }
};

class IntBinOrdTree : public IntSet
{
public:
    IntBinOrdTree() : root(-1)
    {}

    virtual bool element(int x) const
    {
        if(root != -1 && getValue(root) == x)
            return true;
        int parent = findParent(x,root);
        return parent != -1 &&
              ((leftChild(parent) != -1 && getValue(leftChild(parent)) == x) ||
               (rightChild(parent) != -1 && getValue(rightChild(parent)) == x));
    }

    virtual bool addElement(int x)
    {
        // ������� � ������
        if(root == -1)
        { 
            // ��������� �� ��� ����� � ����� 0
            root = 0;
            return createNodeAt(x,0);
        }
        int parent = findParent(x,root),
            newIndex = -1;
        // ��� ����� �� ����� �������
        newIndex = data.getNextUnUsed(-1);
        if(x <= getValue(parent))// ��������� ������ �� �� ������ ���� ��� ���������
        { 
            // ��������� ���� ����������
            if(leftChild(parent) != -1)
                return true;
            // ��������� �� ����� �������
            if(!createNodeAt(x,newIndex))
                return false;
            // ��������� �� �������� � ����� �������
            data[parent*3+1] = newIndex/3;
            return true;
        }

        // ��������� ������ �� �� ������ ���� ����� ���������
        // ��������� ���� ����������
        if(rightChild(parent) != -1)
            return true;

        // ��������� �� ����� �������
        if(!createNodeAt(x, newIndex))
            return false;

        // ��������� �� �������� � ����� �������
        data[parent*3+2] = newIndex/3;
        return true;
    }

    virtual bool removeElement(int x)
    { 
        if(root == -1)
            return false;
        // ��������� �� ������
        if(getValue(root) == x)
        { 
            root = eraseRoot(root);
            return true;
        }
        else if(x < getValue(root))
        {
            return eraseFromSubTree(x, leftChild(root));
        }
        else
        {
            return eraseFromSubTree(x, rightChild(root));
        }
    }

    virtual bool intersection(const IntSet& s) const
    {
        return intersection(root, s);
    }

    virtual bool subset(const IntSet& s) const
    {
        return subset(root, s);
    }

    void print() const
    {
        cout << "*****\n";
        if(root == -1)
            cout << "empty " << endl;
        else
            prettyPrint(root);
        cout << "*****\n";
    }

private:
    // ������� � ����������� ���� ������ data �� �������
    // �����: ����� ���� �� ��������� � ��� ��������������
    // �������� �� ������ (�� ����� i, data[3*i] � ����������
    // �� ����, data[3*i+1] � ����� (� �� ������ � ������)
    // �� ������ �� ������ �������� ��� -1, ��� ���� ����
    // ��������, data[3*i+2] - ���������� �� ������� ��������
    DynArray data;

    // ����� �� ������ �� ������� ��� -1, ��� ������� � ������
    int root;

    // �������� �� �������� �� �������� x �
    // ���������� � ����� root
    // ��� ����� ������� �� ���������� � �������, �����
    // ������ �� "������������" �� �������, �.�. ����,
    // ����� ��������� �� ����� �� ���� x
    int findParent(int x, int root) const
    {
        if(root == -1)
            return -1;

        if(x <= getValue(root))
        { 
            // ��������� x �� � � �������, �� �� ����� ��
            // ���� ��� ��������� �� root
            if(leftChild(root) == -1)
                return root;
            // ��������� � ���� ��������� �� root
            if(getValue(leftChild(root)) == x)
                return root;
            // ���������� ��������� ������
            return findParent(x, leftChild(root));
        }

        // ��������� x �� � � �������, �� �� ����� ��
        // ���� ����� ��������� �� root
        if(rightChild(root) == -1)
            return root;
        // ��������� � ���� ��������� �� root
        if(getValue(rightChild(root)) == x)
            return root;
        // ���������� ��������� �������
        return findParent(x, rightChild(root));
    }

    bool intersection(int treeRoot, const IntSet &t) const
    {
        if(treeRoot == -1)
            return false;
        return t.element(getValue(treeRoot)) ||
               intersection(leftChild(treeRoot),t) ||
               intersection(rightChild(treeRoot), t);
    }

    bool subset(int treeRoot, const IntSet &t) const
    {
        if(treeRoot == -1)
            return true;
        return t.element(getValue(treeRoot)) &&
               subset(leftChild(treeRoot), t) &&
               subset(rightChild(treeRoot), t);
    }

    void prettyPrint(int treeRoot, int level = 0) const
    {
        if(treeRoot == -1)
            return;
        prettyPrint(leftChild(treeRoot), level+1);
        cout << setw(level*3) << getValue(treeRoot) << endl;
        prettyPrint(rightChild(treeRoot), level+1);
    }

    // �������� �� ���������� �� ����� � ����� root
    // ��� root == -1 ���������� � �����������
    int getValue(int root) const
    {
        return data[3*root];
    }

    // �������� �� ����� ���������
    ArrIndexProxy leftChild(int root) const
    {
        return data[3*root+1];
    }

    // �������� �� ������ ���������
    ArrIndexProxy rightChild(int root) const
    {
        return data[3*root+2];
    }

    // ��������� �� ������� �� ������� ������
    bool createNodeAt(int value, int index)
    {
        return data.addElementAt(value, index) &&
               data.addElementAt(-1, index+1)  &&
               data.addElementAt(-1, index+2);
    }

    // �������� �� ���-������ ������� � ������� � ����� root
    int leftMost(int root)
    {
        if(root == -1)
            return -1;
        if(leftChild(root) == -1)
            return root;
        return leftMost(leftChild(root));
    }

    // ��������� �� ���� � ����� �����
    bool freeNode(int node)
    {
        return data.removeElementAt(node*3) &&
               data.removeElementAt(node*3+1) &&
               data.removeElementAt(node*3+2);
    }

    // ��������� �� ������� �� ����� ��������
    bool eraseFromSubTree(int x, ArrIndexProxy treeRoot)
    {
        if(treeRoot == -1)
            return false;
        // ��������� �� ������
        if(x == getValue(treeRoot))
        {
            treeRoot = eraseRoot(treeRoot);
            return true;
        }
        int parent = findParent(x, treeRoot);

        // node � ��������� �� ������, �����
        // ������� ������ �� ����� ��� �������� x
        ArrIndexProxy node = (x <= getValue(parent) ? leftChild(parent) : rightChild(parent));

        // ������ �� ��������� ��� ��� ����������
        if(leftChild(node) != -1 && rightChild(node) != -1)
        {
            // �������� �� ���������� �� ����� ��� ����������
            // �� ���-������ ������� � ������ �� ��������
            data[node*3] = getValue(leftMost(rightChild(node)));
            return eraseFromSubTree(getValue(node),
                rightChild(node));
        }

        int tmp = node;
        // ������ ��� ���� ����� ���������
        if(leftChild(node) == -1)
        {
            // ���������� ����������� ������� ��������
            // �� ������, ����� � ���� �� �������������
            // �� ����� parent � ������� ������ ��
            // �����/������ �� ���������
            node = rightChild(node);
        } 
        else
        {
            node = leftChild(node);
        }
        return freeNode(tmp);
    }

    // ��������� �� ������ �� ������ �������� ����� ������ �� ����� �� �����
    int eraseRoot(int treeRoot)
    {
        int tmp = treeRoot;
        if(leftChild(treeRoot) == -1)
        {
            treeRoot = rightChild(treeRoot);
            freeNode(tmp);
            return treeRoot;
        }

        if(rightChild(treeRoot) == -1)
        {
            treeRoot = leftChild(treeRoot);
            freeNode(tmp);
            return treeRoot;
        }

        // ������� ��� ��� ����������
        tmp = leftMost(rightChild(treeRoot));

        // ����������� �� ���������� ��
        // ���-������ ������� � ������� ��������
        // ����� ���������� �� ������
        data[treeRoot*3] = getValue(tmp);
        // ��������� �� ���-������ ������� � ������� ��������
        eraseFromSubTree(getValue(tmp), rightChild(treeRoot));
        return treeRoot;
    }
};

bool containsRange(IntSet* set, int start, int end)
{
    for(int i = start; i <= end; i++)
        if(!set->element(i))
            return false;
    return true;
}

int main()
{
    DynArray da;
    IntBinOrdTree tree;
    int i = 0, count = 0;
    cout << "�������� �������� �� ������, -1 �� ����.";
    cin >> i;
    while(i != -1)
    {
        da.addElementAt(i, count);
        tree.addElement(i);
        cin >> i;
        count++;
    }

    cout << containsRange((IntSet*)&da, 1, 5) << endl
         << containsRange((IntSet*)&tree, 1, 5);
    return 0;
}
