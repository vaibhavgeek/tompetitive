int diameter(Node* root)
    {
        Node *p = root;
        if(!p) return 0;
        
        int left_height = 0;
        int right_height = 0;
        if(p->left)
            left_height = height(p->left);
        if(p->right)
            right_height = height(p->right);
        
         int ldiameter = diameter(p->left);
         int rdiameter = diameter(p->right);

            
        return max(1 + left_height + right_height, max(ldiameter, rdiameter));
       
        
    }
    int height(Node *node){
        if(!node) return 0;
        else
            return 1 + max(height(node->right), height(node->left));
    }
