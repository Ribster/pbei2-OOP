#include "globals.h"
#include "application.h"

int main(int argc, char *argv[])
{
    application app(argc, argv);

    // call the user login routine
    app.userLogin();

    // retrieve the database
    app.databaseRetrieve();

    // call the selection menu with underlying function calls
    app.selectionMenu();

    return 0;
}
