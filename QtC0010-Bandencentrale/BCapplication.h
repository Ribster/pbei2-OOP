#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <QtGlobal>
#include <QDebug>
#include <QObject>
#include <QtCore>

#include "globals.h"

#include "artikel.h"
#include "band.h"
#include "bandencentrale.h"
#include "bedrijfsklant.h"
#include "factuur.h"
#include "klant.h"
#include "velg.h"
#include "databasemanagement.h"

class BCapplication : public QObject
{
    Q_OBJECT
public:
    // ctor
    BCapplication(int argc, char **argv, QObject *parent = 0);
    // dtor
    ~BCapplication();

public slots:
    void run(void);

signals:
    void finished(void);

public:

    /**
     * @brief  Print the pointer of a selected variable
     * @param  None
     * @retval None
     */
    void getPtr(void);

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

    // PRINTING
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

    // CONVERSION
    /**
     * @brief  Converting the base class to the subclass
     * @param  Klant            Give the base class
     * @retval Bedrijfsklant    Return the subclass
     */
    Bedrijfsklant* getBedrijfsklant(Klant*);

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

#endif // APPLICATION_H
