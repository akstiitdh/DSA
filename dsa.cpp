#include<bits/stdc++.h>
using namespace std;
	struct TreeNode {
		int val ;
		TreeNode * left;
		TreeNode * right;
		TreeNode(int data) : val(data), left(NULL),right(NULL) {}
	};

	pair<int,int> maxWithOfBinaryTree(TreeNode * root){
		if(!root) return {0,0};
		queue<pair<TreeNode*,  long long >> q;
		q.push({root, 0});
		long long  maxWidth = 0;
		int level = 0;
		int maxLevel=0;
		while(!q.empty()){
			int levelSize = q.size();
			 long long minIndex = q.front().second;
			 long long firstIndex, lastIndex;
			for(int  i =0;i<levelSize;i++){
				// auto [node,index] = q.front();
				TreeNode* node = q.front().first;
				int index = q.front().second;
				q.pop();
				index -= minIndex;
				if(i==0) firstIndex = index;
				if(i== levelSize -1) lastIndex = index;
				if(node ->left) q.push({node->left, 2*index+1});
				if(node->right) q.push({node->right, 2*index + 2});
			}
			if(maxWidth < lastIndex-firstIndex +1){
			    maxWidth = lastIndex-firstIndex +1;
			    maxLevel = level;
			}
			level++;
		}
		return {maxWidth, maxLevel};
	}

   TreeNode * buildTree( vector<int> & values) {
   	if(values.empty() || values[0] == -1) return nullptr;
   	TreeNode * root = new TreeNode(values[0]);
   	queue<TreeNode*>q;
   	q.push(root);
   	int i =0;
   	while(i<values.size()){
   		TreeNode * current = q.front();
   		q.pop();
   		if(values[i] != -1){
   			current->left = new TreeNode(values[i]);
   			q.push(current->left);
   		}
   		i++;
   		if(i<values.size() && values[i] !=-1){
   			current->right = new TreeNode(values[i]);
   			q.push(current->right);
   		}
   		i++;
   	}
   	return root;
   }
int main(){

   vector<int> input = {2,7,5,2,6,-1,9,-1,-1,5,11,4,-1,-1,-1,-1,-1,-1,-1};
   TreeNode * root = buildTree(input);
   cout<< maxWithOfBinaryTree(root).second;
}