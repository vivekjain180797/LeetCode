class Solution {

private:
    void palindrom(string s, int left, int right, string& longest, int& len){
          while(left>=0 && right < s.size() && s[left] == s[right]){
              if(right - left +1 > len){
                  len = right - left + 1;
                  longest = s.substr(left,len);
              }
              left--;
              right++;
          }        
    }

public:
    string longestPalindrome(string s) {
        string longest;
        int len=0;
        for(int i=0; i<s.size();++i){
            palindrom(s,i,i,longest,len);
            palindrom(s,i,i+1,longest,len);
        }
        return longest;
    }
};