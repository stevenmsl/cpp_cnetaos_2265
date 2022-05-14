#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol2265;

/*
Input: root = [4,8,5,0,1,null,6]
Output: 5
Explanation:
For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 =
24 / 6 = 4.
For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
For the node with value 0: The average of its subtree is 0 / 1 = 0.
For the node with value 1: The average of its subtree is 1 / 1 = 1.
For the node with value 6: The average of its subtree is 6 / 1 = 6.
*/

tuple<Node *, int>
testFixture1()
{
  auto root = new Node(4);
  root->left = new Node(8);
  root->left->left = new Node(0);
  root->left->right = new Node(1);

  root->right = new Node(5);
  root->right->right = new Node(6);

  return make_tuple(root, 5);
}

/*
Input: root = [1]
Output: 1
Explanation: For the node with value 1: The average of its subtree is 1 / 1 = 1.
*/

tuple<Node *, int>
testFixture2()
{
  auto root = new Node(1);
  return make_tuple(root, 1);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;
  auto path = sol.countNodes(get<0>(f));
  cout << "Expect to see :" << get<1>(f) << endl;
  cout << path << endl;
}

void test2()
{
  auto f = testFixture2();
  Solution sol;
  auto path = sol.countNodes(get<0>(f));
  cout << "Expect to see :" << get<1>(f) << endl;
  cout << path << endl;
}

main()
{
  test1();
  test2();
  return 0;
}