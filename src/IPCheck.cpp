#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include "sha256.h"

using std::cout; using std::cin;
using std::endl; using std::string;
using std::to_string;
using namespace std;

void getRBF(string path, int* bf, int m);
bool checkIPInRBF(string IP, int* bf, int m);
int getHashValue(string input, int m);
void test(int*bf, int m);

int testCount = 0;

int main(int argc, char** argv){
  string path = "./RBFRow1.txt";
  string ip = "192.168.0.001";
  cout<<"Enter IP-Address to check in the RBF:"<<endl;
  cin>>ip;
  if(argc > 1){
    path = argv[1];
  }
  ifstream MyFile;
  MyFile.open(path);
  int count = 0;
  if(MyFile.is_open()){
    char mychar;
    while ( MyFile ) {
      mychar = MyFile.get();
      count++;
    }
  }
  count--;
  int bf[count];
  getRBF(path, bf, count);
  if(checkIPInRBF(ip, bf, count)){
    cout << "Block"<<endl;
  }
  else{
    cout << "Pass"<<endl;
  }
}

bool checkIPInRBF(string IP, int* bf, int m){
  bool result = true;
  for(int i = 1; i < 9; i++){
    string hashInput = to_string(i) + IP;
    int index = getHashValue(hashInput, m);
    int hashOutput = getHashValue(to_string(index), 2);
    if(hashOutput == 1 && bf[index] == 0 || hashOutput == 0 && bf[index] == 1){
      result &= true;
    }
    else{
      result &= false;
    }
  }
  return result;
}

void getRBF(string path, int* bf, int m){
  ifstream MyFile;
  MyFile.open(path);
  int i = 0;
  if(MyFile.is_open()){
    while(i < m){
      char curr = MyFile.get();
      if(curr == '1'){
        bf[i] = 1;
      }else{
        bf[i] = 0;
      }
      i++;
    }
  }
  cout <<"File read completed!!"<<endl;
  cout <<"Read an RBF of size:"<<i<<endl;
}
