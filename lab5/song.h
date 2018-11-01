#define MAX_STR 200

class Song {
private:

    int * year;
    double * duration;
    char * title;
    char * artist;
public:
    Song();

    const int * getYear();

    void setYear(int year);

    const double * getDuration();

    void setDuration(double duration);

    const char * getTitle();

    const char * getArtist();

    void setTitle(char title[]);

    void setArtist(char artist[]);

    void print();

    ~Song();

};