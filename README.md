MOD\_PHP\_NOOP
===

Overview
---
The mod\_php\_noop package provides an Apache module that implements the php\_value and php\_flag htaccess settings as NoOps.

This prevents the 500 internal server error when apache encounters the php\_value or php\_flag options in .htaccess files when mod\_php is not installed.

I created this module when moving to php-fpm. Many of my users were not using the \<IfModule php5_module\> test in their .htaccess files. I didn't want to install php5 on my apache2.4 servers which proxy all php to my php-fpm servers.

For example. PHP via fcgi proxy to a different php-fpm server.

```
LoadModule proxy_module libexec/apache24/mod_proxy.so
LoadModule proxy_fcgi_module libexec/apache24/mod_proxy_fcgi.so

<VirtualHost *:80>
    <FilesMatch \.php$>
        SetHandler proxy:fcgi://10.10.10.10:9000
    </FilesMatch>
</VirtualHost>
```

System Requirements
---
This module has been tested on FreeBSD 10.1 with apache 2.4 mpm-event. It should also work in Linux and Apache 2.2 (mpm-prefork or mpm-worker).

Installation into Apache
---

```
# install and activate the module
make

# build the module.so file
make build

# install the module.so file
make install

# activate the module in httpd.conf
make activate

# cleanup
make clean
```

Using mod\_php\_noop
---
This module doesn't provide any features. Apache will simply ignore php\_flag and php\_value options. It is only a stub to keep apache happy when it encounters php\_flag or php\_value settings in .htaccess files when mod\_php is not loaded.

```
.htaccess

php_value register_globals 0
php_value magic_quotes_gpc 0

```

Will not throw a 500 internal error when mod_php is not installed.

Other Notes
---
You can use [htscanner](https://pecl.php.net/package/htscanner) to apply the php\_value settings from the .htaccess files to the fpm pool.
