//
//  GameData.cpp
//  English
//
//  Created by wang jia shuai on 13-10-20.
//
//

#include "GameData.h"
#include "cocos2d.h"
USING_NS_CC;
GameData *g_pGameData = NULL;
GameData *GameData::Shared()
{
    if(g_pGameData == NULL){
        g_pGameData = new GameData;
    }
    return g_pGameData;
}

GameData::GameData()
{
    m_pEnglishData = NULL;
}

cs::CSJsonDictionary* GameData::getEnglishData()
{
    if(m_pEnglishData){
        return m_pEnglishData;
    }
    cs::CSJsonDictionary *pDict = new cs::CSJsonDictionary;
    const char *pPath = "res/English.data";
    unsigned long size = 0;
    unsigned char *pData = CCFileUtils::sharedFileUtils()->getFileData(pPath, "r", &size);
    pDict->initWithDescription((const char*)pData);
    
    CCLOG("%s",pDict->getDescription().c_str());
    m_pEnglishData = pDict;
    return pDict;
}

int     GameData::getEnlishKeyIndex(const char *pKey)
{
    if(!m_pEnglishData){
        return 0;
    }
    
    int index = 0;
    std::vector<std::string> keys = m_pEnglishData->getAllMemberNames();
    std::vector<std::string>::iterator iter = keys.begin();
    for(; iter != keys.end(); iter ++){
        if((*iter).compare(pKey) == 0){
            return index;
        }
        index ++;
    }
    
    return 0;
}

int     GameData::getEnlishCount()
{
    if(m_pEnglishData){
        return m_pEnglishData->getItemCount();
    }
    return 0;
}

const char*    GameData::getEnglishKeyName(int index)
{
    if(!m_pEnglishData){
        return NULL;
    }
    
    std::vector<std::string> keys = m_pEnglishData->getAllMemberNames();
    std::string strKey = keys.at(index);
    CCString *pStr = CCString::create(strKey);
    
    return pStr->getCString();
}

const char*     GameData::getEnglishKeyData(const char *pKey)
{
    if(!m_pEnglishData){
        return NULL;
    }
    
    return m_pEnglishData->getItemStringValue(pKey);
}
