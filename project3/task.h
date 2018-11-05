
#define MAX_STR 30
#define MAX_STR2 100

class Task{
    private:
		char taskName [MAX_STR];
		char description [MAX_STR2];
		int month;
		int day;
		int year;
		bool complete;
    public:
		Task();

		void setTaskName(char taskName[]);
        void getTaskName(char *tn);
        void setDescription(char description[]);
        void getDescription (char *d);
		void setMonth(int m);
		int getMonth();
		void setDay(int d);
		int getDay();
		void setYear(int y);
		int getYear();
		void setComplete(bool);
		bool getComplete();

    ~Task();
};

