testParticle: testParticle.cpp particle.o
	g++ -g -Wall -fsanitize=address -std=c++20 testParticle.cpp particle.o -o testParticle

testPG: testPg.cc ParticleGraphics.o
	g++ -g -Wall -fsanitize=address -std=c++20 testPG.cc ParticleGraphics.o -o testPG 

ParticleGraphics.o: ParticleGraphics.cpp ParticleGraphics.h
	g++ -g -Wall -fsanitize=address -std=c++20 -c ParticleGraphics.cpp -o ParticleGraphics.o

cell.o: cell.cpp cell.h
	g++ -g -Wall -fsanitize=address -std=c++20 -c cell.cpp -o cell.o

particle.o: particle.h particle.cpp
	g++ -g -Wall -fsanitize=address -std=c++20 -c particle.cpp -o particle.o

particlesystem.o: particlesystem.cpp particlesystem.h
	g++ -g -Wall -fsanitize=address -std=c++20 -c particlesystem.cpp -o particlesystem.o

clean:
	rm -rf core *.o testParticle testPG
