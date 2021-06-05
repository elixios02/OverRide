struct message
{
	char message[140];
	char username[40];
	int message_len;
};

void	secret_backdoor()
{
	char	string[128];

	fgets(string, 128, stdin);
	system(string);
	return (0);
}

void	set_msg(struct message *msg)
{
	char	str[1024];

	bzero(str, 128);
	puts(">: Msg @Unix-Dude");
	printf("Enter your username");
	fgets(str, 1024, stdin);
	strncpy(msg->message, str, msg->message_len);
	return (0);
}


void	set_username(struct message *msg)
{
	int   var;
	char	buff[128];

	memset(buff, 0, 16);
	puts(">: Enter your username");
	printf(">>:");
	fgets(buff, 128, stdin);
	int i = 0;
	while (i <= 40 && buff[i])
	{
		msg->username[i] = buff[i];
	}
	printf(">: Welcome, %s", msg->username);
	return (0);
}

void	handle_msg(void)
{
	struct message msg;

	bzero(msg->username, 0);
	msg->message_len = 140;
	set_username(msg);
	set_msg(msg);
	return (0);
}


int     main(int argc, char **argv, char **envp)
{
	puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337       |\n--------------------------------------------");
	handle_msg();
	return (0);
}
