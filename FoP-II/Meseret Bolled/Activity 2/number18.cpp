#include <iostream>
#include <cassert>
using namespace std;

void calculateDiscount(double& price, double discount, bool isPercentage)
{
    assert(discount >= 0);
    double discountAmount;
    if (isPercentage) {
        discountAmount = (discount / 100.0) * price;
    } else {
        discountAmount = discount;
    }

    assert(price - discountAmount != 0);

    price = price - discountAmount;
}

int main()
{
    double price;
    double discount;
    bool isPercentage;

    cout << "Enter price of item: ";
    cin >> price;

    cout << "Enter discount (percentage or fixed amount): ";
    cin >> discount;

    cout << "Is the discount a percentage (1) or fixed amount (0)? ";
    cin >> isPercentage;

    calculateDiscount(price, discount, isPercentage);

    cout << "Discounted price: " << price << endl;

    return 0;
}
