#include "globals.h"

#include "artikel.h"
#include "band.h"
#include "bandencentrale.h"
#include "bedrijfsklant.h"
#include "factuur.h"
#include "globals.h"
#include "klant.h"
#include "velg.h"

#include <iostream>

using namespace std;

// ctor
application::application(int argc, char **argv){
    this->_argc = argc;
    this->_argv = argv;

    // set main menu list options
    _menulist_main.push_back("End program");
    _menulist_main.push_back("Client management");
    _menulist_main.push_back("Article management");

    // set client list options
    _menulist_clients.push_back("Back to Main Menu");
    _menulist_clients.push_back("List Clients");
    _menulist_clients.push_back("Add Client");
    _menulist_clients.push_back("Delete Client");
    _menulist_clients.push_back("View Client");

    // set article list options
    _menulist_articles.push_back("Back to Main Menu");
    _menulist_articles.push_back("List Articles");
    _menulist_articles.push_back("Add Article");
    _menulist_articles.push_back("Delete Article");
    _menulist_articles.push_back("Stock/Selling History");
}

// dtor
application::~application(){

}

// login

void application::userLogin(){
    // temp variables
    int selectvalue = 0;
    QString userlevel;

    // print welcome message
    printHeaderText("INFO", "This is the application for selling Tires and Rimms.");

    // get the user level
    do {
        printHeaderText("LOGIN", "Select the user account to log in:");
        printSelectionchoice("", UserLevel_Admin, "Director (autoretrieve database)");
        printSelectionchoice("", UserLevel_User, "Salesman (autoretrieve database)");

        cin >> selectvalue;
        cin.get();
    } while (!(selectvalue == UserLevel_Admin || selectvalue == UserLevel_User));

    // string selection according to user level
    if(selectvalue == UserLevel_Admin){
        userlevel = "Director";
    } else if (selectvalue == UserLevel_User) {
        userlevel = "Salesman";
    }

    // give feedback of the selection
    printSelectionfeedback("LOGIN", selectvalue, userlevel);

    // store it for further handling
    this->_userlevel = selectvalue;
}

void application::selectionMenu(void){
    // do this while the app is being kept alive
    while(this->_app_alive){

        // selection buffer
        int selectvalue = 0;

        if(_app_menuclient){
            // Client menu is selected
                // get the user selection
                selectvalue = menuclient_querySelection();

                // let the menu be selected
                menuclient_menulistItemexecution(selectvalue);

        } else if (_app_menuarticle){
            // Article menu is selected
                // get the user selection
                selectvalue = menuarticle_querySelection();

                // let the menu be selected
                menuarticle_menulistItemexecution(selectvalue);

        } else {
            // Main menu is selected
                // get the user selection
                selectvalue = menumain_querySelection();

                // let the menu be selected
                menumain_menulistItemexecution(selectvalue);

        }
    }
}

int application::menumain_querySelection(void){
    // push and receive main menu selection
    return generalQueryUserselection("MAIN MENU", _menulist_main);
}

void application::menumain_menulistItemexecution(int menuselection){
    // check the input values
    if(menuselection < 1) return;
    if(menuselection > _menulist_main.length()) return;

    // select the input and execute the correct application
    switch (menuselection) {
        case MenuList_Exit:
            menu_exit();
            break;
        case MenuList_Clientlist:
            _app_menuclient = true;
            break;
        case MenuList_Articlelist:
            _app_menuarticle = true;
            break;
    }
}

int application::menuarticle_querySelection(void){
    // push and receive article menu selection
    return generalQueryUserselection("MAIN MENU > ARTICLE MENU", _menulist_articles);
}

void application::menuarticle_menulistItemexecution(int menuselection){
    // check the input values
    if(menuselection < 1) return;
    if(menuselection > _menulist_articles.length()) return;

    // select the input and execute the correct application
    switch (menuselection) {
        case MenuList_Articles_Exit:
            _app_menuarticle = false;
            break;
        case MenuList_Articles_List:

            break;
        case MenuList_Articles_Add:

            break;
        case MenuList_Articles_Delete:

            break;
        case MenuList_Articles_History:

            break;
    }
}

int application::menuclient_querySelection(void){
    // push and receive client menu selection
    return generalQueryUserselection("MAIN MENU > CLIENT MENU", _menulist_clients);
}

void application::menuclient_menulistItemexecution(int menuselection){
    // check the input values
    if(menuselection < 1) return;
    if(menuselection > _menulist_clients.length()) return;

    // select the input and execute the correct application
    switch (menuselection) {
        case MenuList_Clients_Exit:
            _app_menuclient = false;
            break;
        case MenuList_Clients_List:

            break;
        case MenuList_Clients_Add:

            break;
        case MenuList_Clients_Delete:

            break;
        case MenuList_Clients_View:

            break;
    }
}

int application::generalQueryUserselection(QString label, QVector<QString> &stringContainer){
    // print selection header message
    int selectvalue = 0;

    // loop over the possible selections
    do {
        printHeaderText(label, "Please select the functionality you want to run:");
        for(int i = 0; i<stringContainer.length(); i++){
            printSelectionchoice("", i+1, stringContainer.at(i));
        }
        cin >> selectvalue;
        cin.get();
    } while(!(selectvalue >= 1 || selectvalue <= (stringContainer.length()-1) ) );

    // give feedback of the selection
        //printSelectionfeedback(label, selectvalue, stringContainer.at(selectvalue-1));

    // return the selected value
    return selectvalue;
}

void application::printHeaderText(QString label, QString text){
    cout << "------------------------------------------------------------------" << endl;
    cout << "[" << label.toUtf8().constData() << "]\t" << text.toUtf8().constData() << endl;
}

void application::printSelectionchoice(QString label, int selection, QString text){
    cout << label.toUtf8().constData() << "\t[" << selection << "]\t" << text.toUtf8().constData() << endl;
}

void application::printSelectionfeedback(QString label, int selection, QString text){
    cout << "[" << label.toUtf8().constData() << "]\tYour choice is: " << selection << ", you selected: " << text.toUtf8().constData() << endl;

}

void application::menu_exit(void){
    this->_app_alive = false;
    printHeaderText("MAIN MENU > EXIT", "We are closing the application. Bye bye!");
}
