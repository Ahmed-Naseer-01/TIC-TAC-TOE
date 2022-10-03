#include<iostream>//TIC TAC TOE Game
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
char restore[9]={'1','2','3','4','5','6','7','8','9'};//asscii code start from 49 to 58
char table[9]={'1','2','3','4','5','6','7','8','9'};
int Counter=0;
bool heading=true;
int player_winner=0;
int x=true;
void color()
{ system("cls");
getchar();
	system("color E4");
}
void color_for_menu()
{
	system("cls");
	getchar();
	system("color 78");
}
void color_for_history()
{
	system("cls");
	getchar();
	system("color FD");
}
void Restore()
{
	for(int i=0;i<9;i++)
		table[i]=restore[i];

		player_winner=0;
}
void history(string name1, string name2)
{

	fstream record;

	record.open("History_of_game.txt",ios::in|ios::app);
	if(heading)
	{
		record<<"\n\n\t\t******GAME IS PLAYED BY ********* \n\n\n";
		record<<"NAME of first player \t\t NAME of second player\n\n";
	heading=false;
	}
	record.close();
	if(heading==false)
	{
	record.open("History_of_game.txt",ios::app);
	if(record)
	{
		record<<name1<<"\t\t\t\t"<<name2;
		if(player_winner==1)
		{
			record<<"\n\n\t\t"<<name1<<"  WON GAME \n";
		}
		else if (player_winner==2)
			record<<"\n\t\t"<<name2<<"  won the game\n";
		else if(player_winner==0)
			record<<"\n\t\t  *******TIE**********\n";
	}

}
record.close();
}
void get_history()
{
	color_for_history();
	string line;
	fstream Record;
	Record.open("History_of_game.txt",ios::in);
	if(Record)
	{
		while(getline(Record,line))
		cout<<line<<endl;
	}
	Record.close();
}
void interface()
 {
 int counter=0;
    for(int i=0;i<9;i++)
 	{
 		cout<<"|_  "<<table[i];
 		cout<<" __|";
 		counter++;
 		if(counter==3)
 		{
 		cout<<"\n";
 		counter=0;
	 }
 }
}
void update_table(int index,int trial)
{
	for(int i=0;i<=index;i++)
	{
		if(i==index&&trial==1)
	{
			table[index]='*';
	}
		else if(i==index&&trial==2)
		{
		table[index]='#';
	}
	}
	interface();
}
int winner_check()
{

string 	s1,s2,s3,s4	,s5,s6,s7,s8;
		int a=0,b=1,c=2,d=0,e=0;
		cout<<"\n\t\t\tchecker\t\t";
	for(int i=0;i<3;i++)
{
s1+=table[i];
		s2+=table[3+i];
		s3+=table[6+i];
		s4+=table[a+i];
		s5+=table[b+i];
		s6+=table[c+i];
	s7+=table[e];
		s8+=table[c];
		a+=2;
		b+=2;
		c+=2;
	e+=4;

}

		if(s1=="###"||s2=="###"||s3=="###"||s4=="###"||s5=="###"||s6=="###"||s7=="###"||s8=="###")
		{
			return 2;
		}
			if(s1=="***"||s2=="***"||s3=="***"||s4=="***"||s5=="***"||s6=="***"||s7=="***"||s8=="***")
			{
			  	return 1;
}
else
	return 0;
	}

void start_game()
{
	system("cls");
	system("color 8F");
	if(Counter!=0)
	Restore();
	if(Counter>=0)
	{
	string first_player,second_player,check;
	int playedby;
	cout<<"\nplayer 1 : \n\t\t";
	cout<<"ENTER YOUR NAME \n\t\t";
	cin>>first_player;
		cout<<"\nplayer 2 : \n\t\t";
	cout<<"ENTER YOUR NAME \n\t\t";
	cin>>second_player;
	cout<<"\n\n WHO WANT TO play first \n\n";
	cout<<first_player<<" OR "<<second_player;
	cin>>check;
	if(check==first_player)
		playedby=1;
		else
		playedby=2;

	int player1,player2;
for(int i=1;i<=9;i++)
{
	if(playedby==1)
	{
		if(x==true)
		{
		interface();
	x=false;
	}
		cout<<"\n"<<first_player<<" : \n\t";
		cin>>player1;
			playedby=2;
		if((int)table[player1-1]!=42||(int)table[player1-1]!=35)
{
	update_table(player1-1,1);
}
int y=winner_check();
	if(y==1)
	{
		player_winner=1;
	break;
	}

}

	if(playedby==2)
	{
			if(x==true)
		{
		interface();
	x=false;
	}
			cout<<"\n"<<second_player<<" : \n\t";
		cin>>player2;
			playedby=1;
		if((int)table[player2-1]!=42||(int)table[player2-1]!=35)
		{
	update_table(player2-1,2);
}
int x=winner_check();
	if(x==2)
	{
		player_winner=2;
	break;
	}
}
	}
switch(player_winner)
{
	case 1:
		cout<<"\n\n\t\t*********Player 1 won Congragulation\n\n";
	history(first_player,second_player);
break;
case 2:
cout<<"\n\n\t\t*********Player 2 won Congragulation\n\n";
	history(first_player,second_player);
break;
}
}
}
void instruction()
{
	color();
	cout<<"\n\t\t*****  INSTRUCTION SECTION *******\n\n\n";
	cout<<"\n in this game you get interface like this : \n\n\n";
	int counter=0;
    for(int i=0;i<9;i++)
 	{
 		cout<<"|_  "<<restore[i];
 		cout<<" __|";
 		counter++;
 		if(counter==3)
 		{
 		cout<<"\n";
 		counter=0;
	 }
 }
 cout<<"\n\n\nyou just have to enter number in respective box you want \n\n";
 cout<<"\n Don't enter input in those box, that was already occupied  \n";


}
int main()
{
	int option;
	cout<<"\n\n\t\t\t*******TIC TAC TOE GAME********\n\n"<<endl;
	cout<<"\n\n\t\t\t press ENTER TO START \n\n";
	getchar();
while(1)
{
	color_for_menu();
	cout<<"\n\n\t\t\t1) Instruction\n\t\t\t2)Start \n\t\t\t3)Play_again \n\t\t\t4)History\n\t\t\t5)exit"<<endl;
	cout<<"\n\n\tSelect an option :\n\t\t";
	cin>>option;
	switch(option)
	{
	case 1:
	{
	instruction();
	cout<<"\n\n\t\tpress enter\n";
	getchar();
	break;
}
		case 2:
{
				start_game();
				break;
}
				case 3:
{

						start_game();
				break;
}
				case 4:
{

					get_history();
					cout<<"\n\n\t\tpress enter\n";
					getchar();
break;
}
					case 5:
						exit(5);
}
}
}//date 27-feb-2021
//in 3 days....
//code based on loops string array switch functions
