/*==============================================================================
 | Filename: Educational_Math.h                                                     
 | Programmer: Gabriel V. de a Cruz Jr.                                  
 | Class: CptS 121, Fall 2012 ; Lab Section 7                            
 | Programming Assignment 8: Educational Math Program                    
 | Date: December 7, 2012                                                 
 +------------------------------------------------------------------------------
 | Description: This file contains all the function definitions required to run
 |              this program. There are also resource functions contained under
 |              random.h and graphics.h that are used by the functions on this 
 |              file.
 +==============================================================================*/
#include "Educational_Math.h"

/**
 * Function name : drawTitle ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws title on screen
 */
void drawTitle (const int x, const int y) {
	MoveCursor (x, y);
	printf ("88     88      8      88888888  88   88");
	MoveCursor (x, y + 1);
	printf ("8888 8888     888     88888888  88   88");
	MoveCursor (x, y + 2);
	printf ("88 888 88    88 88       88     8888888");
	MoveCursor (x, y + 3);
	printf ("88  8  88   88   88      88     88   88");
	MoveCursor (x, y + 4);
	printf ("88     88  888888888     88     88   88");
}

/**
 * Function name : drawMenu ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws the main menu on screen
 */
void drawMenu (const int x, const int  y) {
	DrawBorder (x - 1, y - 1, x + 28, y + 4);
	MoveCursor (x, y);
	printf ("[ 1 ] HOW TO USE THE PROGRAM");
	MoveCursor (x, y + 1);
	printf ("[ 2 ] DIFFICULTY LEVEL");
	MoveCursor (x, y + 2);
	printf ("[ 3 ] START LEARNING");
	MoveCursor (x, y + 3);
	printf ("[ 4 ] SAVE & QUIT");
}

/**
 * Function name : drawUserBar ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws the user bar at lower
 *                 part of the screen with user initials
 */
void drawUserBar (const char *cInitials) {
	DrawBorder (0, 22, 10, 24);
	printf ("USER: %s", cInitials);
}

/**
 * Function name : drawDifficultyBar ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws the difficulty bar
 *                 at lower part of the screen with level
 *                 of difficulty
 */
void drawDifficultyBar (Level difficulty) {
	DrawBorder (11, 22, 31, 24);
	printf ("LEVEL: ");
	getDifficulty (difficulty);
}

/**
 * Function name : drawPointsBar ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws points bar and the
 *                 points earned for the current sequence of
 *                 problems
 */
void drawPointsBar (int wPoints) {
	DrawBorder (51, 22, 63, 24);
	printf ("POINTS: %d", wPoints);
}

/**
 * Function name : drawTotalPointsBar ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws the total points bar
 *                 and the total points earned from using the
 *                 program
 */
void drawTotalPointsBar (int wPoints) {
	DrawBorder (64, 22, 78, 24);
	printf ("OVERALL: %d", wPoints);
}

/**
 * Function name : drawProgressBar ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws the progress bar and 
 *                 current question out of 10
 */
void drawProgressBar (int wCurrentQuestion, int wTotalQuestions) {
	DrawBorder (32, 22, 50, 24);
	printf ("PROBLEM# %d OF %d", wCurrentQuestion, wTotalQuestions);
}

/**
 * Function name : getDifficulty ()
 * Date Created  : 7 December 2012
 * Definition    : This function prints out the literal string of
 *                 level of difficulty specified
 */
void getDifficulty (Level difficulty) {
	switch (difficulty) {
		case EASY:         printf ("EASY");         break;
		case FAIR:         printf ("FAIR");         break;
		case INTERMEDIATE: printf ("INTERMEDIATE"); break;
		case HARD:         printf ("HARD");         break;
		case IMPOSSIBLE:   printf ("IMPOSSIBLE");   break;
	}
}

/**
 * Function name : selectMainMenuItem ()
 * Date Created  : 7 December 2012
 * Definition    : This function allows user to select an item
 *                 from the main menu
 */
short selectMainMenuItem (void) {
	short nMenuItem = 0;
	char cMenu = '\0';

	MoveCursor (24, 16);
	printf ("CHOOSE MENU: ");
	DrawBorder (36, 15, 40, 17);

	while (True) {
		MoveCursor (38, 16);
		cMenu = getch ();
		nMenuItem = cMenu - '0';

		if (nMenuItem >= 1 && nMenuItem <= 4) 
			break;
	}
}

/**
 * Function name : drawDifficultyMenu ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws the level of difficulty
 *                 menu
 */
void drawDifficultyMenu (const int x, const int y) {
	DrawBorder (x - 1, y - 1, x + 28, y + 6);
	MoveCursor (x, y);
	printf ("DIFFICULTY LEVEL MENU");
	MoveCursor (x, y + 1);
	printf ("LEVEL 1: EASY");
	MoveCursor (x, y + 2);
	printf ("LEVEL 2: FAIR");
	MoveCursor (x, y + 3);
	printf ("LEVEL 3: INTERMEDIATE");
	MoveCursor (x, y + 4);
	printf ("LEVEL 4: HARD");
	MoveCursor (x, y + 5);
	printf ("LEVEL 5: IMPOSSIBLE");
}

/**
 * Function name : setDifficulty ()
 * Date Created  : 7 December 2012
 * Definition    : This function sets level of difficulty
 */
int setDifficulty (void) {
	int wDifficulty = -1;
	char cMenu = '\0';

	/* clears old border */
	MoveCursor (36, 17);
	printf ("             ");

	MoveCursor (24, 18);
	printf ("CHOOSE LEVEL#: ");
	DrawBorder (38, 17, 42, 19);

	while (True) {
		MoveCursor (40, 18);
		cMenu = getch ();
		wDifficulty = cMenu - '0';

		if (wDifficulty >= 1 && wDifficulty <= 5) 
			break;
	}

	return wDifficulty;
}

/**
 * Function name : startLearning ()
 * Date Created  : 7 December 2012
 * Definition    : This function when user starts to learn math
 *                 based on level of difficulty chosen
 */
void startLearning (Level difficulty, int *wTotalPoints_ptr) {
	int wPoints = 0;
	int i = 0;

	char ch = '\0';

	ch = messageBox ("Do you want a review before you start?", 18, 10, 39, 4, True);

	if (toupper (ch) == 'Y') {
		viewHelp (difficulty);
	}

	/* generate a sequence of ten problems */
	for (i = 0; i < N_QUESTIONS; i++) {
		drawProgressBar (i, N_QUESTIONS);
		drawPointsBar (wPoints);
		drawTotalPointsBar (*wTotalPoints_ptr + wPoints);

		DrawBorder (0, 0, 79, 21);

		/* picks level difficulty */
		switch (difficulty) {
			case EASY:         wPoints += easyLevel (wPoints);          break;
			case FAIR:         wPoints += fairLevel (wPoints);          break;
			case INTERMEDIATE: wPoints += intermediateLevel (wPoints);  break;
			case HARD:         wPoints += hardLevel (wPoints);          break;
			case IMPOSSIBLE:   wPoints += impossibleLevel (wPoints);    break;
		}
	}

	*wTotalPoints_ptr += wPoints;
}

/**
 * Function name : easyLevel ()
 * Date Created  : 7 December 2012
 * Definition    : This function includes addition and subtraction
 *                 problems, with positive digit operands and up to
 *                 three terms only. Problems becomes a little more 
 *                 difficult as the users enters correct answers
 */
int easyLevel (const int wPoints) {
	int wOperands[3] = {0};  /* array of operands */
	int wResult = 0;
	int wAnswer = 0;
	int wStartRange = 0, 
		wEndRange = 0;

	int isCorrect = 0;
	
	char cOperations [2];

	short sNumOfOperands = 0;
	short i = 0;     /* counters */

	/* problems becomes a little more difficult as 
	   the user enters correct answer */
	if (wPoints < 3) { 
		/* sets easy problems */
		sNumOfOperands = 2; 
		wStartRange = 0;
		wEndRange = 5;
		isCorrect = 1;
	} else if (wPoints >= 3 && wPoints < 9) {
		/* sets moderate problems */
		sNumOfOperands = 3;
		wStartRange = 1;
		wEndRange = 6;
		isCorrect = 2;
	} else {
		/* sets more difficult problems */
		sNumOfOperands = 3;
		wStartRange = 0;
		wEndRange = 9;
		isCorrect = 3;
	}

	/* prints out how much points the problem is worth */
	MoveCursor (3, 8);
	printf ("Worth +%d Point(s)", isCorrect);

	/* sets positive single digit operands */
	for (i = 0; i < sNumOfOperands; i++) 
		wOperands[i] = RandomInteger (wStartRange, wEndRange); 

	wResult = wOperands[0];

	/* sets operations 0 is addition and 1 is subtraction */
	for (i = 0; i < sNumOfOperands - 1; i++) {
		cOperations[i] = RandomInteger (0, 1) == 1 ? '+' : '-';
		wResult = compute (wResult, wOperands[i + 1], cOperations[i]);
	}

	/* draws equation on blackboard */
	drawNumber (wOperands[0], 2, 2);
	drawOperator (cOperations[0], 8, 3);
	drawNumber (wOperands[1], 11, 2);

	if (sNumOfOperands == 3) {
		drawOperator (cOperations[1], 17, 3);
		drawNumber (wOperands[2], 20, 2);
		drawOperator ('=', 26, 3);
		MoveCursor (29, 4);
	} else {
		drawOperator ('=', 17, 3);
		MoveCursor (20, 4);
	}

	/* prompts user for answer */
	scanf ("%d", &wAnswer);

	/* check's user's answer */
	if (wAnswer == wResult) {
		drawCorrect (5, 11);
		Pause (900);
	} else {
		isCorrect = -1; /* subtracts 1 point if incorrect */
		drawWrong (5, 11);
		Pause (900);
	}

	return isCorrect;
}

/**
 * Function name : fairLevel ()
 * Date Created  : 7 December 2012
 * Definition    : This function includes multiplications problems,
 *                 with positive digit operands and up to two terms 
 *                 only. Problems becomes a little more difficult as 
 *                 the users enters correct answers
 */
int fairLevel (const int wPoints) {
	int wOperands[2] = {0};  /* array of operands */
	int wResult = 0;
	int wAnswer = 0;
	int wStartRange = 0, 
		wEndRange = 0;

	int isCorrect = 0;

	short sNumOfOperands = 2; /* maximum of two operands */
	short i = 0;     /* counters */

	/* problems becomes a little more difficult as 
	   the user enters correct answer */
	if (wPoints < 3) { 
		/* sets easy problems */
		wStartRange = 0;
		wEndRange = 3;
		isCorrect = 1;
	} else if (wPoints >= 3 && wPoints < 7) {
		/* sets moderate problems */
		wStartRange = 3;
		wEndRange = 6;
		isCorrect = 2;
	} else {
		/* sets more difficult problems */
		wStartRange = 6;
		wEndRange = 9;
		isCorrect = 3;
	}

	/* prints out how much points the problem is worth */
	MoveCursor (3, 8);
	printf ("Worth +%d Point(s)", isCorrect);

	/* sets positive single digit operands */
	wOperands[0] = RandomInteger (wStartRange, wEndRange); 
	wOperands[1] = RandomInteger (wStartRange, wEndRange); 

	/* computes result */
	wResult = compute (wOperands[0], wOperands[1], '*');

	/* draws equation on blackboard */
	drawNumber (wOperands[0], 2, 2);
	drawOperator ('*', 8, 3);
	drawNumber (wOperands[1], 11, 2);
	drawOperator ('=', 17, 3);
	MoveCursor (20, 4);

	/* prompts user for answer */
	scanf ("%d", &wAnswer);

	/* check's user's answer */
	if (wAnswer == wResult) {
		drawCorrect (5, 11);
		Pause (900);
	} else {
		isCorrect = -1; /* subtracts 1 point if incorrect */
		drawWrong (5, 11);
		Pause (900);
	}

	return isCorrect;
}

/**
 * Function name : intermediateLevel ()
 * Date Created  : 7 December 2012
 * Definition    : This function includes division problems, with 
 *                 positive digit operands and up to two terms 
 *                 only. Problems becomes a little more difficult as 
 *                 the users enters correct answers. Results should 
 *                 be shown in the Num R Remainder
 */
int intermediateLevel (const int wPoints) {
	int wOperands[2] = {0};  /* array of operands */
	int wResult = 0;
	int wResultRemainder = 0;
	int wAnswer = 0;
	int wAnswerRemainder = 0;
	int wStartRangeNumerator = 0, 
		wEndRangeNumerator = 0,
		wStartRangeDenominator = 0, 
		wEndRangeDenominator = 0;

	int isCorrect = 0;

	short sNumOfOperands = 2; /* maximum of two operands */
	short i = 0;     /* counters */

	char cAnswer[4] = "";

	/* problems becomes a little more difficult as 
	   the user enters correct answer */
	if (wPoints < 3) { 
		/* sets easy problems */
		wStartRangeNumerator = 0; 
		wEndRangeNumerator = 4;
		wStartRangeDenominator = 1; /* cannot be zero */
		wEndRangeDenominator = 4;
		isCorrect = 1;
	} else if (wPoints >= 3 && wPoints < 7) {
		/* sets moderate problems */
		wStartRangeNumerator = 3; 
		wEndRangeNumerator = 6;
		wStartRangeDenominator = 1; /* cannot be zero */
		wEndRangeDenominator = 6;
		isCorrect = 2;
	} else {
		/* sets more difficult problems */
		wStartRangeNumerator = 6; 
		wEndRangeNumerator = 9;
		wStartRangeDenominator = 2; /* cannot be zero */
		wEndRangeDenominator = 5;
		isCorrect = 3;
	}

	/* prints out how much points the problem is worth */
	MoveCursor (3, 8);
	printf ("Worth +%d Point(s)", isCorrect);

	/* sets positive single digit operands */
	wOperands[0] = RandomInteger (wStartRangeNumerator, wEndRangeNumerator);
	/* denominator cannot be zero */
	while (wOperands[1] == 0 || wOperands[1] > wOperands[0]) {
		wOperands[1] = RandomInteger (wStartRangeDenominator, wEndRangeDenominator); 
		if (wOperands[0] == 0) break;
	}

	/* computes result */
	wResult = compute (wOperands[0], wOperands[1], '/');
	wResultRemainder = compute (wOperands[0], wOperands[1], '%');

	/* draws equation on blackboard */
	drawNumber (wOperands[0], 2, 2);
	drawOperator ('/', 8, 3);
	drawNumber (wOperands[1], 11, 2);
	drawOperator ('=', 17, 3);

	/* input validation */
	while (True) {
		MoveCursor (20, 4);
		printf ("                                           ");

		/* prompts user for answer */
		MoveCursor (20, 4);
		fflush (stdin);
		gets (cAnswer);

		if (strlen (cAnswer) == 1 && isdigit (cAnswer[0])) {
			wAnswer = atoi (cAnswer);
			break;
		} else if (strlen (cAnswer) == 3 && (cAnswer[1] == 'r' || cAnswer[1] == 'R') && 
				   isdigit (cAnswer[0]) && isdigit (cAnswer[2])) {
			wAnswer = (int) (cAnswer[0] - '0');
			wAnswerRemainder = (int) (cAnswer[2] - '0');
			break;
		} else if (strlen (cAnswer) == 3 && isdigit (cAnswer[0]) && 
			       isdigit (cAnswer[1]) && isdigit (cAnswer[2])) {
			wAnswer = atoi (cAnswer);
			break;
		} else {
			MoveCursor (20, 4);
			printf ("Invalid input! Press Enter to continue");
			getch();
		}
	}

	/* check's user's answer */
	if (wAnswer == wResult && wResultRemainder == wAnswerRemainder) {
		drawCorrect (5, 11);
		Pause (900);
	} else {
		isCorrect = -1; /* subtracts 1 point if incorrect */
		drawWrong (5, 11);
		Pause (900);
	}

	return isCorrect;
}

/**
 * Function name : hardLevel ()
 * Date Created  : 7 December 2012
 * Definition    : This function includes a mix of addition, subtraction,
 *                 multiplication, and division problems, with positive and
 *                 negative single digit operands and up to three terms only
 */
int hardLevel (const int wPoints) {
	int wOperands[3] = {0};  /* array of operands */
	int wResult = 0;
	int wAnswer = 0;
	int wStartRange = 0, 
		wEndRange = 0;

	int isCorrect = 0;
	
	char cOperations [2];

	short sNumOfOperands = 0;
	short i = 0;     /* counters */

	Boolean isFlip = False;

	/* problems becomes a little more difficult as 
	   the user enters correct answer */
	if (wPoints < 6) { 
		/* sets easy problems */
		sNumOfOperands = 2; 
		wStartRange = RandomInteger (0, 1);
		wEndRange = 5;
		isCorrect = 2;
	} else if (wPoints >= 6 && wPoints < 15) {
		/* sets moderate problems */
		sNumOfOperands = 3;
		wStartRange = RandomInteger (0, 1);
		wEndRange = 6;
		isCorrect = 3;
	} else {
		/* sets more difficult problems */
		sNumOfOperands = 3;
		wStartRange = RandomInteger (0, 1);
		wEndRange = 9;
		isCorrect = 5;
	}

	/* prints out how much points the problem is worth */
	MoveCursor (3, 8);
	printf ("Worth +%d Point(s)", isCorrect);

	/* sets operations 0 is addition and 1 is subtraction */
	if (sNumOfOperands == 2) {
		if (RandomChance ()) { cOperations[0] = RandomInteger (0, 1) == 1 ? '+' : '-'; }
		else { cOperations[0] = RandomInteger (0, 1) == 1 ? '*' : '/'; } 
	} else {
		cOperations[0] = RandomInteger (0, 1) == 1 ? '*' : '/';
		cOperations[1] = RandomInteger (0, 1) == 1 ? '+' : '-';
	}

	/* sets positive single digit operands */
	for (i = 0; i < sNumOfOperands; i++) {
		wOperands[i] = RandomInteger (wStartRange, wEndRange);

		/* if operator is division, it must not have a remainder */
		if (i == 1 && cOperations[0] == '/') {
			if (wOperands[1] == 0 || compute (wOperands[0], wOperands[1], '%') != 0)
				i = 0; 
		}
	}

	/* change signs of the operands randomly */
	wOperands[0] = RandomChance() ? wOperands[0] * -1: wOperands[0];
	wOperands[1] = RandomChance() ? wOperands[1] * -1: wOperands[1];

	wResult = compute (wOperands[0], wOperands[1], cOperations[0]);

	if (sNumOfOperands == 3) {
		/* change signs of the operands randomly */
		wOperands[2] = RandomChance() ? wOperands[2] * -1: wOperands[2];

		if (RandomChance ()) {
			wResult = compute (wResult, wOperands[2], cOperations[1]);
		} else {
			isFlip = True;
			wResult = compute (wOperands[2], wResult, cOperations[1]);
		}
	}

	MoveCursor (2, 2);
	if (sNumOfOperands == 2) {
		printf ("%d %c %d = ",  wOperands[0], cOperations[0], wOperands[1]);
	} else {
		if (isFlip) {
			printf ("%d %c %d %c %d = ", wOperands[2], cOperations[1], wOperands[0], cOperations[0], wOperands[1]);
		} else {
			printf ("%d %c %d %c %d = ", wOperands[0], cOperations[0], wOperands[1], cOperations[1], wOperands[2]);
		}
	}

	/* prompts user for answer */
	scanf ("%d", &wAnswer);

	/* check's user's answer */
	if (wAnswer == wResult) {
		drawCorrect (5, 11);
		Pause (900);
	} else {
		isCorrect = -1; /* subtracts 1 point if incorrect */
		drawWrong (5, 11);
		Pause (900);
	}

	return isCorrect;
}

/**
 * Function name : impossibleLevel ()
 * Date Created  : 7 December 2012
 * Definition    : This function includes a mix of addition, subtraction,
 *                 multiplication, and division problems, with positive and 
 *                 negative two and three digit operands and up to three 
 *                 terms only
 */
int impossibleLevel(const int wPoints) {
	int wOperands[3] = {0};  /* array of operands */
	int wResult = 0;
	int wAnswer = 0;
	int wStartRange = 0, 
		wEndRange = 0;

	int isCorrect = 0;
	
	char cOperations [2];

	short sNumOfOperands = 0;
	short i = 0, j = 0;     /* counters */

	Boolean isFlip = False;

	/* problems becomes a little more difficult as 
	   the user enters correct answer */
	if (wPoints < 15) { 
		/* sets easy problems */
		sNumOfOperands = 2; 
		wStartRange = 10;
		wEndRange = 90;
		isCorrect = 5;
	} else if (wPoints >= 3 && wPoints < 36) {
		/* sets moderate problems */
		sNumOfOperands = 3;
		wStartRange = 10;
		wEndRange = 200;
		isCorrect = 7;
	} else {
		/* sets more difficult problems */
		sNumOfOperands = 3;
		wStartRange = 10;
		wEndRange = 999;
		isCorrect = 10;
	}

	/* prints out how much points the problem is worth */
	MoveCursor (3, 8);
	printf ("Worth +%d Point(s)", isCorrect);

	/* sets operations 0 is addition and 1 is subtraction */
	if (sNumOfOperands == 2) {
		if (RandomChance ()) { cOperations[0] = RandomInteger (0, 1) == 1 ? '+' : '-'; }
		else { cOperations[0] = RandomInteger (0, 1) == 1 ? '*' : '/'; } 
	} else {
		cOperations[0] = RandomInteger (0, 1) == 1 ? '*' : '/';
		cOperations[1] = RandomInteger (0, 1) == 1 ? '+' : '-';
	}

	/* sets positive operands */
	for (i = 0; i < sNumOfOperands; i++) {
		wOperands[i] = RandomInteger (wStartRange, wEndRange);

		/* if operator is division, it must not have a remainder */
		if (i == 1 && cOperations[0] == '/') {
			if (wOperands[1] == 0)  {
				i = 0; 
			} else if (compute (wOperands[0], wOperands[1], '%') != 0) {
				while (True) {
					wOperands [1] = RandomInteger (2, RandomChance () ? (wOperands[0] - 1) : wOperands[0]);
					if (compute (wOperands[0], wOperands[1], '%') == 0) break;
				}
			}
		}
	}

	/* change signs of the operands randomly */
	wOperands[0] = RandomChance() ? wOperands[0] * -1: wOperands[0];
	wOperands[1] = RandomChance() ? wOperands[1] * -1: wOperands[1];

	wResult = compute (wOperands[0], wOperands[1], cOperations[0]);

	if (sNumOfOperands == 3) {
		/* change signs of the operands randomly */
		wOperands[2] = RandomChance() ? wOperands[2] * -1: wOperands[2];

		if (RandomChance ()) {
			wResult = compute (wResult, wOperands[2], cOperations[1]);
		} else {
			isFlip = True;
			wResult = compute (wOperands[2], wResult, cOperations[1]);
		}
	}

	MoveCursor (2, 2);

	if (sNumOfOperands == 2) {
		printf ("%d %c %d = ",  wOperands[0], cOperations[0], wOperands[1]);
	} else {
		if (isFlip) {
			printf ("%d %c %d %c %d = ", wOperands[2], cOperations[1], wOperands[0], cOperations[0], wOperands[1]);
		} else {
			printf ("%d %c %d %c %d = ", wOperands[0], cOperations[0], wOperands[1], cOperations[1], wOperands[2]);
		}
	}

	/* prompts user for answer */
	scanf ("%d", &wAnswer);

	/* check's user's answer */
	if (wAnswer == wResult) {
		drawCorrect (5, 11);
		Pause (900);
	} else {
		isCorrect = -1; /* subtracts 1 point if incorrect */
		drawWrong (5, 11);
		Pause (900);
	}

	return isCorrect;
}

/**
 * Function name : compute ()
 * Date Created  : 7 December 2012
 * Definition    : This function computes mathematical expression
 *                 with specified two operands and operator
 */
int compute (int wOperand1, int wOperand2, const char cOperator) {
	int wResult = 0;

	switch (cOperator) {
		case '+': wResult = wOperand1 + wOperand2; break;
		case '-': wResult = wOperand1 - wOperand2; break;
		case '*': wResult = wOperand1 * wOperand2; break;
		case '/': wResult = wOperand1 / wOperand2; break;
		case '%': wResult = wOperand1 % wOperand2; break;
	}

	return wResult;
}

/**
 * Function name : drawNumber ()
 * Date Created  : 7 December 2012
 * Definition    : This function allows user to specify a number
 *                 to draw and functions outputs a graphical
 *                 symbol of the number
 */
void drawNumber (int number, int x, int y) {
	switch (number) {
		case 0: drawZero (x, y);  break;
		case 1: drawOne (x, y);   break;
		case 2: drawTwo (x, y);   break;
		case 3: drawThree (x, y); break; 
		case 4: drawFour (x, y);  break;
		case 5: drawFive (x, y);  break;
		case 6: drawSix (x, y);   break;
		case 7: drawSeven (x, y); break;
		case 8: drawEight (x, y); break;
		case 9: drawNine (x, y);  break;
	}
}

/**
 * Function name : drawOperator ()
 * Date Created  : 7 December 2012
 * Definition    : This function allows user to specify an operator
 *                 to draw and functions outputs a graphical
 *                 symbol of the operator
 */
void drawOperator (char sign, int x, int y) {
	switch (sign) {
		case '+': drawPlusSign (x, y);     break;
		case '-': drawMinusSign (x, y);    break;
		case '*': drawMultiplySign (x, y); break;
		case '/': drawDivisionSign (x, y); break;
		case '=': drawEqualSign (x, y);    break;
	}
}

/**
 * Function name : drawEqualSign ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws equal sign at specified
 *                 x, y position on screen
 */
void drawEqualSign (int x, int y) {
	MoveCursor (x, y);
	printf ("   ");
	MoveCursor (x, y + 1);
	printf (" = ");
	MoveCursor (x, y + 2);
	printf ("   ");
}

/**
 * Function name : drawMultiplySign ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws multiply sign at specified
 *                 x, y position on screen
 */
void drawMultiplySign (int x, int y) {
	MoveCursor (x, y);
	printf ("   ");
	MoveCursor (x, y + 1);
	printf (" * ");
	MoveCursor (x, y + 2);
	printf ("   ");
}

/**
 * Function name : drawPlusSign ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws plus sign at specified
 *                 x, y position on screen
 */
void drawPlusSign (int x, int y) {
	MoveCursor (x, y);
	printf ("   ");
	MoveCursor (x, y + 1);
	printf (" + ");
	MoveCursor (x, y + 2);
	printf ("   ");
}

/**
 * Function name : drawMinusSign ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws minus sign at specified
 *                 x, y position on screen
 */
void drawMinusSign (int x, int y) {
	MoveCursor (x, y);
	printf ("   ");
	MoveCursor (x, y + 1);
	printf (" - ");
	MoveCursor (x, y + 2);
	printf ("   ");
}
	
/**
 * Function name : drawDivisionSign ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws division sign at specified
 *                 x, y position on screen
 */
void drawDivisionSign (int x, int y) {
	MoveCursor (x, y);
	printf ("   ");
	MoveCursor (x, y + 1);
	printf (" / ");
	MoveCursor (x, y + 2);
	printf ("   ");
}

/**
 * Function name : drawZero ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws zero digit at specified
 *                 x, y position on screen
 */
void drawZero (int x, int y) {
	MoveCursor (x, y);
	printf (" 8888 ");
	MoveCursor (x, y + 1);
	printf ("88  88");
	MoveCursor (x, y + 2);
	printf ("88  88");
	MoveCursor (x, y + 3);
	printf ("88  88");
	MoveCursor (x, y + 4);
	printf (" 8888 ");
}

/**
 * Function name : drawOne ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws one digit at specified
 *                 x, y position on screen
 */
void drawOne (int x, int y) {
	MoveCursor (x, y);
	printf ("   88 ");
	MoveCursor (x, y + 1);
	printf (" 8888 ");
	MoveCursor (x, y + 2);
	printf ("   88 ");
	MoveCursor (x, y + 3);
	printf ("   88 ");
	MoveCursor (x, y + 4);
	printf ("   88 ");
}

/**
 * Function name : drawtwo ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws two digit at specified
 *                 x, y position on screen
 */
void drawTwo (int x, int y) {
	MoveCursor (x, y);
	printf (" 8888 ");
	MoveCursor (x, y + 1);
	printf ("88  88");
	MoveCursor (x, y + 2);
	printf ("   88 ");
	MoveCursor (x, y + 3);
	printf (" 88   ");
	MoveCursor (x, y + 4);
	printf ("888888");
}

/**
 * Function name : drawThree ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws three digit at specified
 *                 x, y position on screen
 */
void drawThree (int x, int y) {
	MoveCursor (x, y);
	printf (" 8888 ");
	MoveCursor (x, y + 1);
	printf ("88  88");
	MoveCursor (x, y + 2);
	printf ("   88 ");
	MoveCursor (x, y + 3);
	printf ("88  88");
	MoveCursor (x, y + 4);
	printf (" 8888 ");
}

/**
 * Function name : drawFour ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws four digit at specified
 *                 x, y position on screen
 */
void drawFour (int x, int y) {
	MoveCursor (x, y);
	printf ("88  88");
	MoveCursor (x, y + 1);
	printf ("88  88");
	MoveCursor (x, y + 2);
	printf ("888888");
	MoveCursor (x, y + 3);
	printf ("    88");
	MoveCursor (x, y + 4);
	printf ("    88");
}

/**
 * Function name : drawFive ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws five digit at specified
 *                 x, y position on screen
 */
void drawFive (int x, int y) {
	MoveCursor (x, y);
	printf ("888888");
	MoveCursor (x, y + 1);
	printf ("88    ");
	MoveCursor (x, y + 2);
	printf ("88888 ");
	MoveCursor (x, y + 3);
	printf ("    88");
	MoveCursor (x, y + 4);
	printf ("88888 ");
}

/**
 * Function name : drawSix ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws six digit at specified
 *                 x, y position on screen
 */
void drawSix (int x, int y) {
	MoveCursor (x, y);
	printf (" 8888 ");
	MoveCursor (x, y + 1);
	printf ("88    ");
	MoveCursor (x, y + 2);
	printf ("88888 ");
	MoveCursor (x, y + 3);
	printf ("88  88");
	MoveCursor (x, y + 4);
	printf (" 8888 ");
}

/**
 * Function name : drawSeven ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws seven digit at specified
 *                 x, y position on screen
 */
void drawSeven (int x, int y) {
	MoveCursor (x, y);
	printf ("888888");
	MoveCursor (x, y + 1);
	printf ("   88 ");
	MoveCursor (x, y + 2);
	printf ("  88  ");
	MoveCursor (x, y + 3);
	printf (" 88   ");
	MoveCursor (x, y + 4);
	printf ("88    ");
}

/**
 * Function name : drawEight ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws eight digit at specified
 *                 x, y position on screen
 */
void drawEight (int x, int y) {
	MoveCursor (x, y);
	printf (" 8888 ");
	MoveCursor (x, y + 1);
	printf ("88  88");
	MoveCursor (x, y + 2);
	printf (" 8888 ");
	MoveCursor (x, y + 3);
	printf ("88  88");
	MoveCursor (x, y + 4);
	printf (" 8888 ");
}

/**
 * Function name : drawNine ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws nine digit at specified
 *                 x, y position on screen
 */
void drawNine (int x, int y) {
	MoveCursor (x, y);
	printf (" 8888 ");
	MoveCursor (x, y + 1);
	printf ("88  88");
	MoveCursor (x, y + 2);
	printf (" 88888");
	MoveCursor (x, y + 3);
	printf ("    88");
	MoveCursor (x, y + 4);
	printf (" 8888 ");
}

/**
 * Function name : drawCorrect ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws correct sign at specified
 *                 x, y position on screen
 */
void drawCorrect (int x, int y) {
	MoveCursor (x, y);
	printf("          ***");
	MoveCursor (x, y + 1);
	printf("         ***");
	MoveCursor (x, y + 2);
	printf("        ***");
	MoveCursor (x, y + 3);
	printf("       ***");
	MoveCursor (x, y + 4);
	printf("***   ***");
	MoveCursor (x, y + 5);
	printf(" *******");
	MoveCursor (x, y + 6);
	printf("  *****");
}

/**
 * Function name : drawWrong ()
 * Date Created  : 7 December 2012
 * Definition    : This function draws wrong sign at specified
 *                 x, y position on screen
 */
void drawWrong (int x, int y) {
	MoveCursor (x, y);
	printf("***       ***");
	MoveCursor (x, y + 1);
	printf(" ***     ***");
	MoveCursor (x, y + 2);
	printf("  ***   ***");
	MoveCursor (x, y + 3);
	printf("    *****");
	MoveCursor (x, y + 4);
	printf("  ***   ***");
	MoveCursor (x, y + 5);
	printf(" ***     ***");
	MoveCursor (x, y + 6);
	printf("***       ***");
}

/**
 * Function name : viewHelp ()
 * Date Created  : 7 December 2012
 * Definition    : This function provides help/hint for user
 */
void viewHelp (Level difficulty) {
	DrawBorder (15, 0, 63, 21);
	switch (difficulty) {
		case EASY:         easyHelp (16, 1);         break;
		case FAIR:         fairHelp (16, 1);         break;
		case INTERMEDIATE: intermediateHelp (16, 1); break;
		case HARD:         hardHelp (16, 1);         break;
		case IMPOSSIBLE:   impossibleHelp (16, 1);   break;
	}
	getch ();
}

/**
 * Function name : easyHelp ()
 * Date Created  : 7 December 2012
 * Definition    : This function prints hint about easy level
 */
void easyHelp (int x, int y) {
	MoveCursor (x, y);
	printf ("EASY LEVEL: ");
	MoveCursor (x, y + 1);
	printf ("Includes addition and subtraction problems,    ");
	MoveCursor (x, y + 2);
	printf ("with positive single digit operands and up to  ");
	MoveCursor (x, y + 3);
	printf ("three terms only.");
	MoveCursor (x, y + 4);
	printf ("                                               ");

	MoveCursor (x, y + 5);
	printf ("Example:");
	MoveCursor (x, y + 6);
	printf ("  3 + 2 = 5");
	MoveCursor (x, y + 8);
	printf ("  3 - 2 = 1");
	MoveCursor (x, y + 10);
	printf ("  2 - 3 = -1");
	MoveCursor (x, y + 12);
	printf ("  3 + 2 + 1 = 6");
	MoveCursor (x, y + 13);
	printf ("   >> 3 + 2 = (5) >> (5) + 1 = 6");
	MoveCursor (x, y + 15);
	printf ("  3 - 2 + 1 = 2");
	MoveCursor (x, y + 16);
	printf ("   >> 3 - 2 = (1) >> (1) + 1 = 2");
	MoveCursor (x, y + 19);
	printf ("          Press <ENTER> to continue");
}

/**
 * Function name : fairHelp ()
 * Date Created  : 7 December 2012
 * Definition    : This function prints hint about fair level
 */
void fairHelp (int x, int y) {
	MoveCursor (x, y);
	printf ("FAIR LEVEL: ");
	MoveCursor (x, y + 1);
	printf ("Includes multiplication problems, with positive");
	MoveCursor (x, y + 2);
	printf ("single digits operands and up to two terms only");
	MoveCursor (x, y + 3);
	printf ("                                               ");

	MoveCursor (x, y + 4);
	printf ("Example:");
	MoveCursor (x, y + 5);
	printf ("  3 * 2 = 6");
	MoveCursor (x, y + 7);
	printf ("  4 * 1 = 4");
	MoveCursor (x, y + 9);
	printf ("  7 * 0 = 0");

	MoveCursor (x, y + 19);
	printf ("          Press <ENTER> to continue");
}

/**
 * Function name : intermediateHelp ()
 * Date Created  : 7 December 2012
 * Definition    : This function prints hint about intermediate level
 */
void intermediateHelp (int x, int y) {
	MoveCursor (x, y);
	printf ("INTERMEDIATE LEVEL: ");
	MoveCursor (x, y + 1);
	printf ("Includes division problems, with positive      ");
	MoveCursor (x, y + 2);
	printf ("single digits operands and up to two terms only");
	MoveCursor (x, y + 3);
	printf ("NOTE: Results should be shown in the form ");
	MoveCursor (x, y + 4);
	printf ("          < Number R Remainder > ");
	MoveCursor (x, y + 5);
	printf ("                                               ");

	MoveCursor (x, y + 6);
	printf ("Example:");
	MoveCursor (x, y + 7);
	printf ("  3 / 1 = 3");
	MoveCursor (x, y + 9);
	printf ("  0 / 2 = 0");
	MoveCursor (x, y + 11);
	printf ("  4 / 2 = 2");
	MoveCursor (x, y + 13);
	printf ("  7 / 3 = 2R1");

	MoveCursor (x, y + 19);
	printf ("          Press <ENTER> to continue");
}

/**
 * Function name : hardHelp ()
 * Date Created  : 7 December 2012
 * Definition    : This function prints hint about hard level
 */
void hardHelp (int x, int y) {
	MoveCursor (x, y);
	printf ("HARD LEVEL: ");
	MoveCursor (x, y + 1);
	printf ("Includes a mix of addition, subtraction,       ");
	MoveCursor (x, y + 2);
	printf ("multiplication, and division problems, with    ");
	MoveCursor (x, y + 3);
	printf ("positive and negative single digit operands and");
	MoveCursor (x, y + 4);
	printf ("up to three terms only");

	MoveCursor (x, y + 6);
	printf ("Example:");
	MoveCursor (x, y + 7);
	printf ("  3 + 2 * -7 = -11");
	MoveCursor (x, y + 8);
	printf ("   >> 2 * -7 = (-14) >> 3 + (-14) = -11");
	MoveCursor (x, y + 10);
	printf ("  10 - 3 * 3 = 1");
	MoveCursor (x, y + 11);
	printf ("   >> 3 * 3 = (9) >> 10 - (9) = 1");
	MoveCursor (x, y + 13);
	printf ("  10 - 4 / 2 = 8");
	MoveCursor (x, y + 14);
	printf ("   >> 4 / 2 = (2) >> 10 - (2) = 8");

	MoveCursor (x, y + 19);
	printf ("          Press <ENTER> to continue");
}

/**
 * Function name : impossibleHelp ()
 * Date Created  : 7 December 2012
 * Definition    : This function prints hint about impossible level
 */
void impossibleHelp (int x, int y) {
	MoveCursor (x, y);
	printf ("IMPOSSIBLE LEVEL: ");
	MoveCursor (x, y + 1);
	printf ("Includes a mix of addition, subtraction,       ");
	MoveCursor (x, y + 2);
	printf ("multiplication, and division problems, with    ");
	MoveCursor (x, y + 3);
	printf ("positive and negative two and three digit      ");
	MoveCursor (x, y + 4);
	printf ("operands and up to three terms only");

	MoveCursor (x, y + 6);
	printf ("Example:");
	MoveCursor (x, y + 7);
	printf ("  10 + 11 * 23 = 263");
	MoveCursor (x, y + 8);
	printf ("   >> 11 * 23 = (253) >> 10 + (253) = 263");
	MoveCursor (x, y + 10);
	printf ("  78 - 32 * 29 = -850");
	MoveCursor (x, y + 11);
	printf ("   >> 32 * 29 = (928) >> 78 - (928) = -850");
	MoveCursor (x, y + 13);
	printf ("  42 / -21 - 823 = -825");
	MoveCursor (x, y + 14);
	printf ("   >> 42 / -21 = (-2) >> (-2) - 823 = -825");

	MoveCursor (x, y + 19);
	printf ("          Press <ENTER> to continue");
}

/**
 * Function name : learnToUseProgram ()
 * Date Created  : 7 December 2012
 * Definition    : This function prints hint on the different levels
 *                 of the program
 */
void learnToUseProgram (void) {
	int x = 16, y = 1;

	DrawBorder (15, 0, 63, 21);
	MoveCursor (x, y);
	printf ("Mathematics is one of the most important, yet  ");
	MoveCursor (x, y + 1);
	printf ("most difficult, subjects to teach and learn. We");
	MoveCursor (x, y + 2);
	printf ("have all heard of the saying \"Practice makes  ");
	MoveCursor (x, y + 3);
	printf ("perfect\".");
	MoveCursor (x, y + 19);
	printf ("          Press <ENTER> to continue");	
	getch ();
	DrawBorder (15, 0, 63, 21);
	easyHelp (16, 1);
	getch ();
	DrawBorder (15, 0, 63, 21);
	fairHelp (16, 1);     
	getch ();
	DrawBorder (15, 0, 63, 21);
	intermediateHelp (16, 1);
	getch ();
	DrawBorder (15, 0, 63, 21);
	hardHelp (16, 1); 
	getch ();
	DrawBorder (15, 0, 63, 21);
	impossibleHelp (16, 1);  
	getch ();
}

/**
 * Function name : generateDataFile ()
 * Date Created  : 7 December 2012
 * Definition    : This function saves all users data on a file
 */
void generateDataFile (FILE *stream, char *cInitials, int wTotalPoints) {
	fprintf (stream, "| %4s | %12d |\n", cInitials, wTotalPoints);
	fprintf (stream, "-----------------------\n");
}

/**
 * Function name : messageBox ()
 * Date Created  : 7 December 2012
 * Definition    : This function allows programmer to output messagebox
 */
char messageBox (char *message, int x, int y, int length, int width, Boolean optYesNo) {
	char ch = '\0';

	DrawBorder (x, y, x + length, y + width);
	printf ("%s", message);
	if (optYesNo == True) {
		MoveCursor (length/2 + x - 6, y + width - 1);
		printf ("[Y / N]: ");
		ch = getch ();
	}

	if (toupper(ch) == 'Y' || toupper(ch) == 'N') 
		return ch;
	else 
		return messageBox (message, x, y, length, width, optYesNo);
}













