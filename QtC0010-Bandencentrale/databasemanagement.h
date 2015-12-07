#ifndef DATABASEMANAGEMENT_H
#define DATABASEMANAGEMENT_H

#include <QVector>

class Artikel;
class Band;
class Velg;
class Klant;
class Factuur;
class Bandencentrale;

class DatabaseManagement final
{
public:
    DatabaseManagement();
    virtual ~DatabaseManagement();

    /**
     * @brief  Get the whole tire company from file
     * @param  None
     * @retval Bandencentrale   The pointer to the dynamic allocated object
     */
    static Bandencentrale* getTireCompany(void);

    /**
     * @brief  Get all the articles from file
     * @param  None
     * @retval Artikel   The pointer to the dynamic allocated object
     */
    static QVector<Artikel*> getArticles(void);

    /**
     * @brief  Get all the tires from file
     * @param  None
     * @retval Artikel   The pointer to the dynamic allocated object
     */
    static QVector<Band*> getTires(void);

    /**
     * @brief  Get all the rimms from file
     * @param  None
     * @retval Artikel   The pointer to the dynamic allocated object
     */
    static QVector<Velg*> getRimms(void);

    /**
     * @brief  Get all the clients from file
     * @param  None
     * @retval Artikel   The pointer to the dynamic allocated object
     */
    static QVector<Klant*> getClients(void);

    /**
     * @brief  Get all the invoices from file
     * @param  None
     * @retval Artikel   The pointer to the dynamic allocated object
     */
    static QVector<Factuur*> getInvoices(void);

    /**
     * @brief  Write the object to file
     * @param  Artikel  The object that needs to be written
     * @retval bool     Wether the action was succesfull
     */
    static bool writeArticle(Artikel&);

    /**
     * @brief  Write the object to file
     * @param  Band     The object that needs to be written
     * @retval bool     Wether the action was succesfull
     */
    static bool writeArticle(Band&);

    /**
     * @brief  Write the object to file
     * @param  Velg     The object that needs to be written
     * @retval bool     Wether the action was succesfull
     */
    static bool writeArticle(Velg&);

    /**
     * @brief  Write the object to file
     * @param  Klant    The object that needs to be written
     * @retval bool     Wether the action was succesfull
     */
    static bool writeClient(Klant&);

    /**
     * @brief  Write the object to file
     * @param  Factuur  The object that needs to be written
     * @retval bool     Wether the action was succesfull
     */
    static bool writeInvoice(Factuur&);

    /**
     * @brief  Update the object in file
     * @param  Artikel  The object that needs to be updated
     * @retval bool     Wether the action was succesfull
     */
    static bool updateArticle(Artikel&);

    /**
     * @brief  Update the object in file
     * @param  Band     The object that needs to be updated
     * @retval bool     Wether the action was succesfull
     */
    static bool updateArticle(Band&);

    /**
     * @brief  Update the object in file
     * @param  Velg     The object that needs to be updated
     * @retval bool     Wether the action was succesfull
     */
    static bool updateArticle(Velg&);

    /**
     * @brief  Update the object in file
     * @param  Klant    The object that needs to be updated
     * @retval bool     Wether the action was succesfull
     */
    static bool updateClient(Klant&);

    /**
     * @brief  Update the object in file
     * @param  Factuur  The object that needs to be updated
     * @retval bool     Wether the action was succesfull
     */
    static bool updateInvoice(Factuur&);

    /**
     * @brief  Delete the object in file
     * @param  Artikel  The object that needs to be deleted
     * @retval bool     Wether the action was succesfull
     */
    static bool deleteArticle(Artikel&);

    /**
     * @brief  Delete the object in file
     * @param  Band     The object that needs to be deleted
     * @retval bool     Wether the action was succesfull
     */
    static bool deleteArticle(Band&);

    /**
     * @brief  Delete the object in file
     * @param  Velg     The object that needs to be deleted
     * @retval bool     Wether the action was succesfull
     */
    static bool deleteArticle(Velg&);

    /**
     * @brief  Delete the object in file
     * @param  Klant    The object that needs to be deleted
     * @retval bool     Wether the action was succesfull
     */
    static bool deleteClient(Klant&);

    /**
     * @brief  Delete the object in file
     * @param  Factuur  The object that needs to be deleted
     * @retval bool     Wether the action was succesfull
     */
    static bool deleteInvoice(Factuur&);

private:

};

#endif // DATABASEMANAGEMENT_H
