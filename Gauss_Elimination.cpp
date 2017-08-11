#include<iostream>
using namespace std;

int pivot(float **mat,int iter,int m){
	// This function returns the pivot element
	int max=mat[iter][iter];
	int index=iter;
	for(int i=iter;i<m;i++){
		if(max<mat[i][iter]){
			max=mat[i][iter];
			index=i;
		}
	}
	return index;
}

void print_mat(float **mat,int m,int n){
	// This function prints the matrix
	for(int i=0;i<m;i++){
		cout<<"[";
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<"]"<<endl;
	}
	cout<<endl;
}

int main(){
	int m=0;
	int n=0;
	cout<<"Enter the matrix dimensions"<<endl;

	cin>>m>>n;

	cout<<"Now enter the coefficients of augmented matrix."<<endl;
	float **mat;
	mat=new float*[m];
	for(int i=0;i<m;i++){
		mat[i]=new float[n];
		for(int j=0;j<n;j++){
			cout<<"Enter coefficient of "<<i<<","<<j<<" element: ";
			cin>>mat[i][j];
		 }
		}

	cout<<"The matrix that you have entered is:"<<endl;
	print_mat(mat,m,n);
	// finding pivot and exchanging its row
		int piv=0;
		for(int col_iter=0;col_iter<n-2;col_iter++){
			piv=pivot(mat,col_iter,m); //passing the matrix along with column number and number of rows
			cout<<"pivot is "<<piv<<" of "<<col_iter<<"."<<endl;
			if(piv!=col_iter){
			// then exchange the pivot row 
				for(int i=0;i<n;i++){
					float c=0;
					c=mat[col_iter][i];
					mat[col_iter][i]=mat[piv][i];
					mat[piv][i]=c;
				}

			}
			
			// making elemnents zero
			for(int j=col_iter+1;j<m;j++){

				float fpiv=mat[col_iter][col_iter];

				float below=mat[j][col_iter];
				
				
				for(int k=0;k<n;k++){
					if(mat[j][k]==0 && mat[col_iter][k]==0){
						continue;
					}
					mat[j][k]=mat[j][k]-below*(mat[col_iter][k]/fpiv);

				} 

			}
			cout<<"The matrix after making elements under the pivot element to zero is: "<<endl;
			print_mat(mat,m,n);

		}


		cout<<"The final upper triangular matrix is : "<<endl;
		print_mat(mat,m,n);
		// Backsubstitution

		cout<<endl;
		cout<<"Starting Backsubstitution"<<endl;
       float x[m];
       for(int i=n-2;i>=0;i--){
       		float sum=mat[i][n-1]; // last element of the row

       		for(int j=m-1;j>=i;j--){
       			 if(j==i){
       			 	sum=(sum/mat[i][j]);
       			 }
       			 else{
       			 sum=sum-(x[j])*(mat[i][j]);
       			}

       		}

       		x[i]=sum;

       }
       cout<<"The variables obtained are: "<<endl;
       for(int i=0;i<m;i++){
       	cout<<"x"<<i<<" is:"<<x[i]<<endl;
       }

}