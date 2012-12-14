/*==============================================================================
 | Filename: main.c                                                      
 | Programmer: Gabriel V. de a Cruz Jr.                                  
 | Class: CptS 121, Fall 2012 ; Lab Section 7                            
 | Programming Assignment 8: Educational Math Program                  
 | Date: December 7, 2012                                                 
 +------------------------------------------------------------------------------
 | Description: This program is an Educational Math Program that targets elem-
 |              entary school children. Program is intended for student to 
 |              practice simple, addition, subtraction, multiplication and 
 |              division.
 +==============================================================================*/
#include "Educational_Math.h"

int main (void) {

	FILE *outputStream = NULL;

	char cInitials [4] = ""; /* stores user initials */
	short nMenuItem = 0;     /* menu item chosen */
	int wTotalPoints = 0;    /* tracks user's total points */

	/* level of difficulty is set to easy */
	Level difficulty = EASY;

	/* opens file stream */
	outputStream = fopen ("results.txt", "a");

	/* seed random-number generator */
	Randomize ();

	/* prompts user to input 3-letter initials */
	MoveCursor (24, 10);
	printf ("ENTER 3-LETTER INITIALS: ");
	gets (cInitials);


	/* loops until user exits */
	while (True) {

		/* initializes blackboard */
		system ("cls");
		drawTitle (18, 3);
		drawMenu (24, 10);
		drawUserBar (cInitials);
		drawDifficultyBar (difficulty);
		drawTotalPointsBar (wTotalPoints);

		/* prompts user to select a menu */
		nMenuItem = selectMainMenuItem ();

		switch (nMenuItem) {

			case LEARN_TO_USE_PROGRAM:
				/* Learn about how to use the program */
				learnToUseProgram ();
				break;

			case DIFFICULTY_SELECTION:
				/* dificulty selection */
				drawDifficultyMenu (24, 10);
				difficulty = (Level) setDifficulty ();
				drawDifficultyBar (difficulty);
				break;

			case START_LEARNING:
				/* start a new sequence of 10 problems */
				startLearning (difficulty, &wTotalPoints);
				break;

			case SAVE_QUIT:
				/* saves data to file */
				generateDataFile (outputStream, cInitials, wTotalPoints);

				/* closes file stream */
				fclose (outputStream);

				/* saves and quit */
				system ("cls");
				drawTitle (18, 3);
				MoveCursor (24, 10);
				printf ("Until next time, Good bye!");
				Pause (800);
				system ("cls");
				exit (1);
				break;
		}
	}

	return 0;
}