/*
Projekt kasyno na semestr 3 WSTI
Mateusz Pietrzyk 3DZI album 5060

Jest problem w black jacku. Nie dziala zakonczenie pentli w
przypadku kiedy gracz lub krupier maja BlackJacka na rozdaniu... :(

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <vector>
#include <windows.h>
#include <vector>
using namespace std;

 class Kolory
{
    //private:
        //int kredyt;
    public:
        //int kredyt;
        Kolory(){
                //kredyt=0;
            }

        /*int dodajKredyt(int &kredyt){
                cout<<"\t\tWrzuc kase zeby grac! (1zl = 10 kredyow): ";
                do{
                    cin>>kredyt;
                    if (cin.good()) break;
                    else
                    {
                        cout<<"Blad! Podaj prawidlowa liczbe!"<<endl;
                        cin.clear();
                        cin.ignore();
                    }
                }while(true);
                kredyt*=10;
                cout<<"Kretyty: "<<kredyt<<"\n";
            } */

        void redBg(){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | BACKGROUND_RED | FOREGROUND_INTENSITY);
            }

        void greenBg(){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | BACKGROUND_GREEN | FOREGROUND_INTENSITY);
            }

        void blueBg(){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY);
            }

        void whiteTxt(){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
            }

        void goldTxt(){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
            }

        void greenTxt(){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            }

        void redTxt(){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
            }

        void violetTxt(){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY );
            }

        void blueTxt(){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }

};
class Bandyta : public Kolory
{

private:

    int roll[9];
    int kredyt, stawka, dodajKase;
    const float wartosc[8]={1, 1.5, 2, 2.5, 3, 4, 5, 20};
    char dalej='t',kredytUp='t';
    char podbij='n';
    char klawisz;

public:

    Bandyta(){
        //kredyt=0;
        stawka=1;
    }

    void welcome(){
        greenTxt(); cout<<"*******************************************************************************\n";
        greenTxt(); cout<<"*                                                                             *\n";
        cout<<"*"; whiteTxt(); cout<<"\t\t\t  Witaj w Jednorekim Bandycie                         "; greenTxt(); cout<<"*\n";
        greenTxt(); cout<<"*                                                                             *\n";
        greenTxt(); cout<<"*******************************************************************************\n";
        getch();
    }

    int opcje(int kredyt){
        system("cls");
        //pokazMenuTop();
        greenTxt(); cout<<"*******************************************************************************\n";
        whiteTxt(); cout<<"\t\tTwoje kredyty: "<<kredyt; cout<<"\t\tStawka: "<<stawka<<"\n";
        greenTxt(); cout<<"*******************************************************************************\n\n";
        whiteTxt();cout<<"\t ("; greenTxt(); cout<<"Enter"; whiteTxt(); cout<<") Dalej!\t("; greenTxt(); cout<<"Z";
        whiteTxt(); cout<<")miana stawki\t("; greenTxt(); cout<<"D"; whiteTxt(); cout<<")odaj kredyty\t("; greenTxt(); cout<<"Q"; whiteTxt(); cout<<")uit\n\n";
        greenTxt(); cout<<"*******************************************************************************\n\n";
    }

    void zmienStawke(){
         whiteTxt();cout<<"\t\tMozliwe stawki 1,2,3,4,5,10,20,30,40,50,100: ";
                do {
                    cin>>stawka;
                    if (stawka==1||stawka==2||stawka==3||stawka==4||stawka==5||stawka==10||
                        stawka==20||stawka==30||stawka==40||stawka==50||stawka==100) break;
                    else
                        {
                        whiteTxt();cout<<"\t\t\tBlad! Podaj prawidlowa liczbe!"<<endl;
                        cin.clear();
                        cin.ignore();
                        }
                    } while(true);
    }

    void dodajKredyt(){
        whiteTxt();cout<<"\t\tWrzuc kase zeby grac! (1zl = 10 kredyow): ";
        do{
            cin>>dodajKase;
            if (cin.good()) break;
            else
            {
                whiteTxt();cout<<"Blad! Podaj prawidlowa liczbe!"<<endl;
                cin.clear();
                cin.ignore();
            }
        }while(true);
        kredyt+=(dodajKase*10);
        cout<<"Kretyty: "<<kredyt<<"\n";

    }

    void pokazMenuTop(){
            greenTxt(); cout<<"*******************************************************************************\n";
            whiteTxt(); cout<<"\t\tTwoje kredyty: "<<kredyt; cout<<"\t\tStawka: "<<stawka<<"\n";
            greenTxt(); cout<<"*******************************************************************************\n\n";
        }

    void pokazMenuBottom(){
            greenTxt(); cout<<"*******************************************************************************\n\n";
            whiteTxt();cout<<"\t ("; greenTxt(); cout<<"Enter"; whiteTxt(); cout<<") Dalej!\t("; greenTxt(); cout<<"Z";
            whiteTxt(); cout<<")miana stawki\t("; greenTxt(); cout<<"D"; whiteTxt(); cout<<")odaj kredyty\t("; greenTxt(); cout<<"Q"; whiteTxt(); cout<<")uit\n\n";
            greenTxt(); cout<<"*******************************************************************************\n\n";
        }

    int losuj(int &kasa){
        kredyt=kasa;
        do{
            klawisz=getch();
            if (klawisz=='z') zmienStawke();
            if (klawisz=='d') dodajKredyt();
            if (klawisz=='q') return kredyt;
            system("cls");

            pokazMenuTop();
            for (int i=0 ; i<9 ; i++) roll[i]=rand()%8;
            //cout<<"*******************************************************************************\n\n";
            whiteTxt();cout<<"\t\t\t\t-------------\n";
            cout<<"\t\t\t\t---"; goldTxt(); cout<<"BANDITO"; whiteTxt(); cout<<"---\n";
            cout<<"\t\t\t\t-------------\n";
            cout<<"\t\t\t\t| "<<roll[3]+1<<" | "<<roll[4]+1<<" | "<<roll[5]+1<<" |\n";
            cout<<"\t\t\t\t*************\n";
            whiteTxt(); cout<<"\t\t\t\t*"; greenBg(); cout<<" "<<roll[0]+1<<" "; whiteTxt(); cout<<"*"; greenBg(); cout<<" "<<roll[1]+1<<" "; whiteTxt(); cout<<"*"; greenBg(); cout<<" "<<roll[2]+1<<" "; whiteTxt(); cout<<"*\n";
            cout<<"\t\t\t\t*************\n";
            cout<<"\t\t\t\t| "<<roll[6]+1<<" | "<<roll[7]+1<<" | "<<roll[8]+1<<" |\n";
            cout<<"\t\t\t\t-------------\n\n";

            // wygrane

            //poziome
           if (roll[3]==roll[4]&&roll[3]==roll[5]&&roll[3]==roll[5])
           {
                whiteTxt(); cout<<"\t\t\t\t     HIT!\n";
                kredyt +=(stawka*wartosc[roll[3]])*2;
                whiteTxt(); cout<<"\t\t\t      Dodano "/*<<setprecision(1)*/<<(stawka*wartosc[roll[3]])*2<<" kredytow!\n";
           }
           else if (roll[0]==roll[1]&&roll[0]==roll[2]&&roll[1]==roll[2])
           {
                whiteTxt(); cout<<"\t\t\t\t     HIT!\n";
                kredyt +=(stawka*wartosc[roll[0]])*2;
                whiteTxt(); cout<<"\t\t\t      Dodano "/*<<setprecision(1)*/<<(stawka*wartosc[roll[0]])*2<<" kredytow!\n";
           }
           else if (roll[6]==roll[7]&&roll[6]==roll[8]&&roll[7]==roll[8])
           {
                whiteTxt(); cout<<"\t\t\t\t     HIT!\n";
                kredyt +=(stawka*wartosc[roll[6]])*2;
                whiteTxt(); cout<<"\t\t\t      Dodano "/*<<setprecision(1)*/<<(stawka*wartosc[roll[6]])*2<<" kredytow!\n";
           }

           //krzyzowe
           else if (roll[3]==roll[1]&&roll[3]==roll[8]&&roll[1]==roll[8]||
                    roll[6]==roll[1]&&roll[6]==roll[5]&&roll[1]==roll[5])
           {
               whiteTxt(); cout<<"\t\t\t\t     HIT!"<<endl;
               kredyt +=(stawka*wartosc[roll[1]])*1.25;
               whiteTxt(); cout<<"\t\t\t      Dodano "/*<<setprecision(1)*/<<(stawka*wartosc[roll[1]])*1.3<<" kredytow!\n";
           }

           //pionowa
           /*
            else if (roll[4]==roll[1]&&roll[4]==roll[7]&&roll[1]==roll[7])
           {
               cout<<"!MEDIUM HIT!"<<endl;
               kredyt +=(stawka*wartosc[roll[1]])*1.5;
               cout<<"Dodano "<<setprecision(1)<<(stawka*wartosc[roll[1]])*1.5<<" kredytow.\n";
           }
           */

           //brak trafienia
            else kredyt-=stawka;
            pokazMenuBottom();
            if (kredyt<stawka)
            {
                whiteTxt(); cout<<"\t     Masz za malo kredytow! Zmien stawke lub dodaj kredyty!\n\n";
                whiteTxt(); cout<<"\t\t("; greenTxt(); cout<<"Z"; whiteTxt(); cout<<")mien stawke ";
                greenTxt(); cout<<"/"; whiteTxt();cout<<" ("; greenTxt(); cout<<"D"; whiteTxt(); cout<<")odaj kredyty ";
                greenTxt(); cout<<"/"; whiteTxt();cout<<" ("; greenTxt(); cout<<"Q"; whiteTxt(); cout<<")uit: ";

                do{
                cin>>kredytUp;
                cout<<"\n\n";
                    if (kredytUp=='z'||kredytUp=='Z')
                        {
                        zmienStawke();
                        break;
                        }
                    else if (kredytUp=='d'||kredytUp=='d')
                        {
                         dodajKredyt();
                         break;
                        }
                    else if(kredytUp=='q'||kredytUp=='Q') return kredyt;
                    else
                    {
                        cout<<"Blad! Podaj wlasciwa opcje."<<endl;
                        cin.clear();
                        cin.ignore();
                    }
                } while(true);
            }
        }  while(klawisz!='13');
        return kredyt;
    }
};

class BlackJack : public Kolory
{
private:
    string kartyGracz[6], kartyKrup[6], karta;
    string kartaKolor[4]= {"Kier","Trefl","Karo","Pik"};
    string kartaFigura[13]= {"2","3","4","5","6","7","8","9","10","Walet","Dama","Krol","Ace"};
    const int kartyWartosc[13]/*[52]*/ = {2,3,4,5,6,7,8,9,10,10,10,10,11}; /* ,
                            2,3,4,5,6,7,8,9,10,10,10,10,11,
                            2,3,4,5,6,7,8,9,10,10,10,10,11,
                            2,3,4,5,6,7,8,9,10,10,10,10,11}; */
    int stawka, kredyt, wartoscKarty, sumaGracz, sumaKrup, face , suit, czyBJ, Xgracz, Xkrup, pomAce, czyAce=0, pomAce2, czyAce2=0,zmiana=0,dodajKase;
    bool next = false;
    char hitStay, keepGoing;
public:
    BlackJack(){
        stawka=1;
        sumaGracz=0;
        sumaKrup=0;
        wartoscKarty=0;
        czyBJ=0;
        Xgracz=0;
        Xkrup=0;
        czyAce=0;
        pomAce=0;
        pomAce2=0;
        czyAce2=0;
        zmiana=0;
    }

    void welcome(){
        greenTxt(); cout<<"*******************************************************************************\n";
        greenTxt(); cout<<"*                                                                             *\n";
        cout<<"*"; whiteTxt(); cout<<"\t\t\t      Witaj w grze BlackJack                          "; greenTxt(); cout<<"*\n";
        greenTxt(); cout<<"*                                                                             *\n";
        greenTxt(); cout<<"*******************************************************************************\n";
        getch();
    }

    void dodajKredyt(int kredyt){
        cout<<"\t\tWrzuc kase zeby grac! (1zl = 10 kredyow): ";
        do{
            cin>>dodajKase;
            if (cin.good()) break;
            else
            {
                cout<<"Blad! Podaj prawidlowa liczbe!"<<endl;
                cin.clear();
                cin.ignore();
            }
        }while(true);
        kredyt+=(dodajKase*10);
        cout<<"Kretyty: "<<kredyt<<"\n";
    }

    int dodajKarte(){
        suit = rand()%4;
        face = rand()%13;

        wartoscKarty = kartyWartosc[face];
        return wartoscKarty;
    }

    void pokazMenuTop(){
            greenTxt(); cout<<"*******************************************************************************\n";
            whiteTxt(); cout<<"\t\tTwoje kredyty: "<<kredyt; cout<<"\t\tStawka: "<<stawka<<"\n";
            greenTxt(); cout<<"*******************************************************************************\n\n";
        }

    void pokazKarte(){
        cout<<kartaFigura[face]<<" "<<kartaKolor[suit]<<" ";
        karta ={kartaFigura[face]+" "+kartaKolor[suit]}; //zapisuje kolor i wartosc karty do zmiennej karta aby moc ja zapisac w tablicy kartyGracza badz karty Krupiera
    }

    void zakrytaKartaKrupiera(){
        karta ={kartaFigura[face]+" "+kartaKolor[suit]};
    }

    void reset(){
        sumaGracz=0;
        sumaKrup=0;
        wartoscKarty=0;
        czyBJ=0;
        Xgracz=0;
        Xkrup=0;
    }

    int play(int kasa){
    //START:
    kredyt=kasa;
    do{
        reset();
        system("cls");
        pokazMenuTop();
        whiteTxt(); cout<<"\t\t\tPodaj ile chcesz postawic: ";
        do{
            cin>>stawka;
            if (cin.good()&&stawka<=kredyt) break;
            else
            {
                whiteTxt(); cout<<"\t\tBlad! Za malo kredytow lub niewlasciwa liczba!"<<endl;
                cin.clear();
                cin.ignore();
            }
        }while(true);
        system ("cls");
        kredyt-=stawka;
        pokazMenuTop();
        whiteTxt(); cout<<"\t\t\t\t\t\t\tKarty Krupiera: \n\n";
        pomAce2=dodajKarte();
        sumaKrup+=pomAce2;
        if(pomAce2==11) czyAce2=1;
        else czyAce2=0;
        cout<<"\t\t\t\t\t\t\t";pokazKarte();
        kartyKrup[Xkrup]=karta;
        pomAce2=dodajKarte();
        if(czyAce2==0){
            if(pomAce2==11) czyAce2=1;
        }
        czyBJ=sumaKrup+pomAce2;
        Xkrup++;
        zakrytaKartaKrupiera();
        kartyKrup[Xkrup]=karta;
        cout<<"\n";
            if(sumaKrup==10||sumaKrup==11)
            {
                if(czyBJ==21)
                {   //nie wiem czemu nie konczy petli
                    whiteTxt(); cout<<"\t\t\t\t\t\tKrupier ma BlackJacka! Przegrales!\n";
                    whiteTxt(); cout<<"\t\t\t\t\t\tDruga karta krupiera to: "<<kartyKrup[1]<<endl;
                    break;
                    next = true;
                    keepGoing='13';
                    return keepGoing;
                    //goto(START);
                }
                else if(czyBJ<21) { whiteTxt(); cout<<"\t\t\t\t\t\tKrupier nie ma BlackJacka\n"; }
            }
        //cout<<"krupier as: "<<czyAce2<<endl;
        cout<<endl;
        whiteTxt(); cout<<"\t\t\t\t\t\t\tPunkty krupier: "<<sumaKrup<<"\n";
        cout<<endl;

        whiteTxt(); cout<<"\tKarty Gracza: \n\n";
        pomAce=dodajKarte();
        sumaGracz+=pomAce;
        cout<<"\t"; pokazKarte();
        cout<<"\n";
        kartyGracz[Xgracz]=karta;
        if(pomAce==11) czyAce=1;
        else czyAce=0;
        pomAce=dodajKarte();
        sumaGracz+=pomAce;
        if(czyAce==0){
            if(pomAce==11) czyAce=1;
        }
        Xgracz++;
         cout<<"\t"; pokazKarte();
        kartyGracz[Xgracz]=karta;
        cout<<"\n\n";
        whiteTxt(); cout<<"\tPunkty gracza: "<<sumaGracz<<"\n";
        cout<<"\n";

        if(sumaGracz==21)
        {
            whiteTxt(); cout<<"\nGracz ma BlackJacka!\n";
            kredyt+=(stawka*2)+(stawka/2);
            break;
            next = true;
            keepGoing='13';
        }

        //Hitujemy / stejujemy
    do{
            greenTxt(); cout<<"*******************************************************************************\n\n";
            whiteTxt(); cout<<"\t\t\t    ("; greenTxt(); cout<<"H"; whiteTxt(); cout<<")it   czy  ("; greenTxt(); cout<<"S"; whiteTxt();cout<<")tay?: ";
            do{
                cin>>hitStay;
                    if (hitStay=='h'||hitStay=='H'||hitStay=='s'||hitStay=='S')break;
                    else
                    {
                        whiteTxt(); cout<<"\t\t\tBlad! Podaj wlasciwa opcje."<<endl;
                        cin.clear();
                        cin.ignore();
                    }
                } while(true);

            system("cls");
            if(hitStay=='h'||hitStay=='H')
            {
                pokazMenuTop();
                //greenTxt(); cout<<"*******************************************************************************\n\n";
                whiteTxt(); cout<<"\t\t\t\t\t\t\tKarty Krupiera: \n\n";
                //for (int i =0 ; i<=Xkrup ; i++){
                    cout<<"\t\t\t\t\t\t\t"<<kartyKrup[0]<<"\n";
                //}
                cout<<"\n";
                whiteTxt(); cout<<"\t\t\t\t\t\t\tPunkty krupier: "<<sumaKrup<<"\n";
                cout<<"\n";

                whiteTxt(); cout<<"\tKaty gracza: \n\n";
                for (int i =0 ; i<=Xgracz ; i++){
                    cout<<"\t"<<kartyGracz[i]<<endl;
                }
                pomAce=dodajKarte();
                sumaGracz+=pomAce;
                if(czyAce==0){
                    if(pomAce==11) czyAce=1;
                }
                Xgracz++;
                cout<<"\t"; pokazKarte();
                kartyGracz[Xgracz]=karta;
                if(zmiana!=1){ //zapewnia ze odejmowanie 10 od sumy nie powtorzy sie za kazdymr azem jesli wynik bedzie przekraczal 21
                    if(czyAce==1){
                            if(sumaGracz>21){
                                sumaGracz=sumaGracz-10;
                                zmiana=1;
                                }
                    }
                }
                cout<<"\n";
                whiteTxt(); cout<<"\tPunkty gracza: "<<sumaGracz<<"\n";
                cout<<"\n";

                if (sumaGracz>21){
                    redTxt(); cout<<"\t\t\t\tB U S T E D !\n";
                    next = true;
                }
                else next=false;
            }



            if(hitStay=='s'||hitStay=='S')
            {
                pokazMenuTop();
                whiteTxt(); cout<<"\t\t\t\t\t\t\tKarty Krupiera: \n\n";
                for (int i =0 ; i<=Xkrup ; i++){
                    cout<<"\t\t\t\t\t\t\t"<<kartyKrup[i]<<"\n";
                }
                if(czyBJ<17){
                do{
                    cout<<"\t\t\t\t\t\t\t"; pomAce2=dodajKarte(); cout<<"\n";
                    czyBJ+=pomAce2;
                    if(czyAce2==0){
                        if(pomAce2==11) czyAce2=1;
                    }
                    Xkrup++;
                    cout<<"\t\t\t\t\t\t\t"; pokazKarte(); cout<<"\n";
                    kartyKrup[Xkrup]=karta;
                    //sprawdza czy z asem i po ustawieniu wartosci asa na 1 suma pkt jest mniejsza niz 17
                    if(czyAce2==1){
                        if(czyBJ>21){
                            czyBJ=czyBJ-10;
                            if(czyBJ<17){
                                cout<<"\t\t\t\t\t\t\t"; pomAce2=dodajKarte(); cout<<"\n";
                                czyBJ+=pomAce2;
                                if(czyAce2==0){
                                if(pomAce2==11) czyAce2=1;
                                }
                                Xkrup++;
                                cout<<"\t\t\t\t\t\t\t"; pokazKarte(); cout<<"\n";
                                kartyKrup[Xkrup]=karta;
                            }
                        }
                    }
                    //cout<<"czyBJ: "<<czyBJ<<" czyace "<<czyAce2<<endl;
                }while(czyBJ<17);
                }


                cout<<"\n";
                whiteTxt(); cout<<"\t\t\t\t\t\t\tPunkty krupier: "<<czyBJ<<"\n";

                whiteTxt(); cout<<"\tKaty gracza:\n";
                for (int i =0 ; i<=Xgracz ; i++){
                    cout<<"\t"<<kartyGracz[i]<<"\n";
                }
                cout<<"\n";
                whiteTxt(); cout<<"\tPunkty gracza: "<<sumaGracz<<"\n";
                cout<<"\n";
                if(czyBJ>21){
                    redTxt(); cout<<"\t\t\t\tKrupier B U S T E D !\n\n";
                    cout<<"\n";
                    kredyt+=(stawka*2);
                    next=true;
                }
                else if(sumaGracz>czyBJ){
                    goldTxt(); cout<<"\t\t\t\tGracz WYGRYWA!\n";
                    cout<<"\n";
                    kredyt+=(stawka*2);
                    next=true;
                }
                  else if(sumaGracz<czyBJ){
                    goldTxt(); cout<<"\t\t\t\tKrupier WYGRYWA!\n";
                    cout<<"\n";
                    next=true;
                }
                else if(sumaGracz==czyBJ){
                    violetTxt(); cout<<"\t\t\t\t    REMIS!\n";
                    cout<<"\n";
                    kredyt+=stawka;
                    next=true;
                }
            }
        }while(next!=true);
        greenTxt();cout<<"*******************************************************************************\n\n";
        whiteTxt();cout<<"\t\t\t\tTwoje kredyty: "<<kredyt<<"\n\n";
        whiteTxt();cout<<"\t ("; greenTxt(); cout<<"Enter"; whiteTxt(); cout<<") graj dalej \t(";
        greenTxt(); cout<<"D"; whiteTxt(); cout<<")odaj kredyty\t\t("; greenTxt(); cout<<"Q"; whiteTxt(); cout<<")uit\n\n";

        keepGoing=getch();
        if(keepGoing=='d'||keepGoing=='D') {
            int cash=kredyt;
            dodajKredyt(kredyt);
            kredyt+=cash;
            keepGoing=='13';
        }
        else if(keepGoing=='q'||keepGoing=='Q') return kredyt;

     }while(keepGoing!='13');

    return kredyt;
    }

};

class Ruletka : public Kolory
{
    private:
        int stawka,kredyt,wylosowanaLiczba,random,dodajKase;
        const int liczby[37]={ 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
        char kolory[37]{'b','r','b','r','b','r','b','r','b','r','b','b','r','b','r','b','r','b','r','r','b','r','b','r','b','r','b','r','b','b','r','b','r','b','r','b','r'};
        char kolorLiczby;
        int postawPoziomoRz1,postawPoziomoRz2,postawPoziomoRz3,
            postawPionowo1st12,postawPionowo2nd12,postawPionowo3rd12,postawPolowki1to18,
            postawPolowki19to36,postawPazysteTak,postawPazysteNie,postawKolorR,postawKolorB;
        int stawkaPostawPoziomoRz1,
            stawkaPostawPoziomoRz2,
            stawkaPostawPoziomoRz3,
            stawkaPostawPionowo1st12,
            stawkaPostawPionowo2nd12,
            stawkaPostawPionowo3rd12,
            stawkaPostawPolowki1to18,
            stawkaPostawPolowki19to36,
            stawkaPostawPazysteTak,
            stawkaPostawPazysteNie,
            stawkaPostawKolorB,
            stawkaPostawKolorR;
        const int liczbyPoziomoRz1[12]={1,4,7,10,13,16,19,22,25,28,31,34};
        const int liczbyPoziomoRz2[12]={2,5,8,11,14,17,20,23,26,29,32,35};
        const int liczbyPoziomoRz3[13]={3,6,9,12,15,18,21,24,27,30,33,36};
        const int liczbyPionowo1st12[12]={1,2,3,4,5,6,7,8,9,10,11,12};
        const int liczbyPionowo2nd12[12]={13,14,15,16,17,18,19,20,21,22,23,24};
        const int liczbyPionowo3rd12[12]={25,26,27,28,29,30,31,32,33,34,35,36};
        const int liczbyPolowki1to18[18]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
        const int liczbyPolowki19to36[18]={19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
        const int liczbyPazyste[18]={2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36};
        const int liczbyNiepazyste[18]={1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35};
        vector<int> postawioneLiczby;
        vector<int> stawkiPostawioneLiczby;

    public:
        Ruletka(){
            stawka=1;
            kredyt=0;
            postawPoziomoRz1=0;
            postawPoziomoRz2=0;
            postawPoziomoRz3=0;
            postawPionowo1st12=0;
            postawPionowo2nd12=0;
            postawPionowo3rd12=0;
            postawPolowki1to18=0;
            postawPolowki19to36=0;
            postawPazysteTak=0;
            postawPazysteNie=0;
            postawKolorB=0;
            postawKolorR=0;
            stawkaPostawPoziomoRz1=1;
            stawkaPostawPoziomoRz2=1;
            stawkaPostawPoziomoRz3=1;
            stawkaPostawPionowo1st12=1;
            stawkaPostawPionowo2nd12=1;
            stawkaPostawPionowo3rd12=1;
            stawkaPostawPolowki1to18=1;
            stawkaPostawPolowki19to36=1;
            stawkaPostawPazysteTak=1;
            stawkaPostawPazysteNie=1;
            stawkaPostawKolorB=1;
            stawkaPostawKolorR=1;
        }

        void reset(){
            postawPoziomoRz1=0;
            postawPoziomoRz2=0;
            postawPoziomoRz3=0;
            postawPionowo1st12=0;
            postawPionowo2nd12=0;
            postawPionowo3rd12=0;
            postawPolowki1to18=0;
            postawPolowki19to36=0;
            postawPazysteTak=0;
            postawPazysteNie=0;
            postawKolorB=0;
            postawKolorR=0;
            stawkaPostawPoziomoRz1=1;
            stawkaPostawPoziomoRz2=1;
            stawkaPostawPoziomoRz3=1;
            stawkaPostawPionowo1st12=1;
            stawkaPostawPionowo2nd12=1;
            stawkaPostawPionowo3rd12=1;
            stawkaPostawPolowki1to18=1;
            stawkaPostawPolowki19to36=1;
            stawkaPostawPazysteTak=1;
            stawkaPostawPazysteNie=1;
            stawkaPostawKolorB=1;
            stawkaPostawKolorR=1;
            postawioneLiczby.clear();
            stawkiPostawioneLiczby.clear();
        }

        void dodajKredyt(){
        cout<<"\t\tWrzuc kase zeby grac! (1zl = 10 kredyow): ";
        do{
            cin>>dodajKase;
            if (cin.good()) break;
            else
            {
                cout<<"Blad! Podaj prawidlowa liczbe!"<<endl;
                cin.clear();
                cin.ignore();
            }
        }while(true);
        kredyt+=(dodajKase*10);
        cout<<"Kretyty: "<<kredyt<<"\n";
        }

        void zmienStawke(){

            if (kredyt!=0){
                cout<<"\t\tPodaj wysokosc stawki: ";
                do{
                    cin>>stawka;
                    if (cin.good()) break;
                    else
                    {
                        cout<<"\t\tBlad! Podaj prawidlowa liczbe!\n"<<endl;
                        cin.clear();
                        cin.ignore();
                    }
                }while(true);
                if(stawka > kredyt)
                {
                    cout<<"\t\tZa Malo kredytow! Ustawiono mansymalna mozliwa stawke.\n";
                    stawka=kredyt;
                    getch();
                }
            }
            else cout<<"\t\tBrak kredytow!\n";
            getch();
        }

        void pokazStol(){

            whiteTxt();
            cout<<"\t";
            for(int i=1;i<13;i++)
                {
                    if(((i*3)!=6)&&((i*3)!=15)&&((i*3)!=24)&&((i*3)!=33))
                        {
                            cout<<" "; redBg(); cout<<(i*3); whiteTxt();
                        }
                    else
                        {
                            cout<<" " << (i*3);
                        }
                }
            cout<<" |"; greenBg(); cout<<" Rz3 "; whiteTxt(); cout<<"|\n";
            cout<<"     "; greenBg(); cout<<"0"; whiteTxt();


            int z = 2;
            for(int i=1;i<12;i++)
                {
                    if(i==1)
                        {
                            cout<< "\t "<<z;
                        }
                    z+=3;
                    if((z)==5||(z)==14||(z)==23||(z)==32)
                        {
                            cout<< " "; redBg(); cout<<z; whiteTxt();
                        }
                    else
                        {
                            cout<< " "<<(z);
                        }
                }
            cout<<" |"; greenBg(); cout<<" Rz2 "; whiteTxt(); cout<<"|\n";


            z = 1;
            for(int i=1;i<12;i++)
                {
                    if(i==1)
                        {
                            cout<<"\t "; redBg(); cout<<z; whiteTxt();
                        }
                    z+=3;
                    if((z)==7||(z)==16||(z)==19||(z)==25||(z)==34)
                        {
                            cout<< " "; redBg(); cout<<z; whiteTxt();
                        }
                    else
                        {
                            cout<< " " <<(z);
                        }
                }
            cout<< " |"; greenBg(); cout<<" Rz1 "; whiteTxt(); cout<<"|\n";

             cout<<"\t|"; greenBg(); cout<<"  1st12 |   2nd12   |\t 3rd12   "; whiteTxt(); cout<<"|\n";
             cout<<"\t|"; greenBg(); cout<<" 1to18 |EVE|"; redBg(); cout << "RED"; whiteTxt(); cout<<"|BLK"; greenBg(); cout<<"|ODD| 19to36 "; whiteTxt(); cout<<"|\n";
        }

        void pokazMenuTop(){
            greenTxt(); cout<<"*******************************************************************************\n";
            whiteTxt(); cout<<"\t\tTwoje kredyty: "<<kredyt; cout<<"\t\tStawka: "<<stawka<<"\n";
            greenTxt(); cout<<"*******************************************************************************\n\n";
        }

        void menuRuletka(){
            cout<<"\n\n";
            whiteTxt(); cout<<"\t   ("; greenTxt(); cout<<"R";whiteTxt(); cout<<")oluj  ";
            whiteTxt(); cout<<"("; greenTxt(); cout<<"P";whiteTxt(); cout<<")ostaw   ";
            whiteTxt(); cout<<"("; greenTxt(); cout<<"S";whiteTxt(); cout<<")tawka   ";
            whiteTxt(); cout<<"("; greenTxt(); cout<<"D";whiteTxt(); cout<<")odaj kredyty   ";
            whiteTxt(); cout<<"("; greenTxt(); cout<<"Q";whiteTxt(); cout<<")uit   \n\n";
        }

        void menuPostaw(){
            cout<<"\n\n";
            whiteTxt(); cout<<"\t\t   ("; greenTxt(); cout<<"L";whiteTxt(); cout<<")iczby  ";
            whiteTxt(); cout<<"("; greenTxt(); cout<<"G";whiteTxt(); cout<<")rupy   ";
            whiteTxt(); cout<<"("; greenTxt(); cout<<"P";whiteTxt(); cout<<")azyste   ";
            whiteTxt(); cout<<"("; greenTxt(); cout<<"K";whiteTxt(); cout<<")olor   \n\n";
        }

        void menuGrupy(){
            cout<<"\n\n";
            whiteTxt(); cout<<"\t\t   ("; greenTxt(); cout<<"1";whiteTxt(); cout<<")Poziomo(-)  ";
            whiteTxt(); cout<<"("; greenTxt(); cout<<"2";whiteTxt(); cout<<")Pionowo(|)   ";
            whiteTxt(); cout<<"("; greenTxt(); cout<<"3";whiteTxt(); cout<<")Polowki   \n\n";
        }

        void menuPoziomo(){
            cout<<"\n\n";
            whiteTxt(); cout<<"\t\t   ("; greenTxt(); cout<<"1";whiteTxt(); cout<<")Rzad 1  ";
            whiteTxt(); cout<<"("; greenTxt(); cout<<"2";whiteTxt(); cout<<")Rzad 2   ";
            whiteTxt(); cout<<"("; greenTxt(); cout<<"3";whiteTxt(); cout<<")Rzad 3   \n\n";
        }

        void menuPionowo(){
            cout<<"\n\n";
            whiteTxt(); cout<<"\t\t   ("; greenTxt(); cout<<"1";whiteTxt(); cout<<")1st12  ";
            whiteTxt(); cout<<"("; greenTxt(); cout<<"2";whiteTxt(); cout<<")2nd12   ";
            whiteTxt(); cout<<"("; greenTxt(); cout<<"3";whiteTxt(); cout<<")3rd12   \n\n";
        }

        void menuPolowki(){
            cout<<"\n\n";
            whiteTxt(); cout<<"\t\t   ("; greenTxt(); cout<<"1";whiteTxt(); cout<<")1-18  ";
            whiteTxt(); cout<<"("; greenTxt(); cout<<"2";whiteTxt(); cout<<")18-36   \n\n";
        }

        void menuPazyste(){
            cout<<"\n\n";
            whiteTxt(); cout<<"\t\t   ("; greenTxt(); cout<<"1";whiteTxt(); cout<<")Pazyste  ";
            whiteTxt(); cout<<"("; greenTxt(); cout<<"2";whiteTxt(); cout<<")Niepazyste   \n\n";
        }

        void menuKolor(){
            cout<<"\n\n";
            whiteTxt(); cout<<"\t\t   ("; greenTxt(); cout<<"1";whiteTxt(); cout<<")Czarne  ";
            whiteTxt(); cout<<"("; greenTxt(); cout<<"2"; whiteTxt();cout<<")";redTxt(); cout<<"Czerwone   \n\n";
        }

        void krecRuletka(){
            random = rand()%37;
            wylosowanaLiczba=liczby[random];
            kolorLiczby=kolory[random];
        }

        void postawLiczbe(int liczba){
            postawioneLiczby.push_back(liczba);
            kredyt-=stawka;
        }

        void postawPoziomo(int wybor){
            if(wybor==1) postawPoziomoRz1=1;
            else if (wybor==2) postawPoziomoRz2=1;
            else if (wybor==3) postawPoziomoRz3=1;
            kredyt-=stawka;
        }

        void postawPionowo(int wybor){
            if(wybor==1) postawPionowo1st12=1;
            else if (wybor==2) postawPionowo2nd12=1;
            else if (wybor==3) postawPionowo3rd12=1;
            kredyt-=stawka;
        }

        void postawPolowki (int wybor){
            if(wybor==1) postawPolowki1to18=1;
            else if (wybor==2) postawPolowki19to36=1;
            kredyt-=stawka;
        }

        void postawPazyste(int wybor){
            if(wybor==1) postawPazysteTak=1;
            else if (wybor==2) postawPazysteNie=1;
            kredyt-=stawka;
        }

        void postawKolor(int wybor){
            if(wybor==1) postawKolorB=1;
            else if (wybor==2) postawKolorR=1;
            kredyt-=stawka;
        }

        void sprawdzWygrana(){
            //liczba

            if (postawioneLiczby.size()!=0)
            {
                for (int i=0 ; i<postawioneLiczby.size() ; i++)
                {
                   if(postawioneLiczby[i]==wylosowanaLiczba)
                    {
                        whiteTxt(); cout<<"\t\tWygrales! \tWygrana: "<<(stawkiPostawioneLiczby[i]*35)<<"\n";
                        kredyt+=(stawkiPostawioneLiczby[i]*35);
                    }
                    else
                    {
                        whiteTxt(); cout<<"\t\tPrzegrales!\n";
                    }
                }
            }

            //poziomo Rz1
            if(postawPoziomoRz1==1)
            {
                bool jest = false;
                for (int i=0 ; i<12 ; i++)
                {
                    if(wylosowanaLiczba==liczbyPoziomoRz1[i])
                    jest=true;
                }
                if(jest==true)
                    {
                        whiteTxt(); cout<<"\t\tWygrales! \tWygrana: "<<(stawkaPostawPoziomoRz1*3)<<"\n";
                        kredyt+=(stawkaPostawPoziomoRz1*3);
                    }
                    else
                    {
                        whiteTxt(); cout<<"\t\tPrzegrales!\n";
                    }
            }

            //poziomo Rz2
            if(postawPoziomoRz2==1)
            {
                bool jest = false;
                for (int i=0 ; i<12 ; i++)
                {
                    if(wylosowanaLiczba==liczbyPoziomoRz2[i])
                    jest=true;
                }
                if(jest==true)
                    {
                        whiteTxt(); cout<<"\t\tWygrales! \tWygrana: "<<(stawkaPostawPoziomoRz2*3)<<"\n";
                        kredyt+=(stawkaPostawPoziomoRz2*3);
                    }
                    else
                    {
                        whiteTxt(); cout<<"\t\tPrzegrales!\n";
                    }
            }

            //poziomo Rz3
            if(postawPoziomoRz3==1)
            {
                bool jest = false;
                for (int i=0 ; i<12 ; i++)
                {
                    if(wylosowanaLiczba==liczbyPoziomoRz3[i])
                    jest=true;
                }
                if(jest==true)
                    {
                        whiteTxt(); cout<<"\t\tWygrales! \tWygrana: "<<(stawkaPostawPoziomoRz3*3)<<"\n";
                        kredyt+=(stawkaPostawPoziomoRz3*3);
                    }
                    else
                    {
                        whiteTxt(); cout<<"\t\tPrzegrales!\n";
                    }
            }

            //pionowo 1st12
            if(postawPionowo1st12==1)
            {
                bool jest = false;
                for (int i=0 ; i<12 ; i++)
                {
                    if(wylosowanaLiczba==liczbyPionowo1st12[i])
                    jest=true;
                }
                if(jest==true)
                    {
                        whiteTxt(); cout<<"\t\tWygrales! \tWygrana: "<<(stawkaPostawPionowo1st12*3)<<"\n";
                        kredyt+=(stawkaPostawPionowo1st12*3);
                    }
                    else
                    {
                        whiteTxt(); cout<<"\t\tPrzegrales!\n";
                    }
            }

            //pionowo 2nd12
            if(postawPionowo2nd12==1)
            {
                bool jest = false;
                for (int i=0 ; i<12 ; i++)
                {
                    if(wylosowanaLiczba==liczbyPionowo2nd12[i])
                    jest=true;
                }
                if(jest==true)
                    {
                        whiteTxt(); cout<<"\t\tWygrales! \tWygrana: "<<(stawkaPostawPionowo2nd12*3)<<"\n";
                        kredyt+=(stawkaPostawPionowo2nd12*3);
                    }
                    else
                    {
                        whiteTxt(); cout<<"\t\tPrzegrales!\n";
                    }
            }

            //pionowo 3rd12
            if(postawPionowo3rd12==1)
            {
                bool jest = false;
                for (int i=0 ; i<12 ; i++)
                {
                    if(wylosowanaLiczba==liczbyPionowo3rd12[i])
                    jest=true;
                }
                if(jest==true)
                    {
                        whiteTxt(); cout<<"\t\tWygrales! \tWygrana: "<<(stawkaPostawPionowo3rd12*3)<<"\n";
                        kredyt+=(stawkaPostawPionowo3rd12*3);
                    }
                    else
                    {
                        whiteTxt(); cout<<"\t\tPrzegrales!\n";
                    }
            }

            //polowki 1-18
            if(postawPolowki1to18==1)
            {
                bool jest = false;
                for (int i=0 ; i<18 ; i++)
                {
                    if(wylosowanaLiczba==liczbyPolowki1to18[i])
                    jest=true;
                }
                if(jest==true)
                    {
                        whiteTxt(); cout<<"\t\tWygrales! \tWygrana: "<<(stawkaPostawPolowki1to18*2)<<"\n";
                        kredyt+=(stawkaPostawPolowki1to18*2);
                    }
                    else
                    {
                        whiteTxt(); cout<<"\t\tPrzegrales!\n";
                    }
            }

            //polowki 19-36
            if(postawPolowki19to36==1)
            {
                bool jest = false;
                for (int i=0 ; i<18 ; i++)
                {
                    if(wylosowanaLiczba==liczbyPolowki19to36[i])
                    jest=true;
                }
                if(jest==true)
                    {
                        whiteTxt(); cout<<"\t\tWygrales! \tWygrana: "<<(stawkaPostawPolowki19to36*2)<<"\n";
                        kredyt+=(stawkaPostawPolowki19to36*2);
                    }
                    else
                    {
                        whiteTxt(); cout<<"\t\tPrzegrales!\n";
                    }
            }

            //pazyste
            if(postawPazysteTak==1)
            {
                bool jest = false;
                for (int i=0 ; i<18 ; i++)
                {
                    if(wylosowanaLiczba==liczbyPazyste[i])
                    jest=true;
                }
                if(jest==true)
                    {
                        whiteTxt(); cout<<"\t\tWygrales! \tWygrana: "<<(stawkaPostawPazysteTak*2)<<"\n";
                        kredyt+=(stawkaPostawPazysteTak*2);
                    }
                    else
                    {
                        whiteTxt(); cout<<"\t\tPrzegrales!\n";
                    }
            }

            //niepazyste
            if(postawPazysteNie==1)
            {
                bool jest = false;
                for (int i=0 ; i<18 ; i++)
                {
                    if(wylosowanaLiczba==liczbyNiepazyste[i])
                    jest=true;
                }
                if(jest==true)
                    {
                        whiteTxt(); cout<<"\t\tWygrales! \tWygrana: "<<(stawkaPostawPazysteNie*2)<<"\n";
                        kredyt+=(stawkaPostawPazysteNie*2);
                    }
                    else
                    {
                        whiteTxt(); cout<<"\t\tPrzegrales!\n";
                    }
            }

            //czarne
            if(postawKolorB==1)
            {
                if(kolorLiczby=='b')
                {
                    whiteTxt(); cout<<"\t\tWygrales! \tWygrana: "<<(stawkaPostawKolorB*2)<<"\n";
                    kredyt+=(stawkaPostawKolorB*2);
                }
                else
                {
                    whiteTxt(); cout<<"\t\tPrzegrales!\n";
                }

            }

            //czerwone
            if(postawKolorR==1)
            {
                if(kolorLiczby=='r')
                {
                    whiteTxt(); cout<<"\t\tWygrales! \tWygrana: "<<(stawkaPostawKolorR*2)<<"\n";
                    kredyt+=(stawkaPostawKolorR*2);
                }
                else
                {
                    whiteTxt(); cout<<"\t\tPrzegrales!\n";
                }

            }
        }

        void pokazZaklady(){
            int zmienna=0;

            //liczba
            if(postawioneLiczby.size()!=0)
            {
                for (int i=0 ; i<postawioneLiczby.size() ; i++)
                {
                    zmienna++;
                    whiteTxt(); cout<<"\t\t"<<zmienna<<". Postawiona liczba: "<<postawioneLiczby[i]; cout<<"\t\tStawka: "<<stawkiPostawioneLiczby[i]<<"\n";
                }
            }

            //poziomo rz1
            if(postawPoziomoRz1==1)
            {
                zmienna++;
                whiteTxt(); cout<<"\t\t"<<zmienna<<". Postawione pole: Rz1 \t\tStawka: "<<stawkaPostawPoziomoRz1<<"\n";
            }

            //poziomo rz2
            if(postawPoziomoRz2==1)
            {
                zmienna++;
                whiteTxt(); cout<<"\t\t"<<zmienna<<". Postawione pole: Rz2 \t\tStawka: "<<stawkaPostawPoziomoRz2<<"\n";
            }

            //poziomo rz3
            if(postawPoziomoRz3==1)
            {
                zmienna++;
                whiteTxt(); cout<<"\t\t"<<zmienna<<". Postawione pole: Rz3 \t\tStawka: "<<stawkaPostawPoziomoRz3<<"\n";
            }

            //ppionow 1st12
            if(postawPionowo1st12==1)
            {
                zmienna++;
                whiteTxt(); cout<<"\t\t"<<zmienna<<". Postawione pole: 1st12 \t\tStawka: "<<stawkaPostawPionowo1st12<<"\n";
            }

            //ppionow 2nd12
            if(postawPionowo2nd12==1)
            {
                zmienna++;
                whiteTxt(); cout<<"\t\t"<<zmienna<<". Postawione pole: 2nd12 \t\tStawka: "<<stawkaPostawPionowo2nd12<<"\n";
            }

            //ppionow 1st12
            if(postawPionowo3rd12==1)
            {
                zmienna++;
                whiteTxt(); cout<<"\t\t"<<zmienna<<". Postawione pole: 3rd12 \t\tStawka: "<<stawkaPostawPionowo3rd12<<"\n";
            }

            //polowki 1-18
            if(postawPolowki1to18==1)
            {
                zmienna++;
                whiteTxt(); cout<<"\t\t"<<zmienna<<". Postawione pole: 1to18 \t\tStawka: "<<stawkaPostawPolowki1to18<<"\n";
            }
            //polowki 19-36
            if(postawPolowki19to36==1)
            {
                zmienna++;
                whiteTxt(); cout<<"\t\t"<<zmienna<<". Postawione pole: 19to36 \t\tStawka: "<<stawkaPostawPolowki19to36<<"\n";
            }

            //pazyste
            if(postawPazysteTak==1)
            {
                zmienna++;
                whiteTxt(); cout<<"\t\t"<<zmienna<<". Postawione pole: EVEN \t\tStawka: "<<stawkaPostawPazysteTak<<"\n";
            }

            //niepazyste
            if(postawPazysteNie==1)
            {
                zmienna++;
                whiteTxt(); cout<<"\t\t"<<zmienna<<". Postawione pole: ODD \t\tStawka: "<<stawkaPostawPazysteNie<<"\n";
            }

            //czarne
            if(postawKolorB==1)
            {
                zmienna++;
                whiteTxt(); cout<<"\t\t"<<zmienna<<". Postawione pole: BLK \t\tStawka: "<<stawkaPostawKolorB<<"\n";
            }

            //czerwone
            if(postawKolorR==1)
            {
                zmienna++;
                whiteTxt(); cout<<"\t\t"<<zmienna<<". Postawione pole: "; redBg() ;cout<<"RED"; whiteTxt(); cout<<"\t\t\tStawka: "<<stawkaPostawKolorR<<"\n";
            }
        }

        int graj(int kasa){
            char wyborMenu;
            kredyt=kasa;

            do{
                system("cls");
                pokazMenuTop();
                pokazStol();
                menuRuletka();
                pokazZaklady();
                wyborMenu=getch();
                //}while(wyborMenu!='r'||wyborMenu!='p'||wyborMenu!='s'||wyborMenu!='d'||wyborMenu!='q')
                switch(wyborMenu)
                {
                case 'r':
                    {
                        krecRuletka();
                        if(kolorLiczby=='r')
                            {
                            whiteTxt();cout<<"\t\tWylosowana liczba: "; redBg(); cout<<wylosowanaLiczba<<"\n"; whiteTxt();
                            }
                        else
                            {
                             whiteTxt(); cout<<"\t\tWylosowana liczba: "<<wylosowanaLiczba<<"\n";
                            }
                            sprawdzWygrana();
                            reset();
                            getch();
                        break;
                    }
                case 'p':
                    {
                        system("cls");
                        pokazMenuTop();
                        pokazStol();
                        menuPostaw();
                        char wyborPostaw;
                        wyborPostaw=getch();
                        switch(wyborPostaw)
                        {
                            case 'l': //liczby
                                {
                                    system("cls");
                                    pokazMenuTop();
                                    pokazStol();
                                    menuPostaw();
                                    int liczba;
                                    whiteTxt();cout<<"\tPodaj na jaka liczbe chcesz postawic: ";
                                    do{
                                        cin>>liczba;
                                        if (liczba<=36||liczba>=0)break;
                                        else
                                        {
                                            cout<<"\t\t\tBlad! Podaj wlasciwa liczbe."<<endl;
                                            cin.clear();
                                            cin.ignore();
                                        }
                                    } while(true);
                                    postawLiczbe(liczba);
                                    //kredyt-=stawka;
                                    stawkiPostawioneLiczby.push_back(stawka);
                                    //stawkaPostawionaLiczba=stawka;
                                    break;
                                }
                            case 'g': //grupy
                                {
                                    system("cls");
                                    pokazMenuTop();
                                    pokazStol();
                                    menuGrupy();
                                    int wyborGrupy;
                                    wyborGrupy=getch();
                                    switch(wyborGrupy)
                                    {
                                        case '1': //poziomo
                                            {
                                            system("cls");
                                            pokazMenuTop();
                                            pokazStol();
                                            menuPoziomo();
                                            int wyborPoziomo;
                                            wyborPoziomo=getch();
                                            switch(wyborPoziomo)
                                                {
                                                case '1': //rz1
                                                    {
                                                        wyborPoziomo=1;
                                                        postawPoziomo(wyborPoziomo);
                                                        stawkaPostawPoziomoRz1=stawka;
                                                        whiteTxt(); cout<<"\t\tPostawiles na Rzad 1.\n";
                                                        getch();
                                                        break;
                                                    }
                                                case '2': //rz2
                                                    {
                                                        wyborPoziomo=2;
                                                        postawPoziomo(wyborPoziomo);
                                                        stawkaPostawPoziomoRz2=stawka;
                                                        whiteTxt(); cout<<"\t\tPostawiles na Rzad 2.\n";
                                                        getch();
                                                        break;
                                                    }
                                                case '3': //rz3
                                                    {
                                                        wyborPoziomo=3;
                                                        postawPoziomo(wyborPoziomo);
                                                        stawkaPostawPoziomoRz3=stawka;
                                                        whiteTxt(); cout<<"\t\tPostawiles na Rzad 3.\n";
                                                        getch();
                                                        break;
                                                    }
                                                }
                                                break;
                                            }
                                        case '2': //pionowo
                                            {
                                            system("cls");
                                            pokazMenuTop();
                                            pokazStol();
                                            menuPionowo();
                                            int wyborPionowo;
                                            wyborPionowo=getch();
                                            switch(wyborPionowo)
                                                {
                                                case '1': //1st12
                                                    {
                                                        wyborPionowo=1;
                                                        postawPionowo(wyborPionowo);
                                                        stawkaPostawPionowo1st12=stawka;
                                                        whiteTxt(); cout<<"\t\tPostawiles na 1st 12.\n";
                                                        getch();
                                                        break;
                                                    }
                                                case '2': //2nd12
                                                    {
                                                        wyborPionowo=2;
                                                        postawPionowo(wyborPionowo);
                                                        stawkaPostawPionowo2nd12=stawka;
                                                        whiteTxt(); cout<<"\t\tPostawiles na 2nd 12.\n";
                                                        getch();
                                                        break;
                                                    }
                                                case '3': //3rd12
                                                    {
                                                        wyborPionowo=3;
                                                        postawPionowo(wyborPionowo);
                                                        stawkaPostawPionowo3rd12=stawka;
                                                        whiteTxt(); cout<<"\t\tPostawiles na 3rd 12.\n";
                                                        getch();
                                                        break;
                                                    }
                                                }
                                            break;
                                            }
                                        case '3': //polowki
                                            {
                                            system("cls");
                                            pokazMenuTop();
                                            pokazStol();
                                            menuPolowki();
                                            int wyborPolowki;
                                            wyborPolowki=getch();
                                            switch(wyborPolowki)
                                                {
                                                case '1': //1to18
                                                    {
                                                    wyborPolowki=1;
                                                    postawPolowki(wyborPolowki);
                                                    stawkaPostawPolowki1to18=stawka;
                                                    whiteTxt(); cout<<"\t\tPostawiles na liczby 1 do 18.\n";
                                                    getch();
                                                    break;
                                                    }
                                                case '2': //18to36
                                                    {
                                                    wyborPolowki=2;
                                                    postawPolowki(wyborPolowki);
                                                    stawkaPostawPolowki19to36=stawka;
                                                    whiteTxt(); cout<<"\t\tPostawiles na liczby 18 do 36.\n";
                                                    getch();
                                                    break;
                                                    }
                                                }
                                            break;
                                            }

                                    }
                                    break;
                                }
                            case 'p': //pazyste
                                {
                                    system("cls");
                                    pokazMenuTop();
                                    pokazStol();
                                    menuPazyste();
                                    int wyborPazyste;
                                    wyborPazyste=getch();
                                    switch(wyborPazyste)
                                    {
                                        case '1': //pazyste
                                            {
                                                wyborPazyste=1;
                                                postawPazyste(wyborPazyste);
                                                stawkaPostawPazysteTak=stawka;
                                                whiteTxt(); cout<<"\t\tPostawiles na pazyste.\n";
                                                getch();
                                                break;
                                            }
                                        case '2': //niepazyste
                                            {
                                                wyborPazyste=2;
                                                postawPazyste(wyborPazyste);
                                                stawkaPostawPazysteNie=stawka;
                                                whiteTxt(); cout<<"\t\tPostawiles na niepazyste.\n";
                                                getch();
                                                break;
                                            }
                                    }
                                    break;
                                }
                            case 'k': //kolor
                                {
                                    system("cls");
                                    pokazMenuTop();
                                    pokazStol();
                                    menuKolor();
                                    int wyborKolor;
                                    wyborKolor=getch();
                                    switch(wyborKolor)
                                    {
                                        case '1': //czarne
                                            {
                                            wyborKolor=1;
                                            postawKolor(wyborKolor);
                                            stawkaPostawKolorB=stawka;
                                            whiteTxt(); cout<<"\t\tPostawiles na kolor czarny\n";
                                            getch();
                                            break;
                                            }
                                        case '2': //cerwone
                                            {
                                            wyborKolor=2;
                                            postawKolor(wyborKolor);
                                            stawkaPostawKolorR=stawka;
                                            whiteTxt(); cout<<"\t\tPostawiles na kolor"; redTxt();cout<<" czerwony\n";
                                            whiteTxt();
                                            getch();
                                            break;
                                            }
                                    }
                                    break;
                                }

                        }
                        getch();
                        break;
                    }
                case 's':
                    {
                        zmienStawke();
                        break;
                    }
                case 'd':
                    {
                        dodajKredyt();
                        break;
                    }

                }
            }while(wyborMenu!='q');
            return kredyt;

        }
};

int main()
{
    srand((unsigned)time(NULL));

    int kasa;
    int wybor;
    Bandyta jb;
    BlackJack jack;
    Ruletka roll;
    Kolory k;

    k.greenTxt(); cout<<"*******************************************************************************\n";
    k.greenTxt(); cout<<"*                                                                             *\n";
    cout<<"*"; k.whiteTxt(); cout<<"                            Witaj w CASINO ROYAL!                            "; k.greenTxt(); cout<<"*\n";
    k.greenTxt(); cout<<"*                                                                             *\n";
    k.greenTxt(); cout<<"*******************************************************************************\n";
    k.greenTxt(); cout<<"*                                                                             *\n";
    k.greenTxt(); cout<<"*"; k.whiteTxt(); cout<<"                        Wrzuc pieniadze aby otrzymac                         "; k.greenTxt(); cout<<"*\n";
    k.greenTxt(); cout<<"*                                                                             *\n";
    k.greenTxt(); cout<<"*"; k.whiteTxt(); cout<<"                               kredyty na gre                                "; k.greenTxt(); cout<<"*\n";
    k.greenTxt(); cout<<"*                                                                             *\n";
    k.greenTxt(); cout<<"*"; k.whiteTxt(); cout<<"                             1 zl = 10 kredytow                              "; k.greenTxt(); cout<<"*\n";
    k.greenTxt(); cout<<"*                                                                             *\n";
    k.greenTxt(); cout<<"*******************************************************************************\n\n";
    k.whiteTxt(); cout<<"                                  Wrzucasz: ";

    do{
    cin>>kasa;
    if (cin.good()) break;
            else
            {
                cout<<"\t\t\tBlad! Podaj prawidlowa liczbe! ";
                cin.clear();
                cin.ignore();
            }
    }while(true);
    kasa*=10;
    cout<<"                          Otrzymujesz: "<<kasa<<" kredytow!\n";
    getch();
    system("cls");

    do{
        //menu();
        k.greenTxt(); cout<<"*******************************************************************************\n";
        k.greenTxt(); cout<<"*                                                                             *\n";
        cout<<"*"; k.whiteTxt(); cout<<"                            Witaj w CASINO ROYAL!                            "; k.greenTxt(); cout<<"*\n";
        k.greenTxt(); cout<<"*                                                                             *\n";
        k.greenTxt(); cout<<"*******************************************************************************\n";
        k.greenTxt(); cout<<"*                                                                             *\n";
        cout<<"*"; k.whiteTxt(); cout<<"                                 Wybierz gre:                                "; k.greenTxt(); cout<<"*\n";
        k.greenTxt(); cout<<"*                                                                             *\n";
        cout<<"*"; k.whiteTxt(); cout<<"                           ("; k.greenTxt();cout<<"1"; k.whiteTxt(); cout<<") Jednoreki bandyta                             "; k.greenTxt(); cout<<"*\n";
        k.greenTxt(); cout<<"*                                                                             *\n";
        cout<<"*"; k.whiteTxt(); cout<<"                           ("; k.greenTxt();cout<<"2"; k.whiteTxt(); cout<<") Black Jack                                    "; k.greenTxt(); cout<<"*\n";
        k.greenTxt(); cout<<"*                                                                             *\n";
        cout<<"*"; k.whiteTxt(); cout<<"                           ("; k.greenTxt();cout<<"3"; k.whiteTxt(); cout<<") Ruletka                                       "; k.greenTxt(); cout<<"*\n";
        k.greenTxt(); cout<<"*                                                                             *\n";
        cout<<"*"; k.whiteTxt(); cout<<"                           ("; k.greenTxt();cout<<"4"; k.whiteTxt(); cout<<") Opusc gre                                     "; k.greenTxt(); cout<<"*\n";
        k.greenTxt(); cout<<"*                                                                             *\n";
        k.greenTxt(); cout<<"*******************************************************************************\n";
        k.whiteTxt();cout<<"                                  Wybierasz: ";

        do {

                cin>>wybor;
                if (wybor==1||wybor==2||wybor==3||wybor==4) break;
                else
                {
                    cout<<"Takie opcje nie istnieja! Sprobuj ponownie."<<endl;
                    cin.clear();
                    cin.ignore();
                }
        } while(true);

        switch (wybor)
        {
        case 1:
            system("cls");
            jb.welcome();
            jb.opcje(kasa);
            jb.losuj(kasa);
            system("cls");
            break;

        case 2:
            system("cls");
            jack.welcome();
            kasa=jack.play(kasa);
            system("cls");
            break;

        case 3:
            roll.graj(kasa);

            //cout<<"Jeszcze nie dziala sorry!\n";
            break;

        case 4:
            cout<<"Zapraszamy ponownie!\n";
            break;
        default: cout<<"Takie opcje nie istnieja! Sprobuj ponownie.";
        }
    }while(wybor!=4);

    cout<<"Stan twojego konta na koniec to: "<<kasa/10<<"  zlotych\n";

    return 0;
}
