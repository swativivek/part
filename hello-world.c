/*
 * Copyright (c) 2006, Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 */

/**
 * \file
 *         A very simple Contiki application showing how Contiki programs look
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#include "contiki.h"

#include <stdio.h> /* For printf() */
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>
int isprime(int p)
{
    int d;

    for (d = 2; d < p; d = d + 1)
	if (p % d == 0)
	    return 0;

    return 1;
}
int probableprime(int randomkey)
{
	int i;
	srand(time(NULL));
	i = rand()%randomkey;
	while(i>2 && i<randomkey)
	{
		
		
		if (isprime(i))
			break;
		else
			i= rand()%randomkey;
		
	}
	return i;
}

uint32_t modpow(uint32_t b, uint32_t e, uint32_t m) {
    uint32_t result = 1;

    while (e > 0) {
        if ((e & 1) == 1) {
            
            result = (result * b) % m;
        }
        b = (b * b) % m;
        e >>= 1;
    }

    return result;
}


/*---------------------------------------------------------------------------*/
PROCESS(hello_world_process, "Hello world process");
AUTOSTART_PROCESSES(&hello_world_process);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(hello_world_process, ev, data)
{
  PROCESS_BEGIN();

        uint32_t p, b, c, secretKey;
	srand(time(NULL));
	int sc = rand(); 
        secretKey = 123456789;
        //
        // public key calculation
        //
        
        p = probablePrime(sc);
        b = 3;
        c = modPow(b,secretKey, p);
        //
        // Encryption
        //
        
        
        uint32_t X = 16;
        uint32_t r = sc%p;
        uint32_t EC = (X * modPow(c,r, p))%p;
        
        
 

  printf("Hello, world\n Encrypted- %" PRIu32 "\nand %" PRIu32 ,r,EC );
  
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
