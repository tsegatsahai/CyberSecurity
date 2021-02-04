#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <math.h>

using namespace std;

long long int modCalculator( long long int a, long long int b,long long int c );
int main()
{
	//Key Information//
	long long int d = 214447; //encryption key 
	long long int e = 501631; //decryption key
	long long int N = 1618711;
	
	string fileName;
	char letter, answer;
	vector <long long int> text;
	ifstream myFile;
	ofstream myFiles; 
	
	cout << "Please insert 'E' for encryption or 'D' for decryption: ";
	cin >> answer;
	if(answer == 'E' || answer == 'e')
		{
			cout << "Please insert a text file to encrypt: " ;
			cin >> fileName; 
			myFile.open(fileName);
			if(!myFile)
				{
					throw runtime_error("Could not open file");
				}
			//add the data read from the file to a vector
			while (myFile >> letter) 
				{
					text.push_back(tolower(letter));
				}
			vector<long long int>::iterator it = text.begin();
			myFiles.open("cipherText1.txt");
			if(!myFiles)
				{
					throw runtime_error("Could not open file");
				}
			//iterate through the vector and encrypt each character and write it to the file cipherText1.txt
			while(it != text.end())
				{
					myFiles << modCalculator(*it, d ,N) <<  '\t';
					++it;
				}	
			cout << "success!"<<endl;
			myFiles.close();
		}
	else if (answer == 'D' || answer == 'd')
		{
			long long int num = 0;
			cout << "Please insert a text file to decrypt: " ;
			cin >> fileName; 
			myFile.open(fileName);
			if(!myFile)
				{
					throw runtime_error("Could not open file");
				}
			while (myFile >> num) 
				{
					text.push_back(num);
				}
			myFiles.open("plainText1.txt");
			if(!myFiles)
				{
					throw runtime_error("Could not open file");
				}
			vector<long long int>::iterator it = text.begin();
			//iterate through the vector and decrypt each long int and write it to the file cipherText1.txt
			while(it != text.end())
				{
					myFiles <<  char(modCalculator(*it, e ,N));
					++it;
				}	
			cout << "success!"<< endl;
			myFiles.close();
		}
}

// to calculate a^b mod c
long long int modCalculator( long long int a, long long int b,long long int c )      
{
   long long int result = 1;
   while( b > 0 )
	   {
		   result *= a;
		   result %= c;
		   b--;
		}
   return result;
}