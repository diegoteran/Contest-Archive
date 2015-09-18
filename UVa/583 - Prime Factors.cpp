	 #include <cstdio>
	 #include <algorithm>
	 
	 using namespace std;
	 
	 #define MAXN 1000000
	 long long notPrime[MAXN], i, j, n;
	
	int main(){
	        
	        for (i = 4; i < MAXN; i+= 2)
	                 notPrime[i] = 2;
	                 
	        for (i = 3; i*i < MAXN; i+=2)
	                if(!notPrime[i])
	                        for (j = i*i; j < MAXN; j+=i)
	                        		if(!notPrime[j])
	                                	notPrime[j] = i;
	                
	         
	        while (scanf("%lld", &n), n){
	              printf("%lld = ", n);
	               if(n < 0){
	                        printf("-1 x ");
	                        n = -n;
	                 }
	                 while(n>=1000000){
	                 	for(i=2; i < 1000000; i++){
	                 		if(n%i==0){
	                 			printf("%lld x ", i);
	                 			n /= i;
	                 			break;
	                 		}
	                 	}
	                 	if(i >= 1000000)
	                 	break;
	                 }
	                 if(i < 1000000)
	                 while(notPrime[n]){
	                         printf("%lld x ", notPrime[n]);
	                        n = n/notPrime[n];
	              }
	               printf("%lld\n", n);
	       }
	         
	
	  
	 }