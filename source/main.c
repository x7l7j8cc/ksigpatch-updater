#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h> // chdir
#include <dirent.h> // mkdir
#include <switch.h>

#include "config.h"
#include "download.h"
#include "tcolor.h"
#include "unzip.h"


const char *OPTION_LIST[] = {
    LOPTION_1 ,LOPTION_2, LOPTION_3, LOPTION_4, LOPTION_5
};
const char *IOPTION_LIST[] = {
    LIOPTION_1 ,LIOPTION_2, LIOPTION_3, LOPTION_4, LOPTION_5
};

/**/
long int findSize(char file_name[]) 
{ 
    FILE* fp = fopen(file_name, "r"); 
  
    if (fp == NULL) { 
        printf("File Not Found!\n"); 
        return -1; 
    } 
  
    fseek(fp, 0L, SEEK_END); 
    long int res = ftell(fp); 
    fclose(fp); 
  
    return res; 
}
/**/

void refreshScreen(int cursor)
{
    consoleClear();
    
    //Change to Cyan Text then to Red
    changeTColor("cyan"); printf("\n%s: v%s.\n", APP_NAME, APP_VERSION);
    changeTColor("red"); printf("Original Code by %s, modded for Kosmos Only by %s\n\n", ORIG_AUTHOR, MODK_AUTHOR);
    
    char file_name[] = { DIR_FILE_PATCHES }; 
    long int res = findSize(file_name); 
    //if (res != -1) printf("Size of the file is %ld bytes \n", res);
    //11552
    
    //Change to White Text
    changeTColor("white"); printf("\nPress (UP/DOWN) to navigate and (A) to select option\nPress (+) to exit\n\n\n");

    changeTColor("green"); //Change to Green Text
    for (int i = 0; i < CURSOR_LIST_MAX + 1; i++)
    {
        if( i == 2 ){
            changeTColor("cyan");
        } else if( i == 3 ){
            changeTColor("white");
        } else if( i == 4 ){
            changeTColor("red");
        } else {
            changeTColor("green");
        }
        
        if( access( DIR_FILE_PATCHES, F_OK ) != -1 ) {
            // file exists
            if( i==2 && res == 11388 ){
                printf("[%c] %s\n\n", cursor == i ? '>' : ' ', OPTION_LIST[i]);
            } else if( i==2 && res != 11388 ){
                printf("[%c] %s\n\n", cursor == i ? '>' : ' ', IOPTION_LIST[i]);
            } else {
                printf("[%c] %s\n\n", cursor == i ? '>' : ' ', OPTION_LIST[i]);
            }
        } else {
            // file doesn't exist
            printf("[%c] %s\n\n", cursor == i ? '>' : ' ', IOPTION_LIST[i]);
        }
    }
    
    consoleUpdate(NULL);
}

void printDisplay(const char *text, ...)
{
    va_list v;
    va_start(v, text);
    vfprintf(stdout, text, v);
    va_end(v);
    consoleUpdate(NULL);
}

int appInit()
{
    consoleInit(NULL);
    socketInitializeDefault();
    return 0;
}

void appRefresh()
{
    appInit();
    refreshScreen(0);
}

void appExit()
{
    socketExit();
    consoleExit(NULL);
}

void kosmosUpdEnd()
{
    changeTColor("magenta"); //Change to Magenta Text
    printf("\nFinished!!!\n\nRemember to Reboot for the patches to be loaded!\n");
    printf("Press + to Exit or Wait 3 Second to Reload Menu.\n");
    consoleUpdate(NULL);
    svcSleepThread(3000000000ull);
    appRefresh();
}
void appUpdEnd()
{
    changeTColor("magenta"); //Change to Magenta Text
    printf("\nApp Updated!!!\n");
    printf("Please Wait 3 Second to Reload Menu.\n");
    consoleUpdate(NULL);
    svcSleepThread(3000000000ull);
    appRefresh();
}
void rmvNLOGEnd()
{
    changeTColor("magenta"); //Change to Magenta Text
    printf("\nNichole Logo Removed!!!\n");
    printf("Please Wait 3 Second to Reload Menu.\n");
    consoleUpdate(NULL);
    svcSleepThread(3000000000ull);
    appRefresh();
}

int main(int argc, char **argv)
{
    // init stuff
    appInit();
    mkdir(APP_PATH, 0777);

    // change directory to root (defaults to /switch/)
    chdir(ROOT);

    // set the cursor position to 0
    short cursor = 0;

    // main menu
    refreshScreen(cursor);

    // muh loooooop
    while(appletMainLoop())
    {
        hidScanInput();
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

        // move cursor down...
        if (kDown & KEY_DOWN)
        {
            if (cursor == CURSOR_LIST_MAX) cursor = 0;
            else cursor++;
            refreshScreen(cursor);
        }

        // move cursor up...
        if (kDown & KEY_UP)
        {
            if (cursor == 0) cursor = CURSOR_LIST_MAX;
            else cursor--;
            refreshScreen(cursor);
        }

        if (kDown & KEY_A)
        {
            changeTColor("yellow"); //Change to Yellow Text
            switch (cursor)
            {
            case UP_MSIG:
                if (downloadFile(SIG_MINI_URL, TEMP_FILE, OFF))
                {
                    unzip(TEMP_FILE);
                    changeTColor("red"); printf("removing temp files...\n");
                    remove(TEMP_FILE);
                    remove(DIR_TINFOIL_PATCH); //removing Tinfoil-Patch (if found)
                    kosmosUpdEnd();
                }
                else
                {
                    printDisplay("Failed to download kosmos sigpatches\n");
                }
                break;

            case UP_FSIG:
                if (downloadFile(SIG_FULL_URL, TEMP_FILE, OFF))
                {
                    unzip(TEMP_FILE);
                    changeTColor("red"); printf("removing temp files...\n");
                    remove(TEMP_FILE);
                    kosmosUpdEnd();
                }
                else
                {
                    printDisplay("Failed to download kosmos sigpatches w/ tinfoil patch\n");
                }
                break;
                
            case UP_HSIG:
                if (downloadFile(SIG_HARK1_URL, TEMP_FILE, OFF))
                {
                    //unzip(TEMP_FILE);
                    changeTColor("red");
                    printf("moving loader file...\n");
                    remove(DIR_FILE_KIP); rename(TEMP_FILE, DIR_FILE_KIP);
                    printf("removing temp file...\n");
                    remove(TEMP_FILE);
                    
                    changeTColor("yellow");
                    if (downloadFile(SIG_HARK2_URL, TEMP_FILE, OFF))
                    {
                        //unzip(TEMP_FILE);
                        changeTColor("red");
                        printf("moving patches file...\n");
                        remove(DIR_FILE_PATCHES); rename(TEMP_FILE, DIR_FILE_PATCHES);
                        printf("removing temp file...\n");
                        remove(TEMP_FILE);
                        kosmosUpdEnd();
                    }
                    else
                    {
                        printDisplay("Failed to download sigpatches by HarukoNX-patchini patch\n");
                    }
                }
                else
                {
                    printDisplay("Failed to download sigpatches by HarukoNX-loader patch\n");
                }
                break;
                
            case UP_RMNL:
                changeTColor("red"); printf("removing nichole logo...\n");
                DIR *theFolder = opendir(DIR_NICHOLELOGO);
                struct dirent *next_file;
                char filepath[380];

                while ( (next_file = readdir(theFolder)) != NULL )
                {
                    sprintf(filepath, "%s/%s", DIR_NICHOLELOGO, next_file->d_name);
                    remove(filepath);
                }
                closedir(theFolder);
                rmdir(DIR_NICHOLELOGO);
                rmvNLOGEnd();
                break;

            case UP_APP:
                if (downloadFile(APP_URL, TEMP_FILE, OFF))
                {
                    changeTColor("red"); printf("installing app file...\n");
                    remove(APP_OUTPUT); rename(TEMP_FILE, APP_OUTPUT); remove(OLD_APP_PATH);
                    appUpdEnd();
                }
                else
                {
                    printDisplay("Failed to download app update\n");
                }
                break;
            }
        }
        
        // exit...
        if (kDown & KEY_PLUS) break;
    }

    // cleanup then exit
    appExit();
    return 0;
}