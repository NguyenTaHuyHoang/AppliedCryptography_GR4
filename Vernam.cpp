/*
Bai 1:
------------------------------------------------
A2  |  A7  | A8  | A1  | A5  | A6  | A3  | A4  |
------------------------------------------------
0.01| 0.01 | 0.03| 0.04| 0.06| 0.15| 0.3 | 0.4 |
------------------------------------------------
  0 |  1   |                                   |
------------------------------------------------
   0.02    | 0.03| 0.04| 0.06| 0.15| 0.3 | 0.4 |
------------------------------------------------
	0      |   1 |							   |
------------------------------------------------
		0.05     | 0.04| 0.06| 0.15| 0.3 | 0.4 |
------------------------------------------------
		  1      |  0  |					   |
------------------------------------------------
			  0.09     | 0.06| 0.15| 0.3 | 0.4 |
------------------------------------------------
				1      | 0   |				   |
------------------------------------------------
					0.15     | 0.15| 0.3 | 0.4 |
------------------------------------------------
						0    |  1  |		   |
------------------------------------------------
							0.3    | 0.3 | 0.4 |
------------------------------------------------
								0  |  1  |	   |
------------------------------------------------
									0.6  | 0.4 |
------------------------------------------------
									1    |  0  |
------------------------------------------------
										1	   |
------------------------------------------------

										 +
										/\
									  /   1
									 /	   +
									/      /\
								   /	  0  \
								  /     /     \
								 /     +	   \
								/     /\        \
							   /     0  \        \
							  /    /     \        \
							 /    +       \        \
							/    / \       \        \
						   /    1   \       \        \
						 /     /     \       \        \
						/     +       \       \        \
					   0     / \       \       1        1
					 /      1   \       0       \        \
				   /       /     \       \       \        \
				 /        +       \       \       \        \
			   /         / \       0       \       \        \
			 /          0   \       \       \       \        \
		   /           /     \       \       \       \        \
		 /            /       1       \       \       \        \
	   /             +         \       \       \       \        \
	 /              / \         \       \       \       \        \
   /              0    1         \       \       \       \        \
 /				/		\		  \ 	  \	      \	      \	       \
A4			   A2		A7	 	  A8		A1	   A5	   A3	   A6

   l(f) = 0.04 x 5 + 0.01 x 7 + 0.3 x 3 + 0.4 x 1
		+ 0.06 x 4 + 0.15 x 2 + 0.01 x 7 + 0.03 x 6 = 2.36

Entropy H(X) = |log2(0.04)x0.04 + log2(0.01)x0.01 + log2(0.3)x0.3
				+ log2(0.4)x0.4 + log2(0.06)x0.06 + log2(0.15)x0.15
				+ log2(0.01)x0.01 + log2(0.03)x0.03| = 2.17434
*/
//-------------------------------
// Bai 2
//-------------------------------
#include <iostream>
#include <ctime>
using namespace std;

string keyGenerate(int size);
string vernamEncrypt(string plaintext, string key);
string vernamDecrypt(string plaintext, string key);

string keychar = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
	srand(time(NULL));
	string p = "thuantuanhoangdangdat", c = "", k = "";

	for (int i = 0; i < 20; i++)
	{
		k = keyGenerate(p.length());
		c = vernamEncrypt(p, k);
		cout << "Ciphertext[" << i << "] =\t" << c << endl;
		p = vernamDecrypt(c, k);
		cout << "Plaintext[" << i << "] =\t" << p << endl;
	}
}

string keyGenerate(int size)
{
	string key = "";
	for (int i = 0; i < size; i++)
	{
		key += keychar[rand() % keychar.length()];
	}

	return key;
}

string vernamEncrypt(string plaintext, string key)
{
	string result = "";

	for (int i = 0; i < plaintext.length(); i++)
	{
		result += char((int)plaintext[i] ^ (int)key[i]);
	}

	return result;
}

string vernamDecrypt(string ciphertext, string key)
{
	string result = "";

	for (int i = 0; i < ciphertext.length(); i++)
	{
		result += char((int)ciphertext[i] ^ (int)key[i]);
	}

	return result;
}
