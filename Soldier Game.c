#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define SIZEMIN 3
#define SIZEMAX 12
void printTable(int **arr,int rows,int cols);
int move(int **ar,char direction,int steps,int rows,int cols);
int fistAttack(int **arr,int rows,int cols,int dir);
int swordAttack(int **arr,int rows,int cols,int direct);
int axeAttack(int **arr,int rows,int cols,int direction);
int bowAttack(int **arr,int rows,int cols,int direction);
void placeEnemies(int **arr,int rows,int cols,double p);


int main(void)
{
	srand((int)time(NULL));
   int **array,ginomeno,i,j,k,row,col,p,f,q,N,M,difficulty,money=0,z,e,eligible,totalmoney=0,w,t,x,y;
   double d,b;
   char c,input[4];

      do{
         printf("Dwse plithos grammwn gia to tamplo: ");
	 scanf("%d",&N);
	}while(N<SIZEMIN || N>SIZEMAX);
      do{
	 printf("Dwse plithos sthlwn gia to tamplo: ");
	 scanf("%d",&M);
	}while(M<SIZEMIN || M>SIZEMAX);
	do{
		printf("Dwse epipedo dyskolias gia thn pista: ");
		scanf("%d",&difficulty);
	}while(difficulty!=1 && difficulty!=2 && difficulty!=3);
  
    //memory allocation
    array=(int**)malloc(N*sizeof(int*));
    if(array==NULL){
			printf("MALLOC ERROR PROGRAM IS ABOUT TO EXIT");
			exit(0);
	}
		
    for(i=0 ; i<N ; i++){
	    array[i]=(int*)malloc(M*sizeof(int));
		if(array[i]==NULL){
			printf("MALLOC ERROR PROGRAM IS ABOUT TO EXIT");
			exit(0);
		}	
	}   
 
	for(i=0 ; i<N ; i++){        
       for(j=0 ; j<M ; j++){
          array[i][j]='.'; 
     }
   }
	switch(difficulty){
		case 1:
			//generates obstacles and places them somewhere in random
    		for(i=0 ; i<round(0.05*N*M) ; i++){  
    			ginomeno=0.05*M*N;
    			//printf("%d\n",ginomeno);
    			row=rand() % N;
      			col=rand() % M;
      			array[row][col]='#';
			}
                       t=round(0.05*N*M);
                        placeEnemies(array,N,M,t);
			//generates enemies and places them somewhere in random
/*
			for(i=0 ; i<round(0.05*N*M) ; i++){
    			do{
    				row=rand() % N;
    				col=rand() % M;
    				d = (double) rand() /  ( (double) RAND_MAX + 1);
    				d= d*3+1;
    				k=(int)d;			
				}while(array[row][col]=='#');
			array[row][col]=k;
			}
*/
			break;
		case 2:
			for(i=0 ; i<round(0.05*N*M) ; i++){  
    			row=rand() % N;
      			col=rand() % M;
      			array[row][col]='#';
			}
                       y=round(0.1*N*M);
                       placeEnemies(array,N,M,y);
/*	
			for(i=0 ; i<round(0.1*N*M); i++){ 
		      do{
    			row=rand() % N;
    			col=rand() % M;
    			d = (double) rand() /  ( (double) RAND_MAX + 1);
    			d= d*3+1;
    			k=(int)d;
                       }while(array[row][col]=='#');
    			array[row][col]=k;
			}
*/
			break;
		case 3:
			for(i=0 ; i<round(0.1*N*M) ; i++){  
    			row=rand() % N;
      			col=rand() % M;
      			array[row][col]='#';
			}	
                      x=round(0.1*N*M);
                        placeEnemies(array,N,M,x);
                  /*
			for(i=0 ; i<round(0.1*N*M) ; i++){
 		     do{
    			row=rand() % N;
    			col=rand() % M;
    			d = (double) rand() /  ( (double) RAND_MAX + 1);
    			d= d*3+1;
    			k=(int)d;
  			 }while(array[row][col]=='#');
    			array[row][col]=k;
			}
*/
			break;	
	}  
do{
   row=rand() % N;
   col=rand() % M;
   array[row][col]='$';
}while(array[row][col]=='#' || array[row][col]==1 || array[row][col]==2 || array[row][col]==3);

	

   do{
   	eligible=0;
   	printTable(array,N,M);

   	do{
	fgets(input,4,stdin);
    if(input[0]=='X' || input[0]=='x'){
		printf("\nthanks for playing!!!\n");
        return 0;
    } 
	}while(input[0]!='U' && input[0]!='u' && input[0]!='D' && input[0]!='d' && input[0]!='R' && input[0]!='r' && input[0]!='L' && input[0]!='l' && input[0]!='X' && input[0]!='x' && input[0]!='F' && input[0]!='f' && input[0]!='S' && input[0]!='s' && input[0]!='A' && input[0]!='a' && input[0]!='B' && input[0]!='b');   
    if(input[0]=='U' || input[0]=='u' || input[0]=='D' || input[0]=='d' || input[0]=='R' || input[0]=='r' || input[0]=='L' || input[0]=='l'){
    	
      	q=input[1]-48;
      	z=input[2]-48;
      	if(q<1 || q>9 || (z>=0 && z<=9)){
      		printf("lathos move xanadwse\n");
		}
       else{
   w=move(array,input[0],q,N,M);
  if(w!=0)
    f=w;
    if(w!=0 && f>=1 && f<=4){
		money+=5*q;	
		totalmoney+=5*q;
     }
  }
 }
  if(input[0]=='F' || input[0]=='f'){
     eligible=fistAttack(array,N,M,f);
     if(eligible==1){
     	money+=50;
     	totalmoney+=50;
	 }
  }
  if(input[0]=='S' || input[0]=='s'){
    eligible=swordAttack(array,N,M,f);
    if(eligible==1){
     	money+=80;
     	totalmoney+=80;
	 }
  }
  if(input[0]=='A' || input[0]=='a'){  
	eligible=axeAttack(array,N,M,f);
	if(eligible==1){
     	money+=70;
     	totalmoney+=70;
	 }	
	}
  if(input[0]=='B' || input[0]=='b'){
	eligible=bowAttack(array,N,M,f);
	if(eligible==1){
     	money+=60;
     	totalmoney+=60;
	 }
	}
	
		
				
	
	printf("\nYour total money spent is:%d\n",totalmoney);
   printf("\nYour money is %d\n",money);
  
  e=0;

 for(i=0 ; i<N ; i++){
   for(j=0; j<M ; j++){
      if(array[i][j]==1 || array[i][j]==2 || array[i][j]==3 )
         e++;
    }
  }

  if(e==0)
  {
	money=0;
     for(i=0 ; i<N ; i++)
        free(array[i]);

    free(array);
       
	N++;
	M++;
       //memory allocation
    array=(int**)malloc(N*sizeof(int*));
    if(array==NULL){
			printf("MALLOC ERROR PROGRAM IS ABOUT TO EXIT");
			exit(0);
	}
		
    for(i=0 ; i<N ; i++){
	    array[i]=(int*)malloc(M*sizeof(int));
		if(array[i]==NULL){
			printf("MALLOC ERROR PROGRAM IS ABOUT TO EXIT");
			exit(0);
		}	
	}   


           for(i=0 ; i<N ; i++){        
       for(j=0 ; j<M ; j++){
          array[i][j]='.'; 
     }
   }
	switch(difficulty){
		case 1:
			//generates obstacles and places them somewhere in random
    		for(i=0 ; i<0.05*N*M ; i++){  
    			ginomeno=0.05*M*N;
    			//printf("%d\n",ginomeno);
    			row=rand() % N;
      			col=rand() % M;
      			array[row][col]='#';
			}	
                           t=round(0.05*N*M);
                        placeEnemies(array,N,M,t);
			//generates enemies and places them somewhere in random
		/*	for(i=0 ; i<0.05*N*M ; i++){
    			do{
    				row=rand() % N;
    				col=rand() % M;
    				d = (double) rand() /  ( (double) RAND_MAX + 1);
    				d= d*3+1;
    				k=(int)d;			
				}while(array[row][col]=='#');
			array[row][col]=k;
			}
*/
			break;
		case 2:
			for(i=0 ; i<0.05*N*M ; i++){  
    			row=rand() % N;
      			col=rand() % M;
      			array[row][col]='#';
			}	
                           y=round(0.1*N*M);
                       placeEnemies(array,N,M,y);
/*
			for(i=0 ; i<0.1*N*M ; i++){
                    do{
    			row=rand() % N;
    			col=rand() % M;
    			d = (double) rand() /  ( (double) RAND_MAX + 1);
    			d= d*3+1;
    			k=(int)d;
                      }while(array[row][col]=='#');
    			array[row][col]=k;
			}
  */
			break;
		case 3:
			for(i=0 ; i<0.1*N*M ; i++){  
    			row=rand() % N;
      			col=rand() % M;
      			array[row][col]='#';
			}	

                      x=round(0.1*N*M);
                        placeEnemies(array,N,M,x);
/*
			for(i=0 ; i<0.1*N*M ; i++){
                    do{
    			row=rand() % N;
    			col=rand() % M;
    			d = (double) rand() /  ( (double) RAND_MAX + 1);
    			d= d*3+1;
    			k=(int)d;
                         }while(array[row][col]=='#');
    			array[row][col]=k;
			}
*/
			break;	
	} 
do{
   row=rand() % N;
   col=rand() % M;
   array[row][col]='$';
}while(array[row][col]=='#' || array[row][col]==1 || array[row][col]==2 || array[row][col]==3);


    printf("Level up\n");
    
   money=0;
   

}


}while(N<=SIZEMAX && M<=SIZEMAX);

 for(i=0; i<N ; i++)
  free(array[i]);

 free(array);

  printf("Congratulations you beat the game");

return 0;

}


void printTable(int **arr,int rows,int cols)
{
    int i,j;
          printf("   ");
	for(i=0 ; i<cols ; i++)
            if(i>9)
              printf("%d",i+1);
           else
		printf(" %d",i+1);

	        printf("\n");
	for(i=0; i<(2*cols+4); i++)
		printf("-");
	        printf("\n");
	   for(i=0 ; i<rows ; i++){
              if(i>8)
              printf("%d| ",i+1);
             else
		printf("%d | ",i+1);
	for(j=0 ; j<cols ; j++){
             if(arr[i][j]==1 || arr[i][j]==2 || arr[i][j]==3)
                    printf("%d ",arr[i][j]);
                 else
                     printf("%c ",arr[i][j]);	
	      }
 	         printf("\n");
	        }
	printf("\n");




}


int move(int **ar,char direction,int steps,int rows,int cols)
{
  int i,j,k,m,s,x,e,y,h;


     for(i=0 ; i<rows ; i++){       /* briskw thn thesi tou $ */
       for(j=0 ; j<cols ; j++){
             if(ar[i][j]=='$'){
                 k=i;
                 m=j;
               }        
 	  }
       }
 
   


  if(direction =='U' || direction =='u'){          /*up*/
    

    if(k-steps<0){

  
       for(i=1 ; i<=k ; i++){
          if(ar[k-i][m]=='#' || ar[k-i][m]==1 || ar[k-i][m]==2 || ar[k-i][m]==3){
               printf("yparxei empodio\n"); 
               return 0;
              }
         }

      h=k;
      e=steps-k-1;
      k=rows-1;

      for(j=0 ; j<=e ; j++){
        if(ar[k-j][m]=='#' || ar[k-j][m]==1 || ar[k-j][m]==2 || ar[k-j][m]==3){
              printf("yparxei empodio\n");
              return 0;
            }
        }

        ar[h][m]='.';
        ar[k-e][m]='$';
         return 1;
}


  else{
    for(i=1 ; i<=steps ; i++){               
        if(ar[k-i][m]=='#' || ar[k-i][m]==1 || ar[k-i][m]==2 || ar[k-i][m]==3){   
              printf("Yparxei empodio\n");
                return 0;
          }
      }

  
     ar[k][m]='.';
     ar[k-steps][m]='$';
      return 1;
   }

}


  if(direction =='R' || direction =='r'){         /*right*/


      
      if(m+steps>cols-1){

  
       for(i=1 ; i<=(cols-1)-m ; i++){
          if(ar[k][m+i]=='#' || ar[k][m+i]==1 || ar[k][m+i]==2 || ar[k][m+i]==3){
               printf("yparxei empodio\n"); 
               return 0;
              }
         }

      h=m;
      e=steps-((cols-1)-m)-1;
      m=0;

      for(j=0 ; j<=e ; j++){
        if(ar[k][m+j]=='#' || ar[k][m+j]==1 || ar[k][m+j]==2 || ar[k][m+j]==3){
              printf("yparxei empodio\n");
              return 0;
            }
        }

        ar[k][h]='.';
        ar[k][m+e]='$';
         return 2;
}

    



 else{
      for(i=1 ; i<=steps ; i++){
        if(ar[k][m+i]=='#' || ar[k][m+i]==1 || ar[k][m+i]==2 || ar[k][m+i]==3){
           printf("yparxei empodio\n");
             return 0;
     }
  }

 
    
    ar[k][m]='.';
    ar[k][m+steps]='$';
    return 2;

  }

}


    if(direction =='L' || direction =='l'){      /*left*/

  
     if(m-steps<0){

  
       for(i=1 ; i<=m ; i++){
          if(ar[k][m-i]=='#' || ar[k][m-i]==1 || ar[k][m-i]==2 || ar[k][m-i]==3){
               printf("yparxei empodio\n"); 
               return 0;
              }
         }

      h=m;
      e=steps-m-1;
      m=cols-1;

      for(j=0 ; j<=e ; j++){
        if(ar[k][m-j]=='#' || ar[k][m-j]==1 || ar[k][m-j]==2 || ar[k][m-j]==3){
              printf("yparxei empodio\n");
              return 0;
            }
        }

        ar[k][h]='.';
        ar[k][m-e]='$';
         return 4;
}
    



   else{
 
     for(i=1 ; i<=steps ; i++){
       if(ar[k][m-i]=='#' || ar[k][m-i]==1 || ar[k][m-i]==2 || ar[k][m-i]==3){
          printf("yparxei empodio\n");
             return 0;
     }
  }

  
       ar[k][m]='.';
       ar[k][m-steps]='$';
       return 4;
  }
    
}


  if(direction =='D' || direction =='d'){   /*down*/

   
      if(k+steps>rows-1){

  
       for(i=1 ; i<=(rows-1)-k ; i++){
          if(ar[k+i][m]=='#' || ar[k+i][m]==1 || ar[k+i][m]==2 || ar[k+i][m]==3){
               printf("yparxei empodio\n"); 
               return 0;
              }
         }

      h=k;
      e=steps-(rows-1-k)-1;
      k=0;

      for(j=0 ; j<=e ; j++){
        if(ar[k+j][m]=='#' || ar[k+j][m]==1 || ar[k+j][m]==2 || ar[k+j][m]==3){
              printf("yparxei empodio\n");
              return 0;
            }
        }

        ar[h][m]='.';
        ar[k+e][m]='$';
         return 3;
}

  
  else {
   
     for(i=1 ; i<=steps ; i++){
        if(ar[k+i][m]=='#' || ar[k+i][m]==1 || ar[k+i][m]==2 || ar[k+i][m]==3){         
          printf("yparxei empodio\n");
             return 0 ;
     }
  }


    
      ar[k][m]='.';
      ar[k+steps][m]='$';
       return 3;

    }

}


}


int bowAttack(int **arr,int rows,int cols,int dir){
	int k,i,j,m;
	for(i=0 ; i<rows ; i++){       /* briskw thn thesi tou $ */
       for(j=0 ; j<cols ; j++){
            if(arr[i][j]=='$'){
                k=i;
                m=j;
            }        
 	  	}
    }	
	if(dir==1){//koitaei panw
		if(k-1<0 || k-2<0 || ((k-1>=0 && k-2>=0) && (arr[k-2][m]=='.' || arr[k-2][m]=='#'))){
			printf("de xrewnesai gia kati ekanes airball\n");
			return 0;
		}
		if(k-1>=0 && k-2>=0){
			if(arr[k-2][m]==1 && (arr[k-1][m]=='.' || arr[k-1][m]=='#' || arr[k-1][m]==1 || arr[k-1][m]==2 || arr[k-1][m]==3)){
				arr[k-2][m]='.';
			}
			else if(arr[k-2][m]==2 && (arr[k-1][m]=='.' || arr[k-1][m]=='#' || arr[k-1][m]==1 || arr[k-1][m]==2 || arr[k-1][m]==3)){
				if(k-3<0 || arr[k-3][m]=='#' || arr[k-3][m]==1 || arr[k-3][m]==2 || arr[k-3][m]==3){
					arr[k-2][m]=1;
				}
				else{
					arr[k-2][m]='.';
					arr[k-3][m]=1;
				}
			}
			else if(arr[k-2][m]==3 && (arr[k-1][m]=='.' || arr[k-1][m]=='#' || arr[k-1][m]==1 || arr[k-1][m]==2 || arr[k-1][m]==3)){
				if(k-3<0 || arr[k-3][m]=='#' || arr[k-3][m]==1 || arr[k-3][m]==2 || arr[k-3][m]==3){
					arr[k-2][m]=2;
				}
				else{
					arr[k-2][m]='.';
					arr[k-3][m]=2;
				}	
			}	
		}
	}
	if(dir==3){//koitaei katw
		if(k+1>rows-1 || k+2>rows-1 || ((k+1<=rows-1 && k+2<=rows-1) && (arr[k+2][m]=='.' || arr[k+2][m]=='#'))){
			printf("de xrewnesai gia kati ekanes airball\n");
			return 0;
		}
		if(k+1<=rows-1 && k+2<=rows-1){
			if(arr[k+2][m]==1 && (arr[k+1][m]=='.' || arr[k+1][m]=='#' || arr[k+1][m]==1 || arr[k+1][m]==2 || arr[k+1][m]==3)){
				arr[k+2][m]='.';
			}
			else if(arr[k+2][m]==2 && (arr[k+1][m]=='.' || arr[k+1][m]=='#' || arr[k+1][m]==1 || arr[k+1][m]==2 || arr[k+1][m]==3)){
				if(k+3>rows-1 || arr[k+3][m]=='#' || arr[k+3][m]==1 || arr[k+3][m]==2 || arr[k+3][m]==3){
					arr[k+2][m]=1;
				}
				else{
					arr[k+2][m]='.';
					arr[k+3][m]=1;
				}
			}
			else if(arr[k+2][m]==3 && (arr[k+1][m]=='.' || arr[k+1][m]=='#' || arr[k+1][m]==1 || arr[k+1][m]==2 || arr[k+1][m]==3)){
				if(k+3>rows-1 || arr[k+3][m]=='#' || arr[k+3][m]==1 || arr[k+3][m]==2 || arr[k+3][m]==3){
					arr[k+2][m]=2;
				}
				else{
					arr[k+2][m]='.';
					arr[k+3][m]=2;
				}	
			}	
		}
	}
	if(dir==4){//koitaei aristera
		if(m-1<0 || m-2<0 || ((m-1>=0 && m-2>=0) && (arr[k][m-2]=='.' || arr[k][m-2]=='#'))){
			printf("de xrewnesai gia kati ekanes airball\n");
			return 0;
		}
		if(m-1>=0 && m-2>=0){
			if(arr[k][m-2]==1 && (arr[k][m-1]=='.' || arr[k][m-1]=='#' || arr[k][m-1]==1 || arr[k][m-1]==2 || arr[k][m-1]==3)){
				arr[k][m-2]='.';
			}
			else if(arr[k][m-2]==2 && (arr[k][m-1]=='.' || arr[k][m-1]=='#' || arr[k][m-1]==1 || arr[k][m-1]==2 || arr[k][m-1]==3)){
				if(m-3<0 || arr[k][m-3]=='#' || arr[k][m-3]==1 || arr[k][m-3]==2 || arr[k][m-3]==3){
					arr[k][m-2]=1;
				}
				else{
					arr[k][m-2]='.';
					arr[k][m-3]=1;
				}
			}
			else if(arr[k][m-2]==3 && (arr[k][m-1]=='.' || arr[k][m-1]=='#' || arr[k][m-1]==1 || arr[k][m-1]==2 || arr[k][m-1]==3)){
				if(m-3<0 || arr[k][m-3]=='#' || arr[k][m-3]==1 || arr[k][m-3]==2 || arr[k][m-3]==3){
					arr[k][m-2]=2;
				}
				else{
					arr[k][m-2]='.';
					arr[k][m-3]=2;
				}	
			}	
		}
	}
	if(dir==2){//koitaei dexia
		if(m+1>cols-1 || m+2>cols-1 || ((m+1<=cols-1 && m+2<=cols-1) && (arr[k][m+2]=='.' || arr[k][m+2]=='#'))){
			printf("de xrewnesai gia kati ekanes airball\n");
			return 0;
		}
		if(m+1<=cols-1 && m+2<=cols-1){
			if(arr[k][m+2]==1 && (arr[k][m+1]=='.' || arr[k][m+1]=='#' || arr[k][m+1]==1 || arr[k][m+1]==2 || arr[k][m+1]==3)){
				arr[k][m+2]='.';
			}
			else if(arr[k][m+2]==2 && (arr[k][m+1]=='.' || arr[k][m+1]=='#' || arr[k][m+1]==1 || arr[k][m+1]==2 || arr[k][m+1]==3)){
				if(m+3>cols-1 || arr[k][m+3]=='#' || arr[k][m+3]==1 || arr[k][m+3]==2 || arr[k][m+3]==3){
					arr[k][m+2]=1;
				}
				else{
					arr[k][m+2]='.';
					arr[k][m+3]=1;
				}
			}
			else if(arr[k][m+2]==3 && (arr[k][m+1]=='.' || arr[k][m+1]=='#' || arr[k][m+1]==1 || arr[k][m+1]==2 || arr[k][m+1]==3)){
				if(m+3>cols-1 || arr[k][m+3]=='#' || arr[k][m+3]==1 || arr[k][m+3]==2 || arr[k][m+3]==3){
					arr[k][m+2]=2;
				}
				else{
					arr[k][m+2]='.';
					arr[k][m+3]=2;
				}	
			}	
		}
	}
	return 1;		
}


int axeAttack(int **arr,int rows,int cols,int dir){
	int k,i,j,m;
	for(i=0 ; i<rows ; i++){       /* briskw thn thesi tou $ */
       for(j=0 ; j<cols ; j++){
            if(arr[i][j]=='$'){
                k=i;
                m=j;
            }        
 	  	}
    }
    
   

    if(dir==1){//koitaei panw
    
    	if( k-1<0 || (k-2<0 && (arr[k-1][m]=='.' || arr[k-1][m]=='#')) || ((k-1>=0 && k-2>=0) && (arr[k-1][m]=='.' || arr[k-1][m]=='#') && (arr[k-2][m]=='.' || arr[k-2][m]=='#'))){
			printf("de kanei tipota de xrewnesai gia airball\n");
			return 0;
		}
  
   if(k-1>=0 && k-2>=0 && (arr[k-1][m]==1 || arr[k-1][m]==2 || arr[k-1][m]==3) && (arr[k-2][m]==1 || arr[k-2][m]==2 || arr[k-2][m]==3))
     {



		if(k-1>=0 && k-2>=0 && arr[k-1][m]==1 && arr[k-2][m]==1){//an einai kai ta duo ena tote feygoun
			arr[k-1][m]='.';
			arr[k-2][m]='.';
		}
		
		if(k-1>=0 && k-2>=0 && arr[k-1][m]==1 && arr[k-2][m]==2){
			arr[k-1][m]='.';
			if(k-3<0 || arr[k-3][m]=='#' || arr[k-3][m]==1 || arr[k-3][m]==2 || arr[k-3][m]==3){//an exei toixo h empodio
				arr[k-2][m]=1;
			}
			else {
				arr[k-3][m]=1;
				arr[k-2][m]='.';
			}		
		}
		if(k-1>=0 && k-2>=0 && arr[k-1][m]==2 && arr[k-2][m]==1){
			arr[k-1][m]='.';
			arr[k-2][m]=1;
		}
		if(k-1>=0 && k-2>=0 && arr[k-1][m]==1 && arr[k-2][m]==3){
			arr[k-1][m]='.';
			if(k-3<0 || arr[k-3][m]=='#' || arr[k-3][m]==1 || arr[k-3][m]==2 || arr[k-3][m]==3){//an exei toixo h empodio
				arr[k-2][m]=2;
			}
			else{
				arr[k-2][m]='.';
				arr[k-3][m]=2;
			}
		}
		if(k-1>=0 && k-2>=0 && arr[k-1][m]==2 && arr[k-2][m]==2){
			if(k-3<0 || arr[k-3][m]=='#' || arr[k-3][m]==1 || arr[k-3][m]==2 || arr[k-3][m]==3){
				arr[k-1][m]=1;
				arr[k-2][m]=1;
			}
			else{
				
				arr[k-1][m]='.';
                                arr[k-2][m]=1;
                                arr[k-3][m]=1;
			}
		}
		if(k-1>=0 && k-2>=0 && arr[k-1][m]==2 && arr[k-2][m]==3){
			if(k-3<0 || arr[k-3][m]=='#' || arr[k-3][m]==1 || arr[k-3][m]==2 || arr[k-3][m]==3){
				arr[k-1][m]=1;
				arr[k-2][m]=2;
			}
			else{
				arr[k-1][m]='.';
				arr[k-2][m]=1;
				arr[k-3][m]=2;
			}
		}
		if(k-1>=0 && k-2>=0 && arr[k-1][m]==3 && arr[k-2][m]==1){
			arr[k-1][m]='.';
			arr[k-2][m]=2;
		}
		if(k-1>=0 && k-2>=0 && arr[k-1][m]==3 && arr[k-2][m]==2){
			if(k-3<0 || arr[k-3][m]=='#' || arr[k-3][m]==1 || arr[k-3][m]==2 || arr[k-3][m]==3){
				arr[k-1][m]=2;
				arr[k-2][m]=1;
			}
			else{
				arr[k-1][m]='.';
				arr[k-2][m]=2;
				arr[k-3][m]=1;
			}
		}
		if(k-1>=0 && k-2>=0 && arr[k-1][m]==3 && arr[k-2][m]==3){
			if(k-3<0 || arr[k-3][m]=='#' || arr[k-3][m]==1 || arr[k-3][m]==2 || arr[k-3][m]==3){
				arr[k-1][m]=2;
				arr[k-2][m]=2;
			}
			else{
				arr[k-1][m]='.';
				arr[k-2][m]=2;
				arr[k-3][m]=2;
			}				
		}
		
       }
 
     else{
      
		if(k-1>=0 && arr[k-1][m]==1){//1 sto prwto
			arr[k-1][m]='.';
		}
		if(k-1>=0 && k-2>=0 && arr[k-2][m]==1){//1 sto deytero
			arr[k-2][m]='.';
		}
		
		if(k-1>=0 && arr[k-1][m]==2){//2 sto prwto kai meta toixos/empodio
			if(k-2<0 || (k-2>=0 && (arr[k-2][m]=='#' || arr[k-2][m]==1 || arr[k-2][m]==2 || arr[k-2][m]==3))){
				arr[k-1][m]=1;
			}
			else if(k-2>=0 && arr[k-2][m]!='#' && arr[k-2][m]!=1 && arr[k-2][m]!=2 && arr[k-2][m]!=3){
				arr[k-1][m]='.';
				arr[k-2][m]=1;
			}
		}
		if(k-1>=0 && k-2>=0  && arr[k-2][m]==2){//2 sto deytero kai meta oxi/nai empodio/toixos
			if(k-3>=0 && arr[k-3][m]!='#' && arr[k-3][m]!=1 && arr[k-3][m]!=2 && arr[k-3][m]!=3){
				arr[k-2][m]='.';
				arr[k-3][m]=1;
			}
			else if(k-3<0 || (arr[k-3][m]=='#' || arr[k-3][m]==1 || arr[k-3][m]==2 || arr[k-3][m]==3)){
				arr[k-2][m]=1;
			}
		}
		if(k-1>=0 && arr[k-1][m]==3){//3 sto prwto kai meta oxi toixos/empodio
			if(k-2>=0 && arr[k-2][m]!='#' && arr[k-2][m]!=1 && arr[k-2][m]!=2 && arr[k-2][m]!=3){
				arr[k-1][m]='.';
				arr[k-2][m]=2;
			}
			else if(k-2<0 || arr[k-2][m]=='#' ||  ( arr[k-2][m]==1 || arr[k-2][m]==2 || arr[k-2][m]==3)){
				arr[k-1][m]=2;
			}
		} 
		if(k-1>=0 && arr[k-2][m]==3){//3 sto deytero kai meta oxi empodio/toixos 
			if(k-2>=0 && k-3>=0 && arr[k-3][m]!='#' && arr[k-3][m]!=1 && arr[k-3][m]!=2 && arr[k-3][m]!=3){
				arr[k-2][m]='.';
				arr[k-3][m]=2;
			}
			else if(k-2<0 || k-3<0 || (arr[k-3][m]=='#' || arr[k-3][m]==1 || arr[k-3][m]==2 || arr[k-3][m]==3)){
				arr[k-2][m]=2;
			}
		}  

         }

    }
	 
	 
	 
	 
	 
	if(dir==3){//koitaei katw


  if(k+1>rows-1 || (k+2>rows-1 && (arr[k+1][m]=='.' || arr[k+1][m]=='#')) || ((k+1<=rows-1 && k+2<=rows-1) && (arr[k+1][m]=='.' || arr[k+1][m]=='#') && (arr[k+2][m]=='.' || arr[k+2][m]=='#'))){
			printf("de kanei tipota de xrewnesai gia airball\n");
			return 0;
		}



   if(k+1<=rows-1 && k+2<=rows-1 && (arr[k+1][m]==1 || arr[k+1][m]==2 || arr[k+1][m]==3) && (arr[k+2][m]==1 || arr[k+2][m]==2 || arr[k+2][m]==3))

     {

		if(k+1<=rows-1 && k+2<=rows-1 && arr[k+1][m]==1 && arr[k+2][m]==1){//an einai kai ta duo ena tote feygoun
			arr[k+1][m]='.';
			arr[k+2][m]='.';
		}
		
		if(k+1<=rows-1 && k+2<=rows-1 && arr[k+1][m]==1 && arr[k+2][m]==2){
			arr[k+1][m]='.';
			if(k+3>rows-1 || arr[k+3][m]=='#' || (arr[k+3][m]==1 || arr[k+3][m]==2 || arr[k+3][m]==3)){//an exei toixo h empodio
				arr[k+2][m]=1;
			}
			else {
				arr[k+3][m]=1;
				arr[k+2][m]='.';
			}		
		}
		if(k+1<=rows-1 && k+2<=rows-1 && arr[k+1][m]==2 && arr[k+2][m]==1){
			arr[k+1][m]='.';
			arr[k+2][m]=1;
		}
		if(k+1<=rows-1 && k+2<=rows-1 && arr[k+1][m]==1 && arr[k+2][m]==3){
			arr[k+1][m]='.';
			if(k+3>rows-1 || arr[k+3][m]=='#' || (arr[k+3][m]==1 || arr[k+3][m]==2 || arr[k+3][m]==3)){//an exei toixo h empodio
				arr[k+2][m]=2;
			}
			else{
				arr[k+2][m]='.';
				arr[k+3][m]=2;
			}
		}
		if(k+1<=rows-1 && k+2<=rows-1 && arr[k+1][m]==2 && arr[k+2][m]==2){
			if(k+3>rows-1 || arr[k+3][m]=='#' || (arr[k+3][m]==1 || arr[k+3][m]==2 || arr[k+3][m]==3)){
				arr[k+1][m]=1;
				arr[k+2][m]=1;
			}
			else{
				arr[k+3][m]=1;
				arr[k+2][m]=1;
				arr[k+1][m]='.';
			}
		}
		if(k+1<=rows-1 && k+2<=rows-1 && arr[k+1][m]==2 && arr[k+2][m]==3){
			if(k+3>rows-1 || arr[k+3][m]=='#' || (arr[k+3][m]==1 || arr[k+3][m]==2 || arr[k+3][m]==3)){
				arr[k+1][m]=1;
				arr[k+2][m]=2;
			}
			else{
				arr[k+1][m]='.';
				arr[k+2][m]=1;
				arr[k+3][m]=2;
			}
		}
		if(k+1<=rows-1 && k+2<=rows-1 && arr[k+1][m]==3 && arr[k+2][m]==1){
			arr[k+1][m]='.';
			arr[k+2][m]=2;
		}
		if(k+1<=rows-1 && k+2<=rows-1 && arr[k+1][m]==3 && arr[k+2][m]==2){
			if(k+3>rows-1 || arr[k+3][m]=='#' || (arr[k+3][m]==1 || arr[k+3][m]==2 || arr[k+3][m]==3)){
				arr[k+1][m]=2;
				arr[k+2][m]=1;
			}
			else{
				arr[k+1][m]='.';
				arr[k+2][m]=2;
				arr[k+3][m]=1;
			}
		}
		if(k+1<=rows-1 && k+2<=rows-1 && arr[k+1][m]==3 && arr[k+2][m]==3){
			if(k+3>rows-1 || arr[k+3][m]=='#' || (arr[k+3][m]==1 || arr[k+3][m]==2 || arr[k+3][m]==3)){
				arr[k+1][m]=2;
				arr[k+2][m]=2;
			}
			else{
				arr[k+1][m]='.';
				arr[k+2][m]=2;
				arr[k+3][m]=2;
			}				
		}
		
	}

    	
	else{	
		
		if(k+1<=rows-1 && arr[k+1][m]==1){//1 sto prwto
			arr[k+1][m]='.';
		}
		if(k+1<=rows-1 && k+2<=rows-1 && arr[k+2][m]==1){//1 sto deytero
			arr[k+2][m]='.';
		}
		
		if(k+1<=rows-1 && arr[k+1][m]==2){//2 sto prwto kai meta toixos/empodio
			if(k+2>rows-1  || arr[k+2][m]=='#' || (arr[k+2][m]==1 || arr[k+2][m]==2 || arr[k+2][m]==3)){
				arr[k+1][m]=1;
			}
			else if(k+2<=rows-1 && arr[k+2][m]!='#' && arr[k+2][m]!=1 && arr[k+2][m]!=2 && arr[k+2][m]!=3){
				arr[k+1][m]='.';
				arr[k+2][m]=1;
			}
		}
		if(k+1<=rows-1 && k+2<=rows-1  && arr[k+2][m]==2){//2 sto deytero kai meta oxi/nai empodio/toixos
			if(k+3<=rows-1 && arr[k+3][m]!='#' && arr[k+3][m]!=1 && arr[k+3][m]!=2 && arr[k+3][m]!=3){
				arr[k+2][m]='.';
				arr[k+3][m]=1;
			}
			else if(k+3>rows-1 || arr[k+3][m]=='#' || (arr[k+2][m]==1 || arr[k+2][m]==2 || arr[k+2][m]==3)){
				arr[k+2][m]=1;
			}
		}
		if(k+1<=rows-1 && arr[k+1][m]==3){//3 sto prwto kai meta oxi toixos/empodio
			if(k+2<=rows-1 && arr[k+2][m]!='#' && arr[k+2][m]!=1 && arr[k+2][m]!=2 && arr[k+2][m]!=3){
				arr[k+1][m]='.';
				arr[k+2][m]=2;
			}
			else if(k+2>rows-1 || arr[k+2][m]=='#' || (arr[k+2][m]==1 || arr[k+2][m]==2 || arr[k+2][m]==3)){
				arr[k+1][m]=2;
			}
		} 
		if(k+1<=rows-1 && arr[k+2][m]==3){//3 sto deytero kai meta oxi empodio/toixos 
			if(k+2<=rows-1 && k+3<=rows-1 && arr[k+3][m]!='#' && arr[k+3][m]!=1 && arr[k+3][m]!=2 && arr[k+3][m]!=3){
				arr[k+2][m]='.';
				arr[k+3][m]=2;
			}
			else if(k+2>rows-1 || k+3<rows-1 || arr[k+3][m]=='#' || (arr[k+2][m]==1 || arr[k+2][m]==2 || arr[k+2][m]==3)){
				arr[k+2][m]=2;
			}
		}  
           }
           
	}
		
	
	
	if(dir==2){//dexia
 if(m+1>cols-1 || (m+2>cols-1 && (arr[k][m+1]=='.' || arr[k][m+1]=='#')) || ((m+1<=cols-1 && m+2<=cols-1) && (arr[k][m+1]=='.' || arr[k][m+1]=='#') && (arr[k][m+2]=='.' || arr[k][m+2]=='#'))){
			printf("de kanei tipota de xrewnesai gia airball\n");
			return 0;
		}


     if(m+1<=cols-1 && m+2<=cols-1 && (arr[k][m+1]==1 || arr[k][m+1]==2 || arr[k][m+1]==3) && (arr[k][m+2]==1 || arr[k][m+2]==2 || arr[k][m+2]==3))
 
      {

		if(m+1<=cols-1 && m+2<=cols-1 && arr[k][m+1]==1 && arr[k][m+2]==1){
			arr[k][m+1]='.';
			arr[k][m+2]='.';
		}
		if(m+1<=cols-1 && m+2<=cols-1 && arr[k][m+1]==1 && arr[k][m+2]==2){
			arr[k][m+1]='.';
			if(m+3>cols-1 || arr[k][m+3]=='#' || (arr[k][m+3]==1 || arr[k][m+3]==2 || arr[k][m+3]==3)){//an exei toixo h empodio
				arr[k][m+2]=1;
			}
			else {
				arr[k][m+3]=1;
				arr[k][m+2]='.';
			}		
		}
		if(m+1<=cols-1 && m+2<=cols-1 && arr[k][m+1]==2 && arr[k][m+2]==1){
			arr[k][m+1]='.';
			arr[k][m+2]=1;
		}
		if(m+1<=cols-1 && m+2<=cols-1 && arr[k][m+1]==1 && arr[k][m+2]==3){
			arr[k][m+1]='.';
			if(m+3>cols-1 || arr[k][m+3]=='#' || (arr[k][m+3]==1 || arr[k][m+3]==2 || arr[k][m+3]==3)){//an exei toixo h empodio
				arr[k][m+2]=2;
			}
			else{
				arr[k][m+2]='.';
				arr[k][m+3]=2;
			}
		}
		if(m+1<=cols-1 && m+2<=cols-1 && arr[k][m+1]==2 && arr[k][m+2]==2){
			if(m+3>cols-1 || arr[k][m+3]=='#' || (arr[k][m+3]==1 || arr[k][m+3]==2 || arr[k][m+3]==3)){
				arr[k][m+1]=1;
				arr[k][m+2]=1;
			}
			else{
				arr[k][m+3]=1;
				arr[k][m+2]=1;
				arr[k][m+1]='.';
			}
		}
		if(m+1<=cols-1 && m+2<=cols-1 && arr[k][m+1]==2 && arr[k][m+2]==3){
			if(m+3>cols-1 || arr[k][m+3]=='#' || (arr[k][m+3]==1 || arr[k][m+3]==2 || arr[k][m+3]==3)){
				arr[k][m+1]=1;
				arr[k][m+2]=2;
			}
			else{
				arr[k][m+1]='.';
				arr[k][m+2]=1;
				arr[k][m+3]=2;
			}
		}
		if(m+1<=cols-1 && m+2<=cols-1 && arr[k][m+1]==3 && arr[k][m+2]==1){
			arr[k][m+1]='.';
			arr[k][m+2]=2;
		}
		if(m+1<=cols-1 && m+2<=cols-1 && arr[k][m+1]==3 && arr[k][m+2]==2){
			if(m+3>cols-1 || arr[k][m+3]=='#' || (arr[k][m+3]==1 || arr[k][m+3]==2 || arr[k][m+3]==3)){
				arr[k][m+1]=2;
				arr[k][m+2]=1;
			}
			else{
				arr[k][m+1]='.';
				arr[k][m+2]=2;
				arr[k][m+3]=1;
			}
		}
		if(m+1<=cols-1 && m+2<=cols-1 && arr[k][m+1]==3 && arr[k][m+2]==3){
			if(m+3>cols-1 || arr[k][m+3]=='#' || (arr[k][m+3]==1 || arr[k][m+3]==2 || arr[k][m+3]==3)){
				arr[k][m+1]=2;
				arr[k][m+2]=2;
			}
			else{
				arr[k][m+1]='.';
				arr[k][m+2]=2;
				arr[k][m+3]=2;
			}				
		}

         }

    else{

		if(m+1<=cols-1 && arr[k][m+1]==1){//1 sto prwto
			arr[k][m+1]='.';
		}
		if(m+1<=cols-1 && m+2<=cols-1 && arr[k][m+2]==1){//1 sto deytero
			arr[k][m+2]='.';
		}
		if(m+1<=cols-1 && arr[k][m+1]==2){//2 sto prwto kai meta toixos/empodio
			if(m+2>cols-1 || arr[k][m+2]=='#' || (arr[k][m+2]==1 || arr[k][m+2]==2 || arr[k][m+2]==3)){
				arr[k][m+1]=1;
			}
			else if(m+2<=cols-1 && arr[k][m+2]!='#' && arr[k][m+2]!=1 && arr[k][m+2]!=2 && arr[k][m+2]!=3){
				arr[k][m+1]='.';
				arr[k][m+2]=1;
			}
		}
		if(m+1<=cols-1 && m+2<=cols-1  && arr[k][m+2]==2){//2 sto deytero kai meta oxi/nai empodio/toixos
			if(m+3<=cols-1 && arr[k][m+3]!='#' && arr[k][m+3]!=1 && arr[k][m+3]!=2 && arr[k][m+3]!=3){
				arr[k][m+2]='.';
				arr[k][m+3]=1;
			}
			else if(m+3>cols-1 || arr[k][m+3]=='#' || (arr[k][m+3]==1 || arr[k][m+3]==2 || arr[k][m+3]==3)){
				arr[k][m+2]=1;
			}
		}
		if(m+1<=cols-1 && arr[k][m+1]==3){//3 sto prwto kai meta oxi toixos/empodio
			if(m+2<=cols-1 && arr[k][m+2]!='#' && arr[k][m+2]!=1 && arr[k][m+2]!=2 && arr[k][m+2]!=3){
				arr[k][m+1]='.';
				arr[k][m+2]=2;
			}
			else if(m+2>cols-1 || arr[k][m+2]=='#' || (arr[k][m+2]==1 || arr[k][m+2]==2 || arr[k][m+2]==3)){
				arr[k][m+1]=2;
			}
		} 
		if(m+1<=cols-1 && arr[k][m+2]==3){//3 sto deytero kai meta oxi empodio/toixos 
			if(m+2<=cols-1 && m+3<=cols-1 && arr[k][m+3]!='#' && arr[k][m+3]!=1 && arr[k][m+3]!=2 && arr[k][m+3]!=3){
				arr[k][m+2]='.';
				arr[k][m+3]=2;
			}
			else if(m+2>cols-1 || m+3>cols-1 || arr[k][m+3]=='#' || (arr[k][m+3]==1 || arr[k][m+3]==2 || arr[k][m+3]==3)){
				arr[k][m+2]=2;
			}
		}  

            }
	}
	
	
	if(dir==4){//aristera
		if(m-1<0 || (m-2<0 && (arr[k][m-1]=='.' || arr[k][m-1]=='#')) || ((m-1>=0 && m-2>=0) && (arr[k][m-1]=='.' || arr[k][m-1]=='#') && (arr[k][m-2]=='.' || arr[k][m-2]=='#'))){
			printf("de kanei tipota de xrewnesai gia airball\n");
			return 0;
		}


        if(m-1>=0 && m-2>=0 && (arr[k][m-1]==1 || arr[k][m-1]==2 || arr[k][m-1]==3) && (arr[k][m-2]==1 || arr[k][m-2]==2 || arr[k][m-2]==3))
     {

		if(m-1>=0 && m-2>=0 && arr[k][m-1]==1 && arr[k][m-2]==1){
			arr[k][m-1]='.';
			arr[k][m-2]='.';
		}
		if(m-1>=0 && m-2>=0 && arr[k][m-1]==1 && arr[k][m-2]==2){
			arr[k][m-1]='.';
			if(m-3<0 || arr[k][m-3]=='#' || (arr[k][m-3]==1 || arr[k][m-3]==2 || arr[k][m-3]==3)){//an exei toixo h empodio
				arr[k-2][m]=1;
			}
			else {
				arr[k][m-3]=1;
				arr[k][m-2]='.';
			}		
		}
		if(m-1>=0 && m-2>=0 && arr[k][m-1]==2 && arr[k][m-2]==1){
			arr[k][m-1]='.';
			arr[k][m-2]=1;
		}
		if(m-1>=0 && m-2>=0 && arr[k][m-1]==1 && arr[k][m-2]==3){
			arr[k][m-1]='.';
			if(m-3<0 || arr[k][m-3]=='#' || (arr[k][m-3]==1 || arr[k][m-3]==2 || arr[k][m-3]==3)){//an exei toixo h empodio
				arr[k][m-2]=2;
			}
			else{
				arr[k][m-2]='.';
				arr[k][m-3]=2;
			}
		}
		if(m-1>=0 && m-2>=0 && arr[k][m-1]==2 && arr[k][m-2]==2){
			if(m-3<0 || arr[k][m-3]=='#' || (arr[k][m-3]==1 || arr[k][m-3]==2 || arr[k][m-3]==3)){
				arr[k][m-1]=1;
				arr[k][m-2]=1;
			}
			else{
				arr[k][m-3]=1;
				arr[k][m-2]=1;
				arr[k][m-1]='.';
			}
		}
		if(m-1>=0 && m-2>=0 && arr[k][m-1]==2 && arr[k][m-2]==3){
			if(m-3<0 || arr[k][m-3]=='#' || (arr[k][m-3]==1 || arr[k][m-3]==2 || arr[k][m-3]==3)){
				arr[k][m-1]=1;
				arr[k][m-2]=2;
			}
			else{
				arr[k][m-1]='.';
				arr[k][m-2]=1;
				arr[k][m-3]=2;
			}
		}
		if(m-1>=0 && m-2>=0 && arr[k][m-1]==3 && arr[k][m-2]==1){
			arr[k][m-1]='.';
			arr[k][m-2]=2;
		}
		if(m-1>=0 && m-2>=0 && arr[k][m-1]==3 && arr[k][m-2]==2){
			if(m-3<0 || arr[k][m-3]=='#' || (arr[k][m-3]==1 || arr[k][m-3]==2 || arr[k][m-3]==3)){
				arr[k][m-1]=2;
				arr[k][m-2]=1;
			}
			else{
				arr[k][m-1]='.';
				arr[k][m-2]=2;
				arr[k][m-3]=1;
			}
		}
		if(m-1>=0 && m-2>=0 && arr[k][m-1]==3 && arr[k][m-2]==3){
			if(m-3<0 || arr[k][m-3]=='#' || (arr[k][m-3]==1 || arr[k][m-3]==2 || arr[k][m-3]==3)){
				arr[k][m-1]=2;
				arr[k][m-2]=2;
			}
			else{
				arr[k][m-1]='.';
				arr[k][m-2]=2;
				arr[k][m-3]=2;
			}				
		}

        }


     else{

		if(m-1>=0 && arr[k][m-1]==1){//1 sto prwto
			arr[k][m-1]='.';
		}
		if(m-1>=0 && m-2>=0 && arr[k][m-2]==1){//1 sto deytero
			arr[k][m-2]='.';
		}
		if(m-1>=0 && arr[k][m-1]==2){//2 sto prwto kai meta toixos/empodio
			if(m-2<0 || arr[k][m-2]=='#' || (arr[k][m-3]==1 || arr[k][m-3]==2 || arr[k][m-3]==3)){
				arr[k][m-1]=1;
			}
			else if(m-2>=0 && arr[k][m-2]!='#' && arr[k][m-2]!=1 && arr[k][m-2]!=2 && arr[k][m-2]!=3){
				arr[k][m-1]='.';
				arr[k][m-2]=1;
			}
		}
		if(m-1>=0 && m-2>=0  && arr[k][m-2]==2){//2 sto deytero kai meta oxi/nai empodio/toixos
			if(m-3>=0 && arr[k][m-3]!='#' && arr[k][m-3]!=1 && arr[k][m-3]!=2 && arr[k][m-3]!=3){
				arr[k][m-2]='.';
				arr[k][m-3]=1;
			}
			else if(m-3<0 || arr[k][m-3]=='#' || (arr[k][m-3]==1 || arr[k][m-3]==2 || arr[k][m-3]==3)){
				arr[k][m-2]=1;
			}
		}
		if(m-1>=0 && arr[k][m-1]==3){//3 sto prwto kai meta oxi toixos/empodio
			if(m-2>=0 && arr[k][m-2]!='#' && arr[k][m-2]!=1 && arr[k][m-2]!=2 && arr[k][m-2]!=3){
				arr[k][m-1]='.';
				arr[k][m-2]=2;
			}
			else if(m-2<0 || arr[k][m-2]=='#' || (arr[k][m-3]==1 || arr[k][m-3]==2 || arr[k][m-3]==3)){
				arr[k][m-1]=2;
			}
		} 
		if(m-1>=0 && arr[k][m-2]==3){//3 sto deytero kai meta oxi empodio/toixos 
			if(m-2>=0 && m-3>=0 && arr[k][m-3]!='#' && arr[k][m-3]!=1 && arr[k][m-3]!=2 && arr[k][m-3]!=3){
				arr[k][m-2]='.';
				arr[k][m-3]=2;
			}
			else if(m-2<0 || m-3<0 || arr[k][m-3]=='#' || (arr[k][m-3]==1 || arr[k][m-3]==2 || arr[k][m-3]==3)){
				arr[k][m-2]=2;
			}
		}  
           }
	}  
     
	return 1;             
}





int fistAttack(int **arr,int rows,int cols,int dir)
{

   int k,i,j,m;




 for(i=0 ; i<rows ; i++){       /* briskw thn thesi tou $ */
       for(j=0 ; j<cols ; j++){
             if(arr[i][j]=='$'){
                 k=i;
                 m=j;
               }        
 	  }
       }


  if(dir==1){                /* PANW */
	if(k-1<0 || arr[k-1][m]=='.' || arr[k-1][m]=='#'){
		printf("\nde xrewnesai ekanes airball\n");
		return 0;
	}
    if(k-1>=0 && arr[k-1][m]==1){
        arr[k-1][m]='.';
   }

   if(k-1>0 && arr[k-1][m]==2){
         if( arr[k-2][m]=='.'){
           arr[k-1][m]='.';
           arr[k-2][m]=1;
        }
        else if(arr[k-2][m]!='.')
           arr[k-1][m]=1;
          
  }
      else if(k-1==0 && arr[k-1][m]==2)
          arr[k-1][m]=1;
    
      
     if(k-1>0 && arr[k-1][m]==3 ){
       if( arr[k-2][m]=='.'){
          arr[k-1][m]='.';
          arr[k-2][m]=2;
      }
      else if(arr[k-2][m]!='.')
           arr[k-1][m]=2;
   }
      else if(k-1==0 && arr[k-1][m]==3)
             arr[k-1][m]=2;
return 1;
}

 if(dir==3) {  /* KATW */
  if(k+1>rows-1 || arr[k+1][m]=='.' || arr[k+1][m]=='#'){
		printf("\nde xrewnesai ekanes airball\n");
		return 0;
	}
    if(k+1<=rows-1 && arr[k+1][m]==1)
      arr[k+1][m]='.';

   if(k+1<rows-1 && arr[k+1][m]==2 ){ 
       if( arr[k+2][m]=='.'){
          arr[k+1][m]='.';
          arr[k+2][m]=1;
     }
      else if(arr[k+2][m]!='.')
            arr[k+1][m]=1;
     }

      else if(k+1==rows-1 && arr[k+1][m]==2)
            arr[k+1][m]=1;

    if(k+1<rows-1 && arr[k+1][m]==3 ){
       if(arr[k+2][m]=='.'){
           arr[k+1][m]='.';
           arr[k+2][m]=2;
      }
       else if(arr[k+2][m]!='.')
           arr[k+1][m]=2;
    }

     else if(k+1==rows-1 && arr[k+1][m]==3)
           arr[k+1][m]=2;
return 1;
}


 if(dir==2){             /* DEXIA */
if(m+1>cols-1 || arr[k][m+1]=='.' || arr[k][m+1]=='#'){
		printf("\nde xrewnesai ekanes airball\n");
		return 0;
	}
   if(m+1<=cols-1 && arr[k][m+1]==1)
      arr[k][m+1]='.';
  

   if(m+1<cols-1 && arr[k][m+1]==2 ){
       if( arr[k][m+2]=='.'){
          arr[k][m+1]='.';
          arr[k][m+2]=1;
   }
      else if(arr[k][m+2]!='.')
           arr[k][m+1]=1;
    }
 
    else if(m+1==cols-1 && arr[k][m+1]==2)
        arr[k][m+1]=1;

  if(m+1<cols-1 && arr[k][m+1]==3 ){
      if( arr[k][m+2]=='.'){
         arr[k][m+1]='.';
         arr[k][m+2]=2;
     }
    else if(arr[k][m+2]!='.')
           arr[k][m+1]=2;
   }

   else if(m+1==cols-1 && arr[k][m+1]==3)
           arr[k][m+1]=2;

 
return 1;
}


 if(dir==4){       /* ARISTERA */
if(m-1>cols-1 || arr[k][m-1]=='.' || arr[k][m-1]=='#'){
		printf("\nde xrewnesai ekanes airball\n");
		return 0;
	}
  if(m-1>=0 && arr[k][m-1]==1)
     arr[k][m-1]='.';
 
  if(m-1>0 && arr[k][m-1]==2 ){
       if( arr[k][m-2]=='.'){
          arr[k][m-1]='.';
          arr[k][m-2]=1;
  }
      else if(arr[k][m-2]!='.')
          arr[k][m-1]=1;
   }

     else if(m-1==0 && arr[k][m-1]==2)
           arr[k][m-1]=1;

 if(m-1>0 && arr[k][m-1]==3 ){
    if(arr[k][m-2]=='.'){
       arr[k][m-1]='.';
       arr[k][m-2]=2;
  }
  else if(arr[k][m-2]!='.')
      arr[k][m-1]=2;
}

  else if(m-1==0 && arr[k][m-1]==3)
         arr[k][m-1]=2;

}
return 1;
      
}


int swordAttack(int **arr,int rows,int cols,int direct)
{

  int i,j,k,m,p;


   for(i=0 ; i<rows ; i++){       /* briskw thn thesi tou $ */
       for(j=0 ; j<cols ; j++){
             if(arr[i][j]=='$'){
                 k=i;
                 m=j;
               }        
 	  }
       }


 	if(direct==1)        
    {
	if(k-1<0 || (arr[k-1][m]=='.' || arr[k-1][m]=='#') && (arr[k-1][m-1]=='.' || arr[k-1][m-1]=='#' || m-1<0) && (arr[k-1][m+1]=='.' || arr[k-1][m+1]=='#' || m+1>cols-1)){
		printf("\nde xrewnsesai ekanes airball\n");
		return 0;
	}
      if(k-1>=0 && m-1>=0 && arr[k-1][m-1]==1)
               arr[k-1][m-1]='.';


      if(k-1>0 && m-1>=0 && arr[k-1][m-1]==2){
         if( arr[k-2][m-1]=='.'){
           arr[k-1][m-1]='.';
           arr[k-2][m-1]=1;
        }
            else if(arr[k-2][m-1]!='.')
              arr[k-1][m-1]=1;
           }
 
      else if(k-1==0 && m-1>=0 && arr[k-1][m-1]==2)
          arr[k-1][m-1]=1;

         
       if(k-1>0 && m-1>=0 && arr[k-1][m-1]==3 ){
          if( arr[k-2][m-1]=='.'){
          arr[k-1][m-1]='.';
          arr[k-2][m-1]=2;
            }
           else if(arr[k-2][m-1]!='.')
           arr[k-1][m-1]=2;
       }
    else if(k-1==0 && m-1>=0 && arr[k-1][m-1]==3)
             arr[k-1][m-1]=2;


       
 	if(k-1>=0 && arr[k-1][m]==1){
           arr[k-1][m]='.';
         }

        if(k-1>0 && arr[k-1][m]==2){
           if( arr[k-2][m]=='.'){
           arr[k-1][m]='.';
           arr[k-2][m]=1;
           }
           else if(arr[k-2][m]!='.')
           arr[k-1][m]=1;   
        }
      else if(k-1==0 && arr[k-1][m]==2)
          arr[k-1][m]=1;
     
      if(k-1>0 && arr[k-1][m]==3 ){
        if( arr[k-2][m]=='.'){
          arr[k-1][m]='.';
          arr[k-2][m]=2;
         }
         else if(arr[k-2][m]!='.')
           arr[k-1][m]=2;
     }
      else if(k-1==0 && arr[k-1][m]==3)
             arr[k-1][m]=2;


	if(k-1>=0 && m+1<=cols-1 && arr[k-1][m+1]==1){
           arr[k-1][m+1]='.';
         }

        if(k-1>0 && m+1<=cols-1 && arr[k-1][m+1]==2){
           if( arr[k-2][m+1]=='.'){
           arr[k-1][m+1]='.';
           arr[k-2][m+1]=1;
           }
           else if(arr[k-2][m+1]!='.')
           arr[k-1][m+1]=1;   
        }
      else if(k-1==0 && m+1<=cols-1 && arr[k-1][m+1]==2)
          arr[k-1][m+1]=1;
    
      
     if(k-1>0 && m+1<=cols-1 && arr[k-1][m+1]==3 ){
       if( arr[k-2][m+1]=='.'){
          arr[k-1][m+1]='.';
          arr[k-2][m+1]=2;
      }
      else if(arr[k-2][m+1]!='.')
           arr[k-1][m+1]=2;
   }
      else if(k-1==0 && m+1<=cols-1 && arr[k-1][m+1]==3)
             arr[k-1][m+1]=2;

return 1;

}


	if(direct==2)
{
	if(m+1>cols-1 || (k+1>rows-1 && (arr[k][m+1]=='.' || arr[k][m+1]=='#') && (arr[k-1][m+1]=='.' || arr[k+1][m+1]=='#')) || (k-1<0 && (arr[k][m+1]=='.' || arr[k][m+1]=='#') && (arr[k+1][m+1]=='.' || arr[k+1][m+1]=='#')) || ((k-1>=0 && (arr[k-1][m+1]=='.' || arr[k-1][m+1]=='#')) && (arr[k][m+1]=='.' || arr[k][m+1]=='#' ) && ( (k+1<=rows-1) && arr[k+1][m+1]=='.' || arr[k+1][m+1]=='#'))){
		printf("\nde xrewnsesai ekanes airball\n");
		return 0;
	}
	
	  if(m+1<=cols-1 && k-1>=0 && arr[k-1][m+1]==1)
               arr[k-1][m+1]='.';
 	
	  
 	  if(m+1<cols-1 &&  k-1>=0 &&  arr[k-1][m+1]==2 ){
             if( arr[k-1][m+2]=='.'){
              arr[k-1][m+1]='.';
              arr[k-1][m+2]=1;
            }
             else if(arr[k-1][m+2]!='.')
               arr[k-1][m+1]=1;
       }
 
        else if(m+1==cols-1 &&  k-1>=0 && arr[k-1][m+1]==2)
              arr[k-1][m+1]=1;

       if(m+1<cols-1 &&  k-1>=0 && arr[k-1][m+1]==3 ){
          if( arr[k-1][m+2]=='.'){
           arr[k-1][m+1]='.';
           arr[k-1][m+2]=2;
         }
          else if(arr[k-1][m+2]!='.')
             arr[k-1][m+1]=2;
       }

     else if(m+1==cols-1 &&  k-1>=0 &&  arr[k-1][m+1]==3)
           arr[k-1][m+1]=2;

  
        if(m+1<=cols-1 && arr[k][m+1]==1)
          arr[k][m+1]='.';
  

   	if(m+1<cols-1 && arr[k][m+1]==2 ){
          if( arr[k][m+2]=='.'){
           arr[k][m+1]='.';
           arr[k][m+2]=1;
         }
           else if(arr[k][m+2]!='.')
             arr[k][m+1]=1;
      }
 
     else if(m+1==cols-1 && arr[k][m+1]==2)
        arr[k][m+1]=1;

    if(m+1<cols-1 && arr[k][m+1]==3 ){
       if( arr[k][m+2]=='.'){
         arr[k][m+1]='.';
         arr[k][m+2]=2;
     }
      else if(arr[k][m+2]!='.')
           arr[k][m+1]=2;
    }

   else if(m+1==cols-1 && arr[k][m+1]==3)
           arr[k][m+1]=2;

  

      if(m+1<=cols-1 && k+1<=rows-1 && arr[k+1][m+1]==1)
          arr[k+1][m+1]='.';
  

   	if(m+1<cols-1 && k+1<=rows-1 && arr[k+1][m+1]==2 ){
          if( arr[k+1][m+2]=='.'){
           arr[k+1][m+1]='.';
           arr[k+1][m+2]=1;
         }
           else if(arr[k+1][m+2]!='.')
             arr[k+1][m+1]=1;
      }
 
     else if(m+1==cols-1 && k+1<=rows-1 && arr[k+1][m+1]==2)
        arr[k+1][m+1]=1;

    if(m+1<cols-1 && k+1<=rows-1 && arr[k+1][m+1]==3 ){
       if( arr[k+1][m+2]=='.'){
         arr[k+1][m+1]='.';
         arr[k+1][m+2]=2;
       }
       else if(arr[k+1][m+2]!='.')
           arr[k+1][m+1]=2;
      }

   else if(m+1==cols-1 && k+1<=rows-1 && arr[k+1][m+1]==3)
           arr[k+1][m+1]=2;

return 1;
}


    if(direct==3)
{
if(k+1>cols-1 || (arr[k+1][m]=='.' || arr[k+1][m]=='#' ) && (arr[k+1][m-1]=='.' || arr[k+1][m-1]=='#' || m-1<0) && (arr[k+1][m+1]=='.' || arr[k+1][m+1]=='#' || m+1>cols-1)){
		printf("\nde xrewnsesai ekanes airball\n");
		return 0;
	}
	if(k+1<=rows-1 && m-1>=0 && arr[k+1][m-1]==1)
           arr[k+1][m-1]='.';

  	 if(k+1<rows-1 && m-1>=0 && arr[k+1][m-1]==2 ){ 
       	     if( arr[k+2][m-1]=='.'){
               arr[k+1][m-1]='.';
               arr[k+2][m-1]=1;
          }
           else if(arr[k+2][m-1]!='.')
              arr[k+1][m-1]=1;
         }

     else if(k+1==rows-1 && m-1>=0 &&  arr[k+1][m-1]==2)
            arr[k+1][m-1]=1;

    if(k+1<rows-1 && m-1>=0 && arr[k+1][m-1]==3 ){
       if(arr[k+2][m-1]=='.'){
           arr[k+1][m-1]='.';
           arr[k+2][m-1]=2;
         }
          else if(arr[k+2][m-1]!='.')
           arr[k+1][m-1]=2;
    }

    else if(k+1==rows-1 &&  m-1>=0 && arr[k+1][m-1]==3)
           arr[k+1][m-1]=2;



     if(k+1<=rows-1 && arr[k+1][m]==1)
         arr[k+1][m]='.';

      if(k+1<rows-1 && arr[k+1][m]==2 ){ 
         if( arr[k+2][m]=='.'){
           arr[k+1][m]='.';
           arr[k+2][m]=1;
      }
         else if(arr[k+2][m]!='.')
            arr[k+1][m]=1;
       }
     else if(k+1==rows-1 && arr[k+1][m]==2)
            arr[k+1][m]=1;

    if(k+1<rows-1 && arr[k+1][m]==3 ){
       if(arr[k+2][m]=='.'){
           arr[k+1][m]='.';
           arr[k+2][m]=2;
          }
        else if(arr[k+2][m]!='.')
           arr[k+1][m]=2;
       }
    else if(k+1==rows-1 && arr[k+1][m]==3)
           arr[k+1][m]=2;



    if(k+1<=rows-1 && m+1<=cols-1 && arr[k+1][m+1]==1)
      arr[k+1][m+1]='.';

   if(k+1<rows-1 && m+1<=cols-1 && arr[k+1][m+1]==2 ){ 
       if( arr[k+2][m+1]=='.'){
          arr[k+1][m+1]='.';
          arr[k+2][m+1]=1;
     }
      else if(arr[k+2][m+1]!='.')
            arr[k+1][m+1]=1;
     }

      else if(k+1==rows-1 && m+1<=cols-1 && arr[k+1][m+1]==2)
            arr[k+1][m+1]=1;

    if(k+1<rows-1 && m+1<=cols-1 && arr[k+1][m+1]==3 ){
       if(arr[k+2][m+1]=='.'){
           arr[k+1][m+1]='.';
           arr[k+2][m+1]=2;
      }
       else if(arr[k+2][m+1]!='.')
           arr[k+1][m+1]=2;
    }

     else if(k+1==rows-1 && m+1<=cols-1 && arr[k+1][m+1]==3)
           arr[k+1][m+1]=2;

return 1;
}

  if(direct==4)
{

if(m-1<0 || (k+1>rows-1 && (arr[k][m-1]=='.' || arr[k][m-1]=='#') && (arr[k-1][m+1]=='.' || arr[k][m+1]=='#'))  || (k-1<0 && (arr[k][m-1]=='.' || arr[k][m-1]=='#') && (arr[k+1][m-1]=='.' || arr[k+1][m-1]=='#')) || ((arr[k][m-1]=='.' || arr[k][m-1]=='#' ) && (k-1>=0 && (arr[k-1][m-1]=='.' || arr[k-1][m-1]=='#')) && (k+1<=rows-1 &&(arr[k+1][m-1]=='.' || arr[k+1][m-1]=='#')))){
		printf("\nde xrewnsesai ekanes airball\n");
		return 0;
	}


     if(m-1>=0 && k-1>=0 && arr[k-1][m-1]==1)
        arr[k-1][m-1]='.';
   
     if(m-1>0 && k-1>=0 && arr[k-1][m-1]==2 ){
       if( arr[k-1][m-2]=='.'){
          arr[k-1][m-1]='.';
          arr[k-1][m-2]=1;
         }
        else if(arr[k-1][m-2]!='.')
          arr[k-1][m-1]=1;
      } 
    else if(m-1==0 && k-1>=0 && arr[k-1][m-1]==2)
           arr[k-1][m-1]=1;

     if(m-1>0 && k-1>=0 && arr[k-1][m-1]==3 ){
       if(arr[k-1][m-2]=='.'){
         arr[k-1][m-1]='.';
         arr[k-1][m-2]=2;
     }
     else if(arr[k-1][m-2]!='.')
      arr[k-1][m-1]=2;
    }

   else if(m-1==0 && k-1>=0 && arr[k-1][m-1]==3)
         arr[k-1][m-1]=2;


     
      if(m-1>=0 && arr[k][m-1]==1)
        arr[k][m-1]='.';
 
      if(m-1>0 && arr[k][m-1]==2 ){
        if( arr[k][m-2]=='.'){
           arr[k][m-1]='.';
           arr[k][m-2]=1;
         }
          else if(arr[k][m-2]!='.')
            arr[k][m-1]=1;
     }
     else if(m-1==0 && arr[k][m-1]==2)
           arr[k][m-1]=1;

 	if(m-1>0 && arr[k][m-1]==3 ){
    	   if(arr[k][m-2]=='.'){
             arr[k][m-1]='.';
             arr[k][m-2]=2;
           }
           else if(arr[k][m-2]!='.')
              arr[k][m-1]=2;
         }
     else if(m-1==0 && arr[k][m-1]==3)
             arr[k][m-1]=2;



     if(m-1>=0 && k+1<=rows-1 && arr[k+1][m-1]==1)
        arr[k+1][m-1]='.';
 
      if(m-1>0 && k+1<=rows-1 && arr[k+1][m-1]==2 ){
        if( arr[k+1][m-2]=='.'){
           arr[k+1][m-1]='.';
           arr[k+1][m-2]=1;
         }
          else if(arr[k+1][m-2]!='.')
            arr[k+1][m-1]=1;
     }
     else if(m-1==0 && k+1<=rows-1 && arr[k+1][m-1]==2)
           arr[k+1][m-1]=1;

 	if(m-1>0 && k+1<=rows-1 && arr[k+1][m-1]==3 ){
    	   if(arr[k+1][m-2]=='.'){
             arr[k+1][m-1]='.';
             arr[k+1][m-2]=2;
           }
           else if(arr[k+1][m-2]!='.')
              arr[k+1][m-1]=2;
         }
     else if(m-1==0 && k+1<=rows-1 && arr[k+1][m-1]==3)
             arr[k+1][m-1]=2;



}

return 1;


}


void placeEnemies(int **arr,int rows,int cols,double p)
{
     
   int row,col,i,k,b=0,m;
   double d,r;

    row=rand() % rows;
    col=rand() % cols;

     r = (double) rand() /  ( (double) RAND_MAX + 1);
     r=r*3+1;
     m=(int)r;
      arr[row][col]=m;

   
 
do{

        d = (double) rand() /  ( (double) RAND_MAX + 1);
	d= d*4+1;
    	k=(int)d;

   

  if(k==1 && row+1<=rows-1 && arr[row+1][col]=='.'){
   row=row+1;
 
  r = (double) rand() /  ( (double) RAND_MAX + 1);
  r=r*3+1;
  m=(int)r;
    
  arr[row][col]=m;
  b++;

}


else if(k==2 && row-1>=0 && arr[row-1][col]=='.'){
  row=row-1;

 r = (double) rand() /  ( (double) RAND_MAX + 1);
  r=r*3+1;
  m=(int)r;

  arr[row][col]=m;
b++;
}

else if(k==3 && col+1<=cols-1 && arr[row][col+1]=='.')
{

 col=col+1;

r = (double) rand() /  ( (double) RAND_MAX + 1);
  r=r*3+1;
  m=(int)r;

 arr[row][col]=m;
b++;
}

else if(k==4 && col-1>=0 && arr[row][col-1]=='.')
{

  col=col-1;

  r = (double) rand() /  ( (double) RAND_MAX + 1);
  r=r*3+1;
  m=(int)r;

  arr[row][col]=m;
b++;
}


 }while(b<p-1);




  

}

     






