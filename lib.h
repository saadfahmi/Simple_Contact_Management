#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 14
#define EMAIL_LEN 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];

} Contact;