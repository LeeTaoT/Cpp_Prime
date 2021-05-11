#ifndef DEBUG_H
#define DEBUG_H



class  Debug
{
private:
    /* data */
    bool hw ; 
    bool io ; 
    bool other ; 


public:
    constexpr   Debug( bool b = true): hw(b) , io(b), other(b) {}
    constexpr   Debug(bool h , bool i , bool o ) : 
                    hw(h),io(i),other(o) { }

    constexpr bool any() { return hw || io || other;}
    constexpr bool hardware(){ return hw || io;}
    constexpr bool app() { return other;}
    
    void set_io(bool b){ io = b;}
    void set_hw(bool b){hw = b;}
    void set_other(bool b){ other = b;}


    ~ Debug();
};

class HW_Subsystem
{
private:
    Debug debug ;
    constexpr static Debug enable{ true , false ,false};
    /* data */
public:
    HW_Subsystem(/* args */) : debug(false){ }

    bool field_debug() {return debug.any() ;}
    bool default_debug() { return enable.any() && debug.any();}
    void  set_debug( bool b) { debug.set_hw(b); }

};

class IO_Subsytem {

public: 
    IO_Subsytem() : debug(false) { }

    bool field_debug() { return  debug.any();}
    bool default_debug() { return enable.any() && debug.any();}
    bool set_debug(bool b ) { debug.set_io(b);}
private:
    Debug debug;
    constexpr static Debug enable{ true , false , true };


}





#endif
