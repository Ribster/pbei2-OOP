#include "globals.h"

int main(int argc, char *argv[])
{
    application app(argc, argv);

    // call the user login routine
    app.userLogin();

    // call the selection menu with underlying function calls
    app.selectionMenu();

    return 0;
}
