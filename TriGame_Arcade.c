/******************************************************************************
 *                                                                            *
 *                               PROJECT: TriGame Arcade                      *
 *                                                                            *
 ******************************************************************************
 *                                                                            *
 *  Authors:                                                                  *
 *                                                                            *
 *  Sabit Siraji                                                              *
 *  --------------------------------------------------------------------------*
 *  Role: Primary Developer                                                   *                                                     *
 *  Contact: sabitsiraji@gmail.com                                            *
 *                                                                            *
 *  Tamimul Islam                                                             *
 *  --------------------------------------------------------------------------*
 *  Role: Developer                                                           *
 *  Contact: tamimulislam@gmail.com                                           *
 *                                                                            *
 *  Alif Ul Haque                                                             *
 *  --------------------------------------------------------------------------*
 *  Role: Developer                                                           *
 *  Contact: alifhaque19@gmail.com                                            *
 *                                                                            *
 * ----------------------------------------------------------------------------
 *  Description:                                                              *
 *  This project is designed to manage inventory in a warehouse. It includes  *
 *  features for adding, removing, and updating inventory items, as well as   *
 *  generating reports on inventory status.                                   *
 *                                                                            *
 *  Date Created: December 15, 2023                                           *
 *  Last Modified: June 17, 2024                                              *
 *                                                                            *
 ******************************************************************************
 */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<windows.h>
#include<string.h>
#include <conio.h>
#include <process.h>


#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

//TIC TAC TOE FUNCTIONS:

char board[3][3];
char PLAYER,COMPUTER;
struct player
{
    char name[20];
} p1,p2,p3,p4;
int player_count;

void get_info();
void gotoxy(int, int);
void thank();
void load1();
void Select_char();
void show_tut();
void resetBoard();
void printBoard();
void printTutorial();
int checkFreeCell();
void playerMove();
void playerMove2();
int checkWin(char);
int minimax(int, int);
void computerMove();
char checkWinner();
void printWinner(char);
char gamewinner;
void setTextColor();
void recc(char string[]);



//HORSE GAME FUNCTIONS:

void setTextColor(int color);
void gotoxy(int x, int y);
void introduction();
void loading();
void delayy(unsigned int mseconds);
void getup();
void ds(int jump);
void Playagain();
void rec();
void gameover();
void ext();
void lifedecrease();
int obj();
void pause();

static int life1 = 3, scr = 0;
double t = 0, speed = 25;


//SNAKE GAME FUNCTIONS

int length;
int bend_no;
int len;
char key;
void record();
void load();
int life;
int score;
void Delay(long double);
void Move();
void Food();
int Score();
void Print();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void ExitGame();
int Scoreonly();
void playagain();
void setTextColor();

struct coordinate
{
    int x;
    int y;
    int direction;
};

typedef  struct coordinate coordinate;
coordinate head, bend[500],food,body[30];


char c;
int main()
{
    system("cls");
    setTextColor(2);
    printf("\t\t\t\tWELCOME TO MIST ARCADE, the world of MINI GAMES!!\n\n");
    setTextColor(7);
    printf("Here you are getting the chance to explore a number of tiny adventures.\n\n");
    printf("Without delay, let us peek through any of the three adventures.\n\n");
    printf("In our journey, We are entering into any one of the three adventures.\nWe can explore the world of snake game, we can ride a stunning horse, else we can try a tic tac toe game.\n\n");
    setTextColor(2);
    printf("LET US START OUR JOURNEY!!\n\n");
    setTextColor(7);
    while(1)
    {
        setTextColor(4);
        printf("Press A for entering the HORIZON of HORSE\n\n");
        setTextColor(1);
        printf("Press B for entering SNAKE WORLD\n\n");
        setTextColor(6);
        printf("Press C for brainstorming TIC TAC TOE\n\n");
        setTextColor(7);
        printf("Press Q key for exit.\n");
        scanf(" %c",&c);
        c = toupper(c);
        if(c>'C' &&  c!='Q')
        {
            printf("\nEnter a valid character: \n");
        }
        else break;
    }
    getchar();
    system("cls");

    switch(c)
    {
    case 'A':
        system("cls");

        introduction();

        loading();

        getup();
        char ch;
        while(1)
        {

            while(!kbhit())
            {
                ds(0);
                obj();
            }

            ch=getch();
            if(ch==' ')
            {
                for(double i=0; i<15; i+=0.5)
                {
                    ds(1);
                    obj();
                }
                for(double i=0; i<15; i+=0.5)
                {
                    ds(2);
                    obj();
                }
            }
            else if (ch=='x')
            {
                ext();
            }
            else if(ch=='p')
            {
                pause();
            }

        }
        break;


    case 'B':
        //char key;

        Print();

        system("cls");

        load();

        length=5;

        head.x=25;

        head.y=20;

        head.direction=RIGHT;

        Boarder();

        Food(); //to generate food coordinates initially

        life=3; //number of extra lives

        bend[0]=head;

        Move();   //initialing initial bend coordinate

        return 0;
        break;


    case 'C':
        printTutorial();
        char again;
        load1();
        show_tut();
        get_info();
        while(1)
        {
            Select_char();
            char winner = ' ';
            resetBoard();
            printf("\n");
            while(winner == ' ' && checkFreeCell() != 0)
            {
                playerMove();
                if(player_count != 1) printBoard();
                winner = checkWinner();
                if (winner != ' ' || checkFreeCell() == 0)
                {
                    break;
                }

                if(player_count == 1)
                {
                    computerMove();
                    printBoard();
                    winner = checkWinner();
                    if (winner != ' ' || checkFreeCell() == 0)
                    {
                        break;
                    }
                }
                else
                {
                    playerMove2();
                    printBoard();
                    winner = checkWinner();
                    if (winner != ' ' || checkFreeCell() == 0)
                    {
                        break;
                    }
                }
            }
            printf("\nFinal Board: \n");
            printBoard();
            printWinner(winner);
            printf("\n");
            printf("Do you want to play again?(Y/N): ");
            getchar();
            scanf("%c",&again);
            again = toupper(again);
            if (again != 'Y')
            {
                break;
            }
        }

        system("cls");
        thank();
        main();
        break;

    case 'Q':
    exit(0);
    break;
    }
}




void setTextColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
    COORD crd;
    crd.X = x;
    crd.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
}

void introduction()
{
    printf("WELCOME TO OUR ");
    setTextColor(2);
    printf("MINI HORSE GAME!!\n");
    setTextColor(7);
    printf("(press any key to continue)\n");
    getch();
    system("cls");
    printf("Your horse is proceeding towards the ");
    setTextColor(2);
    printf("adventure of nowhere.");
    setTextColor(7);
    printf("But in her path, she is going to face some ");
    setTextColor(4);
    printf("obstacles!\n\n");
    setTextColor(7);
    printf("->Your job is to make your horse jump to save her from the ");
    setTextColor(4);
    printf("incoming obstacles.\n\n");
    setTextColor(7);
    printf("->You can make your horse jump by pressing the ");
    setTextColor(2);
    printf("space key");
    setTextColor(7);
    printf(". Moreover, you can ");
    setTextColor(2);
    printf("pause ");
    setTextColor(7);
    printf("the game in the middle by pressing the  ");
    setTextColor(2);
    printf("p key ");
    setTextColor(7);
    printf(". To ");
    setTextColor(4);
    printf("quit");
    setTextColor(7);
    printf(" the game ,you can press ");
    setTextColor(4);
    printf("x\n\n");
    setTextColor(2);
    printf("\n\nPress any key...");
    setTextColor(7);
    getch();
}

void loading()
{
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++);
        printf("%c",177);
    }
    gotoxy(30,16);
    printf("Press any key to start the game now...");
    getch();
    system("cls");
}

void delayy(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void getup()
{
    gotoxy(0,0);
    printf("Press X to Exit\n");
    gotoxy(0,1);
    printf("Press Space to Jump");
    gotoxy(74,2);
    setTextColor(4);
    printf("Obstacles overcomed: %d",scr);
    setTextColor(2);
    gotoxy(102,2);
    printf("Life remaining: %d",life1);
    setTextColor(7);

    gotoxy(1,25);
    setTextColor(6);
    for(int x=0; x<100; x++)
        printf("####");
    setTextColor(7);
}

void ds(int jump)
{
    static int a=1;
    //int jump=0;

    if(jump==0)
        t=0;
    else if(jump==2)
        t-=0.5;
    else t+=0.5;

    getup();
    setTextColor(4);
    gotoxy(22,14-t);
    printf("                     ");
    gotoxy(36,15-t);
    printf("  *** ");
    gotoxy(34,16-t);
    printf("   ***** ");
    gotoxy(36,17-t);
    printf("******");
    gotoxy(26,18-t);
    printf("         *****  ");
    gotoxy(22,19-t);
    printf("    **************");
    gotoxy(22,20-t);
    printf("   ***************");
    gotoxy(22,21-t);
    printf("   ***************");
    gotoxy(22,22-t);
    if(jump==1 || jump==2)
    {
        printf("    **          **");
        gotoxy(22,23-t);
        printf("    **          **");
        gotoxy(22,24-t);
        printf("    **          **");
    }
    else if(a==1)
    {
        printf("   **             **");
        gotoxy(22,23-t);
        printf("  **               **");
        gotoxy(22,24-t);
        printf(" **                 **");
        a=2;
    }
    else if(a==2)
    {
        printf("     **         **");
        gotoxy(22,23-t);
        printf("      **       **");
        gotoxy(22,24-t);
        printf("       **     **");
        a=1;
    }
    setTextColor(7);
    gotoxy(22,25-t);
    if(jump!=0)
    {
        printf("                      ");
    }

    delayy(speed);
}

void Playagain()
{
    char press;
    //system("cls");
    printf("Do you want to start your adventure again??\n");
    setTextColor(4);
    printf("Press x to quit\n");
    setTextColor(2);
    printf("Press any other key to start again!..");
    setTextColor(7);
    press=getch();
    if(press=='x') main();
    else
    {
        speed=25;
        scr=0;
        life1=3;
        system("cls");
    }
}

void rec()
{
    char pname[20],npname[20],character,character1;
    int ii,jj,pxx=scr;
    FILE *information;
    information=fopen("rec.txt","a+");
    system("cls");
    setTextColor(2);
    printf("Enter your Name please:\n");
    setTextColor(7);
    scanf("%[^\n]",pname);
    for(jj=0; pname[jj]!='\0'; jj++)
    {
        npname[0]=toupper(pname[0]);
        if(pname[jj-1]==' ')
        {
            npname[jj]=toupper(pname[jj]);
            npname[jj-1]=pname[jj-1];
        }
        else npname[jj]=pname[jj];
    }
    npname[jj]='\0';
    fprintf(information,"Player Name :%s\n",npname);
    time_t mytim;
    mytim = time(NULL);
    fprintf(information,"Played Date:%s",ctime(&mytim));
    fprintf(information, "Score:%d\n", pxx);
    for(int i=0; i<=50; i++)
        fprintf(information,"%c",'_');
    fprintf(information,"\n");
    fclose(information);
    printf("Wanna see past records press 'y'\n");
    printf("Else ,press any other key\n");
    character=getch();
    system("cls");
    if(character=='y')
    {
        setTextColor(4);
        information=fopen("rec.txt","r");
        do
        {
            putchar(character1=getc(information));
        }
        while(character1!=EOF);
        setTextColor(7);
        Playagain();
    }
    else Playagain();
    fclose(information);
    system("cls");
}


void gameover()
{
    system("cls");
    setTextColor(4);
    printf("Oh Noo!! All your lives are over.");
    setTextColor(7);
    printf("You have successfully crossed ");
    setTextColor(2);
    printf("%d OBSTACLES!\n",scr);
    setTextColor(7);
    printf("\nNo worries, we will continue the adventure again!\npress any key to quit the game...\n");
    getch();
    system("cls");
    rec();
    system("cls");

}
void ext()
{
    system("cls");
    setTextColor(4);
    printf("You have stopped the journey midway.");
    setTextColor(7);
    printf("You have successfully crossed ");
    setTextColor(2);
    printf("%d OBSTACLES!\n",scr);
    setTextColor(7);
    printf("We will start again some other time!\n");
    printf("Press any key to proceed...");
    getch();
    system("cls");
    rec();
    system("cls");
}

void lifedecrease()
{
    life1--;
    if(life1<0)
    {
        gameover();
    }
    gotoxy(118,2);
    //printf("%d",life);
    char cc;
    //speed=40;
    gotoxy(16,8);
    setTextColor(4);
    if(life1<3)
    {
        printf("\a");
        printf("Your Horse got hurt! ");
        setTextColor(7);
        printf("Do you want to continue?");
        gotoxy(16,9);
        printf("Press any key to continue");
        cc=getch();

        if(cc=='x') ext();
        gotoxy(16,8);
        printf("                                             ");
        gotoxy(16,9);
        printf("                         ");
    }
}

int obj()
{
    static int x=0;
    if(x==62 && t<4)
    {
        lifedecrease();
    }
    else if(x==62 && t>=4)
    {
        scr++;
    }
    setTextColor(2);
    gotoxy(100-x,20);
    printf("   ^   ");
    gotoxy(100-x,21);
    printf("  ^^^ ");
    gotoxy(100-x,22);
    printf(" ^^^^^ ");
    gotoxy(100-x,23);
    printf(" ^^^^^ ");
    gotoxy(100-x,24);
    printf("^^^^^^^ " );
    setTextColor(7);
    x++;
    if(x==79)
    {
        speed-=2;
    }
    if(x==100)
    {
        x=0;
        for(int i=0; i<5; i++)
        {
            gotoxy(0,24-i);
            printf("        ");
        }
    }
    return 1;
}

void pause()
{
    gotoxy(16,8);
    printf("The game is paused. Press any key to continue");
    getch();
    gotoxy(16,8);
    printf("                                             ");
}



void Move()
{
    int a,i;

    do
    {

        Food();
        fflush(stdin);

        len=0;

        for(i=0; i<30; i++)

        {

            body[i].x=0;

            body[i].y=0;

            if(i==length)

                break;

        }

        Delay(length);

        Boarder();

        if(head.direction==RIGHT)

            Right();

        else if(head.direction==LEFT)

            Left();

        else if(head.direction==DOWN)

            Down();

        else if(head.direction==UP)

            Up();

        ExitGame();

    }
    while(!kbhit());

    a=getch();


    if(a==27)

    {

        system("cls");
        setTextColor(4);
        printf("You have quit the game.\n");
        setTextColor(7);
        printf("You've made a score of");
        setTextColor(2);
        printf(" %d!!\n",score);
        setTextColor(7);
        printf("press any key to continue!");
        record();

    }
    key=getch();

    if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN))

    {

        bend_no++;

        bend[bend_no]=head;

        head.direction=key;

        if(key==UP)

            head.y--;

        if(key==DOWN)

            head.y++;

        if(key==RIGHT)

            head.x++;

        if(key==LEFT)

            head.x--;

        Move();

    }

    else if(key==27)

    {
        char playagain;
        system("cls");
        setTextColor(4);
        printf("You have quit the game.\n");
        setTextColor(7);
        printf("You've made a score of");
        setTextColor(2);
        printf(" %d!!\n",score);
        setTextColor(7);
        printf("press any key to continue!");
        record();
    }

    else

    {
        printf("\a");
        Move();

    }
}

void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
}
void load()
{
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); //to display the character slowly
        printf("%c",177);
    }
    getch();
}
void Down()
{
    int i;
    for(i=0; i<=(head.y-bend[bend_no].y)&&len<length; i++)
    {
        GotoXY(head.x,head.y-i);
        {
            setTextColor(6);
            if(len==0)
                printf("v");
            else
                printf("*");
        }
        setTextColor(7);
        body[len].x=head.x;
        body[len].y=head.y-i;
        len++;
    }
    Bend();
    if(!kbhit())
        head.y++;
}
void Delay(long double k)
{
    Score();
    long double i;
    for(i=0; i<=(10000000); i++);
}
void ExitGame()
{
    int i,check=0;
    for(i=4; i<length; i++) //starts with 4 because it needs minimum 4 element to touch its own body
    {
        if(head.x==body[i].x&&head.y==body[i].y)
        {
            check++;
            break;   //check's value increases as the coordinates of head is equal to any other body coordinate
        }
        //if(i==length||check!=0)
        //break;
    }
    if(head.x<=10||head.x>=70||head.y<=10||head.y>=30||check!=0)
    {
        life--;
        if(life>=0)
        {
            head.x=25;
            head.y=20;
            bend_no=0;
            head.direction=RIGHT;
            Move();
        }
        else
        {
            system("cls");
            setTextColor(4);
            printf("All lives completed!!\n");
            setTextColor(7);
            printf("You've made a score of");
            setTextColor(2);
            printf(" %d!!\n",score);
            setTextColor(7);
            printf("press any key to continue!");
            record();
            //exit(0);
        }
    }
}
void Food()
{
    if(head.x==food.x&&head.y==food.y)
    {
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)

            food.y+=11;
    }
    else if(food.x==0)/*to create food for the first time coz global variable are initialized with 0*/
    {
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11;
    }
}
void Left()
{
    int i;
    for(i=0; i<=(bend[bend_no].x-head.x)&&len<length; i++)
    {
        GotoXY((head.x+i),head.y);
        {
            setTextColor(6);
            if(len==0)
                printf("<");
            else
                printf("*");
        }
        body[len].x=head.x+i;
        body[len].y=head.y;
        len++;
    }
    Bend();
    if(!kbhit())
        head.x--;

}
void Right()
{
    int i;
    for(i=0; i<=(head.x-bend[bend_no].x)&&len<length; i++)
    {
        //GotoXY((head.x-i),head.y);
        body[len].x=head.x-i;
        body[len].y=head.y;
        GotoXY(body[len].x,body[len].y);
        {
            setTextColor(6);
            if(len==0)
                printf(">");
            else
                printf("*");
        }
        /*body[len].x=head.x-i;
        body[len].y=head.y;*/
        len++;
    }
    Bend();
    if(!kbhit())
        head.x++;
}
void Bend()
{
    setTextColor(6);
    int diff;
    for(int i=bend_no; i>=0&&len<length; i--)
    {
        if(bend[i].x==bend[i-1].x)
        {
            diff=bend[i].y-bend[i-1].y;
            if(diff<0)
                for(int j=1; j<=(-diff); j++)
                {
                    body[len].x=bend[i].x;
                    body[len].y=bend[i].y+j;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
            else if(diff>0)
                for(int j=1; j<=diff; j++)
                {
                    /*GotoXY(bend[i].x,(bend[i].y-j));
                    printf("*");*/
                    body[len].x=bend[i].x;
                    body[len].y=bend[i].y-j;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
        }
        else if(bend[i].y==bend[i-1].y)
        {
            diff=bend[i].x-bend[i-1].x;
            if(diff<0)
                for(int j=1; j<=(-diff)&&len<length; j++)
                {
                    /*GotoXY((bend[i].x+j),bend[i].y);
                    printf("*");*/
                    body[len].x=bend[i].x+j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
            else if(diff>0)
                for(int j=1; j<=diff&&len<length; j++)
                {
                    /*GotoXY((bend[i].x-j),bend[i].y);
                    printf("*");*/
                    body[len].x=bend[i].x-j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
        }
    }
}
void Boarder()
{
    system("cls");
    int i;
    GotoXY(food.x,food.y);
    setTextColor(2);  /*displaying food*/
    printf("O");
    setTextColor(1);
    for(i=10; i<71; i++)
    {
        GotoXY(i,10);
        printf("!");
        GotoXY(i,30);
        printf("!");
    }
    for(i=10; i<31; i++)
    {
        GotoXY(10,i);
        printf("!");
        GotoXY(70,i);
        printf("!");
    }
    setTextColor(7);
}
void Print()
{
    //GotoXY(10,12);
    printf("Welcome to the ");
    setTextColor(2);
    printf("MINI SNAKE GAME.");
    setTextColor(7);
    printf("(press any key to continue)\n");
    getch();
    system("cls");
    printf("Game instructions:\n->Use");
    printf("->arrow keys ");
    printf("to move the snake.\n\n->You will be provided ");
    setTextColor(2);
    printf("foods ");
    setTextColor(7);
    printf("at several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> Here you are provided with");
    setTextColor(2);
    printf(" three lives");
    setTextColor(7);
    printf(".Your lives will ");
    setTextColor(4);
    printf("decrease ");
    setTextColor(7);
    printf(" as you hit the wall or snake's body.\n\n-> You can pause the game in its middle by pressing any key. To continue the paused game press any other key once again\n\n-> If you want to exit press esc. \n");
    printf("\n\nPress any key to play game...");
    if(getch()==27)
        exit(0);
}

void playagain()
{
    //system("cls");
    char press;
    setTextColor(7);
    printf("Do you want to start your game again??\n");
    setTextColor(4);
    printf("Press esc to quit\n");
    setTextColor(2);
    printf("Press any other key to start again!..");
    setTextColor(7);
    press=getch();
    if(press==27) /*exit(0)*/main();
    else
    {
        system("cls");

        life=3;

        length=5;

        head.x=25;

        head.y=20;

        head.direction=RIGHT;

        Food();

        life=3;

        bend[0]=head;

        Move();
    }
}

void record()
{
    char plname[20],nplname[20],cha,c;
    int i,j,px;
    FILE *info;
    info=fopen("record.txt","a+");
    getch();
    setTextColor(2);
    system("cls");
    printf("Enter your name\n");
    setTextColor(7);
    scanf("%[^\n]",plname);
    //************************
    for(j=0; plname[j]!='\0'; j++)
    {
        nplname[0]=toupper(plname[0]);
        if(plname[j-1]==' ')
        {
            nplname[j]=toupper(plname[j]);
            nplname[j-1]=plname[j-1];
        }
        else nplname[j]=plname[j];
    }
    nplname[j]='\0';
    //*****************************
    //sdfprintf(info,"\t\t\tPlayers List\n");
    fprintf(info,"Player Name :%s\n",nplname);
    //for date and time

    time_t mytime;
    mytime = time(NULL);
    fprintf(info,"Played Date:%s",ctime(&mytime));
    //**************************
    fprintf(info,"Score:%d\n",px=Scoreonly());//call score to display score
    fprintf(info,"\nLevel:%d\n",10);//call level to display level
    for(i=0; i<=50; i++)
        fprintf(info,"%c",'_');
    fprintf(info,"\n");
    fclose(info);
    printf("Wanna see past records press 'y'\n");
    printf("else, press any other key!");
    cha=getch();
    system("cls");
    if(cha=='y')
    {
        setTextColor(4);
        info=fopen("record.txt","r");
        do
        {
            putchar(c=getc(info));
        }
        while(c!=EOF);
        playagain();
    }
    else playagain();
    fclose(info);
}
int Score()
{
    GotoXY(20,8);
    score=length-5;
    setTextColor(2);
    printf("SCORE : %d",(length-5));
    score=length-5;
    GotoXY(50,8);
    setTextColor(4);
    printf("Life : %d",life);
    setTextColor(7);
    return score;
}
int Scoreonly()
{
    int score=Score();
    system("cls");
    return score;
}
void Up()
{
    int i;
    for(i=0; i<=(bend[bend_no].y-head.y)&&len<length; i++)
    {
        GotoXY(head.x,head.y+i);
        {
            setTextColor(6);
            if(len==0)
                printf("^");
            else
                printf("*");
            setTextColor(7);
        }
        body[len].x=head.x;
        body[len].y=head.y+i;
        len++;
    }
    Bend();
    if(!kbhit())
        head.y--;
}


void recc(char string[])
{
    char cha, c;
    int i, j, px;
    FILE *info;
    info = fopen("recc.txt", "a+");

    fprintf(info, "Player 1 Name :%s\n", p1.name);
    fprintf(info, "Player 2 Name :%s\n", p2.name);

    time_t mytime;
    mytime = time(NULL);
    fprintf(info, "Played Date:%s", ctime(&mytime));

    if (strcmp(string, "a") == 0)
        fprintf(info, "The game was a tie.\n");
    else
        fprintf(info, "Winner of the game was %s\n", string);

    for (i = 0; i <= 50; i++)
        fprintf(info, "%c", '_');

    fprintf(info, "\n");
    fclose(info);

    printf("Wanna see past records press 'y'\n");
    printf("else, press any other key!\n");
    //getch();
    //system("cls");

    if (getch() == 'y')
    {
        //setTextColor(4);jn
        info = fopen("recc.txt", "r");
        setTextColor(4);
        do
        {
            putchar(c = getc(info));
        }
        while (c != EOF);
        setTextColor(7);
        // playagain();
    }
    // else playagain();
    fclose(info);
}

void get_info()
{
    printf("->Select the game mode.\n");
    printf("->Enter 1 for single mode or 2 for dual mode.\n");
    printf("->For single mode computer will be the other player.\n");
    printf("->Enter number: ");
    while(1)
    {
        scanf("%d",&player_count);
        if (player_count>2 || player_count<1)
        {
            printf("Enter a valid number!  Enter number: ");
        }
        else break;
    }
    if(player_count == 1)
    {
        printf("Enter Your name: ");
        getchar();
        gets(p1.name);
        strcpy(p2.name,"Computer");
    }
    else
    {
        printf("Enter First players name: ");
        getchar();
        gets(p1.name);
        printf("Enter Second players name: ");
        //getchar();
        gets(p2.name);
    }
}

void thank()
{
    printf("*************************************\n");
    printf("*     THANK YOU FOR PLAYING         *\n");
    printf("*                                   *\n");
    printf("*       SEE YOU NEXT TIME           *\n");
    printf("*************************************\n");
}
void load1()
{
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); //to display the character slowly
        printf("%c",177);
    }
    gotoxy(30,16);
    printf("Press any key to start the game now...");
    getch();
    system("cls");

}

void Select_char()
{
    char in;
    while(1)
    {
        if(player_count == 1)
        {
            printf("Which character you want to select(x or o): ");
            scanf(" %c",&in);
            PLAYER = toupper(in);
            if (PLAYER == 'X') COMPUTER = 'O';
            else if (PLAYER == 'O') COMPUTER = 'X';
            else printf("Please enter a valid character!\n");
            if (PLAYER == 'X' || PLAYER == 'O') break;
        }
        else
        {
            printf("Which character %s wants to select(x or o): ",p1.name);
            scanf(" %c",&in);
            PLAYER = toupper(in);
            if (PLAYER == 'X') COMPUTER = 'O';
            else if (PLAYER == 'O') COMPUTER = 'X';
            else printf("Please enter a valid character!\n");
            if (PLAYER == 'X' || PLAYER == 'O') break;
        }
    }
    if(player_count == 1) printf("You have selected %c",PLAYER);
    else
    {
        printf("%s has selected %c  ",p1.name,PLAYER);
        printf("%s has selected %c\n",p2.name,COMPUTER);
    }
}
void show_tut()
{
    printf("\t\t\t 1 | 2 | 3\n");
    printf("\t\t\t---|---|---\n");
    printf("\t\t\t 4 | 5 | 6\n");
    printf("\t\t\t---|---|---\n");
    printf("\t\t\t 7 | 8 | 9\n");
}
void resetBoard()
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            board[i][j] = ' ';
        }
    }

}

void printBoard()
{
    printf("\t\t\t %c | %c | %c\n",board[0][0],board[0][1],board[0][2]);
    printf("\t\t\t---|---|---\n");
    printf("\t\t\t %c | %c | %c\n",board[1][0],board[1][1],board[1][2]);
    printf("\t\t\t---|---|---\n");
    printf("\t\t\t %c | %c | %c\n",board[2][0],board[2][1],board[2][2]);
}

void printTutorial()
{
    printf("\t\t\t**************************************\n");
    printf("\t\t\t*     WELCOME TO TIC TAC TOE GAME    *\n");
    printf("\t\t\t*                                    *\n");
    printf("\t\t\t*            ENJOY GAMING            *\n");
    printf("\t\t\t**************************************\n");
    printf("\t\t\t             Press any key to continue\n");
    getch();
    system("cls");
    printf("\t\tThe board is played as the following figure\n\n");
    printf("\t\t\t 1 | 2 | 3\n");
    printf("\t\t\t---|---|---\n");
    printf("\t\t\t 4 | 5 | 6\n");
    printf("\t\t\t---|---|---\n");
    printf("\t\t\t 7 | 8 | 9\n");
    printf("->The game is played on a grid that's 3 squares by 3 squares.\n");
    printf("->You can chose symbol as you want , your friend (or the computer) will be the other one.\n");
    printf("->Players take turns putting their marks in empty squares as per number shown above\n");
    printf("->The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n");
    printf("press any key to continue\n");
    getch();
    system("cls");
}

int checkFreeCell()
{
    int freecell = 9;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (board[i][j] != ' ')
            {
                freecell --;
            }
        }
    }
    return freecell;
}

void playerMove()
{
    int x,y,a;
    do
    {
        if(player_count != 1) printf("It is %s s turn\n",p1.name);
        printf("Enter a number between 1 to 9: ");
        scanf("%d",&a);
        x = (a-1)/3;
        y = (a-1)%3;
        if ((a<1 || a>9) || board[x][y] != ' ')
        {
            setTextColor(4);
            printf("Invalid Move\n");
            setTextColor(7);
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    }
    while(board[x][y] != ' ');

}
void playerMove2()
{
    int x,y,a;
    do
    {
        printf("It is %s s turn\n",p2.name);
        printf("Enter a number between 1 to 9: ");
        scanf("%d",&a);
        x = (a-1)/3;
        y = (a-1)%3;
        if ((a<1 || a>9) || board[x][y] != ' ')
        {
            setTextColor(4);
            printf("Invalid Move\n");
            setTextColor(7);
        }
        else
        {
            board[x][y] = COMPUTER;
            break;
        }
    }
    while(board[x][y] != ' ');

}

int checkWin(char player)
{

    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||(board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return 1; // Win
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||(board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return 1; // Win
    }

    return 0; // No win
}

int minimax(int depth, int isMax)
{
    // Evaluate the board
    int score = checkWin(COMPUTER) - checkWin(PLAYER);

    // If the game is over, return the score
    if (score == 1 || score == -1)
    {
        return score;
    }

    // If the board is full, it's a tie
    if (checkFreeCell()==0)
    {
        return 0;
    }

    // Recursive case
    if (isMax)
    {
        int best = -1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] =COMPUTER;
                    best = (best > minimax(depth + 1, !isMax)) ? best : minimax(depth + 1, !isMax);
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
    else
    {
        int best = 1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = PLAYER;
                    best = (best < minimax(depth + 1, !isMax)) ? best : minimax(depth + 1, !isMax);
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

void computerMove()
{
    int bestVal = -1000;
    int bestMoveRow = -1;
    int bestMoveCol = -1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = COMPUTER;
                int moveVal = minimax(0, 0);
                board[i][j] = ' ';

                if (moveVal > bestVal)
                {
                    bestMoveRow = i;
                    bestMoveCol = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    board[bestMoveRow][bestMoveCol] = COMPUTER;

}

char checkWinner()
{

    for (int i=0; i<3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }


    for (int i=0; i<3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[i][0];
        }
    }

    // checking diagonally
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';
}

void printWinner(char gamewinner)
{
    if (gamewinner == PLAYER)
    {
        setTextColor(2);
        if(player_count == 1) printf("You Win\n");
        else printf("%s has won the game\n",p1.name);
        setTextColor(7);
        recc(p1.name);
    }
    else if (gamewinner == COMPUTER)
    {
        setTextColor(2);
        if(player_count == 1) printf("Computer has won the game\n");
        else printf("%s has won the game\n",p2.name);
        setTextColor(7);
        recc(p2.name);
    }
    else
    {
        printf("Its a tie\n");
        recc("a");
    }
}

