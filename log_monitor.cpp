#include <iostream>
#include <fstream>
const std::string dev_login = "admin";
class LogViewer{
public:
    void static view_logs(){
        std::ifstream("logs.txt",std::ios::in);
    }
};

bool file_exists(const std::string& file_name) {
    std::ifstream file(file_name);
    return file.good();
}
int main(){
    std::cout << "\033[1;30m-[\033[1;32mLOG MONITOR BETA\033[1;30m]- \033[1;31mdevmode\033[0m" << std::endl;
    std::cout << "\033[1;30m[\033[1;31m?\033[1;30m] \033[0mEnter the dev password: ";
    std::string dev_pass;
    std::getline(std::cin, dev_pass);
    if (dev_pass != dev_login){
        std::cout << "\033[1;30m[\033[1;31m!\033[1;30m] \033[0mWrong password!" << std::endl;
        return 1;
    }
    std::cout << "\033[1;32mAcces granted!\033[0m" << std::endl;
    return 0;
}
