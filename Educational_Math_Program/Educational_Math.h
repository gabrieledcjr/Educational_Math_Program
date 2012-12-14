/*==============================================================================
 | Filename: Educational_Math.h                                                     
 | Programmer: Gabriel V. de a Cruz Jr.                                  
 | Class: CptS 121, Fall 2012 ; Lab Section 7                            
 | Programming Assignment 8: Educational Math Program                    
 | Date: December 7, 2012                                                 
 +------------------------------------------------------------------------------
 | Description: This file contains all the function prototypes, macro constants,
 |              enumerated types, standard and user-define libraries.
 +==============================================================================*/
#ifndef EDUCATIONAL_MATH_H
#define EDUCATIONAL_MATH_H

/* standard libraries */
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

/* menu items */
#define LEARN_TO_USE_PROGRAM  1
#define DIFFICULTY_SELECTION  2
#define START_LEARNING        3
#define SAVE_QUIT             4

#define N_QUESTIONS           10

/* enumerated types */
typedef enum boolean {
	False, True
} Boolean;

typedef enum level {
	EASY = 1, 
	FAIR, 
	INTERMEDIATE, 
	HARD, 
	IMPOSSIBLE
} Level;

/* user-defined libraries */
#include "random.h"
#include "graphics.h"

/* function prototypes */
void drawTitle (const int x, const int y);
void drawMenu (const int x, const int  y);
void drawUserBar (const char *cInitials);
void drawDifficultyBar (Level difficulty);
void drawPointsBar (int wPoints);
void drawTotalPointsBar (int wPoints);
void drawProgressBar (int wCurrentQuestion, int wTotalQuestions);
void getDifficulty (Level difficulty);

short selectMainMenuItem (void);

void drawDifficultyMenu (const int x, const int y);
int setDifficulty (void);
void startLearning (Level difficulty, int *wTotalPoints_ptr);

int easyLevel (const int wPoints);
int fairLevel (const int wPoints);
int intermediateLevel (const int wPoints);
int hardLevel (const int wPoints);
int impossibleLevel(const int wPoints);

int compute (int wOperand1, int wOperand2, const char cOperator);

void drawNumber (int number, int x, int y);
void drawOperator (char sign, int x, int y);

void drawEqualSign (int x, int y);
void drawPlusSign (int x, int y);
void drawMultiplySign (int x, int y);
void drawMinusSign (int x, int y);
void drawDivisionSign (int x, int y);
void drawZero (int x, int y);
void drawOne (int x, int y);
void drawTwo (int x, int y);
void drawThree (int x, int y);
void drawFour (int x, int y);
void drawFive (int x, int y);
void drawSix (int x, int y);
void drawSeven (int x, int y);
void drawEight (int x, int y);
void drawNine (int x, int y);

void drawCorrect (int x, int y);
void drawWrong (int x, int y);

void viewHelp (Level difficulty);
void easyHelp (int x, int y);
void fairHelp (int x, int y);
void intermediateHelp (int x, int y);
void hardHelp (int x, int y);
void impossibleHelp (int x, int y);
void learnToUseProgram (void);

void generateDataFile (FILE *stream, char *cInitials, int wTotalPoints);
char messageBox (char *message, int x, int y, int length, int width, Boolean optYesNo);

#endif