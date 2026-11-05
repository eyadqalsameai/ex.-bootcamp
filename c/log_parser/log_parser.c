#include <stdio.h>
#include <string.h>
int main()
{
    char line[512];
    int line_num = 1;
    int alert_num = 0;
    FILE *logs_file = fopen("logs_file.txt", "r");
    if (!logs_file)
    {
        printf("Error opening file\n");
        return 1;
    }
    printf("Alert lines:\n");
    while (fgets(line, sizeof(line), logs_file) != NULL)
    {
        if (strstr(line, "FAILED") != NULL || strstr(line, "404") != NULL)
        {
            alert_num++;
            printf("LN. %d : %s", line_num, line);
        }
        line_num++;
    }
    fclose(logs_file);
    printf("\nFound: %d Alert.\n", alert_num);
    return 0;
}