class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root == nullptr) {
            return vector<int>();
        }
        vector<int> my_vector;
        stack<Node*> my_stack;
        my_stack.push(root);
        vector<int> my_result = vector<int>();
        while(my_stack.empty() == false) {
            Node* temp = my_stack.top();
            my_vector.push_back(temp->val);
            my_stack.pop();
            for(int i = 0; i < (temp->children).size(); i++) {
                my_stack.push((temp->children)[i]);
            }
        }
        std::reverse(my_vector.begin(), my_vector.end());
        return my_vector;
    }
};

