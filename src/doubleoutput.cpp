#include "../header/doubleoutput.hpp"

int DoubleOutput::run() {
    file = open(arguments[space], O_WRONLY | O_APPEND | O_CREAT, 0664);
    dup2(file, 1);
    arguments[space] = '\0';
}
