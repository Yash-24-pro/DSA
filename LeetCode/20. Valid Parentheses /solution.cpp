class Solution {
public:
    bool isValid(string s) {
        int a = 0;
        int b = 0;
        int c = 0;
        vector<char> last_opened;
        for(char ch : s){
            if(ch == '('){
                a+=1;
                last_opened.push_back('a');
            }
            else if(ch == '{'){
                b +=1;
                last_opened.push_back('b');
            }
            else if(ch == '['){
                c +=1;
                last_opened.push_back('c');
            }
            else if(ch == ')'){
                if(last_opened.empty() || last_opened.back() != 'a'){
                    return false;
                }
                a--;
                last_opened.pop_back();
                }
            else if(ch == '}'){
                if(last_opened.empty() || last_opened.back() != 'b'){
                    return false;
                }
                b--;
                last_opened.pop_back();
                }
            else if(ch == ']'){
                if(last_opened.empty() || last_opened.back() != 'c'){
                    return false;
                }
                c--;
                last_opened.pop_back();
                }
            }
        return a == 0 && b == 0 && c == 0;
        }
    };
