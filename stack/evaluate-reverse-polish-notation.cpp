class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack {};
        
        for(string s: tokens) {
            if(s.size() > 1 || isdigit(s[0])) stack.push(stoi(s));
            else {
                int o2 = stack.top(); stack.pop();
                int o1 = stack.top(); stack.pop();

                switch(s[0]) {
                    case '+': o1 += o2; break;
                    case '-': o1 -= o2; break;
                    case '*': o1 *= o2; break;
                    case '/': o1 /= o2; break;
                }
                stack.push(o1);
            }
        }
        return stack.top();
    }
};
