//TimeType Sepecification
class TimeType
{
public:
    void Set( /* in */ int hours,
              /* in */ int minutes,
              /* in */ int seconds );
    void Write() const;
    
private:
    int hrs;
    int mins;
    int secs;
};