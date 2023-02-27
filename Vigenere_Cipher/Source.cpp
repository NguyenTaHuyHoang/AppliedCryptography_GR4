#include <string>
#include <iostream>
#include <vector>

using namespace std;

#define N 26

string vigenere_cipher_enc(string key, string message);
string vigenere_cipher_dec(string key, string encrypted_message);

int main() {
	string m = "dangdatthuanhoangtuan", k = "thinh", e_m = "";
	cout << " Original message: " << m << endl;
	e_m = vigenere_cipher_enc(k, m);
	cout << "Encrypted message: " << e_m << endl;
	m = vigenere_cipher_dec(k, e_m);
	cout << "Decrypted message: " << m << endl;
	return 0;
}

vector<int> to_ascii(string key) {

	vector<int> num_keys;

	for (auto& ch : key) {
		num_keys.push_back(int(ch) - 97);
	}
	return num_keys;
}

string vigenere_cipher_enc(string key, string message) {
	vector<int> num_keys = to_ascii(key);
	int num_block = key.length();

	vector<string> plaintexts;
	vector<int> ascii_message = to_ascii(message);
	
	for (int i = 0; i < message.length(); i += num_block) {
		for (int j = 0; j < num_block; j++) {
			if (i + j > message.length()) {
				break;
			}
			ascii_message[i + j] = (ascii_message[i + j] + num_keys[j]) % N;
		}
	}
	
	string encrypted_message;
	for (auto& ascii : ascii_message) {
		encrypted_message += char(ascii + 97);
	}

	return encrypted_message;
}

string vigenere_cipher_dec(string key, string encrypted_message) {
	vector<int> num_keys = to_ascii(key);
	int num_block = key.length();

	vector<string> plaintexts;
	vector<int> ascii_message = to_ascii(encrypted_message);

	for (int i = 0; i < encrypted_message.length(); i += num_block) {
		for (int j = 0; j < num_block; j++) {
			if (i + j > encrypted_message.length()) {
				break;
			}
			ascii_message[i + j] = (ascii_message[i + j] - num_keys[j] + 26) % N;
		}
	}

	string message;
	for (auto& ascii : ascii_message) {
		message += char(ascii + 97);
	}

	return message;
}