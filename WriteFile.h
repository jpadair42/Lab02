#if !defined WRITE_FILE
#define WRITE_FILE

#include "Text.h"

#include <fstream>
using namespace std;

class WriteFile {
    private:
        ofstream output_file; 
        bool closed; // Indicates whether the file is currently open or not. 
    public:
        WriteFile(const char* file_name); // Constructor
        ~WriteFile(); // Destructor
        void writeLine(String* line); // Does what it says.
        void close(); // Close the file.
};

/*
struct WriteFile
{
   ofstream output_file;
   bool closed;
};

WriteFile* createWriteFile(const char* file_name);
void destroyWriteFile(WriteFile* wf);
void writeLine(WriteFile* wf, String* line);
void close(WriteFile* wf);

*/

#endif
