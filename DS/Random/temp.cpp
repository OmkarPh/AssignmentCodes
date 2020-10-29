#include<iostream>
using namespace std;
int main() {
	int row, col, min, str;
	cin>>row>>col>>min>>str;
	char grid[row][col];
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			cin>>grid[i][j];
	
	bool canPass = true;

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(j!=0)
				str -= 1;
			switch(grid[i][j]){
				case '.':
					str -= 2;
					break;
				case '*':
					str += 5;
					break;
				case '#':
					j = col;
					break;
			}
			if(str<min){
				canPass = false;
				i=row;
				break;
			}
		}
	}
	if(!canPass)
		cout<<"No";
	else
		cout<<"Yes"<<endl<<str;
	
	return 0;
}