#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int Jhpmax;
int Jpuis;
int input;
int Jname;
int Jinv;
int Jpos;
int Jhp;

FILE *fichier;

int Menu();
void Color(int Texte,int Fond);
void Motherboard();
void Chargement();
void Position();
void Option();
void Screen();
void Game();
void Move();
void New();
void CPU();
void RAM();
void HDD();
void GPU();

int main();{
    Menu();
    return 0;
}

int Menu(){
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

    printf("\n1.Nouvelle partie\n2.Continue\n3.Option\n4.Quitter\n > ");

    scanf("%d", &input);

    if(input == 1){
        system("cls");
        New();
        return 0;
    }
    if(input == 2){
        system("cls");
        Chargement();
        return 0;
    }
    if(input == 3){
        system("cls");
        Option();
        return 0;
    }
    if(input == 4){
        system("cls");
        return 0;
    }
}

void Color(int Texte,int Fond){
        HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H, Fond * 16 + Texte);
}

void New(){
    fichier = fopen("sauvegarde.txt","w");
    fprintf(fichier,"%d\n%d\n%d\n%d\n%d",100,100,100,1,83);
    fclose(fichier);
    printf("\nDebut histoire\n");
    Chargement();
}

void Chargement(){
    fichier = fopen("sauvegarde.txt","r");
    fscanf(fichier,"%d\n%d\n%d\n%d\n%d",&Jhp,&Jhpmax,&Jpuis,&Jinv,&Jpos);
    fclose(fichier);
    Position();
}

void Position(){
    if(Jpos == 83){
        Screen();
    }
    else if(Jpos == 67){
        CPU();
    }
    else if(Jpos == 82){
        RAM();
    }
    else if(Jpos == 72){
        HDD();
    }
    else if(Jpos == 71){
        GPU();
    }
    else if(Jpos == 77){
        Motherboard();
    }
}

void Option(){
    printf("\n\n\nJeu cree par Karmann Remy et Guern Francois.\n\nCe dernier est notre projet final pour le cours de C au sein de l'ecole Ynov Paris IngeSup.\n\n\n\n");
}

void Screen(){ //enemy de base -> DarkPixel (une fois débugger : une chance de PVMAX +
    int run = 1;
    printf("I can't see where I land my feet... the ground is to bright.\nI may arrived on the screen");
    while (run == 1){

    }
}
void CPU(){ //BOSS -> VIRUS
    int run = 1;
    printf("I arrived in the CPU, it's very hot in here.");
    while (run == 1){

    }
}
void RAM(){ //enemy de base -> background process attaque 2 fois (plus rapide) (une fois débugger : une chance de PUISS +
    int run = 1;
    printf("Everything is going too fast ! For sure I'm in the RAM !");
    while (run == 1){

    }
}
void HDD(){ //enemy de base -> corrupted memory (une fois débugger : une chance de INVENTORYMAX +
    int run = 1;
    printf("No doubts, when I see this gigantic spinning stuff, I'm sure to be in the HDD.");
    while (run == 1){

    }
}
void GPU(){ //enemy de base -> artifacts
    int run = 1;
    printf("Awesome ! This place is unbelievably pretty, the ground is in 4k ! I'm in the GPU I guess.");
    while (run == 1){

    }
}
void Motherboard(){ //GLITCH
    int run = 1;
    printf("Now I am in the Motherboard.");
    while (run == 1){

    }
}

void Move(){
    if(Jpos != 77){
        printf("Ou aller ?...\n")
        scanf("%d", &input);
    }
}
