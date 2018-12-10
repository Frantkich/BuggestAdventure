
void Disp(int stage[8][8]){
    printf("\n");
    for (int i =0; i <8; i++){
        for (int n =0; n<8; n++)
            if(stage[i][n] == 0){
                printf("ÛÛ");
            }
            else if(stage[i][n] == 1){
                printf("°°");
            }
            else if(stage[i][n] == 2){
                printf("||");
            }
            else if(stage[i][n] == 3){
                printf("**");
            }
            else if(stage[i][n] == 4){
                printf("<>");
            }
            else if(stage[i][n] == 5){
                printf("");
            }
            else if(stage[i][n] == 8){
                printf("§§");
            }
        printf("\n");
    }
}
void Game(int stage[8][8]){
    Color(15,0);
    char txt[] = "\nUse the numeric keypad to move.\n";
    Disptxt(txt, 33);
    stage[Jy][Jx] = 8;
    int outputmove;
    int outputfight;
    while (run == 1){
        outputmove = Move(stage);
        if (outputmove == 1 && Alea(3) == 1){
            outputfight = Fight();
            if (outputfight == 1){
                char txt[] = "\nVictory !\n";
                Disptxt(txt, 11);
                Loot();
                SD += 5;
            }
            else if (outputfight == 2){
                Gameover();
                run = 0;
            }
        }
        if (outputmove == 2){
            run = 0;
        }
    }
}
int Move(int stage[8][8]){
    char txt[] = "\nWhat should I do ?\n";
    Disptxt(txt, 20);
    do{
        printf(" > ");
        scanf("%s", &input);
    }
    while(input[0] != '8' && input[0] != '2' && input[0] != '6' && input[0] != '4' && input[0] != '0' && input[0] != '7' && input[0] != '1' && input[0] != '3' && input[0] != '1' && input[0] != '9');

    if(input[0] == '8'){
        if (stage[Jy-1][Jx] == 1){
            stage[Jy][Jx] = 1;
            stage[Jy-1][Jx] = 8;
            Jy -=1;
            return 1;
        }
        if (stage[Jy-1][Jx] == 0){
            Color(9,0);
            char txt[] = "\nI think i can't go through walls ...\n";
            Disptxt(txt, 38);
            Color(15,0);
            return 0;
        }
        if (stage[Jy-1][Jx] == 5){
            Boss();
            return 0;
        }
        if (stage[Jy-1][Jx] == 4){
            Color(9,0);
            char txt[] = "\nYou find a chest !\n";
            Disptxt(txt, 20);
            Color(15,0);
            SD += 30;
            return 0;
        }
    }
    if(input[0] == '2'){
        if (stage[Jy+1][Jx] == 1){
            stage[Jy][Jx] = 1;
            stage[Jy+1][Jx] = 8;
            Jy +=1;
            return 1;
        }
        if (stage[Jy+1][Jx] == 0){
            Color(9,0);
            char txt[] = "\nI think i can't go through walls ...\n";
            Disptxt(txt, 38);
            Color(15,0);
            return 0;
        }
        if (stage[Jy+1][Jx] == 5){
            Boss();
            return 0;
        }
        if (stage[Jy+1][Jx] == 4){
            Color(9,0);
            char txt[] = "\nI find a chest !\n";
            Disptxt(txt, 20);
            Color(15,0);
            SD += 30;
            return 0;
        }
        if (stage[Jy+1][Jx] == 2){
            Color(9,0);
            char txt[] = "\nI go back to the motherboard\n";
            Disptxt(txt, 30);
            Color(15,0);
            Jpos = 77;
            Motherboard();
            return 0;
        }
    }
    if(input[0] == '6'){
        if (stage[Jy][Jx+1] == 1){
            stage[Jy][Jx] = 1;
            stage[Jy][Jx+1] = 8;
            Jx +=1;
            return 1;
        }
        if (stage[Jy][Jx+1] == 0){
            Color(9,0);
            char txt[] = "\nI think i can't go through walls ...\n";
            Disptxt(txt, 38);
            Color(15,0);
            return 0;
        }
        if (stage[Jy][Jx+1] == 5){
            Boss();
            return 0;
        }
        if (stage[Jy][Jx+1] == 4){
            Color(9,0);
            char txt[] = "\nI find a chest !\n";
            Disptxt(txt, 20);
            Color(15,0);
            SD += 30;
            return 0;
        }
    }
    if(input[0] == '4'){
        if (stage[Jy][Jx-1] == 1){
            stage[Jy][Jx] = 1;
            stage[Jy][Jx-1] = 8;
            Jx -=1;
            return 1;
        }
        if (stage[Jy][Jx-1] == 0){
            Color(9,0);
            char txt[] = "\nI think i can't go through walls ...\n";
            Disptxt(txt, 38);
            Color(15,0);
            return 0;
        }
        if (stage[Jy][Jx-1] == 5){
            Boss();
            return 0;
        }
        if (stage[Jy][Jx-1] == 4){
            Color(9,0);
            char txt[] = "\nI find a chest !\n";
            Disptxt(txt, 20);
            Color(15,0);
            SD += 30;
            return 0;
        }
    }
    if(input[0] == '7'){
        Disp(stage);
        return 0;
    }
    if(input[0] == '1'){
        Inventory();
        return 0;
    }
    if(input[0] == '3'){
        Character();
        return 0;
    }
    if(input[0] == '9'){
        Help();
        return 0;
    }
    if(input[0] == '0'){
        Save();
        run = 0;
        printf("\n\nGame Saved !\n\n");
        Sleep(1500);
        return 2;
    }
}
int Fight(){
    Color(12,0);
    WhichEnemie();
    Color(15,0);
    Jvit = Jvitmax;
    Evit = Evitmax;
    int parade = 0;
    int flew = 0;
    input[0] = '0';
    while(Ehp > 0 || Jhp > 0){
        Jvit -=1;
        Evit -=1;
        if(Jvit < 1){
            if(flew == 1){
                Color(9,0);
                printf("\nI finally quit the fight ! I still have %d/%d HP.\n", Jhp, Jhpmax);
                Color(15,0);
                return 3;
            }
            Color(9,0);
            char txt[] = "\nIt's my turn !\n";
            Disptxt(txt, 16);
            printf("\nMy HP : %d/%d\n",Jhp,Jhpmax);
            Color(12,0);
            printf("Bug HP : %d/%d\n",Ehp,Ehpmax);
            Color(15,0);
            printf("\nWhat should I do ?\n1.Light attack\n2.Heavy attack\n3.Defend\n4.Inventory\n9.Help\n0.Flew away\n");
            do{
                printf(" > ");
                scanf(" %s", &input);
            }
            while(input[0] != '1' && input[0] != '2' && input[0] != '3' && input[0] != '4' && input[0] != '0' && input[0] != '9');
            if (input[0] == '9'){
                Help();
                do{
                    printf(" > ");
                    scanf(" %s", &input);
                }
                while(input[0] != '1' && input[0] != '2' && input[0] != '3' && input[0] != '4' && input[0] != '0');
            }
            Color(9,0);
            if (input[0] == '1'){
                if(Alea(10) == 1){
                    char txt[] = "\nI missed...\n";
                    Disptxt(txt, 13);
                    Jvit = Jvitmax;
                }
                else{
                    Ehp -= Jpuis;
                    char txt[] = "\nMy light attack hit !\n";
                    Disptxt(txt, 23);
                    Jvit = Jvitmax;
                }
            }
            if (input[0] == '2'){
                if(Alea(2) == 1){
                    Ehp -= (2*Jpuis);
                    char txt[] = "\nMy heavy attack hit !\n";
                    Disptxt(txt, 23);
                    Jvit = Jvitmax;
                }
                else{
                    char txt[] = "\nI missed...\n";
                    Disptxt(txt, 13);
                    Jvit = Jvitmax;
                }
            }
            if (input[0] == '3'){
                Jvit = Jvitmax;
                parade = 1;
            }
            if (input[0] == '4'){
                Inventory();
            }
            if (input[0] == '0'){
                char txt[] = "\nI prepare myself to flew.\n";
                Disptxt(txt, 27);
                Jvit = (1.5*Jvitmax);
                flew = 1;
            }
            Color(15,0);
        }
        if(Ehp < 1){
            return 1;
        }
        if(Jhp < 1){
            return 2;
        }

        if(Evit < 1){
            if(parade == 1){
                Color(9,0);
                char txt[] = "\nI blocked his attack\n";
                Disptxt(txt, 22);
                Color(15,0);
                Evit = Evitmax;
                parade = 0;
            }
            else{
                Jhp -= Epuis;
                Evit = Evitmax;
                Color(12,0);
                char txt[] = "\nThe bug attack !\n";
                Disptxt(txt, 18);
                Color(15,0);

            }
        }
        if(Ehp < 1){
            return 1;
        }
        if(Jhp < 1){
            return 2;
        }
    }
}
