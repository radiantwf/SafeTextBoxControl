#pragma once
#include "StdAfx.h"
#include "APHash.h"

unsigned int APHash(char *str)
{
    unsigned int hash = 0;
    int i;
 
    for (i=0; *str; i++)
    {
		unsigned int tmp = 0;
        if ((i & 1) == 0)
        {
			tmp = (*str++);
            hash ^= ((hash << 7) ^ tmp ^ (hash >> 3));
        }
        else
        {
			tmp = (*str++);
			hash ^= (~((hash << 11) ^ tmp ^ (hash >> 5)));
        }
    }
	hash &= 0x7FFFFFFF;
    return hash;
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
	hash &= 0x7FFFFFFF;
	return hash;
}