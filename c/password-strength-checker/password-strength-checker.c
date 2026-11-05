#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool checker_strength_password(const char *password)
{
	int length = strlen(password);
	bool password_length = false;
	bool password_upper = false;
	bool password_lower = false;
	bool password_symbols = false;
	bool password_num = false;
	int score = 0;

	if (length >= 8)
	{
		password_length = true;
	}
	for (int i = 0; i < length; i++)
	{
		if (isupper(password[i]))
		{
			password_upper = true;
		}
		if (islower(password[i]))
		{
			password_lower = true;
		}
		if (ispunct(password[i]))
		{
			password_symbols = true;
		}
		if (isdigit(password[i]))
		{
			password_num = true;
		}
	}
	if (password_length == true)
	{
		score++;
	}
	if (password_upper == true)
	{
		score++;
	}
	if (password_lower == true)
	{
		score++;
	}
	if (password_symbols == true)
	{
		score++;
	}
	if (password_num == true)
	{
		score++;
	}
	if (score < 3)
	{
		printf("The password is weak.\n");
	}
	else if (score >= 3 && score < 5)
	{
		printf("The password is medium.\n");
	}
	else
	{
		printf("The password is strong.\n");
	}
}

int main()
{

	char password[24] = "";
	printf("Enter the password: ");

	scanf("%s", password);

	checker_strength_password(password);

	return 0;
}