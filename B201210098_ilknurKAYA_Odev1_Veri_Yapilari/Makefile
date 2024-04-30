hepsi: derle calistir
derle:
	g++ -I ./include/ -o ./lib/Konsol.o -c ./src/Konsol.cpp
	g++ -I ./include/ -o ./lib/Exception.o -c ./src/Exception.cpp
	g++ -I ./include/ -o ./lib/Dosya.o -c ./src/Dosya.cpp
	g++ -I ./include/ -o ./lib/Liste.o -c ./src/Liste.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesi.o -c ./src/YoneticiListesi.cpp
	g++ -I ./include/ -o ./lib/Yonetici.o -c ./src/Yonetici.cpp
	g++ -I ./include/ -o ./lib/SatirListesi.o -c ./src/SatirListesi.cpp
	

	g++ -I ./include/ -o ./bin/main ./lib/Konsol.o ./lib/Exception.o ./lib/Dosya.o ./lib/SatirListesi.o ./lib/Liste.o ./lib/YoneticiListesi.o  ./lib/Yonetici.o   ./src/main.cpp

calistir:
	./bin/main