/*!
 * \brief    File that contains the profiler header
 * \file     Profiler.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     19/10/2016
 */

#ifndef __PROFILER_HPP
#define __PROFILER_HPP

#include "GameEngine/Clock.hpp"
#include "GameEngine/Singleton.hpp"
#include "Memory/ResourceManager.hpp"
#include "Profiler/ProfilerConstant.hpp"

class Profiler : public Singleton < Profiler >
{
public:

    /*!
     * \brief   Constructor
     */
    explicit Profiler();

    /*!
     * \brief   Destructor
     */
    virtual ~Profiler();

    /*!
     * \brief   Initialize the profiler
     */
    void init(ResourceManager * resources);

    /*!
     * \brief   Start to profile a function
     * \param   ID The id of the profiler info
     */
    void startProfile(std::string const& ID);

    /*!
     * \brief   Stop the profiling of a function
     * \param   ID the id of the profiler info
     */
    void stopProfile(std::string const& ID);

private:

    ResourceManager * m_resourceManager;

};

#endif // __PROFILER_HPP