#include "nstdlib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


typedef struct nstring_st {
  int32_t    len;     // The length of the string, ignoring the trailing \0
  char*       str;   // This is a C-style string
} nstring_st;

int32_t nstrlen(char * input) {
	return (int32_t) input[-sizeof(int32_t)];
}

char * nstr_new(char * input) {
	nstring_st * nstr = (nstring_st *) malloc(sizeof(nstring_st));
	nstr->str = (char *) malloc(sizeof(char) * strlen(input) + 1);
	nstr->len = strlen(input); 
	strcpy(nstr->str, input);
	return nstr->str;
}

char * nstr_assign(char * input) {
	nstring_st * nstr = (nstring_st *) malloc(sizeof(nstring_st));
	nstr->str = (char *) malloc(sizeof(char) * strlen(input) + 1);
	nstr->len = nstrlen(input);
	strcpy(nstr->str, input);
	return nstr->str;
}

char * nstr_plus(char * s1, char * s2) {
	nstring_st * nstr = (nstring_st *) malloc(sizeof(nstring_st));
	nstr->str = (char *) malloc(sizeof(char) * (strlen(s1) + strlen(s2)) + 1);
	nstr->len = nstrlen(s1) + nstrlen(s2);
	strcpy(nstr->str, s1);
	strcat(nstr->str, s2);
	return nstr->str;
}