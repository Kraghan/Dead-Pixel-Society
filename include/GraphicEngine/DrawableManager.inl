#include "GraphicEngine/DrawableManager.hpp"

template <typename T>
DrawableManager<T>::DrawableManager()
{
    m_drawableList = nullptr;
}

template <typename T>
DrawableManager<T>::~DrawableManager()
{
    delete [] m_drawableList;
}

template <typename T>
void DrawableManager<T>::init(unsigned int size)
{
    m_size = size;
    m_drawableList = new T[m_size];
}

template <typename T>
T * DrawableManager<T>::getFreeDrawable()
{
    for(unsigned int index = 0; index < m_size; ++index)
    {
        if(m_drawableList[index].isAvailable())
        {
            // Prepare the drawable
            m_drawableList[index].setLayer(-1);
            m_drawableList[index].setVisible(true);
            m_drawableList[index].setAvailable(false);

            // Return it
            return &m_drawableList[index];
        }
    }

    // Else, return nullptr
    return nullptr;
}

template <typename T>
inline const T * DrawableManager<T>::getDrawableList() const
{
    return m_drawableList;
}

template <typename T>
inline unsigned int DrawableManager<T>::getDrawableCount() const
{
    return m_size;
}
