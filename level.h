
void WhichEnemie(){
    if(Jpos == 83){ //S
        Darkpix();
    }
    else if(Jpos == 67){ //C
        Virus();
    }
    else if(Jpos == 82){ //R
        Back_pro();
    }
    else if(Jpos == 72){ //H
        Cor_mem();
    }
    else if(Jpos == 71){ //G
        Artif();
    }
}
void start_virus(){
    system("cls");
    Color(4,0);
    char txt[] = "Virus- Woah ah ah ah, you managed to come to me, bravo, bravo, I congratulate you but you will never be able\nto defeat me. I am the ultimate virus and you're on my property, in my PC. I founded this bugs empire and by\ndestroying it you put me in a mad rage. I will reformat you boah ah ah ah.\n";
    Disptxt(txt,294);
    Color(15,0);
}
void end_game(){
    system("cls");
    Color(4,0);
    char txt[] = "Virus- aaaahhhhhhhhhhhh !!! How is it possible !? How a simple man from the other world like you was he able to\nbeat me!? I am the most powerful bug!!! It's me who ...\n\n";
    Disptxt(txt,169);
    Color(15,0);
    printf("    *slash*\n\n");
    Color(1,0);
    char txt2 [] = "You- Ah, finally some calm, he was talking too much. Well now, I hope that the BIOS can bring me back to my\nworld as promised.\n\n\n\n";
    Disptxt(txt2,130);
    Color(2,0);
    char txt3 [] = "BIOS-  Here you are, you take your time. So you beat this virus ?\n";
    Disptxt(txt3,66);
    Color(1,0);
    char txt4 [] = "\nYou- Yes, and ...\n";
    Disptxt(txt4,19);
    Color(2,0);
    char txt5 [] = "\nBIOS- OK thanks bye bye\n";
    Disptxt(txt5,25);
    Color(15,0);
    char txt6 [] = "...\n...\n...\n";
    Disptxt(txt6,12);
    Color(1,0);
    char txt7 [] = "You- Ah my head hurts so much. What! do not tell me it was all a dream.\n\n\n";
    Disptxt(txt7,74);
    Color(15,0);
    char txt8 [] = "You go on the PC and you see that all the bugs are gone. You find a word file with a message of thanks from the BIOS.\nAll this story was maybe not a dream ...\n\n";
    Disptxt(txt8,160);
    exit(0);
}
void Back_pro(){
    if (Etype==0){
        Evitmax = 10;
        Ehpmax = 100 + (7*nb_back_pro);
        Ehp = Ehpmax;
        Epuis = 7 + (2*nb_back_pro);
        char txt[] = "A wild background process appeared !\n";
        Disptxt(txt, 37);
        nb_back_pro +=1;
    }
    else{
        Evitmax = 10;
        Ehpmax = 60;
        Ehp = Ehpmax;
        Epuis = 18;
        char txt[] = "A giant background process appeared !\n";
        Disptxt(txt, 38);
    }
}
void Position(){
    if(Jpos == 83){ //S
        Screen();
    }

    else if(Jpos == 82){ //R
        RAM();
    }
    else if(Jpos == 72){ //H
        HDD();
    }
    else if(Jpos == 71){ //G
        GPU();
    }
    else if(Jpos == 77){ //M
        Motherboard();
    }
}
void Darkpix(){
    if (Etype==0){
        Evitmax = 6;
        Ehpmax = 40 + (3*nb_darkpix);
        Ehp = Ehpmax;
        Epuis = 2 + nb_darkpix;
        char txt[] = "A wild darkpixel appeared ! \n";
        Disptxt(txt, 30);
        nb_darkpix +=1;
    }
    else{
        Evitmax = 6;
        Ehpmax = 200;
        Ehp = Ehpmax;
        Epuis = 15;
        char txt[] = "A giant darkpixel appeared !\n";
        Disptxt(txt, 30);
    }
}
void Cor_mem(){
    if (Etype==0){
        Evitmax = 8;
        Ehpmax = 150 + (10*nb_cor_mem);
        Ehp = Ehpmax;
        Epuis = 8 + (3*nb_cor_mem);
        char txt[] = "A wild corrupted memory appeared !\n";
        Disptxt(txt, 36);
        nb_cor_mem +=1;
    }
    else{
        Evitmax = 8;
        Ehpmax = 800;
        Ehp = Ehpmax;
        Epuis = 20;
        char txt[] = "A giant corrupted memory appeared !\n";
        Disptxt(txt, 36);
    }
}
void Screen(){
    if (Jx == 0 && Jy ==0){
        Jx = 3;
        Jy = 6;
    }
    int stage[8][8]= {
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,4,0},
        {0,5,1,1,1,0,0,0},
        {0,0,1,0,1,1,1,0},
        {0,0,0,0,1,0,1,0},
        {0,0,1,0,0,1,1,0},
        {0,1,1,1,1,1,0,0},
        {0,0,0,2,0,0,0,0}};
    char txt[] = "\nI can't see where I land my feet... the ground is to bright.\nI may arrived on the screen.\n";
    Disptxt(txt, 92);
    Game(stage);
}
void Artif(){
    if (Etype==0){
        Evitmax = 20;
        Ehpmax = 80 + (5*nb_artif);
        Ehp = Ehpmax;
        Epuis = 10 + (2*nb_artif);
        char txt[] = "A wild artifacts appeared !\n";
        Disptxt(txt, 28);
        nb_artif +=1;
    }
    else{
        Evitmax = 20;
        Ehpmax = 400;
        Ehp = Ehpmax;
        Epuis = 25;
        char txt[] = "A giant corrupted memory appeared !\n";
        Disptxt(txt, 36);
    }
}
void Virus(){
    Evitmax = 100;
    Ehpmax = 1;
    Ehp = Ehpmax;
    Epuis = 1;
}
void Boss(){
    if(strange_code == 0 && ((Jpos == 83 && lvl_unlock[1] == 0) || (Jpos == 71 && lvl_unlock[2] == 0) || (Jpos == 82 && lvl_unlock[3] == 0) || (Jpos == 72 && lvl_unlock[4] == 0))){
        Color(12,0);

        char txt[] = "\nYou've enter the Boss room !\n";
        Disptxt(txt, 30);
        Color(15,0);

        Etype = 1;
        int outputfight = Fight();
        Etype = 0;
        if(outputfight == 1){
            char txt[] = "\nI've slayed the big bug of this component !\nI've found on his dying code, a strange fonction...\nI might give it to the BIOS.\n\n";
            Disptxt(txt, 127);
            strange_code = 1;
            Jpos == 77;
            Motherboard();
        }
        else if(outputfight == 2){
            Gameover();
        }
    }
    else{
        char txt[] = "\nI already defeated this Boss, the room is totaly empty.\n";
        Disptxt(txt, 57);
    }
}
void RAM(){
    if (Jx == 0 && Jy ==0){
        Jx = 5;
        Jy = 6;
    }
    int stage[8][8]= {
        {0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,5,0},
        {0,0,1,1,1,1,1,0},
        {0,0,0,0,1,0,0,0},
        {0,1,4,0,1,0,1,0},
        {0,1,0,0,1,0,1,0},
        {0,1,1,1,1,1,1,0},
        {0,0,0,0,0,2,0,0}};
    char txt[] = "\nEverything is going too fast !\nFor sure I'm in the RAM !\n";
    Disptxt(txt, 60);
    Game(stage);
}
void HDD(){

    if (Jx == 0 && Jy ==0){
        Jx = 6;
        Jy = 6;
    }
    int stage[8][8]= {
        {0,0,0,0,0,0,0,0},
        {0,0,1,0,1,1,5,0},
        {0,0,1,1,1,0,0,0},
        {0,1,1,0,0,1,1,0},
        {0,1,0,1,1,0,1,0},
        {0,1,1,1,0,0,1,0},
        {0,4,0,1,1,1,1,0},
        {0,0,0,0,0,0,2,0}};

    char txt[] = "\nNo doubts, when I see this gigantic spinning stuff, I'm sure to be in the HDD.\n";
    Disptxt(txt, 80);
    Game(stage);
}
void GPU(){
    if (Jx == 0 && Jy ==0){
        Jx = 2;
        Jy = 6;
    }
    int stage[8][8]= {
        {0,0,0,0,0,0,0,0},
        {0,0,5,0,1,1,1,0},
        {0,1,1,1,1,0,1,0},
        {0,1,0,1,0,1,1,0},
        {0,0,1,0,0,1,0,0},
        {0,1,1,1,1,1,1,0},
        {0,0,1,0,0,1,0,0},
        {0,0,2,0,0,0,0,0}};
    char txt[] = "\nAwesome ! This place is unbelievably pretty, the ground is in 4k ! I'm in the GPU I guess.\n";
    Disptxt(txt, 92);
    Game(stage);
}