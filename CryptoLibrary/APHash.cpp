#pragma once
#include "StdAfx.h"
#include "APHash.h"

unsigned int APHash(char *str)
{
    unsigned int hash = 0;
    int i;
 
    for (i=0; *str; i++)
    {
        if ((i & 1) == 0)
        {
            hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));
        }
        else
        {
            hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));
        }
    }
 
    return (hash & 0x7FFFFFFF);
}

unsigned int APHash(unsigned char *point,int length)
{
	unsigned int hash = 0;
	int i;

	for (i = 0; i < length; i++)
	{
		if ((i & 1) == 0)
		{
			hash ^= ((hash << 7) ^ (*point++) ^ (hash >> 3));
		}
		else
		{
			hash ^= (~((hash << 11) ^ (*point++) ^ (hash >> 5)));
		}
	}

	return (hash & 0x7FFFFFFF);
}