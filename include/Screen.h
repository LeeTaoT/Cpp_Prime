#include <string>
#include <iostream>

class Screen {

public :
    typedef std::string::size_type pos;
    Screen() = default;

    Screen(pos ht , pos wd , char c ):height(ht) , width(wd),
                                contents(ht * wd, c){ }
    friend class Window_mgr;
    Screen(pos ht = 0, pos wd = 0) : 
        cursor(0), height(ht), width(wd), contents(ht *wd, ' '){ }
    char get() const 
        { return contents[cursor];}
    inline char get(pos ht , pos wd ) const;
    Screen &clear(char = bkground);
private:
    static const char bkground = ' ';
public:
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos , pos , char);
    Screen &display(std::ostream &os)
                { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const
                { do_display(os); return *this;}


private:
    //function to do the work of displaying a Screen
    void do_display(std::ostream &os) const {os << contents;}
    pos cursor = 0;
    pos height = 0 , width = 0;
    std::string contents;

}