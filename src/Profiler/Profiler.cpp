#include "Profiler/Profiler.hpp"

/* explicit */ Profiler::Profiler()
{
    // None
}

/* virtual */ Profiler::~Profiler()
{
    // None
}

void Profiler::init(ResourceManager * resources)
{
    m_resourceManager = resources;
}

void Profiler::startProfile(std::string const& ID)
{
    // TODO
}

void Profiler::stopProfile(std::string const& ID)
{
    // TODO
}
