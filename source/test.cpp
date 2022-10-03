/*void test(int*bf, int m){
int i, j, k;
string baseIP = "192.168";
bool check = true;
for(i = 0; i < 10; i++){
    string modIP = baseIP + "." + to_string(i);
    for(j = 0; j < 1000; j++){
      string currentIP;
      if(j > 99){
        currentIP = modIP + "." + to_string(j);
      }
      else if(j > 9){
        currentIP = modIP + ".0" + to_string(j);
      }
      else{
        currentIP = modIP + ".00" + to_string(j);
      }
      check = check & checkIPInRBF(currentIP, bf, m);
    }
  }
  if(check){
    cout<<"Yeah Test case passed"<<endl;
  }
}*/
