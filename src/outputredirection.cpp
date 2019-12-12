#include "../header/outputredirection.hpp"

int OutputRedirection::run() {
    file = open(arguments[space] ,  O_WRONLY | O_CREAT | O_TRUNC, 0664);
    dup2(file, 1);
    arguments[space] = '\0';
}
