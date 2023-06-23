#include <iostream>
#include <cassert>

using namespace std;

void applyDiscount(double& price, double discount, bool isPercentage) {
    assert(discount >= 0);

    if (isPercentage) {
        double discountAmount = (discount / 100) * price;
        assert(price - discountAmount > 0);
        price -= discountAmount;
    } else {
        assert(price - discount > 0);
        price -= discount;
    }
}

int main() {
    double price, discount;
    bool isPercentage;

    cout << "Enter the price of the item: ";
    cin >> price;

    cout << "Enter the discount amount: ";
    cin >> discount;

    cout << "Is the discount percentage (1 for percentage, 0 for fixed amount): ";
    cin >> isPercentage;

    applyDiscount(price, discount, isPercentage);

    cout << "Discounted price: " << price << endl;

    return 0;
}
