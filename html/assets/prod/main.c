#include <emscripten/emscripten.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define QSN_LEN 20
#define QNS_LEN 98

double EMSCRIPTEN_KEEPALIVE multiply(double a, double b) {
    return a * b;
}

//TOKEN SPLITTER
char **
str_split (char *a_str, const char a_delim)
{
  char **result = 0;
  size_t count = 0;
  char *tmp = a_str;
  char *last_comma = 0;
  char delim[2];
  delim[0] = a_delim;
  delim[1] = 0;

  /* Count how many elements will be extracted. */
  while (*tmp)
    {
      if (a_delim == *tmp)
	{
	  count++;
	  last_comma = tmp;
	}
      tmp++;
    }

  /* Add space for trailing token. */
  count += last_comma < (a_str + strlen (a_str) - 1);

  /* Add space for terminating null string so caller
     knows where the list of returned strings ends. */
  count++;

  result = malloc (sizeof (char *) * count);

  if (result)
    {
      size_t idx = 0;
      char *token = strtok (a_str, delim);

      while (token)
	{
	  assert (idx < count);
	  *(result + idx++) = strdup (token);
	  token = strtok (0, delim);
	}
      assert (idx == count - 1);
      *(result + idx) = 0;
    }

  return result;
}

/*C substring function: It returns a pointer to the substring */

char *
substring (char *string, int position, int length)
{
  char *pointer;
  int c;

  pointer = malloc (length + 1);

  if (pointer == NULL)
    {
      printf ("Unable to allocate memory.\n");
      exit (1);
    }

  for (c = 0; c < length; c++)
    {
      *(pointer + c) = *(string + position - 1);
      string++;
    }

  *(pointer + c) = '\0';

  return pointer;
}

char* EMSCRIPTEN_KEEPALIVE getpassword(){
  return "PASSWORD";
}

char* EMSCRIPTEN_KEEPALIVE
generate_token (char *qsn_tkn)
{

  // return token;
  //to split tokens
  char **tokens;
  char *token1, *token2, *token3, *actual_token, *answer_token;
//   answer_token = malloc(sizeof(char)*100);
//  ###################################
//   tokens = str_split (token, '.');
// //   int qsn,ans;
//   if (tokens)
//     {
//       token1 = *(tokens + 0);
//       token2 = *(tokens + 1);
//       token3 = *(tokens + 2);
//     }
//   free(tokens);
//  ###################################
// char *str="Hi all.\nMy name is Matteo.\n\nHow are you?";
    char *array[3];
    char *ptop, *pend;
    char wk[1024];//char *wk=malloc(sizeof(char)*(strlen(str)+3));
    int i, size = sizeof(array)/sizeof(char*);
    strcpy(wk, qsn_tkn);
    strcat(wk, ".");
    for(i=0, ptop=wk;i<size;++i){
        if(NULL!=(pend=strstr(ptop, "."))){
            *pend='\0';
            array[i]=strdup(ptop);
            ptop=pend+1;
        } else {
            array[i]=NULL;
            break;
        }
    }
  token1= array[0];
  token2= array[1];
  token3 = array[2];
  char *qsn = substring (token1, QSN_LEN + 1, strlen (token1) - QSN_LEN);
  actual_token = substring (token1, 1, QSN_LEN);
  strcat (actual_token, ".");
  strcat (actual_token, token2);
  strcat (actual_token, ".");
  strcat (actual_token, token3);


  int question_location = atoi (qsn);
  char answer_location = *(actual_token + question_location );
  int answer = (int) answer_location;
  actual_token="";
  char answer_char[10];
  sprintf(answer_char,"%d", (int) answer_location);
  strcat(token2,answer_char);

  answer_token = token1;
  strcat(answer_token,".");



  strcat(answer_token,token2);
  strcat(answer_token,".");

  strcat(answer_token,token3);
  // free(token1);
  // free(token2);
  // free(token3);
  return answer_token;
}

