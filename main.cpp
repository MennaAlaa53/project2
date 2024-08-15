#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void encryptFile(const string& filePath, int key) {
    ifstream inputFile(filePath, ios::binary);
    ofstream outputFile(filePath + ".kashira", ios::binary);

    char ch;
    while (inputFile.get(ch)) {
        outputFile.put(ch + key);
    }

    inputFile.close();
    outputFile.close();
}

void decryptFile(const string& filePath, int key) {
    ifstream inputFile(filePath, ios::binary);
    ofstream outputFile(filePath.substr(0, filePath.find(".kashira")), ios::binary);

    char ch;
    while (inputFile.get(ch)) {
        outputFile.put(ch - key);
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    string filePath;
    int choice, key;

    cout << "Enter the file path: ";
    cin >> filePath;
    cout << "Enter the key for encryption/decryption: ";
    cin >> key;
    cout << "Choose 1 to Encrypt or 2 to Decrypt: ";
    cin >> choice;

    if (choice == 1) {
        encryptFile(filePath, key);
        cout << "File encrypted successfully!" << endl;
    } else if (choice == 2) {
        decryptFile(filePath, key);
        cout << "File decrypted successfully!" << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}