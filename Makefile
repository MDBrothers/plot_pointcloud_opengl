CXX_FLAGS = -std=c++11

morton: libplot3d mortonCodeGenerator.cxx
	g++ $(CXX_FLAGS) mortonCodeGenerator.cxx -L. -I. -lplot3d -lGLU -lGL -DGL_GLEXT_PROTOTYPES

libplot3d: plot3d.cpp plot3d.hpp vertexShader.glsl fragmentShader.glsl
	g++ $(CXX_FLAGS) -shared -fPIC plot3d.cpp -o libplot3d.so -lGLU -lGL -DGL_GLEXT_PROTOTYPES

write:
	g++ $(CXX_FLAGS) -shared -fPIC write.cpp -I./ -o libwrite.so

main: libplot3d write
	g++ $(CXX_FLAGS) main.cpp -L./ -I./ -lwrite -lplot3d

all: morton main

clean:
	rm *.so a.out
