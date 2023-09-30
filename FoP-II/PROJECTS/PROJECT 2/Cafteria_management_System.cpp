 

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
class IngredientManager {
public:
    void readIngredientsFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Could not open ingredients file " << filename << endl;
            return;
        }

        ingredients.clear(); // Clear existing ingredients

        string name;
        double quantity;
        double costPerUnit;
        double lowStockThreshold;

        while (file >> name >> quantity >> costPerUnit >> lowStockThreshold) {
            Ingredient ingredient{name, quantity, costPerUnit, lowStockThreshold};
            ingredients.push_back(ingredient);
        }

        file.close();
    }

    void saveIngredientsToFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cerr << "Error: Could not open ingredients file " << filename << endl;
            return;
        }

        for (const Ingredient& ingredient : ingredients) {
            file << ingredient.name << " "
                 << ingredient.quantity << " "
                 << ingredient.costPerUnit << " "
                 << ingredient.lowStockThreshold << "\n";
        }

        file.close();
    }

    void displayIngredients() {
        cout << "Ingredients:\n";
        cout << "------------------------------------------------\n";
        cout << "Name            Quantity   Cost/Unit   Low Stock\n";
        cout << "------------------------------------------------\n";

        for (const Ingredient& ingredient : ingredients) {
            cout << setw(16) << ingredient.name << " "
                      << setw(10) << ingredient.quantity << " "
                      << setw(10) << ingredient.costPerUnit << " "
                      << setw(10) << ingredient.lowStockThreshold << "\n";
        }

        cout << "------------------------------------------------\n";
    }

    void addIngredient() {
        string name;
        double quantity;
        double costPerUnit;
        double lowStockThreshold;

        cout << "Enter Ingredient Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Cost Per Unit: ";
        cin >> costPerUnit;

        cout << "Enter Low Stock Threshold: ";
        cin >> lowStockThreshold;

        Ingredient ingredient{name, quantity, costPerUnit, lowStockThreshold};
        ingredients.push_back(ingredient);

        cout << "Ingredient added successfully!\n";
    }

    void restockIngredients() {
        string name;
        double quantityToAdd;

        cout << "Enter Ingredient Name to Restock: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Quantity to Add: ";
        cin >> quantityToAdd;

        for (Ingredient& ingredient : ingredients) {
            if (ingredient.name == name) {
                ingredient.quantity += quantityToAdd;
                cout << "Ingredient restocked successfully!\n";
                return;
            }
        }

        cout << "Ingredient not found.\n";
    }
};




//3 - messi 
class PrepaidCardManager {
public:
    void readPrepaidCardsFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Could not open prepaid cards file " << filename << endl;
            return;
        }

        prepaidCards.clear(); // Clear existing prepaid cards

        int cardNumber;
        double balance;

        while (file >> cardNumber >> balance) {
            PrepaidCard card{cardNumber, balance};
            prepaidCards.push_back(card);
        }

        file.close();
    }

    void savePrepaidCardsToFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cerr << "Error: Could not open prepaid cards file " << filename << endl;
            return;
        }

        for (const PrepaidCard& card : prepaidCards) {
            file << card.cardNumber << " " << card.balance << "\n";
        }

        file.close();
    }

    void displayPrepaidCards() {
        cout << "Prepaid Cards:\n";
        cout << "----------------------\n";
        cout << "Card Number   Balance\n";
        cout << "----------------------\n";

        for (const PrepaidCard& card : prepaidCards) {
            cout << setw(12) << card.cardNumber << " "
                      << setw(8) << card.balance << "\n";
        }

        cout << "----------------------\n";
    }

    void addPrepaidCard() {
        int cardNumber;
        double balance;

        cout << "Enter Card Number: ";
        cin >> cardNumber;

        cout << "Enter Initial Balance: ";
        cin >> balance;

        PrepaidCard card{cardNumber, balance};
        prepaidCards.push_back(card);

        cout << "Prepaid Card added successfully!\n";
    }

    void rechargePrepaidCard() {
        int cardNumber;
        int balance;

        cout << "Enter card number to Recharge: ";
        cin >> cardNumber;

        cout << "Enter the amount of money you want to Add: ";
        cin >> balance;

        for (PrepaidCard& prepaidCard : prepaidCards) {
            if (prepaidCard.cardNumber == cardNumber) {
                prepaidCard.balance += balance;
                cout << "card recharged successfully!\n";
                return;
            }
        }
        cout << "Item not found in the menu.\n";
    }

    PrepaidCard* findPrepaidCard(int cardNumber) {
        for (PrepaidCard& card : prepaidCards) {
            if (card.cardNumber == cardNumber) {
                return &card; // Return a pointer to the found card
            }
        }
        return nullptr; // Card not found
    }
};


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
// Function to handle menu operations
void menuOperations(MenuManager& menuManager) {
    int menuChoice;
    do {
        cout << "\nMenu Operations:\n";
        cout << "1. Display Menu\n";
        cout << "2. Add Menu Item\n";
        cout << "3. Restock Menu Item\n";
        cout << "4. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> menuChoice;

        switch (menuChoice) {
            case 1:
                menuManager.displayMenu();
                break;
            case 2:
                menuManager.addMenuItem();
                menuManager.saveMenuToFile("menu.txt");
                break;
            case 3:
                menuManager.restockMenuItem();
                menuManager.saveMenuToFile("menu.txt");
                break;
            case 4:
                cout << "Returning to the main menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (menuChoice != 4);
}

// Function to handle ingredient operations
void ingredientOperations(IngredientManager& ingredientManager) {
    int ingredientChoice;
    do {
        cout << "\nIngredient Operations:\n";
        cout << "1. Display Ingredients\n";
        cout << "2. Add Ingredient\n";
        cout << "3. Restock Ingredients\n";
        cout << "4. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> ingredientChoice;

        switch (ingredientChoice) {
            case 1:
                ingredientManager.displayIngredients();
                break;
            case 2:
                ingredientManager.addIngredient();
                ingredientManager.saveIngredientsToFile("ingredients.txt");
                break;
            case 3:
                ingredientManager.restockIngredients();
                ingredientManager.saveIngredientsToFile("ingredients.txt");
                break;
            case 4:
                cout << "Returning to the main menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (ingredientChoice != 4);
}

// Function to handle prepaid card operations
void prepaidCardOperations(PrepaidCardManager& prepaidCardManager) {
    int cardChoice;
    do {
        cout << "\nPrepaid Card Operations:\n";
        cout << "1. Display Prepaid Cards\n";
        cout << "2. Add Prepaid Card\n";
        cout << "3. to recharge Prepaid cards\n";
        cout<<  "4. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> cardChoice;

        switch (cardChoice) {
            case 1:
                prepaidCardManager.displayPrepaidCards();
                break;
            case 2:
                prepaidCardManager.addPrepaidCard();
                prepaidCardManager.savePrepaidCardsToFile("prepaid_cards.txt");
                break;
            case 3:
                prepaidCardManager.rechargePrepaidCard();
                prepaidCardManager.savePrepaidCardsToFile("prepaid_cards.txt");
            case 4:
                cout << "Returning to the main menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (cardChoice != 4);
}

// Function to handle business operations
void performBusinessOperations() {
    BusinessManager businessManager;
    RemoteOrderManager remoteOrderManager;
    double totalSales = 0.0;
    int businessChoice;

    do {
        cout << "\nBusiness Operations:\n";
        cout << "1. Calculate Sales\n";
        cout << "2. Display Remote Sold Items\n";
        cout << "3. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> businessChoice;

        switch (businessChoice) {
            case 1:
                businessManager.loadSalesFromFile("sales.txt", totalSales);
                cout << "----------------------\n";
                cout << "Current Capital\n";
                cout << "----------------------\n";
                cout<<totalSales<<endl;
                totalSales=0;
                cout << "----------------------\n";

                businessManager.saveSalesToFile("sales.txt", totalSales, businessManager.loadPreviousIncome());
                break;
            case 2:
                remoteOrderManager.loadRemoteSoldItemsFromFile("remote_sold_items.txt", remoteSoldItems);
                remoteOrderManager.displayRemoteSoldItems(remoteSoldItems);
                break;
            case 3:
                cout << "Returning to the main menu...\n";

                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
            cout<<endl;
        }
    } while (businessChoice != 3);
}

// Function to run the main menu
void runMainMenu(MenuManager& menuManager, IngredientManager& ingredientManager, PrepaidCardManager& prepaidCardManager, BusinessManager& businessManager, RemoteOrderManager& remoteOrderManager, double& totalSales) {
    int mainChoice;

    do {
        system("cls");
        cout << "\nMain Menu:\n";
        cout << "1. Menu Operations\n";
        cout << "2. Ingredient Operations\n";
        cout << "3. Prepaid Card Operations\n";
        cout << "4. Remote Order\n";
        cout << "5. Business Operations\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                system("cls");
                menuOperations(menuManager);
                break;
            case 2:
                system("cls");
                ingredientOperations(ingredientManager);
                break;
            case 3:
                system("cls");
                prepaidCardOperations(prepaidCardManager);
                break;
            case 4:
                system("cls");
                remoteOrderManager.remoteOrder(prepaidCardManager);
                menuManager.saveMenuToFile("menu.txt");
                remoteOrderManager.saveRemoteSoldItemsToFile("remote_sold_items.txt", remoteSoldItems);
                break;
            case 5:
                system("cls");
                // Call the business operations function
                performBusinessOperations();
                break;
            case 6:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (mainChoice != 6);
}



//7 - siyamgrn 2


