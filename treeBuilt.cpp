/*
Treenode* dfs(vector<int>& preorder, unordered_map<int, int>& maps, int i, int left, int right) {
	if (right < left) return nullptr;

	Treenode* root = new Treenode(preorder[i]);

	int mid = maps[preorder[i]];

	root->left = dfs(preorder, maps, i + 1, left, mid - 1);
	root->right = dfs(preorder, maps, i + 1 + (mid - left), mid + 1, right);

	return root;
}

Treenode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	unordered_map<int, int> maps;
	for (int i = 0; i < inorder.size(); i++) {
		maps[inorder[i]] = i;
	}

	Treenode* root = dfs(preorder, maps, 0, 0, inorder.size() - 1);
	return root;
}
*/