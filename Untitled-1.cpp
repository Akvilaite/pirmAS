// Example program
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

//using namespace std;
//cout<<"sveiki";

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;

//int main(){
//    cout<<"sveiki"<<endl;

struct Studentas{
    string var;
    string pav;
    vector <int> paz;
    int egz;
    double gal;
    };
Studentas Stud_iv();

int main (){
    vector<Studentas> Grupe;
    cout<<"kiek studentu grupeje";
    int m; cin>m;
    for (auto z=0; z<n; z++)
        Grupe.push_back(Stud_iv());
    cout<<"Studento info:"<<endl;
    for (auto Past:Grupe)
    {
    cout<< setw(10)<<left<<Past.var<<"I"<<setw(15)<<right<<Past.pav;
    for (auto& a: Past.paz) cout<<setw(3)<<a<<"I";
    cout<<setw(5)<<Past.egz<<"I"<<setw(10)<<Past.gal<<endl;
    }  
    }
       
Studentas Stud_iv(){
    int n, laik_paz, sum=0;
    cout<<"sveiki"<<endl;
    Studentas pirmas;
    cout<<"iveskite savo duomenis"<<endl;
    cout<<"vardas: "; cin>>pirmas.var;
    cout<<"pavarde: "; cin>>pirmas.pav;
    cout<<"kiek pazymiu turi " <<pirmas.var<<" "<<pirmas.pav<<": "; cin>n;
    for (int a=0,a<n,a++)
        {
            cout<<a+1<<": "; cin>>laik_paz;
            pirmas.paz.push_back(laik_paz);
            sum+=laik_paz; //sum+=pirmas.paz[a];
            }
        cout<<"iveskite egz paz.: "; cin>>pirmas.egz;
        pirmas.gal =double(sum)/double(n)*0.4 + pirmas.egz*0.6;
        return pirmas;