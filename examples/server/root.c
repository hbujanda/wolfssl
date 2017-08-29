#include "server.c"
#include <bsp_api.h>
#include <fservapi.h>

/*
 *
 *  Function: void applicationTcpDown (void)
 *
 *  Description:
 *
 *      This routine will be called by the NET+OS root thread once every 
 *      clock tick while it is waiting for the TCP/IP stack to come up.  
 *      This function can increment a counter everytime it's called to 
 *      keep track of how long we've been waiting for the stack to start.
 *      If we've been waiting too long, then this function can do something
 *      to handle the error.  
 *
 *      This function will not be called once the stack has started.
 *
 *  Parameters:
 *
 *      none
 *
 *  Return Values:
 *
 *      none
 *
 */

void applicationTcpDown (void)

{
    static int ticksPassed = 0;

    ticksPassed++;
/*
 * Code to handle error condition if the stack doesn't come up goes here.
 */
}

static void WaitForSntp(void)
{
	time_t current_time;
	char *c_time_string;

#define SNTP_WAIT_TIME_MS 3000
    printf("Waiting %d seconds to get time from SNTP server....\n", SNTP_WAIT_TIME_MS / 1000);
    tx_thread_sleep(NS_MILLISECONDS_TO_TICKS(SNTP_WAIT_TIME_MS));
	printf("Done waiting....\n");

	current_time = time(NULL);

    if (current_time == ((time_t)-1))
    {
        (void) fprintf(stderr, "Failure to obtain the current time.\n");
        goto exit;
    }

    /* Convert to local time format. */
    c_time_string = ctime(&current_time);

    if (c_time_string == NULL)
    {
        (void) fprintf(stderr, "Failure to convert the current time.\n");
        goto exit;
    }

    /* Print to stdout. ctime() has already added a terminating newline character. */

exit:
    (void) printf("Current time is %s", c_time_string);
}

/*
 *
 *  Function: void applicationStart (void)
 *
 *  Description:
 *
 *      This routine is responsible for starting the user application.  It should 
 *      create any threads or other resources the application needs.
 *
 *      ThreadX, the NET+OS device drivers, and the TCP/IP stack will be running
 *      when this function is called.
 *
 *  Parameters:
 *
 *      none
 *
 *  Return Values:
 *
 *      none
 *
 */

void applicationStart (void)
{
#if 1
   /* Start flash file system and FTP server */
#define FS_VOLUME1                      "FLASH0"
#define FS_VOLUME1_DIR                  FS_VOLUME1 "/"

    int errorCode = 0;
    /* Link FTP server to file system volume and start FTP server */
    errorCode = naFtpFSInit(FS_VOLUME1_DIR, NA_FTP_DEF_USERS); 
    if (errorCode != 0)
    {
        printf("naFtpFSInit Error: %d\n", errorCode);
        goto exit;
    }

    if (NABspFilesystemForCLib == 0)
    {
        printf ("BSP does not include file system for C library\n");
        goto exit;
    }
#else
    /* start FTP server on ram filesystem */
    naFtpDlInit(NA_FTP_DEF_USERS);
#endif

    WaitForSntp();

    tx_thread_sleep(NS_MILLISECONDS_TO_TICKS(1000));

    /* Following call will allow connections from a client application
       started with 'client -h 192.168.1.100 -A ca.crt' arguments 
     */
    {
        char *argv[] = {"server", "-d", "-b", "-c", "FLASH0/server.crt", "-k", "FLASH0/server.key"};
    
        wolfssl_main(7, argv);
    }
exit:
    printf("app end\n");
}

int dc_log_printf(char* format, ...)
{
    va_list args;
    
    va_start(args, (format));
    
    fflush(stdout);
    vprintf(format, args);
    fflush(stdout);
    
    va_end(args);
    
    return 0;
}
