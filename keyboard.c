#include<iostream>
#include<cstring>
using namespace std;

class keyboard
{
public:
    int R,C,ptr_R,ptr_C,pos_R,pos_C,count;
    char key[50][50],message_letter;
    string message;
    keyboard();
    void accept();
    void calculate();
};

keyboard::keyboard()
{
    ptr_R=0;
    ptr_C=0;
    count++;
}

void keyboard::accept()
{
    cout<<"\n Enter No. of Rows = ";
    cin>>R;
    cout<<"\n Enter No. of Columns = ";
    cin>>C;
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
    message+='*';
}

void keyboard::calculate()
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(message_letter==key[i][j])
            {
                pos_R=i;
                pos_C=j;
            }
        }
    }
    if(ptr_R<pos_R)
    {
        for(int i=0;ptr_R<pos_R;i++)
        {
            ptr_R++;
            if(key[ptr_R-1][ptr_C]==key[ptr_R][ptr_C])
            {
            }
            else
            {
                count++;
            }
        }
    }
    else if(ptr_R>pos_R)
    {
        for(int i=0;ptr_R>pos_R;i++)
        {
            ptr_R--;
            if(key[ptr_R+1][ptr_C]==key[ptr_R][ptr_C])
            {
            }
            else
            {
                count++;
            }
        }
    }
    if(ptr_C<pos_C)
    {
        for(int i=0;ptr_C<pos_C;i++)
        {
            ptr_C++;
            if(key[ptr_R][ptr_C-1]==key[ptr_R][ptr_C])
            {
            }
            else
            {
                count++;
            }
        }
    }
    else if(ptr_C>pos_C)
    {
        for(int i=0;ptr_C>pos_C;i++)
        {
            ptr_C--;
            if(key[ptr_R][ptr_C+1]==key[ptr_R][ptr_C])
            {
            }
            else
            {
                count++;
            }
        }
    }
    if(message_letter==key[ptr_R][ptr_C])
    {
        count++;
    }
}

int main()
{
    keyboard kb;
    kb.accept();
    for(int i=0;kb.message[i]!='*';i++)
    {
        kb.message_letter=kb.message[i];
        kb.calculate();
    }
    cout<<kb.count;
    return 0;
}