#ifndef Code3_H
#define Code3_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

enum ACTION
{
    OK,NOINVENTORY,NOCHANGE,INSUFFICIENTFUNDS,EXACTCHANGE,TOOMUCHCHANGE
};

class CokeMachine
{
	public:
		CokeMachine(std::string name, int cost, int change, int inventory)
		:machineName{name},CokePrice{cost},changeLevel{change},inventoryLevel{inventory}
		{
		}
		
		std::string getMachineName()
		{
			return machineName;
		}
		
		bool buyACoke(int payment, std::string &change, int &action)
		{
			if(payment < CokePrice)
			{
				action = INSUFFICIENTFUNDS;
				return 0;
			}
			else if (changeLevel == 0 || (payment-CokePrice)>changeLevel)
			{
				action = NOCHANGE;
				return 0;
			}
			else if(changeLevel == maxChangeCapacity)
			{
				action = TOOMUCHCHANGE;
				return 0;
			}
			else if(inventoryLevel == 0)
			{
				action = NOINVENTORY;
				return 0;
			}
			else if(payment == CokePrice)
			{
				action = EXACTCHANGE;
				changeLevel = changeLevel + CokePrice;
				inventoryLevel--;
				return 1;
			}
			else
			{
				action = OK;
				payment = payment - CokePrice;
				changeLevel = changeLevel + CokePrice;
				inventoryLevel--;
				change = displayMoney(payment);
				return 1;
			}
		return 0;
		}
		
		int getInventoryLevel()
		{
			return inventoryLevel;
		}
		
		int getMaxInventoryCapacity()
		{
			return maxInventoryCapacity;
		}
		
		bool incrementInventory(int amountToAdd)
		{
			if((inventoryLevel+amountToAdd) > maxInventoryCapacity)
			{
				inventoryLevel = maxInventoryCapacity;
				return 0;
			}
			else
			{
				inventoryLevel = inventoryLevel + amountToAdd;
				return 1;
			}
			return 0;
		}
		
		std::string getChangeLevel()
		{
			return displayMoney(changeLevel);
		}
		
		bool incrementChangeLevel(int amountToAdd)
		{
			if((changeLevel+amountToAdd) > maxChangeCapacity)
			{
				changeLevel = maxChangeCapacity;
				return 0;
			}
			else
			{
				changeLevel = changeLevel + amountToAdd;
				return 1;
			}
			return 0;
		}
		
		std::string getMaxChangeCapacity()
		{
			return displayMoney(maxChangeCapacity);
		}
		
		std::string getCokePrice()
		{
			return displayMoney(CokePrice);
		}
		
		std::string displayMoney(int amount)
		{
			std::string dollars{std::to_string(amount/100)};
			std::string cents{std::to_string(amount%100)};
			std::ostringstream moneyOs;
			moneyOs << dollars << "." << (cents.size() == 1 ? "0" : "") + cents;
			std::string money = moneyOs.str();
			
			return money;
		}
	
	private:
		std::string machineName;
		int changeLevel;
		int maxChangeCapacity{5000};
		int CokePrice;
		int inventoryLevel;
		int maxInventoryCapacity{100};
};

#endif
