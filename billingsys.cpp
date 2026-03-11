#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    float price;
    float gst;
};

int main() {

    Product products[5] = {
        {1, "Milk", 50, 5},
        {2, "Bread", 40, 5},
        {3, "Chocolate", 100, 12},
        {4, "Shampoo", 200, 18},
        {5, "Soap", 60, 12}
    };

    int choice, quantity;
    float subtotal = 0;
    float totalGST = 0;
    float totalAmount = 0;

    cout << "===== POS BILLING SYSTEM =====\n";

    while (true) {

        cout << "\nAvailable Products:\n";
        cout << left << setw(5) << "ID"
        << setw(15) << "Name"
        << setw(10) << "Price"
        << setw(5) << "GST%" << endl;

for(int i = 0; i < 5; i++) {
    cout << left << setw(5) << products[i].id
            << setw(15) << products[i].name
            << setw(10) << products[i].price
            << setw(5) << products[i].gst << endl;
}

        cout << "\nEnter Product ID (0 to finish): ";
        cin >> choice;

        if(choice == 0)
            break;

        bool found = false;

        for(int i = 0; i < 5; i++) {

            if(products[i].id == choice) {

                found = true;

                cout << "Enter Quantity: ";
                cin >> quantity;

                float price = products[i].price * quantity;
                float gstAmount = price * products[i].gst / 100;

                subtotal += price;
                totalGST += gstAmount;

                cout << "Added to cart: " << products[i].name << endl;
                cout << "Price: " << price << endl;
                cout << "GST: " << gstAmount << endl;

                break;
            }
        }

        if(!found)
            cout << "Invalid Product ID\n";
    }

    totalAmount = subtotal + totalGST;

    cout << "\n\n========= INVOICE =========\n";
    cout << fixed << setprecision(2);

    cout << "Subtotal: Rs " << subtotal << endl;
    cout << "Total GST: Rs " << totalGST << endl;
    cout << "---------------------------\n";
    cout << "TOTAL AMOUNT: Rs " << totalAmount << endl;

    cout << "\nThank You! Visit Again!\n";

    cout << "\n====== DAILY SALES SUMMARY ======\n";
    cout << "Total Sales: Rs " << totalAmount << endl;
    cout << "GST Collected: Rs " << totalGST << endl;

    return 0;
}