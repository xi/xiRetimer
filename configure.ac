AC_INIT([retimer], [0.2], [])
AC_CONFIG_SRCDIR([src/playback.h])

VERSION=0.2
NAME=xiRetimer
AC_SUBST(VERSION)
AC_SUBST(NAME)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

AC_SUBST(_CFLAGS)
AC_SUBST(_PKGC)

# check files
AC_CHECK_FILES(
	/usr/share/icons/gnome/16x16/actions/fileopen.png
	/usr/share/icons/gnome/16x16/actions/document-save.png 
	/usr/share/icons/gnome/16x16/actions/document-properties.png 
	/usr/share/icons/gnome/16x16/actions/window-close.png 
	/usr/share/icons/gnome/16x16/actions/media-playback-start.png 
	/usr/share/icons/gnome/16x16/actions/media-skip-backward.png 
	/usr/share/icons/gnome/16x16/actions/edit-clear.png 
	/usr/share/icons/gnome/16x16/actions/stock_refresh.png 
	/usr/share/icons/gnome/16x16/actions/help-about.png,
	[],[icons="error"])
if test "x$icons" = "x" ; then 
  _CFLAGS="$_CFLAGS -DICONS_GNOME"
  echo "  Compiling with Gnome icons"
else
  _CFLAGS="$_CFLAGS -UICONS_GNOME"
  echo "  Compiling without Gnome icons!"
fi

# Checks for libraries.
AC_CHECK_PROG(HAVE_PKG_CONFIG, pkg-config, yes, no)
if test x$HAVE_PKG_CONFIG = xno ; then
   AC_MSG_ERROR([pkg-config is required for compilation!])
fi

AC_CHECK_PROG(HAVE_WX_CONFIG, wx-config, yes, no)
if test x$HAVE_WX_CONFIG = xno ; then
   AC_MSG_ERROR([wx-config is required for compilation! Is wxWidgets installed?])
fi

AC_CHECK_PROG(HAVE_SDL_CONFIG, sdl-config, yes, no)
if test x$HAVE_SDL_CONFIG = xno ; then
   AC_MSG_ERROR([sdl-config is required for compilation! Is SDL installed?])
fi

PKG_CHECK_MODULES([SNDFILE],[sndfile])

PKG_CHECK_MODULES([RubberBand],[rubberband >= 1.4],
	[
	_CFLAGS="$_CFLAGS -DMODE_RUBBERBAND"
	_PKGC="$_PKGC rubberband"
	 echo "  Compiling with RubberBand support"],
	[
	_CFLAGS="$_CFLAGS -UMODE_RUBBERBAND"
	echo "  Compiling without RubberBand support!"
	])

PKG_CHECK_MODULES([MAD],[mad],
	[
	_CFLAGS="$_CFLAGS -DENABLE_MP3"
#	_PKGC="$_PKGC rubberband"
	 echo "  Compiling with mp3 support"],
	[
	_CFLAGS="$_CFLAGS -UENABLE_MP3"
	echo "  Compiling without mp3 support!"
	])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL

AC_CONFIG_FILES([makefile
	src/gui/retimer_wx.cpp
	])
AC_OUTPUT

