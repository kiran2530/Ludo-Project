#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<graphics.h>
#include<time.h>
#include<dos.h>
#include<MMSystem.h>

int R1X=89,R1Y=167,R2X=89,R2Y=89,R3X=167,R3Y=89,R4X=167,R4Y=167,G1X=323,G1Y=89,G2X=401,G2Y=89,G3X=401,G3Y=167,G4X=323,G4Y=167;
int B1X=167,B1Y=401,B2X=89,B2Y=401,B3X=89,B3Y=323,B4X=167,B4Y=323,Y1X=401,Y1Y=323,Y2X=401,Y2Y=401,Y3X=323,Y3Y=401,Y4X=323,Y4Y=323;
int Red_X[]={-1,89,115,141,167,193,219,219,219,219,219,219,245,271,271,271,271,271,271,297,323,349,375,401,427,427,427,401,375,349,323,297,271,271,271,271,271,271,245,219,219,219,219,219,219,193,167,141,115,89,63,63,89,115,141,167,193,219};
int Red_Y[]={-1,219,219,219,219,219,193,167,141,115,89,63,63,63,89,115,141,167,193,219,219,219,219,219,219,245,271,271,271,271,271,271,297,323,349,375,401,427,427,427,401,375,349,323,297,271,271,271,271,271,271,245,245,245,245,245,245,245};
int Green_X[]={-1,271,271,271,271,271,297,323,349,375,401,427,427,427,401,375,349,323,297,271,271,271,271,271,271,245,219,219,219,219,219,219,193,167,141,115,89,63,63,63,89,115,141,167,193,219,219,219,219,219,219,245,245,245,245,245,245,245};
int Green_Y[]={-1,89,115,141,167,193,219,219,219,219,219,219,245,271,271,271,271,271,271,297,323,349,375,401,427,427,427,401,375,349,323,297,271,271,271,271,271,271,245,219,219,219,219,219,219,193,167,141,115,89,63,63,89,115,141,167,193,219};
int Yellow_X[]={-1,401,375,349,323,297,271,271,271,271,271,271,245,219,219,219,219,219,219,193,167,141,115,89,63,63,63,89,115,141,167,193,219,219,219,219,219,219,245,271,271,271,271,271,271,297,323,349,375,401,427,427,401,375,349,323,297,271};
int Yellow_Y[]={-1,271,271,271,271,271,297,323,349,375,401,427,427,427,401,375,349,323,297,271,271,271,271,271,271,245,219,219,219,219,219,219,193,167,141,115,89,63,63,63,89,115,141,167,193,219,219,219,219,219,219,245,245,245,245,245,245,245};
int Blue_X[]={-1,219,219,219,219,219,193,167,141,115,89,63,63,63,89,115,141,167,193,219,219,219,219,219,219,245,271,271,271,271,271,271,297,323,349,375,401,427,427,427,401,375,349,323,297,271,271,271,271,271,271,245,245,245,245,245,245,245};
int Blue_Y[]={-1,401,375,349,323,297,271,271,271,271,271,271,245,219,219,219,219,219,219,193,167,141,115,89,63,63,63,89,115,141,167,193,219,219,219,219,219,219,245,271,271,271,271,271,271,297,323,349,375,401,427,427,401,375,349,323,297,271};
int posR1=0,posR2=0,posR3=0,posR4=0,posG1=0,posG2=0,posG3=0,posG4=0;
int posY1=0,posY2=0,posY3=0,posY4=0,posB1=0,posB2=0,posB3=0,posB4=0;
int dice,no,count=0;
int play_choice,player_no;
int i,j,choice,p1=1,piece_No;                   // p1 use for player no..
char player1[20],player2[20],player3[20],player4[20];
int red1OutAccess=0,red2OutAccess=0,red3OutAccess=0,red4OutAccess=0,green1OutAccess=0,green2OutAccess=0,green3OutAccess=0,green4OutAccess=0,yellow1OutAccess=0,yellow2OutAccess=0,yellow3OutAccess=0,yellow4OutAccess=0,blue1OutAccess=0,blue2OutAccess=0,blue3OutAccess=0,blue4OutAccess=0;
int flagR1=0,flagR2=0,flagR3=0,flagR4=0,flagG1=0,flagG2=0,flagG3=0,flagG4=0,flagY1=0,flagY2=0,flagY3=0,flagY4=0,flagB1=0,flagB2=0,flagB3=0,flagB4=0;
int redEatFlag=0,greenEatFlag=0,yellowEatFlag=0,blueEatFlag=0;
int redWinFlag=0,greenWinFlag=0,yellowWinFlag=0,blueWinFlag=0;
FILE *fp;
char r,r1;					// r IS USE TO READ FILE.. AND r1 IS USE FOR STORE A CHARACTER FOR READ AGAIN RULES..

void display_Board()
{
	readimagefile("a.jpg",200,8,300,40);
	
	rectangle(50,50,440,440);         	// Big square..

	// ALL PIECES SQUARES BLOCKS.....................
	
    rectangle(50,50,200,200);			// Upper left small square..
    rectangle(284,50,440,206);			// Upper right small sqaure..
    rectangle(50,284,206,440);			// Lower left small sqaure..
	rectangle(284,284,440,440);			// Lower right small sqaure..
	rectangle(206,206,284,284);			// Middle square..
	
	for(i=0; i<39; i++)
	{
		setcolor(4);
		line(206+i,206+i,206+i,284-i);	// RED MID SQUARE TRINGLE... 
	}
	for(i=0; i<39; i++)
	{
		setcolor(2);
		line(206+i,206+i,284-i,206+i);	// GREEN MID SQUARE TRINGLE... 
	}
	for(i=0; i<39; i++)
	{
		setcolor(14);
		line(284-i,206+i,284-i,284-i);	// YELLOW MID SQUARE TRINGLE... 
	}
	for(i=0; i<39; i++)
	{
		setcolor(1);
		line(206+i,284-i,284-i,284-i);	// BLUE MID SQUARE TRINGLE... 
	}
			
    for(i=1; i<156; i++)
    {
    	setcolor(4);
    	rectangle(50+i,50+i,206-1,206-1);			// Upper left small square..
	}
	
	for(i=1; i<156; i++)
    {
    	setcolor(2);
    	rectangle(284+i,50+i,440-1,206-1);			// Upper right small sqaure..
	}
    
    for(i=1; i<156; i++)
    {
    	setcolor(1);
    	rectangle(50+i,284+i,206-1,440-1);			// Lower left small sqaure..
	}
    
    for(i=1; i<156; i++)
    {
    	setcolor(14);
    	rectangle(284+i,284+i,440-1,440-1);			// Lower right small sqaure..
	}
	
	// ALL PIECES SMALL CIRCLES..............
	
	fillellipse(89,89,25,25);					// red 1 small circle..
	fillellipse(89,167,25,25);					// red 2 small circle..
	fillellipse(167,89,25,25);					// red 3 small circle..
	fillellipse(167,167,25,25);   				// red 4 small circle..
	
	fillellipse(323,89,25,25);					// green 1 small circle..
	fillellipse(401,89,25,25);					// green 1 small circle..
	fillellipse(323,167,25,25);					// green 1 small circle..
	fillellipse(401,167,25,25);					// green 1 small circle..
	
	fillellipse(89,323,25,25);					// blue 1 small circle..
	fillellipse(89,401,25,25);					// blue 1 small circle..
	fillellipse(167,323,25,25);					// blue 1 small circle..
	fillellipse(167,401,25,25);					// blue 1 small circle..
	
	fillellipse(323,323,25,25);					// yellow 1 small circle..
	fillellipse(401,323,25,25);					// yellow 1 small circle..
	fillellipse(323,401,25,25);					// yellow 1 small circle..
	fillellipse(401,401,25,25);					// yellow 1 small circle..	
	
	
	setcolor(15);
	
	// ALL SMALL SQUARE BLOCKS IN FRONT OF RED.....
	
	rectangle(50,206,76,232);			
	rectangle(76,206,102,232);			// Red starting block..
	for(i=1; i<26; i++)
    {
    	setcolor(4);
    	rectangle(76+i,206+i,102,232-1);
	}
	setcolor(15);
	rectangle(102,206,128,232);
	rectangle(128,206,154,232);
	rectangle(154,206,180,232);
	rectangle(180,206,206,232);
	
	rectangle(50,232,76,258);			
	rectangle(76,232,102,258);			// Red Winning blocks..
	for(i=1; i<26; i++)
    {
    	setcolor(4);
    	rectangle(76+i,232+i,102,258-1);
	}
	setcolor(15);
	rectangle(102,232,128,258);
	for(i=1; i<26; i++)
    {
    	setcolor(4);
    	rectangle(102+i,232+i,128,258-1);
	}
	setcolor(15);
	rectangle(128,232,154,258);
	for(i=1; i<26; i++)
    {
    	setcolor(4);
    	rectangle(128+i,232+i,154,258-1);
	}
	setcolor(15);
	rectangle(154,232,180,258);
	for(i=1; i<26; i++)
    {
    	setcolor(4);
    	rectangle(154+i,232+i,180,258-1);
	}
	setcolor(15);
	rectangle(180,232,206,258);
	for(i=1; i<26; i++)
    {
    	setcolor(4);
    	rectangle(180+i,232+i,206-1,258-1);
	}
	setcolor(15);
	
	
	rectangle(50,258,76,284);			// Red opposite blocks..
	rectangle(76,258,102,284);			
	rectangle(102,258,128,284);				// blue safe
	for(i=1; i<26; i++)
    {
    	setcolor(1);
    	rectangle(102+i,258+i,128,284-1);		// blue safe
	}
	setcolor(0);
	line(102+1,258+1,128-1,284-1);
	line(128,258,102,284);				// BLUE SAFE CROSS LINES.......
	setcolor(15);
	rectangle(128,258,154,284);
	rectangle(154,258,180,284);
	rectangle(180,258,206,284);

	// ALL SMALL SQUARE BLOCKS IN FRONT OF GREEN.....
	
	rectangle(258,50,284,76);			
	rectangle(258,76,284,102);			// GREEN starting block..
	for(i=1; i<26; i++)
    {
    	setcolor(2);
    	rectangle(258+i,76+i,284-1,102-1);
	}
	setcolor(15);
	rectangle(258,102,284,128);
	rectangle(258,128,284,154);
	rectangle(258,154,284,180);
	rectangle(258,180,284,206);
	
	rectangle(232,50,258,76);			
	rectangle(232,76,258,102);			// Green Winning blocks..
	for(i=1; i<26; i++)
    {
    	setcolor(2);
    	rectangle(232+i,76+i,258-1,102-1);
	}
	setcolor(15);
	rectangle(232,102,258,128);
	for(i=1; i<26; i++)
    {
    	setcolor(2);
    	rectangle(232+i,102+i,258-1,128-1);
	}
	setcolor(15);
	rectangle(232,128,258,154);
	for(i=1; i<26; i++)
    {
    	setcolor(2);
    	rectangle(232+i,128+i,258-1,154-1);
	}
	setcolor(15);
	rectangle(232,154,258,180);
	for(i=1; i<26; i++)
    {
    	setcolor(2);
    	rectangle(232+i,154+i,258-1,180-1);
	}
	setcolor(15);
	rectangle(232,180,258,206);
	for(i=1; i<26; i++)
    {
    	setcolor(2);
    	rectangle(232+i,180+i,258-1,206-1);
	}
	setcolor(15);
	
	
	rectangle(206,50,232,76);			// Green opposite blocks..
	rectangle(206,76,232,102);			// red safe
	rectangle(206,102,232,128);
	for(i=1; i<26; i++)
    {
    	setcolor(4);
    	rectangle(206+i,102+i,232-1,128-1);
	}
	setcolor(0);
	line(206,102,232,128);
	line(232,102,206,128);				// RED SAFE CROSS LINES.......
	setcolor(15);
	rectangle(206,128,232,154);
	rectangle(206,154,232,180);
	rectangle(206,180,232,206);
	
	// ALL SMALL SQUARE BLOCKS IN FRONT OF YELLOW.....
	// ------------------------------------ YELLOW OPPOSITE block..
	rectangle(284,206,310,232);			
	rectangle(310,206,336,232);			
	rectangle(336,206,362,232);
	rectangle(362,206,388,232);					
	for(i=1; i<26; i++)
    {
    	setcolor(2);
    	rectangle(362+i,206+i,388-1,232-1);			// GREEN safe
	}
	setcolor(0);
	line(362,206,388,232);
	line(388,206,362,232);				// GREEN SAFE CROSS LINES.......
	setcolor(15);
	rectangle(388,206,414,232);
	rectangle(414,206,440,232);
	
	//-----------------------------------  YELLOW Winning blocks..
	rectangle(284,232,310,258);				
	for(i=1; i<26; i++)
    {
    	setcolor(14);
    	rectangle(284+i,232+i,310-1,258-1);
	}
	setcolor(15);		
	rectangle(310,232,336,258);			
	for(i=1; i<26; i++)
    {
    	setcolor(14);
    	rectangle(310+i,232+i,336-1,258-1);
	}
	setcolor(15);
	rectangle(336,232,362,258);
	for(i=1; i<26; i++)
    {
    	setcolor(14);
    	rectangle(336+i,232+i,362-1,258-1);
	}
	setcolor(15);
	rectangle(362,232,388,258);
	for(i=1; i<26; i++)
    {
    	setcolor(14);
    	rectangle(362+i,232+i,388-1,258-1);
	}
	setcolor(15);
	rectangle(388,232,414,258);
	for(i=1; i<26; i++)
    {
    	setcolor(14);
    	rectangle(388+i,232+i,414-1,258-1);
	}
	setcolor(15);
	rectangle(414,232,440,258);
	
	// ---------------------------------- YELLOW STARTING blocks..
	rectangle(284,258,310,284);			
	rectangle(310,258,336,284);			
	rectangle(336,258,362,284);
	rectangle(362,258,388,284);
	rectangle(388,258,414,284);
	for(i=1; i<26; i++)
    {
    	setcolor(14);
    	rectangle(388+i,258+i,414-1,284-1);
	}
	setcolor(15);
	rectangle(414,258,440,284);

	// ALL SMALL SQUARE BLOCKS IN FRONT OF BLUE.....
	// ---------------------------------- BLUE OPPOSITE BLOCKS...
	rectangle(258,284,284,310);			
	rectangle(258,310,284,336);			
	rectangle(258,336,284,362);
	rectangle(258,362,284,388);
	for(i=1; i<26; i++)
    {
    	setcolor(14);
    	rectangle(258+i,362+i,284-1,388-1);		// YELLOW SAFE BLOCK...
	}
	setcolor(0);
	line(258,362,284,388);
	line(284,362,258,388);						// YELLOW SAFE CROSS LINES...
	setcolor(15);
	rectangle(258,388,284,414);
	rectangle(258,414,284,440);
	
	// ------------------------------- BLUE Winning blocks..
	rectangle(232,284,258,310);	
	for(i=1; i<26; i++)
    {
    	setcolor(1);
    	rectangle(232+i,284+i,258-1,310-1);
	}
	setcolor(15);		
	rectangle(232,310,258,336);			
	for(i=1; i<26; i++)
    {
    	setcolor(1);
    	rectangle(232+i,310+i,258-1,336-1);
	}
	setcolor(15);
	rectangle(232,336,258,362);
	for(i=1; i<26; i++)
    {
    	setcolor(1);
    	rectangle(232+i,336+i,258-1,362-1);
	}
	setcolor(15);
	rectangle(232,362,258,388);
	for(i=1; i<26; i++)
    {
    	setcolor(1);
    	rectangle(232+i,362+i,258-1,388-1);
	}
	setcolor(15);
	rectangle(232,388,258,414);
	for(i=1; i<26; i++)
    {
    	setcolor(1);
    	rectangle(232+i,388+i,258-1,414-1);
	}
	setcolor(15);
	rectangle(232,414,258,440);
	
	// ----------------------------- BLUE STARTING BLOCKS...
	rectangle(206,284,232,310);			
	rectangle(206,310,232,336);		
	rectangle(206,336,232,362);
	rectangle(206,362,232,388);
	rectangle(206,388,232,414);
	for(i=1; i<26; i++)
    {
    	setcolor(1);
    	rectangle(206+i,388+i,232-1,414-1);
	}
	setcolor(15);
	rectangle(206,414,232,440);
	
	// ALL PIECES..........................
	if(player_no==2 || player_no==3 || player_no==4)
	{
		for(i=0; i<=12; i++)
	    {
	    	if(i==12)
	    	{
	    		setcolor(15);
			}
	    	else
	    	{
	    		setcolor(4);
			}
	    	circle(R1X,R1Y,i);						// red 2 small circle..		( Piece )
			setcolor(15);
			setbkcolor(4);
	    	outtextxy(R1X-4,R1Y-8,"1");				// red piece 1...
	    	
	    	if(i==12)
	    	{
	    		setcolor(15);
			}
	    	else
	    	{
	    		setcolor(4);
			}
	    	circle(R2X,R2Y,i);						// red 2 small circle..
			setcolor(15);
			setbkcolor(4);
	    	outtextxy(R2X-4,R2Y-8,"2");				// red piece 2...
	    	
			if(i==12)
	    	{
	    		setcolor(15);
			}
	    	else
	    	{
	    		setcolor(4);
			}
			circle(R3X,R3Y,i);						// red 3 small circle..
			setcolor(15);
			setbkcolor(4);
	    	outtextxy(R3X-4,R3Y-8,"3");				// red piece 3...
	    	
	    	if(i==12)
	    	{
	    		setcolor(15);
			}
	    	else
	    	{
	    		setcolor(4);
			}
			circle(R4X,R4Y,i);   					// red 4 small circle..	
			setcolor(15);
			setbkcolor(4);
	    	outtextxy(R4X-4,R4Y-8,"4");				// red piece 4...
	    	outtextxy(89+15,128-8,player1);
		}
	}
	
	if(player_no==3 || player_no==4)
	{
		for(i=0; i<=12; i++)
	    {
	    	if(i==12)
	    	{
	    		setcolor(15);
			}
	    	else
	    	{
	    		setcolor(2);
			}
	    	circle(G1X,G1Y,i);						// Green 1 small circle..
	    	setcolor(15);
			setbkcolor(2);
	    	outtextxy(G1X-4,G1Y-8,"1");
	    	
	    	if(i==12)
	    	{
	    		setcolor(15);
			}
	    	else
	    	{
	    		setcolor(2);
			}
			circle(G2X,G2Y,i);						// Green 2 small circle..		( Piece )
			setcolor(15);
			setbkcolor(2);
	    	outtextxy(G2X-4,G2Y-8,"2");
	    	
	    	if(i==12)
	    	{
	    		setcolor(15);
			}
	    	else
	    	{
	    		setcolor(2);
			}
			circle(G3X,G3Y,i);						// Green 3 small circle..
			setcolor(15);
			setbkcolor(2);
	    	outtextxy(G3X-4,G3Y-8,"3");
	    	
	    	if(i==12)
	    	{
	    		setcolor(15);
			}
	    	else
	    	{
	    		setcolor(2);
			}
			circle(G4X,G4Y,i);   					// Green 4 small circle..	
			setcolor(15);
			setbkcolor(2);
	    	outtextxy(G4X-4,G4Y-8,"4");
	    	outtextxy(323+15,128-8,player2);
		}
	}
	
	if(player_no==4)
	{
		for(i=0; i<=12; i++)
	    {
	    	
			if(i==12)
	    	{
	    		setcolor(15);
			}
	    	else
	    	{
	    		setcolor(1);
			}
			circle(B1X,B1Y,i);   					// BLUE 1 PIECE...
			setcolor(15);
			setbkcolor(1);
	    	outtextxy(B1X-4,B1Y-8,"1");
			
			if(i==12)
	    	{
	    		setcolor(15);
			}
	    	else
	    	{
	    		setcolor(1);
			}
	    	circle(B2X,B2Y,i);						// BLUE 2 PIECE...
			setcolor(15);
			setbkcolor(1);
	    	outtextxy(B2X-4,B2Y-8,"2");
			
			if(i==12)
	    	{
	    		setcolor(15);
			}
	    	else
	    	{
	    		setcolor(1);
			}
	    	circle(B3X,B3Y,i);						// BLUE 3 PIECE...
	    	setcolor(15);
			setbkcolor(1);
	    	outtextxy(B3X-4,B3Y-8,"3");
	    	
	    	if(i==12)
	    	{
	    		setcolor(15);
			}
	    	else
	    	{
	    		setcolor(1);
			}
			circle(B4X,B4Y,i);						// BLUE 4 PIECE.....
			setcolor(15);
			setbkcolor(1);
	    	outtextxy(B4X-4,B4Y-8,"4");
			outtextxy(89+15,362-8,player4);
		}
	}
	
	if(player_no==2 || player_no==3 || player_no==4)
	{
		for(i=0; i<=12; i++)
	    {
	    	if(i==12)
	    	{
	    		setcolor(15);
			}
	    	else
	    	{
	    		setcolor(14);
			}
			circle(Y1X,Y1Y,i);						// YELLOW 1 PIECE...
			setcolor(15);
			setbkcolor(14);
	    	outtextxy(Y1X-4,Y1Y-8,"1");
	    	
			if(i==12)
	    	{
	    		setcolor(15);
			}
	    	else
	    	{
	    		setcolor(14);
			}
			circle(Y2X,Y2Y,i);   					// YELLOW 2 PIECE...	
			setcolor(15);
			setbkcolor(14);
	    	outtextxy(Y2X-4,Y2Y-8,"2");
			
			if(i==12)
	    	{
	    		setcolor(15);
			}
	    	else
	    	{
	    		setcolor(14);
			}
			circle(Y3X,Y3Y,i);						// YELLOW 3 PIECE...
			setcolor(15);
			setbkcolor(14);
	    	outtextxy(Y3X-4,Y3Y-8,"3");
			
			if(i==12)
	    	{
	    		setcolor(15);
			}
	    	else
	    	{
	    		setcolor(14);
			}
	    	circle(Y4X,Y4Y,i);						// YELLOW 4 PIECE...
	    	setcolor(15);
			setbkcolor(14);
	    	outtextxy(Y4X-4,Y4Y-8,"4");
	    	outtextxy(323+15,362-8,player3);
		}	
	}
	
	system("cls");
	printf("\n\t PRESS ENTER KEY TO CONTINUE....");
    getchar();
	
}


int rd()
{
	srand(time(NULL));

	while(1)
	{
		no=rand()%7;
		
		if(no==0)
		{
			continue;
		}
		
		break;
	}
	// Beep(250,500);                                                    // FOR SOUND...
	return no;
}

void stop()
{
	PlaySound(TEXT("STOPPED"),NULL,SND_APPLICATION);
}

void play()
{
	char song[100]={"pubg"};
	PlaySound(song,NULL,SND_ASYNC);
}


// -----------------------------------------------------------------------------------------------------------------------------------------
int main()
{
	int a=177,b=219;
    printf("\n\t\t\t\t\t\t LOADING... \n\n");				// LOADING.....
    printf("\t\t");
    for(i=0; i<80; i++)
    {
        printf("%c",a);
    }
    printf("\r");
    printf("\t\t");
    for(i=0; i<80; i++)
    {
   	    printf("%c",b);
        Sleep(40);
    }
    
    fp=fopen("ludorules.txt","r");
    
	int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    
	display_Board();
	play();							                               // FOR MUSIC PLAY...............
	
	system("color 0E");
	
    while(1)
    {
		fp=fopen("ludoking.txt","r");
    	system("cls");
    	printf("\n\n\t");
    	for(i=0; i<3; i++)
    	{
   	    	for(j=0; j<89; j++)
   	    	{
   	    		if(i==1 && j==39)
				{
					printf(" LUDO ");
				}
				else
				{
					if(i==1 && (j==84 || j==85 || j==86 || j==87 || j==88))
					{
						printf(" ");
					}
					else
					{
   	    				printf("%c",b);
					}
				}
			}
			printf("\n\t");
    	}
    	printf("\n");
    	while(!feof(fp))
    	{
    	    r=fgetc(fp);
    	    printf("%c",r);
    	    Sleep(1);
    	}
    	
        printf("\n\n\t\t 1. PLAY \n\t\t 2. EXIT ");
        printf("\n\t ENTER YOUR CHOICE : ");
        scanf("%d",&choice);
		
        switch(choice)
        {
            case 1 : 
                while(1)
                {
                	play();                  						             // FOR MUSIC PLAY...............
                	printf("\n\t ENTER HOW MANY PLAYERS WANT TO PLAY : ");
	                scanf("%d",&player_no);
	                getchar();
	                
	                if(player_no==2)
	                {
	                	system("color 04");
		                printf("\n\t ENTER RED/1st PLAYER NAME : ");
		                gets(player1);
		                system("color 06");
		                printf("\n\t ENTER YELLOW/2rd PLAYER NAME : ");
		                gets(player3);
		                break;
					}
	                else if(player_no==3)
	                {
	                	system("color 04");
		                printf("\n\t ENTER RED/1st PLAYER NAME : ");
		                gets(player1);
		                system("color 02");
		                printf("\n\t ENTER GREEN/2nd PLAYER NAME : ");
		                gets(player2);
		                system("color 06");
		                printf("\n\t ENTER YELLOW/3rd PLAYER NAME : ");
		                gets(player3);
		                break;
					}
	                else if(player_no==4)
	                {
	                	system("color 04");
		                printf("\n\t ENTER RED/1st PLAYER NAME : ");
		                gets(player1);
		                system("color 02");
		                printf("\n\t ENTER GREEN/2nd PLAYER NAME : ");
		                gets(player2);
		                system("color 06");
		                printf("\n\t ENTER YELLOW/3rd PLAYER NAME : ");
		                gets(player3);
		                system("color 01");
		                printf("\n\t ENTER BLUE/4th PLAYER NAME : ");
		                gets(player4);
		                break;
					}
					else
					{
						system("cls");
						printf("\n\t YOU ENTER WRONG PLAYER NUMBERS. ONLY 2 OR 3 OR 4 PLAYERS CAN PLAY THE GAME.");
					}
					
				}
                
                display_Board();				// player name dispaly on board......
                stop();												// TO STOP THE MUSIC...................
                system("color 0F");
                while(1)
                {
                    switch(p1)
                    {
                        case 1 : 
                            printf("\n\t %s TURNS ENETR 1 FOR PLAY : ",player1);
                            scanf("%d",&play_choice);

                            switch(play_choice)
                            {
                                case 1 :
                                    dice=rd();
                                    printf("\n\t\t DICE : %d",dice);
                                    
                                    while(dice==6 || red1OutAccess==6 || red2OutAccess==6 || red3OutAccess==6 || red4OutAccess==6)
                                    {
                                    	if(dice==1)
					                    {
					                    	readimagefile("1.jpg",25,51,49,75);
										}
										else if(dice==2)
					                    {
					                    	readimagefile("2.jpg",25,51,49,75);
										}
										else if(dice==3)
					                    {
					                    	readimagefile("3.jpg",25,51,49,75);
										}
										else if(dice==4)
		                                {
					                        readimagefile("4.jpg",25,51,49,75);
										}
										else if(dice==5)
	                                    {
					                        readimagefile("5.jpg",25,51,49,75);
										}
										else
		                                {
					                        readimagefile("6.jpg",25,51,49,75);
										}
														
                                    	printf("\n\n\t %s. ENETR THE PIECE NUMBER WHICH PIECE YOU WANT TO MOVE : ",player1);
                                    	scanf("%d",&piece_No);

                                    	switch(piece_No)
                                    	{
                                    	    case 1 :
                                    	    	if(dice==6 || red1OutAccess==6)
                                    	    	{
                                    	    		red1OutAccess=6;
                                    	    		
                                    	    		if(flagR1==0)
                                    	    		{
                                    	    			posR1=1;
                                            			R1X = Red_X[posR1];
                                            			R1Y = Red_Y[posR1];
                                            
                                            			setbkcolor(0);
														cleardevice();
														
														if(dice==1)
					                                    {
					                                    	readimagefile("1.jpg",25,51,49,75);
														}
														else if(dice==2)
					                                    {
					                                    	readimagefile("2.jpg",25,51,49,75);
														}
														else if(dice==3)
					                                    {
					                                    	readimagefile("3.jpg",25,51,49,75);
														}
														else if(dice==4)
					                                    {
					                                    	readimagefile("4.jpg",25,51,49,75);
														}
														else if(dice==5)
					                                    {
					                                    	readimagefile("5.jpg",25,51,49,75);
														}
														else
					                                    {
					                                    	readimagefile("6.jpg",25,51,49,75);
														}
														
                                            			display_Board();
                                            			
                                            			flagR1=1;
													}
													else
													{
														posR1=posR1+dice;
														
														if(posR1<58)
														{
															R1X = Red_X[posR1];
                                            				R1Y = Red_Y[posR1];
                                            				
                                            				if((R1X==89 && R1Y==219) || (R1X==219 && R1Y==115) ||(R1X==271 && R1Y==89) ||(R1X==375 && R1Y==219) ||(R1X==401 && R1Y==271) ||(R1X==271 && R1Y==375) ||(R1X==219 && R1Y==401) ||(R1X==115 && R1Y==271))
                                            				{
                                            					
															}
															else if((R1X==G1X && R1Y==G1Y))
															{
																G1X=323;
																G1Y=89;
																green1OutAccess=0;
																flagG1=0;
																redEatFlag=1;
															}
															else if((R1X==G2X && R1Y==G2Y))
															{
																G2X=401;
																G2Y=89;
																green2OutAccess=0;
																flagG2=0;
																redEatFlag=1;
															}
															else if((R1X==G3X && R1Y==G3Y))
															{
																G3X=401;
																G3Y=167;
																green3OutAccess=0;
																flagG3=0;
																redEatFlag=1;
															}
															else if((R1X==G4X && R1Y==G4Y))
															{
																G4X=323;
																G4Y=167;
																green4OutAccess=0;
																flagG4=0;
																redEatFlag=1;
															}
															else if((R1X==B1X && R1Y==B1Y))
															{
																B1X=167;
																B1Y=401;
																blue1OutAccess=0;
																flagB1=0;
																redEatFlag=1;
															}
															else if((R1X==B2X && R1Y==B2Y))
															{
																B2X=89;
																B2Y=401;
																blue2OutAccess=0;
																flagB2=0;
																redEatFlag=1;
															}
															else if((R1X==B3X && R1Y==B3Y))
															{
																B3X=89;
																B3Y=323;
																blue3OutAccess=0;
																flagB3=0;
																redEatFlag=1;
															}
															else if((R1X==B4X && R1Y==B4Y))
															{
																B4X=167;
																B4Y=323;
																blue4OutAccess=0;
																flagB4=0;
																redEatFlag=1;
															}
															else if((R1X==Y1X && R1Y==Y1Y))
															{
																Y1X=401;
																Y1Y=323;
																yellow1OutAccess=0;
																flagY1=0;
																redEatFlag=1;
															}
															else if((R1X==Y2X && R1Y==Y2Y))
															{
																Y2X=401;
																Y2Y=401;
																yellow2OutAccess=0;
																flagY2=0;
																redEatFlag=1;
															}
															else if((R1X==Y3X && R1Y==Y3Y))
															{
																Y3X=323;
																Y3Y=401;
																yellow3OutAccess=0;
																flagY3=0;
																redEatFlag=1;
															}
															else if((R1X==Y4X && R1Y==Y4Y))
															{
																Y4X=323;
																Y4Y=323;
																yellow4OutAccess=0;
																flagY4=0;
																redEatFlag=1;
															}
															
                                            				setbkcolor(0);
															cleardevice();
															
															if(dice==1)
						                                    {
						                                    	readimagefile("1.jpg",25,51,49,75);
															}
															else if(dice==2)
						                                    {
						                                    	readimagefile("2.jpg",25,51,49,75);
															}
															else if(dice==3)
						                                    {
						                                    	readimagefile("3.jpg",25,51,49,75);
															}
															else if(dice==4)
						                                    {
						                                    	readimagefile("4.jpg",25,51,49,75);
															}
															else if(dice==5)
						                                    {
						                                    	readimagefile("5.jpg",25,51,49,75);
															}
															else
						                                    {
						                                    	readimagefile("6.jpg",25,51,49,75);
															}
															
                                            				display_Board();
                                            				
                                            				if(posR1==57)
                                            				{
                                            					redWinFlag=1;
															}
														}
														else
														{
															posR1=posR1-dice;
															
															if(dice==6 || red2OutAccess==6 || red3OutAccess==6 || red4OutAccess==6)
															{
																printf("\n\t YOU CAN'T MOVE PIECE NO 1..PLEASE ENTER PIECE NO AS PER THE RULE...");
																continue;
															}
															else
															{
																printf("\n\t YOU CAN'T MOVE ANY PIECE");
															}
														}
                                            			
													}
												}
												else
												{
													printf("\n\t YOU CAN'T MOVE PIECE NO 1..PLEASE ENTER PIECE NO AS PER THE RULE...");
													continue;
												}
                                             
											break;
										
											case 2 :
												if(dice==6 || red2OutAccess==6)
                                    	    	{
                                    	    		red2OutAccess=6;
                                    	    		
                                    	    		if(flagR2==0)
                                    	    		{
                                    	    			posR2=1;
                                            			R2X = Red_X[posR2];
                                            			R2Y = Red_Y[posR2];
                                            
                                           				setbkcolor(0);
														cleardevice();
														
														if(dice==1)
					                                    {
					                                    	readimagefile("1.jpg",25,51,49,75);
														}
														else if(dice==2)
					                                    {
					                                    	readimagefile("2.jpg",25,51,49,75);
														}
														else if(dice==3)
					                                    {
					                                    	readimagefile("3.jpg",25,51,49,75);
														}
														else if(dice==4)
					                                    {
					                                    	readimagefile("4.jpg",25,51,49,75);
														}
														else if(dice==5)
					                                    {
					                                    	readimagefile("5.jpg",25,51,49,75);
														}
														else
					                                    {
					                                    	readimagefile("6.jpg",25,51,49,75);
														}
                                            			display_Board();
                                            			
                                            			flagR2=1;
													}
													else
													{
														posR2=posR2+dice;
														
														if(posR2<58)
														{
															R2X = Red_X[posR2];
                                            				R2Y = Red_Y[posR2];
                                            				
                                            				if((R2X==89 && R2Y==219) || (R2X==219 && R2Y==115) ||(R2X==271 && R2Y==89) ||(R2X==375 && R2Y==219) ||(R2X==401 && R2Y==271) ||(R2X==271 && R2Y==375) ||(R2X==219 && R2Y==401) ||(R2X==115 && R2Y==271))
                                            				{
                                            					
															}
															else if((R2X==G1X && R2Y==G1Y))
															{
																G1X=323;
																G1Y=89;
																green1OutAccess=0;
																flagG1=0;
																redEatFlag=1;
															}
															else if((R2X==G2X && R2Y==G2Y))
															{
																G2X=401;
																G2Y=89;
																green2OutAccess=0;
																flagG2=0;
																redEatFlag=1;
															}
															else if((R2X==G3X && R2Y==G3Y))
															{
																G3X=401;
																G3Y=167;
																green3OutAccess=0;
																flagG3=0;
																redEatFlag=1;
															}
															else if((R2X==G4X && R2Y==G4Y))
															{
																G4X=323;
																G4Y=167;
																green4OutAccess=0;
																flagG4=0;
																redEatFlag=1;
															}
															else if((R2X==B1X && R2Y==B1Y))
															{
																B1X=167;
																B1Y=401;
																blue1OutAccess=0;
																flagB1=0;
																redEatFlag=1;
															}
															else if((R2X==B2X && R2Y==B2Y))
															{
																B2X=89;
																B2Y=401;
																blue2OutAccess=0;
																flagB2=0;
																redEatFlag=1;
															}
															else if((R2X==B3X && R2Y==B3Y))
															{
																B3X=89;
																B3Y=323;
																blue3OutAccess=0;
																flagB3=0;
																redEatFlag=1;
															}
															else if((R2X==B4X && R2Y==B4Y))
															{
																B4X=167;
																B4Y=323;
																blue4OutAccess=0;
																flagB4=0;
																redEatFlag=1;
															}
															else if((R2X==Y1X && R2Y==Y1Y))
															{
																Y1X=401;
																Y1Y=323;
																yellow1OutAccess=0;
																flagY1=0;
																redEatFlag=1;
															}
															else if((R2X==Y2X && R2Y==Y2Y))
															{
																Y2X=401;
																Y2Y=401;
																yellow2OutAccess=0;
																flagY2=0;
																redEatFlag=1;
															}
															else if((R2X==Y3X && R2Y==Y3Y))
															{
																Y3X=323;
																Y3Y=401;
																yellow3OutAccess=0;
																flagY3=0;
																redEatFlag=1;
															}
															else if((R2X==Y4X && R2Y==Y4Y))
															{
																Y4X=323;
																Y4Y=323;
																yellow4OutAccess=0;
																flagY4=0;
																redEatFlag=1;
															}
															
                                           					setbkcolor(0);
															cleardevice();
															
															if(dice==1)
						                                    {
						                                    	readimagefile("1.jpg",25,51,49,75);
															}
															else if(dice==2)
						                                    {
						                                    	readimagefile("2.jpg",25,51,49,75);
															}
															else if(dice==3)
						                                    {
						                                    	readimagefile("3.jpg",25,51,49,75);
															}
															else if(dice==4)
						                                    {
						                                    	readimagefile("4.jpg",25,51,49,75);
															}
															else if(dice==5)
						                                    {
						                                    	readimagefile("5.jpg",25,51,49,75);
															}
															else
						                                    {
						                                    	readimagefile("6.jpg",25,51,49,75);
															}
															
                                            				display_Board();
                                            				
                                            				if(posR2==57)
                                            				{
                                            					redWinFlag=1;
															}
														}
														else
														{
															posR2=posR2-dice;
															
															if(dice==6 || red1OutAccess==6 || red3OutAccess==6 || red4OutAccess==6)
															{
																printf("\n\t YOU CAN'T MOVE PIECE NO 2..PLEASE ENTER PIECE NO AS PER THE RULE...");
																continue;
															}
															else
															{
																printf("\n\t YOU CAN'T MOVE ANY PIECE");
															}
														}
                                            			
													}
                                    	    		 
												}
												else
												{
													printf("\n\t YOU CAN'T MOVE PIECE NO 2..PLEASE ENTER PIECE NO AS PER THE RULE...");
													continue;
												}
                                            
											break;   
										
											case 3 :
												if(dice==6 || red3OutAccess==6)
                                    	    	{
                                    	    		red3OutAccess=6;
                                    	    		
                                    	    		if(flagR3==0)
                                    	    		{
                                    	    			posR3=1;
                                            			R3X = Red_X[posR3];
                                            			R3Y = Red_Y[posR3];
                                            
                                            			setbkcolor(0);
														cleardevice();
														
														if(dice==1)
					                                    {
					                                    	readimagefile("1.jpg",25,51,49,75);
														}
														else if(dice==2)
					                                    {
					                                    	readimagefile("2.jpg",25,51,49,75);
														}
														else if(dice==3)
					                                    {
					                                    	readimagefile("3.jpg",25,51,49,75);
														}
														else if(dice==4)
					                                    {
					                                    	readimagefile("4.jpg",25,51,49,75);
														}
														else if(dice==5)
					                                    {
					                                    	readimagefile("5.jpg",25,51,49,75);
														}
														else
					                                    {
					                                    	readimagefile("6.jpg",25,51,49,75);
														}
                                            			display_Board();
                                            			
                                            			flagR3=1;
													}
													else
													{
														posR3=posR3+dice;
														
														if(posR3<58)
														{
															R3X = Red_X[posR3];
                                            				R3Y = Red_Y[posR3];
                                            				
                                            				if((R3X==89 && R3Y==219) || (R3X==219 && R3Y==115) ||(R3X==271 && R3Y==89) ||(R3X==375 && R3Y==219) ||(R3X==401 && R3Y==271) ||(R3X==271 && R3Y==375) ||(R3X==219 && R3Y==401) ||(R3X==115 && R3Y==271))
                                            				{
                                            					
															}
															else if((R3X==G1X && R3Y==G1Y))
															{
																G1X=323;
																G1Y=89;
																green1OutAccess=0;
																flagG1=0;
																redEatFlag=1;
															}
															else if((R3X==G2X && R3Y==G2Y))
															{
																G2X=401;
																G2Y=89;
																green2OutAccess=0;
																flagG2=0;
																redEatFlag=1;
															}
															else if((R3X==G3X && R3Y==G3Y))
															{
																G3X=401;
																G3Y=167;
																green3OutAccess=0;
																flagG3=0;
																redEatFlag=1;
															}
															else if((R3X==G4X && R3Y==G4Y))
															{
																G4X=323;
																G4Y=167;
																green4OutAccess=0;
																flagG4=0;
																redEatFlag=1;
															}
															else if((R3X==B1X && R3Y==B1Y))
															{
																B1X=167;
																B1Y=401;
																blue1OutAccess=0;
																flagB1=0;
																redEatFlag=1;
															}
															else if((R3X==B2X && R3Y==B2Y))
															{
																B2X=89;
																B2Y=401;
																blue2OutAccess=0;
																flagB2=0;
																redEatFlag=1;
															}
															else if((R3X==B3X && R3Y==B3Y))
															{
																B3X=89;
																B3Y=323;
																blue3OutAccess=0;
																flagB3=0;
																redEatFlag=1;
															}
															else if((R3X==B4X && R3Y==B4Y))
															{
																B4X=167;
																B4Y=323;
																blue4OutAccess=0;
																flagB4=0;
																redEatFlag=1;
															}
															else if((R3X==Y1X && R3Y==Y1Y))
															{
																Y1X=401;
																Y1Y=323;
																yellow1OutAccess=0;
																flagY1=0;
																redEatFlag=1;
															}
															else if((R3X==Y2X && R3Y==Y2Y))
															{
																Y2X=401;
																Y2Y=401;
																yellow2OutAccess=0;
																flagY2=0;
																redEatFlag=1;
															}
															else if((R3X==Y3X && R3Y==Y3Y))
															{
																Y3X=323;
																Y3Y=401;
																yellow3OutAccess=0;
																flagY3=0;
																redEatFlag=1;
															}
															else if((R3X==Y4X && R3Y==Y4Y))
															{
																Y4X=323;
																Y4Y=323;
																yellow4OutAccess=0;
																flagY4=0;
																redEatFlag=1;
															}
															
                                            				setbkcolor(0);
															cleardevice();
															
															if(dice==1)
						                                    {
						                                    	readimagefile("1.jpg",25,51,49,75);
															}
															else if(dice==2)
						                                    {
						                                    	readimagefile("2.jpg",25,51,49,75);
															}
															else if(dice==3)
						                                    {
						                                    	readimagefile("3.jpg",25,51,49,75);
															}
															else if(dice==4)
						                                    {
						                                    	readimagefile("4.jpg",25,51,49,75);
															}
															else if(dice==5)
						                                    {
						                                    	readimagefile("5.jpg",25,51,49,75);
															}
															else
						                                    {
						                                    	readimagefile("6.jpg",25,51,49,75);
															}
                                            				display_Board();
                                            				
                                            				if(posR3==57)
                                            				{
                                            					redWinFlag=1;
															}
														}
														else
														{
															posR3=posR3-dice;
															
															if(dice==6 || red1OutAccess==6 || red2OutAccess==6 || red4OutAccess==6)
															{
																printf("\n\t YOU CAN'T MOVE PIECE NO 3..PLEASE ENTER PIECE NO AS PER THE RULE...");
																continue;
															}
															else
															{
																printf("\n\t YOU CAN'T MOVE ANY PIECE");
															}
														}
                                            			
													}
                                    	    		  
												}
												else
												{
													printf("\n\t YOU CAN'T MOVE PIECE NO 3..PLEASE ENTER PIECE NO AS PER THE RULE...");
													continue;
												}
                                            
											break;
										
											case 4 :
												if(dice==6 || red4OutAccess==6)
                                    	    	{
                                    	    		red4OutAccess=6;
                                    	    		
                                    	    		if(flagR4==0)
                                    	    		{
                                    	    			posR4=1;
                                            			R4X = Red_X[posR4];
                                            			R4Y = Red_Y[posR4];
                                            
                                            			setbkcolor(0);
														cleardevice();
														
														if(dice==1)
					                                    {
					                                    	readimagefile("1.jpg",25,51,49,75);
														}
														else if(dice==2)
					                                    {
					                                    	readimagefile("2.jpg",25,51,49,75);
														}
														else if(dice==3)
					                                    {
					                                    	readimagefile("3.jpg",25,51,49,75);
														}
														else if(dice==4)
					                                    {
					                                    	readimagefile("4.jpg",25,51,49,75);
														}
														else if(dice==5)
					                                    {
					                                    	readimagefile("5.jpg",25,51,49,75);
														}
														else
					                                    {
					                                    	readimagefile("6.jpg",25,51,49,75);
														}
                                            			display_Board();
                                            			
														flagR4=1;
													}
													else
													{
														posR4=posR4+dice;
														
														if(posR4<58)
														{
															R4X = Red_X[posR4];
                                            				R4Y = Red_Y[posR4];
                                            				
                                            				if((R4X==89 && R4Y==219) || (R4X==219 && R4Y==115) ||(R4X==271 && R4Y==89) ||(R4X==375 && R4Y==219) ||(R4X==401 && R4Y==271) ||(R4X==271 && R4Y==375) ||(R4X==219 && R4Y==401) ||(R4X==115 && R4Y==271))
                                            				{
                                            					
															}
															else if((R4X==G1X && R4Y==G1Y))
															{
																G1X=323;
																G1Y=89;
																green1OutAccess=0;
																flagG1=0;
																redEatFlag=1;
															}
															else if((R4X==G2X && R4Y==G2Y))
															{
																G2X=401;
																G2Y=89;
																green2OutAccess=0;
																flagG2=0;
																redEatFlag=1;
															}
															else if((R4X==G3X && R4Y==G3Y))
															{
																G3X=401;
																G3Y=167;
																green3OutAccess=0;
																flagG3=0;
																redEatFlag=1;
															}
															else if((R4X==G4X && R4Y==G4Y))
															{
																G4X=323;
																G4Y=167;
																green4OutAccess=0;
																flagG4=0;
																redEatFlag=1;
															}
															else if((R4X==B1X && R4Y==B1Y))
															{
																B1X=167;
																B1Y=401;
																blue1OutAccess=0;
																flagB1=0;
																redEatFlag=1;
															}
															else if((R4X==B2X && R4Y==B2Y))
															{
																B2X=89;
																B2Y=401;
																blue2OutAccess=0;
																flagB2=0;
																redEatFlag=1;
															}
															else if((R4X==B3X && R4Y==B3Y))
															{
																B3X=89;
																B3Y=323;
																blue3OutAccess=0;
																flagB3=0;
																redEatFlag=1;
															}
															else if((R4X==B4X && R4Y==B4Y))
															{
																B4X=167;
																B4Y=323;
																blue4OutAccess=0;
																flagB4=0;
																redEatFlag=1;
															}
															else if((R4X==Y1X && R4Y==Y1Y))
															{
																Y1X=401;
																Y1Y=323;
																yellow1OutAccess=0;
																flagY1=0;
																redEatFlag=1;
															}
															else if((R4X==Y2X && R4Y==Y2Y))
															{
																Y2X=401;
																Y2Y=401;
																yellow2OutAccess=0;
																flagY2=0;
																redEatFlag=1;
															}
															else if((R4X==Y3X && R4Y==Y3Y))
															{
																Y3X=323;
																Y3Y=401;
																yellow3OutAccess=0;
																flagY3=0;
																redEatFlag=1;
															}
															else if((R4X==Y4X && R4Y==Y4Y))
															{
																Y4X=323;
																Y4Y=323;
																yellow4OutAccess=0;
																flagY4=0;
																redEatFlag=1;
															}
															
                                            				setbkcolor(0);
															cleardevice();
															if(dice==1)
						                                    {
						                                    	readimagefile("1.jpg",25,51,49,75);
															}
															else if(dice==2)
						                                    {
						                                    	readimagefile("2.jpg",25,51,49,75);
															}
															else if(dice==3)
						                                    {
						                                    	readimagefile("3.jpg",25,51,49,75);
															}
															else if(dice==4)
						                                    {
						                                    	readimagefile("4.jpg",25,51,49,75);
															}
															else if(dice==5)
						                                    {
						                                    	readimagefile("5.jpg",25,51,49,75);
															}
															else
						                                    {
						                                    	readimagefile("6.jpg",25,51,49,75);
															}
						                                    
                                            				display_Board();
                                            				
                                            				if(posR4==57)
                                            				{
                                            					redWinFlag=1;
															}
														}
														else
														{
															posR4=posR4-dice;
															
															if(dice==6 || red1OutAccess==6 || red2OutAccess==6 || red3OutAccess==6)
															{
																printf("\n\t YOU CAN'T MOVE PIECE NO 4..PLEASE ENTER PIECE NO AS PER THE RULE...");
																continue;
															}
															else
															{
																printf("\n\t YOU CAN'T MOVE ANY PIECE");
															}
														}
													}
                                    	    		   
												}
												else
												{
													printf("\n\t YOU CAN'T MOVE PIECE NO 4..PLEASE ENTER PIECE NO AS PER THE RULE...");
													continue;
												}
                                            
											break;  
											
											default : 
												printf("\n\t PLEASE ENTER THE PIECE NUMBER OF RANGE 1 TO 4 ... ");
												continue;                                
                                    	}
                                    
                                    	if(redEatFlag==1 || redWinFlag==1)
                                    	{
                                    		redEatFlag=0;
											redWinFlag=0;
										}
										else if(dice==6)
										{
											count=count+1;
											if(count==3)
											{
												printf("\n\t YOU LOST YOUR TURN BECAUSE OF THREE CONJECUTIVE DICE 6...");
												break;
											}
										}
										else
										{
											if(player_no==4 || player_no==3)
											p1++;
											else
											p1=p1+2;
											
											count=0;
										}
                                    	
                                    	break;
									}
									if(dice==6 || red1OutAccess==6 || red2OutAccess==6 || red3OutAccess==6 || red4OutAccess==6)
									{
										
									}
									else
									{
										if(player_no==4 || player_no==3)
										p1++;
										else
										p1=p1+2;
											
										setbkcolor(0);
										cleardevice();
										
										if(dice==1)
	                                    {
	                                    	readimagefile("1.jpg",25,51,49,75);
										}
										else if(dice==2)
	                                    {
	                                    	readimagefile("2.jpg",25,51,49,75);
										}
										else if(dice==3)
	                                    {
	                                    	readimagefile("3.jpg",25,51,49,75);
										}
										else if(dice==4)
	                                    {
	                                    	readimagefile("4.jpg",25,51,49,75);
										}
										else if(dice==5)
	                                    {
	                                    	readimagefile("5.jpg",25,51,49,75);
										}
										else
	                                    {
	                                    	readimagefile("6.jpg",25,51,49,75);
										}
										
	                                    display_Board();
									}		
                                break;
                                
                                default :
                                    printf("\n\t YOU ENTERED WRONG INPUT. PLEASE ENETR 1...");
                            }
                            getchar();
                        break;
                        
                        case 2 : 
                            printf("\n\t %s TURNS ENETR 1 FOR PLAY : ",player2);
                            scanf("%d",&play_choice);
                            
                            switch(play_choice)
                            {
                                case 1 :
                                    dice=rd();
                                    printf("\n\t\t DICE : %d",dice);
                                    
                                    while(dice==6 || green1OutAccess==6 || green2OutAccess==6 || green3OutAccess==6 || green4OutAccess==6)
                                    {
                                    	if(dice==1)
					                    {
					                    	readimagefile("1.jpg",441,51,465,75);
										}
										else if(dice==2)
					                    {
					                    	readimagefile("2.jpg",441,51,465,75);
										}
										else if(dice==3)
					                    {
					                    	readimagefile("3.jpg",441,51,465,75);
										}
										else if(dice==4)
		                                {
					                        readimagefile("4.jpg",441,51,465,75);
										}
										else if(dice==5)
	                                    {
					                        readimagefile("5.jpg",441,51,465,75);
										}
										else
		                                {
					                        readimagefile("6.jpg",441,51,465,75);
										}
										
                                    	printf("\n\n\t %s. ENETR THE PIECE NUMBER WHICH PIECE YOU WANT TO MOVE : ",player2);
                                    	scanf("%d",&piece_No);

                                    	switch(piece_No)
                                    	{
                                    	    case 1 :
                                    	    	if(dice==6 || green1OutAccess==6)
                                    	    	{
                                    	    		green1OutAccess=6;
                                    	    		
                                    	    		if(flagG1==0)
                                    	    		{
                                    	    			posG1=1;
                                            			G1X = Green_X[posG1];
                                            			G1Y = Green_Y[posG1];
                                            
                                            			setbkcolor(0);
														cleardevice();
														
														if(dice==1)
					                                    {
					                                    	readimagefile("1.jpg",441,51,465,75);
														}
														else if(dice==2)
					                                    {
					                                    	readimagefile("2.jpg",441,51,465,75);
														}
														else if(dice==3)
					                                    {
					                                    	readimagefile("3.jpg",441,51,465,75);
														}
														else if(dice==4)
					                                    {
					                                    	readimagefile("4.jpg",441,51,465,75);
														}
														else if(dice==5)
					                                    {
					                                    	readimagefile("5.jpg",441,51,465,75);
														}
														else
					                                    {
					                                    	readimagefile("6.jpg",441,51,465,75);
														}
														
                                            			display_Board();
                                            			
														flagG1=1;
													}
													else
													{
														posG1=posG1+dice;
														
														if(posG1<58)
														{
															G1X = Green_X[posG1];
                                            				G1Y = Green_Y[posG1];
                                            				
                                            				if((G1X==89 && G1Y==219) || (G1X==219 && G1Y==115) ||(G1X==271 && G1Y==89) ||(G1X==375 && G1Y==219) ||(G1X==401 && G1Y==271) ||(G1X==271 && G1Y==375) ||(G1X==219 && G1Y==401) ||(G1X==115 && G1Y==271))
                                            				{
                                            					
															}
															else if((G1X==R1X && G1Y==R1Y))
															{
																R1X=89;
																R1Y=167;
																red1OutAccess=0;
																flagR1=0;
																greenEatFlag=1;
															}
															else if((G1X==R2X && G1Y==R2Y))
															{
																R2X=89;
																R2Y=89;
																red2OutAccess=0;
																flagR2=0;
																greenEatFlag=1;
															}
															else if((G1X==R3X && G1Y==R3Y))
															{
																R3X=167;
																R3Y=89;
																red3OutAccess=0;
																flagR3=0;
																greenEatFlag=1;
															}
															else if((G1X==R4X && G1Y==R4Y))
															{
																R4X=167;
																R4Y=167;
																red4OutAccess=0;
																flagR4=0;
																greenEatFlag=1;
															}
															else if((G1X==B1X && G1Y==B1Y))
															{
																B1X=167;
																B1Y=401;
																blue1OutAccess=0;
																flagB1=0;
																greenEatFlag=1;
															}
															else if((G1X==B2X && G1Y==B2Y))
															{
																B2X=89;
																B2Y=401;
																blue2OutAccess=0;
																flagB2=0;
																greenEatFlag=1;
															}
															else if((G1X==B3X && G1Y==B3Y))
															{
																B3X=89;
																B3Y=323;
																blue3OutAccess=0;
																flagB3=0;
																greenEatFlag=1;
															}
															else if((G1X==B4X && G1Y==B4Y))
															{
																B4X=167;
																B4Y=323;
																blue4OutAccess=0;
																flagB4=0;
																greenEatFlag=1;
															}
															else if((G1X==Y1X && G1Y==Y1Y))
															{
																Y1X=401;
																Y1Y=323;
																yellow1OutAccess=0;
																flagY1=0;
																greenEatFlag=1;
															}
															else if((G1X==Y2X && G1Y==Y2Y))
															{
																Y2X=401;
																Y2Y=401;
																yellow2OutAccess=0;
																flagY2=0;
																greenEatFlag=1;
															}
															else if((G1X==Y3X && G1Y==Y3Y))
															{
																Y3X=323;
																Y3Y=401;
																yellow3OutAccess=0;
																flagY3=0;
																greenEatFlag=1;
															}
															else if((G1X==Y4X && G1Y==Y4Y))
															{
																Y4X=323;
																Y4Y=323;
																yellow4OutAccess=0;
																flagY4=0;
																greenEatFlag=1;
															}
															
                                            				setbkcolor(0);
															cleardevice();
															
															if(dice==1)
						                                    {
						                                    	readimagefile("1.jpg",441,51,465,75);
															}
															else if(dice==2)
						                                    {
						                                    	readimagefile("2.jpg",441,51,465,75);
															}
															else if(dice==3)
						                                    {
						                                    	readimagefile("3.jpg",441,51,465,75);
															}
															else if(dice==4)
						                                    {
						                                    	readimagefile("4.jpg",441,51,465,75);
															}
															else if(dice==5)
						                                    {
						                                    	readimagefile("5.jpg",441,51,465,75);
															}
															else
						                                    {
						                                    	readimagefile("6.jpg",441,51,465,75);
															}
														
                                            				display_Board();
                                            				
                                            				if(posG1==57)
                                            				{
                                            					greenWinFlag=1;
															}
														}
														else
														{
															posG1=posG1-dice;
															
															if(dice==6 || green2OutAccess==6 || green3OutAccess==6 || green4OutAccess==6)
															{
																printf("\n\t YOU CAN'T MOVE PIECE NO 1..PLEASE ENTER PIECE NO AS PER THE RULE...");
																continue;
															}
															else
															{
																printf("\n\t YOU CAN'T MOVE ANY PIECE");
															}
														}
													}
                                    	    		 
												}
												else
												{
													printf("\n\t YOU CAN'T MOVE PIECE NO 1..PLEASE ENTER PIECE NO AS PER THE RULE...");
													continue;
												}
                                            
											break;
										
											case 2 :
												if(dice==6 || green2OutAccess==6)
                                    	    	{
                                    	    		green2OutAccess=6;
                                    	    		
                                    	    		if(flagG2==0)
                                    	    		{
                                    	    			posG2=1;
                                            			G2X = Green_X[posG2];
                                            			G2Y = Green_Y[posG2];
                                            
                                            			setbkcolor(0);
														cleardevice();
														
														if(dice==1)
					                                    {
					                                    	readimagefile("1.jpg",441,51,465,75);
														}
														else if(dice==2)
					                                    {
					                                    	readimagefile("2.jpg",441,51,465,75);
														}
														else if(dice==3)
					                                    {
					                                    	readimagefile("3.jpg",441,51,465,75);
														}
														else if(dice==4)
					                                    {
					                                    	readimagefile("4.jpg",441,51,465,75);
														}
														else if(dice==5)
					                                    {
					                                    	readimagefile("5.jpg",441,51,465,75);
														}
														else
					                                    {
					                                    	readimagefile("6.jpg",441,51,465,75);
														}
														
                                            			display_Board();
                                            			
														flagG2=1;
													}
													else
													{
														posG2=posG2+dice;
														
														if(posG2<58)
														{
															G2X = Green_X[posG2];
                                            				G2Y = Green_Y[posG2];
                                            				
                                            				if((G2X==89 && G2Y==219) || (G2X==219 && G2Y==115) ||(G2X==271 && G2Y==89) ||(G2X==375 && G2Y==219) ||(G2X==401 && G2Y==271) ||(G2X==271 && G2Y==375) ||(G2X==219 && G2Y==401) ||(G2X==115 && G2Y==271))
                                            				{
                                            					
															}
															else if((G2X==R1X && G2Y==R1Y))
															{
																R1X=89;
																R1Y=167;
																red1OutAccess=0;
																flagR1=0;
																greenEatFlag=1;
															}
															else if((G2X==R2X && G2Y==R2Y))
															{
																R2X=89;
																R2Y=89;
																red2OutAccess=0;
																flagR2=0;
																greenEatFlag=1;
															}
															else if((G2X==R3X && G2Y==R3Y))
															{
																R3X=167;
																R3Y=89;
																red3OutAccess=0;
																flagR3=0;
																greenEatFlag=1;
															}
															else if((G2X==R4X && G2Y==R4Y))
															{
																R4X=167;
																R4Y=167;
																red4OutAccess=0;
																flagR4=0;
																greenEatFlag=1;
															}
															else if((G2X==B1X && G2Y==B1Y))
															{
																B1X=167;
																B1Y=401;
																blue1OutAccess=0;
																flagB1=0;
																greenEatFlag=1;
															}
															else if((G2X==B2X && G2Y==B2Y))
															{
																B2X=89;
																B2Y=401;
																blue2OutAccess=0;
																flagB2=0;
																greenEatFlag=1;
															}
															else if((G2X==B3X && G2Y==B3Y))
															{
																B3X=89;
																B3Y=323;
																blue3OutAccess=0;
																flagB3=0;
																greenEatFlag=1;
															}
															else if((G2X==B4X && G2Y==B4Y))
															{
																B4X=167;
																B4Y=323;
																blue4OutAccess=0;
																flagB4=0;
																greenEatFlag=1;
															}
															else if((G2X==Y1X && G2Y==Y1Y))
															{
																Y1X=401;
																Y1Y=323;
																yellow1OutAccess=0;
																flagY1=0;
																greenEatFlag=1;
															}
															else if((G2X==Y2X && G2Y==Y2Y))
															{
																Y2X=401;
																Y2Y=401;
																yellow2OutAccess=0;
																flagY2=0;
																greenEatFlag=1;
															}
															else if((G2X==Y3X && G2Y==Y3Y))
															{
																Y3X=323;
																Y3Y=401;
																yellow3OutAccess=0;
																flagY3=0;
																greenEatFlag=1;
															}
															else if((G2X==Y4X && G2Y==Y4Y))
															{
																Y4X=323;
																Y4Y=323;
																yellow4OutAccess=0;
																flagY4=0;
																greenEatFlag=1;
															}
															
                                            				setbkcolor(0);
															cleardevice();
															
															if(dice==1)
						                                    {
						                                    	readimagefile("1.jpg",441,51,465,75);
															}
															else if(dice==2)
						                                    {
						                                    	readimagefile("2.jpg",441,51,465,75);
															}
															else if(dice==3)
						                                    {
						                                    	readimagefile("3.jpg",441,51,465,75);
															}
															else if(dice==4)
						                                    {
						                                    	readimagefile("4.jpg",441,51,465,75);
															}
															else if(dice==5)
						                                    {
						                                    	readimagefile("5.jpg",441,51,465,75);
															}
															else
						                                    {
						                                    	readimagefile("6.jpg",441,51,465,75);
															}
														
                                            				display_Board();
                                            				
                                            				if(posG2==57)
                                            				{
                                            					greenWinFlag=1;
															}
														}
														else
														{
															posG2=posG2-dice;
															
															if(dice==6 || green1OutAccess==6 || green3OutAccess==6 || green4OutAccess==6)
															{
																printf("\n\t YOU CAN'T MOVE PIECE NO 2..PLEASE ENTER PIECE NO AS PER THE RULE...");
																continue;
															}
															else
															{
																printf("\n\t YOU CAN'T MOVE ANY PIECE");
															}
														}
													}
                                    	    		 
												}
												else
												{
													printf("\n\t YOU CAN'T MOVE PIECE NO 2..PLEASE ENTER PIECE NO AS PER THE RULE...");
													continue;
												}
                                             
											break;   
										
											case 3 :
												if(dice==6 || green3OutAccess==6)
                                    	    	{
                                    	    		green3OutAccess=6;
                                    	    		
                                    	    		if(flagG3==0)
                                    	    		{
                                    	    			posG3=1;
                                            			G3X = Green_X[posG3];
                                            			G3Y = Green_Y[posG3];
                                            
                                            			setbkcolor(0);
														cleardevice();
														
														if(dice==1)
					                                    {
					                                    	readimagefile("1.jpg",441,51,465,75);
														}
														else if(dice==2)
					                                    {
					                                    	readimagefile("2.jpg",441,51,465,75);
														}
														else if(dice==3)
					                                    {
					                                    	readimagefile("3.jpg",441,51,465,75);
														}
														else if(dice==4)
					                                    {
					                                    	readimagefile("4.jpg",441,51,465,75);
														}
														else if(dice==5)
					                                    {
					                                    	readimagefile("5.jpg",441,51,465,75);
														}
														else
					                                    {
					                                    	readimagefile("6.jpg",441,51,465,75);
														}
														
                                            			display_Board();
                                            			
														flagG3=1;
													}
													else
													{
														posG3=posG3+dice;
														
														if(posG3<58)
														{
                                            				G3X = Green_X[posG3];
                                            				G3Y = Green_Y[posG3];
                                            				
                                            				if((G3X==89 && G3Y==219) || (G3X==219 && G3Y==115) ||(G3X==271 && G3Y==89) ||(G3X==375 && G3Y==219) ||(G3X==401 && G3Y==271) ||(G3X==271 && G3Y==375) ||(G3X==219 && G3Y==401) ||(G3X==115 && G3Y==271))
                                            				{
                                            					
															}
															else if((G3X==R1X && G3Y==R1Y))
															{
																R1X=89;
																R1Y=167;
																red1OutAccess=0;
																flagR1=0;
																greenEatFlag=1;
															}
															else if((G3X==R2X && G3Y==R2Y))
															{
																R2X=89;
																R2Y=89;
																red2OutAccess=0;
																flagR2=0;
																greenEatFlag=1;
															}
															else if((G3X==R3X && G3Y==R3Y))
															{
																R3X=167;
																R3Y=89;
																red3OutAccess=0;
																flagR3=0;
																greenEatFlag=1;
															}
															else if((G3X==R4X && G3Y==R4Y))
															{
																R4X=167;
																R4Y=167;
																red4OutAccess=0;
																flagR4=0;
																greenEatFlag=1;
															}
															else if((G3X==B1X && G3Y==B1Y))
															{
																B1X=167;
																B1Y=401;
																blue1OutAccess=0;
																flagB1=0;
																greenEatFlag=1;
															}
															else if((G3X==B2X && G3Y==B2Y))
															{
																B2X=89;
																B2Y=401;
																blue2OutAccess=0;
																flagB2=0;
																greenEatFlag=1;
															}
															else if((G3X==B3X && G3Y==B3Y))
															{
																B3X=89;
																B3Y=323;
																blue3OutAccess=0;
																flagB3=0;
																greenEatFlag=1;
															}
															else if((G3X==B4X && G3Y==B4Y))
															{
																B4X=167;
																B4Y=323;
																blue4OutAccess=0;
																flagB4=0;
																greenEatFlag=1;
															}
															else if((G3X==Y1X && G3Y==Y1Y))
															{
																Y1X=401;
																Y1Y=323;
																yellow1OutAccess=0;
																flagY1=0;
																greenEatFlag=1;
															}
															else if((G3X==Y2X && G3Y==Y2Y))
															{
																Y2X=401;
																Y2Y=401;
																yellow2OutAccess=0;
																flagY2=0;
																greenEatFlag=1;
															}
															else if((G3X==Y3X && G3Y==Y3Y))
															{
																Y3X=323;
																Y3Y=401;
																yellow3OutAccess=0;
																flagY3=0;
																greenEatFlag=1;
															}
															else if((G3X==Y4X && G3Y==Y4Y))
															{
																Y4X=323;
																Y4Y=323;
																yellow4OutAccess=0;
																flagY4=0;
																greenEatFlag=1;
															}
															
                                            				setbkcolor(0);
															cleardevice();
															
															if(dice==1)
						                                    {
						                                    	readimagefile("1.jpg",441,51,465,75);
															}
															else if(dice==2)
						                                    {
						                                    	readimagefile("2.jpg",441,51,465,75);
															}
															else if(dice==3)
						                                    {
						                                    	readimagefile("3.jpg",441,51,465,75);
															}
															else if(dice==4)
						                                    {
						                                    	readimagefile("4.jpg",441,51,465,75);
															}
															else if(dice==5)
						                                    {
						                                    	readimagefile("5.jpg",441,51,465,75);
															}
															else
						                                    {
						                                    	readimagefile("6.jpg",441,51,465,75);
															}
														
                                            				display_Board();
                                            				
                                            				if(posG3==57)
                                            				{
                                            					greenWinFlag=1;
															}
														}
														else
														{
															posG3=posG3-dice;
															
															if(dice==6 || green1OutAccess==6 || green2OutAccess==6 || green4OutAccess==6)
															{
																printf("\n\t YOU CAN'T MOVE PIECE NO 3..PLEASE ENTER PIECE NO AS PER THE RULE...");
																continue;
															}
															else
															{
																printf("\n\t YOU CAN'T MOVE ANY PIECE");
															}
														}
													}
                                    	    		 
												}
												else
												{
													printf("\n\t YOU CAN'T MOVE PIECE NO 3..PLEASE ENTER PIECE NO AS PER THE RULE...");
													continue;
												}
                                             
											break;
										
											case 4 :
												if(dice==6 || green4OutAccess==6)
                                    	    	{
                                    	    		green4OutAccess=6;
                                    	    		
                                    	    		if(flagG4==0)
                                    	    		{
                                    	    			posG4=1;
                                            			G4X = Green_X[posG4];
                                            			G4Y = Green_Y[posG4];
                                            
                                            			setbkcolor(0);
														cleardevice();
														
														if(dice==1)
					                                    {
					                                    	readimagefile("1.jpg",441,51,465,75);
														}
														else if(dice==2)
					                                    {
					                                    	readimagefile("2.jpg",441,51,465,75);
														}
														else if(dice==3)
					                                    {
					                                    	readimagefile("3.jpg",441,51,465,75);
														}
														else if(dice==4)
					                                    {
					                                    	readimagefile("4.jpg",441,51,465,75);
														}
														else if(dice==5)
					                                    {
					                                    	readimagefile("5.jpg",441,51,465,75);
														}
														else
					                                    {
					                                    	readimagefile("6.jpg",441,51,465,75);
														}
														
                                            			display_Board();
                                            			
														flagG4=1;
													}
													else
													{
														posG4=posG4+dice;
														
														if(posG4<58)
														{
                                            				G4X = Green_X[posG4];
                                            				G4Y = Green_Y[posG4];
                                            				
                                            				if((G4X==89 && G4Y==219) || (G4X==219 && G4Y==115) ||(G4X==271 && G4Y==89) ||(G4X==375 && G4Y==219) ||(G4X==401 && G4Y==271) ||(G4X==271 && G4Y==375) ||(G4X==219 && G4Y==401) ||(G4X==115 && G4Y==271))
                                            				{
                                            					
															}
															else if((G4X==R1X && G4Y==R1Y))
															{
																R1X=89;
																R1Y=167;
																red1OutAccess=0;
																flagR1=0;
																greenEatFlag=1;
															}
															else if((G4X==R2X && G4Y==R2Y))
															{
																R2X=89;
																R2Y=89;
																red2OutAccess=0;
																flagR2=0;
																greenEatFlag=1;
															}
															else if((G4X==R3X && G4Y==R3Y))
															{
																R3X=167;
																R3Y=89;
																red3OutAccess=0;
																flagR3=0;
																greenEatFlag=1;
															}
															else if((G4X==R4X && G4Y==R4Y))
															{
																R4X=167;
																R4Y=167;
																red4OutAccess=0;
																flagR4=0;
																greenEatFlag=1;
															}
															else if((G4X==B1X && G4Y==B1Y))
															{
																B1X=167;
																B1Y=401;
																blue1OutAccess=0;
																flagB1=0;
																greenEatFlag=1;
															}
															else if((G4X==B2X && G4Y==B2Y))
															{
																B2X=89;
																B2Y=401;
																blue2OutAccess=0;
																flagB2=0;
																greenEatFlag=1;
															}
															else if((G4X==B3X && G4Y==B3Y))
															{
																B3X=89;
																B3Y=323;
																blue3OutAccess=0;
																flagB3=0;
																greenEatFlag=1;
															}
															else if((G4X==B4X && G4Y==B4Y))
															{
																B4X=167;
																B4Y=323;
																blue4OutAccess=0;
																flagB4=0;
																greenEatFlag=1;
															}
															else if((G4X==Y1X && G4Y==Y1Y))
															{
																Y1X=401;
																Y1Y=323;
																yellow1OutAccess=0;
																flagY1=0;
																greenEatFlag=1;
															}
															else if((G4X==Y2X && G4Y==Y2Y))
															{
																Y2X=401;
																Y2Y=401;
																yellow2OutAccess=0;
																flagY2=0;
																greenEatFlag=1;
															}
															else if((G4X==Y3X && G4Y==Y3Y))
															{
																Y3X=323;
																Y3Y=401;
																yellow3OutAccess=0;
																flagY3=0;
																greenEatFlag=1;
															}
															else if((G4X==Y4X && G4Y==Y4Y))
															{
																Y4X=323;
																Y4Y=323;
																yellow4OutAccess=0;
																flagY4=0;
																greenEatFlag=1;
															}
															
                                            				setbkcolor(0);
															cleardevice();
																
															if(dice==1)
						                                    {
						                                    	readimagefile("1.jpg",441,51,465,75);
															}
															else if(dice==2)
						                                    {
						                                    	readimagefile("2.jpg",441,51,465,75);
															}
															else if(dice==3)
						                                    {
						                                    	readimagefile("3.jpg",441,51,465,75);
															}
															else if(dice==4)
						                                    {
						                                    	readimagefile("4.jpg",441,51,465,75);
															}
															else if(dice==5)
						                                    {
						                                    	readimagefile("5.jpg",441,51,465,75);
															}
															else
						                                    {
						                                    	readimagefile("6.jpg",441,51,465,75);
															}
														
                                            				display_Board();
                                            				
                                            				if(posG4==57)
                                            				{
                                            					greenWinFlag=1;
															}
														}
														else
														{
															posG4=posG4-dice;
															
															if(dice==6 || green1OutAccess==6 || green2OutAccess==6 || green3OutAccess==6)
															{
																printf("\n\t YOU CAN'T MOVE PIECE NO 4..PLEASE ENTER PIECE NO AS PER THE RULE...");
																continue;
															}
															else
															{
																printf("\n\t YOU CAN'T MOVE ANY PIECE");
															}
														}
													}
                                    	    		 
												}
												else
												{
													printf("\n\t YOU CAN'T MOVE PIECE NO 4..PLEASE ENTER PIECE NO AS PER THE RULE...");
													continue;
												}
												
											break;  
											
											default : 
												printf("\n\t PLEASE ENTER THE PIECE NUMBER OF RANGE 1 TO 4 ... ");  
												continue;                                
                                    	}
                                    	
                                    	if(greenEatFlag==1 || greenWinFlag==1)
                                    	{
                                    		greenEatFlag=0;
                                    		greenWinFlag=0;
										}
										else if(dice==6)
										{
											count=count+1;
											if(count==3)
											{
												printf("\n\t YOU LOST YOUR TURN BECAUSE OF THREE CONJECUTIVE DICE 6...");
												break;
											}
										}
										else
										{
											if(player_no==4 || player_no==3)
											p1++;
											
											count=0;
										}
										
									break;
									
									}
									
									if(dice==6 || green1OutAccess==6 || green2OutAccess==6 || green3OutAccess==6 || green4OutAccess==6)
									{
										
									}
									else
									{
										if(player_no==4 || player_no==3)
										p1++;
										
										setbkcolor(0);
										cleardevice();
										
										if(dice==1)
					                    {
					                    	readimagefile("1.jpg",441,51,465,75);
										}
										else if(dice==2)
					                    {
					                    	readimagefile("2.jpg",441,51,465,75);
										}
										else if(dice==3)
					                    {
					                    	readimagefile("3.jpg",441,51,465,75);
										}
										else if(dice==4)
		                                {
					                        readimagefile("4.jpg",441,51,465,75);
										}
										else if(dice==5)
	                                    {
					                        readimagefile("5.jpg",441,51,465,75);
										}
										else
		                                {
					                        readimagefile("6.jpg",441,51,465,75);
										}
										
                                        display_Board();
									}
									
                                break;
                                
                                default :
                                    printf("\n\t YOU ENTERED WRONG INPUT. PLEASE ENETR 1...");
                            }
                            
                            getchar();
                        break;
                            
                        case 3 : 
                            printf("\n\t %s TURNS ENETR 1 FOR PLAY : ",player3);
                            scanf("%d",&play_choice);
                            
                            switch(play_choice)
                            {
                                case 1 :
                                    dice=rd();
                                    printf("\n\t\t DICE : %d",dice);
                                    
                                    while(dice==6 || yellow1OutAccess==6 || yellow2OutAccess==6 || yellow3OutAccess==6 || yellow4OutAccess==6)
                                    {
                                    	if(dice==1)
					                    {
					                    	readimagefile("1.jpg",441,285,465,309);
										}
										else if(dice==2)
					                    {
					                    	readimagefile("2.jpg",441,285,465,309);
										}
										else if(dice==3)
					                    {
					                    	readimagefile("3.jpg",441,285,465,309);
										}
										else if(dice==4)
		                                {
					                        readimagefile("4.jpg",441,285,465,309);
										}
										else if(dice==5)
	                                    {
					                        readimagefile("5.jpg",441,285,465,309);
										}
										else
		                                {
					                        readimagefile("6.jpg",441,285,465,309);
										}
										
                                    	printf("\n\n\t %s. ENETR THE PIECE NUMBER WHICH PIECE YOU WANT TO MOVE : ",player3);
                                    	scanf("%d",&piece_No);

                                    	switch(piece_No)
                                    	{
                                    	    case 1 :
                                    	    	if(dice==6 || yellow1OutAccess==6)
                                    	    	{
                                    	    		yellow1OutAccess=6;
                                    	    		
                                    	    		if(flagY1==0)
                                    	    		{
                                    	    			posY1=1;
                                            			Y1X = Yellow_X[posY1];
                                            			Y1Y = Yellow_Y[posY1];
                                            	
                                            			setbkcolor(0);
														cleardevice();
														
														if(dice==1)
									                    {
									                    	readimagefile("1.jpg",441,285,465,309);
														}
														else if(dice==2)
									                    {
									                    	readimagefile("2.jpg",441,285,465,309);
														}
														else if(dice==3)
									                    {
									                    	readimagefile("3.jpg",441,285,465,309);
														}
														else if(dice==4)
						                                {
									                        readimagefile("4.jpg",441,285,465,309);
														}
														else if(dice==5)
					                                    {
									                        readimagefile("5.jpg",441,285,465,309);
														}
														else
						                                {
									                        readimagefile("6.jpg",441,285,465,309);
														}
										
                                            			display_Board();
                                            			
														flagY1=1;
													}
													else
													{
														posY1=posY1+dice;
														
														if(posY1<58)
														{
                                            				Y1X = Yellow_X[posY1];
                                            				Y1Y = Yellow_Y[posY1];
                                            				
                                            				if((Y1X==89 && Y1Y==219) || (Y1X==219 && Y1Y==115) ||(Y1X==271 && Y1Y==89) ||(Y1X==375 && Y1Y==219) ||(Y1X==401 && Y1Y==271) ||(Y1X==271 && Y1Y==375) ||(Y1X==219 && Y1Y==401) ||(Y1X==115 && Y1Y==271))
                                            				{
                                            					
															}
															else if((Y1X==R1X && Y1Y==R1Y))
															{
																R1X=89;
																R1Y=167;
																red1OutAccess=0;
																flagR1=0;
																yellowEatFlag=1;
															}
															else if((Y1X==R2X && Y1Y==R2Y))
															{
																R2X=89;
																R2Y=89;
																red2OutAccess=0;
																flagR2=0;
																yellowEatFlag=1;
															}
															else if((Y1X==R3X && Y1Y==R3Y))
															{
																R3X=167;
																R3Y=89;
																red3OutAccess=0;
																flagR3=0;
																yellowEatFlag=1;
															}
															else if((Y1X==R4X && Y1Y==R4Y))
															{
																R4X=167;
																R4Y=167;
																red4OutAccess=0;
																flagR4=0;
																yellowEatFlag=1;
															}
															else if((Y1X==B1X && Y1Y==B1Y))
															{
																B1X=167;
																B1Y=401;
																blue1OutAccess=0;
																flagB1=0;
																yellowEatFlag=1;
															}
															else if((Y1X==B2X && Y1Y==B2Y))
															{
																B2X=89;
																B2Y=401;
																blue2OutAccess=0;
																flagB2=0;
																yellowEatFlag=1;
															}
															else if((Y1X==B3X && Y1Y==B3Y))
															{
																B3X=89;
																B3Y=323;
																blue3OutAccess=0;
																flagB3=0;
																yellowEatFlag=1;
															}
															else if((Y1X==B4X && Y1Y==B4Y))
															{
																B4X=167;
																B4Y=323;
																blue4OutAccess=0;
																flagB4=0;
																yellowEatFlag=1;
															}
															else if((Y1X==G1X && Y1Y==G1Y))
															{
																G1X=323;
																G1Y=89;
																green1OutAccess=0;
																flagG1=0;
																yellowEatFlag=1;
															}
															else if((Y1X==G2X && Y1Y==G2Y))
															{
																G2X=401;
																G2Y=89;
																green2OutAccess=0;
																flagG2=0;
																yellowEatFlag=1;
															}
															else if((Y1X==G3X && Y1Y==G3Y))
															{
																G3X=401;
																G3Y=167;
																green3OutAccess=0;
																flagG3=0;
																yellowEatFlag=1;
															}
															else if((Y1X==G4X && Y1Y==G4Y))
															{
																G4X=323;
																G4Y=167;
																green4OutAccess=0;
																flagG4=0;
																yellowEatFlag=1;
															}
															
                                            				setbkcolor(0);
															cleardevice();
															
															if(dice==1)
										                    {
										                    	readimagefile("1.jpg",441,285,465,309);
															}
															else if(dice==2)
										                    {
										                    	readimagefile("2.jpg",441,285,465,309);
															}
															else if(dice==3)
										                    {
										                    	readimagefile("3.jpg",441,285,465,309);
															}
															else if(dice==4)
							                                {
										                        readimagefile("4.jpg",441,285,465,309);
															}
															else if(dice==5)
						                                    {
										                        readimagefile("5.jpg",441,285,465,309);
															}
															else
							                                {
										                        readimagefile("6.jpg",441,285,465,309);
															}
                                            				display_Board();
                                            				
                                            				if(posY1==57)
                                            				{
                                            					yellowWinFlag=1;
															}
														}
														else
														{
															posY1=posY1-dice;
															
															if(dice==6 || yellow2OutAccess==6 || yellow3OutAccess==6 || yellow4OutAccess==6)
															{
																printf("\n\t YOU CAN'T MOVE PIECE NO 1..PLEASE ENTER PIECE NO AS PER THE RULE...");
																continue;
															}
															else
															{
																printf("\n\t YOU CAN'T MOVE ANY PIECE");
															}
														}
													}
                                    	    		 
												}
												else
												{
													printf("\n\t YOU CAN'T MOVE PIECE NO 1..PLEASE ENTER PIECE NO AS PER THE RULE...");
													continue;
												}
                                             
											break;
										
											case 2 :
												if(dice==6 || yellow2OutAccess==6)
                                    	    	{
                                    	    		yellow2OutAccess=6;
                                    	    		
                                    	    		if(flagY2==0)
                                    	    		{
                                    	    			posY2=1;
                                            			Y2X = Yellow_X[posY2];
                                            			Y2Y = Yellow_Y[posY2];
                                            
                                            			setbkcolor(0);
														cleardevice();
														
														if(dice==1)
									                    {
									                    	readimagefile("1.jpg",441,285,465,309);
														}
														else if(dice==2)
									                    {
									                    	readimagefile("2.jpg",441,285,465,309);
														}
														else if(dice==3)
									                    {
									                    	readimagefile("3.jpg",441,285,465,309);
														}
														else if(dice==4)
						                                {
									                        readimagefile("4.jpg",441,285,465,309);
														}
														else if(dice==5)
					                                    {
									                        readimagefile("5.jpg",441,285,465,309);
														}
														else
						                                {
									                        readimagefile("6.jpg",441,285,465,309);
														}
														
                                            			display_Board();
                                            			
														flagY2=1;
													}
													else
													{
														posY2=posY2+dice;
														
														if(posY2<58)
														{
                                            				Y2X = Yellow_X[posY2];
                                            				Y2Y = Yellow_Y[posY2];
                                            				
                                            				if((Y2X==89 && Y2Y==219) || (Y2X==219 && Y2Y==115) ||(Y2X==271 && Y2Y==89) ||(Y2X==375 && Y2Y==219) ||(Y2X==401 && Y2Y==271) ||(Y2X==271 && Y2Y==375) ||(Y2X==219 && Y2Y==401) ||(Y2X==115 && Y2Y==271))
                                            				{
                                            					
															}
															else if((Y2X==R1X && Y2Y==R1Y))
															{
																R1X=89;
																R1Y=167;
																red1OutAccess=0;
																flagR1=0;
																yellowEatFlag=1;
															}
															else if((Y2X==R2X && Y2Y==R2Y))
															{
																R2X=89;
																R2Y=89;
																red2OutAccess=0;
																flagR2=0;
																yellowEatFlag=1;
															}
															else if((Y2X==R3X && Y2Y==R3Y))
															{
																R3X=167;
																R3Y=89;
																red3OutAccess=0;
																flagR3=0;
																yellowEatFlag=1;
															}
															else if((Y2X==R4X && Y2Y==R4Y))
															{
																R4X=167;
																R4Y=167;
																red4OutAccess=0;
																flagR4=0;
																yellowEatFlag=1;
															}
															else if((Y2X==B1X && Y2Y==B1Y))
															{
																B1X=167;
																B1Y=401;
																blue1OutAccess=0;
																flagB1=0;
																yellowEatFlag=1;
															}
															else if((Y2X==B2X && Y2Y==B2Y))
															{
																B2X=89;
																B2Y=401;
																blue2OutAccess=0;
																flagB2=0;
																yellowEatFlag=1;
															}
															else if((Y2X==B3X && Y2Y==B3Y))
															{
																B3X=89;
																B3Y=323;
																blue3OutAccess=0;
																flagB3=0;
																yellowEatFlag=1;
															}
															else if((Y2X==B4X && Y2Y==B4Y))
															{
																B4X=167;
																B4Y=323;
																blue4OutAccess=0;
																flagB4=0;
																yellowEatFlag=1;
															}
															else if((Y2X==G1X && Y2Y==G1Y))
															{
																G1X=323;
																G1Y=89;
																green1OutAccess=0;
																flagG1=0;
																yellowEatFlag=1;
															}
															else if((Y2X==G2X && Y2Y==G2Y))
															{
																G2X=401;
																G2Y=89;
																green2OutAccess=0;
																flagG2=0;
																yellowEatFlag=1;
															}
															else if((Y2X==G3X && Y2Y==G3Y))
															{
																G3X=401;
																G3Y=167;
																green3OutAccess=0;
																flagG3=0;
																yellowEatFlag=1;
															}
															else if((Y2X==G4X && Y2Y==G4Y))
															{
																G4X=323;
																G4Y=167;
																green4OutAccess=0;
																flagG4=0;
																yellowEatFlag=1;
															}
															
                                            				setbkcolor(0);
															cleardevice();
															
															if(dice==1)
										                    {
										                    	readimagefile("1.jpg",441,285,465,309);
															}
															else if(dice==2)
										                    {
										                    	readimagefile("2.jpg",441,285,465,309);
															}
															else if(dice==3)
										                    {
										                    	readimagefile("3.jpg",441,285,465,309);
															}
															else if(dice==4)
							                                {
										                        readimagefile("4.jpg",441,285,465,309);
															}
															else if(dice==5)
						                                    {
										                        readimagefile("5.jpg",441,285,465,309);
															}
															else
							                                {
										                        readimagefile("6.jpg",441,285,465,309);
															}
														
                                            				display_Board();
                                            				
                                            				if(posY2==57)
                                            				{
                                            					yellowWinFlag=1;
															}
														}
														else
														{
															posY2=posY2-dice;
															
															if(dice==6 || yellow1OutAccess==6 || yellow3OutAccess==6 || yellow4OutAccess==6)
															{
																printf("\n\t YOU CAN'T MOVE PIECE NO 2..PLEASE ENTER PIECE NO AS PER THE RULE...");
																continue;
															}
															else
															{
																printf("\n\t YOU CAN'T MOVE ANY PIECE");
															}
														}
													}
                                    	    		 
												}
												else
												{
													printf("\n\t YOU CAN'T MOVE PIECE NO 2..PLEASE ENTER PIECE NO AS PER THE RULE...");
													continue;
												}
                                             
											break;   
										
											case 3 :
												if(dice==6 || yellow3OutAccess==6)
                                    	    	{
                                    	    		yellow3OutAccess=6;
                                    	    		
                                    	    		if(flagY3==0)
                                    	    		{
                                    	    			posY3=1;
                                            			Y3X = Yellow_X[posY3];
                                            			Y3Y = Yellow_Y[posY3];
                                            
                                            			setbkcolor(0);
														cleardevice();
														
														if(dice==1)
									                    {
									                    	readimagefile("1.jpg",441,285,465,309);
														}
														else if(dice==2)
									                    {
									                    	readimagefile("2.jpg",441,285,465,309);
														}
														else if(dice==3)
									                    {
									                    	readimagefile("3.jpg",441,285,465,309);
														}
														else if(dice==4)
						                                {
									                        readimagefile("4.jpg",441,285,465,309);
														}
														else if(dice==5)
					                                    {
									                        readimagefile("5.jpg",441,285,465,309);
														}
														else
						                                {
									                        readimagefile("6.jpg",441,285,465,309);
														}
														
                                            			display_Board();
                                            			
														flagY3=1;
													}
													else
													{
														posY3=posY3+dice;
														
														if(posY3<58)
														{
                                            				Y3X = Yellow_X[posY3];
                                            				Y3Y = Yellow_Y[posY3];
                                            				
                                            				if((Y3X==89 && Y3Y==219) || (Y3X==219 && Y3Y==115) ||(Y3X==271 && Y3Y==89) ||(Y3X==375 && Y3Y==219) ||(Y3X==401 && Y3Y==271) ||(Y3X==271 && Y3Y==375) ||(Y3X==219 && Y3Y==401) ||(Y3X==115 && Y3Y==271))
                                            				{
                                            					
															}
															else if((Y3X==R1X && Y3Y==R1Y))
															{
																R1X=89;
																R1Y=167;
																red1OutAccess=0;
																flagR1=0;
																yellowEatFlag=1;
															}
															else if((Y3X==R2X && Y3Y==R2Y))
															{
																R2X=89;
																R2Y=89;
																red2OutAccess=0;
																flagR2=0;
																yellowEatFlag=1;
															}
															else if((Y3X==R3X && Y3Y==R3Y))
															{
																R3X=167;
																R3Y=89;
																red3OutAccess=0;
																flagR3=0;
																yellowEatFlag=1;
															}
															else if((Y3X==R4X && Y3Y==R4Y))
															{
																R4X=167;
																R4Y=167;
																red4OutAccess=0;
																flagR4=0;
																yellowEatFlag=1;
															}
															else if((Y3X==B1X && Y3Y==B1Y))
															{
																B1X=167;
																B1Y=401;
																blue1OutAccess=0;
																flagB1=0;
																yellowEatFlag=1;
															}
															else if((Y3X==B2X && Y3Y==B2Y))
															{
																B2X=89;
																B2Y=401;
																blue2OutAccess=0;
																flagB2=0;
																yellowEatFlag=1;
															}
															else if((Y3X==B3X && Y3Y==B3Y))
															{
																B3X=89;
																B3Y=323;
																blue3OutAccess=0;
																flagB3=0;
																yellowEatFlag=1;
															}
															else if((Y3X==B4X && Y3Y==B4Y))
															{
																B4X=167;
																B4Y=323;
																blue4OutAccess=0;
																flagB4=0;
																yellowEatFlag=1;
															}
															else if((Y3X==G1X && Y3Y==G1Y))
															{
																G1X=323;
																G1Y=89;
																green1OutAccess=0;
																flagG1=0;
																yellowEatFlag=1;
															}
															else if((Y3X==G2X && Y3Y==G2Y))
															{
																G2X=401;
																G2Y=89;
																green2OutAccess=0;
																flagG2=0;
																yellowEatFlag=1;
															}
															else if((Y3X==G3X && Y3Y==G3Y))
															{
																G3X=401;
																G3Y=167;
																green3OutAccess=0;
																flagG3=0;
																yellowEatFlag=1;
															}
															else if((Y3X==G4X && Y3Y==G4Y))
															{
																G4X=323;
																G4Y=167;
																green4OutAccess=0;
																flagG4=0;
																yellowEatFlag=1;
															}
															
                                            				setbkcolor(0);
															cleardevice();
															
															if(dice==1)
										                    {
										                    	readimagefile("1.jpg",441,285,465,309);
															}
															else if(dice==2)
										                    {
										                    	readimagefile("2.jpg",441,285,465,309);
															}
															else if(dice==3)
										                    {
										                    	readimagefile("3.jpg",441,285,465,309);
															}
															else if(dice==4)
							                                {
										                        readimagefile("4.jpg",441,285,465,309);
															}
															else if(dice==5)
						                                    {
										                        readimagefile("5.jpg",441,285,465,309);
															}
															else
							                                {
										                        readimagefile("6.jpg",441,285,465,309);
															}
														
                                            				display_Board();
                                            				
                                            				if(posY3==57)
                                            				{
                                            					yellowWinFlag=1;
															}
														}
														else
														{
															posY3=posY3-dice;
															
															if(dice==6 || yellow1OutAccess==6 || yellow2OutAccess==6 || yellow4OutAccess==6)
															{
																printf("\n\t YOU CAN'T MOVE PIECE NO 3..PLEASE ENTER PIECE NO AS PER THE RULE...");
																continue;
															}
															else
															{
																printf("\n\t YOU CAN'T MOVE ANY PIECE");
															}
														}
													}
                                    	    		 
												}
												else
												{
													printf("\n\t YOU CAN'T MOVE PIECE NO 3..PLEASE ENTER PIECE NO AS PER THE RULE...");
													continue;
												}
                                             
											break;
										
											case 4 :
												if(dice==6 || yellow4OutAccess==6)
                                    	    	{
                                    	    		yellow4OutAccess=6;
                                    	    		
                                    	    		if(flagY4==0)
                                    	    		{
                                    	    			posY4=posY4+dice;
                                            			Y4X = Yellow_X[posY4];
                                            			Y4Y = Yellow_Y[posY4];
                                            
                                            			setbkcolor(0);
														cleardevice();
														
														if(dice==1)
									                    {
									                    	readimagefile("1.jpg",441,285,465,309);
														}
														else if(dice==2)
									                    {
									                    	readimagefile("2.jpg",441,285,465,309);
														}
														else if(dice==3)
									                    {
									                    	readimagefile("3.jpg",441,285,465,309);
														}
														else if(dice==4)
						                                {
									                        readimagefile("4.jpg",441,285,465,309);
														}
														else if(dice==5)
					                                    {
									                        readimagefile("5.jpg",441,285,465,309);
														}
														else
						                                {
									                        readimagefile("6.jpg",441,285,465,309);
														}
														
                                            			display_Board();
                                            			
														flagY4=1;
													}
													else
													{
														posY4=posY4+dice;
														
														if(posY4<58)
														{
                                            				Y4X = Yellow_X[posY4];
                                            				Y4Y = Yellow_Y[posY4];
                                            				
                                            				if((Y4X==89 && Y4Y==219) || (Y4X==219 && Y4Y==115) ||(Y4X==271 && Y4Y==89) ||(Y4X==375 && Y4Y==219) ||(Y4X==401 && Y4Y==271) ||(Y4X==271 && Y4Y==375) ||(Y4X==219 && Y4Y==401) ||(Y4X==115 && Y4Y==271))
                                            				{
                                            					
															}
															else if((Y4X==R1X && Y4Y==R1Y))
															{
																R1X=89;
																R1Y=167;
																red1OutAccess=0;
																flagR1=0;
																yellowEatFlag=1;
															}
															else if((Y4X==R2X && Y4Y==R2Y))
															{
																R2X=89;
																R2Y=89;
																red2OutAccess=0;
																flagR2=0;
																yellowEatFlag=1;
															}
															else if((Y4X==R3X && Y4Y==R3Y))
															{
																R3X=167;
																R3Y=89;
																red3OutAccess=0;
																flagR3=0;
																yellowEatFlag=1;
															}
															else if((Y4X==R4X && 4==R4Y))
															{
																R4X=167;
																R4Y=167;
																red4OutAccess=0;
																flagR4=0;
																yellowEatFlag=1;
															}
															else if((Y4X==B1X && Y4Y==B1Y))
															{
																B1X=167;
																B1Y=401;
																blue1OutAccess=0;
																flagB1=0;
																yellowEatFlag=1;
															}
															else if((Y4X==B2X && Y4Y==B2Y))
															{
																B2X=89;
																B2Y=401;
																blue2OutAccess=0;
																flagB2=0;
																yellowEatFlag=1;
															}
															else if((Y4X==B3X && Y4Y==B3Y))
															{
																B3X=89;
																B3Y=323;
																blue3OutAccess=0;
																flagB3=0;
																yellowEatFlag=1;
															}
															else if((Y4X==B4X && Y4Y==B4Y))
															{
																B4X=167;
																B4Y=323;
																blue4OutAccess=0;
																flagB4=0;
																yellowEatFlag=1;
															}
															else if((Y4X==G1X && Y4Y==G1Y))
															{
																G1X=323;
																G1Y=89;
																green1OutAccess=0;
																flagG1=0;
																yellowEatFlag=1;
															}
															else if((Y4X==G2X && Y4Y==G2Y))
															{
																G2X=401;
																G2Y=89;
																green2OutAccess=0;
																flagG2=0;
																yellowEatFlag=1;
															}
															else if((Y4X==G3X && Y4Y==G3Y))
															{
																G3X=401;
																G3Y=167;
																green3OutAccess=0;
																flagG3=0;
																yellowEatFlag=1;
															}
															else if((Y4X==G4X && Y4Y==G4Y))
															{
																G4X=323;
																G4Y=167;
																green4OutAccess=0;
																flagG4=0;
																yellowEatFlag=1;
															}
															
                                            				setbkcolor(0);
															cleardevice();
															
															if(dice==1)
										                    {
										                    	readimagefile("1.jpg",441,285,465,309);
															}
															else if(dice==2)
										                    {
										                    	readimagefile("2.jpg",441,285,465,309);
															}
															else if(dice==3)
										                    {
										                    	readimagefile("3.jpg",441,285,465,309);
															}
															else if(dice==4)
							                                {
										                        readimagefile("4.jpg",441,285,465,309);
															}
															else if(dice==5)
						                                    {
										                        readimagefile("5.jpg",441,285,465,309);
															}
															else
							                                {
										                        readimagefile("6.jpg",441,285,465,309);
															}
															
                                            				display_Board();
                                            				
                                            				if(posY4==57)
                                            				{
                                            					yellowWinFlag=1;
															}
														}
														else
														{
															posY4=posY4-dice;
															
															if(dice==6 || yellow1OutAccess==6 || yellow2OutAccess==6 || yellow3OutAccess==6)
															{
																printf("\n\t YOU CAN'T MOVE PIECE NO 4..PLEASE ENTER PIECE NO AS PER THE RULE...");
																continue;
															}
															else
															{
																printf("\n\t YOU CAN'T MOVE ANY PIECE");
															}
														}
													}
                                    	    		
												}
												else
												{
													printf("\n\t YOU CAN'T MOVE PIECE NO 4..PLEASE ENTER PIECE NO AS PER THE RULE...");
													continue;
												}
                                             
											break;    
											
											default : 
												printf("\n\t PLEASE ENTER THE PIECE NUMBER OF RANGE 1 TO 4 ... "); 
												continue;                              
                                    	}
                                    	
                                    	if(yellowEatFlag==1 || yellowWinFlag==1)
                                    	{
                                    		yellowEatFlag=0;
                                    		yellowWinFlag=0; 
										}
										else if(dice==6)
										{
											count=count+1;
											if(count==3)
											{
												printf("\n\t YOU LOST YOUR TURN BECAUSE OF THREE CONJECUTIVE DICE 6...");
												break;
											}
										}
										else
										{
											if(player_no==4)
											p1++;
											else if(player_no==3)
											p1=p1-2;
											else
											p1=p1-2;
											
											count=0;
										}
										
									break;
									
									}
									
									if(dice==6 || yellow1OutAccess==6 || yellow2OutAccess==6 || yellow3OutAccess==6 || yellow4OutAccess==6)
									{
										
									}
									else
									{
										if(player_no==4)
										p1++;
										else if(player_no==3)
										p1=p1-2;
										else
										p1=p1-2;
											
										setbkcolor(0);
										cleardevice();
										
										if(dice==1)
									    {
						                	readimagefile("1.jpg",441,285,465,309);
										}
										else if(dice==2)
					                    {
							                readimagefile("2.jpg",441,285,465,309);
										}
										else if(dice==3)
						                {
						                	readimagefile("3.jpg",441,285,465,309);
										}
										else if(dice==4)
						                {
									  	    readimagefile("4.jpg",441,285,465,309);
										}
										else if(dice==5)
		                                {
					                        readimagefile("5.jpg",441,285,465,309);
										}
										else
		                                {
					                        readimagefile("6.jpg",441,285,465,309);
										}
										
                                        display_Board();	
									}	
                                break;
                                
                                default :
                                    printf("\n\t YOU ENTERED WRONG INPUT. PLEASE ENETR 1...");
                            }
                            getchar();
                            break;
                            
                        case 4 : 
                            printf("\n\t %s TURNS ENETR 1 FOR PLAY : ",player4);
                            scanf("%d",&play_choice);
                            switch(play_choice)
                            {
                                case 1 :
                                    dice=rd();
                                    printf("\n\t\t DICE : %d",dice);
                                    
                                    while(dice==6 || blue1OutAccess==6 || blue2OutAccess==6 || blue3OutAccess==6 || blue4OutAccess==6)
                                    {
                                    	if(dice==1)
					                    {
					                    	readimagefile("1.jpg",25,285,49,309);
										}
										else if(dice==2)
					                    {
					                    	readimagefile("2.jpg",25,285,49,309);
										}
										else if(dice==3)
					                    {
					                    	readimagefile("3.jpg",25,285,49,309);
										}
										else if(dice==4)
		                                {
					                        readimagefile("4.jpg",25,285,49,309);
										}
										else if(dice==5)
	                                    {
					                        readimagefile("5.jpg",25,285,49,309);
										}
										else
		                                {
					                        readimagefile("6.jpg",25,285,49,309);
										}
										
                                    	printf("\n\n\t %s. ENETR THE PIECE NUMBER WHICH PIECE YOU WANT TO MOVE : ",player4);
                                    	scanf("%d",&piece_No);

                                    	switch(piece_No)
                                    	{
                                    	    case 1 :
                                    	    	if(dice==6 || blue1OutAccess==6)
                                    	    	{
                                    	    		blue1OutAccess=6;
                                    	    		
                                    	    		if(flagB1==0)
                                    	    		{
                                    	    			posB1=1;
                                            			B1X = Blue_X[posB1];
                                            			B1Y = Blue_Y[posB1];
                                            
                                            			setbkcolor(0);
														cleardevice();
														
														if(dice==1)
													    {
										                	readimagefile("1.jpg",25,285,49,309);
														}
														else if(dice==2)
									                    {
											                readimagefile("2.jpg",25,285,49,309);
														}
														else if(dice==3)
										                {
										                	readimagefile("3.jpg",25,285,49,309);
														}
														else if(dice==4)
										                {
													  	    readimagefile("4.jpg",25,285,49,309);
														}
														else if(dice==5)
						                                {
									                        readimagefile("5.jpg",25,285,49,309);
														}
														else
						                                {
									                        readimagefile("6.jpg",25,285,49,309);
														}
										
                                            			display_Board();
                                            			
														flagB1=1;
													}
													else
													{
														posB1=posB1+dice;
														
														if(posB1<58)
														{
                                            				B1X = Blue_X[posB1];
                                            				B1Y = Blue_Y[posB1];
                                            				
                                            				if((B1X==89 && B1Y==219) || (B1X==219 && B1Y==115) ||(B1X==271 && B1Y==89) ||(B1X==375 && B1Y==219) ||(B1X==401 && B1Y==271) ||(B1X==271 && B1Y==375) ||(B1X==219 && B1Y==401) ||(B1X==115 && B1Y==271))
                                            				{
                                            					
															}
															else if((B1X==R1X && B1Y==R1Y))
															{
																R1X=89;
																R1Y=167;
																red1OutAccess=0;
																flagR1=0;
																blueEatFlag=1;
															}
															else if((B1X==R2X && B1Y==R2Y))
															{
																R2X=89;
																R2Y=89;
																red2OutAccess=0;
																flagR2=0;
																blueEatFlag=1;
															}
															else if((B1X==R3X && B1Y==R3Y))
															{
																R3X=167;
																R3Y=89;
																red3OutAccess=0;
																flagR3=0;
																blueEatFlag=1;
															}
															else if((B1X==R4X && B1Y==R4Y))
															{
																R4X=167;
																R4Y=167;
																red4OutAccess=0;
																flagR4=0;
																blueEatFlag=1;
															}
															else if((B1X==G1X && B1Y==G1Y))
															{
																G1X=323;
																G1Y=89;
																green1OutAccess=0;
																flagG1=0;
																blueEatFlag=1;
															}
															else if((B1X==G2X && B1Y==G2Y))
															{
																G2X=401;
																G2Y=89;
																green2OutAccess=0;
																flagG2=0;
																blueEatFlag=1;
															}
															else if((B1X==G3X && B1Y==G3Y))
															{
																G3X=401;
																G3Y=167;
																green3OutAccess=0;
																flagG3=0;
																blueEatFlag=1;
															}
															else if((B1X==G4X && B1Y==G4Y))
															{
																G4X=323;
																G4Y=167;
																green4OutAccess=0;
																flagG4=0;
																blueEatFlag=1;
															}
															else if((B1X==Y1X && B1Y==Y1Y))
															{
																Y1X=401;
																Y1Y=323;
																yellow1OutAccess=0;
																flagY1=0;
																blueEatFlag=1;
															}
															else if((B1X==Y2X && B1Y==Y2Y))
															{
																Y2X=401;
																Y2Y=401;
																yellow2OutAccess=0;
																flagY2=0;
																blueEatFlag=1;
															}
															else if((B1X==Y3X && B1Y==Y3Y))
															{
																Y3X=323;
																Y3Y=401;
																yellow3OutAccess=0;
																flagY3=0;
																blueEatFlag=1;
															}
															else if((B1X==Y4X && B1Y==Y4Y))
															{
																Y4X=323;
																Y4Y=323;
																yellow4OutAccess=0;
																flagY4=0;
																blueEatFlag=1;
															}
															
                                            				setbkcolor(0);
															cleardevice();
															
															if(dice==1)
														    {
											                	readimagefile("1.jpg",25,285,49,309);
															}
															else if(dice==2)
										                    {
												                readimagefile("2.jpg",25,285,49,309);
															}
															else if(dice==3)
											                {
											                	readimagefile("3.jpg",25,285,49,309);
															}
															else if(dice==4)
											                {
														  	    readimagefile("4.jpg",25,285,49,309);
															}
															else if(dice==5)
							                                {
										                        readimagefile("5.jpg",25,285,49,309);
															}
															else
							                                {
										                        readimagefile("6.jpg",25,285,49,309);
															}
														
                                            				display_Board();
                                            				
                                            				if(posB1==57)
                                            				{
                                            					blueWinFlag=1;
															}
														}
														else
														{
															posB1=posB1-dice;
															
															if(dice==6 || blue2OutAccess==6 || blue3OutAccess==6 || blue4OutAccess==6)
															{
																printf("\n\t YOU CAN'T MOVE PIECE NO 1..PLEASE ENTER PIECE NO AS PER THE RULE...");
																continue;
															}
															else
															{
																printf("\n\t YOU CAN'T MOVE ANY PIECE");
															}
														}
													}
                                    	    		
												}
												else
												{
													printf("\n\t YOU CAN'T MOVE PIECE NO 1..PLEASE ENTER PIECE NO AS PER THE RULE...");
													continue;
												}
                                             
											break;
										
											case 2 :
												if(dice==6 || blue2OutAccess==6)
                                    	    	{
                                    	    		blue2OutAccess=6;
                                    	    		
                                    	    		if(flagB2==0)
                                    	    		{
                                    	    			posB2=1;
                                            			B2X = Blue_X[posB2];
                                            			B2Y = Blue_Y[posB2];
                                            
                                            			setbkcolor(0);
														cleardevice();
														
														if(dice==1)
													    {
										                	readimagefile("1.jpg",25,285,49,309);
														}
														else if(dice==2)
									                    {
											                readimagefile("2.jpg",25,285,49,309);
														}
														else if(dice==3)
										                {
										                	readimagefile("3.jpg",25,285,49,309);
														}
														else if(dice==4)
										                {
													  	    readimagefile("4.jpg",25,285,49,309);
														}
														else if(dice==5)
						                                {
									                        readimagefile("5.jpg",25,285,49,309);
														}
														else
						                                {
									                        readimagefile("6.jpg",25,285,49,309);
														}
														
                                            			display_Board();
                                            			
														flagB2=1;
													}
													else
													{
														posB2=posB2+dice;
														
														if(posB2<58)
														{
                                            				B2X = Blue_X[posB2];
                                            				B2Y = Blue_Y[posB2];
                                            				
                                            				if((B2X==89 && B2Y==219) || (B2X==219 && B2Y==115) ||(B2X==271 && B2Y==89) ||(B2X==375 && B2Y==219) ||(B2X==401 && B2Y==271) ||(B2X==271 && B2Y==375) ||(B2X==219 && B2Y==401) ||(B2X==115 && B2Y==271))
                                            				{
                                            					
															}
															else if((B2X==R1X && B2Y==R1Y))
															{
																R1X=89;
																R1Y=167;
																red1OutAccess=0;
																flagR1=0;
																blueEatFlag=1;
															}
															else if((B2X==R2X && B2Y==R2Y))
															{
																R2X=89;
																R2Y=89;
																red2OutAccess=0;
																flagR2=0;
																blueEatFlag=1;
															}
															else if((B2X==R3X && B2Y==R3Y))
															{
																R3X=167;
																R3Y=89;
																red3OutAccess=0;
																flagR3=0;
																blueEatFlag=1;
															}
															else if((B2X==R4X && B2Y==R4Y))
															{
																R4X=167;
																R4Y=167;
																red4OutAccess=0;
																flagR4=0;
																blueEatFlag=1;
															}
															else if((B2X==G1X && B2Y==G1Y))
															{
																G1X=323;
																G1Y=89;
																green1OutAccess=0;
																flagG1=0;
																blueEatFlag=1;
															}
															else if((B2X==G2X && B2Y==G2Y))
															{
																G2X=401;
																G2Y=89;
																green2OutAccess=0;
																flagG2=0;
																blueEatFlag=1;
															}
															else if((B2X==G3X && B2Y==G3Y))
															{
																G3X=401;
																G3Y=167;
																green3OutAccess=0;
																flagG3=0;
																blueEatFlag=1;
															}
															else if((B2X==G4X && B2Y==G4Y))
															{
																G4X=323;
																G4Y=167;
																green4OutAccess=0;
																flagG4=0;
																blueEatFlag=1;
															}
															else if((B2X==Y1X && B2Y==Y1Y))
															{
																Y1X=401;
																Y1Y=323;
																yellow1OutAccess=0;
																flagY1=0;
																blueEatFlag=1;
															}
															else if((B2X==Y2X && B2Y==Y2Y))
															{
																Y2X=401;
																Y2Y=401;
																yellow2OutAccess=0;
																flagY2=0;
																blueEatFlag=1;
															}
															else if((B2X==Y3X && B2Y==Y3Y))
															{
																Y3X=323;
																Y3Y=401;
																yellow3OutAccess=0;
																flagY3=0;
																blueEatFlag=1;
															}
															else if((B2X==Y4X && B2Y==Y4Y))
															{
																Y4X=323;
																Y4Y=323;
																yellow4OutAccess=0;
																flagY4=0;
																blueEatFlag=1;
															}
                                            				
                                            				setbkcolor(0);
															cleardevice();
															
															if(dice==1)
														    {
											                	readimagefile("1.jpg",25,285,49,309);
															}
															else if(dice==2)
										                    {
												                readimagefile("2.jpg",25,285,49,309);
															}
															else if(dice==3)
											                {
											                	readimagefile("3.jpg",25,285,49,309);
															}
															else if(dice==4)
											                {
														  	    readimagefile("4.jpg",25,285,49,309);
															}
															else if(dice==5)
							                                {
										                        readimagefile("5.jpg",25,285,49,309);
															}
															else
							                                {
										                        readimagefile("6.jpg",25,285,49,309);
															}
														
                                            				display_Board();
                                            				
                                            				if(posB2==57)
                                            				{
                                            					blueWinFlag=1;
															}
														}
														else
														{
															posB2=posB2-dice;
															
															if(dice==6 || blue1OutAccess==6 || blue3OutAccess==6 || blue4OutAccess==6)
															{
																printf("\n\t YOU CAN'T MOVE PIECE NO 2..PLEASE ENTER PIECE NO AS PER THE RULE...");
																continue;
															}
															else
															{
																printf("\n\t YOU CAN'T MOVE ANY PIECE");
															}
														}
													}
                                    	    		
												}
												else
												{
													printf("\n\t YOU CAN'T MOVE PIECE NO 2..PLEASE ENTER PIECE NO AS PER THE RULE...");
													continue;
												}
                                             
											break;   
										
											case 3 :
												if(dice==6 || blue3OutAccess==6)
                                    	    	{
                                    	    		blue3OutAccess=6;
                                    	    		
                                    	    		if(flagB3==0)
                                    	    		{
                                    	    			posB3=1;
                                            			B3X = Blue_X[posB3];
                                            			B3Y = Blue_Y[posB3];
                                            
                                            			setbkcolor(0);
														cleardevice();
														
														if(dice==1)
													    {
										                	readimagefile("1.jpg",25,285,49,309);
														}
														else if(dice==2)
									                    {
											                readimagefile("2.jpg",25,285,49,309);
														}
														else if(dice==3)
										                {
										                	readimagefile("3.jpg",25,285,49,309);
														}
														else if(dice==4)
										                {
													  	    readimagefile("4.jpg",25,285,49,309);
														}
														else if(dice==5)
						                                {
									                        readimagefile("5.jpg",25,285,49,309);
														}
														else
						                                {
									                        readimagefile("6.jpg",25,285,49,309);
														}
														
                                            			display_Board();
                                            			
														flagB3=1;
													}
													else
													{
														posB3=posB3+dice;
														
														if(posB3<58)
														{
                                            				B3X = Blue_X[posB3];
                                            				B3Y = Blue_Y[posB3];
                                            				
                                            				if((B3X==89 && B3Y==219) || (B3X==219 && B3Y==115) ||(B3X==271 && B3Y==89) ||(B3X==375 && B3Y==219) ||(B3X==401 && B3Y==271) ||(B3X==271 && B3Y==375) ||(B3X==219 && B3Y==401) ||(B3X==115 && B3Y==271))
                                            				{
                                            					
															}
															else if((B3X==R1X && B3Y==R1Y))
															{
																R1X=89;
																R1Y=167;
																red1OutAccess=0;
																flagR1=0;
																blueEatFlag=1;
															}
															else if((B3X==R2X && B3Y==R2Y))
															{
																R2X=89;
																R2Y=89;
																red2OutAccess=0;
																flagR2=0;
																blueEatFlag=1;
															}
															else if((B3X==R3X && B3Y==R3Y))
															{
																R3X=167;
																R3Y=89;
																red3OutAccess=0;
																flagR3=0;
																blueEatFlag=1;
															}
															else if((B3X==R4X && B3Y==R4Y))
															{
																R4X=167;
																R4Y=167;
																red4OutAccess=0;
																flagR4=0;
																blueEatFlag=1;
															}
															else if((B3X==G1X && B3Y==G1Y))
															{
																G1X=323;
																G1Y=89;
																green1OutAccess=0;
																flagG1=0;
																blueEatFlag=1;
															}
															else if((B3X==G2X && B3Y==G2Y))
															{
																G2X=401;
																G2Y=89;
																green2OutAccess=0;
																flagG2=0;
																blueEatFlag=1;
															}
															else if((B3X==G3X && B3Y==G3Y))
															{
																G3X=401;
																G3Y=167;
																green3OutAccess=0;
																flagG3=0;
																blueEatFlag=1;
															}
															else if((B3X==G4X && B3Y==G4Y))
															{
																G4X=323;
																G4Y=167;
																green4OutAccess=0;
																flagG4=0;
																blueEatFlag=1;
															}
															else if((B3X==Y1X && B3Y==Y1Y))
															{
																Y1X=401;
																Y1Y=323;
																yellow1OutAccess=0;
																flagY1=0;
																blueEatFlag=1;
															}
															else if((B3X==Y2X && B3Y==Y2Y))
															{
																Y2X=401;
																Y2Y=401;
																yellow2OutAccess=0;
																flagY2=0;
																blueEatFlag=1;
															}
															else if((B3X==Y3X && B3Y==Y3Y))
															{
																Y3X=323;
																Y3Y=401;
																yellow3OutAccess=0;
																flagY3=0;
																blueEatFlag=1;
															}
															else if((B3X==Y4X && B3Y==Y4Y))
															{
																Y4X=323;
																Y4Y=323;
																yellow4OutAccess=0;
																flagY4=0;
																blueEatFlag=1;
															}
                                            				
                                            				setbkcolor(0);
															cleardevice();
															
															if(dice==1)
														    {
											                	readimagefile("1.jpg",25,285,49,309);
															}
															else if(dice==2)
										                    {
												                readimagefile("2.jpg",25,285,49,309);
															}
															else if(dice==3)
											                {
											                	readimagefile("3.jpg",25,285,49,309);
															}
															else if(dice==4)
											                {
														  	    readimagefile("4.jpg",25,285,49,309);
															}
															else if(dice==5)
							                                {
										                        readimagefile("5.jpg",25,285,49,309);
															}
															else
							                                {
										                        readimagefile("6.jpg",25,285,49,309);
															}
														
                                            				display_Board();
                                            				
                                            				if(posB3==57)
                                            				{
                                            					blueWinFlag=1;
															}
														}
														else
														{
															posB3=posB3-dice;
															
															if(dice==6 || blue1OutAccess==6 || blue2OutAccess==6 || blue4OutAccess==6)
															{
																printf("\n\t YOU CAN'T MOVE PIECE NO 3..PLEASE ENTER PIECE NO AS PER THE RULE...");
																continue;
															}
															else
															{
																printf("\n\t YOU CAN'T MOVE ANY PIECE");
															}
														}
													}
                                    	    		
												}
												else
												{
													printf("\n\t YOU CAN'T MOVE PIECE NO 3..PLEASE ENTER PIECE NO AS PER THE RULE...");
													continue;
												}
                                             
											break;
										
											case 4 :
												if(dice==6 || blue4OutAccess==6)
                                    	    	{
                                    	    		blue4OutAccess=6;
                                    	    		
                                    	    		if(flagB4==0)
                                    	    		{
                                    	    			posB4=1;
                                            			B4X = Blue_X[posB4];
                                            			B4Y = Blue_Y[posB4];
                                            
                                            			setbkcolor(0);
														cleardevice();
														
														if(dice==1)
													    {
										                	readimagefile("1.jpg",25,285,49,309);
														}
														else if(dice==2)
									                    {
											                readimagefile("2.jpg",25,285,49,309);
														}
														else if(dice==3)
										                {
										                	readimagefile("3.jpg",25,285,49,309);
														}
														else if(dice==4)
										                {
													  	    readimagefile("4.jpg",25,285,49,309);
														}
														else if(dice==5)
						                                {
									                        readimagefile("5.jpg",25,285,49,309);
														}
														else
						                                {
									                        readimagefile("6.jpg",25,285,49,309);
														}
														
                                            			display_Board();
                                            			
														flagB4=1;
													}
													else
													{
														posB4=posB4+dice;
														
														if(posB4<58)
														{
                                            				B4X = Blue_X[posB4];
                                            				B4Y = Blue_Y[posB4];
                                            				
                                            				if((B4X==89 && B4Y==219) || (B4X==219 && B4Y==115) ||(B4X==271 && B4Y==89) ||(B4X==375 && B4Y==219) ||(B4X==401 && B4Y==271) ||(B4X==271 && B4Y==375) ||(B4X==219 && B4Y==401) ||(B4X==115 && B4Y==271))
                                            				{
                                            					
															}
															else if((B4X==R1X && B4Y==R1Y))
															{
																R1X=89;
																R1Y=167;
																red1OutAccess=0;
																flagR1=0;
																blueEatFlag=1;
															}
															else if((B4X==R2X && B4Y==R2Y))
															{
																R2X=89;
																R2Y=89;
																red2OutAccess=0;
																flagR2=0;
																blueEatFlag=1;
															}
															else if((B4X==R3X && B4Y==R3Y))
															{
																R3X=167;
																R3Y=89;
																red3OutAccess=0;
																flagR3=0;
																blueEatFlag=1;
															}
															else if((B4X==R4X && B4Y==R4Y))
															{
																R4X=167;
																R4Y=167;
																red4OutAccess=0;
																flagR4=0;
																blueEatFlag=1;
															}
															else if((B4X==G1X && B4Y==G1Y))
															{
																G1X=323;
																G1Y=89;
																green1OutAccess=0;
																flagG1=0;
																blueEatFlag=1;
															}
															else if((B4X==G2X && B4Y==G2Y))
															{
																G2X=401;
																G2Y=89;
																green2OutAccess=0;
																flagG2=0;
																blueEatFlag=1;
															}
															else if((B4X==G3X && B4Y==G3Y))
															{
																G3X=401;
																G3Y=167;
																green3OutAccess=0;
																flagG3=0;
																blueEatFlag=1;
															}
															else if((B4X==G4X && B4Y==G4Y))
															{
																G4X=323;
																G4Y=167;
																green4OutAccess=0;
																flagG4=0;
																blueEatFlag=1;
															}
															else if((B4X==Y1X && B4Y==Y1Y))
															{
																Y1X=401;
																Y1Y=323;
																yellow1OutAccess=0;
																flagY1=0;
																blueEatFlag=1;
															}
															else if((B4X==Y2X && B4Y==Y2Y))
															{
																Y2X=401;
																Y2Y=401;
																yellow2OutAccess=0;
																flagY2=0;
																blueEatFlag=1;
															}
															else if((B4X==Y3X && B4Y==Y3Y))
															{
																Y3X=323;
																Y3Y=401;
																yellow3OutAccess=0;
																flagY3=0;
																blueEatFlag=1;
															}
															else if((B4X==Y4X && B4Y==Y4Y))
															{
																Y4X=323;
																Y4Y=323;
																yellow4OutAccess=0;
																flagY4=0;
																blueEatFlag=1;
															}
                                            				
                                            				setbkcolor(0);
															cleardevice();
															
															if(dice==1)
														    {
											                	readimagefile("1.jpg",25,285,49,309);
															}
															else if(dice==2)
										                    {
												                readimagefile("2.jpg",25,285,49,309);
															}
															else if(dice==3)
											                {
											                	readimagefile("3.jpg",25,285,49,309);
															}
															else if(dice==4)
											                {
														  	    readimagefile("4.jpg",25,285,49,309);
															}
															else if(dice==5)
							                                {
										                        readimagefile("5.jpg",25,285,49,309);
															}
															else
							                                {
										                        readimagefile("6.jpg",25,285,49,309);
															}
                                            				display_Board();
                                            				
                                            				if(posB4==57)
                                            				{
                                            					blueWinFlag=1;
															}
														}
														else
														{
															posB4=posB4-dice;
															
															if(dice==6 || blue1OutAccess==6 || blue2OutAccess==6 || blue3OutAccess==6)
															{
																printf("\n\t YOU CAN'T MOVE PIECE NO 4..PLEASE ENTER PIECE NO AS PER THE RULE...");
																continue;
															}
															else
															{
																printf("\n\t YOU CAN'T MOVE ANY PIECE");
															}
														}
													}
                                    	    		 
												}
												else
												{
													printf("\n\t YOU CAN'T MOVE PIECE NO 4..PLEASE ENTER PIECE NO AS PER THE RULE...");
													continue;
												}
                                            
											break;
											
											default : 
												printf("\n\t PLEASE ENTER THE PIECE NUMBER OF RANGE 1 TO 4 ... ");
												continue;                           
                                   		}
                                    	
                                    	if(blueEatFlag==1 || blueWinFlag==1)
                                    	{
                                    		blueEatFlag=0;
                                    		blueWinFlag=0;
										}
										else if(dice==6)
										{
											count=count+1;
											if(count==3)
											{
												printf("\n\t YOU LOST YOUR TURN BECAUSE OF THREE CONJECUTIVE DICE 6...");
												break;
											}
										}
										else
										{
											p1=p1-3;
											count=0;
										}
										
									break;
									
									}
									
                                    if(dice==6 || blue1OutAccess==6 || blue2OutAccess==6 || blue3OutAccess==6 || blue4OutAccess==6)
                                    {
                                    		
									}
									else
									{
										p1=p1-3;
										setbkcolor(0);
										cleardevice();
										
										if(dice==1)
					                    {
					                    	readimagefile("1.jpg",25,285,49,309);
										}
										else if(dice==2)
					                    {
					                    	readimagefile("2.jpg",25,285,49,309);
										}
										else if(dice==3)
					                    {
					                    	readimagefile("3.jpg",25,285,49,309);
										}
										else if(dice==4)
		                                {
					                        readimagefile("4.jpg",25,285,49,309);
										}
										else if(dice==5)
	                                    {
					                        readimagefile("5.jpg",25,285,49,309);
										}
										else
		                                {
					                        readimagefile("6.jpg",25,285,49,309);
										}
										
                                        display_Board();
									}		
                                break;
                                
                                default :
                                    printf("\n\t YOU ENTERED WRONG INPUT. PLEASE ENETR 1...");
                            }
                            
                            getchar();
                            break;
                    }
					
					
					if(posR1==57 && posR2==57 && posR3==57 && posR4==57)
					{
						printf("\n\n\n\t\t\t CONGRATULATIONS %s. YOU WIN THE GAME.....",player1);
						getchar();
						exit(0);
					}
					else if(posG1==57 && posG2==57 && posG3==57 && posG4==57)
					{
						printf("\n\n\n\t\t\t CONGRATULATIONS %s. YOU WIN THE GAME.....",player2);
						getchar();
						exit(0);
					}
					else if(posY1==57 && posY2==57 && posY3==57 && posY4==57)
					{
						printf("\n\n\n\t\t\t CONGRATULATIONS %s. YOU WIN THE GAME.....",player3);
						getchar();
						exit(0);
					}
					else if(posB1==57 && posB2==57 && posB3==57 && posB4==57)
					{
						printf("\n\n\n\t\t\t CONGRATULATIONS %s. YOU WIN THE GAME.....",player4);
						getchar();
						exit(0);
					}
					
                }
                break;
        	case 2 : 
        		printf("\n\t YOU EXIT SUCCESSFULLY....");
        		exit(0);
        		break;
        	
        	default :
        		getchar();
        		printf("\n\t YOU ENTERED WRONG CHOICE. PLEASE ENTER 1 FOR PLAY OR 2 FOR EXIT.....\n\t PRESS ENTER KEY TO CONTUNUE.....");
        		getchar();
        		continue;
        	
        }
    }
	
	closegraph();
	return 0;
}

