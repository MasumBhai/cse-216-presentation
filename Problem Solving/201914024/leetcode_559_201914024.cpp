//grp-8 201914024
//https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
class Solution {
public:
    int maxDepth(Node* root) {
       if(root==NULL) return 0;
        int height =0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz= q.size();
            for(int i=0;i<sz;i++){
                Node* cur = q.front();
                q.pop();
                for(Node* child: cur->children){
                    q.push(child);
                }
            }
            height++;

        }
        return height;
    }
};