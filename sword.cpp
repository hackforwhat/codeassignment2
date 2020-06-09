#ifndef _definition_h_
#include "defs.h"
#define _definition_h_
#endif
//friendNumber?
bool friendNumber(int hp, int gil)
{
    int N1 = 0, N2 = 0;
    for (int i = 1; i <= hp; i++)
    {
        if (hp % i == 0) N1 += i;
    }
    for (int j = 1; j <= gil; j++)
    {
        if (gil % j == 0) N2 += j;
    }
    if ((float)N1 / hp == (float) N2 / gil) return true;
    else return false;

}

//Dragon?
bool dragon(int hpr) {
    int z = 0, index = 0;
    for (int x = 1; x <= hpr; x++)
        for (int y = 1; y <= hpr; y++) {
            z = hpr - x - y;
            if (x * x + y * y == z * z) {
                index++;
            }
        }
    if (index > 0 && hpr != 888) return true;
    else return false;
}
//Paladin?
bool snt(int HP) {
    if (HP < 2) return false;
    else {
        int index = 0, i;
        for (i = 2; i <= HP / 2; i++)
        {
            if (HP % i == 0) index++;
        }
        if (index == 0) return true;
        else return false;
    }
}
//mode1
void collocation(int hash1,int hash2,int hash3,bool &paladin_shield,bool &lancelot_spear,bool &guinevere_hair,int theEvent)
{
    if(theEvent==95)
    {
        if(!((hash2<hash1 && lancelot_spear==false) || (hash3<hash1 && guinevere_hair==false)))
        {
            paladin_shield=true;
        }
    }
    if(theEvent==96)
    {
        if(!((hash1<hash2 && paladin_shield==false) || (hash3<hash2 && guinevere_hair==false)))
        {
            lancelot_spear=true;
        }

    }
    if(theEvent==97)
    {
        if(!((hash1<hash3 && paladin_shield==false) || (hash2<hash3 && lancelot_spear==false)))
        {
            guinevere_hair=true;
        }
    }
}

report* walkthrough(knight& theKnight, castle arrCastle[], int nCastle, int mode, int nPetal)
{
    report* pReturn;
    pReturn = new report;
    int bFlag = 0;
    int theEvent;
    int MAXHP = theKnight.HP;
    int b = 0;
    int levelO;
    int poison = -1;
    int odin = -1;
    int lion = -1;
    float basedamage;

    bool thePoision = false;
    bool excalibur = false;
    bool shield_paladin = false;
    bool spear_lancetot = false;
    bool hair_guinevere = false;
    bool lionheart = false;
    bool theOdin = false;
    bool theOW = false;
    bool mythrill = false;
    bool SH = false;
    bool killOdin=false;

    bool arthur = false;
    bool lancelot = false;
    bool guinevere = false;
    bool paladin = false;
    bool dragonKnight = false;
    bool Knight = false;

    pReturn->nLose = 0;
    pReturn->nWin = 0;


    if (theKnight.HP == 999)         arthur = true;
    else if (theKnight.HP == 888) { lancelot = true; spear_lancetot = true; }
    else if (theKnight.HP == 777) { guinevere = true; hair_guinevere = true; }
    else if (snt(theKnight.HP))   { paladin = true; shield_paladin = true; }
    else if (dragon(theKnight.HP)) dragonKnight = true;
    else                           Knight = true;


    //fighting for the existence of mankind here

    for (int i = 0; i < nCastle; i++)
    {
        castle cc = arrCastle[i];
        for (int j = 0; j < cc.nEvent; j++)
        {
            theEvent = cc.arrEvent[j];
            switch (theEvent)
            {
            //MADBEAR
            case 1:
            //MOONBRINGER
            case 2:
            //ELF   
            case 3:
            //SAXON
            case 4:
            //TROLL
            case 5:
                if (arthur == true || lancelot == true || lionheart == true || theOdin == true || paladin == true)
                {
                    pReturn->nWin++;
                    switch (theEvent)
                    {
                    case 1:theKnight.gil += 100; break;
                    case 2:theKnight.gil += 150; break;
                    case 3:theKnight.gil += 450; break;
                    case 4:theKnight.gil += 650; break;
                    case 5:theKnight.gil += 850; break;
                    }



                }
                else
                {
                    b = (j + 1) % 10;
                    levelO = (j + 1) > 6 ? (b > 5 ? b : 5) : b;
                    if (mythrill == true && thePoision == false && theKnight.level < levelO) { pReturn->nLose++; }
                    else if (theKnight.level >= levelO && thePoision == true)
                    {
                        switch (theEvent)
                        {
                        case 1:theKnight.gil += 100; break;
                        case 2:theKnight.gil += 150; break;
                        case 3:theKnight.gil += 450; break;
                        case 4:theKnight.gil += 650; break;
                        case 5:theKnight.gil += 850; break;
                        }
                        switch (theEvent)
                        {
                        case 1:basedamage = 1; break;
                        case 2:basedamage = 1.5; break;
                        case 3:basedamage = 4.5; break;
                        case 4:basedamage = 6.5; break;
                        case 5:basedamage = 8.5; break;
                        default:
                            break;
                        }
                        theKnight.HP = theKnight.HP - basedamage * levelO * 10;
                        pReturn->nWin++;


                    }
                    else if (theKnight.level >= levelO)
                    {
                        switch (theEvent)
                        {
                        case 1:theKnight.gil += 100; break;
                        case 2:theKnight.gil += 150; break;
                        case 3:theKnight.gil += 450; break;
                        case 4:theKnight.gil += 650; break;
                        case 5:theKnight.gil += 850; break;
                        }
                        pReturn->nWin++;
                    }
                    else
                    {
                        switch (theEvent)
                        {
                        case 1:basedamage = 1; break;
                        case 2:basedamage = 1.5; break;
                        case 3:basedamage = 4.5; break;
                        case 4:basedamage = 6.5; break;
                        case 5:basedamage = 8.5; break;
                        }
                        pReturn->nLose++;
                        if (guinevere == true && thePoision==false&& theEvent == 2) break;
                        if(thePoision==true) theKnight.HP=theKnight.HP - 2*basedamage * levelO * 10;
                        else theKnight.HP = theKnight.HP - basedamage * levelO * 10;
                        


                    }


                } break;
            //TORNBERY
            case 6:
            {
                if (thePoision == true ) break;
                b = (j + 1) % 10;
                levelO = (j + 1) > 6 ? (b > 5 ? b : 5) : b;
                if (theKnight.level >= levelO || arthur == true || lancelot == true || theOdin == true || lionheart == true) 
                { 
                    pReturn->nWin++;
                    int tempLevel=theKnight.level;
                    theKnight.level=(theKnight.level==10)? 10:theKnight.level+1;
                    MAXHP=(tempLevel==theKnight.level) ? MAXHP:MAXHP+100; 
                }
                else
                {
                    pReturn->nLose++;
                    if (paladin == true || dragonKnight==true) break;
                    else if (theKnight.antidote >= 1) theKnight.antidote--;
                    else
                    {
                        poison = 6;
                        thePoision = true;
                    }

                }
            } break;
            //QUEEN OF CARDS    
            case 7:
            {
                b = (j + 1) % 10;
                levelO = j + 1 > 6 ? (b > 5 ? b : 5) : b;
                if (theKnight.level >= levelO || arthur == true || lancelot == true || theOdin == true || lionheart == true) { theKnight.gil *= 2; pReturn->nWin++; }
                else
                {
                    pReturn->nLose++;
                    if (SH == false && guinevere == false)
                        theKnight.gil /= 2;
                }
            } break;
            //NINA DE RINGS
            case 8:
            {
                if (friendNumber(theKnight.HP, theKnight.gil) == true)
                {
                    lionheart = true;
                    if (paladin == false)
                        lion = 6;
                }
                if (theKnight.gil < 50 && SH == false && paladin==false && guinevere==false && friendNumber(theKnight.HP, theKnight.gil) == false) break;
                if (thePoision == true)
                {
                    if (SH == false  && guinevere == false && paladin == false && friendNumber(theKnight.HP, theKnight.gil) == false ) theKnight.gil -= 50;
                    theKnight.HP = MAXHP;
                    thePoision = false;
                } 
                if (theKnight.gil > 0)
                {
                    theKnight.HP = theKnight.HP + theKnight.gil;
                    if (theKnight.HP <= MAXHP && SH == false  && guinevere == false && paladin == false) theKnight.gil = 0;
                    else
                    {
                        
                        if (SH == false  && guinevere == false && paladin == false) theKnight.gil = theKnight.HP - MAXHP;
                        theKnight.HP = MAXHP;
                    }
                }
                if (guinevere == true) { theKnight.gil += 50; if (theKnight.gil > 999) theKnight.gil = 999; }

            } break;
            //DURION
            case 9:
                if (thePoision == true) thePoision = false;
                theKnight.HP = MAXHP;
                nPetal += 5;
                if (nPetal > 99 || SH == true) nPetal = 99;
                break;
            //ANTIDOTE
            case 10:
                theKnight.antidote++;
                if (thePoision == true && poison!=0) { theKnight.antidote--; thePoision = false; };
                break;
            //ODIN
            case 11:
                if(killOdin) break;
                theOdin = true;
                odin = 6;
                break;
            //MERLIN
            case 12:
            {
                thePoision = false;
                int tempLevel=theKnight.level;
                theKnight.level=(theKnight.level==10)? 10:theKnight.level+1;
                MAXHP=(tempLevel==theKnight.level) ? MAXHP:MAXHP+100;
                theKnight.HP = MAXHP;
            } break;
            //OMEGA WEAPON
            case 13:
            {
                if (theOW == true) break;
                if (theKnight.level == 10 && excalibur == true || dragonKnight == true && lionheart == true)
                {
                    theOW = true;
                    theKnight.level = 10;
                    theKnight.gil = 999;
                    MAXHP += 100 * (10 - theKnight.level);
                    pReturn->nWin++;
                }
                else
                {
                    pReturn->nLose++;
                    if (mythrill == true) break;
                    theKnight.HP = 0;
                }
            } break;
            //HADES
            case 14:
            {
                if (dragonKnight == false && theOdin==true) {theOdin = false;killOdin=true;}
                if (spear_lancetot == true && hair_guinevere == true && excalibur == false || arthur == true && hair_guinevere == true ||
                    lancelot == true && hair_guinevere == true || guinevere == true && spear_lancetot == true || lionheart == true || dragonKnight == true && theOdin == true)
                {
                    pReturn->nWin++;
                    mythrill = true;
                    break;
                }
                b = (j + 1) % 10;
                levelO = j + 1 > 6 ? (b > 5 ? b : 5) : b;
                if (theKnight.level >= levelO) { mythrill = true; pReturn->nWin++; }
                else
                {
                    pReturn->nLose++;
                    if (mythrill == false)  theKnight.HP = 0;
                }
            } break;
            //SCARLET HAKAMA
            case 15: SH = true;
                break;
            //LOCKEDDOOR
            case 16:    
            break;
            //SHIELD OF PALADIN
            case 95:
            {   
                if(mode==1)
                {
                    collocation(hash(95),hash(96),hash(97),shield_paladin,spear_lancetot,hair_guinevere,theEvent);
                }
                else shield_paladin = true;
            } break;
            //SPEAR OF LANCELOT
            case 96:
            {
                if(mode==1)
                {
                    collocation(hash(95),hash(96),hash(97),shield_paladin,spear_lancetot,hair_guinevere,theEvent);
                }
                else spear_lancetot = true; 
            } break;
            // HAIR OF GUINEVERE
            case 97:
            {
                if(mode==1)
                {
                    collocation(hash(95),hash(96),hash(97),shield_paladin,spear_lancetot,hair_guinevere,theEvent);
                }
                else hair_guinevere = true;
            } break;
            //EXCALIBUR
            case 98:
            {
                if ((shield_paladin == true && spear_lancetot == true && hair_guinevere == true) || arthur == true) excalibur = true;
            } break;
            //Ultimecia(Boss)
            case 99:
            {
                if (excalibur == true && thePoision == true)
                {
                    bFlag = 1;
                    pReturn->nWin++;
                    theKnight.HP /= 3;
                    if (theKnight.HP < 3) theKnight.HP = 1;

                }

                else if (excalibur == true || lionheart == true) { bFlag = 1; pReturn->nWin++; }
                else
                {
                    pReturn->nLose++;
                    if (mythrill == false && guinevere == false)
                        theKnight.HP /= 3;
                    if (theKnight.HP < 3) theKnight.HP = 1;
                }

            } break;


            }
            //arrayEvent

            nPetal--;
            if (theKnight.level > 10) theKnight.level = 10;
            if(MAXHP>999) MAXHP=999;
            if(theKnight.HP>999) theKnight.HP=999;
            if(theKnight.gil>999) theKnight.gil=999;
            if (bFlag == 1) break; 
            if (nPetal == 0 && arthur == false) break;
            if (theKnight.HP <= 0) { callPhoenix(theKnight, MAXHP); thePoision = false, poison = -1; }
            if (thePoision == true)
            {
                poison--;
                if (poison == 0) thePoision = false;
            }
            if (theOdin == true)
            {
                odin--;
                if (odin == 0) theOdin = false;
            }
            if (lionheart == true)
            {
                lion--;
                if (lion == 0) lionheart = false;
            }
            if(theKnight.level<=((j+1)%10) && theEvent==16 && lancelot==false && dragonKnight==false) break; 
        }
        //arrayCastel
        
        if (bFlag == 1) break;
        if (nPetal == 0 && arthur == false) break;
        if (nPetal >= 1 && i == nCastle - 1) i = -1;
        int tempLevel=theKnight.level;
        theKnight.level=(theKnight.level==10)? 10:theKnight.level+1;
        MAXHP=(tempLevel==theKnight.level) ? MAXHP:MAXHP+100;
        if(MAXHP>999) MAXHP=999;
        if(theKnight.HP>999) theKnight.HP=999;
        if(theKnight.gil>999) theKnight.gil=999;
        
    }
    // success or failure?	
    if (nPetal <= 0) nPetal = 0;
    pReturn->nPetal = nPetal;

    if (!bFlag)
    {
        delete pReturn;
        pReturn = NULL;
    }
    return pReturn;
}