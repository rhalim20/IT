#include <iostream>;
#include <string>;
#include <cstring>;	
using namespace  std;


int main() {
	//create char array

	//create int i used in loops and x which indicates our current char as an int value, n is the encryption/decryption number
	int i = 0, x = 0, n = 0;
	//boolean for use if its false
	bool done = false;
	string yesno, final, test1, cont = "C";
	//take string (create a code to take string as input)
	while (cont == "C")
	{
		cont.clear();
		test1.clear();
		yesno.clear();
		final.clear();

		cout << "Please input the string you would like to encrypt/decrypt\n";
		getline(cin, test1); //gets next line and inputs it as the test1 string
		while (!((yesno == "E" || yesno == "D") && done))
		{
			cout << "would you like to encrypt or decrypt? (E/D)\n";
			getline(cin, yesno);
			
			//if E is input it uses the following encryption code
			if (yesno == "E" || yesno == "D")
			{
				if (yesno == "E")
				{
					cout << "what is the encryption key you would like to use?\n";
					cin >> n;
					//makes n smaller 
					n = n % 26;
					//cout << n << "\n";
				}
				else if (yesno == "D")
				{
					cout << "what is the decryption key you would like to use?\n";
					cin >> n;
					n = (26 - (n % 26));
					//cout << n << "\n";

				}
				for (i = 0; i < test1.length(); i++)	//checks if the character at a given position is a null character
				{
					//sets x to the ASCII value of char
					x = test1[i];
					//checks if it is upercase using ASCII values, if not it then checks for lowercase
					if (x < 91 && x>64)
					{
						//checks if char would go out of bounds (upercase runs from 64-90)
						if (x + n > 90)

						{
							// uses the remainder function to only leave a leftover above 90 and then adds 64 to get the minimum number
							final.push_back(((x + n) % 90 + 64));
						}
						else
						{
							final.push_back(x + n);
						}

					}
					//checks if it is lowercase using ASCII values, if not then the char will be unafected
					else if (x < 123 && x > 96)
					{
						//checks if char would go out of bounds (lowercase runs from 96-122)
						if (x + n > 122)
						{
							//uses the remainder function to only leave a leftover above 122 and then adds 96 to get the minimum number
							final.push_back((x + n) % 122 + 96);
						}
						else
						{
							final.push_back(x + n);
						}

					}
					//if the ASCII value is none of the above, it is a special character of sorts and will not be affected
					else
					{
						final.push_back(x);
					}
				}
				
				
				done = true;
				break;
			}
		
			
			
			
		}
		
		
		//FIX THIS PLEASE IT SUCKS AAAA
			cout << final << "\n";
			cout << "Select an option\n (E) Exit\n (C) Continue Encrypting/Decrypting\n";
			cin >> cont;
			if (cont == "E")
			{
				exit;
			}
			cin.get();
	}
}