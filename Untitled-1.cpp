#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>

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
using std::ifstream;

struct Studentas {
    string var;
    string pav;
    vector<int> paz;
    int egz;
    double galVid;
    double galMed;
};

Studentas Stud_iv(int budas);
vector<Studentas> Stud_from_file(string fname);

int main() {
    srand(time(0));
     vector<Studentas> Grupe;

    int budas;
    cout << "Pasirinkite pazymiu ivedimo buda:\n";
    cout << "1 - zinomas pazymiu skaicius\n";
    cout << "2 - nezinomas pazymiu skaicius (baigti ENTER x2)\n";
    cout << "3 - generuoti pazymius ir egzamina\n";
    cout << "4 - nuskaitytiv duomenis is failo\n";
    cin >> budas;

    if (budas==4){
        Grupe = Stud_from_file("kursiokai.txt");
    } else {
        cout << "Kiek studentu grupeje:";
        int m;
        cin >> m;
        for (int z = 0; z < m; z++)
            Grupe.push_back(Stud_iv(budas));
    }
    
    int pasirinkimas;
    cout << "\nPasirinkite galutinio balo skaiciavimo buda:\n";
    cout << "1 - vidurkis\n2 - mediana\n3 - abu\n";
    cin >> pasirinkimas;

    cout << setw(10) << left <<"Vardas" 
         << setw(15) << "Pavarde" 
         << setw(10) << "Egz.";
    if (pasirinkimas == 1 || pasirinkimas == 3)
       cout << setw(20) << "Galutinis (vid.)";
    if (pasirinkimas == 2 || pasirinkimas == 3)
        cout << setw(20) << "Galutinis (med.)";
    cout << endl;

    cout << std::string(70, '-') << endl;

    for (auto Past : Grupe) {
        cout << setw(10) << left << Past.var 
             << setw(15) << Past.pav 
             << setw(10) << Past.egz;
         if (pasirinkimas == 1 || pasirinkimas == 3)
            cout << setw(20) << fixed << setprecision(2) << Past.galVid;
        if (pasirinkimas == 2 || pasirinkimas == 3)
            cout << setw(20) << fixed << setprecision(2) << Past.galMed;
        cout << endl;
    }
}

Studentas Stud_iv(int budas) {
    Studentas pirmas;
    cout << "\n--- Naujas studentas ---\n";
    cout << "Vardas: ";
    cin >> pirmas.var;
    cout << "Pavarde: ";
    cin >> pirmas.pav;

    int sum = 0;
    int n = 0;

    if (budas == 1) {
        cout << "Kiek pazymiu turi " << pirmas.var << " " << pirmas.pav << ": ";
        cin >> n;
        for (int a = 0; a < n; a++) {
            int laik_paz;
            cout << pirmas.paz.size() + 1 << ": ";
            cin >> laik_paz;
            pirmas.paz.push_back(laik_paz);
            sum += laik_paz;
        }
    } else if (budas == 2) {
        cout << "Iveskite pazymius (baigti ENTER x2):" << endl;
        string line;
        int tuscios = 0;
        cin.ignore();
        while (true) {
            std::getline(cin, line);
            if (line.empty()) {
                tuscios++;
                if (tuscios >= 2) break;
                else continue;
            }
            tuscios = 0;
            int laik_paz;
while (true) {
    cout << a+1 << ": ";
    cin >> laik_paz;
    if (cin.fail() || laik_paz < 1 || laik_paz > 10) {
        cin.clear();                 
        cin.ignore(1000, '\n');     
        cout << "Blogas įvedimas! Įveskite pažymį nuo 1 iki 10.\n";
        continue;
    }
    pirmas.paz.push_back(laik_paz);
    sum += laik_paz;
    break;
}

        n = pirmas.paz.size();
    } else if (budas == 3) {
        cout << "Kiek pazymiu sugeneruoti " << pirmas.var << " " << pirmas.pav << ": ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            int laik_paz = rand() % 10 + 1;
            pirmas.paz.push_back(laik_paz);
            sum += laik_paz;
        }
        pirmas.egz = rand() % 10 + 1;
        cout << "Sugeneruoti pazymiai: ";
        for (auto x : pirmas.paz) cout << x << " ";
        cout << " | Egz: " << pirmas.egz << endl;
    }

    if (budas != 3) {
        cout << "Iveskite egzamino paz.: ";
        cin >> pirmas.egz;
    }

    n = pirmas.paz.size();
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

vector<Studentas> Stud_from_file(string fname) {
    ifstream fd(fname);
    vector<Studentas> grupe;
    if (!fd) {
        cout << "Nepavyko atidaryti failo: " << fname << endl;
        return grupe;
    }

    string pav, var;
    int nd, egz;

    // praleidžiam pirma eilutę (antraštę)
    string header;
    std::getline(fd, header);

    while (fd >> var >> pav) {
        Studentas st;
        st.pav = pav;
        st.var = var;

        st.paz.clear();
        int sum = 0;
        for (int i = 0; i < 5; i++) {   // visada tiksliai 5 ND
            fd >> nd;
            st.paz.push_back(nd);
            sum += nd;
        }

        fd >> egz;
        st.egz = egz;

        // galutinis pagal vidurkį
        st.galVid = (double)sum / st.paz.size() * 0.4 + egz * 0.6;

        // galutinis pagal medianą
        sort(st.paz.begin(), st.paz.end());
        double med;
        if (st.paz.size() % 2 == 0)
            med = (st.paz[st.paz.size()/2 - 1] + st.paz[st.paz.size()/2]) / 2.0;
        else
            med = st.paz[st.paz.size()/2];
        st.galMed = med * 0.4 + egz * 0.6;

        grupe.push_back(st);
    }

    return grupe;
}