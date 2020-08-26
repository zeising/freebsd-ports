--- eh_trampoline.cc.orig	2020-08-26 10:14:22 UTC
+++ eh_trampoline.cc
@@ -1,6 +1,5 @@
 void cxx_throw();
 
-__attribute((visibility("hidden")))
 int eh_trampoline()
 {
 	struct X { ~X() {} } x;
