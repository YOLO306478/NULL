#include <stdio.h> 
#include<iostream>
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




int main()
{

	int type=0;
	int modulus=0;
	int bit=0;
	int row=0;
	int column=0;
	int n=0;
	int bitx=0;
	int bity=0;
	int max=0;
    printf("enter modules:");
    scanf("%d",&modulus);  
	 
	int line[modulus] ;
	printf("enter line:\n");
    for(int x=0;x<modulus;x++)
	{
        scanf("%d",&line[x]);
        printf("\n");
		if(line[x]>n)
			n=line[x];
    }
    max=n;
    while(n!=0)
	{
    	n=n/2;
    	bit++;
	}
    int sequence[max+1][bit];   
	char trigger[max+1][bit];
	char triggerJ[max+1][bit]; 
	char triggerK[max+1][bit];
	int K[modulus];
	for(int x=0;x<modulus;x++)
	{
		K[x]=line[x];
		for(int y=0;y<bit;y++)
		{
			sequence[x][y]=line[x]%2;
			line[x]=line[x]/2;
		}
		printf("\n");
		
	}


	printf("counter type(T=1,JK=2):");
	scanf("%d",&type);
	
	if(bit%2==0)
	{		
		bitx=bit/2;
		bity=bit/2;
		column=pow(2,bity);
		row=pow(2,bitx);

	}	
	else
	{		
		bitx=(bit+1)/2;
		bity=(bit-1)/2;
		column=pow(2,bity);
		row=pow(2,bitx);

	}
	
	char** p1 = GrayCode(bity);
	char** p2 = GrayCode(bitx);
    	printf("\n");
	//==============================================================================================================================================
	
	if(type==1){
		for(int x=0;x<modulus-1;x++){
       		for(int y=0;y<bit;y++){
            	if(sequence[x][y]==0&&sequence[x+1][y]==0){
            	trigger[K[x]][y]='0'; 	
            		
				}
            	else if(sequence[x][y]==0&&sequence[x+1][y]==1){
            	trigger[K[x]][y]='1'; 	
            		
				}
            	else if(sequence[x][y]==1&&sequence[x+1][y]==0){
            	trigger[K[x]][y]='1'; 	
            		
				}
            	else if(sequence[x][y]==1&&sequence[x+1][y]==1){
            	trigger[K[x]][y]='0'; 	
            		
				}
       		}
    	}
    	for(int y=0;y<bit;y++)
		{
        	if(sequence[modulus-1][y]==0&&sequence[0][y]==0){
	    		trigger[K[modulus-1]][y]='0'; 		
			}
        	else if(sequence[modulus-1][y]==0&&sequence[0][y]==1){
            	trigger[K[modulus-1]][y]='1'; 		
			}
        	else if(sequence[modulus-1][y]==1&&sequence[0][y]==0){
            	trigger[K[modulus-1]][y]='1'; 		
			}
        	else if(sequence[modulus-1][y]==1&&sequence[0][y]==1){
        		trigger[K[modulus-1]][y]='0'; 	
			}
		}

		char karnaugh[bit][column][row];
		for(int x=0;x<bit;x++)
		{
			for(int y=0;y<column;y++)
			{
				for(int z=0;z<row;z++)
				{
					int on=0;
    				int g=0;
    				for(int j=bitx; j>0; j--)
    				{
       					if(p2[z][j-1]=='1')
        					g=g+pow(2,bitx-j);
					}
					for(int j=bity; j>0; j--)
    				{
       					if(p1[y][j-1]=='1')
        					g=g+pow(2,bit-j);
					}
					
					for(int i=0;i<modulus;i++)
					{
						if(g==K[i])
							on=1;	
					}
					if(on==1)
					{
						karnaugh[x][y][z]=trigger[g][x];
					}
					else
					{
						karnaugh[x][y][z]='X';
					}
				}
			}

		}
		int T=0;
		for(int x=0;x<bit;x++)
		{
			printf("T%d\n",T);
			T++;
			for(int y=0;y<column;y++)
			{
				for(int z=0;z<row;z++)
				{
					printf("%c",karnaugh[x][y][z]);
				}
				printf("\n");
			}
		}

	}
	
	//================================================================================================================================================
	if(type==2){
		for(int x=0;x<modulus-1;x++){
       		for(int y=0;y<bit;y++){
            	if(sequence[x][y]==0&&sequence[x+1][y]==0)
				{
            		triggerJ[K[x]][y]='0';
					triggerK[K[x]][y]='X';  		
				}
            	else if(sequence[x][y]==0&&sequence[x+1][y]==1)
				{
            		triggerJ[K[x]][y]='1'; 	
            		triggerK[K[x]][y]='X'; 
				}
            	else if(sequence[x][y]==1&&sequence[x+1][y]==0)
				{
            		triggerJ[K[x]][y]='X'; 	
            		triggerK[K[x]][y]='1'; 	
				}
            	else if(sequence[x][y]==1&&sequence[x+1][y]==1)
				{
            		triggerJ[K[x]][y]='X'; 	
            		triggerK[K[x]][y]='0'; 
				}
       		}
    	}
    	for(int y=0;y<bit;y++)
		{
      	    if(sequence[modulus-1][y]==0&&sequence[0][y]==0)
			{
	    		triggerJ[K[modulus-1]][y]='0'; 	
				triggerK[K[modulus-1]][y]='X';	
			}
        	else if(sequence[modulus-1][y]==0&&sequence[0][y]==1)
			{
            	triggerJ[K[modulus-1]][y]='1'; 
				triggerK[K[modulus-1]][y]='X';		
			}
        	else if(sequence[modulus-1][y]==1&&sequence[0][y]==0)
			{
            	triggerJ[K[modulus-1]][y]='X'; 
				triggerK[K[modulus-1]][y]='1';		
			}
        	else if(sequence[modulus-1][y]==1&&sequence[0][y]==1)
			{
        		triggerJ[K[modulus-1]][y]='X'; 	
        		triggerK[K[modulus-1]][y]='0';
			}	
		}
		char karnaughJ[bit][column][row];
		char karnaughK[bit][column][row];
		for(int x=0;x<bit;x++)
		{
			for(int y=0;y<column;y++)
			{
				for(int z=0;z<row;z++)
				{
					int on=0;
    				int g=0;
    				for(int j=bitx; j>0; j--)
    				{
       					if(p2[z][j-1]=='1')
        					g=g+pow(2,bitx-j);
					}
					for(int j=bity; j>0; j--)
    				{
       					if(p1[y][j-1]=='1')
        					g=g+pow(2,bit-j);
					}
					
					for(int i=0;i<modulus;i++)
					{
						if(g==K[i])
							on=1;	
					}
					if(on==1)
					{
						karnaughJ[x][y][z]=triggerJ[g][x];
						karnaughK[x][y][z]=triggerK[g][x];
					}
					else
					{
						karnaughJ[x][y][z]='X';
						karnaughK[x][y][z]='X';
					}
				}
			}
		}
			
		for(int x=0;x<bit;x++)
		{
			printf("J%d\n",x);
			for(int y=0;y<column;y++)
			{
				for(int z=0;z<row;z++)
				{
					printf("%c",karnaughJ[x][y][z]);
				}
				printf("\n");
			}
			printf("\n");
		}
		for(int x=0;x<bit;x++)
		{
			printf("K%d\n",x);
			for(int y=0;y<column;y++)
			{
				for(int z=0;z<row;z++)
				{
					printf("%c",karnaughK[x][y][z]);
				}
				printf("\n");
			}
			printf("\n");
		}	
	}
	

	system("PAUSE");
	return 0;
}







