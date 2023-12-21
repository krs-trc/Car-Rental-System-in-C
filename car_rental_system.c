// preprocessor directive header files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>

// Car Menu function prototypes
void createcar();
void displaycar();
void addcar();
void updatecar();
void deletecar();

// Car Booking functions prototypes
void addbooking();
void editbooking();
void deletebooking();
void displaybooking();
void displaycar();

// Car Rental Schedule function prototypes
void carschedule();

// Report function prototypes
void carrental();
void displaysum();

struct customer
{
	char name[100];
	char day[50];
	struct {
		int day;
		int month;
		int year;
	} collect;
    int dur;
	char lic[10];
	char contact[15];
	char id[15];
	float dep;
	int carType;
};

struct car{
	int type;
	char brand[150];
	char model[150];
	int seat;
	float engine;
	char trans[150];
	int year;
	char colour[150];
	int rpd;
	char plate[150];
	char availability[150];
};


int main(){

	printf("\n==========     WELCOME to    ==========\n");
	printf("========== Car Rental System ==========\n\n");
	
	int choice1, choice2, choice3, choice4;
	
	do {
		printf("\n================== MENU =================\n");
		printf("1. Manage Car booking\n");
		printf("2. Manage Car Menu\n");
		printf("3. Scheduling of the rental\n");
		printf("4. View reports\n");
		printf("5. Exit\n");
		printf(">>>>>\n\n");
		
		printf("\nPlease choose your selection: ");
		scanf("%d", &choice1);
		
		 if ( choice1==1 ){
			printf("\n");
			printf("1. Place new booking\n");
			printf("2. Edit booking\n");
			printf("3. Delete booking\n");
			printf("4. Display booking\n");
			printf("\nPlease choose your selection: ");
			scanf("%d", &choice2);
			
			switch (choice2){
				
			case 1:
				 printf("\n");
			    addbooking();	
				break;
			case 2:
				 printf("\n");
				editbooking();
				break;
			case 3:
				 printf("\n");
				deletebooking();
				break;
			case 4:
				 printf("\n");
				displaybooking();
				break;
			default:
				printf("Input entered was invalid!\n");	
					
			}
			
		}
		
		if ( choice1==2 ){
			printf("\n");
			printf("1. Add new car\n");
			printf("2. Edit detail of car\n");
			printf("3. Remove car\n");
			printf("4. Display Car Menu\n");
			printf("\nPlease choose your selection: ");
			scanf("%d", &choice3);
			
			switch (choice3){
				
				case 1:
					 printf("\n\n");
					addcar();
					break;
				case 2:
					 printf("\n\n");
					updatecar();
					break;
				case 3:
					 printf("\n\n");
					 deletecar();
					break;
				case 4:
					printf("\n\n\n");
					displaycar();
					break;
				default:
					printf("Input entered was invalid!\n");
					
			}
			
		}
		
		if ( choice1==3 ){
			printf("\n");
			carschedule();
		
			
		}
		
		if ( choice1==4 ){
			printf("\n");
			printf("1. Monthly Car Rental Report\n");
			printf("2. Monthly Summary Report\n");
			
			printf("\nPlease choose your selection: ");
			scanf("%d", &choice4);
			
			if (choice4==1){
				printf("\n");
			   carrental();
			}   
			
			else{
			   	printf("\n");
			   	displaysum();
			}
			
		}
		printf("\n");
	}
    
    while ( choice1!=5 );
	
	printf("\nThank you for using this system!\n");
}



void displaycar(){
	
	struct car c1;
	FILE *fptr;
	 if ((fptr=fopen("carfile.txt", "rb"))==NULL){
   	
   	printf("File could not be opened.\n");
   }
	
	else {
		    printf("=============== Car Menu ===============\n\n");
		    printf("Car Type     Brand       Model     Seat   Engine(L)  Transmission  Year MFD    Colour      Rent Per Day       Plate No.   Availability\n");
		
		while(fread(&c1, sizeof(struct car),1,fptr)){
			
			printf("%4d\t%10s\t%6s\t%6d\t%6.1f\t%14s\t%8d\t%8s%10d\t%13s\t%10s\n", c1.type, c1.brand, c1.model,c1.seat,c1.engine,c1.trans,c1.year,c1.colour,c1.rpd,c1.plate,c1.availability);
			
		
		}
		printf("\n\n");
	}

	fclose(fptr);
	

}



void addcar(){
	
	
        FILE * fptr;
		int i, j, n;
	    struct car *c;
	
	c = (struct car*)calloc(n, sizeof(struct car));
	
	displaycar();
	printf("\n\n");
	
	printf("Enter how many cars to add: ");
	scanf("%d", &n);
	
   if ((fptr=fopen("carfile.txt", "ab"))==NULL){
   	
   	printf("File could not be opened.\n");
   }
	
	else {
		
	
	for (i=0; i<n; i++){
		
		printf("Enter type of car: ");
		scanf("%d", &c[i].type);
		fflush(stdin);
		
		printf("Enter brand of car: ");
		gets(c[i].brand);
		fflush(stdin);
		
		printf("Enter model of car: ");
		gets(c[i].model);
		
		
		printf("Enter seat capacity: ");
		scanf("%d", &c[i].seat);
		
		printf("Enter engine capacity(L): ");
		scanf("%f", &c[i].engine);
		fflush(stdin);
		
		printf("Enter car transmission type: ");
		gets(c[i].trans);
		
		fflush(stdin);
		printf("Enter year manufactured: ");
		scanf("%d", &c[i].year);
		
		fflush(stdin);
		printf("Enter car colour: ");
		gets(c[i].colour);
		
		fflush(stdin);
		printf("Enter rent per day: ");
		scanf("%d", &c[i].rpd);
		
		fflush(stdin);
		printf("Enter plate number: ");
	    gets(c[i].plate);
	    fflush(stdin);
	    
	    fflush(stdin);
		printf("Enter availability: ");
	    gets(c[i].availability);
	    fflush(stdin);
	    
	    
	    
	    printf("\n");
	    
	    
	    	 fwrite(&c[i], sizeof(struct car), 1, fptr);
        }


       fclose(fptr);
   
	}
	
}


void updatecar(){
	
	
	int num, found,ch;
	struct car c1;
	FILE *fptr, *fptr1;
	
	
	displaycar();
	printf("\n\n");
	
	 if ((fptr=fopen("carfile.txt", "rb"))==NULL){
   	
   	printf("File could not be opened.\n");
   }
	
	else { 
	
	fptr1 = fopen("Temporarystorefile.txt", "wb");
	
	printf("Enter type of car to update: ");
	scanf("%d", &num);
	
	
	   
		
		while(fread(&c1, sizeof(struct car),1,fptr)){
			
			if(c1.type == num){

            found = 1;
	
	    fflush(stdin);
		    printf("Please select which you would like to edit:\n");
            printf("1. Type of car\n");
            printf("2. Brand of car\n");
            printf("3. Model of car\n");
            printf("4. Seat Capacity\n");
            printf("5. Engine Capacity(L)\n");
            printf("6. Car Transmission\n");
            printf("7. Year manufactured\n");
            printf("8. Colour\n");
            printf("9. Rent per day\n");
            printf("10. Plate Number\n");
            printf("11. Availability\n");
            printf(">>>> ");
            scanf("%d",&ch);
            switch(ch)
			{
				case 1:
					fflush(stdin);
                    printf("Enter new type of car: ");
		            scanf("%d", &c1.type);
		            fflush(stdin);
                    break;
                case 2:
                	fflush(stdin);
                    printf("Enter new brand of car: ");
		            gets(c1.brand);
		            fflush(stdin);
		            break;
		        case 3:
		        	printf("Enter new model of car: ");
		            gets(c1.model);
		        	fflush(stdin);
		            
                    break;
				case 4:	
				    fflush(stdin);	
		          	printf("Enter new seat capacity: ");
		            scanf("%d", &c1.seat);
		            break;
		        case 5:
		        	fflush(stdin);
		            printf("Enter new engine capacity (L): ");
		            scanf("%f", &c1.engine);
		            fflush(stdin);
		            break;
		        case 6:
		        	fflush(stdin);
		            printf("Enter car new transmission type: ");
		            gets(c1.trans);
		            break;
		        case 7:
		            fflush(stdin);
		            printf("Enter year new manufactured: ");
		            scanf("%d", &c1.year);
		            fflush(stdin);
                    break;
                case 8:
                	fflush(stdin);
		            printf("Enter new car colour: ");
		            gets(c1.colour);
		            fflush(stdin);
		            break;
		        case 9:
		        	fflush(stdin);
		            printf("Enter new rent per day: ");
		            scanf("%d", &c1.rpd);
		            fflush(stdin);
		            break;
		         case 10:
		        	fflush(stdin);
		            printf("Enter new plate number: ");
	                gets(c1.plate);
	                fflush(stdin);
		            break;
		         case 11:
		        	fflush(stdin);
		            printf("Enter new availability: ");
	                gets(c1.availability);
	                fflush(stdin);
	                break;
	            default:
	            	printf("Invalid input!");
	                fflush(stdin);
	                break;
	                
	                 printf("\n");
		    } 
	    
		}
		
		fwrite(&c1, sizeof(struct car), 1, fptr1);
		
		}
	
	 

	fclose(fptr);
	fclose(fptr1);
	
	if(found){
		
		fptr1 = fopen("Temporarystorefile.txt", "rb");
		 fptr = fopen("carfile.txt", "wb");
		 
		  while(fread(&c1,sizeof(struct car),1,fptr1)){
                fwrite(&c1,sizeof(struct car),1,fptr);
            }
		 
		 fclose(fptr);
	     fclose(fptr1);
		
	}
	
	else{
		printf("\nRecord not found\n");
	}
   
     
     
     
     
	}

        

}




void deletecar(){
	
		
	int num, found;
	struct car c1;
	FILE *fptr, *fptr1;
	
	displaycar();
	printf("\n\n");
	
	
	 if ((fptr=fopen("carfile.txt", "rb"))==NULL){
   	
   	printf("File could not be opened.\n");
   }
	
	else { 
	
	fptr1 = fopen("Temporarystorefile.txt", "wb");
	
	printf("Enter type of car to delete: ");
	scanf("%d", &num);
	
	
	   
		
		while(fread(&c1, sizeof(struct car),1,fptr)){
			
			if(c1.type == num){

            found = 1;
	    
		}
		
		else{
			
			fwrite(&c1, sizeof(struct car), 1, fptr1);
			
		}
		
		
		}
	
	 

	fclose(fptr);
	fclose(fptr1);
	
	if(found){
		
		fptr1 = fopen("Temporarystorefile.txt", "rb");
		 fptr = fopen("carfile.txt", "wb");
		 
		  while(fread(&c1,sizeof(struct car),1,fptr1)){
                fwrite(&c1,sizeof(struct car),1,fptr);
            }
		 
		 fclose(fptr);
	     fclose(fptr1);
		
	}
	
	else{
		printf("\nRecord not found\n");
	}
   
 
     
	}

	
}


void displaybooking()
{	

	struct customer cust;
	FILE *fp;
	 if ((fp=fopen("custfile.txt", "rb"))==NULL)
	 {
	 printf("File could not be opened.\n");
     }
	else 
	{	
	printf("================ Booking List =============\n\n");
	printf("Name            Booking Date (Day)      Collection Date     Duration        Licence Type        Contact No.      MyCard ID     Deposit  Car Type\n");
	while(fread(&cust,sizeof(struct customer),1,fp))
	printf("%-8s\t%-20s\t%5d/%d/%d\t%5d day(s)\t%10s\t\t%s\t%s\t%.2f\t%4d\n", cust.name, cust.day, cust.collect.day , cust.collect.month,cust.collect.year, cust.dur, cust.lic, cust.contact, cust.id,cust.dep,cust.carType);
			
	}

     printf("\n\n");

	fclose(fp);
}

void addbooking()
{
    FILE *fp,*fptr;
	int i, n, change,returnDate=0;
    struct customer *cst;
    struct customer cust;
    struct car c1;

	displaycar();
	
	cst = (struct customer*)calloc(n, sizeof(struct customer));
    
	printf("Enter how many booking to create: ");
	scanf("%d", &n);
	
   if ((fp=fopen("custfile.txt", "ab+"))==NULL){
   	
   	printf("File could not be opened.\n");
   }
	
	else {
			
	for (i=0; i<n; i++)
	{
		fflush(stdin);
	    printf("Name: ");
	    gets(cst[i].name);
	    
	    fflush(stdin);
	    printf("Booking date (DD/MM/YYYY) (day): ");
	    gets(cst[i].day);
	    
	    fflush(stdin);
        printf("Collection date (DD/MM/YYYY): ");
        scanf("%d%*c%d%*c%d",&cst[i].collect.day,&cst[i].collect.month,&cst[i].collect.year);
        
        fflush(stdin);
        printf("Duration(days): ");
	    scanf("%d",&cst[i].dur);
	    
	    fflush(stdin);
	    printf("Licence type (D/DA): ");
	    gets(cst[i].lic);

	    printf("Contact No.: ");
	    gets(cst[i].contact);
	
	    printf("MyCard ID: ");
	    gets(cst[i].id);
	    
	    printf("Deposit(RM): ");
	    scanf("%f",&cst[i].dep);
	    
        type:
	    printf("Car type: ");
	    scanf("%d",&cst[i].carType);
	    
	    fptr = fopen("carfile.txt","rb");
	    fseek(fptr,sizeof(struct car)*(cst[i].carType-1),SEEK_SET);
	    fread(&c1,sizeof(car),1,fptr);
        if (strcmp(c1.availability,"no")==0 )
		{
	        printf("This car is not available! Please choose another car.\n");
            goto type;
	    }
	    
	    if ((strcmp(cst[i].lic,"DA")==0)&&(strcmp(c1.trans,"Manual")==0))
	    {
	    	printf("Your licence is not available for this car! Please choose another car.\n");
	    	goto type;
		}

		fseek(fp,sizeof(struct customer)*(cust.carType-1),SEEK_SET);
		rewind(fp);
	    while(fread(&cust,sizeof(customer),1,fp))
	    {
	    if(cst[i].carType==cust.carType)
	    {
	    	returnDate = cust.collect.day + cust.dur;
	        if(((cst[i].collect.day-cust.collect.day)*(returnDate-cst[i].collect.day)>=0))
	    	{
	    		printf("Car has already been rented on this date! Please choose another car.\n");
	    		goto type;
			}
 	    }
        }
        fclose(fptr);
	    fwrite(&cst[i], sizeof(struct customer), 1, fp);

        //receipt
        printf("\n===== Car Booking Receipt =====\n");
	    printf("Name of customer: %s\n",cst[i].name);
	    printf("Booking date(day): %s\n",cst[i].day);
	    printf("Collection date(time): %d/%d/%d\n",cst[i].collect.day,cst[i].collect.month,cst[i].collect.year);
	    printf("Duration: %d day(s)\n",cst[i].dur);
	    printf("Licence Type: %s\n",cst[i].lic);
	    printf("Contact Number: %s\n",cst[i].contact);
	    printf("MyCard ID: %s\n",cst[i].id);
	    printf("Deposit: RM%.1f\n",cst[i].dep);
	    fptr = fopen("carfile.txt","rb");
	    fseek(fptr,sizeof(struct car)*(cst[i].carType-1),SEEK_SET);
	    fread(&c1,sizeof(car),1,fptr);
	    printf("Type of car: %d - %s\n",c1.type,c1.model);
	    printf("Rent per day: RM%d\n",c1.rpd);
	    printf("Total amount to be paid: RM%d\n",c1.rpd*cst[i].dur);
	    printf("Balance to be paid: RM%.2f\n",(c1.rpd*cst[i].dur)-cst[i].dep);
	    printf("===========================\n\n");
	    fclose (fptr);
	}
	}
	
	fclose(fp);   
}

void editbooking()
{
	char check[15];
	int found=0,ch;
	struct car c1;
	struct customer cust;
	FILE *fp, *fp1,*fptr;
	
	displaybooking();
	
	
	if ((fp=fopen("custfile.txt", "rb"))==NULL){
   	
   	printf("File could not be opened.\n");
   }
	
	else { 
	
	fp1 = fopen("tempfile.txt", "wb");
	fflush (stdin);
	printf("Enter customer MyCard ID: ");
	gets(check);
	
		while(fread(&cust, sizeof(struct customer),1,fp))
		{	
			if(strcmp(check,cust.id)==0)
			{
            found = 1;
	        fflush(stdin);
		    printf("Please select which you would like to edit:\n");
            printf("1. Name\n");
            printf("2. Booking Date(time)\n");
            printf("3. Collection Date(time)\n");
            printf("4. Duration\n");
            printf("5. Licence Type\n");
            printf("6. Contact No.\n");
            printf("7. MyCard ID\n");
            printf("8. Deposit(RM)\n");
            printf("9. Car type\n");
            printf(">>>> ");
            scanf("%d",&ch);
            switch(ch)
			{
				case 1:
					fflush(stdin);
                    printf("Enter new customer name: ");
                    gets(cust.name);
                    break;
                case 2:
                	fflush(stdin);
                    printf("Enter new booking date (DD/MM/YYYY) (day): ");
		            gets(cust.day);
		            break;
		        case 3:
		        	fflush(stdin);
		            printf("Enter new collection date (DD/MM/YYYY): ");
		            scanf("%d%*c%d%*c%d",&cust.collect.day,&cust.collect.month,&cust.collect.year);
                    break;
				case 4:	
				    fflush(stdin);	
		            printf("Enter new duration: ");
		            scanf("%d",&cust.dur);
		            break;
		        case 5:
		        	fflush(stdin);
		            printf("Enter new licence type: ");
		            gets(cust.lic);
		            break;
		        case 6:
		        	fflush(stdin);
		            printf("Enter new contact no: ");
		            gets(cust.contact);
		            break;
		        case 7:
		        	fflush(stdin);
		            printf("Enter new MyCard ID: ");
		            gets(cust.id);
                    break;
                case 8:
                	fflush(stdin);
		            printf("Enter new deposit (RM): ");
		            scanf("%f", &cust.dep);
		            break;
		        case 9:
		        	fflush(stdin);
		        	printf("Enter new car type: ");
		            scanf("%d", &cust.carType);
		            break;
	                default:
	            	printf("Invalid input!");
	                fflush(stdin);
	                break;
		    } 
	    }
		fwrite(&cust, sizeof(struct customer), 1, fp1);
		}
	fclose(fp);
	fclose(fp1);
	
	if(found){
		
		fp1 = fopen("tempfile.txt", "rb");
		 fp = fopen("custfile.txt", "wb");
		 
		  while(fread(&cust,sizeof(struct customer),1,fp1))
		  {
                fwrite(&cust,sizeof(struct customer),1,fp);
            }
		 
		 fclose(fp);
	     fclose(fp1);
	}
	
	else{
		printf("\nRecord not found\n");
	}
       
    }
}

void deletebooking()
{
    char check[15];		
	int found;
	struct customer cust;
	FILE *fp, *fp1;
	
	displaybooking();
	
	if ((fp=fopen("custfile.txt", "rb"))==NULL){
   	
   	printf("File could not be opened.\n");
   }
	
	else { 
	
	fp1 = fopen("tempfile.txt", "wb");
	fflush (stdin);
	printf("Enter customer MyCard ID: ");
	gets(check);
	
		
		while(fread(&cust, sizeof(struct customer),1,fp)){
			
			if(strcmp(check,cust.id)==0){

            found = 1;
	    
		}
		
		else{
			
			fwrite(&cust, sizeof(struct customer), 1, fp1);
			
		}
		}
	
	fclose(fp);
	fclose(fp1);
	
	if(found){
		
		fp1 = fopen("tempfile.txt", "rb");
		 fp = fopen("custfile.txt", "wb");
		 
		  while(fread(&cust,sizeof(struct customer),1,fp1)){
                fwrite(&cust,sizeof(struct customer),1,fp);
            }
		 
		 fclose(fp);
	     fclose(fp1);
		
	}
	
	else{
		printf("\nRecord not found\n");
	} 
     
	}		
}



void displaysum(){
	
		SYSTEMTIME t; // Declare SYSTEMTIME struct

	GetLocalTime(&t);
	struct car c1;
	struct customer cust;
	int totaldays,subTotal, total;

	FILE *fptr, *fptr1;
		
		if((fptr =fopen("carfile.txt", "rb")) == NULL){
			printf("File cannot be opened.");
		}
		if((fptr1 =fopen("custfile.txt", "rb")) == NULL){
			printf("File cannot be opened.");
		}
			
		printf("Monthly Summary Report (%d/%d)\n", t.wMonth, t.wYear);  	
		printf("Branch Location: Kuching\n\n");
	  	printf("Plate No.    Car Brand/Model    Rate/Day(RM)    Total Days    Subtotal\n");
	  	
		while(fread(&cust, sizeof(struct customer),1,fptr1))
	    {

	    	fseek(fptr, (cust.carType - 1) * sizeof( struct car), SEEK_SET ); 
	    	fread(&c1, sizeof(struct car),1,fptr);
			if (cust.carType == c1.type)
			{ 
                printf("%-13s%-7s %-12s%-7d\t",c1.plate,c1.brand,c1.model,c1.rpd);
			    totaldays += cust.dur;
			    subTotal = totaldays * c1.rpd;
			}
			total = total + subTotal;
	        printf("%-16d%-8d\n",totaldays,subTotal );
	        totaldays = 0;
		}
		
		
	  	printf("\n\t\t\t\t\t\t\t%s%d","Total:RM", total);

	fclose(fptr);
	fclose(fptr1);
 	 	
}


void carrental(){
	
	SYSTEMTIME t; // Declare SYSTEMTIME struct
	
	GetLocalTime(&t);
	int num, found, i ,n;
	int totalrpd = 0;
	int totaldays = 0;
	int sumrpd;
	struct car c1;
	struct customer cust;

	FILE *fptr, *fptr1, *fptr2;
	
	if((fptr =fopen("carfile.txt", "rb")) == NULL){
			printf("carfile.txt cannot be opened.\n");
	}
	if((fptr1 =fopen("custfile.txt", "rb")) == NULL){
			printf("custfile.txt cannot be opened.\n");
	}
    

	 
	 do{
		
		if((fptr =fopen("carfile.txt", "rb")) == NULL){
			printf("carfile.txt cannot be opened.");
		}
		if((fptr1 =fopen("custfile.txt", "rb")) == NULL){
			printf("custfile.txt cannot be opened.");
		}
			
			printf("===== list of the car type =====\n");
			while(fread(&c1, sizeof(struct car),1,fptr))
			{
				printf(" %d - %-7s(%s)\n", c1.type, c1.brand, c1.model);
			}
				printf(" 0 - return\n");
				printf("Enter the car type you want to view: ");
				scanf("%d",&num);
				printf("\n");
							
				if(num != 0 )
				{		
			  		printf("Monthly Car Rental Report (%d/%d)\n", t.wMonth, t.wYear);
			  	
					fseek(fptr, (num - 1) * sizeof( struct car), SEEK_SET );
					fread( &c1, sizeof(struct car), 1, fptr );
				
					printf("Car brand(car model): %s(%s)\n", c1.brand, c1.model);
					printf("No. Plate: %s\n", c1.plate);
					printf("Rental Rate: RM%d/day\n\n",c1.rpd);
					printf("Rental	customer  	Total Days   Total Rent\n");
					printf("Detail:											   \n");
					
						while(fread(&cust, sizeof(struct customer),1,fptr1))
						{
							if(cust.carType == num)
							{
							totalrpd = cust.dur * c1.rpd;
							printf("\t%-20s %-10d %d\n",cust.name,cust.dur,totalrpd );
							totaldays = cust.dur + totaldays;
							sumrpd = totalrpd + sumrpd;
							}
						}
							printf("\t\t%s\t%d","Total Rental(RM):",sumrpd);
							printf("\n\n");
								
				}
				
				sumrpd = 0;
				totaldays = 0;
				fclose(fptr);
				fclose(fptr1);
		}while(num != 0);
}



void carschedule(){
	
	SYSTEMTIME t; // Declare SYSTEMTIME struct
	
	GetLocalTime(&t);
	int num, found, i ,n;
	int totalrpd = 0;
	int totaldays = 0;
	int sumrpd;
	int retrndate,retrndateday,retrndatemon,retrndateyr;
	struct car c1;
	struct customer cust;

	FILE *fptr, *fptr1, *fptr2;
	
	if((fptr =fopen("carfile.txt", "rb")) == NULL){
			printf("carfile.txt cannot be opened.\n");
	}
	if((fptr1 =fopen("custfile.txt", "rb")) == NULL){
			printf("custfile.txt cannot be opened.\n");
	}
    

	 
	 do{
		
		if((fptr =fopen("carfile.txt", "rb")) == NULL){
			printf("carfile.txt cannot be opened.");
		}
		if((fptr1 =fopen("custfile.txt", "rb")) == NULL){
			printf("custfile.txt cannot be opened.");
		}
			
			printf("===== list of the car type =====\n");
			while(fread(&c1, sizeof(struct car),1,fptr))
			{
				printf(" %d - %-7s(%s)\n", c1.type, c1.brand, c1.model);
			}
				printf(" 0 - return\n");
				printf("Enter the car type want to view: ");
				scanf("%d",&num);
				printf("\n");
							
				if(num != 0 )
				{		
			  		printf("Monthly Car Rental Schedule (%d/%d)\n", t.wMonth, t.wYear);
			  	
					fseek(fptr, (num - 1) * sizeof( struct car), SEEK_SET );
					fread( &c1, sizeof(struct car), 1, fptr );
				
				
				   
				
					printf("\nNo. Plate: %-8s\n", c1.plate);
					
					
				     printf("\ncustomer name\tcollection date\t  return date\t\n");
					
				
					
						while(fread(&cust, sizeof(struct customer),1,fptr1))
						{
							if(cust.carType == num)
							{
						
							printf("\n%-10s\t",cust.name);
							printf("%5d/%d/%d\t", cust.collect.day,cust.collect.month,cust.collect.year);
							
							retrndate = cust.collect.day + cust.dur;
							
							if(retrndate <= 30 && cust.collect.month!=12 ){
								
							printf("%5d/%d/%d", retrndate,cust.collect.month,cust.collect.year);
							
					  	    } 
			
							if(retrndate >= 30 && cust.collect.month!=12 ){
								
								retrndateday = retrndate-30;
								retrndatemon = cust.collect.month + 1;
								printf("%5d/%d/%d", retrndateday,retrndatemon,cust.collect.year);
								
								
							}
							else if(retrndate >= 30 && cust.collect.month==12){
								
								retrndateday = retrndate-30;
								retrndatemon = cust.collect.month + 1;
								retrndateyr  = cust.collect.year + 1;
								printf("%5d/%d/%d", retrndateday,retrndatemon,retrndateyr);
						
								
							}
						
							}
						}
							
							printf("\n\n");
								
				}
				
				sumrpd = 0;
				totaldays = 0;
				fclose(fptr);
				fclose(fptr1);
		}while(num != 0);
}
