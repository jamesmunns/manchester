/* Includes */
#include "manchester.h"
#include <unistd.h>
#include "stdbool.h"

static int process_from_stdin(void);
static bool parse_input_line(const char* input,
                             Manchester_Bit_t* clock,
                             Manchester_Bit_t* data);

static const int bad_return_value  = -1;
static const int good_return_value =  0;

/* Demo Driver */
int main( int argc, char** argv)
{
    // Default to "failure" return value
    int retval = bad_return_value;

    // Decode arguments
    switch (argc)
    {
        /* No arguments, attempt stdio read */
        case 1:
            /* process_from_stdin will handle printing */
            retval = process_from_stdin();
            break;

        default:
            /* dont modify error return value. Print feedback. */
            fprintf(stderr, "====>Please provide input to stdin\n");
    }
    return retval;
}

/* Process all lines from stdin. If a failure is detected,
 *   return a nonzero value
 */
static int process_from_stdin(void)
{
    char single_line[4]; // "0,1\n"
    Manchester_Bit_t data;
    Manchester_Bit_t clock;

    while(read(STDIN_FILENO, single_line, sizeof(single_line)))
    {
        if(parse_input_line(single_line, &clock, &data))
        {
            printf( "%d,%d => %d\n", clock,
                                     data,
                                     Manchester_Process_Edge(clock, data) );
        }
        else
        {
            fprintf(stderr, "====>Bad Line!\n");
            return bad_return_value;
        }
    }

    return good_return_value;
}

/* Parse a single line. Perform error checking, if form is not
 *   'n,m', return false
 */
static bool parse_input_line(const char* input,
                                   Manchester_Bit_t* clock,
                                   Manchester_Bit_t* data)
{
    uint8_t l_clock;
    uint8_t l_data;

    /* Parse the string to data */
    l_clock  = input[0] - '0';
    l_data   = input[2] - '0';

    /* Error check input values */
    if( ( input[1] != ','   )
     || ( l_clock  >= Undef )
     || ( l_data   >= Undef ) )
    {
        return false;
    }

    /* Return by reference */
    *clock = l_clock;
    *data  = l_data;

    return true;
}

