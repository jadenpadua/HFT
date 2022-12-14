/**
* @description: 
* Step 1: use stack to track open paranthesis 
* Step 2: Iterate through s, if open paranthesis then just push to stack
* Step 3: if closed, return false if stack size is 0 or it does not have a matching open paran at top of stack
* Step 4: return true only if stack is empty and all open paranthesis were matched with closed paranthesis
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        string opening = "({[", closing = ")}]";
        unordered_map<char,char> umap = {
            {'}', '{'},
            {')', '('},
            {']', '['},
        };

        for(auto c : s) {
            if(opening.find(c) != string::npos) {
                stack.push(c);
            }
            else {
                if(stack.size() == 0 || umap[c] != stack.top()) {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.size() == 0;
    }
};
