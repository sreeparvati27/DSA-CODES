#include<iostream>
using namespace std;
# define max 20
class stud
{
int mks[max];
public:
    stud()    //created student construstor
    {
    for(int i=0;i<max;i++)     
      mks[i]=0;   //display "0" in each arry field
    }
    void insertheap(int tot);  //to insert element into heap
    void displayheap(int tot);
    void showmax(int tot);
    void showmin();
};

void  stud::insertheap(int tot) // whwn we are writing the definiton of class make a use of scope resolution operator
{
 for(int i=1;i<=tot;i++)
 {
   cout<<"enter marks";
   cin>>mks[i];
    int j=i;
    int par=j/2;
    while(mks[j]<=mks[par] && j!=0)
     {
        int tmp = mks[j];
        mks[j]=mks[par];
        mks[par]=tmp;
        j=par;
        par=j/2;
     }       
 }
}

void stud::displayheap(int tot)
{
int i=1,space=6;
cout<<endl;
while(i<=tot)
{
    if(i==1 || i==2 || i==4 || i==8 || i==16)
    {
    cout<<endl<<endl;
    for(int j=0;j<space;j++)
         cout<<" ";
    space-=2;   
    }
   cout<<" "<<mks[i];i++;
         
}
}


void stud::showmax(int tot)
{
int max1=mks[1];
for(int i=2;i<=tot;i++)
{
 if(max1<mks[i])
  max1= mks[i];
}
cout<<"Max marks:"<<max1;
}

void stud::showmin()
{
cout<<"Min marks:"<<mks[1];
}

int main()
{
int ch,cont,total,tmp;  //declare variables
int n;
stud s1; //object of the class
do
{
cout<<endl<<"Menu";
cout<<endl<<"1.Read marks of the student ";
cout<<endl<<"2.Display  Min heap";  //child element is greater than parent element
cout<<endl<<"3.Find Max Marks";
cout<<endl<<"4.Find Min Marks";
cout<<endl<<"Enter Choice";
cin>>ch;
switch(ch)
{
case 1:
     cout<<"how many students";
     cin>>total;
    s1.insertheap(total);
    break;
case 2:
    s1.displayheap(total);
    break;
case 3:    s1.showmax(total);
    break;
case 4:
    s1.showmin();
    break;

}
cout<<endl<<"do u want to continue?(1 for continue)";
cin>>cont;
}while(cont==1);

}
OUTPUT

Menu
1.Read marks of the student
2.Display  Min heap
3.Find Max Marks
4.Find Min Marks
Enter Choice1
how many students5
enter marks56
enter marks34
enter marks78
enter marks89
enter marks90

do u want to continue?(1 for continue)1

Menu
1.Read marks of the student
2.Display  Min heap
3.Find Max Marks
4.Find Min Marks
Enter Choice2



       34

     56 78

   89 90
do u want to continue?(1 for continue)1

Menu
1.Read marks of the student
2.Display  Min heap
3.Find Max Marks
4.Find Min Marks
Enter Choice3
Max marks:90
do u want to continue?(1 for continue)1

Menu
1.Read marks of the student
2.Display  Min heap
3.Find Max Marks
4.Find Min Marks
Enter Choice4
Min marks:34
do u want to continue?(1 for continue)0
