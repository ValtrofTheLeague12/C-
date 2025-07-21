#include <iostream>
using namespace std;
int main(void){
	int a = 0;
	int b = 0;
	cout << "give me a number : "  << endl;
	cin >> a;
	cout << "give me second number : " << endl;
	cin >> b;
	int ty = a & b ; /*
             10 1 0 1 0 AND OPERATOR
	      1	0 0 0 1
	       ---------
	        0 0 0 0
        */
	string results = ty == a || ty == b ? "Equal" : "Non Equal";
        cout << results << endl;
	cout << "AND OPERATION : " << ty;
	int orop = a | b; /*
			     OR OPERATION  1 0 1 0
			                   0 0 0 1
					 ------------
					  1  0  1  1 -> to decimal -> 11
			     */
	cout << "\nOR Operation : " << orop << endl;
	int shitval = a << 4; 
	cout << "SHIFFTING OPERATION : " << shitval << endl;
	int xorval = 0b0001 ^ 0b1010;
	cout << "XOR VALUE " << xorval << endl;
	
	/* XOR :
	 * 1 0 1 0
	 * 0 0 0 1
	 * --------- 
	 * 1 0 1 1 -> when bit state is different then the other then its a one
	 * 
	 * 
	 * SHIFFTING : 0 0 0 1  << shift to the left means 0 0 0 1 -> 0 0 1 0 (p(2,0),p(2,1),p(2,2),p(2,3))
	 * 1 0 0 0 -> 16 (shiffted by 4 to the left)
	 * 1 0 1 0 0 0 0 -> shiffted by 4 to the left = 128 + 32 = 160
	 * 0 0 0 1 0 1 0 -> 0 0 0 0 0 1   
	 */
	int val =  ~0b1111; // 1 1 1 1
			    //
			    // 0 1 0 1
			    // 0 0 0 1
			    // -------
			    // 0 1 1 1 

        cout << val + 1 << endl;
	string name = "Yassine";
	string secret = "secrets";
	string enc = "";
	for(int i = 0;i<name.length();i++){
		int xored = (int) name[i] xor secret[i];
		cout << xored << endl;
	        xored = xored >> 3;
		cout << (char) xored << endl; 
        }
         




}
