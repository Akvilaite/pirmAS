#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

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
using std::sort;

struct Studentas {
    string var;
    string pav;
    vector<int> paz;
    int egz;
    double galVid;
    double galMed;
};

Studentas Stud_iv();

int main() {
    vector<Studentas> Grupe;
    cout << "kiek studentu grupeje: ";
    int m;
    cin >> m;
    for (int z = 0; z < m; z++)
        Grupe.push_back(Stud_iv());
    
    int pasirinkimas;
    cout << "Pasirinkite galutinio balo skaiciavimo buda:";
    cout << "1 - vidurkis\n2 - mediana\n3 -abu";
    cin >> pasirinkimas;

    cout << setw(10) << left <<"Vardas" << setw(15) << "Pavardė";
    if (pasirinkimas == 1 || pasirinkimas == 3)
       cout << setw(25) << "Galutinis pagal vid.";
    if (pasirinkimas == 2 || pasirinkimas == 3)
        cout << setw(20) << "Galutinis pagal med.";
    cout << endl;

    cout << std::string(70, '-') << endl;

    for (auto Past : Grupe) {
        cout << setw(10) << left << Past.var << setw(15) << left << Past.pav
        << setw(10) << Past.egz;
         if (pasirinkimas == 1 || pasirinkimas == 3)
            cout << setw(25) << fixed << setprecision(2) << Past.galVid;
        if (pasirinkimas == 2 || pasirinkimas == 3)
            cout << setw(20) << fixed << setprecision(2) << Past.galMed;
        cout << endl;
    }
}
Studentas Stud_iv() {
    cout << "sveiki" << endl;
    Studentas pirmas;
    cout << "iveskite savo duomenis" << endl;
    cout << "vardas: ";
    cin >> pirmas.var;
    cout << "pavarde: ";
    cin >> pirmas.pav;
    cin.ignore();

    cout << "iveskite pazymius (baigti - du kartus ENTER):" << endl;
    string line;
    int sum = 0;  
    int tuscios = 0;

    while (true) {
        std::getline(cin, line);
        if (line.empty()) {
            tuscios++;
            if (tuscios >= 2) break;
            else continue;
        }
        tuscios = 0;
        int laik_paz = std::stoi(line);
        pirmas.paz.push_back(laik_paz);
        sum += laik_paz;
    }

    cout << "iveskite egz paz.: ";
    cin >> pirmas.egz;
    cin.ignore();
    
    int n = pirmas.paz.size();
    if (n > 0) {
        pirmas.galVid = double(sum) / double(n) * 0.4 + pirmas.egz * 0.6;

        sort(pirmas.paz.begin(), pirmas.paz.end());
        double med;
        if(n%2 == 0)
         med = (pirmas.paz[n/2 - 1] + pirmas.paz[n/2]) / 2.0;
        else
          med = pirmas.paz[n/2];
         pirmas.galMed = med * 0.4 + pirmas.egz * 0.6;
    } else {
        pirmas.galVid = pirmas.egz * 0.6;
        pirmas.galMed = pirmas.egz * 0.6;
    }

    return pirmas;
}

