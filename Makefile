all: compile link run

compile:
	g++ -c Game.cpp -I"C:\SFML-2.5.1\include" -DSFML_STATIC

link:
	g++ Game.o -o Game -L"C:\SFML-2.5.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows

run:
	Game.exe