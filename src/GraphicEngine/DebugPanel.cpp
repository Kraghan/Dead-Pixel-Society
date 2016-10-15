#include "GraphicEngine/DebugPanel.hpp"

DebugPanel::DebugPanel()
: m_fps(0.0f)
, m_delta(0)
, m_renderTime(0.0f)
, m_fpsCount(0)
, m_textInUse(0)
, m_layerCount(0)
, m_spriteInUse(0)
, m_appendSkipped(0)

, m_panel(nullptr)
, m_resourceManager(nullptr)
{
    // None
}

DebugPanel::~DebugPanel()
{
    // None
}

void DebugPanel::init(ResourceManager * resourceManager,
    uint32_t spriteCount, uint32_t textCount)
{
    m_resourceManager = resourceManager;
    m_panel = m_resourceManager->getSprite();

    m_spriteCount = spriteCount;
    m_textCount = textCount;

    // Setting the layer
    m_panel->setLayer(14);

    std::string testString = PANEL_KEY;
    sf::Texture * testTexture = m_resourceManager->getTexture(PANEL_KEY);

    m_panel->setTexture(*testTexture);

    // Setting position
    m_panel->setPosition(PANEL_POS_X,
                         PANEL_POS_Y);

    // Creating all texts
    for(uint32_t index = 0; index < INFO_COUNT; ++index)
    {
        // Creating the text
        m_information.push_back(sf::Text());

        // Buffering the text
        sf::Text & _text = m_information.back();

        // Setting attributes
        _text.setFont(*m_resourceManager->getFont(FONT_KEY));
        _text.setPosition(TEXT_POS_X, TEXT_POS_Y + (index *
                         (CHAR_SIZE + TEXT_OFFSET)));

        _text.setFillColor(sf::Color::White);
        _text.setCharacterSize(CHAR_SIZE);
    }

    // Setting fps style
    m_information[1].setStyle(sf::Text::Bold);
}

void DebugPanel::reset()
{
    m_spriteInUse = 0;
    m_textInUse = 0;
}

void DebugPanel::setTextContent()
{
    // Updating all text content with the new values
    m_information[0].setString(ENGINE_VERSION);
    m_information[1].setString(std::string("FPS : ")             + fix::to_string(m_fps));
    m_information[3].setString(std::string("Frame : ")           + fix::to_string(m_fpsCount));
    m_information[6].setString(std::string("Layer count : ")     + fix::to_string(m_layerCount));
    m_information[7].setString(std::string("Append skipped : ")  + fix::to_string(m_appendSkipped));

    m_information[2].setString(std::string("Render : ") +
        fix::to_string(m_renderTime) + " (ms)");

    m_information[4].setString(std::string("Sprite in use : ") +
        fix::to_string(m_spriteInUse) + " (" +
        fix::to_string(((100 / (float)m_spriteCount)) * (float)m_spriteInUse)
        + "%)");

    m_information[5].setString(std::string("Text in use : ") +
        fix::to_string(m_textInUse) + " (" +
        fix::to_string(((100 / (float)m_textCount)) * (float)m_textInUse)
        + "%)");

    if(m_appendSkipped != 0) m_information[7].setFillColor(sf::Color::Red);
    else m_information[7].setFillColor(sf::Color::Green);
}

void DebugPanel::draw(sf::RenderWindow * window)
{
    // Preparing strings
    setTextContent();

    for(uint32_t index = 0; index < m_information.size(); ++index)
    {
        // Draw all the information text
        window->draw(m_information[index]);
    }
}

