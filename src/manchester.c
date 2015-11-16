#include "manchester.h"

/*
 * Process based on 802.3 Manchester encoding.
 *   Assumes edge detection is already handled.
 * Ref: https://en.wikipedia.org/wiki/Manchester_code
 */
Manchester_Bit_t Manchester_Process_Edge( const Manchester_Bit_t clock,
                                          const Manchester_Bit_t data )
{
    // Bad input
    if( ( data  >= Undef )
     || ( clock >= Undef ) )
    {
        return Undef;
    }

    // 802.3 defines output as clock XOR data
    return clock ^ data;
}
