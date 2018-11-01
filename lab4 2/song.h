#define MAX_STR 200

class Song {
private:

    int * year;
    double * duration;
    char * title;
    char * artist;
public:
    Song();

    int getYear();

    void setYear(int year);

    double getDuration();

    void setDuration(double duration);

    void getTitle(char *title);

    void getArtist(char *artist);

    void setTitle(char title[]);

    void setArtist(char artist[]);

    void print();

    ~Song();

};