void insert(stack<int> &s,int temp){
    if(s.size()==0 or s.top()<=temp){
    s.push(temp);
    return;    
    }
   
    int l = s.top();
    s.pop();
    insert(s,temp);
    s.push(l);
}

void SortedStack :: sort()
{  
    if(s.size()==1) return; 
   int temp = s.top();
   s.pop();
   sort();
   insert(s,temp);
}