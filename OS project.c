#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
 
#define Red 0
#define Blue 1
int num_of_cus= 0;
int num_of_cus_out=0;
int num_of_red_cus= 0;
int num_of_blue_cus= 0;
int size_of_q=0;
int arr[];
int arr_of_cafe[];
int st;
int pic;
int st_a[];
 
pthread_mutex_t mutex;
 
void *customers_of_cafe(void *color) {
    pthread_mutex_lock(&mutex);
    num_of_cus++;
    if(num_of_cus%2==Blue){
        printf("Customer with %s outfit is enjoying treats at a table\n","blue");
    }
    else{
        printf("Customer with %s outfit is enjoying treats at a table\n","red");
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}
 
void Allowing_customers(){
    printf("\n\nEnter the number of table: ");
    int t;
    scanf("%d",&t);
    printf("Enter the number of sit in a individual table: ");
    int s;
    scanf("%d",&s);
    int Max_customer=t*s;
    if(Max_customer%2!=0){
    Max_customer--;
    }
    
    pthread_t threads [Max_customer];
    pthread_mutex_init(&mutex, NULL);
    
    for (int i = 0; i < Max_customer; i++) {
        pthread_create(&threads[i], NULL, customers_of_cafe, NULL);
    }
 
    for (int i = 0; i < Max_customer; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    
}
 
void menu(){
    printf("\n1. View the current situation inside the Bakery.");
    printf("\n2. Allowing customers to enter the Bakery.");
    printf("\n3. Implementing queue.");
    printf("\n4. View the outsite queue of Bakery.");
    printf("\n5. How many customers have finished their meal?");
    printf("\n6. Allowing customers from queue to the Bakery.");
    printf("\n7. Exit.");
}
void view(){
    printf("\nCurrent situation of Bakery is:\n");
    
    printf("Blue: %d\n",num_of_blue_cus);
    printf("Red: %d\n\n",num_of_red_cus);
}
 
void *imp_q_by_thread(void *arg) {
    for(int i=0;i<size_of_q;i++){
        int n= rand() % 2;
        arr[i]=n;
        
    }
    
    printf("\nImpelementation Done.......!\n");
    return NULL;
}
 
void imp_q(){
    printf("\nEnter the size of queue: ");
    scanf("%d",&size_of_q);
    //pic=size_of_q;
    pthread_t thread;
    pthread_create(&thread, NULL, imp_q_by_thread, NULL);
    pthread_join(thread, NULL);
    
}
 
void view_q(){
    
    printf("\nThe outsite queue of the cafe\n\n");
    int p=size_of_q;
    for(int i=size_of_q-1;i>=0;i--){
        if(arr[i]==Red){
        st_a[p-1]=0;
            //printf("Red\n");
        }
        else{
            //printf("Blue\n");
            st_a[p-1]=1;
        }
        p--;
    }
    for(int i=num_of_cus_out;i<size_of_q;i++){
        if(st_a[i]==0){
        //st[p-1]=arr[i];
            printf("Red\n");
        }
        else{
            printf("Blue\n");
            //st[p-1]=arr[i];
        }
       
    }
    
 //   for(int i=size_of_q-1;i>=0;i--){
 //       printf("%d ",arr[i]);
 //   }
}
 
void finished_meal(){
    printf("\nEnter the number of customers have finished their meal: ");
    scanf("%d",&num_of_cus_out);
    st=num_of_cus_out;
    int r;
    for(int i=0;i<num_of_cus_out;i++){
    r= rand() % 2;
    if(r==1){
        num_of_blue_cus--;
    }
    else{
        num_of_red_cus--;
    }
    }
 
    for(int i=0;i<num_of_cus-num_of_cus_out;i++){
        if(i<num_of_blue_cus){
            arr_of_cafe[i]=1;
        }
        else{
            arr_of_cafe[i]=0;
        }
 
    }
    
  //   for(int i=0;i<num_of_cus-num_of_cus_out;i++){
   //      printf("%d ",arr_of_cafe[i]);
   // }
    
    printf("%d customers have finished their meal & left the Bakery.\n",num_of_cus_out);
    
    
}
 
void q_to_cafe(){
    for(int i=0;i<num_of_cus_out;i++){
        if(st_a[i]==Red){
            num_of_red_cus++;
        }
        else{
            num_of_blue_cus++;
        }
      //  size_of_q--;
    }
   // pic=size_of_q;
    printf("\n%d customers enter the Bakery from the queue.....!\n",num_of_cus_out);
}
 
int main(){
    
    while(1){
        menu();
        printf("\nEnter your choise: ");
        int n;
        scanf("%d",&n);
        
        if(n==1){
            view();
        }
        if(n==2){
            Allowing_customers();
            num_of_red_cus=num_of_blue_cus=num_of_cus/2;
        }
        if(n==3){
            imp_q();
        }
        if(n==4){
            view_q();
        }
        if(n==5){
            finished_meal();
        }
        if(n==6){
            q_to_cafe();
        }
        if(n==7){
        printf("\nHere we are:\nPrinom Mojumder.(2021-2-60-098)\nTasnim Israk Synthia.(2021-2-60-097)\nSafa Islam.(2021-1-60-002)\nSuraiya Nusrat Tanha.(2021-2-60-030)\n\n\n");
            return 0;
        }
       
    }
    
}
