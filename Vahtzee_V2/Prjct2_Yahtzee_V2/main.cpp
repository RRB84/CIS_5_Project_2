/* 
 * File:   main.cpp
 * Author: Ryan Bouskill
 * Created on June 2st, 2019, 12:35 PM
 * Purpose:  Projet 2 Yahtzee version 2
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
const int COL=4;
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
    const int ROW=7;
    
    const int SIZE=5;//Array Size
    int FrstRol[SIZE];//dice roll array
    int svDice[SIZE];//save dice array
    int ScndRol[SIZE];//second roll array
    int ThrdRol[SIZE];//third roll array
    int Score[ROW][COL];//Score array
    char KpRoll;//answer variable
    bool test;//flag 
    
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
 
    //Display the outputs
    for(int tik=0;tik<13;tik++)
    {
       
        cout<<"  **Round**\n     "<<tik+1<<"/13\n";
        cout<<"\n!!!!First Roll!!!!"<<endl;
        cout<<"-------------------\n";
        DcRoll(FrstRol,SIZE);
        cout<<endl;
        cout<<"\nDo you want to keep rolling? Y/N : ";
            cin>>KpRoll;//answer variable
             if(KpRoll=='N' || KpRoll=='n')//Add up score if done rolling
             {
                ScreMenu(Score,ROW,ones,Twos,Threes,Fours,Fives,Sixes,ThOfK,FrOfK,
                        Chance,FulHse,SmStr,LrStr,YTZe,Total);
                ScreUp(FrstRol,SIZE,ones,Twos,Threes,Fours,Fives,Sixes,ThOfK,FrOfK,
                        Chance,FulHse,SmStr,LrStr,YTZe);
                KpRoll='b';
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
                        cout<<"!!ERROR!!"<<endl;;
                }  
                if(test==true)
                cout<<"\n!!!!Second Roll!!!!";

                ReRoll(svDice,ScndRol,SIZE);
                cout<<endl;
                cout<<"\nDo you want to keep rolling? Y/N : ";
                test=false;
                KpRoll='b';
                cin>>KpRoll;//answer variable  
              }

             if(KpRoll=='N' || KpRoll=='n')//Add up score if done rolling
             {
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
                     cout<<"\n!!!!Third Roll!!!!";
                 ReRoll(svDice,ThrdRol,SIZE);
                 cout<<endl;
            ScreMenu(Score,ROW,ones,Twos,Threes,Fours,Fives,Sixes,ThOfK,FrOfK,
                        Chance,FulHse,SmStr,LrStr,YTZe,Total);
                ScreUp(ThrdRol,SIZE,ones,Twos,Threes,Fours,Fives,Sixes,ThOfK,FrOfK,
                        Chance,FulHse,SmStr,LrStr,YTZe);
            }
            
          KpRoll='b';
          test=false; 
          system("clear");
        }//End of Turn loop.      
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
    }        
}
//Re-Roll Function
int ReRoll(int SVray[],int nxtrol[],int size)
{
    cout<<endl;
    cout<<"-------------------\n";
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
//    for(int i=0;i<size;i++)
//    {
//        cout<<dice[i]<<" ";
//    }
//   
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
     ofstream outFile;//writing to a file
    ifstream inFile;//reading from a file
    int Ans;
    outFile.open("dice_roll.dat");
    for(int i=0;i<size;i++){outFile<<roll[i]<<endl;}
    outFile.close();
    inFile.open("dice_roll.dat");
    int A,B,C,D,E;
    inFile>>A>>B>>C>>D>>E;
    cout<<"Here is your Dice.\n";
    cout<<"["<<A<<"] ["<<B<<"] ["<<C<<"] ["<<D<<"] ["<<E<<"]"<<endl;
    cout<<"Which Category would you like to score?\n";
    cin>>Ans;
    inFile.close();
                switch(Ans){
                case 1:{
                     if(A==1)Ones++;if(B==1)Ones++;if(C==1)Ones++;if(D==1)Ones++;
                     if(E==1)Ones++;                     
                     cout<<"Ones Score is "<<Ones<<endl<<endl;
                     break;
                }
                case 2:{
                     if(A==2)Twos+=2;if(B==2)Twos+=2;if(C==2)Twos+=2;if(D==2)Twos+=2;
                     if(E==2)Twos+=2;                     
                     cout<<"Twos Score is "<<Twos<<endl<<endl;
                     break;
                }
                case 3:{
                     if(A==3)Threes+=3;
                     if(B==3)Threes+=3;
                     if(C==3)Threes+=3;
                     if(D==3)Threes+=3;
                     if(E==3)Threes+=3;
                     
                     cout<<"Threes Score is "<<Threes<<endl<<endl;            
                     break;
                }
                case 4:{
                     if(A==4)Fours+=4;
                     if(B==4)Fours+=4;
                     if(C==4)Fours+=4;
                     if(D==4)Fours+=4;
                     if(E==4)Fours+=4;
                     
                     cout<<"Fours Score is "<<Fours<<endl<<endl;
                     break;
                }
                case 5:{
                     if(A==5)Fives+=5;
                     if(B==5)Fives+=5;
                     if(C==5)Fives+=5;
                     if(D==5)Fives+=5;
                     if(E==5)Fives+=5;
                     
                     cout<<"Fives Score is "<<Fives<<endl<<endl;
                     break;
                }
                case 6:{
                     if(A==6)Sixes+=6;
                     if(B==6)Sixes+=6;
                     if(C==6)Sixes+=6;
                     if(D==6)Sixes+=6;
                     if(E==6)Sixes+=6;
                     
                     cout<<"Sixes Score is "<<Sixes<<endl<<endl;
                     break;
                }
                case 7:{               
                    Chance=A+B+C+D+E;                    
                    cout<<"Chance Score is "<<Chance<<endl<<endl;
                    break;
                }
                case 8:{
                        ThOfK=A+B+C+D+E;                    
                    cout<<"Three of a Kind Score is"<<ThOfK<<endl<<endl;
                    break;
                    }
                case 9:{
                   FrOfK=A+B+C+D+E;
                    
                    cout<<"Four of a Kind Score is "<<FrOfK<<endl<<endl;                      
                    break;
                }
                case 10:{
                    FulHse=0;
                    cout<<"Full House Score is "<<FulHse<<endl<<endl;
                    break;
                }
                case 11:{ 
                    SmlStr=0;
                    cout<<"Small Straight Score is "<<SmlStr<<endl<<endl;
                    break;
                }
                case 12:{
                    LrgStr=0;
                    cout<<"Large Straight Score is "<<LrgStr<<endl<<endl;
                    break;
                }               
                case 13:{
                    YTZe=0;
                    cout<<"YAHTZEE!!! Score is "<<YTZe<<endl<<endl;
                }

            }//end of score menu
                
}