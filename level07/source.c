int read_number(int *tab)
{
  var1 = 0;

  printf(" Index: ");
  var1 = get_unum();

  printf(" Number at data[%u] is %u\n", var1, tab[var1]);
  return 0;
}

int store_number(int *tab)
{
  int var1 = 0;
  int var2 = 0;

  printf("Number: ");
  var1 = get_unum();
  print("Index:");
  var2 = get_unum();

  if (var2 % 3 == 0 || var1 >> 24 == 183)
  {
    puts(" *** ERROR! ***");
    puts("   This index is reserved for wil!");
    puts(" *** ERROR! ***");
    return 1;
  }
  tab[var2] = var1;
  return 0;
}

int clear_stdin()
{
  char c;
  while(1)
  {
    c = getchar()
    if (c == "\n" || c == 255)
      return 0;
  }
  return 0;
}

int	get_unum()
{
	int	number;

	fflush(stdout);
	scanf("%u", number);
	clear_stdin();

	return number;
}

int main(int argc, char **argv, char **envp)
{
  int ret = 0;
  char buff[20] = {0};
  int tab[100];

  while (*argv)
  {
    memset(*argv, 0, strlen(*argv));
    argv++;
  }
  while (*envp)
  {
    memset(*envp, 0, strlen(*envp));
    envp++;
  }

  puts("----------------------------------------------------\n  Welcome to wil's crappy number storage service!   \n----------------------------------------------------\n Commands:                                          \n    store - store a number into the data storage    \n    read  - read a number from the data storage     \n    quit  - exit the program                        \n----------------------------------------------------\n   wil has reserved some storage :>                 \n----------------------------------------------------\n");

  while(1)
  {
    printf("Input command: ");
    fgets(buff, 20, stdin);
    buff[strlen(buff) - 1] = 0;
    if (!strncmp("store", buff, 5))
    {
      ret = store_number(&tab);
    }
    else if (!strncmp("read", buff, 4))
    {
      ret = read_number(&tab);
    }
    else if (!strncmp("quit", buff, 4))
    {
      return 0;
    }
    if (ret != 0)
    {
      printf(" Completed %s command successfully\n", buff);
    }
    else
    {
      printf(" Failed to do %s command\n", buff);
    }
  }
  return 0;
}
