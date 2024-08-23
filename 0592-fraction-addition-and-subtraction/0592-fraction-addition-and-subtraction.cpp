class Solution {
public:
    string fractionAddition(string e) {
        vector<int> den,num;
        vector<char> sign;
        int i=0,n=e.size();
        long long total=1;
        if(e[i]=='-'){
            sign.push_back('-');
            i++;
        }else{
            sign.push_back('+');
        }
        while(i<n){
            int number=0;
            while(e[i]!='/'){
                number=number*10+e[i++]-'0';
            }
            num.push_back(number);
            i++;
            number=0;
            while(isdigit(e[i])){
                number=number*10+e[i++]-'0';
            }
            den.push_back(number);
            total*=number;
            if(i<n){
                sign.push_back(e[i]);
                i++;
            }
        }
        long long top=0;
        for(int i=0;i<num.size();i++){
            if(sign[i]=='+'){
                top+=num[i]*(total/den[i]);
            }else{
                top-=num[i]*(total/den[i]);
            }
        }
        if(top==0){
            return "0/1";
        }
        char s='+';
        if(top<0){
            s='-';
            top=abs(top);
        }
        int gcd = __gcd(top,total);
        top/=gcd;
        total/=gcd;
        if(s=='+'){
            return to_string(top)+'/'+to_string(total);
        }
        return s+to_string(top)+'/'+to_string(total);
    }
};