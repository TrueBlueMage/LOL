#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MSG_WELCOME "WELCOME TO SORTIFY!"
#define MSG_SORT "Sort the following numbers:"
#define MSG_SORT2 "Please sort the numbers"
#define MSG_WELL "Well done!"
#define MSG_WIN "Congratulations, you win!"
#define MSG_OVER "Game Over."
#define MSG_WRONG "Wrong answer."
#define MSG_MAX "You have reached the maximum number of moves."
#define MSG_BYE "Bye."
#define MSG_UNKNOWN "Unknown option."
/* Use puts() to print constant strings */
int game();
int rand_number(const int, const int);
void print_status(const int, const int, const int);
void print_menu(void);
int max_min(int);
int min_max(int);
int the_game();
int status (int);
int score;
int num_rounds;
int main(int argc, char **argv)
{
  if(argc == 2)
  {
      char*c;
      int seed = strtol(argv[1], &c, 10);
      srand(seed);
  }
  char z = 'm';
  puts(MSG_WELCOME);
    
    do 
    {

      switch (z)
      {
      /* print do menu*/
        case 'm':
          print_menu();
        break;

        case 'p':
        {
          int close;
          close = game();
          if (close == 50)
          {
            score = 0;
            num_rounds = 0;
            return 0;
          }
        }

        break;    
        case 's':
        {
          print_status(status(score), score, num_rounds);
          break;
        }
        default:
          printf(MSG_UNKNOWN"\n");
        }
        scanf(" %c", &z);
      } while (z != 'q');
        print_status(status(score), score, num_rounds);
        printf("Bye.\n ");
      return 0;
}

/* generate a random integer between min and max */
int rand_number(const int min, const int max)
{
  if (max < min)
  {
    puts("Max must be larger than Min");
    exit(0);
  }
  int n = abs(max - min) + 1;
  return (rand() % n) + min;
}

/* print the game status */
void print_status(const int level, const int score, const int num_rounds)
{
  puts("+-----------------------------+");
  printf("| level:  %02d                  |\n", level);
  printf("| points: %02d                  |\n", score);
  printf("| plays:  %02d                  |\n", num_rounds);
  puts("+-----------------------------+");
}

/* print the option menu */
void print_menu(void)
{
  puts("+-----------------------------+");
  puts("| SORTIFY                     |");
  puts("| p - next chalenge           |");
  puts("| q - quit                    |");
  puts("| m - print this information  |");
  puts("| s - show your status        |");
  puts("+-----------------------------+");
}

int max_min (int level)
{
  int b;
  int max[] = {10, 30, 30, 0, -100};
  b = max[level];
  return (b);
}
int min_max (int level)
{
  int a;
  int min[] = {0, 0, -50, -100, -200};
  a = min[level];
  return (a);
}
int status (int score)
{
  int level;
  level = score / 10;
  level += 1; 
  return level;
}

int game (void)
{
  printf(MSG_SORT);        
  int i, k, a, b, c, e, f, g, level, troca;
  level = status(score);
  a = min_max ((level - 1));
  b = max_min ((level - 1));
  
  int v[4], d[4], ve[4];
  c = 0;
  e = 0;
  g = 0;
  for (i = 0 ; i < 4; i++)
  {
    v[i] = rand_number(a,b);
    ve[i] = v[i];
  }
  printf("\n%d, %d, %d, %d\n", v[0], v[1], v[2], v[3]);
  for (i = 3; i >= 0; i--)
  {
    for (k = 0; k < i ; k++)
    {
      if (v[i] < v[k])
      {
        troca = v[i];
        v[i] = v[k];
        v[k] = troca;
      }
    }
  }

  while (e != 3)
  {
    for (i = 0; i < 4; i++)
    {
      scanf("%d", &d[i]);
    }
      //ifs que funcionam como cláusula para que os for à frente funcionem mesmo no caso de existirem números equivalentes gerados pela função rand_number
    if (v[0] == v[1])
    {
      c += 1;               
    }
    if (v[0] == v[2])
    {
      c += 1;               
    }
    if (v[0] == v[3])
    {
      c += 1;               
    }
    if (v[1] == v[2])
    {
      c += 1;               
    }
    if (v[1] == v[3])
    {
      c += 1;               
    }
    if (v[2] == v[3])
    {
      c += 1;               
    }
    //if de prevenção no caso da exceção 3:1 (3 números iguais para 1 diferente) ocorrer. Nessas situações o c excederia o limite de 3 ao analisar a index diferente
    if (c == 2)
    {
      e = 1;
    }
    if (c == 1)
    {
      e = 4;
    }
    f = c;
    c = 0;
    //ciclo for usado para detetar diferenças entre os números dados pela função rand_number e os inputs do utilizador
    for (i = 0; i < 4; i++)
    {
      for (k = 0; k < 4 && e != 2; k++)
      {
        g++;
        if (v[i] != d[k])
        {
          c += f + 1;      
        }
      }
        //no caso de não ser detetada a excessão o programa prossegue a verificar se existem erros nas versões normais
        if (c > 3 && e != 1 && e != 2 && e!= 4)
        {
            printf("\n"MSG_SORT2"\n");
            printf("%d, %d, %d, %d\n", ve[0], ve[1], ve[2], ve[3]);
            e = 2;
        }
      if (e != 1 && e != 4)
      {
        c = 0;
      }
    }
      //if utilizado para o mesmo que o ciclo for anterior, mas apenas para a excessão 3:1
      if (e == 1)
      {
        if (c > 18)
        {
          printf("\n"MSG_SORT2"\n");
          printf("%d, %d, %d, %d\n", ve[0], ve[1], ve[2], ve[3]);
          e = 2;
        } 
      }
      if (e == 4)
      {
        if (c > 20)
        {
          printf("\n"MSG_SORT2"\n");
          printf("%d, %d, %d, %d\n", ve[0], ve[1], ve[2], ve[3]);
          e = 2;
        } 
      }                          
    if (g == 16 && e != 2) 
    {
      g = 0;
      for (i = 0; i < 4; i++)
      {
          if (v[i] == d[i])
          {
            g++;             
          }
      }
      if (g == 4)
      {
        printf(MSG_WELL"\n");
        score += 5;
        if (num_rounds > 30)
        {
          num_rounds = 1;
        }
        num_rounds += 1;
        level = status(score);
        if (level == 6)
        {
          printf(MSG_WIN"\n");
          print_status(status(score), score, num_rounds);
          printf("Game Over.\n");
          return score;
        }
        if (num_rounds == 30)
        {
          printf(MSG_MAX"\n");
          print_status(status(score), score, num_rounds);
          printf("Game Over.\n");
          return score;
        }
        break;
      }
      else
      {
        printf(MSG_WRONG"\n");
        num_rounds += 1;
        if (num_rounds == 30)
        {
          printf(MSG_MAX"\n");
          print_status(status(score), score, num_rounds);
          printf("Game Over.\n");
          return score;
        }
        break;
      }
    }
    c = 0;
    e = 0;
    g = 0; 
  }
  return score;
}