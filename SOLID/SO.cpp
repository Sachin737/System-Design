#include <bits/stdc++.h>
using namespace std;

// SINGLE RESPONSIBILITY PRINCIPLE

class Bat
{
public:
    int price;
    int rating;

    Bat()
    {
    }

    Bat(int price, int rating)
    {
        this->price = price;
        this->rating = rating;
    }
};

class Invoice
{
    Bat bat;
    int quantity;

public:
    Invoice(){};

    Invoice(Bat bat, int quantity)
    {
        this->bat = bat;
        this->quantity = quantity;
    }

    int total()
    {
        return quantity * bat.price;
    }
};

class InvoiceDB : public Invoice
{
public:
    Invoice inv;

    InvoiceDB(Invoice invoice)
    {
        this->inv = invoice;
    }

    void savetoDB()
    {
        cout << "Saved to database! " << inv.total() << " \n";
    }
};

class InvoicePrinter : public Invoice
{
public:
    Invoice inv;

    InvoicePrinter(Invoice invoice)
    {
        this->inv = invoice;
    }

    void printInvoice()
    {
        cout << "Printing invoice... " << inv.total() << " \n";
    }
};


// OPEN CLOSED PRINCIPLE
// we should extend our origin live class instead of updating it 

class InvoiceFile : public Invoice
{
public:
    Invoice inv;

    InvoiceFile(Invoice invoice)
    {
        this->inv = invoice;
    }

    void makeFile()
    {
        cout << "Creating Invoice file... " << inv.total() << " \n";
    }
};


int main()
{
    Bat b1(1200, 8);

    Invoice inv(b1, 3); // created general invoice

    InvoiceDB invDB(inv); // db invoice
    invDB.savetoDB();

    InvoicePrinter invPr(inv); // printer
    invPr.printInvoice();


    InvoiceFile invFile(inv); // file
    invFile.makeFile();

    return 0;
}
