//
//  GameSprite_Flay.h
//  English
//
//  Created by wang jia shuai on 13-10-19.
//
//

#ifndef __English__GameSprite_Flay__
#define __English__GameSprite_Flay__
#include "GameSprite.h"

class GameSprite_Flay : public GameSprite {
public:
    //CREATE_FUNC(GameSprite_Flay);
    static GameSprite_Flay* create();
    GameSprite_Flay();

    void    setSelectState();
    void    removeSelectState();
    void    removeFromGame();
    void    setCharacterEN(const char *pEN);
    void    setCharacterCN(const char *pCN);
private:
    CC_SYNTHESIZE(bool, m_bSelect, BSelect);
    CC_SYNTHESIZE(int, m_SpriteID, SpriteID)
    CC_SYNTHESIZE(bool, m_bRemove, BRemove)
    CC_SYNTHESIZE(bool, m_bEnglish, English);
    //CC_SYNTHESIZE(float, m_Speed, Speed);
};

#endif /* defined(__English__GameSprite_Flay__) */
