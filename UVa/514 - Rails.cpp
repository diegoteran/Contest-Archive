#include <cstdio>
#include <iostream>
using namespace std;

int N,count, maxx, temp;
bool flag, used[1001];

int main() {
	int i,j=1;
	
	while(scanf("%d", &N), N){
		
		while(scanf("%d", &maxx), maxx){
			
			count=1; flag = true;
			
			for(i=1; i<=N; i++)
				used[i] = false;
			used[maxx] = true;
			
			while(count<N){
				
				count++;
				scanf("%d", &temp);
				
				if(temp > maxx){
					maxx=temp;
				}else{
					for(i=maxx; i>temp; i--)
						if(used[i]==false)
							flag = false;
				}
				used[temp]=true;
			}
			cout << (flag == true ? "Yes\n" : "No\n") ;
		}
		cout << "\n";
	}
	
}