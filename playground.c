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

void create_location(char *start);
// get_location(char *start);
// create_flight(char *start, char *destination);

void add_location_flow();
char *to_upper_case_string(char *str);

int main()
{
    int input_char;
    while (TRUE)
    {
        // read cli input character
        printf("\n1: Add location\n");
        printf("2: Add flight\n");
        printf("3: Add flight\n");
        printf("9: Exit\n");
        printf("Choose action: ");
        input_char = getchar();
        switch (input_char)
        {
        case '1':
            add_location_flow();
            exit(0);
            break;
        case '2':

            break;
        case '3':
            // list locations
            break;
        case '9':
            // Exit program
            return 0;
            break;

        default:
            break;
        }
    }
}

int location_exists(char *location)
{
    // TODO: Will only work for small files. Add more logic for looping if file size is larger
    char read_buffer[1024], existing_location[4];
    FILE *fdest = fopen("dest.txt", "r");
    fread(read_buffer, 1, 1024, fdest);
    for (int i = 0, j = 0; read_buffer[i] != EOF; i++)
    {
        existing_location[j] = read_buffer[i];
        if (read_buffer[i] == '\n')
        {
            existing_location[3] = '\0';
            j = 0;
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
    scanf("%s", t);

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
