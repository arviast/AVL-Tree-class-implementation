//
// HW #08: AVL left and right rotate
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "avl.h"

using namespace std;


int main()
{
  avltree<int, int>  avl;

    avl.insert(46,1);
    avl.insert(29,2);
    avl.insert(76,3);
    avl.insert(17,4);
    avl.insert(31,5);
    avl.insert(50,15);
    avl.insert(100,6);
    avl.insert(12,7);
    avl.insert(20,8);
    avl.insert(40, 9);
    avl.insert(120,10);
    avl.insert(5,11);
    
    
    
    cout << "MUST be 6 ==" << avl.distance(5,100) << endl;
    cout << "MUST be 3 ==" << avl.distance(46,12) << endl;
    cout << "MUST be 3 ==" << avl.distance(31,12) << endl;
    cout << "MUST be 6 ==" << avl.distance(100,5) << endl;
    cout << "MUST be 0 ==" << avl.distance(100,100) << endl;
    cout << "MUST be -1 ==" << avl.distance(52,52) << endl;
    cout << "MUST be -1 ==" << avl.distance(100,199) << endl;
    cout << "MUST be 4 ==" << avl.distance(20,40) << endl;
    cout << "MUST be 1 ==" << avl.distance(100,120) << endl;
   
    
  cout << endl;
  cout << "Size: " << avl.size() << endl;
  cout << "Height: " << avl.height() << endl;
  avl.inorder();
  cout << endl;

  return 0;
}
