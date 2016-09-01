#if !defined READ_FILE
#define READ_FILE

#include "Text.h"

#include <fstream>
using namespace std;

class ReadFile {
    private:
        ifstream input_file;
        bool _eof; // Indicates whether or not we've hit EOF.
        bool closed; // Determine whether or not file is open or closed.
    public:
        ReadFile(const char* file_name); // Constructor
        ~ReadFile(); // Destructor
        String* readLine(); // Does what it says.
        bool eof(); // Fetch _eof, we don't want the user to be able to set this.
        void close(); // Close the file.
};

/*
struct ReadFile
{
   ifstream input_file;
   bool _eof;
   bool closed;
};

ReadFile* createReadFile(const char* file_name);
void destroyReadFile(ReadFile* rf);
String* readLine(ReadFile* rf);
bool eof(ReadFile* rf);
void close(ReadFile* rf);
*/

#endif
