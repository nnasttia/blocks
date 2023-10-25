#include <iostream>
#include <string>
#include <cmath>
#include <list>
using namespace std;
//string alphabeth = "אבגד´הו÷זחט³¿יךכלםמןנסעףפץצקרשü‏ÿ abcdefghijklmnopqrstuvwyz";
string alphabeth = "abcdefghijklmnopqrstuvwyz";
string vigener_code(string text, string key) {
    string c = "";
    int len_alphabeth = alphabeth.size(); 
    int len_key = key.size();
    for (int i = 0; i < text.size(); i++) {
        int sum1 = alphabeth.find(tolower(text[i])) + alphabeth.find(key[i % len_key]);
        int n = sum1 % len_alphabeth;
        c += alphabeth[n];
    }
    return c; 
}

string vigener_decode(string c, string key) {
    string p = "";
    int len_c = c.size();
    int len_alphabeth = alphabeth.size();
    int len_key = key.size();
    for (int i = 0; i < len_c; i++) {
        int sum1 = alphabeth.find(tolower(c[i])) + len_alphabeth - alphabeth.find(key[i % len_key]);
        int n = sum1 % len_alphabeth;
        p += alphabeth[n];
    }
    return p; 
}
string scital_code(string text, int key) {
    string result = ""; 
    int len_text = text.size();  
    int n = len_text / key + (len_text % key > 0 ? 1 : 0);
    int s = len_text % key;
    char *mas = new char[len_text];
    for (int i = 0; i < len_text; i++) {
        int p = 0;
        if (i % key < s) {
            p = (i % key) * n + (i / key); 
        }
        else{
            p = s * n + (i / key) + (i % key - s) * (n - 1);
        }
        mas[p] = text[i];
    }
    for (int i = 0; i < len_text;i++) {
        result.push_back(mas[i]);
    }
    delete[] mas; 
    return result; 
}
string scital_decode(string text, int key) {
    string result = "";
    int len_text = text.size();
    int n = len_text / key + (len_text % key > 0 ? 1 : 0);
    int s = len_text % key;
    char* mas = new char[len_text];
    for (int i = 0; i < len_text; i++) {
        int p = 0;
        if (i < s * n) {
            p = (i % n) * key + (i / n);
        }
        else {
            int t = (i - s * n);
            p = s + t / (n - 1) + (t % (n - 1)) * key;
        }
        mas[p] = text[i];
    }
    for (int i = 0; i < len_text; i++) {
        result.push_back(mas[i]);
    }
    delete[] mas;
    return result;
}


int main() {
    
    cout << "Vigener code" << endl;
    cout << "Enter a coding word: ";
    string a = "";
    cin >> a; 
    cout << "Enter a key: ";
    string b = ""; 
    cin >> b; 
    string code_result = vigener_code(a, b);
    cout << "Code result: " << code_result<<endl;
    string decode_result = vigener_decode(code_result, b);
    cout << "Decode result: " << decode_result<<endl;
    cout << "Scital code" << endl;
    cout << "Enter a coding word: ";
    string c = "";
    cin >> c; 
    cout << "Enter a number of terms: ";
    int k = 0;
    cin >> k;
    string scital_result = scital_code(c, k);
    cout << "Code result: " << scital_result<<endl;
    string scital_decode_result = scital_decode(scital_result, k);
    cout << "Decode result: " << scital_decode_result << endl;

}