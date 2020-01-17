// Arvinbayar Jamsranjav
// Project 3
// CS 251
// 2019

/*avl.h*/

#pragma once

#include <iostream>
#include <algorithm>  // std::max
#include <cstdlib>    // std::abs
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

template<typename TKey, typename TValue>
class avltree
{
private:
  struct NODE
  {
    TKey   Key;
    TValue Value;
    int    Height;
    NODE*  Left;
    NODE*  Right;
  };
  
  NODE* Root;  // pointer to root node of tree (nullptr if empty)
  int   Size;  // # of nodes in the tree (0 if empty)

  //
  // _inorder does the actual inorder traversal and output
  // to console.  Each key is output to the console followed
  // by " ", including the last key.
  //
  void _inorder(NODE* cur)
  {
    if (cur == NULL)
      return;
    else
    {
      _inorder(cur->Left);
      cout << "(" << cur->Key << "," << cur->Value << "," << cur->Height << ")" << " ";
      _inorder(cur->Right);
    }
  }

  void _inorder_keys(NODE* cur, std::vector<TKey>& V)
  {
    if (cur == NULL)
      return;
    else
    {
      _inorder_keys(cur->Left, V);
      V.push_back(cur->Key);
      _inorder_keys(cur->Right, V);
    }
  }

  void _inorder_values(NODE* cur, std::vector<TValue>& V)
  {
    if (cur == NULL)
      return;
    else
    {
      _inorder_values(cur->Left, V);
      V.push_back(cur->Value);
      _inorder_values(cur->Right, V);
    }
  }

  void _inorder_heights(NODE* cur, std::vector<int>& V)
  {
    if (cur == NULL)
      return;
    else
    {
      _inorder_heights(cur->Left, V);
      V.push_back(cur->Height);
      _inorder_heights(cur->Right, V);
    }
  }
    
  //
  // _copytree:
  //
  // Given a tree, inserts the (key, value) pairs into *this* tree.
  //
  void _copytree(NODE* cur)
  {
    if (cur == NULL)
      return;
    else
    {
      //
      // to copy and build an exact copy, we need to "visit" cur
      // first and insert that (key, value) pair first.  That way
      // all the nodes to the left will properly go to the left,
      // all the node to the right will properly go to the right.
      //
      insert(cur->Key, cur->Value);
      _copytree(cur->Left);
      _copytree(cur->Right);
    }
  }

  //
  // _RightRotate
  // _LeftRotate
  //
  // Rotates the tree around the node N, where Parent is N's parent.  Note that
  // Parent could be null, which means N is the root of the entire tree.  If
  // Parent denotes a node, note that N could be to the left of Parent, or to
  // the right.  You'll need to take all this into account when linking in the
  // new root after the rotation.  Don't forget to update the heights as well.
  //
  void _RightRotate(NODE* Parent, NODE* N)
  {
    assert(N != NULL);  // pre-conditions: N and L must exist
    assert(N->Left != NULL);

    NODE *L= N->Left;
    NODE *B = L->Right;
    
    N->Left= B;
    L->Right = N;
    
    if(Parent == NULL) {
       Root = L;
    }
    else if ( L->Key < Parent->Key) {
       Parent->Left = L;
    }
    else {
       Parent->Right = L;
    }
    
    if( (N->Left == NULL) && (N->Right == NULL)) {
       N->Height = 0;
    }
    else if (N->Left == NULL) {
       N->Height = 1 + N->Right->Height;
    }
    else if (N->Right == NULL) {
       N->Height = 1 + N->Left->Height;
    }
    else {
       N->Height = 1 + max(N->Left->Height, N->Right->Height);
    }
    
    if(L->Left == NULL) {
       L->Height = 1 + L->Right->Height;
    }
    else {
       L->Height = 1 + max (L->Left->Height, L->Right->Height);
    }
  }

  void _LeftRotate(NODE* Parent, NODE* N)
  {
    assert(N != nullptr);  // pre-conditions: N and R must exist
    assert(N->Right != nullptr);
    
    NODE *L = N->Right;
    NODE *A = L->Left;
    
    N->Right = A;
    L->Left = N;
    
    if(Parent==NULL) {
       Root = L;
    }
    else if (L->Key < Parent->Key) {
       Parent->Left = L;
    }
    else {
       Parent->Right = L;
    }
    
     if( (N->Left == NULL) && (N->Right == NULL)) {
       N->Height = 0;
    }
    else if (N->Left == NULL) {
       N->Height = 1 + N->Right->Height;
    }
    else if (N->Right == NULL) {
       N->Height = 1 + N->Left->Height;
    }
    else {
        N->Height = 1 + max(N->Left->Height, N->Right->Height);
    }
    
    if(L->Right == NULL) {
       L->Height = 1 + L->Left->Height;
    }
    else {
       L->Height = 1 + max (L->Left->Height, L->Right->Height);
    }
  }
  
  // destructor: frees memory, erases the root
  void _destructor(NODE* cur) {
    if(cur == NULL) {
          return;
    }
    _destructor(cur->Left);
    _destructor(cur->Right);
    delete cur;

  }
  
  // distance helper 1
  int _distance(NODE* Root, TKey x, TKey y) {
    // Check if the root is empty or not
    if(Root == NULL) {
      return -1;
    }
    // Check if 2 keys are located in left side of tree
    if (Root->Key > x && Root->Key > y) {
      return _distance(Root->Left, x, y);
    }
    // Check if 2 keys are located in right side of tree
    else if (Root->Key < x && Root->Key < y) {
      return _distance(Root->Right, x, y);
    }
    // If previous 2 cases false then 2 keys located
    // in diffent sides, so count each one from the root and add
    else {
      return (_distanceFromRoot(Root,x) + _distanceFromRoot(Root,y));
    }      
  }
  
  // distance helper 2: calculates from Node to looking value
  int _distanceFromRoot(NODE* Root, TKey lookingValue) {
    int distance = -1;  // initialaze variable distance
    
    // If root is empty
    if(Root == NULL) {
        return -1;
    }
    
    // recursively add distance checking root, left and right
    if((Root->Key == lookingValue) ||
        (distance = _distanceFromRoot(Root->Left,lookingValue)) >= 0 || 
        (distance = _distanceFromRoot(Root->Right,lookingValue)) >= 0) {
        return distance + 1;
    }
    return distance;
  }
    
       
public:
  //
  // default constructor:
  //
  // Creates an empty tree.
  //
  avltree()
  {
    Root = NULL;
    Size = 0;
  }

  //
  // copy constructor:
  //
  avltree(avltree& other)
  {
    Root = NULL;
    Size = 0;

    _copytree(other.Root);
  }
  
  //
  // destructor
  //
  virtual ~avltree(){
      _destructor(Root);
  }

  //
  // size:
  //
  // Returns the # of nodes in the tree, 0 if empty.
  //
  int size()
  {
    return Size;
  }

  //
  // height
  //
  // Returns the height of tree; the height of an empty tree is
  // defined as -1.
  //
  int height()
  {
    if (Root == NULL)
      return -1;
    else
      return Root->Height;
  }
  
  // clear function: frees memory, reset variables
  void clear() {
    _destructor(Root);
    Root = NULL;
    Size = 0;
  }
  
  //
  // search:
  //
  // Searches the tree for the given key, returning a pointer to the
  // value if found and nullptr if not.  We return a pointer so the caller
  // may update the underlying value if needed.
  //
  TValue* search(TKey key)
  {
    NODE* cur = Root;
    while (cur != NULL)
    {
      if (key == cur->Key)  // already in tree
      {
        return &cur->Value;
      }

      if (key < cur->Key)  // search left:
      {
        cur = cur->Left;
      }
      else
      {
        cur = cur->Right;
      }
    }//while

    // if get here, not found
    return NULL;
  }
  
  
  // function that fixes the tree
  void _RotateToFix(NODE* Parent, NODE* N) {
      assert(N != NULL);
      // variables for subtrees
      int hLL, hLR, hRL, hRR;
      // height left and right
      int hL = (N->Left == nullptr) ? -1 : N->Left->Height;
      int hR = (N->Right == nullptr) ? -1 : N->Right->Height;
      // check if they are broken
      assert(abs(hL-hR)>1);
      // find height of subtrees
      if(N->Left != NULL){
          hLL = (N->Left->Left == nullptr) ? -1 : N->Left->Left->Height;
          hLR = (N->Left->Right == nullptr) ? -1 : N->Left->Right->Height;
      }
      if(N->Right != NULL) {
          hRL = (N->Right->Left == nullptr) ? -1 : N->Right->Left->Height;
          hRR = (N->Right->Right == nullptr) ? -1 : N->Right->Right->Height;
      }
      // case 1 and 2 leaned to the left
      if(hL > hR) {
          assert(N->Left != nullptr);
          if(hLL > hLR) {
              _RightRotate(Parent, N);
          }
          else {
              _LeftRotate(N, N->Left);
              _RightRotate(Parent, N);
          }
      }
      // case 3 and 4 leaned to the right
      else {
          assert(N->Right != nullptr);
          if(hRL < hRR) {
              _LeftRotate(Parent, N);
          }
          else {
              _RightRotate(N, N->Right);
              _LeftRotate(Parent, N);
          } 
      }
  }

  //
  // insert
  //
  // Inserts the given (key, value) pair into the tree; if the key has
  // already been inserted then the function returns without changing
  // the tree.
  //
  void insert(TKey key, TValue value)
  {
    NODE* prev = NULL;
    NODE* cur = Root;
    
    //
    // stack the nodes we visit so we can walk back up
    // the search path later, adjusting heights:
    //
    stack<NODE*> nodes;

    //
    // 1. Search to see if tree already contains key:
    //
    while (cur != NULL)
    {
      if (key == cur->Key)  // already in tree
        return;

      nodes.push(cur);  // stack so we can return later:

      if (key < cur->Key)  // search left:
      {
        prev = cur;
        cur = cur->Left;
      }
      else
      {
        prev = cur;
        cur = cur->Right;
      }
    }//while

    //
    // 2. if we get here, key is not in tree, so allocate
    // a new node to insert:
    //
    NODE* newNode;
    newNode = new NODE();
    newNode->Key = key;
    newNode->Value = value;
    newNode->Height = 0;  // leaf node -> sub-tree of height 0:
    newNode->Left = NULL;
    newNode->Right = NULL;

    //
    // 3. link in the new node:
    //
    // NOTE: cur is null, and prev denotes node where
    // we fell out of the tree.  if prev is null, then
    // the tree is empty and the Root pointer needs
    // to be updated.
    //
    if (prev == NULL)
      Root = newNode;
    else if (key < prev->Key)
      prev->Left = newNode;
    else
      prev->Right = newNode;

    //
    // 4. update size:
    //
    Size++;

    //
    // 5. walk back up tree using stack and update heights.
    //
    while (!nodes.empty())
    {
      cur = nodes.top();
      nodes.pop();

      int hL = (cur->Left == nullptr) ? -1 : cur->Left->Height;
      int hR = (cur->Right == nullptr) ? -1 : cur->Right->Height;
      int hCur = 1 + max(hL, hR);
          
      if (cur->Height == hCur) {// didn't change, so no need to go further:
        break;
      }
      // checks if it is broken
      else if (abs(hL - hR) > 1) {
          if(nodes.empty()) {
              prev = NULL;
          }
          else{
              prev = nodes.top();
          }
          _RotateToFix(prev, cur);
          break;
      }
      else  // height changed, update and keep going:
        cur->Height = hCur;
    }//while
    return;
  }
  
  // distance function call
  // find the distance between 2 keys
  int distance(TKey k1, TKey k2) { 
    if(search(k1) == NULL || search(k2) == NULL) {
        return -1;
    }
    if( (k1 == k2) && (search(k1) != NULL && search(k2) != NULL)) {
        return 0;
    }
    return (_distance(Root, k1, k2));
  }

  //
  // inorder:
  //
  // Performs an inorder traversal of the tree, outputting
  // the keys to the console.
  //
  void inorder()
  {
    cout << "Inorder: ";

    _inorder(Root);

    cout << endl;
  }

  vector<TKey> inorder_keys()
  {
    vector<TKey>  V;

    _inorder_keys(Root, V);

    return V;
  }

  vector<TValue> inorder_values()
  {
    vector<TValue>  V;

    _inorder_values(Root, V);

    return V;
  }

  vector<int> inorder_heights()
  {
    vector<int>  V;

    _inorder_heights(Root, V);

    return V;
  }
};

