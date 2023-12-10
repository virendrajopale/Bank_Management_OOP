#include <bits/stdc++.h>

#include "Bank_Data.cpp"
using namespace std;
int main()
{
  int choice;
  int num;
  Bank_Data b1;
  Account ac;
  system("clear");
  do
  {

    cout << "\t\t -----------------------------------------" << endl;
    cout << "\t\t Welcome to Bank Management Sysytem \n";
    cout << "\t\t -----------------------------------------" << endl;
    space;
    cout << "\t 1. Create Account " << endl;
    cout << "\t 2. Deposit Money " << endl;
    cout << "\t 3. Withdraw Money " << endl;
    cout << "\t 4. Check Balance" << endl;
    cout << "\t 5. All Account Holders list" << endl;
    cout << "\t 6. Close an Account" << endl;
    cout << "\t 7. Update Account" << endl;
    cout << "\t 8. Close" << endl;
    space;
    cout << "\t Enter choice :: ";

    cin >> choice;
    space;
    switch (choice)
    {
    case 1:
      system("clear");
      b1.Write_Account();
      break;
    case 2:
      system("clear");
      cout << "\t Enter Account Number :: ";
      cin >> num;
      // deposit dunction
          space;
      ac.Money_Deposit_Withdraw(num, 1);
      break;
    case 3:
      system("clear");
      cout << "\t Enter Account Number :: ";
      cin >> num;
      // withdraw dunction
          space;
      ac.Money_Deposit_Withdraw(num, 2);
      break;
    case 4:
    {
      system("clear");
      cout << "\t Enter Account Number :: ";
      cin >> num;
      space;
      ac.Dispay_Details(num);
      // check balance
      break;
    }
    case 5:
      // display list
          space;
      ac.Display_All();
      break;

    case 6:
      system("clear");
      cout << "\t Enter Account Number :: ";
      cin >> num;
      Bank_Data b1;
          space;
      b1.Delete_Account(num);
      // account close
      break;
    case 7:
      system("clear");
      cout << "\t Enter Account Number :: ";
      cin >> num;
      // update account
          space;
      ac.Update_Account(num);
      break;
    case 8:
      system("clear");
      space;
      cout << "\t Thank You" << endl;
      cout<<"\t Enter Control 'C' To Turn Off Server"<<endl;
      break;
    default:
    space;
         cout<<"Wrong Choice"<<endl;
      break;
    }
    cin.ignore();
    space;
    cout<<"Press Any key to continue (1-8) :: ";
    cin >> num; 
    space;
  } while (choice != 8);
  return 0;
}