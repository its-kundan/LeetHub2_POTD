class Node{
    public:
    char data;
    int count;
    Node(char c,int n){
        data=c;
        count =n;
    }
};
class compare{
    public:
    bool operator()(Node a,Node b){
        return a.count < b.count;
    }
};
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<Node,vector<Node>,compare> maxheap;
        if(a>0){
            Node temp('a',a);
            maxheap.push(temp);
            }
        if(b>0){
            Node temp('b',b);
            maxheap.push(temp);
        }
        if(c>0){
            Node temp('c',c);
            maxheap.push(temp);
        }
        string ans="";
        while(maxheap.size()>1){
            Node first=maxheap.top();
            maxheap.pop();
            Node second=maxheap.top();
            maxheap.pop();

            if(first.count>=2){
                ans+=first.data;
                ans+=first.data;
                first.count-=2;
            }
            else{
                ans+=first.data;
                first.count-=1;
            }  
            if(second.count>=first.count && second.count>=2){
                ans+=second.data;
                ans+=second.data;
                second.count-=2;
            }
            else{
                ans+=second.data;
                second.count-=1;
            }
            if(first.count>0)
                maxheap.push(first);
            if(second.count>0)
                maxheap.push(second);
        }
        if(maxheap.size()==1){
            Node temp=maxheap.top();
            maxheap.pop();
            if(temp.count>=2){
                ans+=temp.data;
                ans+=temp.data;
                temp.count-=2;
            }
            else{
                ans+=temp.data;
                temp.count--;
            }
        }
        return ans;
    }
};