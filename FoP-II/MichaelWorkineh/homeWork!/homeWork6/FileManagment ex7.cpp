#include <iostream>
#include <fstream>
#include <iomanip> // Include the <iomanip> header for setw and setprecision
#include <cstring>

using namespace std;

struct Tool {
    char toolName[30];
    int quantity;
    double cost;
};

void addTool(fstream& file) {
    Tool tool;

    cout << "Enter tool name: ";
    cin.ignore();
    cin.getline(tool.toolName, 30);

    cout << "Enter quantity: ";
    cin >> tool.quantity;

    cout << "Enter cost: ";
    cin >> tool.cost;

    int recordNum = -1;
    for (int i = 0; i < 100; i++) {
        Tool tempTool;
        file.seekg(i * sizeof(Tool));
        file.read(reinterpret_cast<char*>(&tempTool), sizeof(Tool));
        if (file.eof()) {
            recordNum = i;
            break;
        }
    }

    if (recordNum != -1) {
        file.seekp(recordNum * sizeof(Tool));
        file.write(reinterpret_cast<const char*>(&tool), sizeof(Tool));
        cout << "Tool added successfully with record number: " << recordNum << endl;
    } else {
        cout << "Inventory is full. Cannot add more tools." << endl;
    }
}

void displayTools(fstream& file) {
    Tool tool;
    file.seekg(0, ios::beg);

    cout << "------------------------------------" << endl;
    cout << "record | toolname          | quantity | cost" << endl;
    cout << "------------------------------------" << endl;

    while (file.read(reinterpret_cast<char*>(&tool), sizeof(Tool))) {
        if (tool.quantity != 0) {
            cout << " " << setw(6) << file.tellg() / sizeof(Tool) - 1 << " | "
                      << setw(18) << tool.toolName << " | "
                      << setw(8) << tool.quantity << " | "
                      << fixed << setprecision(2) << setw(5) << tool.cost << endl;
        }
    }

    cout << "------------------------------------" << endl;
}

void deleteTool(fstream& file) {
    int recordNum;
    cout << "Enter the record number of the tool to delete: ";
    cin >> recordNum;

    Tool tool;
    file.seekg(recordNum * sizeof(Tool));
    file.read(reinterpret_cast<char*>(&tool), sizeof(Tool));

    if (file) {
        tool.quantity = 0;
        file.seekp(recordNum * sizeof(Tool));
        file.write(reinterpret_cast<const char*>(&tool), sizeof(Tool));
        cout << "Tool with record number " << recordNum << " has been deleted." << endl;
    } else {
        cout << "Tool with record number " << recordNum << " does not exist." << endl;
    }
}

void updateTool(fstream& file) {
    int recordNum;
    cout << "Enter the record number of the tool to update: ";
    cin >> recordNum;

    Tool tool;
    file.seekg(recordNum * sizeof(Tool));
    file.read(reinterpret_cast<char*>(&tool), sizeof(Tool));

    if (file) {
        cout << "Enter new quantity: ";
        cin >> tool.quantity;

        cout << "Enter new cost: ";
        cin >> tool.cost;

        file.seekp(recordNum * sizeof(Tool));
        file.write(reinterpret_cast<const char*>(&tool), sizeof(Tool));
        cout << "Tool with record number " << recordNum << " has been updated." << endl;
    } else {
        cout << "Tool with record number " << recordNum << " does not exist." << endl;
    }
}

int main() {
    fstream file("files/hardware.dat", ios::in | ios::out | ios::binary);

    if (!file) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    Tool emptyTool;
    memset(&emptyTool, 0, sizeof(Tool));

    for (int i = 0; i < 100; i++) {
        file.write(reinterpret_cast<const char*>(&emptyTool), sizeof(Tool));
    }

    int choice;
    do {
        cout << "Inventory Management System" << endl;
        cout << "1. Add a tool" << endl;
        cout << "2. Display all tools" << endl;
        cout << "3. Delete a tool" << endl;
        cout << "4. Update a tool" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTool(file);
                break;
            case 2:
                displayTools(file);
                break;
            case 3:
                deleteTool(file);
                break;
            case 4:
                updateTool(file);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 5);

    file.close();
    return 0;
}
