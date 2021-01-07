//Alexander Rollison 1001681800
//Code3_1001681800.cpp, .cpp, .h

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "CokeMachine.h"

using namespace std;

int main(void)
{
	CokeMachine MyCokeMachine{"\n\nCSE 1325 Coke Machine", 50, 500, 100};
    int choice;
    int payment;
    int action;
    std::string change = {"0"};
    bool buycheck;

    int addproduct;
    bool inventorycheck;

    bool changecheck;
    int addchange;

    do
    {
        cout<<MyCokeMachine.getMachineName()<<endl;
        cout<<"\n0. Walk away\n1. Buy a Coke\n2. Restock Machine\n3. Add change\n4. Display Machine Info"<<endl;
        cin>>choice;
        
        switch(choice)
        {
            case 0: //Walk away
                cout<<"Are you sure you aren't really THIRSTY and need a Coke?"<<endl;
                //break out of loop
                break;
            case 1: //Buy a Coke
                cout<<"\ninsert payment ";
                cin>>payment;
                buycheck = MyCokeMachine.buyACoke(payment,change, action);

                if(buycheck == 1)
                {
                    if(action == OK)    
                    {
                        cout<<"Here's your Coke and your change of "<<change<<endl;
                    }

                    if(action == EXACTCHANGE)
                    {
                        cout<<"\nThank you for exact change"<<endl;
                        cout<<"Here's your Coke"<<endl;
                    }
                }
                else
                {
                    switch(action) //OK,NOINVENTORY,NOCHANGE,INSUFFICIENTFUNDS,EXACTCHANGE
                    {
                        case NOINVENTORY:
                            cout<<"\nMachine Empty...\nreturning your payment"<<endl;
                            break;
                        case NOCHANGE:
                            cout<<"\nUnable to give change at this time...\nreturning your payment"<<endl;
                            break;
                        case INSUFFICIENTFUNDS:
                            cout<<"\nInsufficent payment...\nreturning your payment"<<endl;
                            break;
                        case TOOMUCHCHANGE:
                            cout<<"\nChange box is full - call 1800IMFULL to get change removed...\nreturning your payment"<<endl;
                            break;
                        default:
                            cout<<"\nCoke Machine is out of order"<<endl;
                    }
                }
                break;
            case 2: //Restock Machine
                cout<<"\nHow much product are you adding to the machine? ";
                cin>>addproduct;
                inventorycheck = MyCokeMachine.incrementInventory(addproduct);
                if(inventorycheck == 0) //bool is only able to be 1 or 0
                {
                    cout<<"You have exceeded your machine's max inventory capacity"<<endl;
                }
                else
                {
                    cout<<"Your machine has been restocked"<<endl;
                }
                cout<<"Your inventory level is now "<<MyCokeMachine.getInventoryLevel()<<endl;
                break;
            case 3: //Add Change
                cout<<"\nHow much change are you adding to the machine? ";
                cin>>addchange;
                changecheck = MyCokeMachine.incrementChangeLevel(addchange);
                if(changecheck == 0)
                {
                    cout<<"You have exceeded your machine's max change capacity"<<endl;
                }
                else
                {
                    cout<<"Your machine change has been updated"<<endl;
                }
                cout<<"Your change level is now "<<MyCokeMachine.getChangeLevel()<<endl;
                break;
            case 4: //Display Machine Info
                cout<<"\nCurrent Inventory Level\t"<<MyCokeMachine.getInventoryLevel()<<endl;
                cout<<"Max Inventory Capacity\t"<<MyCokeMachine.getMaxInventoryCapacity()<<endl;

                cout<<"\nCurrent Change Level\t"<<MyCokeMachine.getChangeLevel()<<endl;
                cout<<"Max Change Capacity\t"<<MyCokeMachine.getMaxChangeCapacity()<<endl;

                cout<<"\nCurrent Coke Price\t"<<MyCokeMachine.getCokePrice()<<endl;
                break;
        }
    }
    while(choice != 0);
} 
