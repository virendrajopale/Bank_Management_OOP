#include <bits/stdc++.h>
#include "Account.cpp"
using namespace std;
class Bank_Data{
public:
void Write_Account(){
    Account ac;
    ofstream outFile;
    outFile.open("account.dat",ios::binary|ios::app);
    ac.Create_account();
    outFile.write(reinterpret_cast<char*>(&ac),sizeof(Account));
    outFile.close();
    ac.Display_account();
}
void Delete_Account(int n){
 Account ac;
 ifstream inFile;
 ofstream outFile;
 inFile.open("account.dat",ios::binary);
 if(!inFile){
    cout<<"\t file does not exist"<<endl;
    return;
 }
 outFile.open("temp.dat",ios::binary);
 inFile.seekg(0,ios::beg);
 while(inFile.read(reinterpret_cast<char *>(&ac),sizeof(Account))){
    if(ac.retaccno()!=n){
        outFile.write(reinterpret_cast<char *>(&ac),sizeof(Account));
    }
 }
 inFile.close();
 outFile.close();
 remove("Account.dat");
 rename("temp.dat","Bank_Acc.dat");
 cout<<endl<<"\t Account Deleted"<<endl;;
}

};
