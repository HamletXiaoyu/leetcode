/* mu_main.c --- 
 * Filename: mu_main.c
 * Author: Hamlet zheng
 * Created: Sun Apr  8 22:10:45 2018 (+0800)
 */

/* Copyright zhengdf.
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


#include "minunit.h"
#include "mu_suites.h"
#include <stdio.h>

int tests_number; 
int failed_number;
int suites_number;
char error_msg[256];

int main( void )
{
    mu_run_suite(tree_suites);
    mu_run_suite(list_suites);
    mu_run_suite(string_suites);
    mu_run_suite(algorithm_suites);
    mu_run_suite(math_suites);
    mu_run_suite(greedy_suites);
    mu_run_suite(sort_suites);
    mu_run_suite(dp_suites);
    
    if(0==failed_number)
        printf ( "total run %d suites, %d test, ALL PASSED\n", suites_number, tests_number );
    else
        printf ( "total run %d suites, %d test, %d failed\n", suites_number, tests_number, failed_number );
    return 0;
}
