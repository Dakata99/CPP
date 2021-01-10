#include "BST.h"
#define COUNT 5

template<class T>
BST<T>::Node::Node(Node *l, const T& val, Node *r):left(l), value(val), right(r){}

template<class T>
typename BST<T>::Node * BST<T>::copy(Node *r1, Node *r2)
{
    if(r2 == nullptr) return nullptr;

    r1 = new Node(nullptr, r2->value, nullptr);
    r1->left = copy(r1->left, r2->left);
    r1->right = copy(r1->right, r2->right);

    return r1;
}

template<class T>
void BST<T>::copy(const BST<T>& other) { root = copy(root, other.root); }

template<class T>
bool BST<T>::search_element(Node *root, const T& element) const
{
    if(root == nullptr) return false;
    else if(root->value == element) return true;

    return root->value > element ? search_element(root->left, element) : search_element(root->right, element);
}

template<class T>
bool BST<T>::search_rec(const T& element)const { return search_element(root, element); }

template<class T>
bool BST<T>::search_iter(const T& element) const
{
    if(root == nullptr) return false;

    Node *curr = root;
    while (curr != nullptr)
    {
        if(curr->value == element) return true;
        else if(curr->value > element) curr = curr->left;
        else if(curr->value < element) curr = curr->right;
    }

    return false;
}

template<class T>
typename BST<T>::Node * BST<T>::in_pre(Node *root) 
{
    while (root && root->right != nullptr) root = root->right;

    return root;
}

template<class T>
typename BST<T>::Node * BST<T>::in_succ(Node *root) 
{
    while (root && root->left != nullptr) root = root->left;

    return root;
}

template<class T>
typename BST<T>::Node * BST<T>::find_min(Node* root)
{
	Node* current = root;
	while (current != nullptr && current->left != nullptr) current = current->left;
 
    return current;
}

template<class T>
typename BST<T>::Node * BST<T>::remove_rec(Node *root, const T& element)
{
    if(root == nullptr) return root;

    if(root->value > element) root->left = remove_rec(root->left, element);
    else if(root->value < element) root->right = remove_rec(root->right, element);
    else
    {
        if(root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = find_min(root->right);
        root->value = temp->value;
        root->right = remove_rec(root->right, temp->value);
    }
    return root;
}

template<class T>
void BST<T>::remove(const T& element) { if(!search_element(root, element)) return; root = remove_rec(root, element); }

template<class T>
void BST<T>::print(Node *root, int tabs)const
{
    if(root == nullptr) return;

    tabs += COUNT;

    print(root->right, tabs);
    
    for(int i = COUNT; i < tabs; i++) std::cout << ' ';
    std::cout << root->value << std::endl;

    print(root->left, tabs);
}

template<class T>
void BST<T>::print2D()const
{
    if(root == nullptr) return;

    std::cout << "------------------- 2D Tree -------------------\n";
    print(root, 0);
    std::cout << "-----------------------------------------------\n";
}

template<class T>
void BST<T>::dealloc(Node *root)
{
    if(root == nullptr) return;

    dealloc(root->left);
    dealloc(root->right);
    delete root;
}

template<class T>
BST<T>::BST():root(nullptr) {}

template<class T>
BST<T>::BST(const BST& other) { copy(other); }

template<class T>
BST<T>::~BST() { dealloc(root); }

template<class T>
BST<T>& BST<T>::operator=(const BST& other)
{
    if(this != &other)
    {
        dealloc(*this);
        copy(other);
    }
    return *this;
}

template <class T>
Position<T> BST<T>::root_position() { return Position<T>(root); }

template<class T>
void BST<T>::create_rec(Node *&root, std::vector<T> vec, int start, int end)
{
    if(start > end) { root = nullptr; return; }

    size_t mid = (start + end) / 2;
    root = new Node(nullptr, vec[mid], nullptr);

    create_rec(root->left, vec, start, mid - 1);
    create_rec(root->right, vec, mid + 1, end);
}

template<class T>
void BST<T>::create(std::vector<T> vec) { create_rec(root, vec, 0, vec.size() - 1); }

template<class T>
typename BST<T>::Node * BST<T>::insert_rec(Node *root, const T& element)
{
    if(root == nullptr) { return (new Node(nullptr, element, nullptr)); }
    else if(root->value > element) root->left = insert_rec(root->left, element);
    else if(root->value < element) root->right = insert_rec(root->right, element);
    
    return root;
}

template<class T>
void BST<T>::insert_rec(const T& element) { if(!search_element(root, element)) root = insert_rec(root, element); }

template<class T>
void BST<T>::insert_iter(const T& element)
{ 
    Node *curr = root;
    Node *p;
    Node *r;
 
    if (root == nullptr) { root = new Node(nullptr, element, nullptr); return; }
 
    while(curr != nullptr)
    {
        r = curr;
        if (element < curr->value) curr = curr->left;
        else if (element > curr->value) curr = curr->right;
        else return;
    }
 
    p = new Node(nullptr, element, nullptr);
 
    if (element < r->value) r->left = p;
    else r->right = p;
}

template<class T>
void BST<T>::print_pre_order(const Node *root)const
{
    if(root == nullptr) return;

    std::cout << root->value << ' ';
    print_pre_order(root->left);
    print_pre_order(root->right);
}

template<class T>
void BST<T>::print_in_order(const Node *root)const
{
    if(root == nullptr) return;

    print_in_order(root->left);
    std::cout << root->value << ' ';
    print_in_order(root->right);
}

template<class T>
void BST<T>::print_post_order(const Node *root)const
{
    if(root == nullptr) return;

    print_post_order(root->left);
    print_post_order(root->right);
    std::cout << root->value << ' ';
}

template<class T>
void BST<T>::pre_order()const 
{ 
    std::cout << "Pre order traversal: ";
    print_pre_order(root); 
    std::cout << std::endl; 
}

template<class T>
void BST<T>::in_order()const 
{ 
    std::cout << "In order traversal: ";
    print_in_order(root); 
    std::cout << std::endl; 
}

template<class T>
void BST<T>::post_order()const 
{ 
    std::cout << "Post order traversal: ";
    print_post_order(root); 
    std::cout << std::endl; 
}

template<class T>
int BST<T>::calc_height(const Node *root) const
{
    if(root == nullptr) return -1;

    return 1 + std::max(calc_height(root->left), calc_height(root->right));
}

template<class T>
int BST<T>::height()const { return calc_height(root); }

template<class T>
void BST<T>::print_v2(Node *root, int tabs)const
{
    if(root == nullptr) return;

    tabs += COUNT;

    std::cout << std::endl;
    for(int i = COUNT; i < tabs; i++) std::cout << ' ';
    std::cout << root->value << std::endl;

    print_v2(root->left, tabs);
    print_v2(root->right, tabs);
}

template<class T>
void BST<T>::print2D_v2()const
{
    if(root == nullptr) return;

    std::cout << "------------------- 2D Tree -------------------\n";
    print_v2(root, 0);
    std::cout << "-----------------------------------------------\n";
}
