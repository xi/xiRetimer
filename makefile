VERSION = 0.2
CC      = /usr/bin/g++
CFLAGS  = -DMODE_RUBBERBAND -DICONS_GNOME -DVERSION=\"$(VERSION)\"
LDFLAGS = `sdl-config --cflags --libs` `pkg-config --cflags --libs rubberband sndfile`

xiRetimer: gui back
	$(CC) $(CFLAGS) -o xiRetimer *.o $(LDFLAGS) `wx-config --cxxflags --libs`

back: src/*.cpp src/*.h
	$(CC) $(CFLAGS) -c src/*.cpp src/*.h $(LDFLAGS)

gui: back src/gui/*.cpp src/gui/*.h
	$(CC) $(CFLAGS) -c src/gui/*.cpp src/gui/*.h $(LDFLAGS) `wx-config --cxxflags --libs`

.PHONY: clean
clean:
	rm -f *.o src/*.gch src/gui/*.gch

