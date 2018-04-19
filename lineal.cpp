#include <iostream>

using namespace std;

int main()
{
	double c=1.0;
	double dx=0.1;
	double dt=0.1;
	double X=2;
	double T=0.5;
	int Nx= X/dx +1;
	int Nt= T/dt +1;
	
	double *utxnew;
	double *utxold;
	utxnew= new double[Nx];
	utxold= new double[Nx];
	
	double x=0;
	
	int i;
	int j;

	
	for(i=0;i<Nx;i++)
	{
		x=i*dx;
		if(x>0.75 && x<=1.25)
		{
			utxold[i]=1;
		}else
		{
			utxold[i]=0;
		}
	}
	for(j=1;j<Nt;j++)
	{
		utxnew[0]=0;
		utxnew[Nx-1]=0;
		for(i=1;i<Nx-1;i++)
		{
			utxnew[i]=utxold[i]-c*dt*(utxold[i]-utxold[i-1])/dx;
		}
		for(i=0;i<Nx;i++)
		{
			utxold[i]=utxnew[i];
		}
	}
	x=0;		
	for(i=0;i<Nx;i++)
		{
			x=i*dx;
			cout<<x<<" "<<utxnew[i]<<endl;
		}
	return 0;
}

