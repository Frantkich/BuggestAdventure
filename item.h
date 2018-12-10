
void Character(){
    printf("\nMy Stats:\n\nPower : %d\nHealt : %d/%d\nSpeed : %d\n\nI've collected :\n\n- %d memory card\n- %d secured memory\n- %d computing power\n\nStable Data : %d\n",Jpuis,Jhp,Jhpmax,Jvitmax,memory_card,secured_memory,computing_power,SD);
    printf("\n<press a key to continue>\n");
    getch();
}
void Inventory(){
	Color(15,0);
	char txt[] = "\nWhich part of your code do you want to boost ?";
	Disptxt(txt, 50);
	printf("\n1.Heal  : %d\n2.Power : %d\n3.HPmax : %d\n4.Speed : %d\n0.Cancel\n", poHP,poPower,poHPmax,poVit);
    do{
    	printf(" > ");
        scanf("%s",&input);
    }
    while (input[0]!='0' && input[0]!='1' && input[0]!='2' && input[0]!='3' && input[0]!='4');

    if (input[0]=='0'){
        input[0] = 9;
    }
    if((input[0]=='1' && poHP == 0) || (input[0]=='2' && poPower  == 0) || (input[0]=='3' && poHPmax  == 0) || (input[0]=='4' && poVit  == 0)){
    	char txt[] = "\nI don't have this boost anymore\n";
		Disptxt(txt, 33);
    }
    else if (input[0]=='1'){
	    if (poHP >0){
	        if (Jhp==Jhpmax){
	            char txt[] = "\nI am already full life\n";
	            Disptxt(txt, 24);
	        }
	        else{
	            Jhp += (Jhpmax*0.25);
	            if (Jhp>Jhpmax){
	                Jhp = Jhpmax;
	            }
	            poHP --;
	            Jvit = Jvitmax;
	            char txt[] = "\nI feel alive again ! Your HP :";
	            Disptxt(txt, 31);
	            printf("%d\n",Jhp);
	        }
	    }
    }
    else if (input[0]=='2'){
    	if (poPower >0){
	        poPower --;
	        Jpuis *= 1.25;
	        poPower_on += 1;
	        Jvit = Jvitmax;
			char txt[] = "\nI feel so powerful ! Power :";
			Disptxt(txt, 30);
			printf("%d\n", Jpuis);
	    }
    }
    else if (input[0]=='3'){
    	if (poHPmax >0){
	        poHPmax --;
	        Jhpmax *= 1.25;
	        poHPmax_on += 1;
	        Jvit = Jvitmax;
			char txt[] = "\nI feel so tanky ! Healtmax :";
			Disptxt(txt, 30);
			printf("%d\n", Jhpmax);
	    }
    }
    else if (input[0]=='4'){
    	if (poVit >0){
	        poVit --;
	        Jvitmax *= 0.75;
	        poVit_on += 1;
	        Jvit = Jvitmax;
			char txt[] = "\nI feel so fast ! Cooldown of my attacks :";
			Disptxt(txt, 45);
			printf("%d\n", Jvitmax);
	    }
    }
}
void Loot(){
    if (Jpos == 83 && Alea(2) == 1){
        poHP ++;
        printf("I get a clean pixel on the darkpixel.");
    }
    if (Jpos == 72 && Alea(2) == 1){
        secured_memory ++;
        printf("I get a secured memory on the corrupted memory.");
        Jhpmax +=20;
    }
    if (Jpos == 71 && Alea(2) == 1){
        computing_power ++;
        printf("I get a computing power on the artifact.");
        Jpuis +=5;
    }
    if (Jpos == 82 && Alea(3) == 1){
        memory_card ++;
        printf("I get a memory card on the background process.");
        Jvitmax -=1;
    }
}
void Shop(){
    Color(1,0);
	printf("\n I - Hey I have %d SD, What can I buy to you?\n", SD);
	Color(2,0);
    char txt[] = "\nBIOS - Which part of your code do you want to boost ?\n";
    Disptxt(txt, 56);
    Color(15,0);
    char txt2[] = "\n1.Heal : 20 SD\n2.Power : 50 SD\n3.HPmax : 50 SD\n4.Speed : 75 SD\n\n0.Cancel\n";
    Disptxt(txt2,81);
    do{
    	printf(" > ");
    	scanf("%s",&input);
    }
    while(input[0]!='0' && input[0]!='1' && input[0]!='2' && input[0]!='3' && input[0]!='4');
    if (input[0] == '1'){
        if (SD >=20){
        	SD -=20;
            poHP ++;
            Color(2,0);
            char txt[] = "\nTheir is a heal boost for you !\n";
            Disptxt(txt, 33);
            Color(15,0);
            Sleep(2000);
            system("cls");
            return;
        }
    }
    if (input[0] == '2'){
        if(SD >= 50){
        	SD -=50;
            poPower ++;
            Color(2,0);
            char txt[] = "\nTheir is a power boost for you !\n";
            Disptxt(txt, 34);
            Color(15,0);
            Sleep(2000);
            system("cls");
            return;
        }
    }
    if (input[0] == '3'){
        if (SD >= 50){
        	SD -= 50;
            poHPmax ++;
            Color(2,0);
            char txt[] = "\nTheir is a healthmax boost for you !\n";
            Disptxt(txt, 38);
            Color(15,0);
            Sleep(2000);
            system("cls");
            return;
        }
    }
    if (input[0] == '4'){
        if (SD >= 75){
        	SD -=75;
            poVit ++;
            Color(2,0);
            char txt[] = "\nTheir is a speed boost for you !\n";
            Disptxt(txt, 34);
            Color(15,0);
            Sleep(2000);
            system("cls");
            return;
        }
    }
    if (input[0] = '0'){
    	system("cls");
    	return;
    }
    Color(2,0);
    system("cls");
    printf("BIOS- You don't have enough stable data man.\n");
    Sleep(1000);
    Color(15,0);
    Shop();
}
