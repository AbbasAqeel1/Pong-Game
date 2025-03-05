
#include "raylib.h"
#include <iostream>
using namespace std;


//Colors
Color Dark_Purple = Color{ 63, 81, 181,255 };
Color Light_Purple = Color{ 121, 134, 203,255 };
Color Yellow = Color{ 255, 255, 0,255 };


//Player1 and Player2 Scores
int Paddle1_Score = 0;
int Paddle2_Score = 0;


class Ball
{

public:
    float x, y;
    int Speed_x,Speed_y;
    int Radius;

    void Draw()
    {
        DrawCircle(x, y, Radius, WHITE);
    }

    void Update()
    {
        x += Speed_x;
        y += Speed_y;

        //if ball hit the roof or floor
        if (y + Radius >= GetScreenHeight() || y - Radius <= 0)
        {
            Speed_y *= -1;
        }

        //player2 wins
        if (x - Radius <= 0 ) 
        {
            Paddle2_Score++;
            ResetBall();
        }

        //player1 wins
        if (x + Radius >= GetScreenWidth())
        {
            Paddle1_Score++;
            ResetBall();
        }
    }

    void ResetBall()
    {
        //Reset ball position in the middle of the table
        x = GetScreenWidth() / 2;
        y = GetScreenHeight() / 2;

        //Choose the ball dirction randomly
        int SpeedChoices[2] = { -1,1 };
        Speed_x *= SpeedChoices[GetRandomValue(0, 1)];
        Speed_y *= SpeedChoices[GetRandomValue(0, 1)];
    }
};

class Paddle
{
    float x, y;
    float Width, Height;
    int speed;
public:
    Paddle(float x, float y, float Width, float Height, int speed)
    {
        this->x = x;
        this->y = y;
        this->Width = Width;
        this->Height = Height;
        this->speed = speed;

    }

    float GetX()
    {
        return x;
    }
    float GetY()
    {
        return y;
    }
    float GetWidth()
    {
        return Width;
    }
    float GetHeight()
    {
        return Height;
    }
    int GetSpeed()
    {
        return speed;
    }

    //draw the paddle on the screen
    void Draw()
    {
        DrawRectangleRounded(Rectangle{ x,y,Width,Height }, 0.7, 0, Yellow);
    }

    //Update the movment of the paddle up and down
    void Update(bool IsUp)
    {
        //If the palyer pressed Key_UP move the paddle up
        if (IsUp && y > 0)
        {
            y -= speed;
        }
        //If the palyer pressed Key_Down move the paddle Down
        if (!IsUp && y + Height < GetScreenHeight())
            y += speed;
       
    }
};


int main(void)
{
    // Initialization

    //initialize the Width and Height of the screen
    const int Screen_Width = 1000;
    const int Screen_Height = 600;
    
    
    //initialize ball
    Ball ball;
    ball.x = Screen_Width / 2;
    ball.y = Screen_Height / 2;
    ball.Speed_x = 4;
    ball.Speed_y = 4;
    ball.Radius = 15;
    

    Paddle paddle1(10, Screen_Height / 2 - 35, 8, 70, 5);
    Paddle paddle2(Screen_Width - 10 - 8, Screen_Height / 2 - 35, 8, 70, 5);
     

    InitWindow(Screen_Width, Screen_Height, "Pong Game");

    SetTargetFPS(60);
    int framesCounter = 0;
    bool isPause = false;



    // Main game loop
    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(Light_Purple);
        DrawText("Press Space to Pause the Game", 10, Screen_Height - 20, 20, LIGHTGRAY);
        
        //updating

        //Pasuing the game
        if (IsKeyPressed(KEY_SPACE))
        {
            isPause = !isPause;
        }


        //Move paddle1 up and down
        if (IsKeyDown(KEY_W))
        {
            paddle1.Update(true);
        }
        if (IsKeyDown(KEY_S))
        {
            paddle1.Update(false);
        }

        //Move paddle2 up and down
        if (IsKeyDown(KEY_UP))
        {
            paddle2.Update(true);
        }
        if (IsKeyDown(KEY_DOWN))
        {
            paddle2.Update(false);
        }
        

        if (!isPause)
        {
            ball.Update();
            //Checking for collisions
            if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.Radius,
                Rectangle{ paddle1.GetX(),paddle1.GetY(),paddle1.GetWidth(),paddle1.GetHeight() }))
            {
                ball.Speed_x *= -1;
            }

            if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.Radius,
                Rectangle{ paddle2.GetX(),paddle2.GetY(),paddle2.GetWidth(),paddle2.GetHeight() }))
            {
                ball.Speed_x *= -1;
            }
        }
        else
        {
            framesCounter++;
        }
        


        //Drawing
        DrawRectangle(Screen_Width / 2, 0, Screen_Width / 2, Screen_Height, Dark_Purple);
        DrawLine(Screen_Width / 2, 0, Screen_Width / 2, Screen_Height, WHITE);

        ball.Draw();
        paddle1.Draw();
        paddle2.Draw();

        //Print Paddles Scores
        DrawText(TextFormat("%i", Paddle1_Score), 150, 20, 50, WHITE);
        DrawText(TextFormat("%i", Paddle2_Score), Screen_Width - 150, 20, 50, WHITE);

        if (isPause && (framesCounter / 30) % 2)
        {
            DrawText("Paused", Screen_Width / 2 - 55, Screen_Height / 2, 30, WHITE);
            
        }
        
        if (framesCounter > 30 * 10)
        {
            framesCounter = 0;
        }

        DrawFPS(10, 10);
        EndDrawing();
    }





    CloseWindow();

    return 0;
}



