    
    #include <stdio.h>
    #include <math.h>
    
     
    int main() {
	    long long N,temp;
	     
	    while(scanf("%lld", &N), N){
		    temp = sqrt(N);
		     
		    if(temp*temp == N) 
		    	printf("yes\n");
		    else
		    	printf("no\n");
	    }
    }
