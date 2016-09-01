#include "WriteFile.h"
#include <sstream>

WriteFile::WriteFile(const char* file_name) {
    output_file.open(file_name);
    closed = false; // Of course this is false, check the previous line!
}

WriteFile::~WriteFile() {
    close(); // Close the file.
    // I don't think there's any more memory that can be freed from here.
}

void WriteFile::writeLine(String* line) {
    // If open, write line to file.
    if (!closed && line->length() > 0){
        output_file << line->getText() << endl;
    }

}

void WriteFile::close() {
    if (!closed){
        output_file.close(); // Close the file.
        closed = true; // Set this to true since we just closed the file.
   }
}

/*
WriteFile* createWriteFile(const char* file_name)
{
   WriteFile* wf = new WriteFile;
   wf->output_file.open(file_name);
   wf->closed = false;
   return wf;
}

void destroyWriteFile(WriteFile* wf)
{
   close(wf);
   delete wf;
}

void close(WriteFile* wf)
{
   if (!wf->closed)
   {
      wf->output_file.close();
      wf->closed = true;
   }
}

void writeLine(WriteFile* wf, String* line)
{
   if (!wf->closed && line->length() > 0)
   {
      wf->output_file << line->getText() << endl;
   }
}
*/
