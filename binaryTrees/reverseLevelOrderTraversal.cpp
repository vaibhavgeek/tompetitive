vector<int> reverseLevelOrder(Node *root)
{
    vector<int> tree;
    Node *p = root;
    queue<Node*> q;
    stack<int> s;
    
    q.push(p);
    while(!q.empty()){
        p = q.front();
        q.pop();
        s.push(p->data);
        if(p->right) q.push(p->right);

        if(p->left) q.push(p->left);
        
        
    }
    while(!s.empty()){
        tree.push_back(s.top());
        s.pop();
    }
    return tree;
    
}
