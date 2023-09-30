 

//1 - workneh
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <iomanip>
using namespace std;

struct Ingredient {
    string name;
    double quantity;
    double costPerUnit;
    double lowStockThreshold;
};

// Define structs for MenuItem, Ingredient, and PrepaidCard
struct MenuItem {
    int itemID;
    string name;
    double price;
    int quantity;
    string category;
     vector<Ingredient> ingredients;
};

struct PrepaidCard {
    int cardNumber;
    double balance;
};

struct DeliveryInfo {
    string address;
    string additionalInfo;
};

// Define a struct to represent remotely sold items
struct RemoteSoldItem {
    string itemName;
    string address;
    int quantity;
    double totalIncome;
};

// Global container for remotely sold items
vector<RemoteSoldItem> remoteSoldItems;

// Global containers for menu items, ingredients, and prepaid cards
vector<MenuItem> menu;
vector<Ingredient> ingredients;
vector<PrepaidCard> prepaidCards;

// Maps to track low stock ingredients and categorize sales
map<string, int> ingredientLowStock;
map<string, double> categorySales;

// Class to manage menu operations
class MenuManager {
public:
    void readMenuFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Could not open menu file " << filename << endl;
            return;
        }

        menu.clear(); // Clear existing menu items

        int itemID;
        string name;
        double price;
        int quantity;
        string category;

        while (file >> itemID >> name >> price >> quantity >> category) {
            MenuItem menuItem{itemID, name, price, quantity, category};
            menu.push_back(menuItem);
        }

        file.close();
    }

    void saveMenuToFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cerr << "Error: Could not open menu file " << filename << endl;
            return;
        }

        for (const MenuItem& menuItem : menu) {
            file << menuItem.itemID << " "
                 << menuItem.name << " "
                 << menuItem.price << " "
                 << menuItem.quantity << " "
                 << menuItem.category << "\n";
        }

        file.close();
    }

    void displayMenu() {
        cout << "Menu Items:\n";
        cout << "-------------------------------------------------\n";
        cout << "ID   Name             Price     Quantity   Category\n";
        cout << "-------------------------------------------------\n";

        for (const MenuItem& menuItem : menu) {
            cout << setw(4) << menuItem.itemID << " "
                      << setw(16) << menuItem.name << " "
                      << setw(8) << menuItem.price << " "
                      << setw(10) << menuItem.quantity << " "
                      << menuItem.category << "\n";
        }

        cout << "-------------------------------------------------\n";
    }

    void addMenuItem() {
    int itemID;
    string name;
    double price;
    int quantity;
    string category;
// Create a new MenuItem object
    MenuItem menuItem{itemID, name, price, quantity, category};

    Ingredient ingredient; // Create an Ingredient object
    cout << "Enter Item ID: ";
    cin >> itemID;

    // Check if the entered itemID already exists in the menu
    for (const MenuItem& menuItem : menu) {
        if (menuItem.itemID == itemID) {
            cout << "Item with the same ID already exists. Please enter a unique Item ID.\n";
            return; // Exit the function without adding the item
        }
    }

    cout << "Enter Item Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Price: ";
    cin >> price;

    cout << "Enter Quantity: ";
    cin >> quantity;

    cout << "Enter Category: ";
    cin.ignore();
    getline(cin, category);

    // Add ingredients for this menu item
    int numIngredients;
    cout << "Enter the number of ingredients for this item: ";
    cin >> numIngredients;

    for (int i = 0; i < numIngredients; ++i) {
        string ingredientName;
        double ingredientQuantity;
        double ingredientCostPerUnit;
        double ingredientLowStockThreshold;

        cout << "Enter Ingredient Name: ";
        cin.ignore();
        getline(cin, ingredientName);

        cout << "Enter Ingredient Quantity: ";
        cin >> ingredientQuantity;

        cout << "Enter Ingredient Cost Per Unit: ";
        cin >> ingredientCostPerUnit;

        cout << "Enter Ingredient Low Stock Threshold: ";
        cin >> ingredientLowStockThreshold;

        Ingredient ingredient{ingredientName, ingredientQuantity, ingredientCostPerUnit, ingredientLowStockThreshold};

        // Add the ingredient to the menu item's ingredients list
        menuItem.ingredients.push_back(ingredient);
    }

    // Add the new menu item to the menu
    menu.push_back(menuItem);

    cout << "Menu Item added successfully!\n";
}
    void decrementMenuItemQuantity(int itemID, int quantityToSubtract) {
        for (MenuItem& menuItem : menu) {
            if (menuItem.itemID == itemID) {
                if (menuItem.quantity >= quantityToSubtract) {
                    menuItem.quantity -= quantityToSubtract;
                    cout << "Quantity updated successfully!\n";
                } else {
                    cout << "Insufficient quantity in stock.\n";
                }
                return;
            }
        }
        cout << "Item not found in the menu.\n";
    }

    double loadPreviousIncome(){
        double income;
        ifstream file("sales.txt", ios::in);
        if (file.is_open()==false) {
            cerr << "Error: Could not open sales file sales.txt" << endl;
            return 0;
        }

        file >> income;
        return income;
        file.close();
    }

    // Additional functions to save and load sales and low stock data
    void saveSalesToFile(const string& filename, double totalSales, double previousIncome) {
        ofstream file(filename);
        if (!file) {
            cerr << "Error: Could not open sales file " << filename << endl;
            return;
        }
        file << totalSales+previousIncome << endl;
        file.close();
    }

    void restockMenuItem() {
        int restockItemID;
        int restockQuantity;

        cout << "Enter Item ID to Restock: ";
        cin >> restockItemID;

        cout << "Enter Quantity to Add: ";
        cin >> restockQuantity;

        for (MenuItem& menuItem : menu) {
            if (menuItem.itemID == restockItemID) {
                menuItem.quantity += restockQuantity;
                cout << "Menu item restocked successfully!\n";
                saveSalesToFile("sales.txt", -restockQuantity*menuItem.price, loadPreviousIncome());
                return;
            }
        }
        cout << "Item not found in the menu.\n";
    }
};



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


