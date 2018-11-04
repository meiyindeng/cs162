
#define MAX_STR 30
#define MAX_STR2 100

class Task{
    private:
		char taskName [MAX_STR];
		/*char description [MAX_STR2];
		int month;
		int day;
		int year;
		bool complete;*/
    public:
		Task();

		void setTaskName(char taskName[]);
        void getTaskName(char *tn);
    /*void setDescription(char description[]);
		void setMonth(int m);
		void setDay(int d);
		void setYear(int y);
		void setComplete(bool);*/
        void print();
    ~Task();
};

