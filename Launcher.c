#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Color(int Texte,int Fond);
int Menu();
void New();
void Jeu(int *lvl);

int main(){
    Menu();
    return 0;
}

int Menu(){
    int input;

    Color(0, 15);
    printf("\n");
    for(int i = 0; i<120; i++)
        printf(" ");
    for(int i = 0; i<53; i++)
        printf(" ");
    printf("MENU PRINCIPAL");
    for(int i = 0; i<53; i++)
        printf(" ");
    for(int i = 0; i<120; i++)
        printf(" ");

    Color(15,0);
    printf("\n1.Nouvelle partie\n2.Continue\n3.Quitter\n > ");

    scanf("%d", &input);

    if(input == 1){
        system("cls");
        New();
        return 0;
    }
    if(input == 2){
        system("cls");
        Jeu(10);
        return 0;
    }
    if(input == 3){
        system("cls");
        return 0;
    }
}

void Color(int Texte,int Fond){
        HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H, Fond * 16 + Texte);
}

void New(){

    int Jvie = 100;
    int Jpuis = 100;
    int lvl = 0;
    printf("Debut histoire");
    Jeu(&lvl);
}

void Jeu(int *lvl){

}
