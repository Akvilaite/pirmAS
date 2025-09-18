#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::fixed;
using std::setprecision;

struct Studentas {
    string var;
    string pav;
    vector<int> paz;
    int egz;
    double gal;
};

Studentas Stud_iv();

int main() {
    vector<Studentas> Grupe;
    cout << "kiek studentu grupeje: ";
    int m;
    cin >> m;
    for (int z = 0; z < m; z++)
        Grupe.push_back(Stud_iv());

    cout << "Studento info:" << endl;
    for (auto Past : Grupe) {
        cout << setw(10) << left << Past.var << "I" << setw(15) << right << Past.pav;
        for (auto& a : Past.paz)
            cout << setw(3) << a << "I"
        << setw(10) << fixed << setprecision(2) << Past.gal<< endl;
    }
}

Studentas Stud_iv() {
    int n, laik_paz, sum = 0;
    cout << "sveiki" << endl;
    Studentas pirmas;
    cout << "iveskite savo duomenis" << endl;
    cout << "vardas: ";
    cin >> pirmas.var;
    cout << "pavarde: ";
    cin >> pirmas.pav;
    cout << "kiek pazymiu turi " << pirmas.var << " " << pirmas.pav << ": ";
    cin >> n;
    for (int a = 0; a < n; a++) {
        cout << a + 1 << ": ";
        cin >> laik_paz;
        pirmas.paz.push_back(laik_paz);
        sum += laik_paz;
    }
    cout << "iveskite egz paz.: ";
    cin >> pirmas.egz;
    pirmas.gal = double(sum) / double(n) * 0.4 + pirmas.egz * 0.6;
    return pirmas;
}
