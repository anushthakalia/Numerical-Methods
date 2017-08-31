#include <iostream>
#include <stdlib.h>

using namespace std;

float solve(float** A,float* x1,float* x0,int m,int n,int var){
		float sum=0;
		for(int i=0;i<n;i++){
			if(i==var){
				continue;
			}
			else if(i<var){
				sum=sum+(A[var][i]*x1[i]);
			}
			else{
				sum=sum+(A[var][i]*x0[i]);
			}
		}

		return sum;
}


int gauss_seidal(float** A,float* b,float* x1,float* x0,int m,int n,int count){
		if(count==4){
			return 1;
		}
		else{
			for(int var=0;var<m;var++){
				float sum=solve(A,x1,x0,m,n,var);
				x1[var]=(1/A[var][var])*(b[var]-sum);
				cout<<"the sum of Iteration "<<count<<"is "<<sum<<endl;
				for(int k=0;k<m;k++){
				cout<<"Iteration "<<count<<" value of x["<<k<<"] is :"<<x1[k]<<endl;
				}
			}

			for(int var=0;var<m;var++){
				x0[var]=x1[var];
			}
			count ++;
			gauss_seidal(A,b,x1,x0,m,n,count);
		}

}

int check_convergance(float** A,int m,int n){
	int diagonal=0;
	int sum=0;
	int count=0;
	for(int i=0;i<m;i++){
		diagonal=abs(A[i][i]);
		sum=0;
		for(int j=0;j<n;j++){
			if(i==j){
				continue;
			}
			else{
				sum=sum+abs(A[i][j]);
			}
		}

		if(diagonal>sum){
			count++;
		}
		
	}
	if(count==m){
		return 1;
	}
	else{
		return 0;
	}
}


void printmat(float** A,float* b, int m, int n){
	cout<<"The coefficient matrix is:"<<endl;
	for(int i=0;i<m;i++){
		cout<<"[ ";
		for(int j=0;j<n;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<" ]"<<endl;
	}

	cout<<"The b matrix is:"<<endl;
	for(int i=0;i<m;i++){
		cout<<"["<<b[i]<<"]"<<endl;
	}
}

void print(float* x0,float* x1,int m){
	for(int i=0;i<m;i++){
		cout<<"x0 "<<i<<"is "<<x0[i]<<endl;
	}
}

int main(){

	int m=0;
	int n=0;
	cout<<"Enter the matrix dimensions"<<endl;

	cin>>m>>n;
	int count=0;
	cout<<"Now enter the coefficients of  matrix A"<<endl;
	float **A;
	float* x0;
	x0=new float[m];

	float* x1;
	x1=new float[m];
	A=new float*[m];
	for(int i=0;i<m;i++){
		A[i]=new float[n];
		for(int j=0;j<n;j++){
			cout<<"Enter coefficient of "<<i<<","<<j<<" element: ";
			cin>>A[i][j];
		 }
		}
	cout<<"Now enter the coefficients of matrix b"<<endl;
	float *b;
	b=new float[m];
	for(int i=0;i<m;i++){
		cin>>b[i];
	}

	cout<<"Enter initial approximation"<<endl;
	for(int i=0;i<m;i++){
		cin>>x0[i];
	}

	printmat(A,b,m,n);
	int res=check_convergance(A,m,n);
	if(res==1){
		cout<<"The matrix is strictly diagonally dominant"<<endl;
	}
	else{
		cout<<"The matrix is not strictly diagonally dominant"<<endl;
	}
	
	int result=gauss_seidal(A,b,x1,x0,m,n,count);

}