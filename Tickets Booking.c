#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include<stdbool.h>

#define MAX_SEATS 100

bool isSeatAvailable[MAX_SEATS];

char movieName[20], showtime[15], theater[100], city[100];
int numTickets,num,seatNumber[10];

int bookingID = 100;

void initializeSeats() 
{
    for (int i = 0; i < MAX_SEATS; i++) 
	{
        isSeatAvailable[i] = true; 
    }
}

void displayAvailableSeats() 
{
    printf("Available Seats:\n");
    for (int i = 0; i < MAX_SEATS; i++) 
	{
        if (isSeatAvailable[i]) 
		{
            printf("%d  ", i + 1);
        } 
        
		else 
		{
            printf("-  "); 
        }

        if ((i + 1) % 10 == 0) 
		{
            printf("\n");
        }
    }
    printf("\n");
    
    
}

void bookTickets() 
{

    displayAvailableSeats();

    printf("Enter the number of tickets you want to book: ");
    scanf("%d", &numTickets);

    if (numTickets <= 0) 
	{
        printf("Invalid number of tickets.\n");
        return;
    }

    printf("Enter the seat numbers you want to book (1-100):\n");

    for (int i = 0; i < numTickets; i++) 
	{
        scanf("%d", &seatNumber[i]);

        
        if (seatNumber[i] < 1 || seatNumber[i] > MAX_SEATS || !isSeatAvailable[seatNumber[i] - 1]) 
		{
            printf("Invalid seat number or seat is already booked. Please try again.\n");
            i--; 
            continue;
        }

        isSeatAvailable[seatNumber[i] - 1] = false;

        //printf("Ticket booked successfully for seat number %d.\n", seatNumber);
    }
}

void acc()
{
	
	char name[100];
    char ph[10];
    char email[100];

    printf("\n------------------------------------------");
    printf("\n|         Create an Account              |");
    printf("\n------------------------------------------\n");
    
	printf("Enter name: ");
    fgets(name, sizeof(name), stdin);

    
	while(1)
	{
		printf("\nEnter phone number: ");
	    scanf("%s", ph);
	    getchar();
	    
		if((strlen(ph)!=10))
	    {
	    	printf("\nEnter a valid phone number\n");	
		}
		
		else
		break; 
	}
	
	while(1)
	{
		printf("\nEnter email Id: ");
		scanf("%s",email); 
		getchar();
		  
		char *domain = strstr(email, "@gmail.com");
    	if (domain == NULL)
		{
        	printf("\nEnter a valid email ID\n");
    	} 
		else
		break; 
	}
	
    printf("\n------------------------------------------");
    printf("\n|   Your Account has been created!       |");
    printf("\n------------------------------------------\n");
    printf("\nWelcome %s", name);
}


void booking_summary(char movieName[], char showtime[], char theater[], char city[], int numTickets, int seatNumbers[], int bookingID)
{
    printf("\n\n---------Booking Summary---------\n\n");
    printf("Booking ID: %d\n", bookingID);
    printf("Movie: %s\n", movieName);
    printf("Time: %s\n", showtime);
    printf("Theater: %s\n", theater);
    printf("City: %s\n", city);
    printf("Number of Tickets: %d\n", numTickets);
    printf("Seat Numbers: ");
    for (int i = 0; i < numTickets; i++)
    {
        printf("%d  ", seatNumbers[i]);
    }
    printf("\n\n---------------------------------");
}


void booking()
{
    int n, op,t;

	printf("\n------------------------------------------");
    printf("\n|            Movies Available            |");
    printf("\n------------------------------------------");
    printf("\n\n1. KGF Chapter2 (Tel)\n");
    printf("2. Business Man (Tel)\n");
    printf("3. Coco (Eng)\n");
    printf("\nEnter your choice: ");
    scanf("%d", &op);
	
	printf("\n------------------------------------------");
    printf("\n|          Locations Available           |");
    printf("\n------------------------------------------\n");
    printf("\n1. Warangal\n");
    printf("2. Hyderabad\n");
    printf("Please enter location: ");
    scanf("%d", &n);
    
    printf("\n------------------------------------------");
    printf("\n|           Shows Available              |");
    printf("\n------------------------------------------\n");
	printf("1. 11:00am\t2. 2:15pm\t3. 6:00pm\t4. 9:15pm\n");
	printf("Enter show time: ");
	scanf("%d",&t);
	
    switch (op)
    {
    	
    case 1:
        strcpy(movieName, "KGF Chapter2 (Tel)");
        break;
    case 2:
        strcpy(movieName, "Business Man (Tel)");
        break;
    case 3:
        strcpy(movieName, "Coco (Eng)");
        break;
    default:
        printf("Invalid choice.\n");
        return;
    }

    switch (n)
    {	
    case 1:
        strcpy(theater, "PVR Cinemas - Warangal");
        strcpy(city, "Warangal");
        break;
    case 2:
        strcpy(theater, "AMB Cinemas - Gachibowli");
        strcpy(city, "Hyderabad");
        break;
    default:
        printf("Invalid choice.\n");
        return;
    }
	
	switch (t)
	{
	case 1:
		strcpy(showtime,"11:00am");
		break;
	case 2:
		strcpy(showtime,"2:15pm");
		break;
	case 3:
		strcpy(showtime,"6:00pm");
		break;
	case 4:
		strcpy(showtime,"9:00pm");
		break;
	default:
		printf("Invalid choice\n");
		return;	
	}
	
    int payment,i;
    double card;
    int cvv,expiry,otp;
    char upi_id[20];

    printf("\n\n=====================Screen=====================\n\n");
    bookTickets();
    


    printf("\n\n------------------------------------------");
    printf("\n|            Payment                     |");
    printf("\n------------------------------------------\n");
    printf("\nPrice of 1 ticket - 200/-");
    printf("\nPrice of %d tickets - %d*200 = %d",numTickets,numTickets,numTickets*200);
    printf("\nAdditional Charges - %d*18.69 = %.2f",numTickets,numTickets*18.69);
    printf("\nTotal Amount to be paid - %.2f", (numTickets*200) + (numTickets*18.69));
    printf("\n\nChoose the mode of : \n1. Debit/Credit card\n2. UPI");
    printf("\nEnter your choice: ");
    scanf("%d",&payment);

    if (payment==1)
    {
        printf("Enter 16 digit card number: ");
        scanf("%lf",&card);
        printf("Enter CVV (***): ");
        scanf("%d",&cvv);
        printf("Enter Expiry Date:(mm/yy): ");
        scanf("%d",&expiry);
        srand(time(NULL));
        int randomNumber = rand() % 9000 + 1000;
        printf("Enter OTP (%d): ",randomNumber);
        scanf("%d",&otp);
        
		if(otp==randomNumber)
        {
            bookingID++;
            printf("\nPayment Done Successfully");
        	booking_summary(movieName, showtime, theater, city, numTickets, seatNumber, bookingID);
            printf("\nEnjoy your show!");
        }
        else 
        {
        	printf("\nOTP entered incorrectly");
		}
    }

    else if(payment==2)
    {
        printf("Enter your UPI id: ");
        scanf("%s",upi_id);
        srand(time(NULL));
        int randomNumber = rand() % 9000 + 1000;
        printf("Enter OTP (%d): ",randomNumber);
        scanf("%d",&otp);
        if(otp==randomNumber)
        {
        	bookingID++;
            printf("\nPayment Done Successfully");
        	booking_summary(movieName, showtime, theater, city, numTickets, seatNumber, bookingID);
            printf("\nEnjoy your show!\n\n");
        }
        else
        {
        	printf("\nOTP entered incorrectly");
		}
            
    }
	
	 
}



void cancel()
{
    int cancelID;

    printf("Enter the Booking ID to cancel: ");
    scanf("%d", &cancelID);

    if (cancelID == bookingID)
    {
        printf("Booking ID %d has been canceled.\n", cancelID);
        bookingID--;
    }
    else
    {
        printf("Invalid Booking ID.\n");
    }
}

void view_tickets(char movieName[], char showtime[], char theater[], char city[], int numTickets, int seatTickets[], int bookingID)
{
    int viewID;

    printf("Enter the Booking ID to view: ");
    scanf("%d", &viewID);

    if (viewID == bookingID)
    {
        printf("\n\n---------View Booked Tickets---------\n\n");
        printf("Booking ID: %d\n", bookingID);
        printf("Movie: %s\n", movieName);
        printf("Time: %s\n", showtime);
        printf("Theater: %s\n", theater);
        printf("City: %s\n", city);
        printf("Number of Tickets: %d\n", numTickets);
        printf("Seat Numbers: ");
        for (int i = 0; i < numTickets; i++)
        {
            printf("%d  ", seatTickets[i]);
        }
        printf("\n\n------------------------------------");
    }
    else
    {
        printf("Invalid Booking ID.\n");
    }
}

int main() 
{    
	
	initializeSeats();
	
    printf("\t\t\t\t\t*******************************************\n");
    printf("\t\t\t\t\t*                                         *\n");
    printf("\t\t\t\t\t*        WELCOME TO CINEMA TICKET   	  *\n");
    printf("\t\t\t\t\t*            RESERVATION SYSTEM           *\n");
    printf("\t\t\t\t\t*                                         *\n");
    printf("\t\t\t\t\t*******************************************\n");
    
    
	acc();

    int choice;
    int isBookingDone = 0;

    while (1)
    {
        printf("\n\n------------------------------------------\n");
        printf("|       Movie Ticket Booking System      |\n");
        printf("------------------------------------------\n");
        printf("1. Book tickets\n");
        printf("2. View Booked Tickets\n");
        printf("3. Cancel Booking\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n\n------------------------------------------\n");
            printf("|              Booking Tickets           |\n");
            printf("------------------------------------------\n");
            booking();
            isBookingDone = 1;
            break;
        case 2:
            if (isBookingDone)
            {
                  printf("\n\n------------------------------------------\n");
	            printf("|              View Tickets              |\n");
	            printf("------------------------------------------\n");
                view_tickets(movieName, showtime, theater, city, numTickets, seatNumber, bookingID);
            }
            
			else
            {
                printf("\nNo tickets have been booked yet.\n");
            }
            break;
        case 3:
            if (isBookingDone)
            {
	            printf("\n\n------------------------------------------\n");
	            printf("|              Cancel Tickets            |\n");
	            printf("------------------------------------------\n");
                cancel();
                isBookingDone = 0;
            }
            else
            {
                printf("\nNo tickets have been booked yet.\n");
            }
            break;
        case 4:
            printf("\nThank you for using the Cinema Reservation System.\n");
            exit(0);
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;

}