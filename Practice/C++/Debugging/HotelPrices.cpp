//============================================================================
// Name        : HotelPrices.cpp
// Author      : Robert Buzabrici-Filipescu
// Copyright   : HackerRank
// Link        : https://www.hackerrank.com/challenges/hotel-prices/problem
//============================================================================
/* Description :
In this challenge, the task is to debug the existing code to successfully execute all provided test files.

The given code defines two classes HotelRoom and HotelApartment denoting respectively a standard hotel room
and a hotel apartment. An instance of any of these classes has two parameters: bedrooms and bathrooms
denoting respectively the number of bedrooms and the number of bathrooms in the room.

The prices of a standard hotel room and hotel apartment are given as:

Hotel Room: 50. bedrooms + 100.bathrooms.
Hotel Apartment: The price of a standard room with the same number bedrooms and bathrooms plus 100.
For example, if a standard room costs 200, then an apartment with the same number of bedrooms and bathrooms costs 300.

In hotel’s codebase, there is a piece of code reading the list of rooms booked for today and calculates
the total profit for the hotel. However, sometimes calculated profits are lower than they should be.

Debug the existing HotelRoom and HotelApartment classes’ implementations so that the existing code computing
the total profit returns a correct profit.

Your function will be tested against several cases by the locked template code.

Input Format : 
The input is read by the provided locked code template.
In the first line, there is a single integer n denoting the number of rooms booked for today.
After that n lines follow. Each of these lines begins with a room_type which is either standard or apartment,
and is followed by the number of bedrooms and the number of bathrooms in this room.

Constraints : 1 <= n <= 100
There is at least 1 and at most 5 bedrooms in a room
There is at least 1 and at most 5 bathrooms in a room

Output Format :
The output is produced by the provided and locked code template. It calculates the total profit by iterating
through the vector of all rooms read from the input.
*/

#include <iostream>
#include <vector>

using namespace std;

class HotelRoom
{
private:
    int bedrooms_;
    int bathrooms_;
public:
    HotelRoom(int bedrooms, int bathrooms) : bedrooms_(bedrooms), bathrooms_(bathrooms) {}
    int get_price()
    {
        return 50 * bedrooms_ + 100 * bathrooms_;
    }
};

class HotelApartment : public HotelRoom
{
public:
    HotelApartment(int bedrooms, int bathrooms) : HotelRoom(bedrooms + 2, bathrooms) {}
    int get_price()
    {
        return HotelRoom::get_price() + 100;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<HotelRoom*> rooms;
    for (int i = 0; i < n; ++i)
    {
        string room_type;
        int bedrooms;
        int bathrooms;
        cin >> room_type >> bedrooms >> bathrooms;
        if (room_type == "standard")
        {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        }
        else
        {
            rooms.push_back(new HotelApartment(bedrooms, bathrooms));
        }
    }

    int total_profit = 0;
    for (auto room : rooms)
    {
        total_profit += room->get_price();
    }
    cout << total_profit << endl;

    for (auto room : rooms)
    {
        delete room;
    }
    rooms.clear();

    return 0;
}
