#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Reader
{
    ifstream file;

public:
    Reader(string filename)
        : file(filename)
    {
    }

    string readLine()
    {
        string line;
        getline(file, line);
        if (!line.empty())
        {
            return line;
        }
        else
        {
            return "";
        }
    }
};

struct Film
{
    string title;
    string producer;
    int year;

    Film(string title, string producer, int year) : title(title), producer(producer), year(year)
    {
    }
};

bool filmSortFunction(const Film &f1, const Film &f2)
{
    return f1.year == f2.year ? f1.title < f2.title : f1.year < f2.year;
}

class Database
{
    vector<Film> films;

public:
    void addFilm(string filmInfo)
    {
        string delimiter = ",";
        size_t pos = 0;
        string token;
        vector<string> tokens;

        int i = 0;
        while ((pos = filmInfo.find(delimiter)) != string::npos)
        {
            token = filmInfo.substr(0, pos);
            tokens.push_back(token);
            filmInfo.erase(0, pos + delimiter.length());
            ++i;
        }

        tokens.push_back(filmInfo);

        if (tokens.size() == 3)
        {
            Film film(tokens[0], tokens[1], stoi(tokens[2]));
            films.push_back(film);
        }
    }

    void sortFilms()
    {
        sort(films.begin(), films.end(), filmSortFunction);
    }

    void printFilms()
    {
        for (auto &&film : films)
        {
            cout << film.title << ',' << film.producer << ',' << film.year << endl;
        }
    }
};

int main(int argc, char *argv[])
{
    std::vector<std::string> args(argv, argv + argc);
    if (argc != 2)
    {
        exit(1);
    }

    string line;
    Reader reader(argv[1]);
    Database database;

    while (true)
    {
        string s = reader.readLine();
        if (s == "")
            break;
        database.addFilm(s);
    }

    database.sortFilms();
    database.printFilms();

    return 0;
}