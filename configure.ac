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
  echo "  Compiling without Gnome icons!"
fi

# Checks for libraries.
PKG_CHECK_MODULES([SDL],[sdl])
PKG_CHECK_MODULES([sndfile],[sndfile])

PKG_CHECK_MODULES([RubberBand],[rubberband >= 1.4],
	[_CFLAGS="$_CFLAGS -DMODE_RUBBERBAND"
         _PKGC="$_PKGC rubberband"
	 echo "  Compiling with RubberBand support"],
	[ echo "  Compiling without RubberBand support!"])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL

AC_CONFIG_FILES([makefile
	src/gui/retimer_wx.cpp
	])
AC_OUTPUT

