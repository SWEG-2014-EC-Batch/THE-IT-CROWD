#include <iostream>
using namespace std;

void discountCalculator(double &price, double discount, bool discountType);

int main(){
    double price, discount;
    bool discountType;
    discountCalculator(price, discount, discountType);
    if(price>0){
        cout<<"the discount price is "<<price<<endl;
    }
    return 0;
}

void discountCalculator(double &price, double discount, bool discountType){
    if(discountType==1){
        price=price-price*discount;
    }
    else{
        price=price-price*discount;
    }
}