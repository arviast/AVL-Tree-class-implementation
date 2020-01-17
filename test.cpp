/*test.cpp*/

//
// Lab week 07:
// 
// AVL unit tests based on Catch framework.  We are assuming the AVL class is now
// balancing the trees in these tests.
//

#include <iostream>
#include <vector>

#include "avl.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

TEST_CASE("(1) AVL tree with 4 nodes") 
{
  avltree<int, int>  avl;

  //
  // build a simple BST tree with 4 nodes:
  //
  avl.insert(100, -100);
  avl.insert(50, -50);
  avl.insert(150, -150);
  avl.insert(125, -125);

  // 
  // Tests:
  //
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

  REQUIRE(avl.size() == 4);
  REQUIRE(avl.height() == 2);

  REQUIRE(keys[0] == 50);
  REQUIRE(values[0] == -50);
  REQUIRE(heights[0] == 0);

  REQUIRE(keys[1] == 100);
  REQUIRE(values[1] == -100);
  REQUIRE(heights[1] == 2);

  REQUIRE(keys[2] == 125);
  REQUIRE(values[2] == -125);
  REQUIRE(heights[2] == 0);

  REQUIRE(keys[3] == 150);
  REQUIRE(values[3] == -150);
  REQUIRE(heights[3] == 1);
}

TEST_CASE("(2) empty tree") 
{
  avltree<int, int>  avl;

  REQUIRE(avl.size() == 0);
  REQUIRE(avl.height() == -1);
}

TEST_CASE("(3) just one node") 
{
  avltree<int, int>  avl;
	
	avl.insert(123, 88);

  REQUIRE(avl.size() == 1);
  REQUIRE(avl.height() == 0);
	
	vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

	REQUIRE(keys[0] == 123);
	REQUIRE(values[0] == 88);
  REQUIRE(heights[0] == 0);
}



TEST_CASE("(4) FIX LEFT")
{
  avltree<int, int>  avl;

  //
  // build a simple BST tree with 4 nodes:
  //
  avl.insert(50, -50);
  avl.insert(25, -25);
  avl.insert(75, -75);
  avl.insert(12, -12);
    avl.insert(30,-30);
    avl.insert(9,-9);

  // 
  // Tests:
  //
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();    
  
    REQUIRE(avl.size() == 6);
  REQUIRE(avl.height() == 2);

  REQUIRE(keys[4] == 50);
  REQUIRE(values[4] == -50);
  REQUIRE(heights[4] == 1);  
    
    REQUIRE(keys[2] == 25);
  REQUIRE(values[2] == -25);
  REQUIRE(heights[2] == 2);  
    
    REQUIRE(keys[5] == 75);
  REQUIRE(values[5] == -75);
  REQUIRE(heights[5] == 0);  
    
    REQUIRE(keys[1] == 12);
  REQUIRE(values[1] == -12);
  REQUIRE(heights[1] == 1);  
    
    REQUIRE(keys[3] == 30);
  REQUIRE(values[3] == -30);
  REQUIRE(heights[3] == 0);  
    
    REQUIRE(keys[0] == 9);
  REQUIRE(values[0] == -9);
  REQUIRE(heights[0] == 0);  
}




TEST_CASE("(5) FIX LEFT PART II")
{
  avltree<int, int>  avl;

  //
  // build a simple BST tree with 4 nodes:
  //
  avl.insert(50, -50);
  avl.insert(25, -25);
  avl.insert(75, -75);
  avl.insert(12, -12);
    avl.insert(30,-30);
    avl.insert(35,-35);

  // 
  // Tests:
  //
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();    
  
    REQUIRE(avl.size() == 6);
  REQUIRE(avl.height() == 2);

  REQUIRE(keys[4] == 50);
  REQUIRE(values[4] == -50);
  REQUIRE(heights[4] == 1);  
    
    REQUIRE(keys[1] == 25);
  REQUIRE(values[1] == -25);
  REQUIRE(heights[1] == 1);  
    
    REQUIRE(keys[5] == 75);
  REQUIRE(values[5] == -75);
  REQUIRE(heights[5] == 0);  
    
    REQUIRE(keys[0] == 12);
  REQUIRE(values[0] == -12);
  REQUIRE(heights[0] == 0);  
    
    REQUIRE(keys[2] == 30);
  REQUIRE(values[2] == -30);
  REQUIRE(heights[2] == 2);  
    
    REQUIRE(keys[3] == 35);
  REQUIRE(values[3] == -35);
  REQUIRE(heights[3] == 0);  
}


TEST_CASE("(6) FIX RIGHT")
{
  avltree<int, int>  avl;

  //
  // build a simple BST tree with 4 nodes:
  //
  avl.insert(50, -50);
  avl.insert(25, -25);
  avl.insert(75, -75);
  avl.insert(52, -52);
    avl.insert(78,-78);
    avl.insert(90,-90);

  // 
  // Tests:
  //
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();    
  
    REQUIRE(avl.size() == 6);
  REQUIRE(avl.height() == 2);

  REQUIRE(keys[1] == 50);
  REQUIRE(values[1] == -50);
  REQUIRE(heights[1] == 1);  
    
    REQUIRE(keys[0] == 25);
  REQUIRE(values[0] == -25);
  REQUIRE(heights[0] == 0);  
    
    REQUIRE(keys[3] == 75);
  REQUIRE(values[3] == -75);
  REQUIRE(heights[3] == 2);  
    
    REQUIRE(keys[2] == 52);
  REQUIRE(values[2] == -52);
  REQUIRE(heights[2] == 0);  
    
    REQUIRE(keys[4] == 78);
  REQUIRE(values[4] == -78);
  REQUIRE(heights[4] == 1);  
    
    REQUIRE(keys[5] == 90);
  REQUIRE(values[5] == -90);
  REQUIRE(heights[5] == 0);  
}


TEST_CASE("fix right part 2")
{
  avltree<int, int>  avl;

  //
  // build a simple BST tree with 4 nodes:
  //
  avl.insert(50, -50);
  avl.insert(25, -25);
  avl.insert(75, -75);
  avl.insert(52, -52);
    avl.insert(78,-78);
    avl.insert(51,-51);

  // 
  // Tests:
  //
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();    
  
    REQUIRE(avl.size() == 6);
  REQUIRE(avl.height() == 2);

  REQUIRE(keys[1] == 50);
  REQUIRE(values[1] == -50);
  REQUIRE(heights[1] == 1);  
    
    REQUIRE(keys[0] == 25);
  REQUIRE(values[0] == -25);
  REQUIRE(heights[0] == 0);  
    
    REQUIRE(keys[4] == 75);
  REQUIRE(values[4] == -75);
  REQUIRE(heights[4] == 1);  
    
    REQUIRE(keys[3] == 52);
  REQUIRE(values[3] == -52);
  REQUIRE(heights[3] == 2);  
    
    REQUIRE(keys[5] == 78);
  REQUIRE(values[5] == -78);
  REQUIRE(heights[5] == 0);  
    
    REQUIRE(keys[2] == 51);
  REQUIRE(values[2] == -51);
  REQUIRE(heights[2] == 0);  
}


TEST_CASE("(8) DOUBLe")
{
  avltree<int, int>  avl;

  //
  // build a simple BST tree with 4 nodes:
  //
  avl.insert(50, -50);
  avl.insert(25, -25);
  avl.insert(75, -75);
    avl.insert(20,-20);
    avl.insert(21,-21);
   

  // 
  // Tests:
  //
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights(); 

    
  REQUIRE(avl.size() == 5);
  REQUIRE(avl.height() == 2);
    
      REQUIRE(keys[0] == 20);
  REQUIRE(values[0] == -20);
  REQUIRE(heights[0] == 0);

  REQUIRE(keys[1] == 21);
  REQUIRE(values[1] == -21);
  REQUIRE(heights[1] == 1);

  REQUIRE(keys[2] == 25);
  REQUIRE(values[2] == -25);
  REQUIRE(heights[2] == 0);

  REQUIRE(keys[3] == 50);
  REQUIRE(values[3] == -50);
  REQUIRE(heights[3] == 2);
    
  
  REQUIRE(keys[4] == 75);
  REQUIRE(values[4] == -75);
  REQUIRE(heights[4] == 0);   
}


TEST_CASE("(9) DOUBLe 2")
{
  avltree<int, int>  avl;

  //
  // build a simple BST tree with 4 nodes:
  //
  avl.insert(50, -50);
  avl.insert(25, -25);
  avl.insert(75, -75);
    avl.insert(78,-78);
    avl.insert(77,-77);
   

  // 
  // Tests:
  //
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights(); 

    
  REQUIRE(avl.size() == 5);
  REQUIRE(avl.height() == 2);
    
      REQUIRE(keys[0] == 25);
  REQUIRE(values[0] == -25);
  REQUIRE(heights[0] == 0);

  REQUIRE(keys[1] == 50);
  REQUIRE(values[1] == -50);
  REQUIRE(heights[1] == 2);

  REQUIRE(keys[2] == 75);
  REQUIRE(values[2] == -75);
  REQUIRE(heights[2] == 0);

  REQUIRE(keys[3] == 77);
  REQUIRE(values[3] == -77);
  REQUIRE(heights[3] == 1);
    
  
  REQUIRE(keys[4] == 78);
  REQUIRE(values[4] == -78);
  REQUIRE(heights[4] == 0);   
}


TEST_CASE("(10) CLEAR")
{
    
    avltree<int, int>  avl;
    
    
    avl.insert(50,50);
    avl.insert(25,-25);
    
    avl.clear();
    
    vector<int> keys, values, heights;
    keys = avl.inorder_keys();
    values = avl.inorder_values();
    heights = avl.inorder_heights(); 
    
    REQUIRE(avl.size() == 0);
    REQUIRE(avl.height() == -1);
}

TEST_CASE("(11) DEST")
{
    avltree<int, int>  avl;
    
    
    avl.insert(25,1);
    avl.insert(15,2);
    avl.insert(75,3);
    avl.insert(55,4);
    avl.insert(100,5);
    avl.insert(110,6);
    

    
    vector<int> keys, values, heights;
    keys = avl.inorder_keys();
    values = avl.inorder_values();
    heights = avl.inorder_heights(); 
    
    REQUIRE(avl.distance(15,110) == 4);
    //REQUIRE(avl.distance(12,25) == 4);
    
    
}




