#include <iostream>
using namespace std;

void discountCalculator(double &price, double discount, bool discountType);

int main(){
    double price, discount;
    bool discountType;
<<<<<<< HEAD
=======
    cout<<"enter the price"<<endl;
cin>>price;
cout<<"enter the discount rate"<<endl;
cin>>discount;
cout<<"type 1 if the discount is in percentage and type 2 if not"<<endl;
cin>>discountType;
>>>>>>> ccd727f092856b0ef50838f5c061b8ce421d5b9b
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
<<<<<<< HEAD
}
=======
}
>>>>>>> ccd727f092856b0ef50838f5c061b8ce421d5b9b
