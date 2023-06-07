#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>

void main()
{

clrscr();
int i,j,q,t,k,l,n,a,r,val,x,y,u,o=0;
int ES[10],EF[10],LS[10],LF[10],D[10],F[10],A[10],R[10];

cout<<"Enter Total no. of Activities=";
cin>>n;

int g=0;
ES[1]=g;


for(i=1;i<n+1;i++)            //getting activity duration
{
cout<<"Enter duration of"<<i<<" =";
cin>>D[i];
}


for(i=1;i<n+1;i++)         //getting details of each activity from Network diagram	
{	cout<<"For Activity "<<i<<endl;
	cout<<"Enter no. of dependency=";
	cin>>j;

		for(k=0;k<j;k++)	//Calculation of EST and EFT
		{
		cout<<"Dependent Activity"<<k+1<<"=";
		cin>>A[k];
		}

		if(j>1)
		{

			for(l=0;l<j;l++)
			{

			  if(D[A[l]]>D[A[l+1]])
			  {	val=D[A[l]];
				u=A[l];
			  }

			  else
			  {	val=D[A[l+1]];
				u=A[l+1];
			  }

			}
			ES[i+1]=EF[u];
			EF[i]=ES[i]+val;

		}

		else
		{

			if(i=o+1)
		   			{
					EF[i]=ES[i]+D[i];
					ES[i+1]=EF[i];
					}



			else
		    	{	
				EF[i]=ES[i]+D[A[i]];
				ES[i+1]=EF[i];
		       }


		}

++o;

}

LF[i]=EF[i];

for(t=n;t<0;t--)
{
	     if(j>1)
			{
			for(l=0;l<j;l++)
				{
			  		if(D[A[l]]<D[A[l+1]])
			  		{	val=D[A[l]];
						u=A[l];
			  		}
			  		else
			  		{	
						val=D[A[l+1]];
						u=A[l+1];
			  		}
				}
			LF[t+1]=LS[u];
			LS[t]=LF[t]-val;

			}

		else
		{
			if(t=o-1)
				{	LS[t]=LF[t]-D[t];
					LF[t+1]=LS[t];
				}

			else
				{	LS[t]=LF[t]-D[A[t]];
					LF[t+1]=LS[t];
				}
		 }
--o;

LS[t]=LF[t]-val;
}

for(q=1;q<n+1;q++)   //showing total float value
{
	F[q]=LS[q]-ES[q];

	cout<<"EST of Activity "<<q<<"= "<<ES[q]<<endl;
	cout<<"EFT of Activity "<<q<<"= "<<EF[q]<<endl;
	cout<<"LST of Activity "<<q<<"= "<<LS[q]<<endl;
	cout<<"LFT of Activity "<<q<<"= "<<LF[q]<<endl;
	cout<<endl;

	cout<<"Total Float of Activity"<<q<<" is"<<F[q]<<endl;
}



cout<<"Critical Path= ";
	for(y=1;y<n+1;y++)        //Obtaining Critical Path
	{
		if(F[y]==0)
		{
			cout<<y<<"- ";
			o+=D[y];
		}
		cout<<endl;
	}
cout<<"Critical Duration="<<o<<" days"<<endl;


Resource Levelling & Smoothing- 

cout<<"Type of Operation-"<<endl;    //Menu of Operations
cout<<"1. Resource Levelling"<<endl;
cout<<"2. Resource Smoothing"<<endl;
cin>>a;

switch(a)             //Choice Operation
{
case 1:

cout<<"Resource Levelling:";
cout<<"Enter total available resources=";
cin>>r;
for(i=1;i<n+1;i++)
{
cout<<"Enter Resouce required for activity"<<i<<" = ";
cin>>R[i];
}

break;

case 2:
cout<<"Resource Smoothing:"<<endl;
cout<<"Enter total available resources=";
cin>>r;
for(i=1;i<n+1;i++)
{
cout<<"Enter Resource required for activity"<<i<<" = ";
cin>>R[i];
}

break;


default:
cout<<"Undefined Choice!!!";

break;

}


getch();
}
