build_cpp: 
	rm -rf build/
	cmake -S . -B build
	cmake --build build

run: 
	./build/lab
