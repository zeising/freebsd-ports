--- sql-common/client.cc.orig	2019-06-25 10:23:30 UTC
+++ sql-common/client.cc
@@ -7602,7 +7602,7 @@ int STDCALL mysql_options(MYSQL *mysql, enum mysql_opt
 #endif
       break;
     case MYSQL_OPT_SSL_FIPS_MODE: {
-#if defined(HAVE_OPENSSL) && !defined(HAVE_WOLFSSL)
+#if defined(HAVE_OPENSSL) && !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER)
       char ssl_err_string[OPENSSL_ERROR_LENGTH] = {'\0'};
       ENSURE_EXTENSIONS_PRESENT(&mysql->options);
       mysql->options.extension->ssl_fips_mode = *static_cast<const uint *>(arg);
