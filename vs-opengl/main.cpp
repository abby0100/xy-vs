
#include <iostream>  

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

int main(int argc, char *argv[]) {
	std::cout << "Hello VS, this is the main function!" << std::endl;
	return 0;
}