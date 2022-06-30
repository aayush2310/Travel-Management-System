#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>

using namespace std;
void menu();

class ManageMenu
{
protected:
    string userName;//hide admin name
public:
    ManageMenu()
    {
        system("color 0A");//change terminal clr;
        cout<< "\n\n\n\n\n\n\n\t  Enter Your Name to Continue as an Admin: ";
        cin>>userName;
        system("CLS");
        menu();
    }
    ~ManageMenu(){}
};

class Customers
{
public:
    string name,gender,address;
    int age,mobileNo;
    static int cusID;
    char all[999];

    void getDetails()
    {
        ofstream out("old-customers.txt",ios::app);
        {
        cout<<"Enter Customer ID: ";
        cin>>cusID;
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"Enter Age: ";
        cin>>age;
        cout<<"Enter Mobile Number: ";
        cin>>mobileNo;
        cout<<"Enter Address: ";
        cin>>address;
        cout<<"Enter Gender: ";
        cin>>gender;
        }
        out << "\nCustomer ID:" << cusID << "\nName: " <<name << "\nAge: "<< age << "\nMobile Number: " << mobileNo << "\nAddress: "<<address << "\nGender: " <<gender <<endl;
        out.close();
        cout<< "\nSAVED \nNOTE: we save your details record for future purposes\n" <<endl;
    }
    void showDetails()
    {
        ifstream in("old-customers.txt");
        {
            if(in)
            {
                cout<< "File Error!" <<endl;
            }
            while(!(in.eof()))
            {
                in.getline(all, 999);
                cout<< all << endl;
            }
            in.close();
        }
    }
};

int Customers::cusID;

class Cabs
{
public:
    int cabChoice;
    int kilometers;
    float cabCost;
    static float lastcabCost;

    void cabDetails()
    {
        cout<< "We collaborated with fastest,safest and smartest cab service around the country"<<endl;
        cout<< "--------------ABC Cabs-----------------\n"<<endl;
        cout<< "1. Rent a Standard Cab - Rs.15 for 1KM"<<endl;
        cout<< "2.Rent a Luxury Cab - Rs.25 per 1KM"<<endl;

        cout<< "\nTo calculate the cost for your journey" <<endl;
        cout<< "Enter which kind of cab you need:";
        cin>>cabChoice;
        cout<<"Enter kilometers you have to travel:";
        cin>>kilometers;

        int hireCab;
        if(cabChoice==1){
            cabCost=kilometers * 15;
            cout<< "\nYour tour cost " <<cabCost << "rupees for a Standard Cab" << endl;
            cout<<"Press 1 to hire this cab: or";
            cout<<"Press 2 to select another cab: ";
            cin>>hireCab;

            system("CLS");

            if(hireCab==1){
                lastcabCost=cabCost;
                cout<< "\nYou have successfully hired a Standard cab" <<endl;
                cout<< "Goto Menu and take the receipt" <<endl;
            }
            else if(hireCab==2){
                cabDetails();
            }
            else{
                cout<< "Invalid Input! Redirecting to previous menu \nPlease Wait!" <<endl;
                Sleep(999);
                system("CLS");
                cabDetails();
            }
        }
        else if(cabChoice==2){
            cabCost=kilometers * 25;
            cout<< "\nYour tour  will cost " <<cabCost << "rupees for a luxury Cab" << endl;
            cout<<"Press 1 to hire this cab: or";
            cout<<"Press 2 to select another cab: ";
            cin>>hireCab;

            system("CLS");

            if(hireCab==1){
                lastcabCost=cabCost;
                cout<< "\nYou have successfully hired a luxury cab" <<endl;
                cout<< "Goto Menu and take the receipt" <<endl;
            }
            else if(hireCab==2){
                cabDetails();
            }
            else{
                cout<< "Invalid Input! Redirecting to previous menu \nPlease Wait!" <<endl;
                Sleep(1100));
                system("CLS");
                cabDetails();
            }
        }
        else{
            cout<< "Invalid Input! Redirecting to Main menu \nPlease Wait!" <<endl;
            Sleep(1100));
            system("CLS");
            menu();
        }
        cout<< "\nPress 1 to Redirect Main menu: ";
        cin >> hireCab;
        system("CLS");
        if(hireCab==1){
            menu();
        }
        else{
            menu();
        }
    }
};

float Cabs::lastcabCost;

class Booking
{
public:
    int choiceHotel;
    int packChoice;
    static float hotelCost;

    void hotels()
    {
        string hotelNo[]={"Avendra","ChoiceYou","ElephantBay"};
        for(int a=0;a<3;a++){
            cout<< (a+1) << ".Hotel" <<endl;
        }
        cout<< "\nCurrently we collaborated with above hotels!"<<endl;
        cout<< "Press any key to back or\n Enter number of the hotel you want to book: ";
        system("CLS");
        if(choiceHotel == 1){
            cout<< "-----WELCOME TO HOTEL AVENDRA----\n" <<endl;
            cout<< "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." <<endl;
            cout<< "Packages offered by Avendra:\n"<<endl;
            cout<< "1.Standard Pack" <<endl;
            cout<< "\tAll basic facilites you need just for: Rs.5000" <<endl;
            cout<< "2. Premium Pack" <<endl;
            cout<< "\tEnjoy Premium: Rs.10000.00" <<endl;
            cout<< "3. Luxury Pack"<< endl;
            cout<< "\tLive a Luxury at Avendra: Rs.15000.00" <<endl;

            cout<< "\nPress another key to back or\nEnter package number you want to book: ";
            cin>>packChoice;

            if(packChoice==1){
                hotelCost=5000.00;
                cout<< "\nYou have successfully booked Standard pack at Avendra"<<endl;
                cout<< "Go to menu and take the receipt" <<endl;
            }
            else if(packChoice==2){
                hotelCost=10000.00;
                cout<< "\nYou have successfully booked Premium Pack at Avendra"<<endl;
                cout<< "Go to menu and take the receipt" <<endl;
            }
            else if(packChoice==3){
                hotelCost=15000.00;
                cout<< "\nYou have successfully booked Luxury pack at Avendra"<<endl;
                cout<< "Go to menu and take the receipt" <<endl;
            }
            else{
                cout << "Invalid Input: Redirecting to Previous Menu \nPlease Wait!" <<endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            int gotomenu;
            cout << "\nPress 1 to redirect main menu";
            cin>>gotomenu;
            if(gotomenu==1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 2){
            cout<< "-----WELCOME TO HOTEL ChoiceYou----\n" <<endl;
            cout<< "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." <<endl;
            cout<< "Packages offered by ChoiceYou:\n"<<endl;
            cout<< "1.Standard Pack" <<endl;
            cout<< "\tAll basic facilites you need just for: Rs.5000" <<endl;
            cout<< "2. Premium Pack" <<endl;
            cout<< "\tEnjoy Premium: Rs.10000.00" <<endl;
            cout<< "3. Luxury Pack"<< endl;
            cout<< "\tLive a Luxury at ChoiceYou: Rs.15000.00" <<endl;

            cout<< "\nPress another key to back or\nEnter package number you want to book: ";
            cin>>packChoice;

            if(packChoice==1){
                hotelCost=5000.00;
                cout<< "\nYou have successfully booked Standard pack at ChoiceYou"<<endl;
                cout<< "Go to menu and take the receipt" <<endl;
            }
            else if(packChoice==2){
                hotelCost=10000.00;
                cout<< "\nYou have successfully booked Premium Pack at ChoiceYou"<<endl;
                cout<< "Go to menu and take the receipt" <<endl;
            }
            else if(packChoice==3){
                hotelCost=15000.00;
                cout<< "\nYou have successfully booked Luxury pack at ChoiceYou"<<endl;
                cout<< "Go to menu and take the receipt" <<endl;
            }
            else{
                cout << "Invalid Input: Redirecting to Previous Menu \nPlease Wait!" <<endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            int gotomenu;
            cout << "\nPress 1 to redirect main menu";
            cin>>gotomenu;
            if(gotomenu==1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 3){
            cout<< "-----WELCOME TO HOTEL ElephantBay----\n" <<endl;
            cout<< "Set in tropical gardens on the banks of the Maha Oya river while Seeing Elephants" <<endl;
            cout<< "Amazing offer in this summer: Rs.5000.00 for one day!!!"<<endl;
            cout<< "1.Standard Pack" <<endl;
            cout<< "\tAll basic facilites you need just for: Rs.5000" <<endl;
            cout<< "2. Premium Pack" <<endl;
            cout<< "\tEnjoy Premium: Rs.10000.00" <<endl;
            cout<< "3. Luxury Pack"<< endl;
            cout<< "\tLive a Luxury at ElephantBay: Rs.15000.00" <<endl;

            cout<< "\nPress another key to back or\nEnter package number you want to book: ";
            cin>>packChoice;

            if(packChoice==1){
                hotelCost=5000.00;
                cout<< "\nYou have successfully booked Standard pack at ElephantBay"<<endl;
                cout<< "Go to menu and take the receipt" <<endl;
            }
            else if(packChoice==2){
                hotelCost=10000.00;
                cout<< "\nYou have successfully booked Premium Pack at ElephantBay"<<endl;
                cout<< "Go to menu and take the receipt" <<endl;
            }
            else if(packChoice==3){
                hotelCost=15000.00;
                cout<< "\nYou have successfully booked Luxury pack at ElephantBay"<<endl;
                cout<< "Go to menu and take the receipt" <<endl;
            }
            else{
                cout << "Invalid Input: Redirecting to Previous Menu \nPlease Wait!" <<endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            int gotomenu;
            cout << "\nPress 1 to redirect main menu";
            cin>>gotomenu;
            if(gotomenu==1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            cout<< "Invalid Input! Redirecting to previous Menu \nPlease Wait!" <<endl;
            Sleep(1100);
            system("CLS");
            menu();
        }

    }

};

float Booking::hotelCost;

class Charges : public Booking, Cabs, Customers
{
public:
    void printBill()
    {
        ofstream outf("reciept.txt");
        {
            outf << "-----------ABC Travel Agency-----------" <<endl;
            outf << "----------------Receipt----------------" <<endl;
            outf << "_______________________________________" <<endl;

            outf << "Customer ID: " << Customers::cusID << endl << endl;
            outf << "Description\t\t Total" <<endl;
            outf << "Hotel cost:\t\t "<<fixed <<setprecision(2) <<Booking::hotelCost<<endl;
            outf <<"Travel (cab) cost:\t "<<fixed << setprecision(2) <<Cabs::lastcabCost<<endl;

            outf << "_______________________________________" <<endl;
            outf << "Total Charge:\t\t " <<fixed <<setprecision(2)<<Booking::hotelCost+Cabs::lastcabCost <<endl;
            outf << "_______________________________________" <<endl;
            outf << "--------------THANK YOU----------------" << endl;
        }
        outf.close();
    }
    void showBill()
    {
        ifstream inf("receipt.txt");
        {
            if(!inf)
            {
                cout<< "File opening error!" <<endl;
            }
            while(!(inf.eof())){
                inf.getline(all,999);
                cout<< all <<endl;
            }
        }
        inf.close();
    }
};

void menu()
{
    int mainChoice;
    int inChoice;
    int gotoMenu;

    cout<< "\t\t        *ABC Travels *\n" <<endl;
    cout<< "------------------------------Main Menu---------------------------" <<endl;

    cout<< "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" <<endl;
    cout<< "\t|\t\t\t\t\t\t"<<endl;
    cout << "\t|\tCustomer Management -> 1\t|" <<endl;
    cout << "\t|\tCabs Management     -> 2\t|" <<endl;
    cout << "\t|\tBookings Management -> 3\t|" <<endl;
    cout << "\t|\tCharges and Bill    -> 4\t|" <<endl;
    cout << "\t|\tExit                -> 5\t|" <<endl;
    cout << "\t|\t\t\t\t\t\t\t" <<endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;

    cout << "\nEnter Your Choice: ";
    cin>>mainChoice;

    system("CLS");

    Customers a2;
    Cabs a3;
    Booking a4;
    Charges a5;

    if(mainChoice==1){
        cout << "------Customers-------\n" <<endl;
        cout << "1. Enter New Customer"<<endl;
        cout << "2. See Old Customers"<<endl;

        cout<< "\nEnter Choice: ";
        cin>> inChoice;

        system("CLS");
        if(inChoice==1){
            a2.getDetails();
        }
        else if(inChoice==2){
            a2.showDetails();
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" <<endl;
            Sleep(1100);
            system("CLS");
            menu();
        }

        cout << "\nPress 1 to Redirect main menu: ";
        cin>>gotoMenu;
        system("CLS");
        if(gotoMenu==1){
            menu();
        }
        else{
            menu();
        }
    }
    else if(mainChoice==2){
        a3.cabDetails();
    }
    else if(mainChoice==3){
        cout<< "--> Book a luxury using the system <--" << endl;
        a4.hotels();
    }
    else if(mainChoice==4){
        cout<< "-->Get your receipt <--" <<endl;
        a5.printBill();

        cout << "Your receipt is already printed you can get it from file path\n" << endl;
        cout << "to display your receipt in the screen,Enter 1: or Enter another key to back main menu: ";

        cin>>gotoMenu;

        if(gotoMenu==1){
            system("CLS");
            a5.showBill();
            cout<<"\n Press 1 to redirect main menu: ";
            cin>> gotoMenu;
            system("CLS");
            if(gotoMenu==1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            system("CLS");
            menu();
        }
    }
    else if(mainChoice==5){
        cout<< "--GOOD BYE--" << endl;
        Sleep(999);
        system("CLS");
        menu();
    }
    else{
        cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" <<endl;
        Sleep(1100);
        system("CLS");
        menu();
    }

}

int main()
{
    ManageMenu startObj;
    return(0);
}
