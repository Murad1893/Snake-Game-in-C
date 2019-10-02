#include<stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<windows.h>



char maze[100][100];
int i,j,h1,h2,t1,t2,score=0,f1,f2;
int tail_x[100],tail_y[100];
char name[100];

void assign_maze()
{
	
    	for(i=0;i<=20;i++)
     {
     	for(j=0;j<=30;j++)
     	{
     		if(i==0 || i==20 || j==0 || j==30)
     		{
     			maze[i][j]=219;
			 }
			 else maze[i][j]=' ';
		 }
	 }
	
}

void print_maze()
{
	print_score();
	printf("\n");
	
	for(i=0;i<=20;i++)
     {printf("\t\t\t");
     	for(j=0;j<=30;j++)
     	{
		 
     		printf("%c",maze[i][j]);
     	
		 }
		 printf("\n");
	 }	
	
}


void print_food()
{
	f1=rand()%20;
	f2=rand()%30;
	maze[f1][f2]='O';
	
}

void move_tail()
{
    int i,x,y,temp1,temp2;

    x=tail_x[0];
    y=tail_y[0];

    tail_x[0]=h1;
    tail_y[0]=h2;
    
    for(i=1;i<=score;i++)
    {   temp1=0;
	    temp2=0;
    	
        maze[x][y]='-';
        temp1 = tail_x[i];
        temp2 = tail_y[i];

        tail_x[i]=x; 
        tail_y[i]=y;

        x=temp1; 
        y=temp2;
       
    }

}
void remove_tail()
{
    int x,y;
    for(x=0;x<=20;x++)
        for(y=0;y<=30;y++)
    {
        if(maze[x][y]=='-')
            maze[x][y]=' ';
    }

}

int print_score(){

	
	printf("Score: %d food(%d,%d) head(%d,%d) tail(%d,%d) ",score,f1,f2,h1,h2,tail_x[1],tail_y[1]);
	printf("\nPress any key accept WASD to pause. Press ESC key to end game.\n");

	
}

void up(){
	char y;
	if(maze[h1][h2]==maze[f1][f2])
	{
		score++;
		Beep(10000,50);
		print_food();
	}
	
	
	 maze[h1][h2]=' ';
        maze[h1-1][h2]='^';
        h1--;

}
void down(){
	if(maze[h1][h2]==maze[f1][f2])
	{
		score++;
		Beep(10000,50);
		print_food();
	}
	 maze[h1][h2]=' ';
        maze[h1+1][h2]='V';
        h1++;
}
void right(){
	if(maze[h1][h2]==maze[f1][f2])
	{
		score++;
		Beep(10000,50);
		print_food();
	}
	 maze[h1][h2]=' ';
        maze[h1][h2+1]='>';
        h2++;
}
void left(){
	if(maze[h1][h2]==maze[f1][f2])
	{
		score++;
		Beep(10000,50);
		print_food();
	}
	    maze[h1][h2]=' ';
        maze[h1][h2-1]='<';
        h2--;
}

void gameover()
{   
    if(maze[h1][h2]=='-'){
	music();
	end();
    exit(0);}
	if(maze[h1][h2]==maze[0][h2])
	    {
	    end();
		exit(0);}
    if(maze[h1][h2]==maze[h1][0]){
    music();
	end();
        exit(0);}
    if(maze[h1][h2]==maze[20][h2]){
	music();
	end();
        exit(0);}
    if(maze[h1][h2]==maze[h1][30]){
	music();
	end();
        exit(0);}
    
	
}
int music(){
	Beep (800,100);
	Beep (400,100);
	Beep (500,100);
    Beep (400,100);
    Beep (800,100);
	Beep (400,100);
	Beep (500,100);
    Beep (400,100);
    Beep (100,675);
}

int end()
{
	system("cls");
	printf("Name :");
	puts(name);
	printf("\n");
	printf("Score: %d",score);
	getch();
	printf("\n\nDo you want to play again? Y or N");
	char y=getch();
	switch(y)
	{
		case 'Y':
			main();
			break;
		default:
			getch();
			exit(0);
	}
	
}

void intro()
{
	system("cls");
	printf("\t\tWELCOME TO THE SNAKE GAME!\n                         ");
	printf("\n\n");
	printf("\t\tA Project By:                                            O \n");
	printf("\t\tMurad Popattia (K17-3722)                               O  \n");
	printf("\t\tAli Ammar (K17-3713)                                     O \n");
	printf("\t\tOsama Ali (K17-3716)                                    O  \n");
	printf("\t\tHamza Ahmad (K17-3703)                                   O \n");
	
	printf("\n\n\t\tEnter your name: ");
	gets(name);	
}

void rules()
{
	printf("\t\tRules:\n");
	printf("1. Control the snake by WASD keys.\n");
	printf("2. As the snake eats food its length will grow and so will the score.\n");
	printf("3. If the snake hits the walls or its body.. its game over!");
	printf("\n\n\t Select your Difficulty: ");
	printf("\n\n\tEasy(E)");
		printf("\n\n\tMedium(M)");
			printf("\n\n\tHard(H)\n");
		
	
}


int main()
{
	char ch;
	int x;
	score=0;
     intro();
     system("cls");
     rules();
     label:
     printf("\n\nEnter here: ");
     ch=getche();
     switch(ch){
     	case 'E':
     		{
     			x=300;
     			printf("\n\nPress any key too continue.....");
     			break;
			 }
			 case 'M':
     		{
     			x=200;
     			printf("\n\nPress any key too continue.....");
     			break;
			 }
			 case 'H':
     		{
     			x=80;
     			printf("\n\nPress any key too continue.....");
     			break;
			 }
			 default:
			{
				printf("\n\nPlease enter a valid key ");
				goto label;
			}
	    
	 }
     assign_maze();
     h1=15;
     h2=15;
     print_food();
     maze[15][15]='>';
     char y;
     do{
	
	y=getch();	
	switch(y)
	{
		case 'w':
		  {
		  
		   while(!kbhit())
		   {
		   	up();
		   	system("cls");
remove_tail();
move_tail();
print_maze();
gameover();
Sleep(x);

		   
		   }
break;
	}
		  	case 's':
		  {
		  	while(!kbhit())
		   {
		   	down();
		   	system("cls");
remove_tail();
move_tail();
print_maze();
gameover();
Sleep(x);
		   	
		   }
		  	
		  	break;
		  }
		  	case 'a':
		  {
		  	while(!kbhit())
		   {
		   	left();
		   	system("cls");
remove_tail();
move_tail();
print_maze();
gameover();
Sleep(x);
		   	
		   }
		  	
		  	break;
		  }
		  	case 'd':
		  {
		  	while(!kbhit())
		   {
		   	right();
		   	system("cls");
remove_tail();
move_tail();
print_maze();
gameover();
Sleep(x);
		   
		   }
		  	
		  	break;
		  }
		  default:
		  break;
		  
}
system("cls");
print_maze();
gameover();

}while(y!=27);
end();
}
