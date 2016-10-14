/*!
 * \brief   Header of ResourceLoader class
 * \file    ResourceLoader.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    14/10/2016
 */

#ifndef __RESOURCE_LOADER_HPP
#define __RESOURCE_LOADER_HPP

#include <vector>

#include "Memory/Resource.hpp"
#include "Memory/ResourceManager.hpp"

class ResourceLoader
{
public:

    /*!
     * \brief   Constructor
     */
    explicit ResourceLoader();

    /*!
     * \brief   Destructor
     */
    virtual ~ResourceLoader();

    /*!
     * \brief   Initialize all resources info
     */
    void init();

    /*!
     * \brief   Load all the resources in the manager
     * \param   manager The manager to load resources in
     */
    void load(ResourceManager * manager);

private:

    /*!
     * \brief   Container to store resource info
     */
    std::vector < Resource > m_resources;
};

#endif // __RESOURCE_LOADER_HPP
