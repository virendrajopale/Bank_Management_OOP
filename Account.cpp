using namespace std;
#define space cout<<endl;
class Account
{
private:
    int account_no;
    char name[50];
    char type;
    int money_deposit;

public:
void report() const{

     cout<<" \t "<<account_no<<setw(10)<<name<<setw(10)<<type<<setw(10)<<money_deposit<<endl;
}
int retaccno() const{
    return account_no;
}
void deposit(int money) {
   money_deposit+=money;
}
void withdraw(int money) {
   money_deposit-=money;
}
int returnDeposit() const{
   return money_deposit;
}
void update();
    void Create_account();
    void Display_account();
    void Dispay_Details(int n);
    void Display_All();
    void Money_Deposit_Withdraw(int,int);
    void Update_Account(int );
};
//void
void Account:: Create_account(){
system("clear");
 cout<<"\t Enter Account Number :: ";
 cin>>account_no;
 cout<<"\t Enter Name of Account holder :: ";
 cin.ignore();
 cin.getline(name,50);
 cout<<"\t Enter Type of Account (C/S) :: ";
 cin>>type;
  type=toupper(type);
  cout<<"\t Enter the initial amount :: ";
  cin>>money_deposit;
  space;
  cout<<"\t Account Created..\n"<<endl;
  
 }
 void Account:: Display_account(){
    cout<<"\t Bank Account Number :: "<<account_no<<endl;
    cout<<"\t Account Holder Name :: "<<name<<endl;
    cout<<"\t Account Type :: "<<type<<endl;
    cout<<"\t Balance :: "<<money_deposit<<endl;
 }
 void Account:: Dispay_Details(int n){
  Account ac;
  bool flag=false;
  ifstream inFile;
  inFile.open("account.dat",ios::binary);
  if(!inFile){
    cout<<"File Could not be open..."<<endl;
    return;
  }
  cout<<"\t Bank Account Details"<<endl;
  while(inFile.read(reinterpret_cast<char* >(&ac),sizeof(Account))){

   if(ac.retaccno()==n){
    ac.Display_account();
    flag=true;
  }
   }
 inFile.close();
 if(flag==false){
    cout<<"\t Account No. Does not Exist"<<endl;
 }
 }

void Account :: Display_All(){

    system("clear");
    Account ac;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile){
        cout<<"\t File Does Not Exist"<<endl;
        return;
    }
    cout<<"\t Bank Account Holder's List"<<endl;
    space;
    cout<<"\t ======================================="<<endl;
    cout<<"\t A/c no.\t Name\t Type\t Balance"<<endl;
    cout<<"\t ======================================="<<endl;
    space;
    while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
      ac.report();
    }
   inFile.close();

}

void Account :: Money_Deposit_Withdraw(int acc_no,int choice){
  int amount;
  bool found=false;
  Account ac;
  fstream File;
  File.open("account.dat",ios::binary|ios::in|ios::out);
  if(!File){
    cout<<"\t File could not be Found......"<<endl;
  return;
  }
  while(!File.eof() and found==false){
    File.read(reinterpret_cast<char *>(&ac),sizeof(Account));
    if(ac.retaccno()==acc_no){
      ac.Display_account();
      space;
      if(choice==1){
        cout<<"\t Enter Amount To Be Deposit :: ";
        cin>>amount;
        ac.deposit(amount);
      }
      if(choice==2){
        cout<<"\t Enter Amount To Be Withdraw :: ";
        cin>>amount;
        int balance=ac.returnDeposit()-amount;
        if(balance<0){
          cout<<"\t Insufficiant Balance"<<endl;
          
        }
        else{
          ac.withdraw(amount);
        }
      }
      int pos=(-1)*static_cast<int>(sizeof(Account));
      File.seekp(pos,ios::cur);
      File.write(reinterpret_cast<char*>(&ac),sizeof(Account));
      cout<<"\t File Closed"<<endl;
      found=true;

    }
  }
  File.close();
  if(found==false){
    cout<<"\t File Not Found"<<endl;
  }
}

void Account :: update(){
  cout<<"\t Account Number :: "<<account_no<<endl;
  cout<<"\t Update Account Holder's Name :: ";
  cin.ignore();
  cin.getline(name,50);
  cout<<"\t Update Account Type :: ";
  cin>>type;
  type=toupper(type);
  

}
void Account :: Update_Account(int acc_no){
  bool found=false;
  Account ac;
  fstream File;
  File.open("account.dat",ios::binary|ios::in|ios::out);
  if(!File){
    cout<<"\t File Could Not Be Found"<<endl;
    return;
  }
  while (!File.eof() and found==false)
  {
    File.read(reinterpret_cast<char*>(&ac),sizeof(Account));
    if(ac.retaccno()==acc_no){
      ac.Display_account();
      space;
      cout<<"\t Enter New Details of The Account"<<endl;
      ac.update();
        int pos=(-1)*static_cast<int>(sizeof(Account));
      File.seekp(pos,ios::cur);
      File.write(reinterpret_cast<char*>(&ac),sizeof(Account));
      cout<<"\t File Updated"<<endl;
      found=true;
    }
  }
   File.close();
  if(found==false){
    cout<<"\t File Not Found"<<endl;
  }
  
}