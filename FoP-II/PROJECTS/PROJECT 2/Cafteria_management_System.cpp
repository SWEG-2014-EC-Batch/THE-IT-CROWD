 

//1 - workneh

//2 -  addis

//3 - messi 

//4 - siyamregn

//5 - mike

class RemoteOrderManager {
public:
    void loadRemoteSoldItemsFromFile(const string& filename, vector<RemoteSoldItem>& remoteSoldItems) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Could not open remote sold items file " << filename << endl;
            return;
        }

        remoteSoldItems.clear(); // Clear existing remote sold items

        string itemName;
        string address;
        int quantity;
        float totalIncome;

        while (file >> itemName >> address >> quantity >> totalIncome) {
            RemoteSoldItem soldItem{itemName, address, quantity, totalIncome};
            remoteSoldItems.push_back(soldItem);
        }

        file.close();
    }

    void saveRemoteSoldItemsToFile(const string& filename, const vector<RemoteSoldItem>& remoteSoldItems) {
        ofstream file(filename);
        if (!file) {
            cerr << "Error: Could not open remote sold items file " << filename << endl;
            return;
        }

        for (const RemoteSoldItem& soldItem : remoteSoldItems) {
            file << soldItem.itemName << " " << soldItem.address << " " << soldItem.quantity << " "<<soldItem.totalIncome<<"\n";
            BusinessManager businessManager;
            businessManager.saveSalesToFile("sales.txt", soldItem.totalIncome, businessManager.loadPreviousIncome());
        }

        file.close();
    }

    void remoteOrder(PrepaidCardManager& prepaidCardManager) {
        string itemName;
        string address;
        int quantity;
        int cardNumber;
        double totalPrice;

        cout << "Available Menu Items:\n";
        MenuManager menuManager;
        menuManager.displayMenu(); // Display the menu

        cout << "Enter Prepaid Card Number: ";
        cin >> cardNumber;

        // Find the prepaid card
        PrepaidCard* card = prepaidCardManager.findPrepaidCard(cardNumber);
        if (card != nullptr) {
            cout << "Enter Item Name for Remote Order: ";
            cin.ignore();
            getline(cin, itemName);

            cout << "Enter Delivery Address: ";
            getline(cin, address);

            cout << "Enter Quantity: ";
            cin >> quantity;
            for (const MenuItem& menuItem : menu) {
                if (menuItem.name == itemName) {
                    totalPrice = quantity*menuItem.price;
                }
                if(itemName=="Cheeseburger"){
                   ingredients[0].quantity-=quantity; ingredients[2].quantity-=quantity;
                   ingredients[3].quantity-=quantity; ingredients[4].quantity-=quantity;
                   ingredients[7].quantity-=quantity;
                }
                if(itemName=="Spaggeti"){
                    ingredients[0].quantity-=quantity; ingredients[1].quantity-=quantity;
                    ingredients[2].quantity-=quantity; ingredients[3].quantity-=quantity;
                    ingredients[6].quantity-=quantity;
                }
                if(itemName=="Beefsoup"){
                   ingredients[0].quantity-=quantity; ingredients[2].quantity-=quantity;
                   ingredients[3].quantity-=quantity; ingredients[4].quantity-=quantity;
                }
                if(itemName=="Vegansoup"){
                   ingredients[0].quantity-=quantity; ingredients[2].quantity-=quantity;
                   ingredients[3].quantity-=quantity; ingredients[5].quantity-=quantity;
                }
            }

            // Check if the item exists in the menu
            bool itemFound = false;
            for (const MenuItem& menuItem : menu) {
                if (menuItem.name == itemName) {
                    itemFound = true;
                    // Check if there is enough quantity in stock
                    if (menuItem.quantity >= quantity) {
                        // Check if the card has enough balance
                        if (card->balance >= menuItem.price * quantity) {
                            // Process the order, decrement the menu item quantity, and update the card balance
                            MenuManager menuManager;  // Create an instance of MenuManager
                            menuManager.decrementMenuItemQuantity(menuItem.itemID, quantity);
                            RemoteSoldItem soldItem{itemName, address, quantity, totalPrice};
                            remoteSoldItems.push_back(soldItem);
                            card->balance -= menuItem.price * quantity;
                            cout << "Order placed successfully!\n";
                            return;
                        } else {
                            cout << "Insufficient balance on the prepaid card.\n";
                            return;
                        }
                    } else {
                        cout << "Insufficient quantity in stock.\n";
                        return;
                    }
                }
            }

            if (!itemFound) {
                cout << "Item not found in the menu.\n";
            }
        } else {
            cout << "Prepaid card not found.\n";
        }
    }

    void displayRemoteSoldItems(const vector<RemoteSoldItem>& remoteSoldItems) {
        cout << "Remote Sold Items:\n";
        cout << "------------------------------------------------------------\n";
        cout << "Item Name        Delivery Address   Quantity     total price\n";
        cout << "------------------------------------------------------------\n";

        for (const RemoteSoldItem& soldItem : remoteSoldItems) {
            cout << setw(8) << soldItem.itemName << " "
                      << setw(16) << soldItem.address << " "
                      << setw(8) << soldItem.quantity << " "
                      << setw(16) << soldItem.totalIncome << "\n";
        }

        cout << "-----------------------------------\n";
    }
};




//6 - addis 2 

//7 - siyamgrn 2


