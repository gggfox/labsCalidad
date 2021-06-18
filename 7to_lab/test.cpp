//Gauss Jordan Method C++ code
//wikkihut.com

#include<iostream>
#include<iomanip>
#include<cmath>
#define N 4
	using namespace std;

int main()
{
	float Matrix[N][N+1],x[N];
		// Matrix = Augumented Matrix [Ad]
	float temp;

	//variables for loops
	int i,j,k;

	//Scan values of Matrix.

	cout<<"Enter Elements of "<<N<<" Rows & "<<N+1<<" Columns\n";
	

	for(i=0; i<N; i++)
	{
		cout<<"\tEnter Row  "<<i+1<<" & Press Enter\n";
		for(j=0; j<N+1; j++)
		cin>>Matrix[i][j];
	}

	 //make above matrix Identity or Diagonal Matrix

	cout<<fixed;
	for(j=0; j<N; j++)

		for(i=0; i<N; i++)
		if(i!=j)
		{
			temp=Matrix[i][j]/Matrix[j][j];

			for(k=0; k<N+1; k++)
				Matrix[i][k]-=Matrix[j][k]*temp;
		}


		//print the Diagonal matrix

	cout<<"\n ---------------------------------\n";
	cout<<"\n Diagonal  Matrix is:\n";

	for(i=0; i<N; i++)
	{
		for(j=0; j<N+1; j++)
		cout<<setw(8)<<setprecision(4)<<Matrix[i][j];
		cout<<endl;
	}

	
	cout<<"\n ---------------------------------\n";


	//print values of x,y,z

	cout<<"\n The Solution is:\n";
	for(i=0; i<N; i++)
	 cout<<"x["<<setw(3)<<i+1<<"]="<<setw(7)<<setprecision(4)<<Matrix[i][N]/Matrix[i][i]<<endl;

//wikkihut.com/gauss-jordan-c/
return 0;
}
