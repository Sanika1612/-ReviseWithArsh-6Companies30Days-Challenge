

/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  string ans="";
  for(int i=0; i<src.length(); i++){
      int c=1;
      while(i+1<src.length() && src[i+1]==src[i]){
          i++;
          c++;
      }
      ans+=src[i];
      ans+=to_string(c);
  }
  return ans;
}     
 
