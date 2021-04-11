#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

#define Przycisk_Zaloguj 1
#define Przycisk_Moje_Filmy 1
#define Przycisk_Wypozycz_Film 2
#define Przycisk_Zmien_Haslo 3
#define Przycisk_Wyloguj 5
#define Przycisk_Filmy 1
#define Przycisk_Usun_Uzytkownika 2
#define Przycisk_Dodaj_Uzytkownika 3
#define Przycisk_Zmiana_Hasla_Potwierdz 6
#define Przycisk_Zmiana_Hasla_Zmien_Haslo 7
#define Przycisk_Zmiana_Wypozycz 8
#define Przycisk_Zmiana_Zwroc 9
#define Przycisk_Platnosci_Zaplac 10
#define Przycisk_Dodaj_Uzytkownika_Dodaj 6
#define Przycisk_Dodaj_Uzytkownika_Usun 7
#define Przycisk_Filmy_Nowy_Film 8
#define Przycisk_Filmy_Usun_Film 9
#define Przycisk_Filmy_Zmien_Cene 10


LRESULT CALLBACK ProceduraOknaLogowania(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ProceduraOknaUzytkownika(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ProceduraOknaAdministratora(HWND, UINT, WPARAM, LPARAM);


void rejestracjaKlasyOknaLogowania(HINSTANCE);
void rejestracjaKlasyOknaUzytkownika(HINSTANCE);
void rejestracjaKlasyOknaAdministratora(HINSTANCE);
void oknoLogowania();
void oknoUzytkownika(HWND);
void oknoAdministratora(HWND);
void dodajZawartoscLogowanie(HWND);
void dodajZawartoscUzytkownik(HWND);
    void dodajZawartoscUzytkownikMojeFilmy(HWND);
    void dodajZawartoscUzytkownikZmianaHasla2(HWND);
    void dodajZawartoscUzytkownikZmianaHasla1(HWND);
    void dodajZawartoscUzytkownikWyporzycz(HWND);
    void SchowajUzytkownik();
void dodajZawartoscAdministrator(HWND);
    void dodajZawartoscAdministratorFilmy(HWND);
    void dodajZawartoscAdministratorDodacUzytkownika(HWND);
    void dodajZawartoscAdministratorUsunUzytkownika(HWND);
    void SchowajAdministrator();


HWND hLogin, hHaslo, hOknoLogowania,
    hFilm1, hListaMoichFilmow, hMojeFilmyTytul, hMojeFilmyTytulFilmu, hMojeFilmyTytulFilmuEdit, hMojeFilmyZwroc,
    hWypozyczTytul, hWypozyczLista, hWypozyczyZaDzien, hWypozyczCeny, hWypozyczTytulFilmu, hWypozyczTytulFilmuEdit, hWypozyczTytulWypozycz,
    hZmianaHaslaNoweTytul, hZmianaHaslaLogin, hZmianaHaslaLoginEdit, hZmianaHaslaHaslo, hZmianaHaslaHasloEdit, hZmianaHaslaPotwierdz,
    hZmianaHaslaNoweTytul2, hZmianaHaslaNoweHaslo, hZmianaHaslaNoweHasloEdit, hZmianaHaslaPowtorzHaslo2, hZmianaHaslaPowtorzHasloEdit2, hZmianaHaslaZmienHaslo,
    hFilmyTytul, hFilmyZaDzien ,hListaFilmow, hFilmyCeny, hFilmyNowyFilm, hFilmyNowyFilmEdit, hFilmyCena,hFilmyCenaEdit,hFilmyOk1, hFilmyUsunFilm, hFilmyUsunFilmEdit,
    hFilmyOk2, hFilmyZmienCene, hFilmyTytulFilmu, hFilmyTytulFilmuEdit, hFilmyNowaCena, hFilmyNowaCenaEdit, hFilmyOk3, hFilmyRamka,
    hDodacUzytkownikaTytul, hDodacUzytkownikaLogin, hDodacUzytkownikaLoginEdit, hDodacUzytkownikaHaslo, DodacUzytkownikaHasloEdit, DodacUzytkownikaDodaj,
    hUsunUzytkownikaTytul, hUsunUzytkownikaLogin, hUsunUzytkownikaLoginEdit, hUsunUzytkownikaHaslo, hUsunUzytkownikaHasloEdit, hUsunUzytkownikaHasloUsun;

LPSTR log, has, ceny_wyswietlanie, loginUzytkownika, hasloUzytkownika;


int WINAPI WinMain(HINSTANCE hUchwyt, HINSTANCE hPoprzedniUchwyt, LPSTR argumenty, int ncmdshow)
{

    rejestracjaKlasyOknaLogowania(hUchwyt);
    rejestracjaKlasyOknaUzytkownika(hUchwyt);
    rejestracjaKlasyOknaAdministratora(hUchwyt);
    oknoLogowania();

    MSG komunikat = {0};

    while(GetMessage(&komunikat,NULL,NULL,NULL))
    {
        TranslateMessage(&komunikat);
        DispatchMessage(&komunikat);
    }

        return 0;
}

LRESULT CALLBACK ProceduraOknaLogowania(HWND uchwytLogowanie, UINT komunikat, WPARAM wparametr, LPARAM lparametr)
{
    switch (komunikat)
    {
        case WM_COMMAND:
             switch(wparametr)
            {
                case Przycisk_Zaloguj:

                    char login[20];
                    char haslo[20];
                    GetWindowText(hLogin,login,20);
                    GetWindowText(hHaslo,haslo,20);

                    string line;
                    ifstream Plik("logowanie.txt", ios::in);

                    while(getline(Plik,line))
                    {
                        LPSTR log = strdup( line.c_str() );
                        getline(Plik,line);
                        LPSTR has = strdup( line.c_str() );

                        if(!strcmp(login,"admin") && !strcmp(haslo,"admin1"))
                        {
                            oknoAdministratora(uchwytLogowanie);
                            goto wyjscie;

                        }

                        else if(!strcmp(login,log) && !strcmp(haslo,has))
                        {
                            loginUzytkownika = log;
                            hasloUzytkownika = has;
                            oknoUzytkownika(uchwytLogowanie);
                            goto wyjscie;
                        }
                    }
                            MessageBox( NULL, "Nie poprawny login lub haslo!", "Nie poprawny login lub haslo!", MB_ICONEXCLAMATION );
                            SetWindowText(hLogin,"");
                            SetWindowText(hHaslo,"");

                    wyjscie:
                    Plik.close();
                    break;
            }
            break;
        case WM_CREATE:
            dodajZawartoscLogowanie(uchwytLogowanie);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProcW(uchwytLogowanie,komunikat,wparametr,lparametr);
    }
}

LRESULT CALLBACK ProceduraOknaUzytkownika(HWND uchwytUzytkownik, UINT komunikat, WPARAM wparametr, LPARAM lparametr)
{
    switch (komunikat)
    {
        case WM_COMMAND:
             switch(wparametr)
            {
                case Przycisk_Moje_Filmy:
                    SchowajUzytkownik();
                    dodajZawartoscUzytkownikMojeFilmy(uchwytUzytkownik);
                    break;
                case Przycisk_Wypozycz_Film:
                    SchowajUzytkownik();
                    dodajZawartoscUzytkownikWyporzycz(uchwytUzytkownik);
                    break;
                case Przycisk_Zmien_Haslo:
                    SchowajUzytkownik();
                    dodajZawartoscUzytkownikZmianaHasla1(uchwytUzytkownik);
                    break;
                case Przycisk_Wyloguj:
                     DestroyWindow(uchwytUzytkownik);
                    break;
                case Przycisk_Zmiana_Hasla_Potwierdz:
                {
                    char login[20];
                    char haslo[20];
                    GetWindowText(hZmianaHaslaLoginEdit,login,20);
                    GetWindowText(hZmianaHaslaHasloEdit,haslo,20);


                    if(!strcmp(login,loginUzytkownika) && !strcmp(haslo,hasloUzytkownika))
                    {
                       SchowajUzytkownik();
                       dodajZawartoscUzytkownikZmianaHasla2(uchwytUzytkownik);
                       break;
                    }
                    else
                    {
                        MessageBox( NULL, "Nie poprawny login lub haslo!", "Nie poprawny login lub haslo!", MB_ICONEXCLAMATION );
                        SetWindowText(hZmianaHaslaLoginEdit,"");
                        SetWindowText(hZmianaHaslaHasloEdit,"");
                        break;
                    }
                    break;
                }
                case Przycisk_Zmiana_Hasla_Zmien_Haslo:
                {
                    char haslo1[20];
                    char haslo2[20];
                    GetWindowText(hZmianaHaslaNoweHasloEdit,haslo1,20);
                    GetWindowText(hZmianaHaslaPowtorzHasloEdit2,haslo2,20);

                    if(!strcmp(haslo1,"") || !strcmp(haslo2,""))
                     {
                        MessageBox( NULL, "Nie podano has³a!", "Nie podano has³a!", MB_ICONEXCLAMATION );
                        SetWindowText(hZmianaHaslaNoweHasloEdit,"");
                        SetWindowText(hZmianaHaslaPowtorzHasloEdit2,"");
                        break;
                     }
                     else if(!strcmp(haslo1,haslo2))
                     {

                        string line;
                        ifstream Plik("logowanie.txt", ios::in);
                        ofstream temp;
                        temp.open("temp.txt");

                        while (getline(Plik, line))
                        {
                            if (line != loginUzytkownika &&  line != "")
                                temp << line << endl;
                            else
                            {
                                temp << line << endl;
                                temp << haslo1 << endl;
                                getline(Plik, line);
                            }
                        }
                        temp.close();
                        Plik.close();
                        remove("logowanie.txt");
                        rename("temp.txt", "logowanie.txt");
                        MessageBox( NULL, "Haslo zostalo zmienione", "Haslo zostalo zmienione", MB_OK);
                        SchowajUzytkownik();
                        dodajZawartoscUzytkownikZmianaHasla1(uchwytUzytkownik);
                        break;
                     }
                     else
                     {
                         MessageBox( NULL, "Podane hasla nie sa takie same!", "Podane hasla nie sa takie same!", MB_ICONEXCLAMATION );
                         SetWindowText(hZmianaHaslaNoweHasloEdit,"");
                         SetWindowText(hZmianaHaslaPowtorzHasloEdit2,"");
                         break;
                     }


                   break;
                }
                case Przycisk_Zmiana_Wypozycz:
                {
                     char tytul[40];
                     GetWindowText(hWypozyczTytulFilmuEdit,tytul,40);

                     if(!strcmp(tytul,""))
                     {
                        MessageBox( NULL, "Nie podano tytulu!", "Nie podano tytulu!", MB_ICONEXCLAMATION );
                        SetWindowText(hWypozyczTytulFilmuEdit,"");
                        break;
                     }

                     string loginUzytkownikaPlik = loginUzytkownika;
                     loginUzytkownikaPlik = "Uzytkownicy\\" + loginUzytkownikaPlik + ".txt";

                     string line,linie;
                     bool wypozyczony = 0;
                     ifstream Plik("wypozycz.txt", ios::in);
                     ifstream Uzytkownikk(loginUzytkownikaPlik.c_str(), ios::in);
                     ofstream Uzytkownik(loginUzytkownikaPlik.c_str(),ios_base::app | ios_base::out);

                     while(getline(Uzytkownikk,linie))
                     {
                         LPSTR log = strdup( linie.c_str());

                         if(!strcmp(tytul,log))
                         {
                            MessageBox( NULL, "Film jest juz wypozyczony!", "Film jest juz wypozyczony!", MB_ICONEXCLAMATION );
                            Uzytkownikk.close();
                            wypozyczony = 1;
                            break;
                         }
                     }

                        if(!wypozyczony)
                        {
                            while(getline(Plik,line))
                            {
                                 LPSTR log = strdup( line.c_str());

                                 if(!strcmp(tytul,log))
                                 {
                                   Uzytkownik << tytul << endl;
                                   MessageBox( NULL, "Film zostal wpozyczony", "Film zostal wpozyczony", MB_OK);
                                   goto wypozycz;
                                 }
                            }
                            MessageBox( NULL, "Nie znaleziono filmu!", "Nie znaleziono filmu o tym tytule!", MB_ICONEXCLAMATION );
                        }

                wypozycz:
                    Plik.close();
                    Uzytkownik.close();
                    SetWindowText(hWypozyczTytulFilmuEdit,"");
                    break;
                }
                case Przycisk_Zmiana_Zwroc:
                {
                    char tytul[40];
                    GetWindowText(hMojeFilmyTytulFilmuEdit,tytul,40);

                    if(!strcmp(tytul,""))
                    {
                        MessageBox( NULL, "Nie podano tytulu!", "Nie podano tytulu!", MB_ICONEXCLAMATION );
                        SetWindowText(hMojeFilmyTytulFilmuEdit,"");
                        break;
                    }

                    string line;
                    string loginUzytkownikaPlik = loginUzytkownika;
                    loginUzytkownikaPlik = "Uzytkownicy\\" + loginUzytkownikaPlik + ".txt";
                    ifstream Plik(loginUzytkownikaPlik.c_str(), ios::in);

                    while(getline(Plik,line))
                    {
                     LPSTR log = strdup( line.c_str());

                     if(!strcmp(tytul,log))
                     {
                        Plik.close();
                        Plik.open(loginUzytkownikaPlik.c_str());
                        ofstream temp;
                        temp.open("temp.txt");

                        while (getline(Plik, line))
                        {
                            if (line != tytul &&  line != "")
                                temp << line << endl;
                        }
                        temp.close();
                        Plik.close();
                        remove(loginUzytkownikaPlik.c_str());
                        rename("temp.txt", loginUzytkownikaPlik.c_str());
                        MessageBox( NULL, "Zwrocono film", "zwrocono film", MB_OK);
                        SchowajUzytkownik();
                        dodajZawartoscUzytkownikMojeFilmy(uchwytUzytkownik);

                       goto zwroc;
                    }
                 }
                 MessageBox( NULL, "Nie znaleziono filmu!", "Nie znaleziono filmu o tym tytule!", MB_ICONEXCLAMATION );
                 Plik.close();
                 SetWindowText(hMojeFilmyTytulFilmuEdit,"");
            zwroc:
                    break;
                }
            }
            break;
        case WM_CREATE:
            dodajZawartoscUzytkownik(uchwytUzytkownik);
            dodajZawartoscUzytkownikMojeFilmy(uchwytUzytkownik);
            break;

        case WM_DESTROY:
            ShowWindow(hOknoLogowania, SW_SHOW);
            DestroyWindow(uchwytUzytkownik);
            break;

        default:
            return DefWindowProcW(uchwytUzytkownik,komunikat,wparametr,lparametr);
    }
}

LRESULT CALLBACK ProceduraOknaAdministratora(HWND uchwytAdministrator, UINT komunikat, WPARAM wparametr, LPARAM lparametr)
{
    switch (komunikat)
    {
        case WM_COMMAND:
             switch(wparametr)
            {
                case Przycisk_Filmy:
                    SchowajAdministrator();
                    dodajZawartoscAdministratorFilmy(uchwytAdministrator);
                    break;
                case Przycisk_Dodaj_Uzytkownika:
                    SchowajAdministrator();
                    dodajZawartoscAdministratorDodacUzytkownika(uchwytAdministrator);
                    break;
                case Przycisk_Usun_Uzytkownika:
                    SchowajAdministrator();
                    dodajZawartoscAdministratorUsunUzytkownika(uchwytAdministrator);
                    break;
                case Przycisk_Wyloguj:
                     DestroyWindow(uchwytAdministrator);
                    break;
                case Przycisk_Dodaj_Uzytkownika_Dodaj:
                {
                     char login[20];
                     char haslo[20];
                     GetWindowText(hDodacUzytkownikaLoginEdit,login,20);
                     GetWindowText(DodacUzytkownikaHasloEdit,haslo,20);
                     if(!strcmp(login,"") || !strcmp(haslo,""))
                     {
                        MessageBox( NULL, "Nie poprawnie wyelniony login lub haslo!", "Nie poprawnie wyelniony login lub haslo!", MB_ICONEXCLAMATION );
                        SetWindowText(hDodacUzytkownikaLoginEdit,"");
                        SetWindowText(DodacUzytkownikaHasloEdit,"");
                        break;
                     }
                            string line;
                            ifstream Plik("logowanie.txt", ios::in);
                            ofstream temp;
                            temp.open("temp.txt");
                            temp << login << "\n" << haslo << "\n";

                            while(getline(Plik,line))
                                temp << line << endl;

                            temp.close();
                            Plik.close();
                            remove("logowanie.txt");
                            rename("temp.txt", "logowanie.txt");

                     MessageBox( NULL, "Dodano uzytkownika", "Dodano uzytkownika", MB_OK);
                     SetWindowText(hDodacUzytkownikaLoginEdit,"");
                     SetWindowText(DodacUzytkownikaHasloEdit,"");
                     break;
                }
                case Przycisk_Dodaj_Uzytkownika_Usun:
                {
                     char login[20];
                     char haslo[20];
                     GetWindowText(hUsunUzytkownikaLoginEdit,login,20);
                     GetWindowText(hUsunUzytkownikaHasloEdit,haslo,20);
                     if(!strcmp(login,"") || !strcmp(haslo,""))
                     {
                        MessageBox( NULL, "Nie poprawnie wyelniony login lub haslo!", "Nie poprawnie wyelniony login lub haslo!", MB_ICONEXCLAMATION );
                        SetWindowText(hUsunUzytkownikaLoginEdit,"");
                        SetWindowText(hUsunUzytkownikaHasloEdit,"");
                        break;
                     }
                     string line;
                     ifstream Plik("logowanie.txt", ios::in);

                     string loginUzytkownikaPlik = login;
                     loginUzytkownikaPlik = "Uzytkownicy\\" + loginUzytkownikaPlik + ".txt";

                     while(getline(Plik,line))
                     {
                         LPSTR log = strdup( line.c_str() );
                         getline(Plik,line);
                         LPSTR has = strdup( line.c_str() );

                         if(!strcmp(login,log) && !strcmp(haslo,has))
                         {
                            Plik.close();
                            Plik.open("logowanie.txt");
                            ofstream temp;
                            temp.open("temp.txt");

                            while (getline(Plik, line))
                            {
                                if (line != login &&  line != "")
                                    temp << line << endl;
                                else
                                    getline(Plik, line);
                            }
                            temp.close();
                            Plik.close();
                            remove("logowanie.txt");
                            rename("temp.txt", "logowanie.txt");
                            MessageBox( NULL, "Usunieto uzytkownika", "usunieto Uzytkownika", MB_OK);
                            remove(loginUzytkownikaPlik.c_str());

                           goto koniec;
                         }
                     }
                     MessageBox( NULL, "Nie znaleziono uzytkownika!", "Nie znaleziono uzytkownika o tym loginie i hasle!", MB_ICONEXCLAMATION );
                     Plik.close();
                koniec:
                     SetWindowText(hUsunUzytkownikaLoginEdit,"");
                     SetWindowText(hUsunUzytkownikaHasloEdit,"");
                    break;
                }
                case Przycisk_Filmy_Nowy_Film:
                {
                     char tytul[40];
                     char cena[20];
                     GetWindowText(hFilmyNowyFilmEdit,tytul,40);
                     GetWindowText(hFilmyCenaEdit,cena,20);
                     if(!strcmp(tytul,"") || !strcmp(cena,""))
                     {
                        MessageBox( NULL, "Nie poprawnie tytul lub cena!", "Nie poprawnie wyelniony tytul lub cena!", MB_ICONEXCLAMATION );
                        SetWindowText(hFilmyNowyFilmEdit,"");
                        SetWindowText(hFilmyCenaEdit,"");
                        break;
                     }
                            string line;
                            ifstream Plik("wypozycz.txt", ios::in);
                            ofstream temp;
                            temp.open("temp.txt");
                            temp << tytul << "\n" << cena << "\n";

                            while(getline(Plik,line))
                                temp << line << endl;

                            temp.close();
                            Plik.close();
                            remove("wypozycz.txt");
                            rename("temp.txt", "wypozycz.txt");

                     MessageBox( NULL, "Dodano nowy film", "Dodano nowy film", MB_OK);
                     SchowajAdministrator();
                     dodajZawartoscAdministratorFilmy(uchwytAdministrator);
                     break;
                }
                case Przycisk_Filmy_Usun_Film:
                {
                     char tytul[40];
                     int ile_lini=0;
                     GetWindowText(hFilmyUsunFilmEdit,tytul,40);

                     if(!strcmp(tytul,""))
                     {
                        MessageBox( NULL, "Nie podano tytulu!", "Nie podano tytulu!", MB_ICONEXCLAMATION );
                        SetWindowText(hFilmyUsunFilmEdit,"");
                        break;
                     }
                     string line;
                     ifstream Plik("wypozycz.txt", ios::in);

                     while(getline(Plik,line))
                         ile_lini +=1;

                     Plik.close();
                     Plik.open("wypozycz.txt");

                     while(getline(Plik,line))
                     {
                         LPSTR log = strdup( line.c_str());

                         if(!strcmp(tytul,log))
                         {
                            Plik.close();
                            Plik.open("wypozycz.txt");
                            ofstream temp;
                            temp.open("temp.txt");

                            while (getline(Plik, line))
                            {
                                if (line != tytul &&  line != "")
                                    temp << line << endl;

                                else
                                    getline(Plik, line);
                            }
                            temp.close();
                            Plik.close();
                            remove("wypozycz.txt");
                            rename("temp.txt", "wypozycz.txt");
                            MessageBox( NULL, "Usunieto film", "Usunieto film", MB_OK);

                            SchowajAdministrator();
                            dodajZawartoscAdministratorFilmy(uchwytAdministrator);

                           goto usun;
                        }
                     }
                     MessageBox( NULL, "Nie znaleziono filmu!", "Nie znaleziono filmu o tym tytule!", MB_ICONEXCLAMATION );
                     Plik.close();
                     SetWindowText(hFilmyUsunFilmEdit,"");
                usun:
                            Plik.open("wypozycz.txt");
                            ofstream temp;
                            temp.open("temp.txt");

                            for(int i=0; i < ile_lini-2 ;i++)
                            {
                                getline(Plik, line);
                                temp << line << endl;
                            }
                            temp.close();
                            Plik.close();
                            remove("wypozycz.txt");
                            rename("temp.txt", "wypozycz.txt");
                    break;
                }
                case Przycisk_Filmy_Zmien_Cene:
                {
                     char tytul[40];
                     char cena[20];
                     GetWindowText(hFilmyTytulFilmuEdit,tytul,40);
                     GetWindowText(hFilmyNowaCenaEdit,cena,20);

                     if(!strcmp(tytul,"") || !strcmp(cena,""))
                     {
                        MessageBox( NULL, "Nie podano tytulu lub ceny!", "Nie podano tytulu lub ceny!", MB_ICONEXCLAMATION );
                        SetWindowText(hFilmyTytulFilmuEdit,"");
                        SetWindowText(hFilmyNowaCenaEdit,"");
                        break;
                     }

                     string line;
                     ifstream Plik("wypozycz.txt", ios::in);

                     while(getline(Plik,line))
                     {
                         LPSTR log = strdup( line.c_str());

                         if(!strcmp(tytul,log))
                         {
                            Plik.close();
                            Plik.open("wypozycz.txt");
                            ofstream temp;
                            temp.open("temp.txt");

                            while (getline(Plik, line))
                            {
                                if (line != tytul &&  line != "")
                                    temp << line << endl;
                                else
                                {
                                    temp << line << endl;
                                    temp << cena << endl;
                                    getline(Plik, line);
                                }
                            }
                            temp.close();
                            Plik.close();
                            remove("wypozycz.txt");
                            rename("temp.txt", "wypozycz.txt");
                            MessageBox( NULL, "Zmieniono cene", "Zmieniono cene", MB_OK);
                            SchowajAdministrator();
                            dodajZawartoscAdministratorFilmy(uchwytAdministrator);

                           goto cena;
                     }
                 }
                 MessageBox( NULL, "Nie znaleziono filmu!", "Nie znaleziono filmu o tym tytule!", MB_ICONEXCLAMATION );
                 Plik.close();
                 SetWindowText(hFilmyTytulFilmuEdit,"");
                 SetWindowText(hFilmyNowaCenaEdit,"");
            cena:
                break;
                    break;
                }
            }
            break;
        case WM_CREATE:
            dodajZawartoscAdministrator(uchwytAdministrator);
            dodajZawartoscAdministratorFilmy(uchwytAdministrator);
            break;

        case WM_DESTROY:
            ShowWindow(hOknoLogowania, SW_SHOW);
            DestroyWindow(uchwytAdministrator);
            break;

        default:
            return DefWindowProcW(uchwytAdministrator,komunikat,wparametr,lparametr);
    }
}

void rejestracjaKlasyOknaLogowania(HINSTANCE hUchwyt)
{
    WNDCLASSW klassaOknaLogowania = {0};

    klassaOknaLogowania.hbrBackground = (HBRUSH)COLOR_WINDOW;
    klassaOknaLogowania.hCursor = LoadCursor(NULL,IDC_ARROW);
    klassaOknaLogowania.hInstance = hUchwyt;
    klassaOknaLogowania.lpszClassName = L"Logowanie";
    klassaOknaLogowania.lpfnWndProc = ProceduraOknaLogowania;


    RegisterClassW(&klassaOknaLogowania);
}


void rejestracjaKlasyOknaUzytkownika(HINSTANCE hUchwyt)
{
    WNDCLASSW klassaOknaUzytkownika = {0};

    klassaOknaUzytkownika.hbrBackground = (HBRUSH)COLOR_WINDOW;
    klassaOknaUzytkownika.hCursor = LoadCursor(NULL,IDC_ARROW);
    klassaOknaUzytkownika.hInstance = hUchwyt;
    klassaOknaUzytkownika.lpszClassName = L"Uzytkownik";
    klassaOknaUzytkownika.lpfnWndProc = ProceduraOknaUzytkownika;


    RegisterClassW(&klassaOknaUzytkownika);
}

void rejestracjaKlasyOknaAdministratora(HINSTANCE hUchwyt)
{
    WNDCLASSW klassaOknaAdministratora = {0};

    klassaOknaAdministratora.hbrBackground = (HBRUSH)COLOR_WINDOW;
    klassaOknaAdministratora.hCursor = LoadCursor(NULL,IDC_ARROW);
    klassaOknaAdministratora.hInstance = hUchwyt;
    klassaOknaAdministratora.lpszClassName = L"Administrator";
    klassaOknaAdministratora.lpfnWndProc = ProceduraOknaAdministratora;


    RegisterClassW(&klassaOknaAdministratora);
}

void oknoLogowania()
{
    hOknoLogowania = CreateWindowW(L"Logowanie",L"Wypozyczalnia Filmow",WS_OVERLAPPEDWINDOW | WS_VISIBLE,700,200,500,310,NULL,NULL,NULL,NULL);
}

void oknoUzytkownika(HWND uchwytLogowanie)
{
    CreateWindowW(L"Uzytkownik",L"Urzytkownik",WS_OVERLAPPEDWINDOW | WS_VISIBLE,700,200,740,500,uchwytLogowanie,NULL,NULL,NULL);
    SetWindowText(hLogin,"");
    SetWindowText(hHaslo,"");
    ShowWindow(uchwytLogowanie, SW_HIDE);
}

void oknoAdministratora(HWND uchwytLogowanie)
{
    CreateWindowW(L"Administrator",L"Administrator",WS_OVERLAPPEDWINDOW | WS_VISIBLE,700,200,740,500,uchwytLogowanie,NULL,NULL,NULL);
    SetWindowText(hLogin,"");
    SetWindowText(hHaslo,"");
    ShowWindow(uchwytLogowanie, SW_HIDE);
}

void dodajZawartoscLogowanie(HWND Uchwyt)
{
    CreateWindowW(L"Static", L"Login:",WS_VISIBLE | WS_CHILD,100,100,50,20,Uchwyt,NULL,NULL,NULL);
        hLogin = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,152,100,200,20,Uchwyt,NULL,NULL,NULL);

    CreateWindowW(L"Static", L"Haslo:",WS_VISIBLE | WS_CHILD,100,130,50,20,Uchwyt,NULL,NULL,NULL);
        hHaslo = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,152,130,200,20,Uchwyt,NULL,NULL,NULL);

    CreateWindowW(L"Button",L"Zaloguj",WS_VISIBLE | WS_CHILD,290,160,60,20,Uchwyt,(HMENU)Przycisk_Zaloguj,NULL,NULL);

}

void dodajZawartoscUzytkownik(HWND Uchwyt)
{
    CreateWindowW(L"Button",L"Moje filmy",WS_VISIBLE | WS_CHILD,0,1,130,90,Uchwyt,(HMENU)Przycisk_Moje_Filmy,NULL,NULL);
    CreateWindowW(L"Button",L"Wypozycz film",WS_VISIBLE | WS_CHILD,0,92,130,90,Uchwyt,(HMENU)Przycisk_Wypozycz_Film,NULL,NULL);
    CreateWindowW(L"Button",L"Zmien haslo",WS_VISIBLE | WS_CHILD,0,183,130,90,Uchwyt,(HMENU)Przycisk_Zmien_Haslo,NULL,NULL);
    CreateWindowW(L"Button",L"Wyloguj",WS_VISIBLE | WS_CHILD,0,274,130,90,Uchwyt,(HMENU)Przycisk_Wyloguj,NULL,NULL);
    CreateWindowW(L"Static",L"Ramka",WS_VISIBLE | WS_CHILD | BS_GROUPBOX,0,0,130,465,Uchwyt,(HMENU)NULL,NULL,NULL);
}

void dodajZawartoscUzytkownikMojeFilmy(HWND Uchwyt)
{
    hMojeFilmyTytul = CreateWindowW(L"Static", L"Twoje filmy:",WS_VISIBLE | WS_CHILD,190,55,300,20,Uchwyt,NULL,NULL,NULL);
    hListaMoichFilmow = CreateWindowEx( WS_EX_CLIENTEDGE, "LISTBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | LBS_EXTENDEDSEL, 190, 80, 300, 250, Uchwyt, NULL,NULL, NULL );

            string line;
            string loginUzytkownikaPlik = loginUzytkownika;
            loginUzytkownikaPlik = "Uzytkownicy\\" + loginUzytkownikaPlik + ".txt";
            ifstream Plik(loginUzytkownikaPlik.c_str(), ios::in);

            while(getline(Plik,line))
            {
                SendMessage( hListaMoichFilmow, LB_ADDSTRING, 0,( LPARAM ) line.c_str());
            }

            Plik.close();

    hMojeFilmyTytulFilmu = CreateWindowW(L"Static", L"Tytul filmu:",WS_VISIBLE | WS_CHILD,190,338,80,20,Uchwyt,NULL,NULL,NULL);
    hMojeFilmyTytulFilmuEdit  = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,265,338,200,20,Uchwyt,NULL,NULL,NULL);
    hMojeFilmyZwroc = CreateWindowW(L"Button",L"Zwroc",WS_VISIBLE | WS_CHILD,485,338,70,20,Uchwyt,(HMENU)Przycisk_Zmiana_Zwroc,NULL,NULL);


}

void dodajZawartoscUzytkownikWyporzycz(HWND Uchwyt)
{
    hWypozyczTytul =CreateWindowW(L"Static", L"Dostepne tytuly:",WS_VISIBLE | WS_CHILD,190,55,300,20,Uchwyt,NULL,NULL,NULL);
    hWypozyczyZaDzien = CreateWindowW(L"Static", L"zl/dzien",WS_VISIBLE | WS_CHILD,500,55,300,20,Uchwyt,NULL,NULL,NULL);
    hWypozyczLista = CreateWindowEx( WS_EX_CLIENTEDGE, "LISTBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | LBS_EXTENDEDSEL, 190, 80, 300, 250, Uchwyt, NULL,NULL, NULL );
    hWypozyczCeny = CreateWindowW(L"Static", L"",WS_VISIBLE | WS_CHILD ,520,80,80,250,Uchwyt,NULL,NULL,NULL);
    hWypozyczTytulFilmu = CreateWindowW(L"Static", L"Tytul filmu:",WS_VISIBLE | WS_CHILD,190,338,80,20,Uchwyt,NULL,NULL,NULL);
    hWypozyczTytulFilmuEdit  = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,265,338,200,20,Uchwyt,NULL,NULL,NULL);
    hWypozyczTytulWypozycz = CreateWindowW(L"Button",L"Wypozycz",WS_VISIBLE | WS_CHILD,485,338,80,20,Uchwyt,(HMENU)Przycisk_Zmiana_Wypozycz,NULL,NULL);

            string line,ceny="";
            ifstream Wyporzycz("wypozycz.txt", ios::in);

            while(getline(Wyporzycz,line))
            {
               SendMessage( hWypozyczLista, LB_ADDSTRING, 0,( LPARAM ) line.c_str());
              getline(Wyporzycz,line);
              ceny += line+"\n";
            }

            Wyporzycz.close();

        LPSTR ceny_wyswietlanie= strdup( ceny.c_str() );
        SetWindowText(hWypozyczCeny,ceny_wyswietlanie);
}

void dodajZawartoscUzytkownikZmianaHasla1(HWND Uchwyt)
{
     hZmianaHaslaNoweTytul = CreateWindowW(L"Static", L"Wprowadz dotychczasowe dane:",WS_VISIBLE | WS_CHILD,280,115,400,40,Uchwyt,NULL,NULL,NULL);
     hZmianaHaslaLogin = CreateWindowW(L"Static", L"Login:",WS_VISIBLE | WS_CHILD,280,150,50,20,Uchwyt,NULL,NULL,NULL);
     hZmianaHaslaLoginEdit = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,332,150,200,20,Uchwyt,NULL,NULL,NULL);

     hZmianaHaslaHaslo = CreateWindowW(L"Static", L"Haslo:",WS_VISIBLE | WS_CHILD,280,180,50,20,Uchwyt,NULL,NULL,NULL);
     hZmianaHaslaHasloEdit = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,332,180,200,20,Uchwyt,NULL,NULL,NULL);

     hZmianaHaslaPotwierdz = CreateWindowW(L"Button",L"Potwierdz",WS_VISIBLE | WS_CHILD,452,210,80,30,Uchwyt,(HMENU)Przycisk_Zmiana_Hasla_Potwierdz,NULL,NULL);
}

void dodajZawartoscUzytkownikZmianaHasla2(HWND Uchwyt)
{
     hZmianaHaslaNoweTytul2 = CreateWindowW(L"Static", L"Wprowadz nowe haslo:",WS_VISIBLE | WS_CHILD,225,115,400,40,Uchwyt,NULL,NULL,NULL);
     hZmianaHaslaNoweHaslo = CreateWindowW(L"Static", L"Nowe haslo:",WS_VISIBLE | WS_CHILD,240,150,80,40,Uchwyt,NULL,NULL,NULL);
     hZmianaHaslaNoweHasloEdit = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,332,150,200,20,Uchwyt,NULL,NULL,NULL);

     hZmianaHaslaPowtorzHaslo2 = CreateWindowW(L"Static", L"Powtorz haslo:",WS_VISIBLE | WS_CHILD,225,180,100,40,Uchwyt,NULL,NULL,NULL);
     hZmianaHaslaPowtorzHasloEdit2 = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,332,180,200,20,Uchwyt,NULL,NULL,NULL);

     hZmianaHaslaZmienHaslo = CreateWindowW(L"Button",L"Zmien haslo",WS_VISIBLE | WS_CHILD,432,210,100,30,Uchwyt,(HMENU)Przycisk_Zmiana_Hasla_Zmien_Haslo,NULL,NULL);
}

void SchowajUzytkownik()
{
    ShowWindow(hFilm1, SW_HIDE);
    ShowWindow(hListaMoichFilmow, SW_HIDE);
    ShowWindow(hMojeFilmyTytul, SW_HIDE);
    ShowWindow(hMojeFilmyTytulFilmu, SW_HIDE);
    ShowWindow(hMojeFilmyTytulFilmuEdit, SW_HIDE);
    ShowWindow(hMojeFilmyZwroc, SW_HIDE);
    ShowWindow(hWypozyczTytul, SW_HIDE);
    ShowWindow(hWypozyczyZaDzien, SW_HIDE);
    ShowWindow(hWypozyczLista, SW_HIDE);
    ShowWindow(hWypozyczCeny, SW_HIDE);
    ShowWindow(hWypozyczTytulFilmu, SW_HIDE);
    ShowWindow(hWypozyczTytulFilmuEdit, SW_HIDE);
    ShowWindow(hWypozyczTytulWypozycz, SW_HIDE);
    ShowWindow(hZmianaHaslaNoweTytul, SW_HIDE);
    ShowWindow(hZmianaHaslaLogin, SW_HIDE);
    ShowWindow(hZmianaHaslaLoginEdit, SW_HIDE);
    ShowWindow(hZmianaHaslaHaslo, SW_HIDE);
    ShowWindow(hZmianaHaslaHasloEdit, SW_HIDE);
    ShowWindow(hZmianaHaslaPotwierdz, SW_HIDE);
    ShowWindow(hZmianaHaslaNoweTytul2, SW_HIDE);
    ShowWindow(hZmianaHaslaNoweHaslo, SW_HIDE);
    ShowWindow(hZmianaHaslaNoweHasloEdit, SW_HIDE);
    ShowWindow(hZmianaHaslaPowtorzHaslo2, SW_HIDE);
    ShowWindow(hZmianaHaslaPowtorzHasloEdit2, SW_HIDE);
    ShowWindow(hZmianaHaslaZmienHaslo, SW_HIDE);
}

void dodajZawartoscAdministrator(HWND Uchwyt)
{
    CreateWindowW(L"Button",L"Filmy",WS_VISIBLE | WS_CHILD,0,1,130,90,Uchwyt,(HMENU)Przycisk_Filmy,NULL,NULL);
    CreateWindowW(L"Button",L"Usun uzytkownika",WS_VISIBLE | WS_CHILD,0,92,130,90,Uchwyt,(HMENU)Przycisk_Usun_Uzytkownika,NULL,NULL);
    CreateWindowW(L"Button",L"Dodaj uzytkownika",WS_VISIBLE | WS_CHILD,0,183,130,90,Uchwyt,(HMENU)Przycisk_Dodaj_Uzytkownika,NULL,NULL);
    CreateWindowW(L"Button",L"Wyloguj",WS_VISIBLE | WS_CHILD,0,274,130,90,Uchwyt,(HMENU)Przycisk_Wyloguj,NULL,NULL);
    CreateWindowW(L"Static",L"Ramka",WS_VISIBLE | WS_CHILD | BS_GROUPBOX,0,0,130,465,Uchwyt,(HMENU)NULL,NULL,NULL);
}

void dodajZawartoscAdministratorFilmy(HWND Uchwyt)
{
    hFilmyTytul = CreateWindowW(L"Static", L"Dostepne tytuly",WS_VISIBLE | WS_CHILD,165,15,300,20,Uchwyt,NULL,NULL,NULL);
    hFilmyZaDzien = CreateWindowW(L"Static", L"zl/dzien",WS_VISIBLE | WS_CHILD,475,15,300,20,Uchwyt,NULL,NULL,NULL);
    hListaFilmow = CreateWindowEx( WS_EX_CLIENTEDGE, "LISTBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | LBS_EXTENDEDSEL, 165, 40, 300, 250, Uchwyt, NULL,NULL, NULL );
    hFilmyCeny = CreateWindowW(L"Static", L"",WS_VISIBLE | WS_CHILD ,495,40,80,250,Uchwyt,NULL,NULL,NULL);

    hFilmyNowyFilm = CreateWindowW(L"Static", L"Nowy film:",WS_VISIBLE | WS_CHILD,175,305,80,20,Uchwyt,NULL,NULL,NULL);
    hFilmyNowyFilmEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,250,305,200,20,Uchwyt,NULL,NULL,NULL);
    hFilmyCena = CreateWindowW(L"Static", L"Cena:",WS_VISIBLE | WS_CHILD,470,305,45,20,Uchwyt,NULL,NULL,NULL);
    hFilmyCenaEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,515,305,50,20,Uchwyt,NULL,NULL,NULL);
    hFilmyOk1 = CreateWindowW(L"Button",L"Ok",WS_VISIBLE | WS_CHILD,585,305,40,20,Uchwyt,(HMENU)Przycisk_Filmy_Nowy_Film,NULL,NULL);
    hFilmyUsunFilm = CreateWindowW(L"Static", L"Usun film:",WS_VISIBLE | WS_CHILD,175,338,80,20,Uchwyt,NULL,NULL,NULL);
    hFilmyUsunFilmEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,250,338,200,20,Uchwyt,NULL,NULL,NULL);
    hFilmyOk2 = CreateWindowW(L"Button",L"Ok",WS_VISIBLE | WS_CHILD,470,338,40,20,Uchwyt,(HMENU)Przycisk_Filmy_Usun_Film,NULL,NULL);
    hFilmyZmienCene = CreateWindowW(L"Static", L"Zmien cene",WS_VISIBLE | WS_CHILD,175,370,80,20,Uchwyt,NULL,NULL,NULL);
    hFilmyTytulFilmu = CreateWindowW(L"Static", L"Tytul filmu:",WS_VISIBLE | WS_CHILD,175,398,80,20,Uchwyt,NULL,NULL,NULL);
    hFilmyTytulFilmuEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,250,398,200,20,Uchwyt,NULL,NULL,NULL);
    hFilmyNowaCena = CreateWindowW(L"Static", L"Nowa cena:",WS_VISIBLE | WS_CHILD,470,398,90,20,Uchwyt,NULL,NULL,NULL);
    hFilmyNowaCenaEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,550,398,50,20,Uchwyt,NULL,NULL,NULL);
    hFilmyOk3 = CreateWindowW(L"Button",L"Ok",WS_VISIBLE | WS_CHILD,620,398,40,20,Uchwyt,(HMENU)Przycisk_Filmy_Zmien_Cene,NULL,NULL);
    hFilmyRamka = CreateWindowW(L"Static",L"Ramka",WS_VISIBLE | WS_CHILD | BS_GROUPBOX,165,295,505,133,Uchwyt,(HMENU)NULL,NULL,NULL);

            string line,ceny="";
            ifstream Plik("wypozycz.txt", ios::in);

            while(getline(Plik,line))
            {
              SendMessage( hListaFilmow, LB_ADDSTRING, 0,( LPARAM ) line.c_str());
              getline(Plik,line);
              ceny += line+"\n";
            }

            Plik.close();
    LPSTR ceny_wyswietlanie= strdup( ceny.c_str() );
    SetWindowText(hFilmyCeny,ceny_wyswietlanie);
}

void dodajZawartoscAdministratorDodacUzytkownika(HWND Uchwyt)
{
    hDodacUzytkownikaTytul = CreateWindowW(L"Static", L"Dodaj uzytkownika:",WS_VISIBLE | WS_CHILD,278,110,150,40,Uchwyt,NULL,NULL,NULL);
    hDodacUzytkownikaLogin = CreateWindowW(L"Static", L"Login:",WS_VISIBLE | WS_CHILD,278,150,60,40,Uchwyt,NULL,NULL,NULL);
    hDodacUzytkownikaLoginEdit = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,332,150,200,20,Uchwyt,NULL,NULL,NULL);
    hDodacUzytkownikaHaslo = CreateWindowW(L"Static", L"Haslo:",WS_VISIBLE | WS_CHILD,278,180,60,40,Uchwyt,NULL,NULL,NULL);
    DodacUzytkownikaHasloEdit = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,332,180,200,20,Uchwyt,NULL,NULL,NULL);
    DodacUzytkownikaDodaj = CreateWindowW(L"Button",L"Dodaj",WS_VISIBLE | WS_CHILD,452,210,80,30,Uchwyt,(HMENU)Przycisk_Dodaj_Uzytkownika_Dodaj,NULL,NULL);
}

void dodajZawartoscAdministratorUsunUzytkownika(HWND Uchwyt)
{
    hUsunUzytkownikaTytul = CreateWindowW(L"Static", L"Usun uzytkownika:",WS_VISIBLE | WS_CHILD,278,110,150,40,Uchwyt,NULL,NULL,NULL);
    hUsunUzytkownikaLogin = CreateWindowW(L"Static", L"Login:",WS_VISIBLE | WS_CHILD,278,150,60,40,Uchwyt,NULL,NULL,NULL);
    hUsunUzytkownikaLoginEdit = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,332,150,200,20,Uchwyt,NULL,NULL,NULL);
    hUsunUzytkownikaHaslo = CreateWindowW(L"Static", L"Haslo:",WS_VISIBLE | WS_CHILD,278,180,60,40,Uchwyt,NULL,NULL,NULL);
    hUsunUzytkownikaHasloEdit = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,332,180,200,20,Uchwyt,NULL,NULL,NULL);
    hUsunUzytkownikaHasloUsun = CreateWindowW(L"Button",L"Usun",WS_VISIBLE | WS_CHILD,452,210,80,30,Uchwyt,(HMENU)Przycisk_Dodaj_Uzytkownika_Usun,NULL,NULL);
}


void SchowajAdministrator()
{
        ShowWindow(hFilmyTytul, SW_HIDE);
        ShowWindow(hFilmyZaDzien, SW_HIDE);
        ShowWindow(hListaFilmow, SW_HIDE);
        ShowWindow(hFilmyCeny, SW_HIDE);
        ShowWindow(hFilmyNowyFilm, SW_HIDE);
        ShowWindow(hFilmyNowyFilmEdit, SW_HIDE);
        ShowWindow(hFilmyCena, SW_HIDE);
        ShowWindow(hFilmyCenaEdit, SW_HIDE);
        ShowWindow(hFilmyOk1, SW_HIDE);
        ShowWindow(hFilmyUsunFilm, SW_HIDE);
        ShowWindow(hFilmyUsunFilmEdit, SW_HIDE);
        ShowWindow(hFilmyOk2, SW_HIDE);
        ShowWindow(hFilmyZmienCene, SW_HIDE);
        ShowWindow(hFilmyTytulFilmu, SW_HIDE);
        ShowWindow(hFilmyTytulFilmuEdit, SW_HIDE);
        ShowWindow(hFilmyNowaCena, SW_HIDE);
        ShowWindow(hFilmyNowaCenaEdit, SW_HIDE);
        ShowWindow(hFilmyOk3, SW_HIDE);
        ShowWindow(hFilmyRamka, SW_HIDE);
        ShowWindow(hDodacUzytkownikaTytul, SW_HIDE);
        ShowWindow(hDodacUzytkownikaLogin, SW_HIDE);
        ShowWindow(hDodacUzytkownikaLoginEdit, SW_HIDE);
        ShowWindow(hDodacUzytkownikaHaslo, SW_HIDE);
        ShowWindow(DodacUzytkownikaHasloEdit, SW_HIDE);
        ShowWindow(DodacUzytkownikaDodaj, SW_HIDE);
        ShowWindow(hUsunUzytkownikaTytul, SW_HIDE);
        ShowWindow(hUsunUzytkownikaLogin, SW_HIDE);
        ShowWindow(hUsunUzytkownikaLoginEdit, SW_HIDE);
        ShowWindow(hUsunUzytkownikaHaslo, SW_HIDE);
        ShowWindow(hUsunUzytkownikaHasloEdit, SW_HIDE);
        ShowWindow(hUsunUzytkownikaHasloUsun, SW_HIDE);
}
