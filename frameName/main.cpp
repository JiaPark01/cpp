#include <iostream>
#include <string>

int main()
{
    std::string name;
    std::cout << "input your name : ";
    std::cin >> name;

    const std::string greeting = "Hello, " + name + "!";    // 연산자 중복 (한번만 더해도 해당)
    const std::string firstLine(greeting.size() + 4, '*');
    const std::string secondLine = "* " + std::string(greeting.size(), ' ') + " *";

    std::cout << firstLine <<std::endl;
    std::cout << secondLine <<std::endl;
    std::cout << "* " << greeting << " *" <<std::endl;
    std::cout << secondLine <<std::endl;
    std::cout << firstLine <<std::endl;

    std::cout << greeting << std::endl;

    return 0;
}