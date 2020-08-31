/*
Author:Manali Redkar
Date:02/18/2020
Description:This assignment has two major parts: Part 1 – A mini-games collection, Part 2 –
Macros vs. Functions.The opponent in the game is basically handled by the random generator.
*/


//list of # include-libraries that are used in the program.PS: few might just be unused
#include <math.h>
#include <stdio.h>   
#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//this is my file variable
FILE * file;

//PART 0
//These variables are for part 0, where the text files are accessed 
int lines; //no. of lines in the text files = no. of names
string opp_num;//the serial number against each name in the givex text file
char ch; //choices
string eachName; 
int any_numb; //randome number in the random_names.txt
string opp_name;

ifstream text("random_names.txt");
int odd;
int any_game; //game that the randomized fuction will generate

//scores
int player_score=0;
int opponent_score=0;

int o=1;//game number, which is not in order of the defined games




//CASE 1
//for game1:Evens or Odds game
int guess_num;
int game1_num;
int picked_num;
int sumCheck;
string outcome;


//for game2:rock/paper/scissor
int opponent_case;
int player_case;
int rock=1;
int paper=2;
int scissor=3;


//for game3:number guessing game
int randomBig=0;
int my_guess;


//for game4
int dice_sides;
int dice_rolls;
int smth;
int randinrange;
int sum1;
int sum2;



//CASE 2
//micros & variables 
int a=10,b=17;
#define subm(a,b) (a)-(b) 
#define cubem(a) (a)*(a)*(a)
#define minm(a,b) (a<b)?(a):(b)
#define oddm(a) ((a%2==0)?1:0)


//This is a random function, can be used in any case/game
 int RandomInRange(int min, int max){
	 return rand()%max + min;
 }

//this is a function for game 'dice roll', which generates a side value randomly between the max and min
 int RollDie(int sides){
    
    randinrange= RandomInRange(1,sides);
    return randinrange;
}

//this function is just to return if its odd or even:game 1
 int IsEven(int number){
	 if(number%2==0){
		  
		return 0;
	 }
	 else if(number%2!=0) {
	 	 
		 return 1;
	 }
 }


// these funtions are for the case 2
int subf(int a,int b){ 
	return a-b;
}
int cubef(int a){ 
	return a*a*a;
}
int minf(int a, int b){ 
	if(a<=b){
		return a;
	} else {
		return b;
	}
}
int oddf(int a){ 
	if( a % 2 ==0){
		return 0;
	}else{
		return 1;
	}
}


   
int main(){
      file = fopen("random_names.txt", "r"); //opens and reads the file
      //counting number of lines in the text file
      while ((ch = fgetc(file)) != EOF){ 
		if (ch == '\n' || ch == '\0')
        lines++;
	}
	
       
    
        srand(time(NULL));
        any_numb= rand()%lines+1;
      for (int i = 1; i <= any_numb; i++){
        getline(text, opp_name);
   }
       

    



	char cha; //choice of case (0,1 or 2)
	

		while(1==1){
            //welcome message
			printf("Welcome to the CSE240 Assignment 2!\n"); //main menue 
		    printf("Menu:\n");
		    printf("1 – CSE240 Mini-Game Collection\n");
		    printf("2 – Macros vs Functions Throw-down\n");
		    printf("0 - Exit\n");
		    printf("Choose an option:");
			scanf("%c",&cha); 
            cout<<endl<<endl;
			switch(cha){
			
			case '1':                 
				while(odd%2==0){
				cout<<"Welcome to CSE240 Mini-Game Collection!"<<endl<<"I am your opponent "<<opp_name<<endl<<"How many rounds should we play? (Choose an odd number)"<<"\n";
                cout<<">";
                cin>>odd;
                cout<<" "<<endl;
				cout<<"The score is:"<<endl;
				cout<<player_score<<" - Player"<<endl;
				cout<<opponent_score<<" - "<<opp_name<<endl;
				cout<<" "<<endl;  
				if(odd%2==0)
				{
					cout<<"ERROR!! Only input odd numbers :) "<<endl;
				}
				}

                //generating any games randomly
				for(int j=0;j<odd;j++){
					any_game= RandomInRange(1,4);
                    //any_game=3;

                    //This is game number 1
                    //Evens or Odds game
					if(any_game==1){
						cout<<"Game#"<< o <<endl;
						cout<<"Even/Odd game!"<<endl;
						cout<<"Guess even or odd! (0 for even, 1 for odd): ";
						cin>>guess_num;
						cout<<"Enter a number (between 0 and 100):"<<"\t";
						cin>>game1_num;
						picked_num = RandomInRange(0, 100);
						cout<< opp_name <<endl;
						sumCheck = picked_num + game1_num;
						cout<<" picked "<<picked_num<<endl;
						if(IsEven(sumCheck)==0){
							outcome = " - EVEN\n";
                            cout<<endl;
						}else{
							outcome = " - ODD\n";
                            cout<<endl;
						}
						
						cout<< picked_num<< " + "<<game1_num<< " = "<<sumCheck << outcome;
						
						
						if(IsEven(sumCheck) ==1 && guess_num==0 ){
							opponent_score++;
						}
						if(IsEven(sumCheck) ==0 && guess_num==1 ){
							opponent_score++;
						}
						if(IsEven(sumCheck) ==1 && guess_num==1 ){
							player_score++;
						}
						if(IsEven(sumCheck) ==0 && guess_num==0 ){
							player_score++;
						}
					}
                    //This is game number 2 
                    //rock/paper/scissor game
					if(any_game==2){
                        cout<<"Game#"<< o <<endl;
						cout<<"Rock, Paper, Scissors game! Choose a throw!"<<endl;
						cout<<"1. Rock"<<endl;
						cout<<"2. Paper"<<endl;
						cout<<"3. Scissors"<<endl;
                        cin>>player_case;
                        cout<<"My choice is "<<player_case<<endl;
                        opponent_case = RandomInRange(1,3);
                        cout<<opp_name<<endl;
                        cout<< "chose "<< opponent_case <<endl;

                        //all the 'if' conditions below are for every possibility, and whenever there is a tie, the score will remain the same.
                        if(player_case==1 && opponent_case==2){
                            opponent_score++;
                            cout<< "opponent score: " << opponent_score<<endl;
                            cout<<" player score: "<< player_score<<endl;
                        }
                        if(player_case==2 && opponent_case==1){
                            player_score++;
                            cout<< "opponent score: " << opponent_score<<endl;
                            cout<<" player score: "<< player_score<<endl;
                        }
                        if(player_case==1 && opponent_case==3){
                            player_score++;
                            cout<< "opponent score: " << opponent_score<<endl;
                            cout<<" player score: "<< player_score<<endl;
                        }
                        if(player_case==3 && opponent_case==1) {
                            opponent_score++;
                            cout<< "opponent score: " << opponent_score<<endl;
                            cout<<" player score: "<< player_score<<endl;
                        }
                        if(player_case==3 && opponent_case==2){
                            player_score++;
                            cout<< "opponent score: " << opponent_score<<endl;
                            cout<<" player score: "<< player_score<<endl;
                        }
                        if(player_case==2 && opponent_case==3){
                            opponent_score++;
                            cout<< "opponent score: " << opponent_score<<endl;
                            cout<<" player score: "<< player_score<<endl;
                        }
                        


                    }

                    //this is the game 3: number guessing game
					if(any_game==3){
						cout<<"Game#"<< o <<endl;
                        cout<<"Number Guessing game!"<<endl;
                        int min3 = RandomInRange(0,30);
                        int max3 = RandomInRange(0,70);
                        
                        max3=max3+min3+30;
                        randomBig = RandomInRange(min3,max3);
                        cout<<"Player I’m thinking of a number between "<<min3<<" and "<<max3<<"!" << endl << "You have 5 guesses!"<<endl;
                        
                        
                        //cout<<randomBig<<endl;

                        //the player has 5 guesses and the there is a feedback everytime a guess is entered
                        for(int z=0;z<5;z++){
                            cout<< "What's guess # "<< z+1 <<"  ";
                            cin>>my_guess;
                            if(my_guess<randomBig){
                                cout<<"My number is greater! "<<endl;    
                            }
                            else if(my_guess>randomBig){
                                cout<<"My number is lower!"<<endl;
                            }
                            else if(my_guess==randomBig){
                                player_score++;
                                cout<<"Player won! " << player_score <<endl;
                                break;
                               
                            }

                            else if(my_guess!=randomBig){
                                opponent_score++;
                                cout<<"Opponent won! "<< opponent_score<<endl;
                            }
                             
                        }
                        


                        
					}

                    //this is the game 4: Dice Roll Showdown
					if(any_game==4){
						cout<<"Game#"<< o <<endl;
                        cout<<"Dice Roll Showdown!"<<endl;
                        cout<<"How many sides do the dice have (input a positive number): ";
                        cin>>dice_sides;
                        cout<<"How many dice will each player roll? ";
                        cin>>dice_rolls;
                        cout<< "Player 1 Rolled: "<< endl;
                        for(int k=0;k<dice_rolls;k++){
                           int smth = RollDie(dice_sides);
                           cout<<smth<<endl;
                            sum1 = smth + sum1;
                        }
                        cout<<"Total: "<<sum1<<endl<<endl;
						cout<<opp_name<<endl;
                        cout<< " Rolled: "<< endl;
                        for(int l=0;l<dice_rolls;l++){
                           int anyth = RollDie(dice_sides);
                           cout<<anyth<<endl;
                            sum2 = anyth + sum2;
                        }
                        cout<<"Total: "<<sum2<<endl;

                        if(sum1>sum2)
                        {
                            cout<<"Player wins";
                            player_score++;
                        }
                        else if(sum1<sum2)
                        {
                            cout<<opp_name<<endl;
                            cout<<" wins!";
                            opponent_score++; 
                        }
                    

					}
					
                    //score is recorded(incremented) and pinted out on the output window after every round of a game
                    cout<<" "<<endl;
					cout<<"The score is:"<<endl;
					cout<<player_score<<" : Player"<<endl;
					cout<<opponent_score<<" : "<<opp_name<<endl;
					cout<<" "<<endl;  
				    
                    o++; 
                    
                }
			    o=1;

                break;

            //The inline functions are parsed by the compiler;the micros are expanded by the C++ prepocessor: this difference creates other differences because it 
			case '2': 
                cout<<"2 – Macros vs Functions Throw-down\n"; 
                cout<< "subf: "<<subf(a,b)<<endl;
                a=10,b=17;
                cout<<"sub_macro: " <<subm(a,b)<<endl;
                a=10,b=17;
                cout<<"subf: " <<subf(a++,b--)<<endl;
                a=10,b=17;
                cout<<"sub_macro: " <<subm(a++,b--)<<endl;
                a=10,b=17;
                cout<< "cubef: "<<cubef(a)<<endl;
                a=10,b=17;
                cout<< "cube_macro: "<<cubem(a)<<endl;
                a=10,b=17;
                cout<< "cubef: "<<cubef(--a)<<endl;
                a=10,b=17;
                cout<< "cube_macro: "<<cubem(--a)<<endl;
                a=10,b=17;
                cout<< "minf: "<<minf(a,b)<<endl;
                a=10,b=17;
                cout<< "min_macro: "<<minm(a,b);
                a=10,b=17;
                cout<<endl;
                cout<< "minf: "<<minf(--a,--b)<<endl;
                a=10,b=17;
                cout<< "min_macro: "<<minm(--a,--b);
                a=10,b=17;
                cout<<endl;
                cout<< "odd: "<<oddf(a)<<endl;
                a=10,b=17;
                cout<< "odd_macro: "<<oddm(a)<<endl;
                a=10,b=17;
                cout<< "oddf: "<<oddf(a++)<<endl;
                a=10,b=17;
                cout<< "odd_macro: "<<oddm(a++)<<endl;
                cout<<endl;
                break;
			case '0':
                 cout<<"0 - Exit\n"; //exit
                return 0;
			    break;
			
			default: printf("invalid operator\n"); // if there is a char that is not one of the cases
			break;

			}
			
			cha = getchar();	
					
		}
		
	return 0; //quits the program after the while loop
}