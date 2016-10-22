#include "Profiler/Profiler.hpp"

/* explicit */ Profiler::Profiler()
{
    Profiler::instance = nullptr;
}

/* virtual */ Profiler::~Profiler()
{
    Profiler::instance = nullptr;
}

void Profiler::init(ResourceManager * resources)
{
    Profiler::instance = this;
    m_resourceManager = resources;
}

void Profiler::startProfile(std::string const& ID)
{

}

void Profiler::stopProfile(std::string const& ID)
{
    
}
