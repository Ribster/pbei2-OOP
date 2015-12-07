#ifndef GLOBALS_H
#define GLOBALS_H

#include <QString>
#include <QVector>
#include <QTextStream>

#include "databasemanagement.h"

/**
 * @brief  Address structure
 */
typedef struct Adres{
    QString straatnaam;
    QString straatnummer;
    int postcode;
    QString gemeente;
    QString land;
} Adres;

/**
 * @brief  Article types
 */
typedef enum ArtikelType{
    ArtikelType_Band    = 1,
    ArtikelType_Velg    = 2
} ArtikelType;

/**
 * @brief  Client types
 */
typedef enum ClientType{
    ClientType_Personal    = 1,
    ClientType_Business    = 2
} ClientType;

/**
 * @brief  Units of measurement used
 */
typedef enum BreedteUnit{
    BreedteUnit_mm      = 1,
    BreedteUnit_inch    = 2
}BreedteUnit;

/**
 * @brief  Colors used for the rimms
 */
typedef enum Kleuren{
    Kleuren_Rood        = 1,
    Kleuren_Blauw       = 2,
    Kleuren_Goud        = 3
} Kleuren;

/**
 * @brief  Seasons for the tires
 */
typedef enum Seizoen{
    Seizoen_Zomer       = 1,
    Seizoen_Winter      = 2
} Seizoen;

/**
 * @brief  User access levels
 */
typedef enum UserLevel{
    UserLevel_Admin     = 1,
    UserLevel_User      = 2
} UserLevel;

/**
 * @brief  Main Menu selection list
 */
typedef enum MenuList{
    MenuList_Exit           = 1,
    MenuList_Clientlist     = 2,
    MenuList_Articlelist    = 3,
    MenuList_Min            = MenuList_Exit,
    MenuList_Max            = MenuList_Articlelist
} MenuList;

/**
 * @brief  Cient Menu selection list
 */
typedef enum MenuList_Clients {
    MenuList_Clients_Exit   = 1,
    MenuList_Clients_List   = 2,
    MenuList_Clients_Add    = 3,
    MenuList_Clients_Delete = 4,
    MenuList_Clients_View   = 5,
    MenuList_Clients_Min    = MenuList_Clients_Exit,
    MenuList_Clients_Max    = MenuList_Clients_View
} MenuList_Clients;

/**
 * @brief  Article Menu selection list
 */
typedef enum MenuList_Articles {
    MenuList_Articles_Exit      = 1,
    MenuList_Articles_List      = 2,
    MenuList_Articles_Add       = 3,
    MenuList_Articles_Delete    = 4,
    MenuList_Articles_History   = 5,
    MenuList_Articles_Min       = MenuList_Articles_Exit,
    MenuList_Articles_Max       = MenuList_Articles_History
} MenuList_Articles;

const QString globals_director = "Director";
const QString globals_salesman = "Salesman";
const QString globals_info = "INFO";
const QString globals_login = "LOGIN";
const QString globals_itemprefix = "";
const QString globals_menumain = "MAIN MENU";
const QString globals_menuexit = "MAIN MENU > EXIT";
const QString globals_menuarticles = "MAIN MENU > ARTICLE MENU";
const QString globals_menuclients = "MAIN MENU > CLIENT MENU";

class application final
{
public:
    // ctor
    application(int argc, char **argv);
    // dtor
    ~application();

    /**
     * @brief  Asks the user for user access level
     * @param  None
     * @retval None
     */
    void userLogin(void);

    /**
     * @brief  Retrieve the Tire Workshop from the local database
     * @param  None
     * @retval None
     */
    void databaseRetrieve(void);

    /**
     * @brief  Main routine for guiding the user through the possible menu's
     * @param  None
     * @retval None
     */
    void selectionMenu(void);

private:
    /**
     * @brief  Get the user input for the main menu selection
     * @param  None
     * @retval int  Selected menu item
     */
    int menumain_querySelection(void);

    /**
     * @brief  Execute the user selected main menu
     * @param  int  Selected menu item
     * @retval None
     */
    void menumain_menulistItemexecution(int);

    /**
     * @brief  Get the user input for the article menu selection
     * @param  None
     * @retval int  Selected menu item
     */
    int menuarticle_querySelection(void);

    /**
     * @brief  Execute the user selected article menu
     * @param  int  Selected menu item
     * @retval None
     */
    void menuarticle_menulistItemexecution(int);

    /**
     * @brief  Get the user input for the client menu selection
     * @param  None
     * @retval int  Selected menu item
     */
    int menuclient_querySelection(void);

    /**
     * @brief  Execute the user selected client menu
     * @param  int  Selected menu item
     * @retval None
     */
    void menuclient_menulistItemexecution(int);

    /**
     * @brief  Get the user input for the menu selection (general)
     * @param  QString label    The label for print prefix
     * @param  stringContainer  The container for the selection possibilities
     * @retval int  Selected menu item
     */
    int generalQueryUserselection(QString label, QVector<QString> &stringContainer);

    /**
     * @brief  Print the header string with label and text
     * @param  QString  label   The label for print prefix
     * @param  QString  text    The message you want to say
     * @retval None
     */
    void printHeaderText(QString, QString);

    /**
     * @brief  Print the selection choice with a certain label and text
     * @param  QString  label       The label for print prefix
     * @param  int      selection   The selected number in the menu
     * @param  QString  text        The message you want to say
     * @retval None
     */
    void printSelectionchoice(QString, int, QString);

    /**
     * @brief  Print the selection with a certain label and text
     * @param  QString  label       The label for print prefix
     * @param  int      selection   The selected number in the menu
     * @param  QString  text        The message you want to say
     * @retval None
     */
    void printSelectionfeedback(QString, int, QString);

    /**
     * @brief  Menu execution for exiting the program
     * @param  None
     * @retval None
     */
    void menu_exit(void);

    // CLIENTS

    /**
     * @brief  User interface for adding a client
     * @param  None
     * @retval bool Wether the addition of the client was successfull
     */
    bool clients_Add(void);

    // ARTICLES


    // INVOICES


    // ERROR MESSAGE
    /**
     * @brief  Getting the authorization of the current logged in user
     * @param  UserLevel    The user level of the current item
     * @retval bool         Wether the user is authorized
     */
    bool getAuthorized(UserLevel);

private:

    int _argc;
    char **_argv;

    bool _app_alive         = true;
    bool _app_menuclient    = false;
    bool _app_menuarticle   = false;

    int _userlevel;
    QVector<QString> _menulist_main;
    QVector<QString> _menulist_clients;
    QVector<QString> _menulist_articles;

    Bandencentrale *_bandencentrale;
};

#endif // GLOBALS_H

