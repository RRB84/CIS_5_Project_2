/* 
 * File:   main.cpp
 * Author: Ryan Bouskill
 * Created on June 1st, 2019, 10:06 AM
 * Purpose:  Projet 2 Yahtzee version 1
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib> //Random Function
#include <ctime>  //Time Function
#include <vector>
#include <iomanip>//manip output
#include <string>   //for string data
#include <fstream> // read write to file
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
void menu(int,int,int,int,int,int,int,int,int,int,int,int,int);//score menu Proto
//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));//for random dice roll
    //Declare Variables
    //variables for score board 
     int Sones=0,STwos=0,SThrees=0,SFours=0,SFives=0,SSixes=0,Score;
     int SThOfK=0,SFrOfK=0,SChance=0,SFulHse=0,SsmStr=0,SLrStr=0,SYTZe=0;
    const int SIZE=5;//Array Size
    int FrstRol[SIZE];//dice roll array
    int svDice[SIZE];//save dice array
    int ScndRol[SIZE];//second roll array
    int ThrdRol[SIZE];//third roll array
    char KpRoll;//answer variable
    bool test;//flag 
    
    
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
 
    //Display the outputs
    cout<<"\n!!!!First Roll!!!!"<<endl;
    cout<<"-------------------\n";
    DcRoll(FrstRol,SIZE);
    cout<<endl;
   cout<<"\nDo you want to keep rolling? Y/N : ";
        cin>>KpRoll;//answer variable
         if(KpRoll=='N' || KpRoll=='n')//Add up score if done rolling
         {
            menu(Sones,STwos,SThrees,SFours,SFives,SSixes,SThOfK,SFrOfK,
                    SChance,SFulHse,SsmStr,SLrStr,SYTZe); 
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
            cin>>KpRoll;//answer variable   
          }
        test=false;
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
        }
       
        
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
void menu(int Sones,int STwos,int SThrees,int SFours,int SFives,int SSixes,
        int SThOfK,int SFrOfK,int SChance,int SFulHse,int SsmStr,int SLrStr,int SYTZe)
{
    //Menu for dice Category 
    cout<<"\n!!!Score Category for your dice!!!\n";
    cout<<"TYPE    SCORE  TYPE               SCORE\n";
    cout<<"1-Ones   = "<<setw(2)<<Sones
    <<"  | 7-Three of a Kind  = "<<setw(2)<<SThOfK<<endl;
    cout<<"2-Twos   = "<<setw(2)<<STwos
    <<"  | 8-Four of a Kind   = "<<setw(2)<<SFrOfK<<endl;
    cout<<"3-Threes = "<<setw(2)<<SThrees
    <<"  | 9-Full House       = "<<setw(2)<<SFulHse<<endl;
    cout<<"4-Fours  = "<<setw(2)<<SFours
    <<"  | 10-Small Straight  = "<<setw(2)<<SsmStr<<endl;
    cout<<"5-Fives  = "<<setw(2)<<SFives
    <<"  | 11-Large Straight  = "<<setw(2)<<SLrStr<<endl;
    cout<<"6-Sixes  = "<<setw(2)<<SSixes
    <<"  | 12-Chance          = "<<setw(2)<<SChance<<endl;
    cout<<"               | 13-YAHTEE!         = "<<setw(2)<<SYTZe<<endl;
}