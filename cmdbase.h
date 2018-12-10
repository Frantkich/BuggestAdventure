
void Disptxt(char text[] , int nbchar){
    for(int i=0; i<nbchar; i++){
        printf("%c",text[i]);
        Sleep(30);
        if (text[i]==46){
            Sleep(50);
        }
    }
}
void Color(int Texte,int Fond){
        HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H, Fond * 16 + Texte);
}
int Alea(int luck){
    int nbr;
    nbr = rand();
    if (nbr%luck==1){
        return 1;
    }
    else{
        return 0;
    }
}
void Chargement(){
    fichier = fopen("sauvegarde.txt","r");
    fscanf(fichier,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",&Jhp,&Jhpmax,&Jpuis,&Jpos,&Jvitmax,&Jx,&Jy,&SD,&strange_code,&poPower,&poPower_on,&poHPmax,&poHPmax_on,&poVit,&poVit_on,&poHP,&secured_memory,&computing_power,&memory_card,&nb_darkpix,&nb_back_pro,&nb_cor_mem,&nb_artif);
    for(int i = 0; i<5; i++){
        fscanf(fichier,"%d\n", &lvl_unlock[i]);
    }
    srand(time(NULL));
    Position();
}
int colorDISPO(){
    //0 : Noir
    //1 : Bleu foncé
    //2 : Vert foncé
    //3 : Turquoise
    //4 : Rouge foncé
    //5 : Violet
    //6 : Vert caca d'oie
    //7 : Gris clair
    //8 : Gris foncé
    //9 : Bleu fluo
    //10 : Vert fluo
    //11 : Turquoise
    //12 : Rouge fluo
    //13 : Violet 2
    //14 : Jaune
    //15 : Blanc
}
void Gameover(){
    run = 0;
    for (int j=0;j<30;j++){
        for (int i=0;i<30;i++){
            Color(1,1);
            printf("                                                                                                                        ");
        }
        Sleep(25);
        Color(0,0);
        system("cls");
    }
    Sleep(25);
    for (int i=0;i<62;i++){
        Color(0,1);
        printf(" YOU'VE BEEN CORRUPTED ");
    }
    printf(" YOU'VE BEEN C");
    Color(0,1);
    printf("\n");
    for(int i = 0; i<120; i++){
        printf(" ");
    }
    for(int i = 0; i<55; i++){
        printf(" ");
    }
    printf("FATAL ERROR");
    for(int i = 0; i<54; i++){
        printf(" ");
    }
    for(int i = 0; i<120; i++){
        printf(" ");
    }
    for (int i=0;i<78;i++){
        Color(0,1);
        printf(" YOU'VE BEEN CORRUPTED ");
    }
    printf("YOU'VE");
    getch();
    Color(15,0);
    system("cls");
}
void Save(){
    fichier = fopen("sauvegarde.txt","w");
    fprintf(fichier,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",Jhp,Jhpmax,Jpuis,Jpos,Jvitmax,Jx,Jy,SD,strange_code,poPower,poPower_on,poHPmax,poHPmax_on,poVit,poVit_on,poHP,secured_memory,computing_power,memory_card,nb_darkpix,nb_back_pro,nb_cor_mem,nb_artif);
    for(int i = 0; i<5; i++){
        fprintf(fichier,"%d\n",lvl_unlock[i]);
    }
    fclose(fichier);
}
void Help(){
    system ("cls");
    char txt[] = "What's your problem ?\n1.Commands\n2.Stats & item\n3.Fight\n4.I'm stuck.\n0.Cancel\n";
    Disptxt(txt,78);
    do{
        printf(" > ");
        scanf(" %s", &input);
    }
    while(input[0] != '0' && input[0] != '1' && input[0] != '2' && input[0] != '3' && input[0] != '4' && input[0] != '5');
    system ("cls");
    if (input[0]=='1'){
        char txt[] = "0.Save and Quit\n9.Help\n\nIn dungeon specifically :\n1.Open inventory\n2.Go below\n3.See character stats\n4.Go left\n6.Go right\n7.Open the Minimap\n8.Go up";
        Disptxt(txt,147);
    }
    if (input[0]=='2'){
        char txt[] = "Stats are pretty basic :\n\nHealthmax -> maximum amounth of health you can have\nHealth -> How much point of health do you have, if it's drop to 0 you loose\n\nPower ->How hard you hit, it's represent the amounth of health point you take off your ennemy\n\nSpeed ->It's the cooldown of your attack, it represent the amounth of turn you will have to prepare yourself before attacking\n\n\nFor boost which you can use in fight their basicly boost one stats for 25pourcents during the dungeon, when you go back to the motherboard they disapear.\nYou can bye them in the shop of the BIOS for some SD (secured data)\nAnd last but not least their is 3 other items you can loot on ennemy who boost you're stats permanently\n";
        Disptxt(txt,700);        
    }
    if (input[0]=='3'){
        char txt[] = "The core of fight is the CoolDown more you have speed more frequently it's your turn\nWhen it's the ennemy turn he can just attack you with a basic attack\nWhen it's your turn you can :\nAttack with a ligth attack, you have 1/10 chance to miss, and you hit as hard as you have power.\n\nAttack with a heavy attack, you have 1/2 chance to missed, but you deal twice damage.\n\nYou can also defend yourself and the next time the ennemy attack you you gonna blocked his attack.\n\nYou can open your inventory to take a boost or just heal yourself.\n\nAnd last but not least you can flew, if you choose this option your gonna have to prepare yourself for a long moment so take it in mind, the ennemy wont let you leave the fight easly.\n";
        Disptxt(txt,720);       
    }
    if (input[0]=='4'){
        char txt[] = "\nTap 9. for healp ;)\n";
        Disptxt(txt,21);        
    }
    if (input[0]=='5'){
        char txt[] = "\n...sorry...\n";
        Disptxt(txt,13);        
    }
    if (input[0] !='0'){
        printf("\n<press a key to continue>\n");
        getch();
        system ("cls");
    }
}
