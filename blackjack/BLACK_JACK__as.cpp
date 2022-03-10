#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>
using namespace std;
struct player{
int suma=0; int carti[21]; int k=0;

}p[10];

char sw(int x)
{char l[6]={'A','J','Q','K',};
char c[2]={'1','0',};
    if(x==1) return  l[0];
    if(x==2) return  '2';
    if(x==3) return  '3';
    if(x==4) return  '4';
    if(x==5) return  '5';
    if(x==6) return  '6';
    if(x==7) return  '7';
    if(x==8) return  '8';
    if(x==9) return  '9';
    if(x==10) return  '0';
    if(x==11) return l[0];
    if(x==12) return l[1];
    if(x==13) return l[2];
    if(x==14) return l[3];
}
int sc(int x)
{
    if(x<=11) return x;
    if(x>11) return 10;
}

void shuffle(int h[200])
{int i,aux,j;

for (i=1;i<=12;i++){h[i]=11;}
for (i=13;i<=24;i++){h[i]=2;}
for (i=25;i<=36;i++){h[i]=3;}
for (i=37;i<=48;i++){h[i]=4;}
for (i=49;i<=60;i++){h[i]=5;}
for (i=61;i<=72;i++){h[i]=6;}
for (i=73;i<=84;i++){h[i]=7;}
for (i=85;i<=96;i++){h[i]=8;}
for (i=97;i<=108;i++){h[i]=9;}
for (i=109;i<=120;i++){h[i]=10;}
for (i=121;i<=132;i++){h[i]=12;}
for (i=133;i<=144;i++){h[i]=13;}
for (i=145;i<=156;i++){h[i]=14;}

 for(j=1;j<=300;j++){
int x=rand()%156+1;
int y=rand()%156+1;
    aux=h[x];
    h[x]=h[y];
    h[y]=aux;
}}
void afisare(int x)
{
    if(sw(x)!='0'){cout<<sw(x)<<" ";}
                      else {cout<<"10"<<" ";}}


int main()
{srand(time(NULL));

    int v[200],i,j,n,m,aux,a,OK1=1,OK2,z,q,pozitie=1;
    cout<<"--------------------------------------------"<<endl<<"                 BLACK JACK                 "<<endl<<"--------------------------------------------"<<endl<<"           What do you want to do?           "<<endl<<"            Play(1)   Leave(0)            "<<endl;
    cin>>n; system("cls"); if(n!=1){while(n!=1){cout<<"SCARED???";}}
shuffle(v);
j=0;
while (OK1==1){if(n==1){ /*cout<<"LOADING"; sleep(1); cout<<"."<<" ";sleep(1); cout<<"."<<" ";sleep(1); cout<<"."<<" ";sleep(1); system("cls"); cout<<"LOADING"; sleep(1); cout<<"."<<" ";sleep(1); cout<<"."<<" ";sleep(1); cout<<"."<<" ";sleep(1); system("cls");cout<<"LOADING"; sleep(1); cout<<"."<<" ";sleep(1); cout<<"."<<" ";sleep(1); cout<<"."<<" ";sleep(1); system("cls");*/cout<<"Please select the number of players: ";cin>>m;system("cls");
    for(i=1;i<=m;i++)
    {   for(int numar= 1;numar<= p[i].k;numar++)
            p[i].carti[numar] = 0;
        p[i].suma=0;
        p[i].k=0;

    }
    int nr = 1;
    while(nr <= 2){
for(i=1;i<=m;i++)
{
    p[i].k=p[i].k+1;
    int t= p[i].k;
    j++;
    p[i].carti[t]=v[j];
    p[i].suma=p[i].suma+sc(v[j]);
}
nr++;
}
cout<<"   HIT(1)   STAY(0)   "<<endl<<endl;
for(i=1;i<=m;i++)
{if(i==m)
    {cout<<"  Dealer"<<"  : ? "; afisare((p[i].carti[2]));
                                   }

  else{cout<<"  Player "<<i<<": "; afisare((p[i].carti[1]));
                                   afisare((p[i].carti[2]));}
cout<< endl;
}i=1;int max=0;;
  while (i<m)
  {     if(p[i].suma == 21)
            cout<<"  Player "<<i<<" has 21"<<endl;

  else {
      while (p[i].suma<21)
      {  if(i!=m){
          cin>>a;
          if (a==1)
          {
              p[i].k=p[i].k+1;
              int t= p[i].k;
              j++;
              p[i].carti[t]=v[j];
              p[i].suma=p[i].suma+sc(v[j]);

              cout<<"  Player "<<i<<" new hand: ";
              for (int l=1;l<=t;l++)
               { afisare((p[i].carti[l])); cout<<" ";}
               cout<<endl;
                int as=0;
              if(p[i].suma>21){
                for(int z=1;z<=t;z++){int o=0;
                    if(p[i].carti[z]==11){o++;
                        p[i].suma=p[i].suma-10;p[i].carti[z]=1;break;}

                    else if (o==0){as=1;}
                }
              }

              if((p[i].suma>21)&&(as==1)){cout<<"  Player "<<i<<" BUSTED with: "<<p[i].suma<<endl; p[i].suma=0;break;}
              if(p[i].suma==21){cout<<endl<<"  Player "<<i<<" has 21"<<endl; break;}
              }
          else if(a==0){cout<<"  Player "<<i<<" STAYS "<<endl<<endl;break;}}


      }}i++;pozitie=1;}

      if(i==m){
            if(p[i].suma>=17){cout<<endl<<"  Dealer's hand: ";
              for (int l=1;l<=2;l++)
               { afisare((p[m].carti[l])); cout<<" ";}cout<<endl;}


            while(p[i].suma<17)
            {               j++;
              p[i].k=p[i].k+1;
               z= p[i].k;
              p[i].carti[z]=v[j];
              p[i].suma=p[i].suma+sc(v[j]);

       cout<<endl<<"  Dealer's hand: ";
              for (int l=1;l<=z;l++)
               { afisare((p[m].carti[l])); cout<<" ";}cout<<endl;}}

           if(p[m].suma>21){cout<<"  Dealer BUSTED with: "<<p[m].suma<<endl; p[m].suma=0;}

  for(i=1;i<=m;i++){
    if (p[i].suma>max){max=p[i].suma;}
  }
  for(i=1;i<=m;i++){
      if((p[i].suma==max)&&(i==m)) {cout<<"  Dealer "<<" !!!!! WON !!!!! "<<endl;}
            else if((p[i].suma==max)&&(i!=m)&&(p[i].suma!=p[m].suma)) {  cout<<endl<<"  Player "<<i<<" !!!!! WON !!!!! "<<endl;}
              else if((p[i].suma!=0)&&(p[m].suma==0)&&(i!=m)) {  cout<<endl<<"  Player "<<i<<" !!!!! WON !!!!! "<<endl;}

      }

  }    _sleep(5000);system("cls");
         cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                               Want to play again?    "<<endl<<"                                YES(1)   NO(0)   "<<endl; cin>>OK2;
         if(OK2==1){
            system("cls");
            for(int numar = j+1;numar<= 156;numar ++ ){
                    v[numar - j] = v[numar];
            }
            int pozitie = 156 - j+1;
            for(i = 1;i<= m;i++){
                int t =p[i].k;
                for(int numar = 1;numar <= t;numar++){
                    v[pozitie] = p[i].carti[numar];
                    pozitie++;
                }
            }
            pozitie--;

         }


         if(OK2!=1){OK1=0;system("cls"); cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                LOSER!!   "<<endl<<endl<<endl;break;}
         }

  return 0;}


