#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
string temat; //info z jakiej dziedzny jest quiz,
string autor;
string tresc[5];
string odpA[5], odpB[5], odpC[5],odpD[5];
string poprawna[5];
string odpowiedz;
int punkty=0;



int main()
{   string linia;
    int nr_pytania=0;//bo pytania sa w tablicy i liczone sa od 0,
    int nr_linii=1;//linie liczone sa od 1,
    fstream plik;
    plik.open("quiz.txt", ios::in);
    if(plik.good()==false)
    {
        cout<<"Nie ma takiego pliku."<<endl;
        exit(0);
    }


    while(getline(plik,linia))
    {
        switch(nr_linii)
        {
            case 1: temat=linia;break;
            case 2: autor=linia;break;
            case 3: tresc[nr_pytania]=linia;break;
            case 4: odpA[nr_pytania]=linia; break;
            case 5: odpB[nr_pytania]=linia; break;
            case 6: odpC[nr_pytania]=linia; break;
            case 7: odpD[nr_pytania]=linia; break;
            case 8: poprawna[nr_pytania]=linia; break;
        }

        if(nr_linii==8)
        {
            nr_pytania++;
            nr_linii=2;
        }
        nr_linii++;


    }
    plik.close();
    plik.clear();

    for(int i =0; i<4; i++)
    {
        cout<<temat<<endl;
        cout<<autor<<endl;
        cout<<tresc[i]<<endl;
        cout<<"A."<<odpA[i]<<endl;
        cout<<"B."<<odpB[i]<<endl;
        cout<<"C."<<odpC[i]<<endl;
        cout<<"D."<<odpD[i]<<endl;

        cout<<"Podaj poprawna odpowiedz"<<endl;
        cin>>odpowiedz;//a b c d



        if(odpowiedz==poprawna[i])
        {
            cout<<"Poprawna odpowiedz"<<endl;
            cout<<endl;
            punkty++;

        }
        else
        {   cout<<"Zle"<<endl;
            cout<<poprawna[i]<<endl;
            cout<<endl;
        }
    }

    cout<<"Zdobyte punkty: "<<punkty<<endl;


    return 0;
}
