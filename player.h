 extern int size,playerCount;/* in the header file tells the compiler that size, 
 playerCount is defined somewhere else. */

typedef struct Player{
	int jerseyNumber;
	char playerName[30];
	int runs;
	int wickets;
	int matchesPlayed;
}Player;

//Global Variables Declerations
Player *p;//Creating array(p) of type Player 
void addPlayer(Player*,int*);
void displayAllPlayer(Player*,int*);
void removePlayer(Player*,int*);
int searchPlayerById(Player*,int*);
void searchPlayerByName(Player*,int*);
void updatePlayerData(Player*,int*);
void displaySortedPlayer();
void displayTop3Player();
void displaySpecificPlayer(Player*,int);
