testParticle: testParticle.o particle.o
	g++ -g -Wall -fsanitize=address -std=c++23 testParticle.o particle.o -o testParticle

# I need to fix testPG. It does not allow me to create the executable;-KD
testPG: testPG.o ParticleGraphics.o
	g++ -g -Wall -fsanitize=address -std=c++23 testPG.o ParticleGraphics.o -o testPG 

testParticle.o: testParticle.cpp particle.cpp particle.h
	g++ -g -Wall -fsanitize=address -std=c++23 -c testParticle.cpp particle.cpp

particle.o: particle.cpp particle.h
	g++ -g -Wall -fsanitize=address -std=c++23 -c particle.cpp

testPG.o: testPG.cc ParticleGraphics.h
	g++ -g -Wall -fsanitize=address -std=c++23 -c testPG.cc

ParticleGraphics.o: ParticleGraphics.cpp ParticleGraphics.h
	g++ -g -Wall -fsanitize=address -std=c++23 -c ParticleGraphics.cpp

# ParticleGraphics.o: ParticleGraphics.cpp ParticleGraphics.h
	# g++ -g -Wall -fsanitize=address -std=c++23 -c ParticleGraphics.cpp -o ParticleGraphics.o

cell.o: cell.cpp cell.h
	g++ -g -Wall -fsanitize=address -std=c++23 -c cell.cpp -c cell.o


particlesystem.o: particlesystem.cpp particlesystem.h
	g++ -g -Wall -fsanitize=address -std=c++23 -c particlesystem.cpp -c particlesystem.o

clean:
	rm -rf core *.o testParticle testPG
