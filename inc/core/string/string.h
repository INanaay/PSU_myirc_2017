/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#ifndef PSU_MYFTP_2017_STRING_H
#define PSU_MYFTP_2017_STRING_H

#include <stdlib.h>

int is_number(const char *str);
void str_remove(char *str, char c);
void str_replace(char *str, char to_replace, char c);
int str_contains(const char *str, const char *request);
char *get_uppercase_string(const char *str);
char *get_lowercase_string(const char *str);
void str_trim(char *str);
char **strsplit(const char *buffer, const char *delim);
size_t count_occurences(const char *buffer, char delim);
size_t tablen(char **tab);
void free_strtab(char **tab);

#endif //PSU_MYFTP_2017_STRING_H
