#include <iostream>
#include <string>

int main() {
	std::string fizz = "Fizz";
	std::string buzz = "Buzz";

	for(int i = 1; i <= 100; i++) {
		if(i % 15 == 0) {
			std::cout << fizz << buzz;
		}
		else if(i % 3 == 0) {
			std::cout << fizz;
		}
		else if(i % 5 == 0) {
			std::cout << buzz;
		}
		else {
			std::cout << i;
		}
		// if(i % 3 != 0 && i % 5 != 0) {
		// 	std::cout << i;
		// }
		std::cout << std::endl;
	}
}