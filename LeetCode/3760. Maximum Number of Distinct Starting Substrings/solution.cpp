class Solution {
public:
    int maxDistinct(string s) {
        string s1;
        s1.push_back(s[0]);
        for(int i=1;i<s.size();i++){
        bool found = false;
            for(int j=0;j<s1.size();j++){
               if(s[i] ==s1[j]){
                found = true;
                break;
               }
               
            }
            if(found == false){

                s1.push_back(s[i]);
            }
        }
        return s1.size();
    }

};
