#include <iostream>
#include <vector>

class Callee
{
public:
    void calledFunction(const std::string& event) { std::cout << event; }
};

class EventHandler
{
public:
    void add( void (Callee::*calledFunction)(const std::string&) );
    void callBack( const std::string& event);
private:
    std::vector<void (Callee::*)(const std::string&)> m_callees;
    Callee callee;
};

void
EventHandler::add( void(Callee::*calledFunction)(const std::string&) )
{
    m_callees.push_back( calledFunction );
}

void
EventHandler::callBack( const std::string& event)
{
    for(const auto & e : m_callees) {
        (callee.*(e))(event);
    }
}

int main()
{
    // Callee callee;
    EventHandler eventHandler;
    eventHandler.add(&Callee::calledFunction);
    eventHandler.callBack( "I'm an event.\n" );
}