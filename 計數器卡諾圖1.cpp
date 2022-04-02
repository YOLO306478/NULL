#include <stdio.h> 
#include<math.h>


char** GrayCode(int n)
{
    int temp = 1;
    for(int i=0; i<n; i++)
        temp*=2;
    char **graycode = new char*[temp];
    for(int i=0; i<temp; i++)
    {
        graycode[i]=new char[n];
    }
    if(n==1)
    {
        graycode[0][0]='0';
        graycode[1][0]='1';
        return graycode;
    }
    char **p = GrayCode(n-1);
    for(int i=0; i<temp/2; i++)
    {
        graycode[i][0]='0';        
        graycode[i+temp/2][0]='1';
        for(int j=1;j<n; j++)
        {
            graycode[i][j]=p[i][j-1];
            graycode[temp-i-1][j]=p[i][j-1];
        }
    }
    return graycode;
}




int main(){
	int type=0;
    int modulus=0;
	int bit=0;
    int row;
    int column;
    int n=0;
    printf("enter modules:");
    scanf("%d",&modulus);  
	 
	int ahh[modulus]; 
	int line[modulus] ;
	printf("enter line:\n");
    for(int x=0;x<modulus;x++){
        scanf("%d",&line[x]);
        printf("\n");
		if(line[x]>n)
			n=line[x];
			ahh[x]=line[x];
    }
    while(n!=0){
    	n=(float)n/2;
    	bit++;
	}
    int sequence[modulus][bit];   
	int trigger[modulus][bit];
	char triggerJ[modulus][bit]; 
	char triggerK[modulus][bit];
	for(int x=0;x<modulus;x++){
		for(int y=0;y<bit;y++){
			sequence[ahh[x]][y]=line[x]%2;
			line[x]=(float)line[x]/2;
		}
	}


	printf("counter type(T=1,JK=2):");
	scanf("%d",&type);
			//gray code
		int m = 1;
    	for(int i=0; i<row; i++)
    	    m*=2;
    	char** p = GrayCode(bit);
    	printf("\n");
	//==============================================================================================================================================
	
	if(type==1){
		for(int x=0;x<modulus-1;x++){
       		for(int y=0;y<bit;y++){
            	if(sequence[ahh[x]][y]==0&&sequence[ahh[x+1]][y]==0){
            	trigger[ahh[x]][y]=0; 	
            		
				}
            	else if(sequence[ahh[x]][y]==0&&sequence[ahh[x+1]][y]==1){
            	trigger[ahh[x]][y]=1; 	
            		
				}
            	else if(sequence[ahh[x]][y]==1&&sequence[ahh[x+1]][y]==0){
            	trigger[ahh[x]][y]=1; 	
            		
				}
            	else if(sequence[ahh[x]][y]==1&&sequence[ahh[x+1]][y]==1){
            	trigger[ahh[x]][y]=0; 	
            		
				}
       		}
    	}
    	for(int y=0;y<bit;y++)
		{
        	if(sequence[ahh[modulus-1]][y]==0&&sequence[ahh[0]][y]==0){
	    		trigger[ahh[modulus-1]][y]=0; 		
			}
        	else if(sequence[ahh[modulus-1]][y]==0&&sequence[ahh[0]][y]==1){
            	trigger[ahh[modulus-1]][y]=1; 		
			}
        	else if(sequence[ahh[modulus-1]][y]==1&&sequence[ahh[0]][y]==0){
            	trigger[ahh[modulus-1]][y]=1; 		
			}
        	else if(sequence[ahh[modulus-1]][y]==1&&sequence[ahh[0]][y]==1){
        		trigger[ahh[modulus-1]][y]=0; 	
			}
		}
		if(bit%2==0){
			column=pow(2,(bit/2));
			row=pow(2,bit/2);
		}	
		else{
			column=pow(2,(bit-1)/2);
			row=pow(2,(bit+1)/2);
		}
		int karnaugh[bit][column][row];
		
		

    	
    	
    	int q=0;
    	int k=0;
		for(int x=0;x<bit;x++)
		{
			for(int y=0;y<column;y++)
			{
				if(q==0){
				for(int z=0;z<row;z++)
				{
				   	int f=bit-1;
    				int g=0;
    				for(int j=0; j<row; j++)
    				{
       					if(p[k][j]=='1')
        					g=g+pow(2,f);
        				f--;
        				
					}
					if(g<modulus)
						karnaugh[x][y][z]=trigger[g][x];
					
					else
						karnaugh[x][y][z]=0;
					k++;
					printf("%d",karnaugh[x][y][z]);
				}
			}
			else if(q==1){
			
					for(int z=row-1;z>-1;z--)
				{
				   	int f=bit-1;
    				int g=0;
    				for(int j=0; j<row; j++)
    				{
       					if(p[k][j]=='1')
        					g=g+pow(2,f);
        				f--;
        				
					}
					if(g<modulus)
						karnaugh[x][y][z]=trigger[g][x];
					
					else
						karnaugh[x][y][z]=0;
					k++;
				}
				for(int z=0;z<row;z++)
					printf("%d",karnaugh[x][y][z]);
		}
		q=!q;
				printf("\n");
			}
			printf("\n");
			k=0;
		}





	}
	//================================================================================================================================================
	if(type==2){
		for(int x=0;x<modulus-1;x++){
       		for(int y=0;y<bit;y++){
            	if(sequence[ahh[x]][y]==0&&sequence[ahh[x+1]][y]==0){
            	triggerJ[ahh[x]][y]='0';
				triggerK[ahh[x]][y]='X';  	
            		
				}
            	else if(sequence[ahh[x]][y]==0&&sequence[ahh[x+1]][y]==1){
            	triggerJ[ahh[x]][y]='1'; 	
            	triggerK[ahh[x]][y]='X'; 
				}
            	else if(sequence[ahh[x]][y]==1&&sequence[ahh[x+1]][y]==0){
            	triggerJ[ahh[x]][y]='X'; 	
            	triggerK[ahh[x]][y]='1'; 	
				}
            	else if(sequence[ahh[x]][y]==1&&sequence[ahh[x+1]][y]==1){
            	triggerJ[ahh[x]][y]='X'; 	
            	triggerK[ahh[x]][y]='0'; 
				}
       		}
    	}
    	for(int y=0;y<bit;y++){
        if(sequence[ahh[modulus-1]][y]==0&&sequence[ahh[0]][y]==0){
	    	triggerJ[ahh[modulus-1]][y]='0'; 	
			triggerK[ahh[modulus-1]][y]='X';	
		}
        else if(sequence[ahh[modulus-1]][y]==0&&sequence[ahh[0]][y]==1){
            triggerJ[ahh[modulus-1]][y]='1'; 
			triggerK[ahh[modulus-1]][y]='X';		
		}
        else if(sequence[ahh[modulus]-1][y]==1&&sequence[ahh[0]][y]==0){
            triggerJ[ahh[modulus-1]][y]='X'; 
			triggerK[ahh[modulus-1]][y]='1';		
		}
        else if(sequence[ahh[modulus]-1][y]==1&&sequence[ahh[0]][y]==1){
        	triggerJ[ahh[modulus-1]][y]='X'; 	
        	triggerK[ahh[modulus-1]][y]='0';
		}	
		}
		
		
		if(bit%2==0)
		{
			column=pow(2,(bit/2));
			row=pow(2,bit/2);
		}	
		else
		{
			column=pow(2,(bit-1)/2);
			row=pow(2,(bit+1)/2);
		}
		char karnaughJ[bit][column][row];
		char karnaughK[bit][column][row];


    	int q=0;
    	int k=0;
		for(int x=0;x<bit;x++)
		{
			printf("J%d\n",x);
			for(int y=0;y<column;y++)
			{
				if(q==0){
				for(int z=0;z<row;z++)
				{
				   	int f=bit-1;
    				int g=0;
    				for(int j=0; j<row; j++)
    				{
       					if(p[k][j]=='1')
        					g=g+pow(2,f);
        				f--;
        				
					}
					if(g<modulus){
						karnaughJ[x][y][z]=triggerJ[g][x];
						karnaughK[x][y][z]=triggerK[g][x];
					}
					
					else{
						karnaughJ[x][y][z]='0';
						karnaughK[x][y][z]='0';
					}
					k++;
					printf("%c",karnaughJ[x][y][z]);
				}
				q++;
			}
			else if(q==1){
			
					for(int z=row-1;z>-1;z--)
				{
				   	int f=bit-1;
    				int g=0;
    				for(int j=0; j<row; j++)
    				{
       					if(p[k][j]=='1')
        					g=g+pow(2,f);
        				f--;
        				
					}
					if(g<modulus)
					{
						karnaughJ[x][y][z]=triggerJ[g][x];
						karnaughK[x][y][z]=triggerK[g][x];
					}
					else
					{
						karnaughJ[x][y][z]='0';
						karnaughK[x][y][z]='0';
					}
					k++;
				}
				for(int z=0;z<row;z++)
					printf("%c",karnaughJ[x][y][z]);
				q--;
		}
				
				printf("\n");
			}
			printf("\n");
			k=0;
		}		
		for(int x=0;x<bit;x++){
			printf("K%d\n",x);
			for(int y=0;y<column;y++){
				for(int z=0;z<row;z++){
					printf("%c",karnaughK[x][y][z]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	
	
	

	return 0;
}







