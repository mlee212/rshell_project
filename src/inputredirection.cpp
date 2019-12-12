#include "../header/inputredirection.hpp"

int InputRedirection::run() {
    file = open(arguments[space], O_RDONLY | O_EXCL);
    if (file == -1) {
        return -1;
    }
    dup2(file, 0);
    arguments[space] = '\0';
    return 1;
}
