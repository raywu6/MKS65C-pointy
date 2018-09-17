#include <stdio.h>
#include <stdlib.h>

/* * * * * * * * * * * * *
   Raymond Wu
   Systems pd10
   HW01 -- Get to the pointer!
   2018-09-14
   * * * * * * * * * * * */

int main() {
  
  //>> Declares and initializes an unsigned int to some value > 2.1 billion
  
  unsigned int unsignedInt = 2100000001;


  //>> Declare a char * that points to the address of your unsigned int
  
  char * intPointer = &unsignedInt; // produces warning


  //>> Print out your int in hex
  //>> The formatting character for a hexadecimal int is: %x
  printf("------------------------------\n");
  
  printf("2100000001 in hex: \t %x \n", unsignedInt); // hex > int, so won't have memory problems


  //>> Use your pointer to print out each individual byte of your int
  //>> The formatting character for a single byte in hex is %hhx, that is half of half of an integer
  printf("------------------------------\n");
  
  int i;
  for ( i=0 ; i<sizeof(unsignedInt) ; i++ ) {     // for every byte in the unsigned int
    printf("Byte %d: \t\t %hhx \n", i, *intPointer); // print [value in] single byte in intPointer
    intPointer++;
  }
  // intPointer now points to the byte after the last byte in unsignedInt
  intPointer = &unsignedInt; // reset, produces warning


  //>> Using your pointer, modify the individual bytes of your int and print out the resulting value in hex and decimal after each modification
  //>> Increment each byte by 
  printf("------------------------------\n"); 

  int j;
  for ( j=0; j<sizeof(unsignedInt) ; j++ ) { // for every byte in the unsigned int
    *intPointer += 1; // +1 to value in this byte
    intPointer++;     // go to next byte

    printf("intPointer value in hex: \t\t %x \n", *intPointer);
    printf("intPointer value in unsigned int: \t %u \n", *intPointer);
  }
  // intPointer now points to the byte after the last byte in unsignedInt
  intPointer = &unsignedInt; // reset, produces warning


  //>> Increment each byte by 16
  printf("------------------------------\n");

  int k;
  for ( k=0 ; k<sizeof(unsignedInt) ; k++ ) { // for every byte in the unsigned int
    *intPointer += 16; // +16 to value in this byte
    intPointer++;      // go to next byte

    printf("intPointer value in hex: \t\t %x \n", *intPointer);
    printf("intPointer value in unsigned int: \t %u \n", *intPointer);
  }
    
  return 0;
}


