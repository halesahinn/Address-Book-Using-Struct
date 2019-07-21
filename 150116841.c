///////////////////////////////////////////////////////////////////////////////////***************************************************************************************************
//
///////////////////////                                               HALE ÞAHÝN                                                                            *************************                              ****************
//////////////////////                                                            150116841                                                                 *************************                             ****************
//////////////////////                                                                       HOMEWORK 2                                                     *************************
//
//////////////////////////////////////////////////////////////////////////////////*****************************************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
typedef struct{
    int id;
    char firstName[15];        //define struct to use it many times
	char lastName[15];
	long int phoneNum;
    char adress[100];
}recordData;

int length(char s[1000]){
   char c;
    for(c = 0; s[c] != '\0'; ++c);         //find the length of a string to specify place of name,surname,address
    return c;
}
int length2(long int m){
   int result = 0;
    while( m != 0 ) {                    //length of a number to specify place of it
       m /= 10;
       result++;
    }
    return result;

}






////////////////////////////////////////////////////   MAIN    **********************************************************************************************************




int main(){



	printf("ADDRESS BOOK\n1 - List all records\n2 - Update a record\n3 - Create a new record\n4 - Delete a record\n5 - Exit\nEnter your choice: ");
        int a, i, k, m, j, b;
		char s[100];
		FILE * file;                                    //declaring and some initializing
		int datacntr = 0;
		char x[47];
		char y[47];
        long  int v;
        char z[1000];
        char t[1000];
        FILE * temp;
         recordData data[10];   
		 recordData datas[10];

                    
                     file = fopen("records.txt","r");
		    		if(file==NULL){
		              file =  fopen("records.txt","w");                        //if there is no file, create new, and prompt the user that it is created now
                                                                                       
		              fprintf(file, "No  First Name  Last Name  Phone Num  Address\n");

                      fprintf(file, "==  ==========  =========  =========  =======");

                      printf("\nCouldn't find the file, created a new one, and it is empty now.\n");

                   fclose(file);

                      main();
	                }
         fclose(file);
		if(scanf("%d", &a) == 1){                    //error check for getting choice from user
                         

	      if((a<6)&&(a>0)){            //if it is on the list continue,otherwise prompt the user

		    switch(a)
		    {

		    	case 1 :
                    printf("No  First Name  Last Name  Phone Num  Address\n");             
					printf("==  ==========  =========  =========  =======\n");
					file = fopen("records.txt","r");                                   //open file to read
	                if(fscanf(file,"%[^\n] %[^\n]",x,y)==feof(file)){
	                	fclose(file);
					break;                                            //if file does not include any record break case to prevent any error
				    }
				    while (!feof(file)) {
                                                                     //continue reading record till the end of file
						fscanf(file,"%d %s %s %ld %s", &data[datacntr].id, data[datacntr].firstName,
					data[datacntr].lastName, &data[datacntr].phoneNum, data[datacntr].adress);

             		for(i=0;i<80;i++){
						if(i==0){
							printf("%d", data[datacntr].id);
						}else if(i==4){
							printf("%s", data[datacntr].firstName);
							i=i+length(data[datacntr].firstName);
                                                                         //printing records according to place that written
						}else if(i==17){
							printf("%s",data[datacntr].lastName);
							i=i+length(data[datacntr].lastName);

						}else if(i==29){
							printf("%ld",data[datacntr].phoneNum);
							i=i+length2(data[datacntr].phoneNum);
						}else if(i==41){
							printf("%s",data[datacntr].adress);
							i=i+length(data[datacntr].adress);

						}else if(i==79){
							printf("\n");

						}else{
							printf(" ");
						}
					}

                    datacntr++;
			}
            fclose(file);
		    	break;




////////////////////////////////////////////////////////////////////******************************************************************************************************************
////////////////////////////////////////////////////////////////////*****************************************************************************************************************



		    	case 2 :

		    		printf("Please enter the record number of the person you want to update : ");
		    		
		    		if(scanf("%d",&k)==1){               //error check
                    datacntr=0;
                  
                    file = fopen("records.txt","r");
                    while (!feof(file)) {               //read until the end of file
				    if(datacntr==0){                    //if first row discard two \n then start reading line

                    fscanf(file, "%[^\n] %[^\n] %d %s %s %ld %s", x, y, &datas[datacntr].id, datas[datacntr].firstName,
					datas[datacntr].lastName, &datas[datacntr].phoneNum, datas[datacntr].adress);
					}else{
						                                //if not first row, start from the beginning of that line and just read that line
						fscanf(file,"%d %s %s %ld %s", &datas[datacntr].id, datas[datacntr].firstName,
					datas[datacntr].lastName, &datas[datacntr].phoneNum, datas[datacntr].adress);
                    }
                    datacntr++;
				    } 
                    fclose(file);

				    if(k>datacntr){                                           //if user enters a data id that doesnt exist prompt user
                        printf("This id does not exist, check again.\n");
                        break;
				    }else{
                    file = fopen("records.txt","r");

		    	    datacntr=1;
				    while (!feof(file)) {
				    if(datacntr==1){

                    fscanf(file, "%[^\n] %[^\n] %d %s %s %ld %s", z, t, &datas[datacntr].id, datas[datacntr].firstName,
					datas[datacntr].lastName, &datas[datacntr].phoneNum, datas[datacntr].adress);
					}else{
						fscanf(file,"%d %s %s %ld %s", &datas[datacntr].id, datas[datacntr].firstName,
					datas[datacntr].lastName, &datas[datacntr].phoneNum, datas[datacntr].adress);
					}
					if(datacntr==k){

					for(i=0;i<80;i++){
						if(i==0){
							printf("\n%d", datas[k].id);
						}else if(i==4){
							printf("%s", datas[k].firstName);
							i=i+length(datas[k].firstName);                    //print the information of record that user entered 

						}else if(i==17){
							printf("%s",datas[k].lastName);
							i=i+length(datas[k].lastName);

						}else if(i==29){
							printf("%ld",datas[k].phoneNum);
							i=i+length2(datas[k].phoneNum);
						}else if(i==41){
							printf("%s",datas[k].adress);
							i=i+length(datas[k].adress);
						}else if(i==79){
						    printf("\n\n");
						}else{
							printf(" ");
						}
					}
                }
                    datacntr++;
			}

                    fclose(file);

		    		printf("1 - Update phone number\n2 - Update address\nEnter your choice :");
		    		if(scanf("%d",&m)==1){







		    		if(m==1){
		    			printf("Enter the new phone number : ");
		    			if(scanf("%ld",&v)==1){




                        temp = fopen("temp.txt","w");
                        fprintf(temp, "No  First Name  Last Name  Phone Num  Address\n");
                                                                                                     //prepare the temp
                        fprintf(temp, "==  ==========  =========  =========  =======");
                        fclose(temp);

                    file = fopen("records.txt", "r");
                    datacntr=1;
				    while (!feof(file)) {
				    if(datacntr==1){                          //get the info from records.txt

                    fscanf(file, "%[^\n] %[^\n] %d %s %s %ld %s", x, y, &datas[datacntr].id, datas[datacntr].firstName,
					datas[datacntr].lastName, &datas[datacntr].phoneNum, datas[datacntr].adress);
					}else{
						fscanf(file,"%d %s %s %ld %s", &datas[datacntr].id, datas[datacntr].firstName,
					datas[datacntr].lastName, &datas[datacntr].phoneNum, datas[datacntr].adress);

                    }
                        if(datacntr==k){
                        datas[datacntr].phoneNum = v;        //change only the wanted one
                        }



                        for(i=0;i<42+length(datas[datacntr].adress);i++){
                                temp = fopen("temp.txt", "a");
						if(i==0){
							fprintf(temp, "\n%d", datas[datacntr].id);
						}else if(i==4){
							fprintf(temp, "%s", datas[datacntr].firstName);         //write all info with new changed one into temp
							i=i+length(datas[datacntr].firstName);

						}else if(i==17){
							fprintf(temp, "%s",datas[datacntr].lastName);
							i=i+length(datas[datacntr].lastName);

						}else if(i==29){
							fprintf(temp, "%ld",datas[datacntr].phoneNum);
							i=i+length2(datas[datacntr].phoneNum);
						}else if(i==41){
							fprintf(temp, "%s",datas[datacntr].adress);
							i=i+length(datas[datacntr].adress);
						}else{
							fprintf(temp, " ");
						}
						fclose(temp);
					}

					datacntr++;
				    }
                    fclose(temp);                    //close temp and file
                    fclose(file);
                    remove("records.txt");
                    rename("temp.txt","records.txt");                  //remove old records and make temp is the new records.txt
                      }else{
                    printf("Please write an integer value.");
                    return EXIT_FAILURE;
		    		}


					}else if(m==2){
						printf("Enter the new address : ");
						if(scanf("%s",&z)==1){
					
                        


                        temp = fopen("temp.txt","w");                                        //open temp to write
                        fprintf(temp, "No  First Name  Last Name  Phone Num  Address\n");
                                                                                              //prepare temp
                        fprintf(temp, "==  ==========  =========  =========  =======");
                        fclose(temp);

                    file = fopen("records.txt", "r");
                    datacntr=1;
				    while (!feof(file)) {
				    if(datacntr==1){
                                                                                  //get old info
                    fscanf(file, "%[^\n] %[^\n] %d %s %s %ld %s", x, y, &datas[datacntr].id, datas[datacntr].firstName,
					datas[datacntr].lastName, &datas[datacntr].phoneNum, datas[datacntr].adress);
					}else{
						fscanf(file,"%d %s %s %ld %s", &datas[datacntr].id, datas[datacntr].firstName,
					datas[datacntr].lastName, &datas[datacntr].phoneNum, datas[datacntr].adress);

                    }
                        if(datacntr==k){
                        	strcpy(datas[k].adress,z);       //copy the user entered address as new one
                        }



                        for(i=0;i<42+length(datas[datacntr].adress);i++){
                                temp = fopen("temp.txt", "a");
						if(i==0){
							fprintf(temp, "\n%d", datas[datacntr].id);
						}else if(i==4){
							fprintf(temp, "%s", datas[datacntr].firstName);       //write all info only changed the adress
							i=i+length(datas[datacntr].firstName);

						}else if(i==17){
							fprintf(temp, "%s",datas[datacntr].lastName);
							i=i+length(datas[datacntr].lastName);

						}else if(i==29){
							fprintf(temp, "%ld",datas[datacntr].phoneNum);
							i=i+length2(datas[datacntr].phoneNum);
						}else if(i==41){
							fprintf(temp, "%s",datas[datacntr].adress);
							i=i+length(datas[datacntr].adress);
						}else{
							fprintf(temp, " ");
						}
						fclose(temp);
					}

					datacntr++;
				    }
                    fclose(temp);
                    fclose(file);                       //again remove old records make the temp new one
                    remove("records.txt");
                    rename("temp.txt","records.txt");
                        
                        
                        
                        
                        
                         }else{
                    printf("Please write an integer value.");
                    return EXIT_FAILURE;
		    		}


                        
                        
                        
                        
                        
                        
					}else{
						printf("Please check your choice!");
					}



					}else{
                    printf("Please write an integer value.");
                    return EXIT_FAILURE;
		    		}
				    }
		    		}else{
                    printf("Please write an integer value.");
                    return EXIT_FAILURE;
		    		}

		    	break;







//////////////////////////////////////////////////////////*************************************************************************************************************************
/////////////////////////////////////////////////////////*************************************************************************************************************************




		    	case 3 :


		    	    
                    printf("Enter the record number to create a new record : ");
		    	    if(scanf("%d", &k)==1){
                    file = fopen("records.txt","r");
                                                                     //control how much record included in records.txt , the number is in datacntr
                    datacntr=0;
				    while (!feof(file)) {
				    if(datacntr==0){

                    fscanf(file, "%[^\n] %[^\n] %d %s %s %ld %s", x, y, &datas[datacntr].id, datas[datacntr].firstName,
					datas[datacntr].lastName, &datas[datacntr].phoneNum, datas[datacntr].adress);
					}else{
						fscanf(file,"%d %s %s %ld %s", &datas[datacntr].id, datas[datacntr].firstName,
					datas[datacntr].lastName, &datas[datacntr].phoneNum, datas[datacntr].adress);
                    }
                    datacntr++;
				    }
                    fclose(file);
                    if((k==datacntr+1)||((datacntr==1)&&(k==1))){   //if given id is the next one continue,otherwise prompt user
                    file = fopen("records.txt","a");      //this will write the file without old info deleted, it will continue writing where it was before
                    fprintf(file, "\n");

		    	    printf("Enter the first name : ");
		    	    if(scanf("%s", &z)==1){
                                                                 //ask the info that required the next record
		    	    printf("Enter the last name : ");
		    	    if(scanf("%s", &t)==1){

		    	    printf("Enter the phone number : ");
		    	    if(scanf("%ld",&v)==1){

		    	    printf("Enter the adress : ");
		    	    if(scanf("%s", &s)==1){

					for(i=0;i<42+length(s);i++){
						if(i==0){
							fprintf(file, "%d", k);
						}else if(i==4){
							fprintf(file, "%s", z);
							i=i+length(z);
                                                        
						}else if(i==17){
							fprintf(file, "%s",t);
							i=i+length(t);
                                                                   //write the entered info into the records.txt, in proper way
						}else if(i==29){
							fprintf(file, "%ld",v);
							i=i+length2(v);
						}else if(i==41){
							fprintf(file, "%s",s);
							i=i+length(s);
						}else{
							fprintf(file," ");
						}
					}


          fclose(file);



                    }else{
                    printf("Please write an integer value.");
                    return EXIT_FAILURE;
                    }
                    }else{
                    printf("Please write an integer value.");
                    return EXIT_FAILURE;
		    		}
		    		}else{
                    printf("Please write an integer value.");
                    return EXIT_FAILURE;
		    		}

		    		}else{
                    printf("Please write an integer value.");
                    return EXIT_FAILURE;
		    		}

		    		}else if(datacntr>=k){
		    	        printf("Watch Out! This id already exists.\n");

		    	    }else{
		    	        printf("This is not the next id, try again.\n");
		    	    }

		    		}else{
                    printf("Please write an integer value.");
                    return EXIT_FAILURE;
		    		}



		        break;


////////////////////////////////////////////////////////////////////////////*****************************************************************************************************
///////////////////////////////////////////////////////////////////////////*******************************************************************************************************




		    	case 4 :
                    printf("Enter the record number to delete : ");
                    if(scanf("%d", &k)==1){                //error check
                    	
                    	 datacntr=0;
                  
                    file = fopen("records.txt","r");               //scan the records for the record ids in datacntr 
                    while (!feof(file)) {                           
				    if(datacntr==0){

                    fscanf(file, "%[^\n] %[^\n] %d %s %s %ld %s", x, y, &datas[datacntr].id, datas[datacntr].firstName,
					datas[datacntr].lastName, &datas[datacntr].phoneNum, datas[datacntr].adress);
					}else{
						fscanf(file,"%d %s %s %ld %s", &datas[datacntr].id, datas[datacntr].firstName,
					datas[datacntr].lastName, &datas[datacntr].phoneNum, datas[datacntr].adress);
                    }
                    datacntr++;
				    }
                    fclose(file);

				    if(k>datacntr){                                        //control the entered id if it exists, otherwise prompt the user
                        printf("This id does not exist, check again.\n");
                        break;
				    }else{
                    file = fopen("records.txt","r");

		    	    datacntr=1;
				    while (!feof(file)) {
				    if(datacntr==1){                                       //read from records.txt to print the chosen record
                                    
                    fscanf(file, "%[^\n] %[^\n] %d %s %s %ld %s", z, t, &datas[datacntr].id, datas[datacntr].firstName,
					datas[datacntr].lastName, &datas[datacntr].phoneNum, datas[datacntr].adress);
					}else{
						fscanf(file,"%d %s %s %ld %s", &datas[datacntr].id, datas[datacntr].firstName,
					datas[datacntr].lastName, &datas[datacntr].phoneNum, datas[datacntr].adress);
					}
					if(datacntr==k){

					for(i=0;i<80;i++){
						if(i==0){
							printf("\n%d", datas[k].id);
						}else if(i==4){
							printf("%s", datas[k].firstName);
							i=i+length(datas[k].firstName);

						}else if(i==17){
							printf("%s",datas[k].lastName);
							i=i+length(datas[k].lastName);          //print the info of the entered id

						}else if(i==29){
							printf("%ld",datas[k].phoneNum);
							i=i+length2(datas[k].phoneNum);
						}else if(i==41){
							printf("%s",datas[k].adress);
							i=i+length(datas[k].adress);
						}else if(i==79){
						    printf("\n\n");
						}else{
							printf(" ");
						}
					}
                }
                    datacntr++;
			}
                        fclose(file);
                        temp = fopen("temp.txt","w");                                    //prepare temp.txt
                        fprintf(temp, "No  First Name  Last Name  Phone Num  Address\n");

                        fprintf(temp, "==  ==========  =========  =========  =======");
                        fclose(temp);

                    file = fopen("records.txt", "r");
                    datacntr=1;
				    while (!feof(file)) {
				    if(datacntr==1){
                                                                             //get the data from records.txt to write them in temp
                    fscanf(file, "%[^\n] %[^\n] %d %s %s %ld %s", x, y, &datas[datacntr].id, datas[datacntr].firstName,
					datas[datacntr].lastName, &datas[datacntr].phoneNum, datas[datacntr].adress);
					}else{
						fscanf(file,"%d %s %s %ld %s", &datas[datacntr].id, datas[datacntr].firstName,
					datas[datacntr].lastName, &datas[datacntr].phoneNum, datas[datacntr].adress);

                    }
                        if(datacntr==k){
                        datacntr++;
                                                   //if the deleting one comes next, skip it
						
						}else if(datacntr>k){      //after the deleted one decremet the id of all next ones
                        	datas[datacntr].id--;
                        for(i=0;i<42+length(datas[datacntr].adress);i++){
                                temp = fopen("temp.txt", "a");
						if(i==0){
							fprintf(temp, "\n%d", datas[datacntr].id);
						}else if(i==4){
							fprintf(temp, "%s", datas[datacntr].firstName);
							i=i+length(datas[datacntr].firstName);
                                                                              //write infos in temp.txt
						}else if(i==17){
							fprintf(temp, "%s",datas[datacntr].lastName);
							i=i+length(datas[datacntr].lastName);

						}else if(i==29){
							fprintf(temp, "%ld",datas[datacntr].phoneNum);
							i=i+length2(datas[datacntr].phoneNum);
						}else if(i==41){
							fprintf(temp, "%s",datas[datacntr].adress);
							i=i+length(datas[datacntr].adress);
						}else{
							fprintf(temp, " ");
						}
						fclose(temp);
					}

				
             
                    
				    }else if(datacntr<k){                               //before the deleting one dont change anything,write all info
				    	for(i=0;i<42+length(datas[datacntr].adress);i++){
                                temp = fopen("temp.txt", "a");
						if(i==0){
							fprintf(temp, "\n%d", datas[datacntr].id);
						}else if(i==4){
							fprintf(temp, "%s", datas[datacntr].firstName);
							i=i+length(datas[datacntr].firstName);

						}else if(i==17){
							fprintf(temp, "%s",datas[datacntr].lastName);
							i=i+length(datas[datacntr].lastName);

						}else if(i==29){
							fprintf(temp, "%ld",datas[datacntr].phoneNum);
							i=i+length2(datas[datacntr].phoneNum);
						}else if(i==41){
							fprintf(temp, "%s",datas[datacntr].adress);
							i=i+length(datas[datacntr].adress);
						}else{
							fprintf(temp, " ");
						}
				       fclose(temp);
                
					}
	  	
                }
                    	
                datacntr++;    	
              }
              
              }	
                    fclose(temp);         //convert temp into new records.txt
                    fclose(file);
                    remove("records.txt");
					rename("temp.txt","records.txt");
                    
						
             
                    	
					}else{
						printf("Please write an integer value.");
						return EXIT_FAILURE;
					}
                    
                
                 printf("Deleted.\n");  
                    
                    
		    	break;
		    	case 5 :
		    		printf("Bye..");
		    		exit(0);
		    	break;

			}





      }else{
      	printf("Please choose an option in between 1-5.\n");
	  }


     }else{
     	printf("Please write an integer value!");
     	return EXIT_FAILURE;
	 }


fclose(file);

//call the menu again
main();


return 0;

}

