#include <iostream>
#include <sstream>
#include<string>
#include<iomanip>

using namespace std;

int main(){
string item1 = "Hamburger";
double price1 = 9.9999999999;
string item2 = "Pizza";
double price2 = 11.999999999;

stringstream menu;

menu << item1 << " - $" << fixed << setprecision(4) << price1 << endl;
menu << item2 << " - $"  << fixed << setprecision(4) << price2 << endl;

cout << menu.str();
return 0;
}
