class Solution {
public:
    bool isValid(string s) {
     if (s.empty()) 
     { 
         return true; 
     }
        
        stack<char> stk;  //create stack to keep track by LIFO principle
        
        for (char c : s)  //Go through each charecter (for each loop)
        {
            if (c == '(' || c == '{' || c == '[') //pushes into stack
            { stk.push(c); }
            else if (c == ')' || c == '}' || c == ']')
            {
                switch (c)
                {
                    case ')': if (stk.empty() || stk.top() != '(') //to see if its false
//by LIFO if top element isn't its opp or if the stack is empty then we return false and end 
            //Since we use OR operator we need to keep stk.empty first else it wont be checked
                                { return false; } 
                        
                                else { stk.pop(); } //when true
                                break;
                        
                    case '}': if (stk.empty() || stk.top() != '{') 
                                { return false; } 
                                else { stk.pop(); } 
                                break;
                        
                    case ']': if (stk.empty() || stk.top() != '[') 
                                { return false; } 
                                else { stk.pop(); } 
                                break;
                        
                    default: ;
                }
            }
        }
        return stk.empty(); 
        //works as a logical return. if stack is empty it returns true else false
}  
};