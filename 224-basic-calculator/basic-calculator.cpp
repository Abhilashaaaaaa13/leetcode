class Solution {
public:
    int calculate(string s) {
        stack<long long>st;
        long long number =0;
        long long result =0;
        int sign = 1;
        int n = s.size();
        for(int i =0;i<n;i++){
            if(isdigit(s[i])){
             number = number*10 +(s[i]-'0') ;//no bnana
            }
            else if(s[i]=='+'){
             // number bn chuka 
             //no result m add kro
            result += (number*sign);
            number =0;
            sign =1;

            }
            else if(s[i]=='-'){
                result += (number*sign);
                number =0;
                sign = -1;
            }
            else if(s[i]=='('){
              st.push(result);
              st.push(sign);
              result =0;
              number =0;
              sign =1;
            }
            else if(s[i]==')'){
                result +=  (number *sign); // bracket k andar ka result h yehh
                number =0;
                int stack_sign = st.top();
                st.pop();
                int stack_result = st.top();
                st.pop();
                result *= stack_sign;
                result += stack_result;
            }
        }
        result += (number*sign);
        return result;
    }
};