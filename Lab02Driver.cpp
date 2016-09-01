#include "ReadFile.h"
#include "WriteFile.h"
#include "Text.h"

#include <iostream>

int main()
{
   
    ReadFile* rf  = new ReadFile("cds.txt");  // File to be read.
    WriteFile* wf = new WriteFile("out.txt"); // File to be written to.
    
   while(!rf->eof())
   {
      String* line = rf->readLine(); // Read line from the input file.
      wf->writeLine(line); // Write line to output file.
      delete line; // Free up memory
   }

   rf->close();
   wf->close();

   delete rf; // Free up more memory
   delete wf; // Free up even more memory

   return 0;
}
