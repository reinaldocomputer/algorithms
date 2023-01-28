#include <iostream>
#include <queue>
#include <vector>

using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

// void swapTree(TreeNode* a, TreeNode* b){
//     TreeNode *c = new TreeNode;
//     c->val = a->val;
//     c->left = a->left;
//     c->right = a->right;

//     a->val=b->val;
//     a->left=b->left;
//     a->right=b->right;

//     b->val=c->val;
//     b->left=c->left;
//     b->right=c->right;
// }
    class Solution {
    public:
        TreeNode* reverseOddLevels(TreeNode* root) {
            queue< pair<int, TreeNode*> > q;
            vector< vector<TreeNode*> > v(20,vector<TreeNode*>());
            vector< vector<int> > v_aux(20,vector<int>());
            q.push(make_pair(0, root));
            v[0].push_back(root);
            v_aux[0].push_back(root->val);

            
            while(not q.empty()){
                TreeNode *current = q.front().second;
                int level = q.front().first;
                q.pop();

                if(current->left != NULL){
                    q.push(make_pair(level+1, current->left));
                    v[level+1].push_back(current->left);
                    v_aux[level+1].push_back(current->left->val);
                }
                if(current->right != NULL){
                    q.push(make_pair(level+1, current->right));
                    v[level+1].push_back(current->right);
                    v_aux[level+1].push_back(current->right->val);
                }
            }
            //[7,13,11]
            //[7][13,11]
            for(int i=0;i<v.size();i++){ // i=1
                if(i%2!=0){
                    // get reversed
                    for(int j=v[i].size()-1;j>=0;j--){ //{11,13}
                        if( (j+1) % 2 == 0 ){ // {1+1,0+1}
                            //right
                            // j = 1
                            v[i-1][(v[i].size())-(j+1)]->left->val = v_aux[i][j]; // v[0][0] = v[1][1]
                        } else { //0
                            // left
                            v[i-1][(v[i].size())-(j+2)]->right->val = v_aux[i][j]; // v[0][0] = v[1][0]
                        }
                    }
                }
            }
            return root;
        }
};