#include "BCapplication.h"

using namespace std;

// SLOTS

void BCapplication::run(void){
    // login user
    userLogin();

    // get bandencentrale from filesystem
    databaseRetrieve();

    // set fixed centrale info
    _bandencentrale->setNaam("Bandencentrale OOP");
    Adres tmpAdres;
    tmpAdres.gemeente = "Sint-Katelijne-Waver";
    tmpAdres.land = "Belgie";
    tmpAdres.postcode = 2860;
    tmpAdres.straatnaam = "DeNayerstraat";
    tmpAdres.straatnummer = "1";
    _bandencentrale->setAdres(tmpAdres);

    DatabaseManagement::writeTirecompany(_bandencentrale);

    // blocking selection loop
    selectionMenu();

    emit finished();
}

// SIGNALS

// ctor
BCapplication::BCapplication(int argc, char **argv, QObject *parent):
    QObject(parent)
{
    QTextStream qtout(stdout);

    this->_argc = argc;
    this->_argv = argv;

    // set main menu list options
    _menulist_main.push_back("End program");
    _menulist_main.push_back("Client management");
    _menulist_main.push_back("Article management");
    _menulist_main.push_back("Invoice management");
    _menulist_main.push_back("Save Database");
    _menulist_main.push_back("Retrieve Database");
    _menulist_main.push_back("Workshop Info");

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

    // set invoice list options
    _menulist_invoices.push_back("Back to Main Menu");
    _menulist_invoices.push_back("List Invoices");
    _menulist_invoices.push_back("Add Invoice");
}

// dtor
BCapplication::~BCapplication(){
    // delete bandencentrale
    delete _bandencentrale;
}

void BCapplication::getPtr(void){
    QTextStream qtout(stdout);

    QString ptrStr = QString("0x%1").arg((quintptr)this->_bandencentrale,
                        QT_POINTER_SIZE * 2, 16, QChar('0'));
    qtout << "0 bandencentrale ptr: " << ptrStr << endl;
}

// login

void BCapplication::userLogin(){
    // temp variables
    int selectvalue = 0;
    QString userlevel;

    // print welcome message
    printHeaderText(globals_info, "This is the application for selling Tires and Rimms.");

    // get the user level
    do {
        printHeaderText(globals_login, "Select the user account to log in:");
        printSelectionchoice(globals_itemprefix, UserLevel_Admin, "Director (autoretrieve database)");
        printSelectionchoice(globals_itemprefix, UserLevel_User, "Salesman (autoretrieve database)");

        cin >> selectvalue;
        cin.get();
    } while (!(selectvalue == UserLevel_Admin || selectvalue == UserLevel_User));

    // string selection according to user level
    if(selectvalue == UserLevel_Admin){
        userlevel = globals_director;
    } else if (selectvalue == UserLevel_User) {
        userlevel = globals_salesman;
    }

    // give feedback of the selection
        //printSelectionfeedback(globals_login, selectvalue, userlevel);

    // store it for further handling
    this->_userlevel = selectvalue;
}

void BCapplication::databaseRetrieve(void){
    // get the wole company in a dynamically generated object
    this->_bandencentrale = DatabaseManagement::getTireCompany();
}

void BCapplication::selectionMenu(void){
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
        } else if (_app_menuinvoice){
            // Article menu is selected
                // get the user selection
                selectvalue = menuinvoice_querySelection();

                // let the menu be selected
                menuinvoice_menulistItemexecution(selectvalue);
        } else {
            // Main menu is selected
                // get the user selection
                selectvalue = menumain_querySelection();

                // let the menu be selected
                menumain_menulistItemexecution(selectvalue);
        }
    }
}

int BCapplication::menumain_querySelection(void){
    // push and receive main menu selection
    return generalQueryUserselection(globals_menumain, _menulist_main);
}

void BCapplication::menumain_menulistItemexecution(int menuselection){
    // check the input values
    if(menuselection < 1) return;
    if(menuselection > _menulist_main.size()) return;

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
        case MenuList_InvoiceList:
            _app_menuinvoice = true;
            break;
        case MenuList_SaveDatabase:
            DatabaseManagement::writeTirecompany(_bandencentrale);
            break;
        case MenuList_RetrieveDatabase:
            delete _bandencentrale;
            _bandencentrale = DatabaseManagement::getTireCompany();
            break;
        case MenuList_PrintDBInfo:
            _bandencentrale->print();
    }
}

int BCapplication::menuarticle_querySelection(void){
    // push and receive article menu selection
    return generalQueryUserselection(globals_menuarticles, _menulist_articles);
}

void BCapplication::menuarticle_menulistItemexecution(int menuselection){
    // check the input values
    if(menuselection < 1) return;
    if(menuselection > _menulist_articles.size()) return;

    // select the input and execute the correct application
    switch (menuselection) {
        case MenuList_Articles_Exit:
            _app_menuarticle = false;
            break;
        case MenuList_Articles_List:
            if(getAuthorized(UserLevel_User)){
                item_List();
            }
            break;
        case MenuList_Articles_Add:
            if(getAuthorized(UserLevel_User)){
                item_Add();
            }
            break;
        case MenuList_Articles_Delete:

            break;
        case MenuList_Articles_History:

            break;
    }
}

int BCapplication::menuclient_querySelection(void){
    // push and receive client menu selection
    return generalQueryUserselection(globals_menuclients, _menulist_clients);
}

void BCapplication::menuclient_menulistItemexecution(int menuselection){
    // check the input values
    if(menuselection < 1) return;
    if(menuselection > _menulist_clients.size()) return;

    // select the input and execute the correct application
    switch (menuselection) {
        case MenuList_Clients_Exit:
            _app_menuclient = false;
            break;
        case MenuList_Clients_List:
            // print clients
            if(getAuthorized(UserLevel_User)){
                //this->_bandencentrale->printClientList();
                clients_List();
            }
            break;
        case MenuList_Clients_Add:
            // add clients
            if(getAuthorized(UserLevel_User)){
                clients_Add();
            }
            break;
        case MenuList_Clients_Delete:

            break;
        case MenuList_Clients_View:

            break;
    }
}

int BCapplication::menuinvoice_querySelection(void){
    return generalQueryUserselection(globals_menuinvoices, _menulist_invoices);
}

void BCapplication::menuinvoice_menulistItemexecution(int menuselection){
    // check the input values
    if(menuselection < 1) return;
    if(menuselection > _menulist_invoices.size()) return;

    // select the input and execute the correct application
    switch (menuselection) {
        case MenuList_Invoices_Exit:
            _app_menuinvoice = false;
            break;
        case MenuList_Invoices_List:
            if(getAuthorized(UserLevel_User)){
                invoice_List();
            }
            break;
        case MenuList_Invoices_Add:
            if(getAuthorized(UserLevel_User)){
                invoice_Add();
            }
            break;
    }
}

int BCapplication::generalQueryUserselection(QString label, QVector<QString> &stringContainer){
    // print selection header message
    int selectvalue = 0;

    // loop over the possible selections
    do {
        printHeaderText(label, "Please select the functionality you want to run:");
        for(int i = 0; i<stringContainer.size(); i++){
            printSelectionchoice("", i+1, stringContainer.at(i));
        }
        cin >> selectvalue;
        cin.get();
    } while(!(selectvalue >= 1 || selectvalue <= (stringContainer.size()-1) ) );

    // give feedback of the selection
        //printSelectionfeedback(label, selectvalue, stringContainer.at(selectvalue-1));

    // return the selected value
    return selectvalue;
}

// USER INTERFACE
QString BCapplication::getQuestion(QTextStream &ostream, QTextStream &istream, QString question){
    ostream << question << endl;
    return istream.readLine();
}

int BCapplication::getQuestionYN(QTextStream &ostream, QTextStream &istream, QString question){
    ostream << question << " [Y / N]" << endl;
    QString returnLine = istream.readLine();
    returnLine = returnLine.trimmed();
    if(returnLine == "Y" || returnLine == "y" || returnLine == "yes" || returnLine == "YES"){
        return 1;
    } else if (returnLine == "N" || returnLine == "n" || returnLine == "no" || returnLine == "NO"){
        return 0;
    }
    return 2;
}
int BCapplication::getQuestionYNBlocking(QTextStream &ostream, QTextStream &istream, QString question){
    int returnValue = 2;

    do {
        ostream << question << " [Y / N]" << endl;
        QString returnLine = istream.readLine();
        returnLine = returnLine.trimmed();
        if(returnLine == "Y" || returnLine == "y" || returnLine == "yes" || returnLine == "YES"){
            returnValue = 1;
        } else if (returnLine == "N" || returnLine == "n" || returnLine == "no" || returnLine == "NO"){
            returnValue = 0;
        }
    } while(returnValue != 0 && returnValue != 1);

    return returnValue;
}


// PRINTING
void BCapplication::printHeaderText(QString label, QString text){
    QTextStream qtout(stdout);
    qtout << globals_headerLine << endl;
    qtout << globals_headerFirst << label << globals_headerSecond << text << endl;
}

void BCapplication::printSelectionchoice(QString label, int selection, QString text){
    QTextStream qtout(stdout);
    qtout << label << globals_selectionFirst << selection << globals_selectionSecond << text << endl;
}

void BCapplication::printSelectionfeedback(QString label, int selection, QString text){
    QTextStream qtout(stdout);
    qtout << globals_selectionFeedbackFirst << label << globals_selectionFeedbackSecond << "Your choice is: " << selection << ", you selected: " << text << endl;
}

void BCapplication::menu_exit(void){
    this->_app_alive = false;
    printHeaderText(globals_menuexit, "We are closing the application. Bye bye!");
}


// CLIENTS
bool BCapplication::clients_Add(void){
    QTextStream qtin(stdin);
    QTextStream qtout(stdout);
    bool answered = false;

    // addition of client
        // client variables
        ClientType tempclass_business = ClientType_Personal;
            // only for business
            QString tempclass_btw;
            double tempclass_bedrijfskorting;
            double tempclass_volumekorting;

        QString tempclass_naam;
        Adres tempclass_adres;
        double tempclass_setkorting1;
        double tempclass_setkorting2;

    // business
        int businessQuestion = getQuestionYN(qtout, qtin, "Is the new client a business?");
        while(businessQuestion == 2){
            businessQuestion = getQuestionYN(qtout, qtin, "Is the new client a business?");
        }
        if(businessQuestion == 1){
            tempclass_business = ClientType_Business;
        } else if (businessQuestion == 0){
            tempclass_business = ClientType_Personal;
        }


    // naam
    tempclass_naam = getQuestion(qtout, qtin, "Clients name?");

    // adres
    tempclass_adres.straatnaam = getQuestion(qtout, qtin, "Street name?");
    tempclass_adres.straatnummer = getQuestion(qtout, qtin, "Street number?");
    tempclass_adres.postcode = getQuestion(qtout, qtin, "Postal code?").toInt();
    tempclass_adres.gemeente = getQuestion(qtout, qtin, "Town name?");
    tempclass_adres.land = getQuestion(qtout, qtin, "Country name?");

    // setkorting 1
    tempclass_setkorting1 = getQuestion(qtout, qtin, "Set discount 4 PCS? [%]").toDouble();

    // setkorting 2
    tempclass_setkorting2 = getQuestion(qtout, qtin, "Set discount on 10 sets? [%]").toDouble();

        // if business
        if(tempclass_business == ClientType_Business){
            tempclass_bedrijfskorting = getQuestion(qtout, qtin, "Company discount? [%]").toDouble();
            tempclass_volumekorting = getQuestion(qtout, qtin, "Volume discount? [%]").toDouble();

            tempclass_btw = getQuestion(qtout, qtin, "Company TAV number?");
        }

    Klant *newKlant;
    // create klant
    if ( tempclass_business == ClientType_Business){
        // business
        newKlant = dynamic_cast<Klant*>(new Bedrijfsklant(
                                            tempclass_naam,
                                            tempclass_adres,
                                            tempclass_setkorting1,
                                            tempclass_setkorting2,
                                            tempclass_btw,
                                            tempclass_volumekorting,
                                            tempclass_bedrijfskorting,
                                            false
                                            ));
    } else {
        // personal client
        newKlant = new Klant(
                    tempclass_naam,
                    tempclass_adres,
                    tempclass_setkorting1,
                    tempclass_setkorting2,
                    false
                    );
    }

    // add client to the Workshop
    this->_bandencentrale->addClient(*newKlant);

    // save the workshop to file
    DatabaseManagement::writeTirecompany(_bandencentrale);

    return answered;
}

void BCapplication::clients_List(void){
    // loop over client list and print out all the info
    QTextStream qtout(stdout);
    qtout << globals_headerLine << endl;
    qtout << "\tThe list of clients:" << endl;
    int iteration = 0;
    QList<Klant*>::iterator i;
    QList<Klant*> tmpList = _bandencentrale->getKlanten();
    for(i = tmpList.begin(); i!= tmpList.end(); i++){
        Klant* tmp = (*i);
        QStringList printList;
        if(tmp->getClientType() == ClientType_Business){
            Bedrijfsklant* tmp2 = dynamic_cast<Bedrijfsklant*>(tmp);
            printList << QString::number(tmp->getClientID()) << tmp->getNaam() << "Business" << tmp2->getBTWnummer();
        } else {
            printList << QString::number(tmp->getClientID()) << tmp->getNaam() << "Personal";
        }


        qtout << globals_selectionFeedbackFirst << ++iteration << globals_selectionFeedbackSecond << printList.join(" - ") << endl;
    }

}

bool BCapplication::item_Add(void){
    QTextStream qtin(stdin);
    QTextStream qtout(stdout);
    bool answered = false;

    // addition of item

        // selection of velg or band

        // get info of artikel class

        // get specific info of subclass

        //

    return answered;
}

void BCapplication::item_List(void){
    QTextStream qtout(stdout);
    // list items
    qtout << globals_headerLine << endl;
    qtout << "\tThe list of Items:" << endl;
    int iteration = 0;
    QList<Artikel*>::iterator i;
    QList<Artikel*> tmpList = _bandencentrale->getArtikels();
    for( i = tmpList.begin(); i!=tmpList.end(); i++){
        Artikel* tmp = (*i);
        QStringList printList;
        if(tmp->getType() == ArtikelType_Band){
            Band* tmp2 = dynamic_cast<Band*>(tmp);
            printList << QString::number(tmp2->getArtikelID()) << tmp2->getNaam() << "Band" << tmp2->getFabrikant() << tmp2->getSnelheidsindex();
        } else if (tmp->getType() == ArtikelType_Velg){
            Velg* tmp2 = dynamic_cast<Velg*>(tmp);
            printList << QString::number(tmp2->getArtikelID()) << tmp2->getNaam() << "Velg";
        }

        qtout << globals_selectionFeedbackFirst << ++iteration << globals_selectionFeedbackSecond << printList.join(" - ") << endl;
    }
}

bool BCapplication::invoice_Add(void){
    QTextStream qtin(stdin);
    QTextStream qtout(stdout);
    bool answered = false;

    return answered;
}

void BCapplication::invoice_List(void){
    QTextStream qtout(stdout);
    // list invoices
    qtout << globals_headerLine << endl;
    qtout << "\tThe list of Invoices:" << endl;
    int iteration = 0;
    QList<Factuur*>::iterator i;
    QList<Factuur*> tmpList = _bandencentrale->getFacturen();
    for( i = tmpList.begin(); i!=tmpList.end(); i++){
        Factuur* tmp = (*i);
        QStringList printList;
        printList << QString::number(tmp->getFactuurnummer()) << QString::number(tmp->getKlant()) << QString::number(tmp->getTotaalprijs());
        qtout << globals_selectionFeedbackFirst << ++iteration << globals_selectionFeedbackSecond << printList.join(" - ") << endl;
    }
}

// ERROR MESSAGE
bool BCapplication::getAuthorized(UserLevel lvlCheck){
    if(lvlCheck == UserLevel_Admin && _userlevel == UserLevel_User){
            cout << "You are not authorized to do this. We are sorry." << endl;
            return false;
    }

    return true;
}

// CONVERSION
Bedrijfsklant* BCapplication::getBedrijfsklant(Klant* ptr){
    return dynamic_cast<Bedrijfsklant*>(ptr);
}
