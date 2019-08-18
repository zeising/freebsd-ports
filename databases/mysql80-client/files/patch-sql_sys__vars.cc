--- sql/sys_vars.cc.orig	2019-06-25 10:23:30 UTC
+++ sql/sys_vars.cc
@@ -4377,7 +4377,7 @@ static Sys_var_ulong Sys_max_execution_time(
     HINT_UPDATEABLE SESSION_VAR(max_execution_time), CMD_LINE(REQUIRED_ARG),
     VALID_RANGE(0, ULONG_MAX), DEFAULT(0), BLOCK_SIZE(1));
 
-#ifndef HAVE_WOLFSSL
+#if !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER)
 static bool update_fips_mode(sys_var *, THD *, enum_var_type) {
   char ssl_err_string[OPENSSL_ERROR_LENGTH] = {'\0'};
   if (set_fips_mode(opt_ssl_fips_mode, ssl_err_string) != 1) {
@@ -4390,7 +4390,7 @@ static bool update_fips_mode(sys_var *, THD *, enum_va
 }
 #endif
 
-#ifdef HAVE_WOLFSSL
+#if defined(HAVE_WOLFSSL) || defined(LIBRESSL_VERSION_NUMBER)
 static const char *ssl_fips_mode_names[] = {"OFF", 0};
 #else
 static const char *ssl_fips_mode_names[] = {"OFF", "ON", "STRICT", 0};
@@ -4406,7 +4406,7 @@ static Sys_var_enum Sys_ssl_fips_mode(
     GLOBAL_VAR(opt_ssl_fips_mode), CMD_LINE(REQUIRED_ARG, OPT_SSL_FIPS_MODE),
     ssl_fips_mode_names, DEFAULT(0), NO_MUTEX_GUARD, NOT_IN_BINLOG,
     ON_CHECK(NULL),
-#ifndef HAVE_WOLFSSL
+#if !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER)
     ON_UPDATE(update_fips_mode),
 #else
     ON_UPDATE(NULL),
