// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

class Internet
{
public:
    virtual void connectTo(string hostname) = 0;
};

class RealInternet : public Internet
{
public:
    void connectTo(string hostname)
    {
        cout << "Connecting to " << hostname << "\n";
    }
};
class ProxyInternet : public Internet
{
    static vector<string> bannedSites;
    Internet *internet = new RealInternet();

public:
    void connectTo(string hostname)
    {
        if (find(bannedSites.begin(), bannedSites.end(), hostname) == bannedSites.end())
        {
            internet->connectTo(hostname);
        }
        else
        {
            cout << "[" << hostname << "] Access denied!\n";
        }
    }
};

vector<string>
    ProxyInternet::bannedSites = {"abc.com", "google.com", "xyz.com"};

int main()
{
    Internet *internet = new ProxyInternet();
    vector<string> servers = {
        "google.com",
        "gsd.com",
        "abc.com",
    };

    for (auto &x : servers)
    {
        internet->connectTo(x);
    }

    return 0;
}