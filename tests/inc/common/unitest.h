/******************************************************************************
 *                                                                            *
 * This program is distributed in the hope that it will be useful, but        *
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY *
 * or FITNESS FOR A PARTICULAR PURPOSE. This file and program are licensed    *
 * under the GNU Lesser General Public License Version 3, 29 June 2007.       *
 * The complete license can be accessed from the following location:          *
 * http://opensource.org/licenses/lgpl-3.0.html                               *
 *                                                                            *
 * Author: Yun Li         (yunli.open@gmail.com)                              *
 *   Date: 03/06/2010                                                         *
 *                                                                            *
 * Author: Gavin Ding     (gavin_ding@sina.cn / fanfan.ding.ict@gmail.com)    *
 *   Date: 07/07/2013                                                         *
 *                                                                            *
 ******************************************************************************/

/******************************************************************************
  REVISION HISTORY
  ================
 
  Date         Version       Name              Description
  ----------   ------------  ----------------  --------------------------------
  03/17/2013   V001.000.000  Gavin Ding        rewrite this file
  ----------   ------------  ----------------  --------------------------------
  
  Date         Version       Name              Description
  ----------   ------------  ----------------  --------------------------------
  07/07/2013   V001.001.000  Gavin Ding        make it more useful
  ----------   ------------  ----------------  --------------------------------

 ******************************************************************************/

#ifndef __UNITEST_H
#define __UNITEST_H

#include <stdio.h>
#include <string.h>

static int g_case_total     = 0;
static int g_case_succeeded = 0;
static int g_case_failed    = 0;

#ifndef NULL
#define NULL ((void*)0)
#endif

#define INTERNAL_USE_ONLY_SUCCEEDED(_a, _b, _oper) \
    printf("    Expected: \""#_a"\" "#_oper" \""#_b"\"\n      Result: Succeeded\n")
#define INTERNAL_USE_ONLY_FAILED(_a, _b, _oper) \
    printf("    Expected: \""#_a"\" "#_oper" \""#_b"\"\n (X)  Result: Failed\n")    
#define INTERNAL_USE_ONLY_CASE_SHOW() \
    printf("Case %d =====>\n", g_case_total); \
    printf("    Location: %s:%d\n", __FILE__, __LINE__); \

#define UNITEST_ERROR(_string) do { \
    printf("Error: "#_string"\n"); \
    return -1;\
} while (0)

#define UNITEST_EQUALS(_a, _b) do { \
    g_case_total++; \
    INTERNAL_USE_ONLY_CASE_SHOW(); \
    if ((_a) == (_b)) { \
        INTERNAL_USE_ONLY_SUCCEEDED(_a, _b, ==); \
        g_case_succeeded++; \
    } \
    else { \
        INTERNAL_USE_ONLY_FAILED(_a, _b, ==); \
        g_case_failed++; \
    } \
    printf("\n"); \
} while (0)

#define UNITEST_DIFFERS(_a, _b) do { \
    g_case_total++; \
    INTERNAL_USE_ONLY_CASE_SHOW(); \
    if ((_a) == (_b)) { \
        INTERNAL_USE_ONLY_FAILED(_a, _b, !=); \
        g_case_failed++; \
    } \
    else { \
        INTERNAL_USE_ONLY_SUCCEEDED(_a, _b, !=); \
        g_case_succeeded++; \
    } \
    printf("\n"); \
} while (0)

#define UNITEST_LESS_THAN(_a, _b) do { \
    g_case_total++; \
    INTERNAL_USE_ONLY_CASE_SHOW(); \
    if ((_a) < (_b)) { \
        INTERNAL_USE_ONLY_SUCCEEDED(_a, _b, <); \
        g_case_succeeded ++; \
    } \
    else { \
        INTERNAL_USE_ONLY_FAILED(_a, _b, <); \
        g_case_failed++; \
    } \
    printf("\n"); \
} while (0)

#define UNITEST_LESS_THAN_EQUALS(_a, _b) do { \
    g_case_total++; \
    INTERNAL_USE_ONLY_CASE_SHOW(); \
    if ((_a) <= (_b)) { \
        INTERNAL_USE_ONLY_SUCCEEDED(_a, _b, <=); \
        g_case_succeeded++; \
    } \
    else { \
        INTERNAL_USE_ONLY_FAILED(_a, _b, <=); \
        g_case_failed++; \
    } \
    printf("\n"); \
} while (0)

#define UNITEST_GREATER_THAN(_a, _b) do { \
    g_case_total++; \
    INTERNAL_USE_ONLY_CASE_SHOW(); \
    if ((_a) > (_b)) { \
        INTERNAL_USE_ONLY_SUCCEEDED(_a, _b, >); \
        g_case_succeeded++; \
    } \
    else { \
        INTERNAL_USE_ONLY_FAILED(_a, _b, >); \
        g_case_failed++; \
    } \
    printf("\n"); \
} while (0)

#define UNITEST_GREATER_THAN_EQUALS(_a, _b) do { \
    g_case_total++; \
    INTERNAL_USE_ONLY_CASE_SHOW(); \
    if ((_a) >= (_b)) { \
        INTERNAL_USE_ONLY_SUCCEEDED(_a, _b, >=); \
        g_case_succeeded++; \
    } \
    else { \
        INTERNAL_USE_ONLY_FAILED(_a, _b, >=); \
        g_case_failed++; \
    } \
    printf("\n"); \
} while (0)

#define UNITEST_STR_EQUALS(_a, _b) do { \
    g_case_total++; \
    INTERNAL_USE_ONLY_CASE_SHOW(); \
    if ( NULL == (_a) || NULL == (_b) ) { \
        UNITEST_ERROR(ptr should not be NULL); \
    } \
    if ( !strcmp((_a), (_b)) ) { \
        INTERNAL_USE_ONLY_SUCCEEDED(_a, _b, ==); \
        g_case_succeeded++; \
    } \
    else { \
        INTERNAL_USE_ONLY_FAILED(_a, _b, ==); \
        g_case_failed++; \
    } \
    printf("\n"); \
} while (0)

#define UNITEST_STR_DIFFERS(_a, _b) do { \
    g_case_total++; \
    INTERNAL_USE_ONLY_CASE_SHOW(); \
    if ( NULL == (_a) || NULL == (_b) ) { \
        UNITEST_ERROR(ptr should not be NULL); \
    } \
    if ( !strcmp((_a), (_b)) ) { \
        INTERNAL_USE_ONLY_FAILED(_a, _b, !=); \
        g_case_failed++; \
    } \
    else { \
        INTERNAL_USE_ONLY_SUCCEEDED(_a, _b, !=); \
        g_case_succeeded++; \
    } \
    printf("\n"); \
} while (0)

#define UNITEST_MEM_EQUALS(_a, _b, _len) do { \
    g_case_total++; \
    INTERNAL_USE_ONLY_CASE_SHOW(); \
    if ( NULL == (_a) || NULL == (_b) ) { \
        UNITEST_ERROR(ptr should not be NULL); \
    } \
    if ( (_len) <= 0 ) { \
        UNITEST_ERROR(mem len should be positive); \
    } \ 
    if ( !memcmp((void*)(_a),(void*)(_b), (int)(_len)) ) { \
        INTERNAL_USE_ONLY_SUCCEEDED(_a, _b, ==); \
        g_case_succeeded++; \
    } \
    else { \
        INTERNAL_USE_ONLY_FAILED(_a, _b, ==); \
        g_case_failed++; \
    } \
    printf("\n"); \
} while (0)

#define UNITEST_MEM_DIFFERS(_a, _b, _len) do { \
    g_case_total++; \
    INTERNAL_USE_ONLY_CASE_SHOW(); \  
    if ( NULL == (_a) || NULL == (_b) ) { \
        UNITEST_ERROR(ptr should not be NULL); \
    } \
    if ( (_len) <= 0 ) { \
        UNITEST_ERROR(mem len should be positive); \
    } \
    if ( !memcmp((void*)(_a), (void*)(_b), (int)(_len)) ) { \
        INTERNAL_USE_ONLY_FAILED(_a, _b, !=); \
        g_case_failed++; \
    } \
    else { \
        INTERNAL_USE_ONLY_SUCCEEDED(_a, _b, !=); \
        g_case_succeeded++; \
    } \
    printf("\n"); \
} while (0)

static void unitest_bar()
{
    printf("********************************************************\n"); 
    printf("*                      Unit Test                       *\n");
    printf("********************************************************\n");
    printf("\n");
}

static int unitest_report()
{
    printf("\n");
    printf("********************************************************\n"); 
    printf("*                     Test Report                      *\n");
    printf("********************************************************\n");
    
    if (0 == g_case_total) {
        printf("No test case is run\n");
        goto pass;
    }
    printf("    Total: %d\n", g_case_total);
    printf("Succeeded: %d (%d%%)\n", g_case_succeeded, g_case_succeeded * 100 / g_case_total);
    printf("********************************************************\n"); 
    printf("\n");

    if (g_case_total != g_case_succeeded) {
        printf("\n");
        printf(":-( Failed\n");
        printf("\n");
        return -1;
    }

pass:    
    printf("\n");
    printf(":-) Passed\n");
    printf("\n");

    return 0;
}

#ifndef HAVE_MAIN
extern int unitest_main(int _argc, char *_argv[]);

int main(int _argc, char *_argv[])
{
    unitest_bar();
    (void)unitest_main(_argc, _argv);
    return unitest_report();
}
#endif  /* end of HAVE_MAIN */

#endif  /* end of __UNITEST_H */

