#include "show.h"
#include "screen.h"
#include "enum.h"
#include <string>
#include <vector>
using namespace std;

class Theatre {
private:
    int theatreId;
    string address;
    City city;
    vector<shared_ptr<Screen>> screens;
    vector<shared_ptr<Show>> shows;

public:
    Theatre(int theatreId, const string& address, City city);

    int getTheatreId() const;
    string getAddress() const;
    City getCity() const;

    void addScreen(const shared_ptr<Screen>& screen);
    void addShow(const shared_ptr<Show>& show);
    vector<shared_ptr<Screen>> getScreens() const;

    vector<shared_ptr<Show>> getShows() const;
};
