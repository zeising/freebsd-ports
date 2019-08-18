--- sql/mysqld.cc.orig	2019-06-25 10:23:30 UTC
+++ sql/mysqld.cc
@@ -4795,7 +4795,7 @@ static int init_thread_environment() {
 
 static PSI_memory_key key_memory_openssl = PSI_NOT_INSTRUMENTED;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if defined(LIBRESSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
 #define FILE_LINE_ARGS
 #else
 #define FILE_LINE_ARGS , const char *, int
@@ -4812,7 +4812,7 @@ static void my_openssl_free(void *ptr FILE_LINE_ARGS) 
 
 static void init_ssl() {
 #ifdef HAVE_OPENSSL
-#if !defined(HAVE_WOLFSSL) && !defined(__sun)
+#if !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER) && !defined(__sun)
 #if defined(HAVE_PSI_MEMORY_INTERFACE)
   static PSI_memory_info all_openssl_memory[] = {
       {&key_memory_openssl, "openssl_malloc", 0, 0,
