class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      vector<int>tree={};

      
     
      Node *p = node;    
      queue<Node*> q;
      q.emplace(p);
      tree.push_back(p->data);
      while (! q.empty()){
            p = q.front();
            q.pop();
 
        if (p->left){
            tree.push_back(p->left->data);
            q.emplace(p->left);
        }
 
        if (p->right){
            tree.push_back(p->right->data);
            q.emplace(p->right);
        }
    }
    return tree;
      
    }
};
