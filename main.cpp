#include "raylib.h"
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <math.h>

class Nemesis
{
public:
    Vector2 position;
    Vector2 centar;
    Vector2 smer;
    Vector2 boom;
    Vector2 velocity;
    Rectangle veverica;
    Rectangle source = {0, 0, 96, 96};
    float sprt = 0;
    bool aniHit;
    float A;
    float B;
    float C;
};

class lisce
{
public:
    float padanje;
    float vreme;
    Vector2 position;
    Rectangle source;
    Color color;
};

float arccos(float x)
{
    float pi = 3.141599;
    return (acos(x) * 360) / pi;
}

void abc(float x1, float x2, float y1, float y2, float *a, float *b, float *c)
{
    *a = x1 - x2;
    *b = y1 - y2;
    *c = sqrt(*a * *a + *b * *b);
}

void sudarsmer(float x1, float x2, float y1, float y2, float *smerX, float *smerY)
{

    if ((x2 - x1) > 0)
    {
        if ((y2 - y1) < 0)
        {
            *smerX = -1;
            *smerY = 1;
        }
    }
    if ((x2 - x1) > 0)
    {
        if ((y2 - y1) > 0)
        {
            *smerX = -1;
            *smerY = -1;
        }
    }
    if ((x2 - x1) < 0)
    {
        if ((y2 - y1) > 0)
        {
            *smerX = 1;
            *smerY = -1;
        }
    }
    if ((x2 - x1) < 0)
    {
        if ((y2 - y1) < 0)
        {
            *smerX = 1;
            *smerY = 1;
        }
    }
}

int main(void)
{
    // Initialization

    const int screenWidth = 1200;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Slap-a-ton");

    InitAudioDevice();

    int niz = 200;
    int lis = 50;
    // Nemesis klasa[50];
    // Nemesis *kusaca = (Nemesis *)malloc(niz*sizeof(Nemesis));
    // lisce *list = (lisce *)malloc(lis*sizeof(lisce));
    Nemesis kusaca[niz];
    lisce list[lis];

    Texture2D prasenceD = LoadTexture("./aset/PrasenceShade1.png");
    Texture2D prasenceL = LoadTexture("./aset/PrasenceShade2.png");
    Texture2D bkg = LoadTexture("./aset/bkgSheet.png");
    Texture2D mouse = LoadTexture("./aset/slap_cursor-Sheet.png");
    Texture2D prdezD = LoadTexture("./aset/prdezD.png");
    Texture2D prdezL = LoadTexture("./aset/prdezL.png");
    Texture2D coin = LoadTexture("./aset/coin.png");
    Texture2D hitbox = LoadTexture("./aset/Debug.png");
    Texture2D gunZ = LoadTexture("./aset/GunZ-Sheet.png");
    Texture2D gunZR = LoadTexture("./aset/Gun.png");
    Texture2D gunZL = LoadTexture("./aset/GunL.png");
    Texture2D explo = LoadTexture("./aset/Explosion.png");
    Texture2D veve = LoadTexture("./aset/veveSheet.png");
    Texture2D pausescr = LoadTexture("./aset/pause_screen_1.png");
    Texture2D oblac = LoadTexture("./aset/oblak-sheet.png");
    Texture2D noise = LoadTexture("./aset/noise.png");
    Texture2D leaf = LoadTexture("./aset/Leaf.png");
    Texture2D cross = LoadTexture("./aset/crossair.png");
    Color slapped = WHITE;
    Music loop = LoadMusicStream("./sound/tokyrm.mp3");
    Music pauseLoop = LoadMusicStream("./sound/tapeHiss_1.mp3");
    Sound slap = LoadSound("./sound/slap.mp3");
    Sound fart = LoadSound("./sound/fart1.mp3");
    Sound zbonj = LoadSound("./sound/coin.mp3");
    Sound fire = LoadSound("./sound/fire.mp3");
    Sound equ = LoadSound("./sound/equip.mp3");
    Sound ARGH = LoadSound("./sound/Zach_scream.mp3");
    Sound argh = LoadSound("./sound/Zach_Bird_scream.mp3");
    Sound oney_scream = LoadSound("./sound/oney_scream.mp3");
    Sound blbl = LoadSound("./sound/blblbl.mp3");
    Sound uhh = LoadSound("./sound/uhh.mp3");
    Sound intro = LoadSound("./sound/intro.WAV");

    SetMusicVolume(loop, 0.7);
    SetMusicVolume(pauseLoop, 0.65);
    SetSoundVolume(slap, 0.3);
    SetSoundVolume(fart, 0.65);
    SetSoundVolume(ARGH, 0.4);
    SetSoundVolume(argh, 0.4);
    SetSoundVolume(fire, 0.25);
    SetSoundVolume(equ, 0.25);
    SetSoundVolume(zbonj, 0.5);
    SetSoundVolume(intro, 0.7);
    SetSoundVolume(uhh, 0.7);

    PlayMusicStream(loop);

    // Ramblings of a madman:

    // int GetRandomValue(int min, int max);     // Get a random value between min and max (both included)

    // Introduce starting speed
    // x, y pos + randomx.brz + randomy.brz

    // Collisions with frame edges
    // if RecCollision(loptica, ivica kadra){x, y pos + -randomx.brz + -randomy.brz}

    // "Make it rain"

    Vector2 mousePoint;
    Rectangle sourcePointer = {0, 0, 64, 64};
    Rectangle sourcePrase = {0, 0, 120, 120};
    Rectangle prase;
    Rectangle praseKlik;
    Rectangle Nemesis = {0, 0, 120, 120};
    Rectangle prdez;
    Rectangle nesto;
    Rectangle srcPrdezD = {350, 0, 50, 50};
    Rectangle srcPrdez = {0, 0, 50, 50};
    Rectangle sourceBkg = {0, 0, 1200, 800};
    Rectangle sourceCoin = {0, 0, 85, 85};
    Rectangle sourceExplo = {0, 0, 96, 96};
    Rectangle okvir = {40, 10, 220, 80};
    Rectangle sourceKrg = {0, 0, 100, 100};
    Rectangle gun = {0, 0, 120, 120};
    Rectangle gunS = {0, 0, 80, 80};
    Rectangle gunSpawn;
    Rectangle metak = {0, 0, 20, 20};
    Rectangle sourceVeve = {0, 0, 150, 150};
    Rectangle sourcePause = {0, 0, 400, 400};
    Rectangle sourceNoise = {0, 0, 1200, 800};
    Rectangle sourceOblac = {0, 0, 1200, 800};
    Rectangle sourceGun = {0, 0, 120, 120};
    Camera2D camera = {0};
    int frame = 0;
    int anim = 0;
    int marker = 0;
    int once = 0;
    int aniCounter = 0;
    int pausedCounter = 0;
    int coinCounter = 0;
    int boop = 0;
    float sprt_paused = 0;
    float sprt_noise = 0;
    int clicks = 0;
    int fel = 0;
    int delta = 0;
    int deltaT = 0;
    float smerX = -1;
    float smerY = 1;
    float smerXn = 0;
    float smerYn = 0;
    float nakudX = 0;
    float nakudY = 0;
    bool clicked = false;
    bool pokupljen = false;
    bool equipped = false;
    bool paljba = false;
    bool hit = false;
    bool aniHitP = false;
    bool iFrame = false;
    bool veveTime = false;
    bool pause = false;
    bool praseKaput = false;
    bool start = false;
    bool stateCheck = false;
    bool veveCheck = false;
    bool dead = false;
    bool novcic = false;
    float velocityX = 0;
    float velocityY = 0;
    float velocityXn = 0;
    float velocityYn = 0;
    float centX, centXn = 0;
    float centY, centYn = 0;
    float shellPointX, shellPointY = 0;
    int cc = 0;
    float Cx = GetRandomValue(75, 1125);
    float Cy = GetRandomValue(75, 725);
    float a, b, c;
    float aN, bN, cN = 1;
    float gA, gB, gC = 1;
    float bgA, bgB, bgC = 1;
    float sA, sB, sC;
    float xDr = 1;
    float yDr = 1;
    float x = 1300; // screenWidth/2-60;
    float y = 300;  // screenHeight/2-60;
    float xn = GetRandomValue(-800, 2000);
    float yn = GetRandomValue(0, 1) * 1200 + GetRandomValue(-100, -200);
    float shellX = -500;
    float shellY = -500;
    float boomX = -200;
    float boomY = -200;
    int gX = GetRandomValue(100, 1100);
    int gY = GetRandomValue(100, 700);
    bool stop = false;

    float rot;

    camera.target = (Vector2){screenWidth / 2 + 300, screenHeight / 2};
    camera.offset = (Vector2){screenWidth / 2, screenHeight / 2}; //
    camera.zoom = 2.0f;

    for (int i = 0; i < niz; i++)
    {

        kusaca[i].position.x = GetRandomValue(1300, 2500);
        kusaca[i].position.y = GetRandomValue(00, 800);
        kusaca[i].centar.x = kusaca[i].position.x + 60;
        kusaca[i].centar.y = kusaca[i].position.y + 60;
        kusaca[i].A = 0;
        kusaca[i].B = 0;
        kusaca[i].C = 0;
        kusaca[i].smer.x = -1;
        kusaca[i].smer.y = 0;
        kusaca[i].velocity.x = 0;
        kusaca[i].velocity.y = 0;
        kusaca[i].veverica = {0, 0, 120, 120};
        kusaca[i].boom.x = -500;
        kusaca[i].boom.y = -500;
        kusaca[i].aniHit = false;
    }
    for (int i = 0; i < lis; i++)
    {
        list[i].position.x = (float)GetRandomValue(0, 1200);
        list[i].position.y = (float)GetRandomValue(300, -3000);
        list[i].padanje = GetRandomValue(2, 10);
        list[i].vreme = 0;
        list[i].source = {0, 0, 55, 32};
        list[i].color = WHITE;
    }

    SeekMusicStream(loop, 3);

    HideCursor();
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        // prase = {x-25,y-15,150,150};
        if (!pause)
        {

            UpdateMusicStream(loop);

            aniCounter++;
            fel++;
            coinCounter++;
            boop++;
            frame++;
            anim++;
            /*
            if (!stop)
            {
                PlaySoundMulti(intro);
                stop = true;
            }*/
            if (frame <= 500)
                x -= 1;
            if (frame > 500)
                start = true;

            if (start && camera.zoom >= 1.005)
            {
                camera.zoom -= 0.005;
                camera.target.x -= 1.5;
            }

            // if (x>(screenWidth/(camera.zoom*2)) && x<(screenWidth -(screenWidth/(camera.zoom*2)))) camera.target.x = x;
            // if (y>(screenHeight/(camera.zoom*2)) && y<(screenHeight -(screenHeight/(camera.zoom*2)))) camera.target.y = y;

            centX = x + 55;
            centY = y + 55;

            centXn = xn + 50;
            centYn = yn + 50;

            if (centX <= -50 && !dead)
            {
                PlaySoundMulti(ARGH);
                PlaySoundMulti(argh);
                PlaySoundMulti(oney_scream);
                dead = true;
            }

            shellPointX = x + 160;
            shellPointY = y + 60;

            prdez = {x, y, 64, 64};

            mousePoint = GetMousePosition();

            if (start)
            {
                if (!veveTime)
                {
                    if (x >= screenWidth - 100)
                    {
                        smerX = -smerX;
                        x -= 10;
                    }
                    else if (x <= 10)
                    {
                        smerX = -smerX;
                        x += 10;
                    }
                }

                if (y >= screenHeight - 100 || y == 10)
                {
                    smerY = -smerY;
                    y -= 10;
                }
                if (y <= 10)
                {
                    smerY = -smerY;
                    y += 10;
                }
            }

            //////////////
            // LOOP ANIMATION
            /////////////

            if (aniCounter == 5)
            {
                if (clicked)
                    sourcePointer.x += 64;
                if (aniHitP)
                {
                    sourceExplo.x += 96;
                }
                for (int i = 0; i < niz; i++)
                {
                    if (kusaca[i].aniHit)
                    {
                        kusaca[i].sprt += 96;
                        kusaca[i].source = {0 + kusaca[i].sprt, 0, 96, 96};
                    }
                }
                for (int i = 0; i < niz; i++)
                {
                    if (kusaca[i].sprt >= 1248)
                    {
                        kusaca[i].boom.x = -500;
                    }
                }
                sourceCoin.x += 85;
                sourceVeve.x += 150;
                sourcePrase.x += 120;
                sourceBkg.x += 1200;
                srcPrdezD.x -= 50;
                srcPrdez.x += 50;
                if (sourcePointer.x == 256)
                {
                    sourcePointer.x = 0;
                    clicked = false;
                }
                if (sourceExplo.x == 1248)
                {
                    sourceExplo.x = 0;
                    aniHitP = false;
                }
                if (sourcePrase.x == 600)
                    sourcePrase.x = 0;
                if (srcPrdezD.x == 0)
                    srcPrdez.x = 350;
                if (srcPrdez.x == 350)
                    srcPrdezD.x = 0;
                if (sourceCoin.x == 680)
                    sourceCoin.x = 0;
                if (sourceKrg.x == 3200)
                    sourceKrg.x = 0;
                if (sourceVeve.x == 1200)
                    sourceVeve.x = 0;

                aniCounter = 0;
            }

            if (anim == 12)
            {
                sourceOblac.x += 1200;
                if (sourceOblac.x == 9 * 1200)
                    sourceOblac.x = 0;
                for (int i = 0; i < lis; i++)
                {
                    if (list[i].position.y >= 400)
                    {
                        list[i].vreme++;
                    }
                    if (list[i].vreme > 12 && list[i].color.a >= 60)
                        list[i].color.a -= 25;
                    if (list[i].color.a <= 60)
                        list[i].color.a = 0;
                    list[i].source.x += 55;
                    if (list[i].source.x >= 330)
                        list[i].source.x = 0;
                    list[i].position.y += list[i].padanje;
                }
                sourceGun.x += 120;
                sourceBkg.x += 1200;
                if (sourceGun.x == 720)
                    sourceGun.x = 0;
                if (sourceBkg.x == 10800)
                    sourceBkg.x = 0;

                anim = 0;
            }

            //////////////
            // LOOP ANIMATION
            /////////////

            // SourceRec sekcija
            // prase = {x+5,y+5,110,110};
            if (start)
            {
                if (cc >= 10 || novcic)
                {
                    gunSpawn = {(float)gX, (float)gY, 50, 50}; //
                    novcic = true;
                }
                prase = {x - 5, y - 5, 110, 110};
                praseKlik = {x - 25, y - 25, 150, 150};
                Nemesis = {xn + 10, yn + 10, 100, 100};
                nesto = {Cx, Cy, 85, 85};
            }

            // SourceRec
            if (start)
            {
                if (CheckCollisionRecs(nesto, prase))
                {
                    if (!pokupljen)
                    {
                        PlaySoundMulti(zbonj);
                        pokupljen = true;
                        Cx = -500;
                        Cy = -500;
                        cc++;
                        coinCounter = 0;
                    }
                }

                if (pokupljen)
                {
                    for (int i = 0; i < 16; i++)
                    {
                        Cx = GetRandomValue(75, 1125);
                        Cy = GetRandomValue(75, 725);
                        if (Cx == centX && Cy == centY)
                        {
                            Cx = GetRandomValue(75, 1125);
                            Cy = GetRandomValue(75, 725);
                        }
                    }
                    if (coinCounter == 90)
                    {
                        pokupljen = false;
                        coinCounter = 0;
                    }
                }

                if (CheckCollisionRecs(gunSpawn, prase) && !equipped)
                {
                    PlaySound(equ);
                    equipped = true;
                    gX = -500;
                    gY = -500;
                }
            }

            ////////////////////////////////
            // SUDAR PRASE
            ////////////////////////////////
            if (start)
            {
                if (CheckCollisionRecs(Nemesis, prase) && !iFrame)
                {
                    // ubrzaj prase
                    abc(centXn, centX, centYn, centY, &bgA, &bgB, &bgC);
                    if (smerX != smerXn)
                    {
                        smerX = -smerX;
                    }
                    if (smerY != smerYn)
                    {
                        smerY = -smerY;
                    }
                    // if (smerX==smerXn) smerXn=-smerXn;
                    // if (smerY==smerYn) smerYn=-smerYn;
                    // ovaj deo radi, ali kad mu je smer isti kao smer kretanja besnog praseta ima da ga okrene na suprotnu stranu;
                    // kako da se resi ovo govno, hmmm;
                    // dodo smerove sad kadgod se sudare zlo prase se nacedi nekako i ide gore ili dole.
                    // reseno odbijanje praseta u svakom slucaju, sad je problem sto zlopras ne reaguje kako zelim, samo se trza u mestu.
                    velocityX += abs(bgA / bgC) * 10; // ogranici ubrzanje na 20
                    velocityY += abs(bgB / bgC) * 10; // ogranici ubrzanje na 20
                    velocityXn -= abs(bgA / bgC) * 10;
                    velocityYn -= abs(bgB / bgC) * 10;
                    // yn -= abs(bN/cN)*45;
                    iFrame = true;
                    delta = frame;
                    PlaySound(blbl);
                    if (cc >= 1)
                        cc -= 1;
                    // PlaySound(boop);
                    // Problem sa smerom prilikom odbijanja
                }

                if (iFrame)
                {
                    if (frame % 4 == 0)
                        slapped = WHITE;
                    else
                        slapped = BLANK;
                }

                if ((frame - delta) == 45)
                {
                    iFrame = false;
                    velocityXn = 0;
                    velocityYn = 0;
                    velocityX = 0;
                    velocityY = 0;
                    smerXn = -smerXn;
                    smerYn = -smerYn;
                    slapped = WHITE;
                }

                if (CheckCollisionRecs(Nemesis, metak))
                {
                    boomX = xn;
                    boomY = yn;
                    hit = true;
                    aniHitP = true;
                    paljba = false;
                    shellX = -500;
                    shellY = -500;
                    if (cc >= 10)
                        praseKaput = true;
                }

                if (hit)
                {
                    xn = GetRandomValue(-800, 2000);
                    yn = GetRandomValue(0, 1) * 1200 + GetRandomValue(-100, -200);
                    hit = false;
                }
            }

            ////////////////////////////////
            // SUDAR PRASE
            ////////////////////////////////

            ////////////////////////////////
            // SQUIRREL COLLISION
            ////////////////////////////////

            if (cc >= 15)
                veveCheck = true;

            if (veveCheck)
            {

                for (int i = 0; i < niz; i++)
                {
                    kusaca[i].position.x -= 3;
                    // kusaca[i].centar.x = kusaca[i].position.x + 60;
                    // kusaca[i].centar.y = kusaca[i].position.y + 60;
                    kusaca[i].veverica = {kusaca[i].position.x, kusaca[i].position.y, 120, 120};
                    // if (kusaca[i].position.x > 1100 || kusaca[i].position.x < 100) kusaca[i].smer.x *= -1;
                    // if (kusaca[i].position.y > 700  || kusaca[i].position.y < 100) kusaca[i].smer.y *= -1;
                }

                for (int i = 0; i < niz; i++)
                {
                    if (CheckCollisionRecs(kusaca[i].veverica, metak))
                    {
                        kusaca[i].boom.x = kusaca[i].position.x;
                        kusaca[i].boom.y = kusaca[i].position.y;
                        shellX = -500;
                        shellY = -500;
                        kusaca[i].position.x = 5000;
                        kusaca[i].aniHit = true;
                    }
                }
                for (int i = 0; i < niz; i++)
                {
                    if (CheckCollisionRecs(kusaca[i].veverica, prase))
                    {
                        marker++;
                        kusaca[i].centar.x = kusaca[i].position.x + 60;
                        kusaca[i].centar.y = kusaca[i].position.y + 60;
                        abc(kusaca[i].centar.x, centX, kusaca[i].centar.y, centY, &kusaca[i].A, &kusaca[i].B, &kusaca[i].C);
                        if (smerX != kusaca[i].smer.x)
                        {
                            smerX = -smerX;
                        }
                        if (smerY != kusaca[i].smer.y)
                        {
                            smerY = -smerY;
                        }
                        velocityX += abs(kusaca[i].A / kusaca[i].C) * 2; // ogranici ubrzanje na 20
                        velocityY += abs(kusaca[i].B / kusaca[i].C) * 2; // ogranici ubrzanje na 20
                        // kusaca[i].velocity.x -= abs(kusaca[i].A/kusaca[i].C)*10;
                        // kusaca[i].velocity.y -= abs(kusaca[i].B/kusaca[i].C)*10;
                        iFrame = true;
                        delta = frame;
                        if (marker >= 10)
                            veveTime = true;
                    }
                }

                if (iFrame)
                {
                    if (frame % 4 == 0)
                        slapped = WHITE;
                    else
                        slapped = BLANK;
                }

                if ((frame - delta) == 30)
                {
                    iFrame = false;
                    // velocityXn = 0;
                    // velocityYn = 0;
                    velocityX = 0;
                    velocityY = 0;
                    smerXn = -smerXn;
                    smerYn = -smerYn;
                    slapped = WHITE;
                }

                if (x <= 50)
                {
                    deltaT = frame;
                }

                if ((frame - deltaT == 60) && once == 0)
                {
                    once++;
                }
            }

            ////////////////////////////////
            // SQUIRREL COLLISION
            ////////////////////////////////

            ////////////////////////////////
            // Input
            ////////////////////////////////

            // prase input kontrolisan (zavisno sa koje strane ga pljusnes, ide na suprotnu); Zapravo sam uspeo uz trigonometrijska sranja o.o
            // Zlo prase sistem pracenja
            // Brzo prase, sampion

            /*
            aN=centXn-centX;
            bN=centYn-centY;
            cN=sqrt(aN*aN+bN*bN);
            yn-=(bN/cN)*3; // cos
            xn-=(aN/cN)*3; // sin
            */

            ////////////
            // Movement
            ////////////

            if (cc >= 5)
                stateCheck = true;

            if (start && stateCheck)
            {
                if (!veveCheck || !praseKaput)
                {
                    abc(centX, centXn, centY, centYn, &aN, &bN, &cN);

                    xn += smerXn * (abs(aN / cN) * 2 + velocityXn); // cos
                    yn += smerYn * (abs(bN / cN) * 2 + velocityYn); // sin

                    if (aN / cN <= 0)
                        smerXn = -1;
                    if (aN / cN > 0)
                        smerXn = 1;
                    if (bN / cN < 0)
                        smerYn = -1;
                    if (bN / cN > 0)
                        smerYn = 1;
                }
            }
            // Player
            if (start)
            {
                x += smerX * (xDr + velocityX);
                y += smerY * (yDr + velocityY);
            }

            ////////////
            // Movement
            ////////////

            ///////////
            // SLAP
            //////////

            if (CheckCollisionPointRec(mousePoint, praseKlik))
            {
                // abc(centX,mousePoint.x,centY,mousePoint.y,&a,&b,&c);
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                {
                    PlaySoundMulti(slap);
                    clicks++;
                    abc(centX, mousePoint.x, centY, mousePoint.y, &a, &b, &c);
                    y += (b / c) * 15;
                    x += (a / c) * 15;
                    sudarsmer(centX, mousePoint.x, centY, mousePoint.y, &smerX, &smerY);
                    velocityX = (abs(a / c)) * 10;
                    velocityY = (abs(b / c)) * 10;
                    if (clicks % 8 == 0 && clicks != 0)
                    {
                        fel = 0;
                        PlaySoundMulti(fart);
                    }
                    if (clicks % 13 == 0 && clicks != 0)
                    {
                        PlaySoundMulti(uhh);
                    }
                    clicked = true;
                }
            }

            ///////////
            // SLAP
            //////////

            if (!CheckCollisionPointRec(mousePoint, prase))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && equipped && !paljba)
                {
                    // isprdi metak u tom smeru
                    if (smerX == -1)
                        shellPointX -= 180;
                    shellX = shellPointX;
                    shellY = shellPointY;
                    gA = shellPointX - mousePoint.x;
                    gB = shellPointY - mousePoint.y;
                    gC = sqrt(gA * gA + gB * gB);
                    paljba = true;
                    PlaySoundMulti(fire);
                }
            }

            // hitbox se pomeri jer se X,y praseta pomeri nakon klika a samim tim i shellX,Y koji vrednost uzimaju od x,y i kad kliknes prase se pomeri

            // hitbox srcRec za metak, za po 4px veci
            metak = {shellX - 2, shellY - 2, 24, 24};

            // ako je paljb, vozi metak. Cim izadje sa ivice ekrana. ne dodajes mu vise vrednost da ne nastavi da leti
            if (paljba)
            {
                shellX -= (gA / gC) * 20;
                shellY -= (gB / gC) * 20;
            }

            ////////////
            // SLOWDOWN
            ///////////
            // Piggy slows down gradually after being slapped

            if (frame % 3 == 0 && velocityX > 0)
            {
                velocityX -= 0.25;
            }
            if (frame % 3 == 0 && velocityY > 0)
            {
                velocityY -= 0.25;
            }

            ////////////
            // SLOWDOWN
            ///////////

            /////////////////
            // RESET state
            // Tastatura proto RESET state
            /////////////////

            if (IsKeyReleased(KEY_R))
            {
                x = 540;
                y = 340;
                cc = 0;
                velocityX = 0;
                velocityY = 0;
                xn = 10;
                yn = 10;
                gX = GetRandomValue(100, 1100);
                gY = GetRandomValue(100, 700);
                equipped = false;
                PlaySoundMulti(ARGH);
                PlaySoundMulti(argh);
            }

            if (equipped)
            {
                gunSpawn = {-500, -500, 40, 40};
            }

            /////////////////
            // RESET state
            /////////////////

            rot += GetMouseWheelMove();
        }

        if (IsKeyReleased(KEY_SPACE))
        {
            pause = !pause;
        }

        if (pause)
        {
            PlayMusicStream(pauseLoop);
            UpdateMusicStream(pauseLoop);
            pausedCounter++;
        }

        if (pausedCounter == 7)
        {
            sprt_paused += 400;
            sprt_noise += 1200;
            sourcePause = {0 + sprt_paused, 0, 400, 400};
            sourceNoise = {0 + sprt_noise, 0, 1200, 800};
            if (sprt_paused == 4800)
            {
                sprt_paused = 0;
            }
            if (sprt_noise == 1200 * 12)
            {
                sprt_noise == 0;
            }
            pausedCounter = 0;
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        BeginMode2D(camera);

        DrawTextureRec(bkg, sourceBkg, (Vector2){0, 0}, WHITE);

        if (!pokupljen && start)
        {
            DrawTextureRec(coin, sourceCoin, (Vector2){Cx, Cy}, WHITE);
            pokupljen = false;
        }

        // METAK || HITBOX

        DrawCircle(shellX, shellY, 10, BLACK);

        // METAK || HITBOX

        // prase go boom boom

        DrawTextureRec(explo, sourceExplo, Vector2{boomX, boomY}, WHITE);

        // prase go boom boom

        // DrawTextureRec(gunZ,sourceGun,Vector2{(float)gX,(float)gY},WHITE);

        if (!equipped)
        {
            if (cc >= 10 || novcic)
                DrawTextureRec(gunZ, sourceGun, Vector2{(float)gX, (float)gY}, WHITE);
        }

        if (paljba && equipped)
        {
            if (shellX > 1220 || shellX < -100 || shellY > 820 || shellY < -20)
                paljba = false;
        }

        /////////////
        // SPAWN Nemesis Prase
        /////////////

        if (smerXn == 1)
        {
            DrawTextureRec(prasenceD, sourcePrase, (Vector2){xn, yn}, GRAY);
        }
        if (smerXn == -1)
        {
            DrawTextureRec(prasenceL, sourcePrase, (Vector2){xn, yn}, GRAY);
        }
        // DrawRectangleLines(xn, yn, 120, 120, YELLOW);
        // DrawTextureRec(hitbox, sourceFix,(Vector2){xn-15,yn-15}, WHITE); //150 150

        /////////////
        // SPAWN Nemesis Prase
        /////////////

        /////////////
        // Main prase
        /////////////

        if (smerX == 1)
        {
            DrawTextureRec(prasenceD, sourcePrase, (Vector2){x, y}, slapped);
            if (equipped)
                DrawTextureRec(gunZR, gunS, Vector2{x + 80, y + 40}, slapped);
            if (clicks % 8 == 0 && clicks != 0 && fel < 35)
            {
                DrawTextureRec(prdezL, srcPrdez, (Vector2){x - 30.0f, y + 60.0f}, YELLOW);
            }
        }

        if (smerX == -1)
        {
            DrawTextureRec(prasenceL, sourcePrase, (Vector2){x, y}, slapped);
            if (equipped)
                DrawTextureRec(gunZL, gunS, Vector2{x - 40, y + 40}, slapped);
            if (clicks % 8 == 0 && clicks != 0 && fel < 35)
            {
                DrawTextureRec(prdezD, srcPrdezD, (Vector2){x + 110, y + 60}, YELLOW);
            }
        }

        // DrawLineV(Vector2 {mousePoint.x,mousePoint.y}, Vector2 {centX,centY}, WHITE);

        if (CheckCollisionPointRec(mousePoint, praseKlik))
        {
            sudarsmer(centX, mousePoint.x, centY, mousePoint.y, &nakudX, &nakudY);

            abc(centX, mousePoint.x, centY, mousePoint.y, &sA, &sB, &sC);
            DrawLineEx(Vector2{centX, centY}, Vector2{mousePoint.x + nakudX * abs(sA / sC) * 150, mousePoint.y + nakudY * abs(sB / sC) * 150}, 3, YELLOW);
            // DrawTexturePro(scarfy, sourceRec, destRec, origin, (float)rotation, WHITE);
            // DrawTexture(strelica, centX-60, centY-60, WHITE);
        }

        // DrawRectangleLinesEx(Rectangle {mousePoint.x-15,mousePoint.y-15,30,30}, 5, ORANGE);
        if (CheckCollisionPointRec(mousePoint, prase))
        {
            DrawTextureRec(mouse, sourcePointer, Vector2{mousePoint.x - 32, mousePoint.y - 32}, WHITE);
        }

        if (!equipped)
        {
            DrawTextureRec(mouse, sourcePointer, Vector2{mousePoint.x - 32, mousePoint.y - 32}, WHITE);
        }

        if (!CheckCollisionPointRec(mousePoint, prase) && equipped)
        {
            DrawTexture(cross, mousePoint.x - 32, mousePoint.y - 32, WHITE);
            // DrawRectangleLinesEx(Rectangle {mousePoint.x-15,mousePoint.y-15,30,30}, 5, ORANGE);
        }

        /////////////
        // Main Prase
        /////////////

        for (int i = 0; i < niz; i++)
        {
            DrawTextureRec(veve, sourceVeve, (Vector2){kusaca[i].position.x, kusaca[i].position.y}, WHITE);
            // DrawRectangleLines(kusaca[i].position.x,kusaca[i].position.y,120,120,YELLOW);
            DrawTextureRec(explo, kusaca[i].source, Vector2{kusaca[i].boom.x, kusaca[i].boom.y}, WHITE);
            // DrawRectangle(kusaca[i].boom.x+35,kusaca[i].boom.y+35,50,50,ORANGE);
            // DrawTextureRec(hitbox, sourceFix,(Vector2){kusaca[i].position.x-15,kusaca[i].position.y-15}, WHITE);
        }

        // Custom pointer draw and pointer UI

        // DrawTextureRec(mousePointer, sourcePointer,(Vector2){mousePoint.x,mousePoint.y}, WHITE);
        // DrawTextureRec(krug, sourceKrg, (Vector2){mousePoint.x-20,mousePoint.y-10}, WHITE);

        // DEBUG LAYER
        //

        // HITBOX
        /*
        DrawRectangleLines(shellX-15, shellY-15, 30, 30, YELLOW); // metak hitbox
        DrawRectangleLines(x-25, y-25, 150, 150, YELLOW); // dobro prase hitbox
        DrawRectangleLines(xn+10, yn+10, 100, 100, YELLOW); // zlo prase hitbox

        //DrawTextureRec(hitbox, sourceFix,(Vector2){xn-15,yn-15}, WHITE); //150 150 // koordinatni sistem putujuci
        //DrawTextureRec(hitbox, sourceFix,(Vector2){x-15,y-15}, WHITE); //150 150 // koordinatni sistem putujuci

        // STATS

        DrawText(TextFormat("srcPrdezD.x%.3f\nsrcPrdez.x %.3f", srcPrdezD.x, srcPrdez.x), 1000,0, 20, WHITE);
        DrawText(TextFormat("smerXn %0.3f\nsmerYn %.3f\n", nakudX,nakudY), 1000,110, 20, WHITE);
        DrawText(TextFormat("camezom %.3f,\nboom.y %.3f\n", camera.zoom,velocityYn), 1050,180, 25, WHITE);
        DrawText(TextFormat("frame \n %.3f", sourceOblac.x), 1050,280, 25, WHITE);
        DrawText(TextFormat("smerX \n %.3f", smerX), 1050,380, 25, WHITE);
        DrawText(TextFormat("smerY \n %0.3f", smerY), 1050,480, 25, WHITE);
        DrawText(TextFormat("sin=b/c \n %0.3f", b/c), 1050,580, 25, WHITE);
        DrawText(TextFormat("cos=a/c \n %0.3f", a/c), 1050,680, 25, WHITE);

        */

        // DEBUG LAYER
        //
        for (int i = 0; i < lis; i++)
        {
            DrawTextureRec(leaf, list[i].source, Vector2{list[i].position.x, list[i].position.y}, list[i].color);
        }
        // STATS
        // DrawTexture(oblac,0,0,WHITE);
        DrawTextureRec(oblac, sourceOblac, Vector2{0, 0}, WHITE);
        // Coin counter upper left
        DrawRectangleRounded(okvir, 0.8, 4, BLACK);
        DrawTextureRec(coin, sourceCoin, (Vector2){50, 10}, slapped);
        DrawText(TextFormat("X %i", cc), 125, 25, 50, WHITE);

        if (pause)
        {
            // DrawRectangle(0,0,1200,800,{0,0,0,150});
            DrawTextureRec(noise, sourceNoise, Vector2{0, 0}, WHITE);
            DrawTextureRec(pausescr, sourcePause, Vector2{400, 200}, WHITE);
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
