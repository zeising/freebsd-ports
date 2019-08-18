--- mysys/my_md5.cc.orig	2019-06-25 10:23:30 UTC
+++ mysys/my_md5.cc
@@ -56,7 +56,7 @@ static void my_md5_hash(unsigned char *digest, unsigne
 int compute_md5_hash(char *digest, const char *buf, int len) {
   int retval = 0;
   int fips_mode = 0;
-#if !defined(HAVE_WOLFSSL)
+#if !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER)
   fips_mode = FIPS_mode();
 #endif /* HAVE_WOLFSSL */
   /* If fips mode is ON/STRICT restricted method calls will result into abort,
