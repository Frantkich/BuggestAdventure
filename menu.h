
void Motherboard2(){
    Color(15,0);
    do{
        printf(" > ");
        scanf(" %s", &input);
    }
    while(input[0] != '0' && input[0] != '1' && input[0] != '2' && input[0] != '4' && input[0] != '5' && input[0] != '6' && input[0] != '7' && input[0] != '8' && input[0] != '9');
    if (input[0] == '0'){
        Save();
        run = 0;
        printf("\n\nGame Saved !\n\n");
        Sleep(500);
    }
    if (input[0] == '1'){
        BIOS();
        Motherboard();
    }
    if (input[0] == '2'){
        Character();
        Motherboard();
    }
    if(input[0] == '9'){
        Help();
        Motherboard();
    }
    Color(1,0);
    if (input[0] == '4'){
        if(lvl_unlock[0] == 1){
            Jpos = 83;
            Position();
        }
    }
    if (input[0] == '5'){
        if(lvl_unlock[1] == 1){
            Jpos = 71;
            Position();
        }
    }
    if (input[0] == '6'){
        if(lvl_unlock[2] == 1){
            Jpos = 82;
            Position();
        }
    }
    if (input[0] == '7'){
        if(lvl_unlock[3] == 1){
            Jpos = 72;
            Position();
        }
    }
    if (input[0] == '8'){
        if(lvl_unlock[4] == 1){
            start_virus();
            Jpos = 67;
            int outputfight;
            outputfight=Fight();
            if (outputfight==1){
                end_game();
            }
        }
    }
    if(input[0] != '0'){
        char txt[] = "This component his lock...\n";
        Disptxt(txt, 27);
        Motherboard2();
    }   
}
void Motherboard(){
    if (poPower_on != 0 || poHPmax_on != 0 || poVit_on != 0){
        if (poPower_on != 0){
            for(int i = 0; i<poPower_on; i++){
                Jpuis /= 1.25;
            }
            poPower_on = 0;
        }
        if (poHPmax_on != 0){
            for(int i = 0; i<poHPmax_on; i++){
                Jhpmax /= 1.25;
            }
            poHPmax_on = 0;
        }
        if (poVit_on != 0){
            for(int i = 0; i<poVit_on; i++){
                Jvitmax /= 0.75;
            }
            poVit_on = 0;
        }
        char txt [] ="\nI feel like my code's boosts disappear\n";
        Disptxt(txt, 40);
    }
    Jx = 0;
    Jy = 0;
    Jhp = Jhpmax;

    char txt [] = "\nNow I am in the Motherboard.\n\nWhat do I want to do:\n\n0.Save and Quit\n1.Talk to the BIOS\n2.See your stats\n9.Help\n\nOr just go to the:\n4.Screen\n5.GPU\n6.RAM\n7.HDD\n8.CPU\n";
    Disptxt(txt, 166);
    Motherboard2();
}
void Option(){
    char txt [] = "\n\n\nJeu cree par Karmann Remi et Guern Francois.\n\nCe dernier est notre projet final pour le cours de C au sein de l'ecole Ynov Paris IngeSup.\n\n\n\n";
    Disptxt(txt, 145);
    getch();
    system("cls");
    Menu();
}
void BIOS(){
    Color(2,0);
    char txt [] = "\nBIOS - Hello kid !\n";
    Disptxt(txt, 20);
    Color(15,0);
    if (lvl_unlock[0] == 0){
        char txt [] = "\nBIOS - Oh I forget to give you access to the first component !\n";
        Color(2,0);
        Disptxt(txt,65);
        Color(1,0);
        char txt2 [] = "\nYou - Yes please ...\n";
        Disptxt(txt2,24);
        Color(2,0);
        char txt3 [] = "BIOS - Give me 2 secondes\n*BIOS hitting his face against a numeric table*\nBIOS - it's should be okay !\n";
        Disptxt(txt3,104);
        Color(1,0);
        char txt4 [] = "\nYou - Euuuh thank you ... I guess...\n";
        Disptxt(txt4, 39);
        Color(2,0);
        char txt5 [] = "\nBIOS - Bye dearling !\n\n";
        Disptxt(txt5,26);
        Color(15,0);
        lvl_unlock[0] = 1;
        return;
    }
    if (strange_code == 1){
        for(int i=0; i<5;i++){
            if (lvl_unlock[i] == 0){
                lvl_unlock[i] = 1;
                i = 5;
            }
        }
        strange_code = 0;
        Color(2,0);
        char txt [] = "\nBIOS - Awesome ! You found THE fonction to unlock the bus of the next component !\nBIOS - Good Luck for the next boss !\nBIOS - Bye dearling !\n\n";
        Disptxt(txt, 144);
        Color(15,0);
        return;
    }
    Shop();
}
int Menu(){
    Color(0, 15);
    printf("\n");
    for(int i = 0; i<120; i++){
        printf(" ");
    }
    for(int i = 0; i<55; i++){
        printf(" ");
    }
    printf("MAIN MENU");
    for(int i = 0; i<56; i++){
        printf(" ");
    }
    for(int i = 0; i<120; i++){
        printf(" ");
    }
    Color(15,0);
    char txt[] = "\n\n\n1.New game\n2.Continue\n3.Option\n0.Quit\n";
    Disptxt(txt, 41);
    do{
        printf(" > ");
        scanf("%s", &input);
    }
    while(input[0] != '1' && input[0] != '2' && input[0] != '3' && input[0] != '4' && input[0] != '0');
    if(input[0] == '1'){
        char txt[] = "\nDo you want to overwrite the last backup?\n\n1.Continue\n0.Cancel\n";
        Disptxt(txt, 66);
        do{
            printf(" > ");
            scanf("%s", &input);
        }
        while(input[0] != '1' && input[0] != '0');
        if(input[0] == '1'){
            New();
            return 0;
        }
        if(input[0] == '0'){
            system("cls");
            Menu();
        }
    }
    if(input[0] == '2'){
        system("cls");
        Chargement();
        return 0;
    }
    if(input[0] == '3'){
        Option();
        return 0;
    }
    if(input[0] == '0'){
        system("cls");
        return 0;
    }
}
void New(){
    Save();
    char txt[] = "Do you want to run the introduction ?\n1.Yes\n0.No\n";
    Disptxt(txt, 50);

    do{
        printf(" > ");
        scanf("%s", &input);
    }
    while (input[0] != '1' && input[0] != '0');

    system ("cls");

    if (input[0] == '1'){
        char intro[] = "You had just finished your cybersecurity IT studies, your degree in hand, you were looking for a job.\nAlas that was six month ago and you still got nothing...\n\nOne evening, while you're lamenting about your sad life, you remembered a strange proposal that has been made to you.\nYou had refused because the wage was strangely high for this kind of job.\nYou just have to repair a PC, no matter the time or the way.\n\nYou have contacted the offerer and one week later you were in possession of the PC.\nWhile you were working on this PC, you understand why this job was so well paid.\n\nTHAT'S THE BUGGEST PC YOU EVER SEEN !\n\nYour eyelids became more and more heavy after hours of work.\nWhile you were fighting against the sleep, your head fell down and crashed against the keyboard, and your adventure \nbegan\n\n......\nDo not complain about the screenplay I'm just the voiceover...\nor just a voice in the head of our story's hero...\n";
        Disptxt(intro, 925);

        printf("\n\nAre you ready to start your adventure ?\n<press a key to continue>\n");
        getch();
        system("cls");
        char dialogue[1175] = " ? ? - Hey !\n......\n ? ? - Hey man wake up !!\n......\n ? ? - WAKE UP ASSHOLE !!!\n\n You - Mom please let me sleep...   WAIT WHAT THE FUCK, WHO ARE YOU AND WHERE ARE WE ?\n\n ? ? - Calm down my man, we are in the kingdom of my mother and\n\n You - Wait ! What do you mean by 'the kingdom of my mother'\n\n ? ? - LET ME FINISH... I talked of my mother 'Board'.\n\n You - Motherboard ? wtf... and how are you ?\n\n ? ? - My name is Killian but everybody calls me 'BIOS'...\n\n You - Why ?\n\nBIOS - I don't know ...\n\n You - Why am I here ?\n\nBIOS - The answer is I don't know but I know that now you can't go out of here !\n\n You - WHAT ??\n\nBIOS - Just kidding... To be honest it's possible to go back to your sad IRL life.\n\n You - Okay tell me how I can return to my place.\n\nBIOS - You'll have to kill a virus how puts the mess into my kingdom since many months.\n\n You - Tell me where this virus is, I will personaly kick his numeric ass.\n\nBIOS - Wait, the virus blocked all the access to the component where is hidding.\n\n You - Sooooo ? ...\n\nBIOS - To reach him you will have to unlock all the other components, start with the screen.\n\n You - Okay let's do this ! \n\nBIOS - Good luck boi !\n";
        Disptxt(dialogue, 1175);
        printf("\n<press a key to continue>\n");
        getch();
        system ("cls");
    }
    Chargement();
}
