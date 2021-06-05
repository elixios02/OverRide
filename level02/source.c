int main(int argc, char **argv) {
	char username[100];
	memset(&username, 0, 12);

  char tab1[48];
  memset(&tab1, 0, 5);

	char tab2[112];
  memset(&tab2, 0, 12);

	FILE *file;
  int size;

	file = fopen("/home/users/level03/.pass", "r");

	if (file == 0) {
		fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
    exit(1);
	}

	size = fread(tab1, 1, 41, file);
	tab1[strcspn(tab1, "\n")] = 0;
  if (size != 41)
	{
        fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
        exit(1);
	}
  fclose(file)
  puts("===== [ Secure Access System v1.0 ] =====");
  puts("/***************************************\\");
  puts("| You must login to access this system. |");
  puts("\\**************************************/");

  printf("--[ Username: ");
	fgets(username, 100, stdin);
	username[strcspn(username, "\n")] = 0;

	printf("--[ Password: ");
	fgets(tab2, 100, stdin);
	tab2[strcspn(tab2, "\n")] = 0;

  puts("*****************************************");

	if (strncmp(tab1, tab2, 41) == 0) {
	    printf("Greetings, %s!\n", username);
      system("/bin/sh");
      return (0);
	}
	printf(username);
	puts(" does not have access!");
	exit(1);
}
