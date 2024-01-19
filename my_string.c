#include "my_string.h"

size_t str_len(const char *s)
{
  size_t i = 0;
  while (*s++ != '\0') ++i;
  return i;
}

int str_cmp(const char *s1, const char *s2)
{
  return str_n_cmp(s1, s2, (size_t) -1);
}

int str_n_cmp(const char *s1, const char *s2, size_t n)
{
  while (n-- && *s1 != '\0' && *s1 == *s2) {
    s1++;
    s2++;
  }
  return ((const unsigned char) *s1) - ((const unsigned char) *s2);
}

void *mem_cpy(
  void *restrict dst,
  const void *restrict src,
  size_t n)
{
  char *d = (char *) dst;
  char *s = (char *) src;
  while (n--) *d++ = *s++;
  return dst;
}

char *str_chr(const char *s, int c)
{
  while (*s != '\0' && *s != c) ++s;
  if (*s == c) return (char *) s;
  return NULL;
}

char *str_p_brk(const char *s, const char *charset)
{
  while (*s != '\0') {
    if (str_chr(charset, *s)) return (char *) s;
    ++s;
  }
  return NULL;
}

char *str_sep(char **stringp, const char *delim)
{
  if (stringp == NULL) return NULL;

  char *token_start = *stringp;
  char *token_end = str_p_brk(*stringp, delim);

  if (token_end == NULL) return NULL;

  *token_end = '\0';
  *stringp = token_end+sizeof(char);

  return token_start;
}

char *str_cat(char *s1, const char *s2)
{
  char *ret = s1;

  while (*s1 != '\0') ++s1;
  while (*s2 != '\0') *s1++ = *s2++;
  *s1 = '\0';

  return ret;
}

