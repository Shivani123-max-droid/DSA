class Solution {
public:
    bool isValid(string str) {
        stack<char> s;

        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
                s.push(str[i]);
            } 
            else {
                if(s.empty()) return false; 

                char top = s.top();
                if((str[i] == ')' && top == '(') ||
                   (str[i] == ']' && top == '[') ||
                   (str[i] == '}' && top == '{')) {
                    s.pop();
                } 
                else {
                    return false;
                }
            }
        }
        return s.empty();
    }
};