#include "ReadFile.h"
#include <iostream>
#include <string>
#include "Text.h"

ReadFile::ReadFile(const char* file_name) {
   input_file.open(file_name);
   closed = false; // Of course this is false, check the line above!
   _eof = false; // Assume the file isn't empty...

}

ReadFile::~ReadFile() {
    close(); // This will call the function to close the file.
    //delete str;
}

bool ReadFile::eof() {
    return _eof; // Return whether or not we've reached EOF.
}

void ReadFile::close() {
    // Check if file is closed. If it isn't, then go ahead and close it.
    if (!closed) {
        input_file.close();
        closed = true; // We just closed the file on the previous line, so set this to true.
    }
}

String* ReadFile::readLine() {
   if (closed) return NULL; // Can't read the file if it's closed, so return NULL
   if (_eof) return NULL;   // Can't read beyond the last line, so return NULL

   string text;
   _eof = !(getline(input_file, text));

   String* str = new String((const char*) text.c_str()); // How do I delete this pointer if I need its return value? 
   return str;
}

/*
ReadFile* createReadFile(const char* file_name)
{
   ReadFile* rf = new ReadFile;

   rf->input_file.open(file_name);
   rf->closed = false;
   rf->_eof = false;

   return rf;
}

void destroyReadFile(ReadFile* rf)
{
   close(rf);
   delete rf;
}

bool eof(ReadFile* rf)
{
   return rf->_eof;
}

void close(ReadFile* rf)
{
   if (!rf->closed)
   {
      rf->input_file.close();
      rf->closed = true;
   }
}

String* readLine(ReadFile* rf)
{
   if (rf->closed) return NULL;
   if (rf->_eof) return NULL;

   string text;
   rf->_eof = !(getline(rf->input_file, text));

   String* str = new String((const char*) text.c_str());
   return str;
}
*/
