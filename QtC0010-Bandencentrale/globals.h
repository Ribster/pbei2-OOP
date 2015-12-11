#ifndef GLOBALS_H
#define GLOBALS_H

#include <QString>
#include <QVector>
#include <QTextStream>


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
    MenuList_Exit               = 1,
    MenuList_Clientlist         = 2,
    MenuList_Articlelist        = 3,
    MenuList_InvoiceList        = 4,
    MenuList_SaveDatabase       = 5,
    MenuList_RetrieveDatabase   = 6,
    MenuList_PrintDBInfo        = 7,
    MenuList_Min            = MenuList_Exit,
    MenuList_Max            = MenuList_PrintDBInfo
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

/**
 * @brief  Invoice Menu selection list
 */
typedef enum MenuList_Invoices {
    MenuList_Invoices_Exit      = 1,
    MenuList_Invoices_List      = 2,
    MenuList_Invoices_Add       = 3,
    MenuList_Invoices_Min       = MenuList_Invoices_Exit,
    MenuList_Invoices_Max       = MenuList_Invoices_Add
} MenuList_Invoices;

const QString globals_director = "Director";
const QString globals_salesman = "Salesman";
const QString globals_info = "INFO";
const QString globals_login = "LOGIN";
const QString globals_itemprefix = "";
const QString globals_menumain = "MAIN MENU";
const QString globals_menuexit = "MAIN MENU > EXIT";
const QString globals_menuarticles = "MAIN MENU > ARTICLE MENU";
const QString globals_menuclients = "MAIN MENU > CLIENT MENU";
const QString globals_menuinvoices = "MAIN MENU > INVOICE MENU";
const QString globals_headerLine = "------------------------------------------------------------------";
const QString globals_headerFirst = "[";
const QString globals_headerSecond = "]\t";
const QString globals_selectionFirst = "\t[";
const QString globals_selectionSecond = "]\t";
const QString globals_selectionFeedbackFirst = "\t[";
const QString globals_selectionFeedbackSecond = "]\t";

const QString globals_bandencentrale_foldername = "-Bandencentrale";
const QString globals_bandencentrale_foldername_Articles = "Items";
const QString globals_bandencentrale_foldername_Articles_Band = "-Band";
const QString globals_bandencentrale_foldername_Articles_Velg = "-Velg";
const QString globals_bandencentrale_foldername_Clients = "Clients";
const QString globals_bandencentrale_foldername_Clients_Corporate = "-Corporate";
const QString globals_bandencentrale_foldername_Clients_Personal = "-Personal";
const QString globals_bandencentrale_foldername_Invoices = "Invoices";
const QString globals_bandencentrale_foldername_Invoices_General = "-invoice";

const QString globals_bandencentrale_fileExtension = ".overload";

#endif // GLOBALS_H

