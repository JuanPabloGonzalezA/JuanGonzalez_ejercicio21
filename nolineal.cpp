#include <iostream>
#include <math.h>

using namespace std;
double gauss(double mean,double sigma,double x);
int main()
{
	double c=1.0;
	double dx=0.01;
	double dt=0.01;
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
		utxold[i]=gauss(1.0,0.1,x);
	}
	
	for(j=1;j<Nt;j++)
	{
		utxnew[0]=0;
		utxnew[Nx-1]=0;
		for(i=1;i<Nx-1;i++)
		{
			utxnew[i]=utxold[i]-utxold[i]*dt*(utxold[i]-utxold[i-1])/dx;
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
double gauss(double mean,double sigma,double x)
{
	return exp(-pow((x-mean)/sigma,2)/2.0);
}
