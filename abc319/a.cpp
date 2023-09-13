#include <bits/stdc++.h>
using namespace std;

// Legendary Players

int main() {
    unordered_map<string, int> mapping;
    mapping["tourist"] = 3858;
    mapping["ksun48"] = 3679;
    mapping["Benq"] = 3658;
    mapping["Um_nik"] = 3648;
    mapping["apiad"] = 3638;
    mapping["Stonefeang"] = 3630;
    mapping["ecnerwala"] = 3613;
    mapping["mnbvmar"] = 3555;
    mapping["newbiedmy"] = 3516;
    mapping["semiexp"] = 3481;

    string name;
    cin >> name;
    cout << mapping[name] << '\n';
}
