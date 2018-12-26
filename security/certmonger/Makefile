# Created by: Aragon Gouveia <aragon@phat.za.net>
# $FreeBSD: head/x11-wm/spectrwm/Makefile 479249 2018-09-08 12:31:06Z zeising $

PORTNAME=	certmonger
PORTVERSION=	0.79.6
CATEGORIES=	security
MASTER_SITES=	https://releases.pagure.org/${PORTNAME}/

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	certificate manager part of FreeIPA

LICENSE=	GPLv3

LIB_DEPENDS=	libtalloc.so:devel/talloc \
		libtevent.so:devel/tevent \
		libdbus-1.so:devel/dbus \
		libnss3.so:security/nss \
		libplc4.so:devel/nspr \
		libcurl.so:ftp/curl \
		libldap.so:net/openldap24-sasl-client \
		libidn2.so:dns/libidn2 \
		libpopt.so:devel/popt \
		libxmlrpc.so:net/xmlrpc-c \
		libwwwssl.so:www/libwww \
		libexpat.so:textproc/expat2

USES=		autoreconf gettext localbase pkgconfig ssl
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto" \
		OPENSSL_SSL_CFLAGS="-I{OPENSSLINC}" OPENSSL_SSL_LIBS="-L${OPENSSLLIB} -lssl"
CONFIGURE_ARGS=	--disable-systemd --disable-sysvinit

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/certmonger.conf \
		${STAGEDIR}${ETCDIR}/certmonger.conf.sample
.include <bsd.port.mk>
