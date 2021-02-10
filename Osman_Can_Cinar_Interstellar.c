#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
/*
							  O S M A N   C A N   C I N A R   
								 1 7 0 7 0 0 0 6 0 5 6
								 
								 
							 Y A S A R   U N I V E R S I T Y
						  S O F T W A R E   E N G I N E E R I N G
							
							
							I N T E R S T E L L A R   G A M E 
							

			 ! ! ! ! P L E A S E   P L A Y   T H E   G A M E   O N   F U L L   S C R E E N ! ! ! !	
*/

	void signature()
	{
		printf("		THIS GAME IS MADE BY	O S M A N   C A N   C I N A R   \n");
		
	}

	void arrows()
	{
		printf("\n	||			||			||			|| 			|| \n");
		printf("	||			||			||			|| 			|| \n");
		printf("	||			||			||			|| 			|| \n");
		printf("	\\/			\\/			\\/			\\/			\\/  \n\n\n");
	}

	void menu(int fuel, float current_year)
	{
		printf("	 ! ! ! ! P L E A S E   P L A Y   T H I S   G A M E   O N   F U L L   S C R E E N ! ! ! !\n\n\n");
		printf("	 _____   _   _   _______   ______   _____   _____ _______ ______ _      _               _____ 	\n");
		printf("	|_   _| | \\ | | |__   __| |  ____| |  __ \\ / ____|__   __|  ____| |    | |        /\\   |  __ \\ 	\n");
		printf("	  | |   |  \\| |    | |    | |__    |  __) | (___    | |  | |__  | |    | |       /  \\  | |__) |	\n");
		printf("	  | |   | . ` |    | |    |  __|   |  _  / \\___ \\   | |  |  __| | |    | |      / /\\ \\ |  _  / 	\n");
		printf("	 _| |_  | |\\  |    | |    | |____  | | \\ \\ ____) |  | |  | |____| |____| |____ / ____ \\| | \\ \\ 	\n");
		printf("	|_____| |_| \\_|    |_|    |______| |_|  \\_\\_____/   |_|  |______|______|______/_/    \\_\\_|  \\_\\	\n\n\n");
		printf("		- - - -  W e l c o m e   t o   t h e   I n t e r s t e l l a r   G a m e  - - - -	\n\n");
		printf("	In this game you're starting from Planet Earth and travel among other 7 planets to find a habitable planet for humanity.\n");
		printf("	If you find a planet that is habitable and have enough fuel in the tank to go back to earth than you could be the chosen one!!! \n\n");
		printf("	Currently you're at planet Earth and you have %d light years of fuel and year is %0.lf.\n",fuel, current_year);
		printf("	Hope you come back before all your loved ones die. Good luck on your Journey!!! \n\n");
		printf("	The Journey Begins...\n\n");
		printf("						E   A   R   T   H						\n"); 
		printf("					 	  2   0   2   0					\n\n");
		arrows();
	}
	
	void smiley()
	{
		int i,j;
		for (i = 0; i <= 10; i++)
		{
			printf("		");
			for (j = 0; j <= 10; j++)
			{
				if ( (	(i%10 == 0) || 
						(j%10 == 0) || 
						(j % 5 == 2 && (i-4)*(i-3)==0) || 
						(j % 5 == 3 && (i-4)*(i-3)==0) ||
						( i== 6 && j==5) ||
						(i == 7 && (j - 2)*(j - 8) == 0) ||
						(i == 8 && abs(j-5)<3)				) && ( (i%10)+(j%10)!=0) )
						{
							printf(" * ");
						}
				else printf("   ");
			}
			printf("\n");
		}	
		printf("\n\n");
	}
	
	void bad_news(float current_year, int  i, int fuel)
	{
		printf("	You don't have enough fuel!\n");
		printf("	Btw Current Year is : %.0f and you're at Planet%d. \n",current_year,i+2);
		printf("	You have %d light years worth fuel!\n\n",fuel);
		
	}
	
	int good_news(float current_year, int choice)
	{
		printf("	Well Done! You've found a habitable planet.\n\n");
		smiley();
		smiley();
		smiley();
		printf("	Current Year is : %.0f \n\n",current_year);
		printf("	Now you need to decide, Do you want to go back to Earth and save the Humanity or Stay here and Chill.\n");	
		printf("	Press 1 for Stay&Chill, Press 2 for Going Back.\n");
		printf("	User's Choice: ");
		scanf("%d",&choice);
		printf("\n");
		return choice;
	}
	
	int abs(int a)												// Absolute
	{
		if(a < 0)
			return a = -a;
		else
			return a;
	}
	
	int rand_gen()												// Random Generator
	{
		srand(time(NULL));
		return rand();
	}
	
	float calc_travel_time(int travel_time)						// Calculates Travel Time
	{
		int year = travel_time / 365;
		int days = travel_time % 365;
		float years = year + days * 0.0027;
		return years; 
	}
	
	int calc_distance(int travelling_dist[], int destination_p, int current_p, int fuel)  // Calculates Distance
	{
		int distance = abs(travelling_dist[destination_p] - travelling_dist[current_p]);
		
		if( fuel >= distance)
		{
			fuel -= distance;
			current_p = destination_p;
			printf("	 *You've traveled %d light years and it took %d earth days.\n",distance,distance);
			printf("	 *You also have %d light years worth fuel!\n",fuel);
			return fuel;
		}
		else if(fuel < distance)
		 	return 0;
	}
	
	float calc_time(int hours_spent, int earth_equivalent)		// Calculates Time
	{
		int space_time = hours_spent * earth_equivalent; 	// converting space time to earth hours
		int year = (space_time / 8760); 						// 1 year is 8760 hours = 365 x 24
		int months = (space_time % 8760) / 730; 			// 1 month is 730 hours = 30 x 24
		int weeks = (space_time % 730) / 168; 				// 1 week is 168 hours = 7 x 24
		int days =  (space_time % 168) / 24; 				// 1 day is 24 hours = 24 x 1
		int hours = (space_time % 24); 						// rest of hours left
				
		int date[5], i;
		date[0] = year;
		date[1] = months;
		date[2] = weeks;
		date[3] = days;
		date[4] = hours;
		
		for(i = 0; i< 5; i++)
		{
			if( i == 0)
			{	
				printf("\n");
				printf("	%d Years, ",date[i]);
			}
			else if( i == 1)
			{
				printf("  %d Months, ",date[i]);
			}
			else if( i == 2)
			{
				printf("  %d Weeks, ",date[i]);
			}
			else if( i == 3)
			{
				printf("  %d Days, ",date[i]);
			}
			else if( i == 4)
			{
				printf("  %d Hours.\n",date[i]);
			}
		}
		float years = ((year * 1) + ( months * 0.083 ) + ( weeks * 0.019 ) + ( days * 0.0027) + ( hours * 0.0001 ));
		return years;
	}
	
	float planet1(int guess) 									//Guess a Number Game
	{
		float a;
		int guess_found = 0, hour = 0;
		int rand_generated = rand_gen()%10 + 1;
		printf("						P  L  A  N  E  T  1						\n\n\n");
		printf("	Welcome to the Planet1's Guess a Number Game :) \n\n\n");
		printf("	%d\n\n",rand_generated);						//Developer Mode Only!
			
		do{
			
			hour++;
			printf(" 	**** %d. Round **** \n",hour); 
			printf("	Please Guess a number between 1 to 10 !!\n");
			printf("	User's Guess: ");
			scanf("		%d",&guess);
			
			if(1 <= guess  &&  guess <= 10 )
			{
				if(guess == rand_generated)
					guess_found = 1;
				else if(guess < rand_generated)
					printf("	HINT: Your guess is Lower than the Number!\n\n"); 
				else if(guess > rand_generated)
					printf("	HINT: Your guess is Higher than the Number!\n\n");
			}
			else
			{
				printf("	Enter a value betweern 1 and 10!\n\n");
				printf("	The number is reseted!\n\n");
				rand_generated = rand_gen()%10 + 1;
				printf("	%d\n\n",rand_generated);						//Developer Mode Only!
			}
		}while(guess_found == 0);
		
		printf("\n");
		printf("	Congratulations!\n");
		printf("	You Have Won the Planet1's -Guess a Number Game-\n\n");
		printf("	You've spent %d hours at planet1 and it equals this many earth time; \n",hour); 
		a = calc_time(hour,60000);
		printf("\n");
		printf("---------------------------------------------------------------------------------------------------------------------\n\n");
		return a;
	}
	
	float planet2(int guess)									// Evil Guess a Number Game
	{
		float a;
		int guess_found = 0, accuracy = 0, hour = 0;
		int rand_generated = rand_gen()%20 + 1;
		printf("\n\n");
		printf("						P  L  A  N  E  T  2						\n\n\n");
		printf("	Welcome to the Evil Guess a Number Game :) \n");
		printf("	%d\n",rand_generated);						//Developer Mode Only!
		printf("\n");
		
		do
		{
			hour++;
			printf(" 	**** %d. Round **** \n",hour);
			printf("	Please Guess a number between 1 to 20 !!\n");
			printf("	User's Guess: ");
			scanf("%d",&guess);
			accuracy = rand_gen()%2;
			
			if(1 <= guess  &&  guess <= 20)
			{
				if(guess == rand_generated)
					guess_found = 1;
				else 
				{
					if(accuracy== 0)
					{
						if(guess > rand_generated)
							printf("	Your guess is Higher than the Number!\n\n");
						else
							printf("	Your guess is Lower than the Number!\n\n");
					}
					else
					{
						if(guess > rand_generated)
							printf("	Your guess is Lower than the Number!\n\n");
						else
							printf("	Your guess is Higher than the Number!\n\n");	
					}
				}
			}
			else
			{
				printf("	Enter a value betweern 1 and 20!\n\n");
				printf("	The number is reseted!\n\n");
				rand_generated = rand_gen()%20 + 1;
				printf("	%d\n\n",rand_generated);						//Developer Mode Only!
			}
			}while(guess_found == 0);
		
		printf("\n");
		printf("	Congratulations!\n");
		printf("	You Have Won the Planet2's -Evil Guess a Number Game-\n\n");
		printf("	You've spent %d hours at planet2 and it equals this many earth time, \n",hour); 
		a = calc_time(hour,20000);
		printf("\n");
		printf("---------------------------------------------------------------------------------------------------------------------\n\n");
		return a;
	}
	
	float planet3(int guess)									// Cumulative Addition
	{
		float a;
		int guess_found = 0, hour = 0, target = 0;
		int rand_generated = 7 + rand_gen()%16 + 1;
		printf("\n\n");
		printf("						P  L  A  N  E  T  3						\n\n\n");
		printf("	Welcome to the Cummulative Addition Game :) \n\n\n");
		printf("	Computer will guess a number between 7 and 23 and you need to reach to that number by cumulative addition.\n");
		printf("	You Can Only Enter These Values (2,3,5)! Enter a Value: \n\n");
		
		while(guess_found == 0)
		{
			printf("	 **** %d. Try **** \n",hour+1);
			printf("	answer :%d\n",rand_generated);    	//Developer Mode Only
			printf("	User's Guess: ");
			scanf("%d",&guess);
			printf("\n");
			
			if(guess == 2 || guess == 3 || guess == 5)
			{
				target += guess;
				hour++;
				if(target > rand_generated)
				{
					printf("	start over!\n");
					printf("	The number is reseted!\n\n");
					rand_generated = 7 + rand_gen()%16 + 1;
					target = 0;
					continue;
				}
				else if(target == rand_generated)
				{
					printf("	It's found, you reached to %d.\n\n",rand_generated);
					guess_found = 1;
			 }
			}
			else
			{
				printf("	Invalid Choice, Now Target Number is Reseted!!");
				printf("	enter only 2,3 or 5!\n");
				printf("	The number is reseted!\n\n");
				rand_generated = 7 + rand_gen()%16 + 1;
				continue;
			}
		}
		
		printf("	Congratulations!\n");
		printf("	You Have Won the Planet3's -Cummulative Addition Game-\n\n");
		printf("	You've spent %d hours at planet3 and it equals this many earth time, \n",hour); 
		a = calc_time(hour,1200000);
		printf("\n");
		printf("---------------------------------------------------------------------------------------------------------------------\n\n");
		return a;
	}
	
	float planet4() 											// Super Duper Master Dice Roll Championship
	{ 
		float a;
		int roll_pc, roll_user, i;
		int count_user = 0, count_pc = 0, hour = 0;
		printf("\n\n");
		printf("						P  L  A  N  E  T  4						\n\n\n");
		printf("	Welcome to the Super Duper Master Dice Roll Championship :) \n\n");
		
		for(i = 1; i <= 3; i++)
		{
			printf(" 	**** %d. Round **** \n",i);
			roll_user = rand_gen()%6 + 1; 
			roll_pc = rand_gen()%6 + 1;
			
			while(roll_user == roll_pc)
				roll_pc = rand_gen()%6 + 1;
			
			if(roll_user > roll_pc)
			{
				count_user++;
				hour++;
				printf("	User rolled %d, Pc rolled %d and User won the %d. round.\n\n",roll_user,roll_pc,i);
			}
			else if(roll_user < roll_pc)
			{
				count_pc++;
				hour++;
				printf("	User rolled %d, Pc rolled %d and Pc won the %d. round.\n\n",roll_user,roll_pc,i);		
			}
			else
			{
				hour++;
				printf("	User rolled %d, Pc rolled %d and Round is Draw.\n\n",roll_user,roll_pc,i);
				i--;
			}
			
			if(i == 3)
			{
				if(count_user >= 2 && count_pc < count_user )
				{
					break;
				}
				else if(count_user < count_pc && count_pc >= 2 )
				{
			  		i = 0;
			  		count_user = 0;
			  		count_pc = 0;
			  		printf("	Rematch Time for the User!!\n\n");
				}
			}
		}
		
		printf("	Congratulations user have won!!!\n");
		printf("	You Have Won the Planet4's -Super Duper Master Dice Roll Championship-\n\n");
		printf("	You've spent %d hours at planet4 and it equals this many earth time, \n",hour); 
		a = calc_time(hour,35000);
		printf("\n");
		printf("---------------------------------------------------------------------------------------------------------------------\n\n");
		printf("\n");	
		return a;
	}
	
	float planet5(int guess) 									// Rock&Paper&Scissor
	{ 
		float a;
		int guess_pc, i;
		int count_user = 0, count_pc = 0, hour = 0;
		int rock = 1, paper = 2, scissor = 3;
		printf("\n\n");
		printf("						P  L  A  N  E  T  5						\n\n\n");
		printf("	Welcome to the Rock & Paper & Scissor Game:) \n\n");
		
		for(i = 1; i <= 3; i++)
		{
			guess_pc = rand_gen()%3 + 1;
			printf("	-Round %d-\n\n",i);
			printf("	Choose your object.\n");
			printf("	Press 1 to select Rock.\n");
			printf("	Press 2 to select Paper.\n");
			printf("	Press 3 to select Scissor.\n");
			printf("	Pc's choice : %d\n",guess_pc);									// DEVELOPER MODE ONLY
			printf("	User's Choice: ");
			scanf("%d",&guess);
			printf("\n");
			
					
			
			switch(guess)
				{
					case 1: 	printf("	User selected Rock.\n");
								break;
							
					case 2: 	printf("	User selected Paper.\n");
								break;
					
					case 3: 	printf("	User selected Scissor.\n");
								break;
							
					default:	printf("	User made an invalid selection.\n");
								printf("	Choose only 1 or 2 or 3!!\n\n");
								guess_pc = rand_gen()%3 + 1;
								i = 0;
								break;
				}	
			
			
			if(guess == 1 || guess == 2 || guess == 3)
			{
				switch(guess_pc)
				{
					case 1: 	printf("	PC selected Rock.\n");
								break;
							
					case 2: 	printf("	PC selected  Paper.\n");
								break;
								
					case 3: 	printf("	PC selected  Scissor.\n");
								break;
							
					default:
								break;
				}
			} 	
			
			if((guess == 1 && guess_pc == 3) || ((guess == 2 && guess_pc == 1)) || (guess == 3 && guess_pc == 2))
			{
				count_user++;
				hour++;
				printf("	User won the %d. round.\n\n",i);
			}
			else if((guess == 3 && guess_pc == 1) || ((guess == 1 && guess_pc == 2)) || (guess == 2 && guess_pc == 3))
			{
				count_pc++;
				hour++;
				printf("	Pc won the %d. round.\n\n",i);
			}
			else if(guess == guess_pc)
			{
				hour++;
				printf("	Round is Draw!\n\n");		
				i--;	
			}
			
			if(i == 3)
			{
				if(count_user >= 2 && count_pc < count_user )
				{
					break;
				}
				else if(count_user < count_pc && count_pc >= 2 )
				{
			  		i = 0;
			  		count_user = 0;
			  		count_pc = 0;
			  		printf("	Rematch Time for the User!!\n\n");
				}
			}
		}
		
		printf("	Congratulations user have won!!!\n");
		printf("	You Have Won the Planet5's -Rock & Paper & Scissor Game-\n");
		printf("	You've spent %d hours at planet5 and it equals this many earth time, \n\n",hour);
		a = calc_time(hour,100000);
		printf("\n");
		printf("---------------------------------------------------------------------------------------------------------------------\n\n");
		return a;
	}
	
	float planet6(int guess)									// Binary-to-Decimal
	{
		float a;
		int i, j, z;
		int guess_pc, binary_requested, binary_dig_loc; // for decimal 255 binary equivalent is 11111111 max 8 digits required.
		int binary_form[8], guess_found = 0, hour=0; 					
		printf("\n\n");
		printf("						P  L  A  N  E  T  6						\n\n\n");
		printf("	Welcome to the Binary-to-Decimal/Decimal-to-Binary :) \n\n");
		printf("	Convert the number to Binary then answer the question according to your result!\n");
		printf("	Most significant bit to Least significant bit\n\n");
		
		for(i = 1; i <= 3; i++)
		{
			printf("	-Round %d-\n\n",i);
			guess_pc = rand_gen()%255 + 1;	
			printf("	The given number is %d \n",guess_pc); 
			
			if(128 <= guess_pc && guess_pc < 255)
			{
				for(j = 0; guess_pc > 0; j++)    
				{    
					binary_form[j] = guess_pc % 2;    
					guess_pc = guess_pc / 2;    
				}
				binary_dig_loc = rand_gen()%8;
			}
			else if( 64 <= guess_pc && guess_pc < 128)
			{   
					binary_form[7] == 0;        
				
				for(j = 0; guess_pc > 0; j++)    
				{    
					binary_form[j] = guess_pc % 2;    
					guess_pc = guess_pc / 2;    
				}
				binary_dig_loc = rand_gen()%7;
			}
			else if( 32 <= guess_pc && guess_pc < 64)
			{
				for(z = 6; z >= 7; z++)    
					binary_form[z] == 0;        
				
				for(j = 0; guess_pc > 0; j++)    
				{    
					binary_form[j] = guess_pc % 2;    
					guess_pc = guess_pc / 2;    
				}
				binary_dig_loc = rand_gen()%6;
			}
			else if(16 <= guess_pc && guess_pc < 32)	
			{
				for(z = 5; z >= 7; z++)      
					binary_form[z] == 0;        
			
				for(j = 0; guess_pc > 0; j++)    
				{    
					binary_form[j] = guess_pc % 2;    
					guess_pc = guess_pc / 2;    
				}
				binary_dig_loc = rand_gen()%5;
			}
			else if(8 <= guess_pc && guess_pc < 16)
			{
				for(z = 4; z >= 7; z++)    
					binary_form[z] == 0;        
					
				for(j = 0; guess_pc > 0; j++)    
				{    
					binary_form[j] = guess_pc % 2;    
					guess_pc = guess_pc / 2;    
				}
				binary_dig_loc = rand_gen()%4;
			}
			else if(4 <= guess_pc && guess_pc < 8)
			{
				for(z = 3; z >= 7; z++)    
					binary_form[z] == 0;        
				
				for(j = 0; guess_pc > 0; j++)    
				{    
					binary_form[j] = guess_pc % 2;    
					guess_pc = guess_pc / 2;    
				}
				binary_dig_loc = rand_gen()%3;
			}
			else if(2 <= guess_pc && guess_pc < 4)
			{
				for(z = 2; z >= 7; z++)      
					binary_form[z] == 0;        
				
				for(j = 0; guess_pc > 0; j++)    
				{    
					binary_form[j] = guess_pc % 2;    
					guess_pc = guess_pc / 2;    
				}
				binary_dig_loc = rand_gen()%2;
			}
			else if(0 <= guess_pc && guess_pc < 2)
			{
				for(z = 1; z >= 7; z++)     
					binary_form[z] == 0;        
				
				for(j = 0; guess_pc > 0; j++)    
				{    
					binary_form[j] = guess_pc % 2;    
					guess_pc = guess_pc / 2;    
				}
				binary_dig_loc = rand_gen()%1;
			}
			printf("\n	Binary of Given Number is = "); // DEVELOPER MODE ONLY
			   
			for(j = j-1 ; j >= 0 ; j--)    		// to print the binary number if you want to check
				printf("%d",binary_form[j]);    // DEVELOPER MODE ONLY
		
			printf("\n	What is is the digit %d? (question %d/3)\n",binary_dig_loc,i);
			printf("	digit %d is %d \n",binary_dig_loc,binary_form[binary_dig_loc]);	// DEVELOPER MODE ONLY
			printf("	User's Guess: ");
			scanf("%d",&guess);
			printf("\n");
			
			if(binary_form[binary_dig_loc] == guess)
			{
				guess_found++;
				hour++;
				printf("	User got it right %d. round!\n\n",i);
			}
			else
			{
				hour++;
				printf("	User didn't get the correct result!\n\n");
				i = 0;
				guess_found = 0;
			}
			if(i == 3 && guess_found == 3)
				break;
		}
		
		printf("	Congratulations!\n");
		printf("	You Have Won the Planet6's -Binary-to-Decimal/Decimal-to-Binary Game-\n");
		printf("	You've spent %d hours at planet6 and it equals this many earth time, \n\n",hour); 
		a = calc_time(hour,1825); // In the doc. it says that 1 day is equal to 5 years than 1 hour equals to 1825 hours in earth.
		printf("\n");
		printf("---------------------------------------------------------------------------------------------------------------------\n\n");	
		return a;
	}
	
	float planet7(int guess)									// Fast Multiplier
	{
		clock_t start_t, end_t, total_t;
		float a = 0.0;
		int i = 0, num1 = 0, num2 = 0, guess_found = 0, gnrl_time = 0, multiplication = 0;
		
		printf("\n\n");
		printf("						P  L  A  N  E  T  7						\n\n\n");
		printf("	Welcome to the Planet7's Fast Multiplier Game :) \n\n\n");
		
		do
		{
			num1 = 10 + rand_gen()%20 + 1;
			num2 = 10 + rand_gen()%20 + 1;
			
			while(num1 == num2)
				num2 = 10 + rand_gen()%20 + 1;
			
			multiplication = (num1 * num2);
			printf("	%d \n",multiplication);      // DEV MODE ONLY
			printf(" 	**** %d. Round **** \n",i + 1);
			printf("	What is the result of %d x %d =  \n",num1,num2);
			printf("	User's Answer:");
			start_t = clock();
			scanf("%d",&guess);
			printf("\n");	
						
			if(guess == multiplication)
			{
				end_t = clock();
				total_t = (int)(end_t - start_t) / CLOCKS_PER_SEC;
				gnrl_time += total_t;
				gnrl_time = gnrl_time * 0.000277778 * 7500000;
				guess_found = 1;
				i++;
				printf("\n");
				printf("	Congratulations!\n");
				printf("	You Have Won the Planet7's - Fast Multiplier -\n\n");
				a = calc_time(gnrl_time,1); 
				printf("\n");
				printf("---------------------------------------------------------------------------------------------------------------------\n\n");
				return a;
			}
			else if(guess != multiplication)
			{	
				end_t = clock();
				printf("	Wrong answer!\n\n\n");
				total_t = (int)(end_t - start_t) / CLOCKS_PER_SEC;
				gnrl_time += total_t;
				i++;
			}	
		}while(guess_found == 0);
	}
	
	int main()													// Main 
	{
		// 		! ! ! ! P L E A S E   P L A Y   T H E   G A M E   O N   F U L L   S C R E E N ! ! ! ! 		//
		int b, guess, choice, temp, habitable_planet = 6;//rand_gen() % 7;
		int travel_time = 0, i = 0, fuel = 1500, f1 = fuel; 			// In order to run the code accuretly f1 and b must be initally same. 
		int travelling_dist[] = {0, 30, 210, 270, 720, 610, 580,790}, habitable_life[7] = {0};
		float current_year = 2020.00;
		bool planet_found = false;
		habitable_life[habitable_planet] = 1;
		printf("	habitable_planet is : Planet%d \n",habitable_planet + 1);  // DEVELOPER MODE ONLY		
		menu(fuel,current_year);

		while(i < 7)
		{
			if(i < 7 && planet_found == true)
			{
				choice = good_news(current_year, choice);
				
				switch(choice)
				{
					case 1:	printf("	Alright Chill Bill have fun on Planet%d :) \n\n\n\n",i);
							signature();
							break;
					case 2: printf("	Let's see if you have enough Fuel to go back.\n\n");
							temp =calc_distance(travelling_dist,0,habitable_planet,fuel);
							if(temp)
							{
								fuel = temp;
								printf("\n");
								printf("	You've Traveled from Planet%d to Earth!  And the year is %0.f \n",habitable_planet + 1,current_year);
								printf("	You saved the world.\n\n");
								printf("	Y O U  A R E  T H E  C H O S E N  O N E ! \n\n\n\n");
								signature();
								break;    	
							}
							else
							{
								printf("	You don't have enough fuel!\n");
								printf("	Btw Current Year is : %.0f and you're at Planet%d. \n",current_year,i);
								printf("	Now you live at planet%d , Have a good life!\n",i + 1);
								break;
							}		
					default: printf("	Error!");
							break;
				}
		
				return 0;
			}
			else
			{
				if(i == 0 )
				{
					printf("	You've Traveled from Earth to Planet1 \n");
					temp = calc_distance(travelling_dist,1,0,fuel);
					
					if(temp)
						fuel = temp;    	
					else
					{
						bad_news(current_year, i, fuel);
						break;
					}

					b = fuel;			
					travel_time = f1- b;	 														// earth to p1 travel time 
					current_year = current_year + calc_travel_time(travel_time) + planet1(guess);	// time spent at p1 and calc current date				
					
					if(habitable_life[0] == 1)
						planet_found = true;						
				}
				else if(i == 1)
				{
					arrows();
					printf("	You've Traveled from Planet1 to Planet2 \n");
					temp = calc_distance(travelling_dist,2,1,fuel);
					
					if(temp)
						fuel = temp;    	
					else
					{
						bad_news(current_year, i, fuel);
						break;
					}
				
					b = fuel;
					travel_time = f1- b;															// p1 to p2 travel time
					current_year = current_year + calc_travel_time(travel_time) + planet2(guess);	// time spent at p2 and calc current date
					
					if(habitable_life[1] == 1)
						planet_found = true;
				}
				else if(i == 2)
				{	
					arrows();
					printf("	You've Traveled from Planet2 to Planet3 \n");	
					temp = calc_distance(travelling_dist,3,2,fuel);	
												
					if(temp)
						fuel = temp;    	
					else
					{
						bad_news(current_year, i, fuel);
						break;
					}
					
					b = fuel;
					travel_time = f1- b;															// p2 to p3 travel time
					current_year = current_year + calc_travel_time(travel_time) + planet3(guess);	// time spent at p3 and calc current date
					
					if(habitable_life[2] == 1)
						planet_found = true;	
				}
				else if(i == 3)
				{
					arrows();
					printf("	You've Traveled from Planet3 to Planet4 \n");
					temp = calc_distance(travelling_dist,4,3,fuel);
					
					if(temp)
						fuel = temp;    	
					else
					{
						bad_news(current_year, i, fuel);
						break;
					}
					
					b = fuel;
					travel_time = f1- b;															// p3 to p4 travel time
					current_year = current_year + calc_travel_time(travel_time) + planet4(guess);	// time spent at p4 and calc current date
					
					if(habitable_life[3] == 1)
						planet_found = true;
				}
				else if(i == 4)
				{
					arrows();
					printf("	You've Traveled from Planet4 to Planet5 \n");
					temp = calc_distance(travelling_dist,5,4,fuel);
					
					if(temp)
						fuel = temp;    	
					else
					{
						bad_news(current_year, i, fuel);
						break;
					}
					
					b = fuel;
					travel_time = f1- b;															// p3 to p5 travel time
					current_year = current_year + calc_travel_time(travel_time) + planet5(guess);	// time spent at p5 and calc current date
					
					if(habitable_life[4] == 1)
						planet_found = true;	
				}
				else if(i == 5)
				{
					arrows();
					printf("	You've Traveled from Planet5 to Planet6 \n");
					temp = calc_distance(travelling_dist,6,5,fuel);
						
					if(temp)
						fuel = temp;    	
					else
					{
						bad_news(current_year, i, fuel);
						break;
					}
				
					b = fuel; 
					travel_time = f1- b;															// p5 to p6 travel time
					current_year = current_year + calc_travel_time(travel_time) + planet6(guess);	// time spent at p6 and calc current date
					
					if(habitable_life[5] == 1)
						planet_found = true;
				}
				else if(i == 6)
				{
					arrows();
					printf("	You've Traveled from Planet6 to Planet7 \n");
					temp = calc_distance(travelling_dist,7,6,fuel);
						
					if(temp)
						fuel = temp;    	
					else
					{
						bad_news(current_year, i, fuel);
						break;
					}
				
					b = fuel; 
					travel_time = f1- b;															// p6 to p7 travel time
					current_year = current_year + calc_travel_time(travel_time) + planet7(guess);	// time spent at p7 and calc current date
					
					if(habitable_life[6] == 1)
						planet_found = true;
						
					i--; // this line makes sure that if the habitable planet is 7 then i must stay in the loop.
				}
			}
			i++;
		}
		return 0;
	}
