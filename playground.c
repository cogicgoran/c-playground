/*
Airline mock.
Add airline destination locations.
Add flights.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

void add_location_flow();
int location_exists(char *location);
void create_location(char *start);
void list_locations();
void add_flight();
void create_flight(char *origin, char *destination);
void select_location(char *location);
void clear_screen(void);

void list_flights();

char *to_upper_case_string(char *str);

int main()
{
    int input_char;
    while (TRUE)
    {
        printf("\n1: Add location\n");
        printf("2: Add flight\n");
        printf("3: List locations\n");
        printf("4: List flights\n");
        printf("9: Exit\n");
        printf("Choose action: ");
        while ((input_char = getchar()) == '\n' || input_char == EOF)
        {
            // noop
        }
        clear_screen();
        switch (input_char)
        {
        case '1':
            add_location_flow();
            break;
        case '2':
            add_flight();
            break;
        case '3':
            list_locations();
            break;
        case '4':
            list_flights();
            break;
        case '9':
            exit(0);
            break;
        default:
            break;
        }
    }
}

void list_flights()
{
    char read_buffer[1024];
    FILE *fp = fopen("flights.txt", "r");
    if (fp == NULL)
    {
        printf("\nCould not open flights file\n");
        exit(2);
    }
    fread(read_buffer, 1, 1024, fp);
    printf("%s", read_buffer);
}

void select_location(char *location)
{
    // TODO: Buffer overflow fix
    scanf("%s", location);
    if (strlen(location) != 3)
    {
        printf("\nERR: Locations must have 3 characters\n");
        exit(1);
    }
    to_upper_case_string(location);
    if (!location_exists(location))
    {
        printf("\nLocation does not exist\n");
        exit(1);
    }
    location[3] = '\0';
}

void create_flight(char *origin, char *destination)
{
    char write_buffer[12] = "";
    FILE *fp = fopen("flights.txt", "a");
    if (fp == NULL)
    {
        printf("\nCould not open dest file to add location\n");
        exit(2);
    }

    char filler[] = " => ";
    strcat(write_buffer, origin);
    strcat(write_buffer, filler);
    strcat(write_buffer, destination);
    write_buffer[10] = '\n';
    write_buffer[11] = '\0';
    fwrite(write_buffer, 1, sizeof(write_buffer) - 1, fp); // TODO: Figure out why i need to put -1 in order for unknown character to be not entered
    fclose(fp);
    printf("\nFlight created\n");
}

void add_flight()
{
    // TODO: i think input needs to be cleared before inserting flight
    char origin_location[4];
    char destination_location[4];
    printf("Origin location name: ");
    select_location(origin_location);
    printf("Destination location name: ");
    select_location(destination_location);
    create_flight(origin_location, destination_location);
}

void list_locations()
{
    char read_buffer[1024], existing_location[4];
    FILE *fdest = fopen("dest.txt", "r");
    fread(read_buffer, 1, 1024, fdest);
    printf("\n------------------------\n");
    printf("Locations:\n");
    for (int i = 0, j = 0; read_buffer[i] != EOF; i++)
    {
        existing_location[j] = read_buffer[i];
        if (read_buffer[i] == '\n')
        {
            existing_location[3] = '\0';
            printf("%d: %3s\n", (i + 1) / 4, existing_location);
            j = 0;
        }
        else
        {
            j++;
        }
    }
    printf("------------------------\n");
}

int location_exists(char *location)
{
    // TODO: Will only work for small file with less than 1024 bytes of length. Add more logic for looping if file size is larger to read bigger buffer, in chunks
    char read_buffer[1024], existing_location[4];
    FILE *fdest = fopen("dest.txt", "r");
    if (fdest == NULL)
    {
        printf("\nCould not open dest file to check existing location\n");
        exit(2);
    }
    fread(read_buffer, 1, 1024, fdest);
    for (int i = 0, j = 0; read_buffer[i] != EOF; i++)
    {
        existing_location[j] = read_buffer[i];
        if (read_buffer[i] == '\n')
        {
            existing_location[3] = '\0';
            if (!strcmp(location, existing_location))
            {
                return TRUE;
            }
            j = 0;
        }
        else
        {
            j++;
        }
    }
    return FALSE;
}

void add_location_flow()
{
    char t[4];
    // TODO: Buffer overflow fix
    printf("Location name: ");
    fgetc(stdin);
    fgets(t, 4, stdin);
    t[3] = '\0';
    if (strlen(t) != 3)
    {
        printf("\nERR: Locations must have 3 characters\n");
        return;
    }
    to_upper_case_string(t);
    if (location_exists(t))
    {
        printf("\nLocation already exists\n");
        return;
    }
    t[3] = '\n';
    FILE *fp = fopen("dest.txt", "a");
    if (fp == NULL)
    {
        printf("\nCould not open dest file to add location\n");
        exit(2);
    }
    fwrite(t, 1, sizeof(t), fp);
    printf("\nLocation added\n");
    fclose(fp);
};

char *to_upper_case_string(char *str)
{
    int i;
    for (i = 0; *(str + i) != '\0'; i++)
    {
        *(str + i) = toupper(*(str + i));
    }
    return str;
}

void clear_screen(void)
{
    system("clear");
}
