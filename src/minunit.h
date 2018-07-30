/* minunit.h --- 
 * Filename: minunit.h
 * Author: Hamlet zheng
 * Created: Sun Apr  8 22:09:15 2018 (+0800)
 */

/* Copyright zhengdf
 * 
 * 允许免费使用，拷贝，修改，发布，但在所有的拷贝上必须保留上述
 * copyright部分和本使用声明部分，除非显示声明，copyright的持有者
 * 不得作为再发布软件的广告。copyright的持有者对使用本软件的适用范围不做任何声明，
 * 
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */

#ifndef _MIN_UNIT_H_
#define _MIN_UNIT_H_

#include <stdio.h>
#include <time.h>


#define mu_assert(x,fmt, ...)                                           \
  do {                                                                  \
    if( !(x) ) {                                                        \
      fprintf( stdout, "[    FAILED] %s : %d, "fmt"\n", __FILE__, __LINE__, ##__VA_ARGS__ ); \
      return 1;                                                         \
    }                                                                   \
  } while(0);


#define mu_run_test(test) do { \
    fprintf ( stdout, "[RUN       ] %s\n", #test ); \
    clock_t tick = clock(); \
    char *message = test(); \
    tick = clock()-tick; \
    tests_number++; \
    if (message){ fprintf ( stdout, "[    FAILED] %s (%d ms)\n", message, (int)tick ); failed_number++; } \
    else fprintf (stdout, "[        OK] %s (%d ms)\n", #test, (int)tick);  \
    } while (0)

#define mu_run_test1p(test, para1) do {                   \
    fprintf ( stdout, "[RUN       ] %s\n", #test ); \
    clock_t tick = clock(); \
    char *message = test(para1); \
    tick = clock()-tick; \
    tests_number++; \
    if (message){ fprintf ( stdout, "[    FAILED] %s (%d ms)\n", message, (int)tick ); failed_number++; } \
    else fprintf (stdout, "[        OK] %s (%d ms)\n", #test, (int)tick);  \
    } while (0)

#define mu_run_suite(suite) do { \
    suite(); \
    suites_number++; \
    } while (0)


extern int tests_number;
extern int failed_number;
extern int suites_number;
extern char error_msg[256];


#endif /*_MIN_UNIT_H_*/
