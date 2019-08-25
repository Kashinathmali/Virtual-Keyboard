#include<iostream>
using namespace std;

class keyboard
{
public:
    int R,C,nxt_R,nxt_C=0,pos_R=0,pos_C,count,n;
    char key[50][50],message_letter;
    string message;
    keyboard();
    void accept();
    int cal();
    int A();
    int B();
};

keyboard::keyboard()                    //consteructor
{
     count=1,n=1;
    nxt_R=0;
    nxt_C=0;
}

void keyboard::accept()                                 //used to input
{
    cout<<"\n Enter No. of Rows = ";                    
    cin>>R;
	if(R==0){terminate();}
    cout<<"\n Enter No. of Columns = ";             
    cin>>C;
    if(C==0){terminate();}
    cout<<"\n Enter Layout of Keyboard : "<<"\n";      
    int i=0;
    while(i<R)
    {
        for(int j=0;j<C;j++)
        {
            cin>>key[i][j];               
        }
        i++;
    }
    cout<<"\n Enter Word to be type : ";
    cin>>message;                     
    message+='*';               //Added to find enter key 
}
int keyboard::cal()
{
     for(int i=pos_C;i<C;i++)                   //checks row or column from current position
    {
        for(int j=pos_R;j<R;j++)
        {
            if(message_letter==key[j][i])              
            {
                nxt_R=j;                
                nxt_C=i; 
               return 0;
            }
            else                               //checks from start 
            {
                  for(int i=0;i<C;i++)
                 {
                        for(int j=0;j<R;j++)
                         {
                                if(message_letter==key[j][i])              
                                {
                                        nxt_R=j;            
                                        nxt_C=i;     
                                }
                        }
                }
            }
       }
   }
}
int keyboard::A()                                       //Runs from row to column 
{
        if(pos_R<nxt_R)
	    {
	                while(pos_R!=nxt_R)
	                {
	                        pos_R++;
	                        if(key[pos_R][pos_C]==key[pos_R-1][pos_C])
	                        {
	                                count--; 
	                        }
	                      count++;                     
	                }
	    }
	    if(pos_R>nxt_R)
	    {
	                while(pos_R!=nxt_R)
	                {
	                        pos_R--;
	                        if(key[pos_R][pos_C]==key[pos_R+1][pos_C])
	                        {
	                                count--;
	                        }
	                        count++;              
	                }
	    }
        if(pos_C>nxt_C)
	    {
	                while(pos_C!=nxt_C)
	                {
	                        pos_C--; 
	                        if(key[pos_R][pos_C]==key[pos_R][pos_C+1])
	                        {
	                                count--;
	                        }
	                        count++;
	                }
	    }
	    if(pos_C<nxt_C)
	    {
	                while(pos_C!=nxt_C)
	                {
	                        pos_C++;
	                        if(key[pos_R][pos_C]==key[pos_R][pos_C-1])
	                        {
	                                count--;
	                        }
	                        count++;                 
	                }
	    }
	    if(key[pos_R][pos_C]==key[nxt_R][nxt_C])                    //increased count to select character
	    {   
	             count++;
	    }return count;
}
int keyboard::B()                       //runs from coumn to row
{
        if(pos_C>nxt_C)
        {
                while(pos_C!=nxt_C)
                {
                        pos_C--; 
                        if(key[pos_R][pos_C]==key[pos_R][pos_C+1])
                        {
                                count;
                        }
                        count++; 
                }
    }
    if(pos_C<nxt_C)
    {
                while(pos_C!=nxt_C)
                {
                        pos_C++;
                        if(key[pos_R][pos_C]==key[pos_R][pos_C-1])
                        {
                                count--; 
                        }
                        count++;          
                }
    }
     if(pos_R<nxt_R)
    {
                while(pos_R!=nxt_R)
                {
                        pos_R++;
                        if(key[pos_R][pos_C]==key[pos_R-1][pos_C])
                        {
                                count--; 
                        }
                      count++;                      
                }
    }
    if(pos_R>nxt_R)
    {
                while(pos_R!=nxt_R)
                {
                        pos_R--;
                        if(key[pos_R][pos_C]==key[pos_R+1][pos_C])
                        {
                                count--; 
                        }
                        count++; 
                }
    }
    if(key[pos_R][pos_C]==key[nxt_R][nxt_C])                    //count increased to select character
    {   
             count++;
    }return count;
}
int main()
{
	int temp,fir,sec,p_R,p_C,n=1;
    keyboard kb;                   
    kb.accept();                       
    for(int i=0;kb.message[i]!='\0';i++)
    {
        kb.message_letter=kb.message[i];               
                 kb.cal();
                 if(kb.message_letter!=kb.key[kb.nxt_R][kb.nxt_C])
                 {
                        cout<<"\nGiven input character "<<kb.key[kb.nxt_R][kb.nxt_C]<<" is not present in keyboard layout.... \n\n";
                        return 0;
                 }
                 temp=kb.count;
                p_R=kb.pos_R;p_C=kb.pos_C;
                fir=kb.A();
                kb.count=temp;
                kb.pos_R=p_R;kb.pos_C=p_C;
                sec=kb.B();
                kb.count=temp;
                if(fir<=sec)
                {
                      kb.count=fir;
                }
                else
                        kb.count=sec;
    }
    kb.count--;                   //count decreased for enter 
    cout<<"\nKeystrokes = "<<kb.count<<endl;
    return 0;
}
