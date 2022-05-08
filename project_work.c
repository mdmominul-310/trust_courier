#include <stdio.h>
//user welcome
void welcome(void);
//user login
int login();
// create delivery
int delivery(void);

int get_division(int div_option);
int get_weight(int weight_option);
void senderInfo( char *name,char *address,char *m_number );
void recieverInfo( char *name,char *address,char *m_number );

//product information
void productInfo(int *price,int *collectCash);
//invoice
void invoice(char senderName[],char senderAddress[],char senderNumber[],char recieverName[],char recieverAddress[],char recieverNumber[],char pickup_location[], char delivery_location[],int price, int cashcollection, int cod,int total);

int main(void)
{
    //login status
    int log=0;
    //user input
        char input;
    // user data

            welcome();
            printf("where you would like to go:");
            scanf("%c",&input);
            printf("%c",input);


            switch(input)
            {
            case '1':
             login(&log);
            case 0:
                return 0;
            default:
                welcome();
            }
}

// welcome message funcion
void welcome(void)
{
      printf("\n\t\t\t         WELCOME ");
     printf("\n\t\t\t            to ");
     printf("\n\t\t\t   THE TRUST COURIER ");
     printf("\n\t\t________________________________________");
     printf("\n\t\t________________________________________");
     printf("\n\t\t________________________________________");
     printf("\n\t\t [1] Login");
     printf("\n\t\t [0] press 0 to quit             ");
     printf("\n\t\t________________________________________\n\n");
}
// user login seystem

int login(int *status)
{
    int exit_status=1;
    while(exit_status!=0)
    {
    // user information
    char username[15];
    char password[12];

   // login process
    printf(" >Enter your username:\n");
    scanf("%s",&username);

    printf("Enter your password:\n");
    scanf("%s",&password);
    // login condition
    if(strcmp(username,"admin")==0){
        if(strcmp(password,"1234")==0){

        printf("\nWelcome.Login Success!");
        delivery();
        exit_status=0;


        }else{

     printf("\nwrong password \n ");
     printf("\n\t\t________________________________________");
     printf("\n\t\t [1] Try again");
     printf("\n\t\t [0] press 0 to quit             ");
     printf("\n\t\t________________________________________\n\n");
     scanf("%d",&exit_status);

}
    }else{

    printf("\nUser doesn't exist");
    printf("\nwrong password \n ");
    printf("\n\t\t________________________________________");
    printf("\n\t\t [1] Try again");
    printf("\n\t\t [0] press 0 to quit             ");
    printf("\n\t\t________________________________________\n\n");
    scanf("%d",&exit_status);
}
    }


}

// create delivery
int delivery(void)
{
    //sender information
    char sender_name[100];
    char sender_address[100];
    char sender_m_number[100];
    char pickup_location[100];


    //Reciever  information
    char reciever_name[100];
    char reciever_address[100];
    char reciever_m_number[100];
    char delivery_location[100];

    //Product information
    int productPrice;
    int productCashCollection;
    // user input
    int user_input;

  printf("\n\t\t________________________________________");
     printf("\n\t\t [1] Create Order");
     printf("\n\t\t [0] press 0 to quit             ");
     printf("\n\t\t________________________________________\n\n");

    scanf("%d",&user_input);

    if(user_input==1){
    //sender information
    senderInfo( &sender_name,&sender_address,&sender_m_number );

    //reciever information
    recieverInfo( &reciever_name,&reciever_address,&reciever_m_number );

    //For perchel pickup location
    printf("Pickup loction : \n");
    int pickupLocation=get_division(pickupLocation);

    //For perchel deliver location
    printf("Delivery loction : \n");
    int deliveryLocation=get_division(deliveryLocation);

printf("%d",deliveryLocation);
    //deciede pickup location
    switch(pickupLocation)
    {
    case 1:
         pickup_location[100]="Dhaka";
        break;
    case 2:
        pickup_location[100]="Barishal";
        break;
    case 3:
         pickup_location[100]="Chitagong";
        break;
     case 4:
         pickup_location[100]="Rajsahi";
        break;
     case 5:
         pickup_location[100]="Khulna";
        break;
     case 6:
       pickup_location[100]="Rangpur";
        break;
     case 7:
        pickup_location[100]="Sylhet";
        break;
    case 8:
        pickup_location[100]="Mymenshing";
        break;
    default:
         pickup_location[100]="Dhaka";

    }


      //deciede Delivery location
    switch(deliveryLocation)
    {
    case 1:
         delivery_location[100]="Dhaka";
        break;
    case 2:
        delivery_location[100]="Barishal";
        break;
    case 3:
         delivery_location[100]="Chitagong";
        break;
     case 4:
         delivery_location[100]="Rajsahi";
        break;
     case 5:
         delivery_location[100]="Khulna";
        break;
     case 6:
       delivery_location[100]="Rangpur";
        break;
     case 7:
        delivery_location[100]="Sylhet";
        break;
    case 8:
        delivery_location[100]="Mymenshing";
        break;
    default:
         delivery_location[100]="Dhaka";

    }

    //For product information
    productInfo(&productPrice,&productCashCollection);
    int cod=productCashCollection*0.01;
    int total=productCashCollection+cod;

    invoice(sender_name, sender_address,sender_m_number,reciever_name,reciever_address,reciever_m_number,pickup_location, delivery_location,productPrice, productCashCollection, cod,total);

    }



    // for invoice

    else{
        return 0;
    }
}



// collect delivery area
int get_division(int div_option)
{

    printf("Select location :\n\n");
    printf("1> Dhaka \n");
    printf("2> Barishal \n");
    printf("3> Chittagong \n");
    printf("4> Rajshahi \n");
    printf("5> Khulna \n");
    printf("6> Rangpur \n");
    printf("7> Sylhet \n");
    printf("8> Mymensingh \n\n");

    printf("Choose the option from above : ");
    scanf("%d",&div_option);

    switch(div_option)
    {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    case 6:
        return 6;
    case 7:
        return 7;
    case 8:
        return 8;
    default :
        return 0;

    }

}

// collect product weight
int get_weight(int weight_option)
{

    printf("\n\nWeight of the parcel : \n\n");
    printf("1> 1-3 kg\n");
    printf("2> 4-6 kg\n");
    printf("3> 7-9 kg\n");
    printf("4> 10-12 kg\n\n");
    printf("Choose the option from above : ");
    scanf("%d",&weight_option);

    switch(weight_option)
    {

    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    default:
        return 0;

    }

}

// collect sender information information
void senderInfo( char *name,char *address,char *m_number )
{

    // Taking User informations

    printf("\n\n*Sender Information : \n\n");
    printf("Sender name : ");
    fflush(stdin);
    gets(name);

    printf("\n Sender address : ");
    fflush(stdin);
    gets(address);

    printf("\n Sender Mobile number(+88) : ");
    fflush(stdin);
    gets(m_number);


}

// collect reciever information
void recieverInfo( char *name,char *address,char *m_number )
{

    // Taking User informations

    printf("\n\n*Reciever Information : \n\n");
    printf("Reciever name : ");
    fflush(stdin);
    gets(name);

    printf("\n Reciever address : ");
    fflush(stdin);
    gets(address);

    printf("\n Reciever Mobile number(+88) : ");
    fflush(stdin);
    gets(m_number);


}

// product information
void productInfo(int *price, int *collectCash)
{
    printf("Procuct price : ");
    scanf("%d",price);

    printf("Cash Collection : ");
    scanf("%d",collectCash);
}

//invoice
void invoice(char senderName[],char senderAddress[],char senderNumber[],char recieverName[],char recieverAddress[],char recieverNumber[],char pickup_location[], char delivery_location[],int price, int cashcollection, int cod,int total)
{

     printf("\n\t\t\t            Invoice ");
     printf("\n\t\t________________________________________");
     printf("\n\t\t Sender Name:          %s",senderName);
     printf("\n\t\t________________________________________");
     printf("\n\t\t Sender Address:       %s",senderAddress);
     printf("\n\t\t________________________________________");
     printf("\n\t\t Sender Number:        %s",senderNumber);
     printf("\n\t\t________________________________________");
     printf("\n\t\t Reciever Name:        %s",recieverName);
     printf("\n\t\t________________________________________");
     printf("\n\t\t Reciever Address:     %s",recieverAddress);
     printf("\n\t\t________________________________________");
     printf("\n\t\t Reciever Number:      %s",recieverNumber);
     printf("\n\t\t________________________________________");
     printf("\n\t\t pickup Location:      %s",pickup_location);
     printf("\n\t\t________________________________________");
     printf("\n\t\t Delivery Location:    %s",delivery_location);
     printf("\n\t\t________________________________________");
     printf("\n\t\t Product Price:        %d",price);
     printf("\n\t\t________________________________________");
     printf("\n\t\t Cash Collection:      %d",cashcollection);
     printf("\n\t\t________________________________________");
     printf("\n\t\t Cod Charge:           %d",cod);
     printf("\n\t\t________________________________________");
      printf("\n\t\tTotal Charge:         %d",total);
     printf("\n\t\t________________________________________");


}
