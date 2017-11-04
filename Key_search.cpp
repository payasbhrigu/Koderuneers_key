#include<bits/stdc++.h>

using namespace std;

int a=-1;

int OpCodes(char s1[100][100],char s2[])
{
       
       a++;
       
       
        int i=0,j=0,k=0,count1 = 0, count2 = 0,count=0,flag=-2;  
     
        while (s1[a][count1] != '\0')

                count1++;                       //Calculating length of s1 (Line from file)

        while (s2[count2] != '\0')

                count2++;                       //Calculating length of s2  (Token)
        
       while(s1[a])
       {
                if(count2<count1)                       //The length of substring is always less than the compared string
                {

                        for (i = 0; i <= count1 - count2; i++)

                        {

                                for (j = i; j < i + count2; j++)

                                {

                                        flag = 1;

                                        if (s1[j][k] != s2[j - i])

                                         {

                                                flag = 0;

                                                break;

                                         }
                                         k++;

                                }

                                if (flag == 1)

                                count++;

                        }   
                }
                a++;
    }
    return count;
}
    
void GenerateTokens(char token[])
{
        
        cout<<"Enter the token to be used in this code : ";
        gets(token);
        strcat(token," ");
}    
        
int main()
{
        ifstream fin("Koderunners.kdr");
        char token[100],word[100];
        int i=0,d=0;
         

        GenerateTokens(token);

        
        char linearr[100][100];
        
        int countOccur[100];
        for( d=0;d<100;d++)
                countOccur[d]=0;
        
        
        
        cout<<"The input file is : \n";                         // Taking the input from file in each line
        i=0;
        while(fin)
        {        
        
               
                if(fin!='\0')
                {
                        fin.getline(word,100,'\n');
                        strcpy(linearr[i],word);
                        puts(linearr[i]);
                        cout<<"\n";
                }
                  
          i++;
        
        }  
        printf("\n\n");      
        

        d=0;
        int Sum_of_counts=0;
                for(int z=0;z<i-1;z++)
                {
                        
                     countOccur[d]= OpCodes(linearr,token);             //Counting how many times token has occurred in file
                     Sum_of_counts+=countOccur[d];
                     d++;
                      
                 } 

                        
                        
        
        if(Sum_of_counts==0)
                    cout<<"Error ! Some words other than"<<token <<" have appeared !";          //Printing desired output
        else
                    cout<<token<<" has appeared in the file "<<Sum_of_counts<<" times"; 
        
               
        fin.close();
        return 0;
}
