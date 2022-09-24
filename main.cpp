#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <windows.h>

using namespace std;

int nr, nrj, nr_etape;
fstream f("date.in");
fstream g("jucatori.in");
fstream h("campionat.in");

string num_camp;

void campionat()
{
    h >> num_camp;
    h >> nr_etape;
}

class Jucator;
class Echipa
{
public:
    string nume, antrenor;
    int jocuri, victorii, egaluri, infrangeri, gol_prim, gol_insc;
    friend class Jucator;

public:
    void citire();
    void afisare();
    void afisare(int);
    double punctaj(int);
    void locul();
    void simulare();
    void etapa();
    void anumit_loc();
    void gol_prim_tast();
    void gol_insc_tast();
    void punct_tast();
    void raport(string, int, int);

}t[100];

class Jucator
{
public:
    string nume, prenume, pozitie;
    int goluri, pase, anul, echipindex;
    double valoare;

public:
    void citire();
    void afisare();
    void afisare(int);
    void adaugare();
    void stergere();
    double varsta()
    {
        return 2022 - anul;
    }
    string getEchipa(int);
    void editare();
    void juc_echip();
    void stat_juc();

}v[100];

void Echipa::citire()
{
    f >> nr;

    for(int i = 0; i < nr; i++)
    {
        f >> t[i].nume;
        f >> t[i].antrenor;
    }
}

void antet()
{
    cout << "Nr: ";
    cout << setw(13) << "Nume:";
    cout << setw(13) << "Antrenor:";
    cout << setw(13) << "Jocuri:";
    cout << setw(15) << "Victorii:";
    cout << setw(15) << "Egaluri:";
    cout << setw(15) << "Pierderi: ";
    cout << setw(9)  << "GP:";
    cout << setw(11) << "GM:";
    cout << setw(13) << "Puncte:" << endl;
}

void Echipa::afisare()
{
    antet();
    for(int i = 0; i < nr; i++)
    {
        cout << i + 1;
        cout << setw(15) << setfill(' ') << t[i].nume;
        cout << setw(13) << t[i].antrenor;
        cout << setw(10) << t[i].jocuri;
        cout << setw(15) << t[i].victorii;
        cout << setw(15) << t[i].egaluri;
        cout << setw(15) << t[i].infrangeri;
        cout << setw(12) << t[i].gol_prim;
        cout << setw(12) << t[i].gol_insc;
        cout << setw(12) << t[i].punctaj(i) << endl;
    }
}

void Echipa::afisare(int i)
{
    cout << i + 1;
    cout << setw(15) << t[i].nume;
    cout << setw(13) << t[i].antrenor;
    cout << setw(10) << t[i].jocuri;
    cout << setw(15) << t[i].victorii;
    cout << setw(15) << t[i].egaluri;
    cout << setw(15) << t[i].infrangeri;
    cout << setw(12) << t[i].gol_prim;
    cout << setw(12) << t[i].gol_insc;
    cout << setw(12) << t[i].punctaj(i) << endl;
}

double Echipa::punctaj(int i)
{
    return t[i].victorii * 3 + t[i].egaluri;
}

string Jucator::getEchipa(int i)
{
    int q = v[i].echipindex;

    if(q == 1)
        return "Locomotiva";
    else if(q == 2)
        return "Petrocub";
    else if(q == 3)
        return "Milsami";
    else if(q == 4)
        return "Speranta";
    else if(q == 5)
        return "FCSB";
    else if(q == 6)
        return "Floresti";
    else if(q == 7)
        return "BaltiCF";
    else if(q == 8)
        return "Zimbru";
    else if(q == 9)
        return "Cluj";
    else if(q == 10)
        return "Sheriff";
}

void Jucator::citire()
{
    g >> nrj;

    for(int i = 0; i < nrj; i++)
    {
        g >> v[i].nume;
        g >> v[i].prenume;
        g >> v[i].echipindex;
        g >> v[i].anul;
        g >> v[i].pozitie;
        g >> v[i].goluri;
        g >> v[i].pase;
        g >> v[i].valoare;
    }
}

void antet2()
{
    cout << "Nr: ";
    cout << setw(12) << "Nume: ";
    cout << setw(12) << "Prenume: ";
    cout << setw(13) << "Echipa: ";
    cout << setw(13) << "Anul: ";
    cout << setw(13) << "Varsta: ";
    cout << setw(13) << "Pozitie: ";
    cout << setw(13) << "Aparitii: ";
    cout << setw(13) << "Goluri: ";
    cout << setw(13) << "Pase: ";
    cout << setw(12) << "Valoare: " << endl;
}

void Jucator::afisare()
{
    antet2();
    for(int i = 0; i < nrj; i++)
    {
        cout << i + 1;
        cout << setw(12) << v[i].nume;
        cout << setw(14) << v[i].prenume;
        cout << setw(13) << v[i].getEchipa(i);
        cout << setw(13) << v[i].anul;
        cout << setw(12) << v[i].varsta();
        cout << setw(13) << v[i].pozitie;
        cout << setw(13) << t[i].jocuri;
        cout << setw(13) << v[i].goluri;
        cout << setw(13) << v[i].pase;
        cout << setw(12) << v[i].valoare << endl;
    }
}
void Jucator::afisare(int i)
{
        cout << i + 1;
        cout << setw(12) << v[i].nume;
        cout << setw(14) << v[i].prenume;
        cout << setw(13) << v[i].getEchipa(i);
        cout << setw(13) << v[i].anul;
        cout << setw(12) << v[i].varsta();
        cout << setw(13) << v[i].pozitie;
        cout << setw(13) << t[i].jocuri;
        cout << setw(13) << v[i].goluri;
        cout << setw(13) << v[i].pase;
        cout << setw(12) << v[i].valoare << endl;
}
void Jucator::juc_echip()
{
    string team;

    cout << "Introduceti numele echipei a carei jucatori cautati: ";
    cin >> team;
    antet2();
    for(int i = 0; i < nrj; i++)
        if(v[i].getEchipa(i) == team)
            afisare(i);
}

void Jucator::adaugare()
{
    cout << "Introduceti numele: ";
    cin >> v[nrj].nume;
    cout << "Introduceti prenumele: ";
    cin >> v[nrj].prenume;
    cout << "Introduceti anul nasterii: ";
    cin >> v[nrj].anul;
    cout << "Introduceti indexul echipei: " << endl;
    cout << "_________________" << endl;
    cout << "|Locomotiva----1|" << endl;
    cout << "|Petrocub------2|" << endl;
    cout << "|Milsami-------3|" << endl;
    cout << "|Speranta------4|" << endl;
    cout << "|FCSB----------5|" << endl;
    cout << "|Floresti------6|" << endl;
    cout << "|BaltiCF-------7|" << endl;
    cout << "|Zimbru--------8|" << endl;
    cout << "|Cluj----------9|" << endl;
    cout << "|Sheriff------10|" << endl;
    cout << "|_______________|" << endl;
    cin >> v[nrj].echipindex;
    cout << "Introduceti pozitia: ";
    cin >> v[nrj].pozitie;
    cout << "Introduceti valoarea pe piata: ";
    cin >> v[nrj].valoare;

    nrj++;

}
void Jucator::stergere()
{
  bool removed = false;
  afisare();

  string numele;
  cout << endl << "Introduceti numele jucatorului care trebuie exclus: ";
  cin >> numele;
  cout << endl;

  for (int i = 0; i < nrj; i++) {
    if (removed) {
      v[i] = v[i + 1];
    }
    if (v[i].nume == numele) {
      removed = true;
      v[i] = v[i + 1];
    }
  }
  nrj--;
}

void Jucator::editare()
{
    afisare();

    cout << endl << endl;

    int poz, aleg;
    string nou;
    double actual;

    cout << "Introduceti pozitia jucatorului pe care doriti sal editati: ";
    cin >> poz;

    poz--;

    cout << endl;

    cout << "_________________" << endl;
    cout << "|Nume----------1|" << endl;
    cout << "|Prenume-------2|" << endl;
    cout << "|Anul----------3|" << endl;
    cout << "|IndexEchipa---4|" << endl;
    cout << "|Pozitia-------5|" << endl;
    cout << "|Valoarea------6|" << endl;
    cout << "|_______________|" << endl;
    cin >> aleg;

    if(aleg == 1)
    {
        cout << "Introduceti numele nou: ";
        cin >> nou;
        v[poz].nume = nou;
    }
    else if(aleg == 2)
    {
        cout << "Introduceti prenumele nou: ";
        cin >> nou;
        v[poz].prenume = nou;
    }
    else if(aleg == 3)
    {
        cout << "Introduceti anul de nastere nou: ";
        cin >> actual;
        v[poz].anul = actual;
    }
    else if(aleg == 4)
    {
    cout << "Alegeti echipa noua" << endl;
    cout << "_________________" << endl;
    cout << "|Locomotiva----1|" << endl;
    cout << "|Petrocub------2|" << endl;
    cout << "|Milsami-------3|" << endl;
    cout << "|Speranta------4|" << endl;
    cout << "|FCSB----------5|" << endl;
    cout << "|Floresti------6|" << endl;
    cout << "|BaltiCF-------7|" << endl;
    cout << "|Zimbru--------8|" << endl;
    cout << "|Cluj----------9|" << endl;
    cout << "|Sheriff------10|" << endl;
    cout << "|_______________|" << endl;
    cin >> aleg;

    switch(aleg)
    {
        case 1: v[poz].echipindex = 1;break;
        case 2: v[poz].echipindex = 2;break;
        case 3: v[poz].echipindex = 3;break;
        case 4: v[poz].echipindex = 4;break;
        case 5: v[poz].echipindex = 5;break;
        case 6: v[poz].echipindex = 6;break;
        case 7: v[poz].echipindex = 7;break;
        case 8: v[poz].echipindex = 8;break;
        case 9: v[poz].echipindex = 9;break;
        case 10: v[poz].echipindex = 10;break;
    }
    }
    else if(aleg == 5)
    {
        cout << "Introduceti pozitia noua: ";
        cin >> nou;
        v[poz].pozitie = nou;
    }
    else if(aleg == 6)
    {
        cout << "Introduceti noua valoare: ";
        cin >> actual;
        v[poz].valoare = actual;
    }

}

void Jucator::stat_juc()
{
    int g, gm = 0, pm = 0, p;
    for(int i = 0; i < nr; i++)
        for(int j = 0; j < nrj; j++)
            if(t[i].nume == v[j].getEchipa(v[j].echipindex))
            {
                v[j].goluri = rand() % t[i].gol_insc/2;
                v[j].pase = rand() % t[i].gol_insc/2;
            }

            for(int i = 0; i < nrj - 1; i++)
                for(int j = i + 1; j < nrj; j++){

                if(v[i].goluri + v[i].pase < v[j].goluri + v[j].pase){
                Jucator aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
                }
            afisare();

        for(int i = 0; i < nrj; i++)
        {
                if(v[i].goluri > gm){
                        g = i;
                        gm = v[i].goluri;
                    }
                if(v[i].pase > pm){
                    p = i;
                    pm = v[i].pase;
                }
        }

        cout << endl;
        cout << "Goalgheter-ul anului: " << v[g].nume << " " << v[g].prenume << " cu " << v[g].goluri << " goluri marcate" << endl;
        cout << "Asistent-ul anului: " << v[p].nume << " " << v[p].prenume << " cu " << v[p].pase << " pase decisive" << endl;
        cout << "Jucatorul anului: " << v[0].nume << " " << v[0].prenume << " cu " << v[0].goluri << " goluri si " << v[0].pase << " pase " << endl << endl;
}

void Echipa::simulare()
{
    int scor1, scor2, etap;
    int meciuri;

    meciuri = nr_etape / (nr - 1);

  for(int k = 0; k < meciuri; k++)
    for(int i = 0; i < nr-1; i++)
        for(int j = i+1; j < nr; j++)
    {
    scor1 = rand() % 6 + 0;
    scor2 = rand() % 6 + 0;

    t[i].gol_insc += scor1;
    t[i].gol_prim += scor2;
    t[j].gol_insc += scor2;
    t[j].gol_prim += scor1;

    cout << setw(13) << t[i].nume << setw(5) << scor1 << setw(7) << " - ";
    cout << setw(5) << scor2 << setw(13) << t[j].nume << endl;

    if(scor1 > scor2)
    {
        t[i].victorii++;
        t[j].infrangeri++;
    }
    else if(scor1 < scor2)
    {
        t[j].victorii++;
        t[i].infrangeri++;
    }
    else
    {
        t[i].egaluri++;
        t[j].egaluri++;
    }
    t[i].jocuri++;
    t[j].jocuri++;
    etap = t[i].jocuri;
    }

    cout << endl << "Etapa nr " << etap << " disputata cu succes! " << endl;
    cout << endl << "\t\t\t\t\t" << "Clasamentul dupa etapa data: "<< endl << endl;
}

void rap_antet()
{
    cout << endl;
    cout << setw(20) << "GM:";
    cout << setw(11) << "GP:";
    cout << setw(15) << "Puncte:" << endl << endl;
}

void Echipa::raport(string nume, int s1, int s2)
{
    cout << setw(13) << nume;
    cout << setw(5) << "+" << s1;
    cout << setw(10) << "-" << s2;
    if(s1 > s2)
        cout << setw(13) << "+3p";
    else if(s1 < s2)
        cout << setw(13) << "+0p";
    else
        cout << setw(13) << "+1p";
    cout << endl;
}


void Echipa::etapa()
{
    int scor1, scor2, etap;    rap_antet();

    for(int i = 0; i < nr-1; i+=2)
    {
    scor1 = rand() % 6 + 0;
    scor2 = rand() % 6 + 0;

    t[i].gol_insc += scor1;
    t[i].gol_prim += scor2;
    t[i+1].gol_insc += scor2;
    t[i+1].gol_prim += scor1;

   cout << setw(13) << t[i].nume << setw(6) << scor1 << setw(6) << " - ";
    cout << setw(5) << scor2 << setw(13) << t[i+1].nume << endl << endl;

    if(scor1 > scor2)
    {
        t[i].victorii++;
        t[i+1].infrangeri++;

    }
    else if(scor1 < scor2)
    {
        t[i+1].victorii++;
        t[i].infrangeri++;

    }
    else
    {
        t[i].egaluri++;
        t[i+1].egaluri++;

    }
    raport(t[i].nume, scor1, scor2);
    raport(t[i+1].nume, scor2, scor1);
    cout << endl;
    t[i].jocuri++;
    t[i+1].jocuri++;
    etap = t[i].jocuri;
    }

    cout << endl << "Etapa nr " << etap << " disputata cu succes! " << endl;
    cout << endl << "\t\t\t\t\t" << "Clasamentul dupa etapa data: "<< endl << endl;
}
void Echipa::locul()
{
    for(int i = 0; i < nr; i++)
        for(int j = i+1; j < nr; j++)
        if(t[i].punctaj(i) < t[j].punctaj(j))
    {
        Echipa aux;
        aux = t[i];
        t[i] = t[j];
        t[j] = aux;
    }
    afisare();
    cout << endl;
}

void Echipa::anumit_loc()
{
    string search;

    cout << "Introduceti numele echipei cautate: ";
    cin >> search;
    cout << endl;
    antet();
    for(int i = 0; i < nr; i++)
        if(t[i].nume == search)
            afisare(i);
}

void Echipa::gol_prim_tast()
{
    int numar;

    cout << "Introduceti numarul minim de goluri primite: ";
    cin >> numar;

        antet();
    for(int i = 0; i < nr; i++)
        if(t[i].gol_prim > numar)
            afisare(i);
}
void Echipa::gol_insc_tast()
{
    int numar;

    cout << "Introduceti numarul minim de goluri inscrise: ";
    cin >> numar;

    antet();
    for(int i = 0; i < nr; i++)
        if(t[i].gol_insc > numar)
            afisare(i);
}
void Echipa::punct_tast()
{
    int numar;

    cout << "Introduceti numarul de puncte: ";
    cin >> numar;

    antet();
    for(int i = 0; i < nr; i++)
        if(t[i].punctaj(i) < numar)
            afisare(i);
}

int main()
{
    Echipa e;
    Jucator p;
    campionat();

    int alegere;

    do
    {
    cout << endl << "\t\t\t\t\t" << num_camp  << endl;
    cout << "\t\t\t\t\t Total etape: " << nr_etape << endl;
    cout << endl;
    cout << " ______________________________MENIU_________________________________ " << endl;
    cout << "|....................................................................|" << endl;
    cout << "|A) Introducerea / stergerea unui jucator---------------------------1|" << endl;
    cout << "|B) Afisarea informatiei--------------------------------------------2|" << endl;
    cout << "|C) Schimbarea valorii unui anumit jucator--------------------------3|" << endl;
    cout << "|D) Clasamentul in functie de punctaj-------------------------------4|" << endl;
    cout << "|E) Locul ocupat de o anumita echipa--------------------------------5|" << endl;
    cout << "|F) Clasament pe baza reusitelor jucatorilor------------------------6|" << endl;
    cout << "|G) Comparareea intre clasamentul anterior si cel real--------------7|" << endl;
    cout << "|H) Echipe cu un numar de goluri inscrise/primite mai mare ca n-----8|" << endl;
    cout << "|H) Echipe cu un numar de puncte mai mic ca n-----------------------9|" << endl;
    cout << "|() Iesire----------------------------------------------------------0|" << endl;
    cout << "|....................................................................|" << endl;
    cout << "|____________________________________________________________________|" << endl;
    cout << endl;

    e.citire();
    p.citire();
    alegere = getch();
    system("cls");

    switch(alegere)
    {
    case '1':
            cout << " _______________ " << endl;
            cout << "|Introducere---1|" << endl;
            cout << "|Stergere------2|" << endl;
            cout << "|_______________|" << endl;
            alegere = getch();

            switch(alegere)
            {
                case '1': p.adaugare();break;
                case '2': p.stergere();break;
            }
            break;

    case '2':
               cout << " _____________ " << endl;
               cout << "|Echipe------1|" << endl;
               cout << "|Jucatori----2|" << endl;
               cout << "|Juc/echipa--3|" << endl;
               cout << "|_____________|" << endl;
               alegere = getch();

               switch(alegere)
               {
                   case '1': e.afisare(); break;
                   case '2': p.afisare(); break;
                   case '3': p.juc_echip(); break;
               }
               break;

    case '3': p.editare(); break;


    case '4':

            cout << "\t\t\t\t\t\ Clasamentul inainte de etape:"  << endl << endl;
            e.locul();
            cout << endl << endl;
            e.simulare();
            cout << endl;
            e.locul();
            break;

    case '5': e.anumit_loc(); break;
    case '6': p.stat_juc();break;
    case '7': e.locul(); e.etapa(); e.locul(); nr_etape++; break;

    case '8':
            cout << " ____________ " << endl;
            cout << "|Inscrise---1|" << endl;
            cout << "|Primite----2|" << endl;
            cout << "|____________|" << endl;
            alegere = getch();

            switch(alegere)
            {
                case '1': e.gol_insc_tast();break;
                case '2': e.gol_prim_tast();break;
            }
            break;
    case '9': e.punct_tast();break;
    }

    }while(alegere != '0');
}
