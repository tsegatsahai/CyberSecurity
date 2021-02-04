#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

bool primeNum(long long int num);
long long int gcdFinder(long long int x, long long int y);
long long int extendedGcd(long long int a, long long int b, long long int *x, long long int *y);
long long int publicKeyGeneration(long long int a);
long long int privateKeyGeneration(long long int a, long long int b);
int main()
{
   long long int p, q, N, z, e, d;
	srand(time(0));
	//pick a random number 
	long long int ran = rand()% 1800 + 200;
	while(!primeNum(ran))
		{ 
			ran = rand()% 1800+ 200;
		}
	p = ran;
	ran = rand()% 1800 + 200;
	while(!primeNum(ran) || ran == p)
		{ 
			ran = rand()% 1800 + 200;
		}
	q = ran;
	N = q * p;
	z = (q-1)*(p-1);
	cout << "p: " <<p << "  q: " << q << " N: "<< N<< " z: "<< z <<endl;
	e = publicKeyGeneration(z);
	d = privateKeyGeneration(e, z);
	cout << "Pub key: " << e << "," << N << endl; 
	cout << "Priv key: " << d << "," << N << endl;
	return 0;
}

//to check if our number is a prime number
bool primeNum(long long int num)
{
	long long int n = sqrt(num);
	for(int i=2; i<=n; i++)
		{
			if(num%i == 0){return false;}
		}
	return true; 
}
//using the Euclidean algorithm to find the gcd of two numbers
long long int gcdFinder(long long int x, long long int y)
{
	
	long long int c, a, b;
	a = max(x, y);
	b = min(x, y);
	c = a%b;
	while(c != 0)
		{
			a = b;
			b = c;
			c = a%b;
		}
	return b; 
}
//using the extended Euclidean algorithm to help us generate the private key
long long int extendedGcd(long long int a, long long int b, long long int *x, long long int *y)
{
	if (a == 0)
		{
			*x = 0, *y = 1; 
			return b;
		} 
  
    long long int x1, y1; 
    long long int gcd = extendedGcd(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}
long long int publicKeyGeneration(long long int a) //a= z
{
	//pick a rand number between 1 and a
	long long int e= rand()% a + 1;
	//if the rand number is one or if it is not relatively prime with a, generate another rand number
	while( e == 1 || gcdFinder(e, a) > 1)
		{ 
			e = rand()% a + 1;
		}
	return e;
}
long long int privateKeyGeneration(long long int a, long long int b) //a=e, b=z
{
	long long int r,s;
	long long int gcd = extendedGcd(a, b, &r, &s);
	if(gcd != 1){cout << "failed to generate private key"<< endl;}
	else{
			long long d = (r%b +b)%b;
			return d;
		}
}

