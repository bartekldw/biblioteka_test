#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <chrono>
#include <ctime>
#include <vector>
namespace console {
    void log_err(const std::string& msg) {
        std::cout << "\033[1;30m[\033[1;31m!\033[1;30m]\033[0m " << msg << std::endl;
    }
    void log_err(const std::string& msg, int num) {
        std::cout << "\033[1;30m[\033[1;31m!\033[1;30m]\033[0m " << msg << num << "!" << std::endl;
    }
    void reset_colour() {
        std::cout << "\033[0m";
    }

    void print_special_colour(const std::string& colour) {
        if (colour == "black")
            std::cout << "\033[1;30m";
        else if (colour == "red")
            std::cout << "\033[1;31m";
        else if (colour == "green")
            std::cout << "\033[1;32m";
        else if (colour == "yellow")
            std::cout << "\033[1;33m";
        else if (colour == "blue")
            std::cout << "\033[1;34m";
        else if (colour == "purple")
            std::cout << "\033[1;35m";
        else if (colour == "cyan")
            std::cout << "\033[1;36m";
        else if (colour == "white")
            std::cout << "\033[1;37m";
        else
            std::cout << "\033[1;37m"; // default
    }
    void print_special_liblary(const std::string& style, const std::string& colour, const std::string name) {
        if (style == "classic") {
            std::cout << "\033[1;30m--";
            print_special_colour(colour);
            std::cout << name;
            reset_colour();
            std::cout << "\033[1;30m";
            std::cout << "--";
        }
        else if (style == "ascii") {
            std::cout << "\033[1;30m--[";
            print_special_colour(colour);
            std::cout << name;
            reset_colour();
            std::cout << "\033[1;30m";
            std::cout << "]--";
        }
        else if (style == "retro") {
            std::cout << "\033[1;30m[ SYSTEM: ";
            print_special_colour(colour);
            std::cout << name;
            reset_colour();
            std::cout << "\033[1;30m";
            std::cout << "]\033[0m";
            std::cout << "\033[1;32m";
        }
        else {
            std::cout << "\033[1;30m--";
            std::cout << "--";
            print_special_colour(colour);
            std::cout << name;
            reset_colour();
            std::cout << "\033[1;30m--";
            std::cout << "--";
        }
    }
    bool file_exists(const std::string& file_name) {
        std::ifstream file(file_name);
        return file.good();
    }
    void clear() {std::cout << "\033[2J\033[H";}
    void get_data(int& num, const std::string& communicate) {
        while (true) {
            std::cout << "Enter the " << communicate << ": ";
            std::cin >> num;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Try entering the valid " << communicate << "!" << std::endl;
                continue;
            }
            else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
    }
    void get_data(std::string& s_data, const std::string& communicate) {
        while (true) {
            std::cout << "Enter the " << communicate << ": ";
            std::getline(std::cin, s_data);
            if (std::cin.fail() || s_data.empty()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Try entering the valid data!" << std::endl;
                continue;
            }
            else{break;}
        }
    }
    void get_data(int& num, const std::string& communicate, bool should_allocate) {
        std::string s_data;
        while (true) {
            std::cout << "Enter the " << communicate << ": (leave alone when should automatically decide) ";
            std::getline(std::cin, s_data);
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Try entering the valid data!" << std::endl;
                continue;
            }
            else{break;}
        }

        if (!s_data.empty()) {
            num= std::stoi(s_data);
        }
    }
    void get_data(int& choice) {
        while (true) {
            std::cout << "Enter the operation: \033[1;30m";
            std::cin >> choice;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Try entering the valid data!" << std::endl;
                continue;
            }
            else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
    }

    void end_module() {
        std::cout << "Click ENTER to continue..." << std::endl;
        std::cin.get();
    }
    void end_module(bool exiting_program) {
        clear();
        std::cout << "\033[1;30m[\033[1;32mLibrary Managment\033[1;30m]\033[0m\n";
        std::cout << "Click ENTER to exit... ";
        std::cin.get();

    }
}

class LogWriter {
public:
    void static clear_log() {
        std::ofstream log("logs.txt", std::ios::trunc);
        log.close();
    }
    void static write_log(const std::string& log_text) {
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        std::tm* local_time = std::localtime(&now_time);
        std::ofstream log("logs.txt",std::ios::out | std::ios::app);
        log << "[" << local_time->tm_hour << ":" << local_time->tm_min << ":" << local_time->tm_sec << "]: " << log_text << "\n";
        log.close();
    }
    void static write_log(const std::string& log_text, const std::string& log_var) {
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        std::tm* local_time = std::localtime(&now_time);
        std::ofstream log("logs.txt",std::ios::out | std::ios::app);
        log << "[" << local_time->tm_hour << ":" << local_time->tm_min << ":" << local_time->tm_sec << "]: " << log_text << " " << log_var << "\n";
        log.close();
    }
    void static write_log(const std::string& log_text, const std::string& log_var, const std::string& s_continuation) {
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        std::tm* local_time = std::localtime(&now_time);
        std::ofstream log("logs.txt",std::ios::out | std::ios::app);
        log << "[" << local_time->tm_hour << ":" << local_time->tm_min << ":" << local_time->tm_sec << "]: " << log_text << log_var << " " << s_continuation << "\n";
        log.close();
    }

    void static write_log_err(const std::string& log_text) {
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        std::tm* local_time = std::localtime(&now_time);
        std::ofstream log("logs.txt",std::ios::out | std::ios::app);
        log << "[" << local_time->tm_hour << ":" << local_time->tm_min << ":" << local_time->tm_sec << "]: " << log_text << " [ERROR]" << "\n";
        log.close();
    }
    void static write_log_warning(const std::string& log_text) {
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        std::tm* local_time = std::localtime(&now_time);
        std::ofstream log("logs.txt",std::ios::out | std::ios::app);
        log << "[" << local_time->tm_hour << ":" << local_time->tm_min << ":" << local_time->tm_sec << "]: " << log_text << " [WARNING]" << "\n";
        log.close();
    }
};
class FileManagement { //FileManagement class to manage text files
private:
    void static export_book_data(const std::string& line, int& id, std::string& name, std::string& author, int& year) { //export whole string to few variables as id, name, author and year
        int index = 0;
        std::string id_string; std::string year_string;
        while (line[index] != ';') {
            id_string += line[index];
            index++;
        }
        index++;
        while (line[index] != ';') {
            name += line[index];
            index++;
        }
        index++;
        while (line[index] != ';') {
            author += line[index];
            index++;
        }
        index++;
        while (index < line.size()) {
            year_string += line[index];
            index++;
        }

        id = std::stoi(id_string);
        year = std::stoi(year_string);
    }
    void static print_book_data(int id, const std::string& name, const std::string& author, int year) { //print book data in a pretty formatting style
        std::cout << name << " (" << id << "):" << std::endl;
        std::cout << "\tAuthor: " << author << std::endl;
        std::cout << "\tID: " << id << std::endl;
    }
public: //public modules that can be used outside function
    std::string file_name; //the variable that holds the file name as a string
    bool save_data(int id, const std::string& name, const std::string& author, int year) { //bool function to determinate if the file has been edited successfully or not
        std::ofstream file_save(file_name, std::ios::out | std::ios::app);
        if (file_save.is_open()) {
            file_save << id << ";" << name << ";" << author << ";" << year << "\n";
            file_save.close();
            return true;
        }
        else {
            return false;
        }
    }
    bool print_books() { //bool function to print all books in a file that determinate if the file has loaded successfully
        std::ifstream file_load(file_name, std::ios::in);
        if (file_load.is_open()) {
            std::string line;
            while (std::getline(file_load, line)) {
                int id = 0;
                int year = 0;
                std::string name;
                std::string author;
                export_book_data(line, id, name, author, year);
                print_book_data(id, name, author, year);
            }
            file_load.close();
            return true;
        }
        else {
            return false;
        }
    }
};

struct Book { //struct to hold the book data
    int id;
    std::string name;
    std::string author;
    int year;
};
class Library { //class that manages book data
public:
    std::string file;
    std::string name;
    std::string colour;
    std::string style;
    void display_menu() {
        console::clear();
        console::print_special_liblary(style, colour, name);
        std::cout << " menu..." << std::endl;
        console::reset_colour();
        std::cout << "1. Add book" << std::endl;
        std::cout << "2. Display books" << std::endl;
        std::cout << "3. Edit libraries" << std::endl;
        std::cout << "4. Exit" << std::endl;
    }
    void add_book(std::vector<Book>& books) {
        console::clear();
        console::print_special_liblary(style, colour, name);
        std::cout << " adding book..." << std::endl;
        console::reset_colour();
        int id;
        std::string name;
        std::string author;
        int year;
        bool should_allocate_id = false;
        console::get_data(id, "id", should_allocate_id);
        console::get_data(name, "name");
        console::get_data(author, "author");
        console::get_data(year, "year");

        Book book;
        book.id = id;
        book.name = name;
        book.author = author;
        book.year = year;

        books.push_back(book);
        FileManagement file_save;
        file_save.file_name = file;
        file_save.save_data(id, name, author, year);
        std::cout << "\033[1;32m[SUCCESS]\033[0m \033[1;30mSuccessfully added \033[1;37m" << name << " \033[1;30mto library!\033[0m" << std::endl;
        console::end_module();

    }
    void print_books() {
        console::clear();
        console::print_special_liblary(style, colour, name);
        std::cout << " displaying books..." << std::endl;
        console::reset_colour();
        FileManagement file_save;
        file_save.file_name = file;
        file_save.print_books();
        std::cout << "\033[1;32m[SUCCESS]\033[0m \033[1;30mSuccessfully displayed all books!\033[0m" << std::endl;
        console::end_module();
    }

};


class LibraryCreator {
private:
    void static export_library_data(const std::string& line, std::string& name, std::string&colour, std::string& style) { //export whole string to few variables as id, name, author and year
        int index = 0;
        while (line[index] != ';') {
            name += line[index];
            index++;
        }
        index++;
        while (line[index] != ';') {
            colour += line[index];
            index++;
        }
        index++;
        while (index < line.size()) {
            style += line[index];
            index++;
        }
    }
public:
    std::string file_name;
    bool save_library(const std::string& name, const std::string colour, const std::string style) {
        std::ofstream file_save(file_name, std::ios::out | std::ios::app);
        if (file_save.is_open()) {
            file_save << name << ";" << colour << ";" << style << "\n";
            file_save.close();
            return true;
        }
        return false;
    }
    bool create_library(std::vector<Library>& lib_dat) {
        if (console::file_exists(file_name)) {
            std::ifstream file_load("library.txt",std::ios::in);
            if (file_load.is_open()) {
                LogWriter::write_log("Loaded library.txt data file succesfully");
                std::string line;
                std::string name, colour, style;
                while (std::getline(file_load, line)) {
                    export_library_data(line, name, colour, style);
                    Library librarycur;
                    librarycur.name = name;
                    librarycur.colour = colour;
                    librarycur.style = style;
                    librarycur.file = "library.txt";
                    lib_dat.push_back(librarycur);
                    LogWriter::write_log("Succesfully added library ",name,"to object vector");
                    name = ""; colour = ""; style = "";
                }
                LogWriter::write_log("Succesfully converted text file data to object vector of libraries data");
                return true;
            }
            else {
                LogWriter::write_log_err("Error while trying to acces the library data file. Try checking the working directory of the project");
                return false;
            }
        }
        else {
            LogWriter::write_log("Opened the library creator as there is no valid library");
            std::cout << "\033[1;30m[\033[1;32mLibrary Managment\033[1;30m]\033[0m\nHey! ";
            std::cout << "Looks like you have never used this Library Managment. " << std::endl;
            std::cout << "To continue, please agree to create your own library (Y/n): \033[1;30m";
            std::string choice;

            do {
                std::getline(std::cin, choice);
                if (choice != "Y" && choice != "y" && choice != "N" && choice != "n" && choice != "") {
                    console::log_err("Please enter a valid confirmation!");
                    LogWriter::write_log_warning("Invalid syntax of user input while asking for permission for creating a library");

                    std::cout << "To continue, please agree to create your own library (Y/n): \033[1;30m";
                }
                else {
                    break;
                }
            }while (true);
            std::cout << "\033[0m";
            if (choice == "" || choice == "Y" || choice == "y") {
                LogWriter::write_log("User accepted to create a library");
                console::clear();
                LogWriter::write_log("Asking the user for the name of the library");
                std::cout << "\033[1;30m[\033[1;32mLibrary Managment\033[1;30m]\033[0m\n";
                std::cout << "\033[1;30m[\033[1;32m?\033[1;30m]\033[0m Enter the name of your library: \033[1;30m";
                std::string name;
                std::string colour_string;
                do {
                    std::getline(std::cin, name);
                    if (name.empty()) {
                        LogWriter::write_log_warning("User tried to create an empty library");
                        console::log_err("A library name cannot be empty!");
                        std::cout << "\033[1;30m[\033[1;32m?\033[1;30m]\033[0m Enter the name of your library: \033[1;30m";
                    }
                    else{ break;}
                } while (true);
                LogWriter::write_log("Succesfully got the library name:", name);
                LogWriter::write_log("Asking the user for the color of ",name,"library");
                int colour = 0;
                int* type_of_warning = new int{0};
                do{
                    console::clear();
                    std::cout << "\033[1;30m[\033[1;32mLibrary Managment\033[1;30m]\033[0m\n";
                    std::cout << "1. \033[1;30m" << name << " (black)\033[0m" << std::endl;
                    std::cout << "2. \033[1;31m" << name << " (red)\033[0m" << std::endl;
                    std::cout << "3. \033[1;32m" << name << " (green)\033[0m" << std::endl;
                    std::cout << "4. \033[1;33m" << name << " (yellow)\033[0m" << std::endl;
                    std::cout << "5. \033[1;34m" << name << " (blue)\033[0m" << std::endl;
                    std::cout << "6. \033[1;35m" << name << " (purple)\033[0m" << std::endl;
                    std::cout << "7. \033[1;36m" << name << " (cyan)\033[0m" << std::endl;
                    std::cout << "8. \033[1;37m" << name << " (white)\033[0m" << std::endl;
                    if (*type_of_warning == 1) {
                        console::log_err("Please enter a valid data!");
                    }
                    else if (*type_of_warning == 2) {
                        console::log_err("Please choose a number between 1 and 8!");
                    }
                    std::cout << "\033[1;30m[\033[1;32m?\033[1;30m]\033[0m Which colour would you like to use in your library display: \033[1;30m";
                    std::cin >> colour;

                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        LogWriter::write_log_warning("User tried to enter wrong type of data");
                        *type_of_warning = 1;
                    }
                    else if (colour < 1 || colour > 8) {
                        LogWriter::write_log_warning("User tried to enter the wrong range of numbers");
                    }
                    else {
                        break;
                    }
                } while (true);
                delete type_of_warning;


               switch (colour) {
                   case 1:
                       colour_string = "black";
                       break;
                   case 2:
                       colour_string = "red";
                       break;
                   case 3:
                       colour_string = "green";
                       break;
                   case 4:
                       colour_string = "yellow";
                       break;
                   case 5:
                       colour_string = "blue";
                       break;
                   case 6:
                       colour_string = "purple";
                       break;
                   case 7:
                       colour_string = "cyan";
                       break;
                   case 8:
                       colour_string = "white";
                       break;


               }
                LogWriter::write_log("Succesfully added ",colour_string, "colour to the library");
                int style = 0;

                int* type_of_warning_style = new int{0};
                do{
                    console::clear();
                    std::cout << "\033[1;30m[\033[1;32mLibrary Managment\033[1;30m]\033[0m\n";
                    std::cout << "1. \033[1;30m--";
                    console::print_special_colour(colour_string);
                    std::cout << name << "\033[1;30m-- (\033[0mclassic\033[1;30m)\033[0m\n";


                    std::cout << "2. \033[1;30m--[";
                    console::print_special_colour(colour_string);
                    std::cout << name << "\033[1;30m]-- (\033[0macscii\033[1;30m)\033[0m\n";

                    std::cout << "3. \033[1;30m[ SYSTEM: ";
                    console::print_special_colour(colour_string);
                    std::cout << name;
                    std::cout << "\033[1;30m";
                    std::cout << "] (\033[0mretro\033[1;30m)\033[0m\n";
                    if (*type_of_warning_style == 1) {
                        console::log_err("Please enter a valid data!");
                    }
                    else if (*type_of_warning_style == 2) {
                        console::log_err("Please choose a number between 1 and 3!");
                    }
                    std::cout << "\033[1;30m[\033[1;32m?\033[1;30m]\033[0m Which style would you like to use in your library display: \033[1;30m";
                    std::cin >> style;
                    if (std::cin.fail()) {
                        LogWriter::write_log_warning("User tried to enter wrong type of data");
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        *type_of_warning_style = 1;
                    }
                    else if (style < 1 || style > 3) {
                        LogWriter::write_log_warning("User tried to enter the wrong range of numbers");
                        *type_of_warning_style = 2;
                    }
                    else {
                        break;
                    }
                } while (true);
                delete type_of_warning_style;
                std::string style_string;
                switch(style) {
                    case 1:
                        style_string = "classic";
                        break;
                    case 2:
                        style_string = "ascii";
                        break;
                    case 3:
                        style_string = "retro";
                        break;
                    default:
                        break;
                }
                LogWriter::write_log("Succesfully added ",style_string,"style to the library");
                console::clear();
                std::cout << "\033[1;30m[\033[1;32mLibrary Managment\033[1;30m]\033[0m\n";
                if (save_library(name, colour_string, style_string)) {
                    LogWriter::write_log("Succesfull creation of ",name,"library");
                    std::cout << "\033[1;30m[\033[1;32mSUCCESS\033[1;30m]\033[0m Successfully created ";
                    console::print_special_colour(colour_string);
                    std::cout << name << "\033[0m library!" << std::endl;

                }
                else {
                    LogWriter::write_log_err("Couldn't create library.txt file. Try checking the working directory of the program");
                    console::log_err("Unexpected error while trying to create library data! Check logs.txt for more info...");

                }
                console::end_module();
                return true;
            }
            else {
                return false;
            }


        }
    }

    void static manage_libraries(int library_id_current, std::vector<Library>& libraries) {
        LogWriter::write_log("Displaying libraries management menu");
        int choice;
        int* type_of_warning = new int {0};
        do{
            console::clear();
            std::cout << "\033[1;30m[\033[1;32mLibrary Managment\033[1;30m]\033[0m\n";
            std::cout << "Current working library: ";
            console::print_special_liblary(libraries[library_id_current].style, libraries[library_id_current].colour,libraries[library_id_current].name);
            console::reset_colour();
            std::cout << "\n1. Select other library" << std::endl;
            std::cout << "2. Manage libraries" << std::endl;
            std::cout << "3. Go back" << std::endl;
            if (*type_of_warning == 1) {
                console::log_err("Please enter a valid data!");
            }
            else if (*type_of_warning == 2) {
                console::log_err("Please choose a number between 1 and 3!");
            }
            std::cout << "\033[1;30m[\033[1;32m?\033[1;30m]\033[0m Select action: \033[1;30m";
            std::cin >> choice;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                LogWriter::write_log_warning("User tried to enter wrong type of data");
                *type_of_warning = 1;
            }
            else if (choice < 1 ||choice > 3) {
                LogWriter::write_log_warning("User tried to enter the wrong range of numbers");
                *type_of_warning = 2;
            }
            else {
                break;
            }
        } while (true);
        *type_of_warning = 0;
        int library_choice;
        if (choice == 2) {
            int library_choice;
            int* type_of_warning_lib_ch = new int {0};
            do{
                console::clear();
                std::cout << "\033[1;30m[\033[1;32mLibrary Managment\033[1;30m]\033[0m\n";
                std::cout << "All libraries:" << std::endl;
                int count = 0;
                for (auto element : libraries) {
                    std::cout << ++count << ". ";
                    console::print_special_liblary(element.style, element.colour, element.name);
                    console::reset_colour();
                    std::cout << std::endl;
                }
                int count_copy = count;

                if (*type_of_warning == 1) {
                    console::log_err("Please enter a valid data!");
                }
                else if (*type_of_warning == 2) {
                    console::log_err("Please choose a number between 1 and ",count_copy);
                }
                std::cout << "\033[1;30m[\033[1;32m?\033[1;30m]\033[0m Select the library you want to edit: \033[1;30m";
                std::cin >> library_choice;

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    LogWriter::write_log_warning("User tried to enter wrong type of data");
                    *type_of_warning = 1;

                }
                else if (library_choice < 1 ||library_choice > count_copy) {
                    LogWriter::write_log_warning("User tried to enter the wrong range of numbers");
                    *type_of_warning = 2;

                }
                else {
                    break;
                }
            } while (true);
            *type_of_warning = 0;


            library_choice--;
            int action_choice;
            do{
                console::clear();
                std::cout << "\033[1;30m[\033[1;32mLibrary Managment\033[1;30m]\033[0m\n";
                console::print_special_liblary(libraries[library_choice].style, libraries[library_choice].colour,libraries[library_choice].name);
                console::reset_colour();
                std::cout << "\n1. Change name \033[1;30m(" << libraries[library_choice].name << ")\033[0m" << std::endl;
                std::cout << "2. Change colour \033[1;30m(";
                console::print_special_colour(libraries[library_choice].colour);
                std::cout << libraries[library_choice].colour;
                std::cout << "\033[1;30m)\n";
                console::reset_colour();
                std::cout << "3. Change style \033[1;30m(";
                std::string style = libraries[library_choice].style;
                if (style == "classic") {
                    std::cout << "--classic--";
                }
                else if (style == "ascii") {
                    std::cout << " --[ascii]--";
                }
                else if (style == "retro") {
                    std::cout << "\033[1;30m[retro]";
                }
                else {
                    std::cout << "--classic--";
                }
                std::cout << "\033[1;30m)\033[0m\n";
                if (*type_of_warning == 1) {
                    console::log_err("Please enter a valid data!");
                }
                else if (*type_of_warning == 2) {
                    console::log_err("Please choose a number between 1 and 3!");
                }
                std::cout << "\033[1;30m[\033[1;32m?\033[1;30m]\033[0m Select action: \033[1;30m";
                std::cin >> action_choice;

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    LogWriter::write_log_warning("User tried to enter wrong type of data");
                    *type_of_warning = 1;
                }
                else if (action_choice < 1 ||action_choice > 3) {
                    LogWriter::write_log_warning("User tried to enter the wrong range of numbers");
                    *type_of_warning= 2;
                }
                else {
                    break;
                }
            } while (true);
            *type_of_warning = 0;
            if (action_choice == 1) {
                std::string new_name;
                do {
                    console::clear();
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\033[1;30m[\033[1;32mLibrary Managment\033[1;30m]\033[0m\n";
                    std::cout << "Old name: ";
                    console::print_special_colour(libraries[library_choice].colour);
                    std::cout << libraries[library_choice].name << std::endl;
                    if (*type_of_warning) {
                        console::log_err("A name cannot be empty!");
                    }
                    std::cout << "\033[1;30m[\033[1;32m?\033[1;30m]\033[0m What should the new name be: \033[1;30m";
                    std::getline(std::cin, new_name);
                    if (new_name.empty()) {
                        *type_of_warning = 1;
                    }
                    else {
                        break;
                    }
                } while (true);
                libraries[library_choice].name = new_name;

                std::ofstream library_management_file("library.txt", std::ios::out | std::ios::trunc);
                if (library_management_file.is_open()) {
                    for (auto element : libraries) {
                        library_management_file << element.name << ";" << element.colour << ";" << element.style << "\n";
                    }
                    library_management_file.close();
                }
                else {
                    LogWriter::write_log_err("Error while trying to load library data file. Try checking your working directory of the program");
                    return;
                }

            }
            else if (action_choice == 2) {
                int colour = 0;
                std::string colour_string;
                *type_of_warning = 0;
                do{
                    console::clear();
                    std::cout << "\033[1;30m[\033[1;32mLibrary Managment\033[1;30m]\033[0m\n";
                    std::cout << "1. \033[1;30m" << libraries[library_choice].name << " (black)\033[0m" << std::endl;
                    std::cout << "2. \033[1;31m" << libraries[library_choice].name << " (red)\033[0m" << std::endl;
                    std::cout << "3. \033[1;32m" << libraries[library_choice].name << " (green)\033[0m" << std::endl;
                    std::cout << "4. \033[1;33m" << libraries[library_choice].name << " (yellow)\033[0m" << std::endl;
                    std::cout << "5. \033[1;34m" << libraries[library_choice].name << " (blue)\033[0m" << std::endl;
                    std::cout << "6. \033[1;35m" << libraries[library_choice].name << " (purple)\033[0m" << std::endl;
                    std::cout << "7. \033[1;36m" << libraries[library_choice].name << " (cyan)\033[0m" << std::endl;
                    std::cout << "8. \033[1;37m" << libraries[library_choice].name << " (white)\033[0m" << std::endl;
                    if (*type_of_warning == 1) {
                        console::log_err("Please enter a valid data!");
                    }
                    else if (*type_of_warning == 2) {
                        console::log_err("Please choose a number between 1 and 8!");
                    }
                    std::cout << "\033[1;30m[\033[1;32m?\033[1;30m]\033[0m Which colour would you like to use: \033[1;30m";
                    std::cin >> colour;

                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        LogWriter::write_log_warning("User tried to enter wrong type of data");
                        *type_of_warning = 1;
                    }
                    else if (colour < 1 || colour > 8) {
                        LogWriter::write_log_warning("User tried to enter the wrong range of numbers");
                    }
                    else {
                        break;
                    }
                } while (true);
                delete type_of_warning;
                switch (colour) {
                    case 1:
                        colour_string = "black";
                        break;
                    case 2:
                        colour_string = "red";
                        break;
                    case 3:
                        colour_string = "green";
                        break;
                    case 4:
                        colour_string = "yellow";
                        break;
                    case 5:
                        colour_string = "blue";
                        break;
                    case 6:
                        colour_string = "purple";
                        break;
                    case 7:
                        colour_string = "cyan";
                        break;
                    case 8:
                        colour_string = "white";
                        break;

                }
                libraries[library_choice].colour = colour_string;

                std::ofstream library_management_file("library.txt", std::ios::out | std::ios::trunc);
                if (library_management_file.is_open()) {
                    for (auto element : libraries) {
                        library_management_file << element.name << ";" << element.colour << ";" << element.style << "\n";
                    }
                    library_management_file.close();
                }
                else {
                    LogWriter::write_log_err("Error while trying to load library data file. Try checking your working directory of the program");
                    return;
                }
            }
            else if (action_choice == 3) {
                int colour = 0;
                std::string colour_string;
                *type_of_warning = 0;
                do{
                    console::clear();
                    std::cout << "\033[1;30m[\033[1;32mLibrary Managment\033[1;30m]\033[0m\n";
                    std::cout << "1. \033[1;30m" << libraries[library_choice].name << " (black)\033[0m" << std::endl;
                    std::cout << "2. \033[1;31m" << libraries[library_choice].name << " (red)\033[0m" << std::endl;
                    std::cout << "3. \033[1;32m" << libraries[library_choice].name << " (green)\033[0m" << std::endl;
                    std::cout << "4. \033[1;33m" << libraries[library_choice].name << " (yellow)\033[0m" << std::endl;
                    std::cout << "5. \033[1;34m" << libraries[library_choice].name << " (blue)\033[0m" << std::endl;
                    std::cout << "6. \033[1;35m" << libraries[library_choice].name << " (purple)\033[0m" << std::endl;
                    std::cout << "7. \033[1;36m" << libraries[library_choice].name << " (cyan)\033[0m" << std::endl;
                    std::cout << "8. \033[1;37m" << libraries[library_choice].name << " (white)\033[0m" << std::endl;
                    if (*type_of_warning == 1) {
                        console::log_err("Please enter a valid data!");
                    }
                    else if (*type_of_warning == 2) {
                        console::log_err("Please choose a number between 1 and 8!");
                    }
                    std::cout << "\033[1;30m[\033[1;32m?\033[1;30m]\033[0m Which colour would you like to use: \033[1;30m";
                    std::cin >> colour;

                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        LogWriter::write_log_warning("User tried to enter wrong type of data");
                        *type_of_warning = 1;
                    }
                    else if (colour < 1 || colour > 8) {
                        LogWriter::write_log_warning("User tried to enter the wrong range of numbers");
                    }
                    else {
                        break;
                    }
                } while (true);
                delete type_of_warning;
                switch (colour) {
                    case 1:
                        colour_string = "black";
                        break;
                    case 2:
                        colour_string = "red";
                        break;
                    case 3:
                        colour_string = "green";
                        break;
                    case 4:
                        colour_string = "yellow";
                        break;
                    case 5:
                        colour_string = "blue";
                        break;
                    case 6:
                        colour_string = "purple";
                        break;
                    case 7:
                        colour_string = "cyan";
                        break;
                    case 8:
                        colour_string = "white";
                        break;

                }
                libraries[library_choice].colour = colour_string;

                std::ofstream library_management_file("library.txt", std::ios::out | std::ios::trunc);
                if (library_management_file.is_open()) {
                    for (auto element : libraries) {
                        library_management_file << element.name << ";" << element.colour << ";" << element.style << "\n";
                    }
                    library_management_file.close();
                }
                else {
                    LogWriter::write_log_err("Error while trying to load library data file. Try checking your working directory of the program");
                    return;
                }
            }




        }


    }
};
int main() {
    LogWriter::clear_log();
    LibraryCreator create;
    create.file_name = "library.txt";
    std::vector<Library> libraries;
    create.create_library(libraries);

    std::vector<Book> books;
    while (true) {
        LogWriter::write_log("Displaying main menu");
        int choice;
        libraries[0].display_menu();
        console::get_data(choice);
        std::cout << "\033[0m";
        if (choice == 1) {
            LogWriter::write_log("User is adding a book");
            libraries[0].add_book(books);
        }
        else if (choice == 2) {
            LogWriter::write_log("Displaying books");
            libraries[0].print_books();
        }
        else if (choice == 3) {
            LogWriter::write_log("Opening the libraries menu");
            create.manage_libraries(0, libraries);
        }
        else if (choice == 4) {
            break;
        }

    }


    console::end_module(true);


    return 0;
}
