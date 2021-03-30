#include<stdio.h>
#include<conio.h>
int total_waiting_time=0,total_idle_time=0,wait_count=0;
struct simulation{
    int cust_no;
    int rd_ar;
    int intr_arr_time;
    int arr_time;
    int rd_se;
    int service_begin;
    int service_time;

};
typedef struct simulation Simulation;

void schedule_arrival_time (Simulation s[],int n);
void schedule_service_time (Simulation s[],int n);
void schedule_completion_of_service (Simulation s[],int n);

void main(){

    //freopen("result.txt", "r", stdin);
    //freopen("result.txt", "w", stdout);

    Simulation s[200];
    int i,j,n,total_service_time=0;
    float avg_waiting_time,probability_wait,probability_of_idle_server,avg_service_time,avg_time_btn_arrival,
    avg_waiting_time_those_who_wait,Average_time_customer_spends_in_the_system;
    printf(" Enter customer number: ");
    scanf("%d",&n);
    printf(" Enter random digit for arrival time for each customer: \n");
    for(i=1;i<2;i++){
      printf("  RD.Arrival[1]: -\n");
      s[i].cust_no=1;
      s[i].rd_ar=0;
      s[i].intr_arr_time=0;
    }
    for(i=2;i<=n;i++){
        printf("  RD.Arrival[%d]: ",i);
        scanf("%d",&s[i].rd_ar);
        s[i].cust_no=i;
        if(s[i].rd_ar > 0 && s[i].rd_ar < 126) s[i].intr_arr_time=1;
        else if(s[i].rd_ar > 125 && s[i].rd_ar < 251) s[i].intr_arr_time=2;
        else if(s[i].rd_ar > 250 && s[i].rd_ar < 376) s[i].intr_arr_time=3;
        else if(s[i].rd_ar > 375 && s[i].rd_ar < 501) s[i].intr_arr_time=4;
        else if(s[i].rd_ar > 500 && s[i].rd_ar < 626) s[i].intr_arr_time=5;
        else if(s[i].rd_ar > 625 && s[i].rd_ar < 751) s[i].intr_arr_time=6;
        else if(s[i].rd_ar > 750 && s[i].rd_ar < 876) s[i].intr_arr_time=7;
        else if(s[i].rd_ar > 875 && s[i].rd_ar < 1001) s[i].intr_arr_time=8;
        else{printf(" Warning!! Please Enter RD. around 1-1000"); return 0;}
    }

    schedule_arrival_time( s, n);

    printf(" Enter random digit for service time for each customer: \n");
    for(i=1;i<2;i++){
      s[i].service_begin=0;
    }
    for(i=1;i<=n;i++){
        printf("  RD.Service[%d]: ",i);
        scanf("%d",&s[i].rd_se);
        if(s[i].rd_se > 0 && s[i].rd_se < 11) s[i].service_time=1;
        else if(s[i].rd_se > 10 && s[i].rd_se < 31) s[i].service_time=2;
        else if(s[i].rd_se > 30 && s[i].rd_se < 61) s[i].service_time=3;
        else if(s[i].rd_se > 60 && s[i].rd_se < 86) s[i].service_time=4;
        else if(s[i].rd_se > 85 && s[i].rd_se < 96) s[i].service_time=5;
        else if(s[i].rd_se > 95 && s[i].rd_se < 101) s[i].service_time=6;
        else{printf(" Warning!! Please Enter RD. around 1-100"); return 0;}
        total_service_time+=s[i].service_time;

    }


    printf("\n   ------------------------------------------------------------------------------------------------------------------");
    printf("\n  | Cust.| RD. for | Inter_arrival | Arrival | RD. for | Service |\n");
    printf("  |  No. |Arrival.T|     Time      |  Time   |Service.T|  Time   |");
    printf("\n   ------------------------------------------------------------------------------------------------------------------\n");
    for(i=1; i<=n; i++){

        printf("     %d       %d         %d      %d    %d        %d     %d\n",s[i].cust_no,s[i].rd_ar,s[i].intr_arr_time,s[i].arr_time,s[i].rd_se,s[i].service_time,s[i].service_begin);
    if(i!=n){
    printf("   ------------------------------------------------------------------------------------------------------------------\n");
        }
    else{
        printf("   --------------------------------------------------------====----------------------------====------====-----====--\n");
        }
    }
return 0;

}
void schedule_arrival_time (Simulation s[],int n){
    int i;
    for( i=2; i<=n; i++){
        s[i].arr_time=s[i-1].arr_time+s[i].intr_arr_time;
    }
}







