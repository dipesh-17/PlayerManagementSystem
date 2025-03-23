#include"player.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int size = 5,playerCount = 5;/* int playerCount = 5; in main.c (or player.c) defines size,playerCount 
and allocates storage for it.This is the only place where playerCount should be defined. */
int main()
{
	// Initial memory allocation
	p = (Player*)malloc(sizeof(Player)*size);//We want to store player,so datatype is player
	if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    //Hardcoded player details 
    
    p[0].jerseyNumber = 7;
	strcpy(p[0].playerName ,"Sachin Tendulkar"); 
	p[0].runs = 18426; 
    p[0].wickets = 45; 
    p[0].matchesPlayed = 463;
    
    p[1].jerseyNumber = 18; 
    strcpy(p[1].playerName, "MS Dhoni"); 
    p[1].runs = 10773; 
    p[1].wickets = 0; 
    p[1].matchesPlayed = 350;

    p[2].jerseyNumber = 45; 
    strcpy(p[2].playerName, "Virat Kohli"); 
    p[2].runs = 12169; 
    p[2].wickets = 56; 
    p[2].matchesPlayed = 254;

    p[3].jerseyNumber = 10; 
    strcpy(p[3].playerName, "Ricky Ponting"); 
    p[3].runs = 13704; 
    p[3].wickets = 34; 
    p[3].matchesPlayed = 375;

    p[4].jerseyNumber = 33; 
    strcpy(p[4].playerName, "Jacques Kallis"); 
    p[4].runs = 10234; 
    p[4].wickets = 292; 
    p[4].matchesPlayed = 325;
    int choice;
	char userChoice[10];
//	printf("How many Players you want to store: ");
//	scanf("%d",&size);
printf("\n-------Welcome to the Player Management System-------\n");
	while(1){
		printf("\n-------------Main Menu-------------\n");
		printf("1. Add Player \n");
		//printf("2. Display Specific Player details\n");
		printf("2. Remove Player\n");
		printf("3. Search Player\n");
		printf("4. Update Player details\n");
		printf("5. Display Player in Sorted manner\n");
		printf("6. Display Top 3 Player details\n");
		printf("7. Display All Players\n");
		printf("0. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%s",userChoice);
		
		//Validate the user input for choice 
		int valid = 0;
		for(int i=0;userChoice[i]!='\0';i++){
			if(isdigit(userChoice[i]))// Check  if input contains only the numeric choice
			{   
				valid = 1;
				break;
			}
		}
		if(!valid){
			printf("\nInvalid choice. Please enter a choice in between 1 to 7.\n");
			continue;
		}
		choice = atoi(userChoice);//Convert valid choice to integer
		
		
		switch(choice){
			case 1:
				if(playerCount<size)
				{
					addPlayer(p,&playerCount);
				    playerCount++;
				}
				else
				{
					char ch;
					int extraSpace;
					printf("\nInsufficient Memory!!!\n");
					fflush(stdin);
					printf("Do you want to increase memory?(Y/N) : ");
					scanf("%c",&ch);
					if(ch=='Y'||ch=='y')
					{
						printf("How many extra player detail you want to add: ");
						scanf("%d",&extraSpace);
						size += extraSpace;
						p = realloc(p,sizeof(Player)*size);
						printf("\nMemory space increased successfully!!\n");
						addPlayer(p,&playerCount);
					    playerCount++;
					}	
				}
				break;
			case 2:
				removePlayer(p,&playerCount);
			    break;	
			case 3:{
				int exit = 0;
				while(exit!=1){
					int ch,index;
		                printf("\nHow do you want to search player\n");
		                printf("1. By Jersey Number\n");
		                printf("2. By Player Name\n");
		                printf("0. Back to Main Menu\n");
		                printf("\nEnter your choice: ");
		                scanf("%d",&ch);
		                switch(ch)
		                {
			            case 1:
				            index = searchPlayerById(p,&playerCount);
				            if(index!= -1){
				            displaySpecificPlayer(p,index);
				            }
				            break;
		            	case 2:
		            		searchPlayerByName(p,&playerCount);
				            break;	
			            case 0:
			            	exit = 1;
				            break;
			            default:
			                printf("\nInvalid Input....try again..\n");	    
		                }
	                }
				break;
			}
			case 4:
			    updatePlayerData(p,&playerCount);
				break;	
			case 5:
				displaySortedPlayer();
			    break;
			case 6:
				displayTop3Player();
			    break;
			case 7:
				displayAllPlayer(p,&playerCount);
				break;
			case 0:
			    printf("\nThank You ... Visit again");
				return 0;
			default:
			    printf("\nInvalid Input..Please try again...");		
		}
		//printf("\n----Do you want to continue program?----\nPress 1 to Continue\nPress 0 to exit");		
	}	
}