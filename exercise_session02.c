#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>


int main() {
    char password[24] = "";
    printf("Enter the password: ");
    
	fgets(password,sizeof(password),stdin);

    int length = strlen(password);
	bool password_length = false;
    bool password_upper = false;
    bool password_lower = false;
    bool password_symbols = false;
	bool password_num =false;

    
	if (length >=8 )
	{
		password_length=true;
	}
    for (int i = 0; i < length; i++) {
    	if(isupper(password[i]))
    	{
	    	password_upper=true;
	    }
	    if(islower(password[i])){
    		password_lower=true;
    	}
    	if(ispunct(password[i]))
    	{
	    	password_symbols = true;
	    }
		if(isdigit(password[i]))
		{
			password_num =true;
		}
    	
    }
    if(password_length && password_lower && password_upper && password_symbols && password_num == true)
    {
    	printf("password is valid.\n");
    }
    else
    {
    	printf("The password must contain:\n 1- More than 8 characters.\n 2- including uppercase letters.\n 3- lowercase letters.\n 4- numbers.\n 5- special characters.\n");
    }
    return 0;
}