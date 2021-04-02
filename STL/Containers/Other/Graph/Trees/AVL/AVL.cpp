#include "AVL.h"
#define COUNT 5

#if 1 /* primary stuff */
template<class T>
AVL<T>::Node::Node(Node *_left, const T& val, Node *_right):left(_left), value(val), right(_right){}

template<class T>
void AVL<T>::copy_rec(Node*& root, const Node* other_root)
{
    if(other_root == nullptr) return;

    root = new Node(nullptr, other_root->value, nullptr);
    copy_rec(root->left, other_root->left);
    copy_rec(root->right, other_root->right);
}

template<class T>
void AVL<T>::dealloc(Node *root)
{
    if(root == nullptr) return;

    dealloc(root->left);
    dealloc(root->right);
    delete root;
}

#endif 

#if 1 /* printing functions */

template<class T>
void AVL<T>::print(Node *root, int tabs)const
{
    if(root == nullptr) return;

    tabs += COUNT;

    print(root->right, tabs);
    
    for(int i = COUNT; i < tabs; i++) std::cout << ' ';
    std::cout << root->value << std::endl;

    print(root->left, tabs);
}

template<class T>
void AVL<T>::print2D()const
{
    if(root == nullptr) return;

    std::cout << "------------------- 2D Tree -------------------\n";
    print(root, 0);
    std::cout << "-----------------------------------------------\n";
}

template<class T>
void AVL<T>::print_v2(Node *root, int tabs)const
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
void AVL<T>::print2D_v2()const
{
    if(root == nullptr) return;

    std::cout << "------------------- 2D Tree -------------------\n";
    print_v2(root, 0);
    std::cout << "-----------------------------------------------\n";
}

template<class T>
void AVL<T>::print_pre_order(const Node *root)const
{
    if(root == nullptr) return;

    std::cout << root->value << ' ';
    print_pre_order(root->left);
    print_pre_order(root->right);
}

template<class T>
void AVL<T>::pre_order()const 
{ std::cout << "Pre order traversal: "; print_pre_order(root); std::cout << std::endl; }

template<class T>
void AVL<T>::print_in_order(const Node *root)const
{
    if(root == nullptr) return;

    print_in_order(root->left);
    std::cout << root->value << ' ';
    print_in_order(root->right);
}

template<class T>
void AVL<T>::in_order()const 
{ std::cout << "In order traversal: "; print_in_order(root); std::cout << std::endl; }

template<class T>
void AVL<T>::print_post_order(const Node *root)const
{
    if(root == nullptr) return;

    print_post_order(root->left);
    print_post_order(root->right);
    std::cout << root->value << ' ';
}

template<class T>
void AVL<T>::post_order() const 
{ std::cout << "Post order traversal: "; print_post_order(root); std::cout << std::endl; }

#endif

#if 1 /* BIG 4*/

template<class T>
AVL<T>::AVL():root(nullptr) {}

template<class T>
AVL<T>::AVL(const AVL& other) { copy_rec(root, other.root); }

template<class T>
AVL<T>::~AVL() { dealloc(root); }

template<class T>
AVL<T>& AVL<T>::operator=(const AVL& other)
{
    if(this != &other)
    {
        dealloc(*this);
        copy(other);
    }
    return *this;
}

#endif

template <class T>
Position<T> AVL<T>::root_position() { return Position<T>(root); }

#if 1 /* create a tree from a vector */

template<class T>
void AVL<T>::create_rec(Node *&root, const std::vector<T>& vec, size_t start, size_t end)
{
    if(start > end) { root = nullptr; return; }

    size_t mid = (start + end) / 2;
    root = new Node(nullptr, vec[mid], nullptr);

    create_rec(root->left, vec, start, mid - 1);
    create_rec(root->right, vec, mid + 1, end);
}

template<class T>
void AVL<T>::create(const std::vector<T>& vec) { create_rec(root, vec, 0, vec.size() - 1); }

#endif

#if 1 /* search an element in a tree */

template<class T>
bool AVL<T>::search_element(Node *root, const T& element) const
{
    if(root == nullptr) return false;
    else if(root->value == element) return true;

    return root->value > element ? search_element(root->left, element) : search_element(root->right, element);
}

template<class T>
bool AVL<T>::search_rec(const T& element)const { return search_element(root, element); }

template<class T>
bool AVL<T>::search_iter(const T& element) const
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

#endif

#if 1 /* remove a node */

template<class T>
typename AVL<T>::Node* AVL<T>::remove_rec(Node *root, const T& element)
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
void AVL<T>::remove(const T& element) 
{ if(!search_element(root, element)) return; root = remove_rec(root, element); }

#endif


#if 1 /* rotation functions */

template<class T>
typename AVL<T>::Node * AVL<T>::LL_rotation(Node *root)
{
    Node *pl = root->left;
    Node *plr = pl->right;

    pl->right = root;
    root->left = plr;
    root->height = calc_height(root);
    pl->height = calc_height(pl);

    return pl;
}

template<class T>
typename AVL<T>::Node * AVL<T>::RR_rotation(Node *root)
{
    Node *pr = root->right;
    Node *prl = pr->left;

    pr->left = root;
    root->right = prl;
    root->height = calc_height(root);
    pr->height = calc_height(pr);

    return pr;
}

template<class T>
typename AVL<T>::Node * AVL<T>::LR_rotation(Node *root)
{
    Node *cl = root->left;
    Node *clr = cl->right;

    cl->right = clr->left;
    root->left = clr->right;

    clr->left = cl;
    clr->right = root;

    cl->height = calc_height(cl);
    root->height = calc_height(root);
    clr->height = calc_height(clr); 
    
    return clr;
}

template<class T>
typename AVL<T>::Node * AVL<T>::RL_rotation(Node *root)
{
    Node *cr = root->right;
    Node *crl = cr->left;

    cr->left = crl->right;
    root->right = crl->left;

    crl->left = root;
    crl->right = cr;

    cr->height = calc_height(cr);
    root->height = calc_height(root);
    crl->height = calc_height(crl);

    return crl;
}

#endif

#if 1 /* insert a node and balance the tree */

template<class T>
typename AVL<T>::Node * AVL<T>::insert_rec(Node *root, const T& element)
{
    if(root == nullptr)
    {
        root = new Node(nullptr, element, nullptr);
        return root;
    }
    if(root->value > element) root->left = insert_rec(root->left, element);
    else if(root->value < element) root->right = insert_rec(root->right, element);

    root->height = calc_height(root);

    if(balance_factor(root) == 2 && balance_factor(root->left) == 1) return LL_rotation(root);
    else if(balance_factor(root) == 2 && balance_factor(root->left) == -1) return LR_rotation(root);
    else if(balance_factor(root) == -2 && balance_factor(root->right) == -1) return RR_rotation(root);
    else if(balance_factor(root) == -2 && balance_factor(root->right) == 1) return RL_rotation(root);

    return root;
}

template<class T>
void AVL<T>::insert_rec(const T& element) 
{ if(!search_element(root, element)) root = insert_rec(root, element); }

template<class T>
void AVL<T>::insert_iter(const T& element)
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

#endif

#if 1 /* additional functions */

template<class T>
int AVL<T>::calc_height(const Node *root) const
{
    if(root == nullptr) return -1;

    return 1 + std::max(calc_height(root->left), calc_height(root->right));
    //return root == nullptr ? -1 : 1 + std::max(calc_height(root->left), calc_height(root->right));
}

template<class T>
int AVL<T>::height()const { return calc_height(root); }

template<class T>
typename AVL<T>::Node* AVL<T>::find_min(Node* root)
{
	Node* current = root;
	while (current != nullptr && current->left != nullptr) current = current->left;
 
    return current;
}

template<class T>
int AVL<T>::balance_factor(Node *root)
{
    int lh = root != nullptr && root->left != nullptr ? root->left->height : -1;
    int rh = root != nullptr && root->right != nullptr ? root->right->height : -1;

    return lh - rh;
}

#endif
