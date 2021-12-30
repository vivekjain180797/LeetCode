class Solution {
public:
    bool isValid(string sh) {
        stack<char> s;
        for(auto ch :sh){
            if(ch=='(' || ch == '[' || ch =='{'){
                s.push(ch);
            } else {
                if(s.empty() || (s.top()=='(' && ch!=')') || (s.top()=='{' && ch!='}') || (s.top()=='[' && ch!=']')) return false;
                s.pop();  //if control reaches to that line, it means we have got the right pair of brackets, so just pop it.
            }
        }
         return s.empty() ? true : false;
    }
};