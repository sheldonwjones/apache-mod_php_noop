/* 
**  mod_php_noop.c
**
**    $ apxs -c -i mod_php_noop.c
**
**    # httpd.conf
**    LoadModule php_noop modules/mod_php_noop.so
**
**    $ apachectl restart
*/

#include "httpd.h"
#include "http_config.h"
#include "http_protocol.h"
#include "ap_config.h"

static const char *php_noop_apache_value_handler(cmd_parms *cmd,
                                                 void *dummy,
                                                 const char *name,
                                                 const char *value)
{
    return NULL;
}

/* Taken from https://github.com/php/php-src/blob/PHP-5.6.11/sapi/apache2handler/apache_config.c#L206-L207 */
const command_rec php_noop_dir_cmds[] =
{
    AP_INIT_TAKE2("php_value", php_noop_apache_value_handler, NULL, OR_OPTIONS, "PHP Value Modifier"),
    AP_INIT_TAKE2("php_flag", php_noop_apache_value_handler, NULL, OR_OPTIONS, "PHP Flag Modifier"),
    {NULL}
};

/* API hooks */
module AP_MODULE_DECLARE_DATA php_noop_module = {
    STANDARD20_MODULE_STUFF,
    NULL,                    /* create per-dir    config structures */
    NULL,                    /* merge  per-dir    config structures */
    NULL,                    /* create per-server config structures */
    NULL,                    /* merge  per-server config structures */
    php_noop_dir_cmds,       /* table of htaccess file commands     */
    NULL                     /* register hooks                      */
};
