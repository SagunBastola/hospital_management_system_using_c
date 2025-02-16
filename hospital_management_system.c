#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>



typedef struct patient{
    int id;
    char pname[20];
    int age;
    char gender[10] ,address[50] , symptomes[255] , checkby[20];
    int date[10];
    
    }patient;

    typedef struct doctor{
        int docid;
        char dname[20];
        char docaddress[50] ,specialized[50];
        int date[10];

    }doc;


    void admit_patient(){

    }

    void discharge_patient(){
        
    }

    void patient_list();

    void available_doctor(){
        
    }

    void add_doctor(){
        
    }
    void appointment();








FILE *fp;



int main(){

    int choice;
     // infinite loop in while(true) ; the loop can be countered by switch statement
     while(1){  
        // system("cls");
        printf("\t\t\t\t<-------Hospital Management system------->\n\n");
        printf("\t1. Admit Patient\n");
        printf("\t2. Discharge Patient\n");
        printf("\t3. Patient List\n");
        printf("\t4. Available Doctor\n");
        printf("\t5. Add Doctor\n");
        printf("\t6. Appointment\n");
        printf("\t0. Exit\n");
        printf("\n------------------------------------------------------");
        printf("\nEnter your choice :\t");
        scanf("%d",&choice);
        while (getchar() != '\n');  // Clear input buffer


        switch (choice) {
            case 1:
                admit_patient();
                break;
            case 2:
                discharge_patient();
                break;
            case 3:
                patient_list();
                break;
            case 4:
                available_doctor();
                break;
            case 5:
                add_doctor();
                break;
            case 6:
            	appointment();
            	break;
            case 0:
                printf("Exiting program...\n");
                exit(0); 
            default:
                printf("Invalid choice! Try again.\n");
        }
        printf("\n\n\t\t Press any key to continue---");
        getchar();
     }





    return 0;
}

void patient_list()
{
        struct patient s;
        FILE *fp;
        fp=fopen("patient.txt","rb");
        while(fread(&s,sizeof(s),1,fp)==1)
        {
            printf("ID: %d\n", s.id);
            printf("Name: %s\n", s.pname);
            printf("Age: %d\n", s.age);
            printf("Gender: %s\n", s.gender);
            printf("Address: %s\n", s.address);
            printf("Symptoms: %s\n", s.symptomes);
            printf("Checked by: %s\n", s.checkby);
            printf("Date: %d/%d/%d\n", s.date[0], s.date[1], s.date[2]);
            printf("\n");
        }
        fclose(fp);
}

void appointment()
{   
    int i=0;
    int dokid;
    struct doctor s[100];
    printf("doctor is only available for 3 hours in this hospital 9:00-10:00, 10:00-11:00, 11:00-12:00\n");
    printf("enter the doctor id:");
    scanf("%d",&dokid);
    FILE *fp;
    fp=fopen("doctor.txt","rb+");
    while(fread(&s,sizeof(s),1,fp)==1)
    {   i++;
        if(s->docid==dokid)
        {
            int choice;
            printf("Doctor Name:%s\n",s->dname);
            printf("Doctor Address:%s\n",s->docaddress);
            printf("Doctor Specialized:%s\n",s->specialized);
            printf("Doctor Date:%d/%d/%d\n",s->date[0],s->date[1],s->date[2]);
            printf("enter the timinings you want to book the appointment:");
            printf("1. 9:00-10:00\n");
            printf("2. 10:00-11:00\n");
            printf("3. 11:00-12:00\n");
            scanf("%d",&choice);
            if (choice < 1 || choice > 3) {
                printf("Invalid choice!\n");
                fclose(fp);
            }
            if(choice==1)
            {
                if(s->date[0]==0)
                {
                    s->date[0]=1;
                    printf("Appointment booked successfully\n");
                }
                else
                {
                    printf("Appointment already booked\n");
                }
            }
            if(choice==2)
            {
                if(s->date[1]==0)
                {
                    s->date[1]=1;
                    printf("Appointment booked successfully\n");
                }
                else
                {
                    printf("Appointment already booked\n");
                }
            }
            if(choice==3)
            {
                if(s->date[2]==0)
                {
                    s->date[2]=1;
                    printf("Appointment booked successfully\n");
                }
                else
                {
                    printf("Appointment already booked\n");
                }
            }
            fseek(fp,(i-1)*sizeof(s),SEEK_SET);
            fwrite(&s,sizeof(s),1,fp);
            fclose(fp);
            break;


        }
        else
        {
            printf("Doctor not found\n");
        }
    }
}