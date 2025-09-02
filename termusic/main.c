#include <stdio.h>
#include <string.h>
#include <windows.h>

#define TERMUSIC_VERSION 1.0


// ---------------------------------------- realtime settings
BOOL is_debug_enabled = FALSE;



// ---------------------------------------- filesystem
// generates program folders, used on first launch
void fs_makedir(const char* path)
{
    if (!CreateDirectory(path, NULL))
    {
        if (is_debug_enabled)
        {
            printf("Error creating %s.", path);
        }  
        return;
    }
}

// ---------------------------------------- arg functions
// struct made for help with arguments, H_ in the start means "Help"
typedef struct 
{
    // short name
    const char* s_name;
    // full name
    const char* f_name;
    // short description
    const char* s_desc;
    // full description
    const char* f_desc;
} H_Argument;

// NULL-argument
H_Argument nullarg = { NULL, NULL, NULL, NULL };

// all the valid arguments stored here
H_Argument h_arglist[] = 
{ 
    { "-v", "--version", "Shows version.", "Displays current program version." },
    { "-d", "--debug",  "Turn on debug mode.", "Turn on verbose output (debug)."}
};

// used to get argument by its name
H_Argument get_argument(const char* name)
{
    for (int i = 0; i < (sizeof(h_arglist) / sizeof(h_arglist[0])); i++)
    {
        H_Argument arg = h_arglist[i];

        if (strcmp(arg.f_name, name) || strcmp(arg.s_name, name))
        {
            return arg;
        }
    }

    return nullarg;
}

// displays all the arguments 
void help_usage()
{
    printf("Usage termusic.exe -<args>.\n");
    printf("\nArgument list:\n");
    for (int i = 0; i < (sizeof(h_arglist) / sizeof(h_arglist[0])); i++)
    {
        H_Argument arg = h_arglist[i];
        printf("\t%-10s | %s:\t%s\n", arg.f_name, arg.s_name, arg.s_desc); 
    } 
}

// displays help message for selected argument
void help_arg(H_Argument arg)
{
    printf("Usage: termusic.exe %s.\n%-10s | %s: %s\n", arg.f_name, arg.f_name, arg.s_name, arg.f_desc);
}


// ---------------------------------------- entry
// program entry point
int main(int argc, char* argv[])
{
    printf("Welcome to termusic!\n"); 

    
    if (argc >= 2)
    {
        for (int i = 1; i < argc; i++)
        {
            if (strcmp(argv[i], "--help") || strcmp(argv[i], "-h"))
            {
                help_usage();
                break;
            }
        }
    }

    return 0;
}
