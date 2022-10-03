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

/*struct bit{
  int data: 1;
};*/

void initializeBF(int *bf, int m);
void buildBF(int *bf, int m);
int getHashValue(string input, int m);
void captureBF(int *bf, int m);
void addIPToRBF(string ip, int* bf, int m);

int main(int argc, char** argv){
  int m = 210455;
  char overrideM;
  cout<<"Would you like to enter the value of M?(Y/N):"<<endl;
  cin>>overrideM;
  if(overrideM == 'Y' || overrideM == 'y'){
    cout<<"Enter the value of m:"<<endl;
    cin>>m;
  }
  else{
    cout<<"The default value of m:"<<m<<" is being used."<<endl;
  }
  int bf[m];
  initializeBF(bf,m);
  buildBF(bf, m);
  captureBF(bf, m);
}


void buildBF(int* bf, int m){
  int i, j, k;
  string baseIP = "192.168";
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
      addIPToRBF(currentIP, bf, m);
    }
  }
}

void addIPToRBF(string IP, int* bf, int m){  
  for(int k = 1; k < 9; k++){
    string hashInput = to_string(k) + IP;
    int index = getHashValue(hashInput, m);
    int hashOutput = getHashValue(to_string(index), 2);
    if(hashOutput == 0){
      bf[index] = 1;
    }
    else{
      bf[index] = 0;
    }
    //cout << k<<"::"<< index<<"::"<< hashOutput <<"::"<< bf[index] << endl;
  }
}

void captureBF(int *bf, int m){
  ofstream MyFile("RBFRow1.txt", std::ofstream::trunc);
  for(int i = 0; i < m; i++){
    MyFile << bf[i];
  }
}

  
void initializeBF(int* bf, int m){
  int i;
  for(i = 0; i < m; i++){
    if(getHashValue(to_string(i), 2) == 0){
      bf[i] = 0;
    }
    else{
      bf[i] = 1;
    }
  }
}    
