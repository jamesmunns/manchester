# Manchester Demo
This project is an example to encode manchester data from a clock and data source to a single output stream

## Assumptions
* This code currently assumes that edge detection is handled
* This code assumes that input will be well formed, and input to STDIN
* Output should be human readable, as opposed to directly machine usable output

## Usage
A makefile is supplied. The project can be built as follows:

    $ make

The example input can be run with the following command:

    $ make run

Arbitrary data can be provided from a file as such

    $ make
    $ ./demo < YOUR_FILE.txt

Or manually input as such:

    $ make
    $ ./demo
      0,1
        0,1 => 1
      1,1
        1,1 => 0

You can hit Control-C or Enter with no data to end the manual input stream.

## Data Format
Input should be in the form "`<clock>`, `<data>`\n", and an output value will be provided
