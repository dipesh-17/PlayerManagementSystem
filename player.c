#include"player.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void addPlayer(Player* p,int *count){
		printf("\nEnter Details for Player %d\n", *count + 1);
		printf("Enter player jersey number: ");
		scanf("%d",&p[*count].jerseyNumber);
		getchar(); 
		printf("Enter Name: ");
		scanf("%[^\n]s",p[*count].playerName);
		//fgets(p[*count].playerName,sizeof(p[*count].playerName),stdin);
		//gets(p[*count].playerName);
		fflush(stdin);
		printf("Enter player runs: ");
		scanf("%d",&p[*count].runs);
		printf("Enter player wickets: ");
		scanf("%d",&p[*count].wickets);
		printf("Enter Number of matches played: ");
		scanf("%d",&p[*count].matchesPlayed);
		printf("\n-----------Player %d details stored successfully------------\n",*count+1);
}
void displayAllPlayer(Player* p,int * count){
	if(count==0){
		printf("\nNo players details in the database.\n");
	}
	printf("\n--------------All Players Details Are------------\n");
	for(int i = 0;i<*count;i++)
	{
		printf("\nJersey Number : %d",p[i].jerseyNumber);
		printf("\nPlayer Name : %s",p[i].playerName);
		printf("\nRuns : %d",p[i].runs);
		printf("\nWickets : %d",p[i].wickets);
		printf("\nNumber of Matches Played : %d\n",p[i].matchesPlayed);
	}
}
void displaySpecificPlayer(Player* p,int i){
    printf("\n----Player details as follow----\n");   
	printf("\nJersey Number : %d",p[i].jerseyNumber);
    printf("\nPlayer Name : %s",p[i].playerName);
    printf("\nRuns : %d",p[i].runs);
	printf("\nWickets : %d",p[i].wickets);
	printf("\nNumber of Matches Played : %d\n",p[i].matchesPlayed);	
	printf("--------------------------------\n");
}
int searchPlayerById(Player* p,int* count){
	int jerseyNo,found = 0;
	printf("\nEnter Player Jersey Number: ");
    scanf("%d",&jerseyNo);
	for(int i = 0;i<*count;i++){
		if(jerseyNo==p[i].jerseyNumber)
		{
			printf("\nPlayer details found.\n");
			found = 1;
			return i;
		}
		}
		if(!found)
		printf("\nPlayer details not found....\n");
		return -1;
}
void searchPlayerByName(Player* p,int* count){
	int found = 0;
	char str[30];
	getchar();
	printf("\nEnter Player Name: ");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';//Remove newline character
	for(int i = 0;i<*count;i++)
	{
		if(strstr(p[i].playerName,str)!=NULL)
		{
			printf("\nPlayer detail found: %s.\n",p[i].playerName);
			displaySpecificPlayer(p,i);
			found = 1;	
		}
	}
	if(!found)
	printf("\nPlayer details not found....\n");
}
void removePlayer(Player* p,int* count){
		int i,jerseyNo;
		i = searchPlayerById(p,count);   
		jerseyNo = p[i].jerseyNumber; 
		if(i!=-1){
			for(int j = i;j<*count-1;j++){
			p[j]=p[j+1];
		    }
		    (*count)--;
		    printf("\nPlayer with Jersey Number %d has been removed successfully.\n",jerseyNo);
		}
		else
		printf("\nPlayer with Jersey Number %d not found.\n",jerseyNo);
}
void updatePlayerData(Player* p,int* count){
	int i;
	i = searchPlayerById(p,count);  
	if(i!=-1){//Check if the player found or not
	int choice,newValue;
	    while(1){
		    printf("\n----Update Player Data for %s----\n",p[i].playerName);
		    printf("1. Update Runs (Current :%d)\n",p[i].runs);
		    printf("2. Update Wickets (Current :%d)\n",p[i].wickets);
		    printf("3. Update Matches Played (Current :%d)\n",p[i].matchesPlayed);
		    printf("4. Back to Main Menu\n");
		    printf("\nEnter you choice: ");
		    scanf("%d",&choice);
		    switch(choice){
		    	case 1://Update Runs
		    		printf("Current Runs: %d\n",p[i].runs);
		    		printf("Enter updated runs count (or 0 to keep current): ");
		    		scanf("%d",&newValue);
		    		if(newValue!=0){
		    			p[i].runs = newValue;
		    			printf("\nRuns updated to %d.\n",p[i].runs);
					}
					else
					printf("\nRuns remains unchanged.\n");
		    		break;
		    	case 2:
		    	    printf("Current Wickets: %d\n",p[i].wickets);
		    	    printf("Enter updated wickets count (or 0 to keep current): ");
		    	    scanf("%d",&newValue);
		    	    if(newValue!=0){
		    	    	p[i].wickets = newValue;
		    	    	printf("\nWickets updated to %d.\n",p[i].wickets);
					}
					else
					printf("\nWickets remain unchanged.\n");
					break;
				case 3:
				    printf("Current Matches Played: %d\n",p[i].matchesPlayed);
				    printf("Enter updated matches played count (or 0 to keep current): ");
				    scanf("%d",&newValue);
				    if(newValue!=0)
				    {
				    	p[i].matchesPlayed = newValue;
				    	printf("\nMatches played updated to %d.\n",p[i].matchesPlayed);
					}
					else
					printf("\nMatches played remain unchanged.\n");
					break;
		    	case 4:
				return;
				default:
				printf("\nInvalid choice.Please try again.\n");	
			}
	    }
    }
	else
	printf("Can't Update player details.\n");    
}
void displayTop3Player(){
	if(playerCount<=3){
		printf("\nThere are less than 3 players in database.\n");
		return;
	}
	Player *sortedPlayers=(Player*)malloc(sizeof(Player)*playerCount);
	if(sortedPlayers==NULL){
		printf("\nMemory allocation failed!\n");
    return;
	}
	//Copying the original data to sortedPlayers
//	for(int i = 0;i<playerCount;i++){
//		sortedPlayers[i] = p[i];
//	}

	memcpy(sortedPlayers,p,sizeof(Player)*playerCount);
	//Ask the user how they want to sort
	int sortChoice;
	printf("\nHow would you like to view the top 3 players?\n");
	printf("1. By Runs\n");
	printf("2. By Wickets\n");
	printf("3. Back to Main Menu\n");
	printf("Enter your choice: ");
	scanf("%d",&sortChoice);
	//Sorting the copied array base on user choice( runs or wickets)
	switch(sortChoice){
		case 1://sort by runs
			for(int i = 0;i<playerCount-1;i++){
				for(int j = 0;j<playerCount-i-1;j++){
					if(sortedPlayers[j].runs < sortedPlayers[j+1].runs){
						Player temp = sortedPlayers[j];//temp = a
						sortedPlayers[j] = sortedPlayers[j+1];//b = a 
						sortedPlayers[j+1] = temp;//b = temp
					}
				}
			}
			printf("\n-------Top 3 Players based on Runs-------\n");
		break;
		case 2://sort by wickets
		    for(int i = 0;i<playerCount-1;i++){
		    	for(int j = 0;j<playerCount-i-1;j++){
		    		if(sortedPlayers[j].wickets < sortedPlayers[j+1].wickets){
		    			Player temp = sortedPlayers[j];
		    			sortedPlayers[j] = sortedPlayers[j+1];
		    			sortedPlayers[j+1] = temp;
					}
				}
			}
			printf("\n--------Top 3 Players based on Wickets--------\n");
		    break;
		case 3:
			free(sortedPlayers);
		return;    
		default:
		printf("Invalid choice,Please try again.\n");
		break;	
	}
	//Displaying top3 players from the sorted array
	for(int i = 0;i<3;i++){
		printf("\nRank %d:\n",i+1);
		displaySpecificPlayer(sortedPlayers,i);
	}
	
	//Free the memory used by the sorted array
	free(sortedPlayers);
}
void displaySortedPlayer(){
	if(playerCount==0){
		printf("\nNo player details available to display.\n");
		return;
	}
	Player * sortedPlayers = (Player*) malloc(sizeof(Player)*playerCount);
	if(sortedPlayers==NULL){
		printf("Memory allocation failed.\n");
		return;
	}
	memcpy(sortedPlayers,p,sizeof(Player)*playerCount);
	int sortChoice,orderChoice;
	printf("\nHow would you like to sort the players?\n");
	printf("1. By Runs\n");
	printf("2. By Wickets\n");
	printf("Enter your choice (1 or 2): ");
	scanf("%d",&sortChoice);
	
	printf("\nChoose the order of sorting:\n");
	printf("1. Maximum First\n");
	printf("2. Minimum First\n");
	printf("Enter your choice(1 or 2): ");
	scanf("%d",&orderChoice);
	
	//sorting logic
	if(sortChoice==1){//sort players by runs maximum or minimum as per the perference
		for(int i=0;i<playerCount - 1;i++){
			for(int j=0;j<playerCount-i-1;j++){
				 if((orderChoice == 1 && sortedPlayers[j].runs < sortedPlayers[j+1].runs)//maximum run first
				 ||
				 (orderChoice == 2 && sortedPlayers[j].runs>sortedPlayers[j+1].runs))//minimum run first
				 {
				 	Player temp = sortedPlayers[j];//temp = a
				 	sortedPlayers[j] = sortedPlayers[j+1];//a = b
				 	sortedPlayers[j+1] = temp;//b=temp
				 }
			}
		}
		printf("\n-------Players sorted by Runs-------\n");
	}
	else if(sortChoice==2){//sort players by wickets maximum or minimum as  the perference 
		for(int i = 0;i<playerCount-1;i++){
			for(int j=0;j<playerCount - i - 1;j++){
				if((orderChoice==1 && sortedPlayers[j].wickets<sortedPlayers[j+1].wickets)//maximum wickets first
				||
				(orderChoice==2 && sortedPlayers[j].wickets>sortedPlayers[j+1].wickets))//minimum wickets first
				{
					Player temp = sortedPlayers[j];
					sortedPlayers[j] = sortedPlayers[j+1];
					sortedPlayers[j+1] = temp; 
				}
			}
		}
		printf("\n-------Players sorted by wickets-------\n");
	}
	else{
		printf("\nInvalid choice!Returning to main menu.\n");
		free(sortedPlayers);
		return;
	}
	for(int i = 0;i<playerCount;i++){
		displaySpecificPlayer(sortedPlayers,i);
	}
	free(sortedPlayers);
}
