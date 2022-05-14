#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol2265;
using namespace std;

/*takeaways
  - visit the subtree
    - count the number of all child nodes
    - add up the value of all child nodes
    - find the average
*/

void Solution::visit(Node *root, int &count, int &sum, int &total)
{
  if (root == nullptr)
    return;
  /* leave */
  if (root->left == nullptr && root->right == nullptr)
  {
    count++, sum += root->val, total++;
    return;
  }
  int nodeCount = 1, nodeSum = root->val;
  visit(root->left, nodeCount, nodeSum, total);
  visit(root->right, nodeCount, nodeSum, total);

  /* node value equals to average of substree */
  if ((nodeSum / nodeCount) == root->val)
    total++;
}

int Solution::countNodes(Node *root)
{
  auto nodeCount = 0, nodeSum = 0, total = 0;
  visit(root, nodeCount, nodeSum, total);

  return total;
}
