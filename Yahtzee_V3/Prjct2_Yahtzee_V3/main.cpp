/* 
 * File:   main.cpp
 * Author: Ryan Bouskill
 * Created on June 3rd, 2019, 09:45 AM
 * Purpose:  Projet 2 Yahtzee version 3
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib> //Random Function
#include <ctime>  //Time Function
#include <vector>
#include <iomanip>//manip output
#include <string>   //for string data
#include <fstream> // read write to file
#include <stdlib.h>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
int DcRoll(int [],int);//dice roll Proto
int SvDice(int[],int);//save dice Proto
void bubSrt(int [],int);//bubble sort Proto
void swap(int &,int &);//swap Proto
bool check(int [],int [],int);//checks user input Proto
int ReRoll(int[],int[],int);//Re-roll Proto
const int COL=4;//2D Array const variable.
int ScreMenu(int[][COL],int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);//score menu Proto
int ScreUp(int[],int,int&,int&,int&,int&,int&,int&,int&,int&,int&,int&,int&,int&,int&);
//Execution Begins Here!
int main(int argc, char** argv) 
{
    ofstream outFile;//writing to a file
    ifstream inFile;//reading from a file
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));//for random dice roll
    //Declare Variables
    //variables for score board 
    int ones=0,Twos=0,Threes=0,Fours=0,Fives=0,Sixes=0,Total=0;
    int ThOfK=0,FrOfK=0,Chance=0,FulHse=0,SmStr=0,LrStr=0,YTZe=0;
    const int ROW=7;//score board rows.
    
    const int SIZE=5;//Array Size
    int FrstRol[SIZE];//dice roll array
    int svDice[SIZE];//save dice array
    int ScndRol[SIZE];//second roll array
    int ThrdRol[SIZE];//third roll array
    int Score[ROW][COL];//Score array    
    char KpRoll;//answer variable
    char a;
    bool test;//flag 
    bool start=false;
    float totalScr=0;
    
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
 
    //Display the outputs
    while(start==false){
        cout<<"Welcome to YAHTZEE!!!\n";
        cout<<"After each roll you can save dice and re-roll or\n";
        cout<<"Choose to at your dice to the score board.\n";        
        cout<<"\nReady to Roll?! Y/N?";
        cin>>a;
      if(a=='y'||a=='Y')start=true;
    }
    system("clear");
    for(int tik=0;tik<13;tik++)
    {
       
        cout<<"        ***Round***\n          "<<tik+1<<" of 13\n";
        cout<<"-----------------------------------\n";
        cout<<"!!!!!!YAHTZEE SCORE BOARD!!!!!!\n";
        cout<<"-----------------------------------\n";
        ScreMenu(Score,ROW,ones,Twos,Threes,Fours,Fives,Sixes,ThOfK,FrOfK,
                 Chance,FulHse,SmStr,LrStr,YTZe,Total);
        cout<<endl;
        cout<<"\n     !!!!First Roll!!!!"<<endl;
        cout<<"     -------------------\n";
        cout<<"     ";DcRoll(FrstRol,SIZE);
        cout<<endl;
        cout<<"\nDo you want to keep rolling? Y/N : ";
        bool round=false; 
        while(round==false)
        {      
            cin>>KpRoll;//answer variable
            if((KpRoll=='y'||KpRoll=='n')||(KpRoll=='Y'||KpRoll=='N'))round=true;
            else
                round=false;            
        }
      
             if(KpRoll=='N' || KpRoll=='n')//Add up score if done rolling
             {
                cout<<"-----------------------------------\n";
                cout<<"!!!!!!YAHTZEE SCORE BOARD!!!!!!\n";
                cout<<"-----------------------------------\n";
                 //Score Board
                ScreMenu(Score,ROW,ones,Twos,Threes,Fours,Fives,Sixes,ThOfK,FrOfK,
                        Chance,FulHse,SmStr,LrStr,YTZe,Total);
                //Scoring Function
                ScreUp(FrstRol,SIZE,ones,Twos,Threes,Fours,Fives,Sixes,ThOfK,FrOfK,
                        Chance,FulHse,SmStr,LrStr,YTZe);
                KpRoll='b';//cancel out other If no statments
             }
            if(KpRoll=='Y' || KpRoll=='y')//continue to next dice roll 2
             {
                 int t=0;
                 while(test==false)
                 {                                 
                    SvDice(svDice,SIZE);
                    //cout<<"\nSorted Roll\n";    
                    bubSrt(FrstRol,SIZE);
                    //cout<<"\nSorted Save\n";
                    bubSrt(svDice,SIZE);
                    test=check(FrstRol,svDice,SIZE);
                    t++;
                    if(t>0&&test==false)
                        cout<<"!!ERROR!!"<<endl;
                }  
                if(test==true)
                cout<<"\n     !!!!Second Roll!!!!\n";
                cout<<"     -------------------\n";
                cout<<"     ";ReRoll(svDice,ScndRol,SIZE);
                cout<<endl;
                cout<<"\nDo you want to keep rolling? Y/N : ";
                test=false;
                KpRoll='b';
                 bool round2=false;                
                 while(round2==false)
                    {      
                        cin>>KpRoll;//answer variable
                        if((KpRoll=='y'||KpRoll=='n')||(KpRoll=='Y'||KpRoll=='N'))round2=true;
                        else
                            round2=false;            
                    }               
                
              }

             if(KpRoll=='N' || KpRoll=='n')//Add up score if done rolling
             {
                cout<<"-----------------------------------\n";
                cout<<"!!!!!!YAHTZEE SCORE BOARD!!!!!!\n";
                cout<<"-----------------------------------\n";
                ScreMenu(Score,ROW,ones,Twos,Threes,Fours,Fives,Sixes,ThOfK,FrOfK,
                        Chance,FulHse,SmStr,LrStr,YTZe,Total);
                ScreUp(ScndRol,SIZE,ones,Twos,Threes,Fours,Fives,Sixes,ThOfK,FrOfK,
                        Chance,FulHse,SmStr,LrStr,YTZe);
                KpRoll='b';
             }
            if(KpRoll=='Y' || KpRoll=='y')//continue to next dice roll 3
            {
                int t=0;
                 while(test==false)
                 {
                    SvDice(svDice,SIZE);
                    //cout<<"\nSorted Roll\n";    
                    bubSrt(ScndRol,SIZE);
                   // cout<<"\nSorted Save\n";
                    bubSrt(svDice,SIZE);
                    test=check(ScndRol,svDice,SIZE);
                    t++;
                    if(t>0&&test==false)
                        cout<<"!!ERROR!!"<<endl;;
                 }
                 if(test==true)
                     cout<<"\n     !!!!Third Roll!!!!\n";
                 cout<<"     -------------------\n";
                 cout<<"     ";ReRoll(svDice,ThrdRol,SIZE);
                 cout<<endl;
                 cout<<"-----------------------------------\n";
                 cout<<"!!!!!!YAHTZEE SCORE BOARD!!!!!!\n";
                 cout<<"-----------------------------------\n";
                 //Score Board
                ScreMenu(Score,ROW,ones,Twos,Threes,Fours,Fives,Sixes,ThOfK,FrOfK,
                        Chance,FulHse,SmStr,LrStr,YTZe,Total);
                            //Scoring function
                ScreUp(ThrdRol,SIZE,ones,Twos,Threes,Fours,Fives,Sixes,ThOfK,FrOfK,
                        Chance,FulHse,SmStr,LrStr,YTZe);
                
            }
            //Save Player Score.
            outFile.open("Player_1_Score.txt");
                outFile<<Total;
          KpRoll='b';
          test=false; 
          system("clear");
        }//End of Turn loop. 
                 cout<<"-----------------------------------\n";
                 cout<<"!!!!!!YAHTZEE SCORE BOARD!!!!!!\n";
                 cout<<"-----------------------------------\n";
                 //Score Board
                ScreMenu(Score,ROW,ones,Twos,Threes,Fours,Fives,Sixes,ThOfK,FrOfK,
                        Chance,FulHse,SmStr,LrStr,YTZe,Total);
                totalScr=Total/375;
                cout<<"Your Total Score is "<<Total<<endl;
                cout<<"You Got "<<totalScr*100<<"% of possible points."<<endl;
    //Exit stage right or left!
    return 0;
}
//Dice Roll function
int DcRoll(int dice[],int size)
{    
    
    for(int i=0;i<size;i++)
    {
       dice[i]=rand()%6+1;
       cout<<"["<<dice[i]<<"] ";
//        cin>>dice[i];
    }        
}
//Re-Roll Function
int ReRoll(int SVray[],int nxtrol[],int size)
{    
    for(int i=0;i<size;i++)
    {
        if(SVray[i]==0)
        {
            SVray[i]=rand()%6+1;
            cout<<"["<<SVray[i]<<"] ";
        }
        else
        {
            cout<<"["<<SVray[i]<<"]* ";
        }
    }
//    for(int j=0;j<size;j++)
//        cout<<ray[j]<<" ";
    
    for(int x=0;x<size;x++)
    {
        nxtrol[x]=SVray[x];
        //cout<<"["<<nxtrol[x]<<"] ";
    }
}
//Save Dice function
int SvDice(int Sray[],int size)
{
    int Die,i=0;
    cout<<"Enter the Dice you would like the save followed"
            "\nby Zero when you are done "<<endl;
    cout<<"Enter Dice? : ";
    cin>>Die;
    while(i<size)
    {
        if(Die!=0)
        {
            i++;            
            Sray[i-1]=Die;
            cout<<"Enter Dice? : ";
            cin>>Die;
        }
        else
        {
            i++;
            Sray[i-1]=0;
        }
    }  
//    cout<<"Saved Dice are.\n";
//    for(int indx=0;indx<size;indx++)
//    {
//        cout<<Sray[indx]<<" ";
//    }
   
}
//buble sort function
void bubSrt(int dice[],int size)
{
    int maxE,indx;
    for(maxE=size-1;maxE>0;maxE--)
    {
        for(indx=0;indx<maxE;indx++)
        {
            if(dice[indx]>dice[indx+1])
            {
                swap(dice[indx],dice[indx+1]);
            }
        }
    }
    cout<<endl;
   
}
//Swap fuction
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;           
}
//Check user input fuction
bool check(int roll[],int save[],int size)
{
    int svSpt=0;
    int tal=0;
    int chk=0,Eql=0;
    bool test;
    for(svSpt=0;svSpt<size;svSpt++)
    {
        for(int i=0;i<size;i++)
        {
            if(roll[i]==save[svSpt])
            {
                tal++;
                svSpt++;                
            }
        }
    }
    for(int x=0;x<size;x++)
            if(save[x]==0)chk++;
    Eql=size-chk;
    if(tal==Eql)    
        test=true;
    else
        test=false;
//    cout<<"size = "<<size<<endl;
//    cout<<"chk = "<<chk<<endl;
//    cout<<"Eql = "<<Eql<<endl;
//    cout<<"Tal = "<<tal<<endl;
    
    return test;
}
//Score menu function
int ScreMenu(int score[][COL],int ROW,int ones,int Twos,int Threes,int Fours,int Fives,int Sixes,
        int ThOfK,int FrOfK,int Chance,int FulHse,int SmlStr,int LrgStr,int YTZe,int Total)
{
    for(int i=0;i<ROW;i++)
    {
        if(i==0)cout<<"1-Ones   = ";
        if(i==1)cout<<"2-Twos   = ";
        if(i==2)cout<<"3-Threes = ";
        if(i==3)cout<<"4-Fours  = ";
        if(i==4)cout<<"5-Fives  = ";
        if(i==5)cout<<"6-Sixes  = ";
        if(i==6)cout<<"7-Chance = ";
        for(int j=0;j<COL;j++)
        {
            if(j==1&&i==0){score[i][j]=ones;cout<<setw(2)<<ones;}
            if(j==1&&i==1){score[i][j]=Twos;cout<<setw(2)<<Twos;}
            if(j==1&&i==2){score[i][j]=Threes;cout<<setw(2)<<Threes;}
            if(j==1&&i==3){score[i][j]=Fours;cout<<setw(2)<<Fours;}
            if(j==1&&i==4){score[i][j]=Fives;cout<<setw(2)<<Fives;}
            if(j==1&&i==5){score[i][j]=Sixes;cout<<setw(2)<<Sixes;}
            if(j==1&&i==6){score[i][j]=Chance;cout<<setw(2)<<Chance;}
            if(j==3&&i==0){score[i][j]=ThOfK;cout<<setw(2)<<ThOfK;}
            if(j==3&&i==1){score[i][j]=FrOfK;cout<<setw(2)<<FrOfK;}
            if(j==3&&i==2){score[i][j]=FulHse;cout<<setw(2)<<FulHse;}
            if(j==3&&i==3){score[i][j]=SmlStr;cout<<setw(2)<<SmlStr;}
            if(j==3&&i==4){score[i][j]=LrgStr;cout<<setw(2)<<LrgStr;}
            if(j==3&&i==5){score[i][j]=YTZe;cout<<setw(2)<<YTZe;}
            if(j==3&&i==6){score[i][j]=Total;cout<<setw(2)<<Total;}
            if(j==2&&i==0)cout<<" |8-Three of a Kind  = ";
            if(j==2&&i==1)cout<<" |9-Four of a Kind   = ";
            if(j==2&&i==2)cout<<" |10-Full House      = ";
            if(j==2&&i==3)cout<<" |11-Small Straight  = ";
            if(j==2&&i==4)cout<<" |12-Large Straight  = ";
            if(j==2&&i==5)cout<<" |13-YAHTZEE!        = ";
            if(j==2&&i==6)cout<<" |Total!             = ";
            if(j==1)Total+=score[i][j];
            if(j==3)Total+=score[i][j];
            
                      
        }
        cout<<endl;
    }
}
int ScreUp(int roll[],int size,int &Ones,int &Twos,int&Threes,int &Fours,int &Fives,int &Sixes,
        int &ThOfK,int &FrOfK,int &Chance,int &FulHse,int &SmlStr,int &LrgStr,int &YTZe)
{     
    int Ans; 
    cout<<"\n     Your Dice to Score.\n";
    cout<<"     -------------------\n     ";
    for(int i=0;i<size;i++)cout<<"["<<roll[i]<<"] ";cout<<endl;
    cout<<"Which Category would you like to score?\n";
    cin>>Ans;    
    switch(Ans){
    case 1:{for(int j=0;j<size;j++)if(roll[j]==1)Ones+=1;break;}                                                          
    case 2:{for(int j=0;j<size;j++)if(roll[j]==2)Twos+=2;break;}                                                         
    case 3:{for(int j=0;j<size;j++)if(roll[j]==3)Threes+=3;break;}                                                                         
    case 4:{for(int j=0;j<size;j++)if(roll[j]==4)Fours+=4;break;}
    case 5:{for(int j=0;j<size;j++)if(roll[j]==5)Fives+=5;break;}                                                            
    case 6:{for(int j=0;j<size;j++)if(roll[j]==6)Sixes+=6;break;}                              
    case 7:{for(int j=0;j<size;j++)Chance+=roll[j];break;}             
    case 8:{//Three of a kind
        bubSrt(roll,size);
        int tal=0;
        for(int j=0;j<size;j++){                                          
            if(roll[j]==roll[j+1])tal++;}                                      
        if(tal==2){
            for(int i=0;i<size;i++)
                ThOfK+=roll[i];}
        break;
        }
    case 9:{//Four of a kind
        bubSrt(roll,size);
        int tally=0;
        for(int j=0;j<size;j++){                                                                   
            if(roll[j]==roll[j+1])tally++;}                                     
        if(tally==3){
            for(int i=0;i<size;i++)
                FrOfK+=roll[i];}                                       
        break;
    }
    case 10:{//full House
        int tal=0;
         bubSrt(roll,size); 
         int temp=roll[0];
         int TempA=roll[4];
         for(int i=0;i<size;i++)
         {
             if(roll[i]==temp)tal++;
             if(roll[i]==TempA)tal++;
         }
         if(tal==5)FulHse=25;                     
        break;
    }
    case 11:{//Small Straight
        int tal=0;                    
        bubSrt(roll,size);
        for(int i=0;i<size;i++)
            if(roll[i]<roll[i+1])tal++;
        if(tal>=3)SmlStr=30;                                       
        break;
    }
    case 12:{//Large Straight.
        bubSrt(roll,size);
        for(int i=0;i<size;i++)
        {
            if(roll[i]==(i+1))LrgStr=40;
            else if(roll[i]==(i+2))LrgStr=40;
            else
                LrgStr=0;
        }
        break;
    }               
    case 13:{//Yahtzee
        int tal=0;
        for(int j=0;j<size;j++){                                            
            if(roll[j]==roll[j+1])tal++;}                                      
        if(tal>=4){YTZe=50;}                        
    }

  }//end of score menu
                
}