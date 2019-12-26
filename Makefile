CC      = /usr/bin/g++
CFLAGS  =  -DICONS_GNOME -DMODE_RUBBERBAND -DENABLE_MP3 -DVERSION=\"0.2\" `sdl-config --cflags` `pkg-config --cflags sndfile rubberband` `wx-config --cppflags`
LDFLAGS = `sdl-config --libs` `pkg-config --libs sndfile rubberband` `wx-config --libs`

xiRetimer: .gui .back
	$(CC) -o xiRetimer *.o $(LDFLAGS)

.gui: src/gui/*.cpp src/gui/*.h
	$(CC) $(CFLAGS) -c src/gui/*.cpp src/gui/*.h
	touch .gui

.back: src/*.cpp src/*.h
	$(CC) $(CFLAGS) -c src/*.cpp src/*.h
	touch .back

.PHONY: clean
clean:
	rm -f *.o src/*.gch src/gui/*.gch .gui .back
