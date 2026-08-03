/*******************************************************************
* CS 214-01 Programming Assignment Relations
* File: RelationInputMain.cpp
* Author: Noah Borden
* Desc: This program takes 4 sets S with relations R of ordered 
		pairs and determines if the relations are reflexive, 
		irreflexive, symmetric, asymmetric, antisymmetric, and/or
		transitive. The program also finds if the relation is an
		equivalence or partial-order relation. If the relation isn't
		reflexive, symmetric, and/or transitive, the program will
		find the respective closures.
* Date: 11/22/25
*
* I attest that this program is entirely my own work
*******************************************************************/

//===================================================================================
// CS214 Relation Inputs Parser C++
// File: RelationInputMain.cpp
//
// Author: Mr. Kevin Preston
// Date:  25-Sep-2021
//===================================================================================
//
// This is the main program that handles the:
//     - Read the input .xml file and build the object that is the boolean matrix of the relation.
//     - Print the information of the relation. 
// If there is ever a problem reading the input file change the input file so Parser can handle it. This is 
// based on Dr. Coleman's code for CS307 and CS499 project assignments. 
//
// The main and the RelationInputParser class are provided to the CS214 students. This was necessary 
// because this was more difficult for the students to parse the input files than to write the Relation
// checking code.  
//
// This zip file should contain this file, the RelationInputParser class and the four input files that contain the
// relations. 
//
// Command line to build on the Raspberry Pi 4 
// c++ -Wall -o main RelationInputMain.cpp RelationInputParser.cpp
//

#include <iostream>
#include <string>
#include <vector>
#include "RelationInputParser.h"

using namespace std;
#define MAX_RELATIONS 4 // Range is 0 to MAX_RELATIONS

const char  *inputfilename[MAX_RELATIONS]; // This is the array that contains all the input relation filenames. 

int    relationsize;    // The order of the set S i.e., |S|.
string relationelement; // The elements of the set S. Need to make them strings. 
bool   rvalue;          // The boolean value returned by accessing the matrix of the relation. 

int main() {
	// Initialize the array with the files that contain all the relations to check. 
	inputfilename[0] = "Relation01.xml";
	inputfilename[1] = "Relation02.xml";
	inputfilename[2] = "Relation03.xml";
	inputfilename[3] = "Relation04.xml";
	
	// Loop through all the files. 

	for (int k = 0; k < MAX_RELATIONS; k++) {
		printf("\n*********************************************************\n");
		printf("*********************************************************\n");
		printf("\nThe input Relation File is: %s\n", inputfilename[k]);
		RelationInputParser *lsdp = RelationInputParser::getInstance();	// Get the singleton
		lsdp->initDataParser(inputfilename[k]);

		// Print size of the relation
		printf("Set size is: %d\n \n", lsdp->getRelationSize());

		// Print the relation elements. 
		printf("The set S contains: \n  {");
		for (int i = 0; i < relationsize - 1; i++)
			printf("%s, ", lsdp->getElement(i).c_str());
		printf("%s} \n\n", lsdp->getElement(relationsize - 1).c_str());

		// Print the Boolean matrix of the relation
		printf("\n The Boolean Matrix of the relation R is: \n\n");

		for (int i = 0; i < relationsize; i++) {
			for (int j = 0; j < relationsize; j++)
				printf(" %x ", lsdp->getRelationElement(i, j));
			printf("\n");
		}

		// Print the ordered pairs of the relation. Not a perfect printing (extra ,) but close enough. 
		printf("\nThe ordered pairs of the relation R: \n");
		printf("{");
		bool first = true;
		for (int i = 0; i < relationsize; i++) {
			for (int j = 0; j < relationsize; j++) {
				if (lsdp->getRelationElement(i, j)) {
					printf("%s(%s, %s)", !first ? ", " : " ", lsdp->getElement(i).c_str(), lsdp->getElement(j).c_str());
					first = false;
				}
			}
		}
		printf(" } \n");

		printf("\nThe properties of the Relation R is as follows: \n\n");

		bool isReflexive = true, isIrreflexive = true, isSymmetric = true, isAsymmetric = true, 
			 isAntisymmetric = true, isTransitive = true;

		for (int i = 0; i < relationsize; i++) {
			// Check for reflexivity -- (i, i) exists
			if (isReflexive)
    			if (!lsdp->getRelationElement(i, i))
        			isReflexive = false;
			// Check for irreflexivity -- (i, i) does not exist
			if (isIrreflexive)
    			if (lsdp->getRelationElement(i, i))
					isIrreflexive = false;
		    for (int j = 0; j < relationsize; j++) {
				// Check for symmetry -- If (i, j) exists, then (j, i) exists
				if (isSymmetric)
					if (lsdp->getRelationElement(i, j) && !lsdp->getRelationElement(j, i))
						isSymmetric = false;
				// Check for asymmetry -- If (i, j) exists, then (j, i) does not exist
				if (isAsymmetric)
					if (lsdp->getRelationElement(i, j) && lsdp->getRelationElement(j, i))
						isAsymmetric = false;
				// Check for antisymmetry -- If (i, j) and (j, i) exists, then i = j
				if (isAntisymmetric)
					if (lsdp->getRelationElement(i, j) && lsdp->getRelationElement(j, i) && (i != j))
						isAntisymmetric = false;
				// Check for transivity -- If (i, j) and (j, k) exists, then (i, k) exists
				if (isTransitive)
					for (int k = 0; k < relationsize; k++)
						if (lsdp->getRelationElement(i, j) && lsdp->getRelationElement(j, k) && !lsdp->getRelationElement(i, k))
							isTransitive = false;
		    }
		}

		bool isPO = isReflexive && isAntisymmetric && isTransitive, isER = isReflexive && isSymmetric && isTransitive;

		printf("      Reflexive                %s\n", isReflexive ? "YES" : "NO");
		printf("      Irreflexive              %s\n", isIrreflexive ? "YES" : "NO");
		printf("      Symmetric                %s\n", isSymmetric ? "YES" : "NO");
		printf("      Asymmetric               %s\n", isAsymmetric ? "YES" : "NO");
		printf("      Antisymmetric            %s\n", isAntisymmetric ? "YES" : "NO");
		printf("      Transitive               %s\n", isTransitive ? "YES" : "NO");
		printf("      Partial Ordering         %s\n", isPO ? "YES" : "NO");
		printf("      Equivalence Relation     %s\n", isER ? "YES" : "NO");

		if (!isReflexive) {
			printf("\nThe reflexive closure set for R is:\n{");
			bool first = true;
			for (int i = 0; i < relationsize; i++) {
				// Print (i, i) if it does not exist
				if (!lsdp->getRelationElement(i, i)) {
					printf("%s(%s, %s)", !first ? ", " : " ", lsdp->getElement(i).c_str(), lsdp->getElement(i).c_str());
					first = false;
				}
			}
			printf(" }");
		}

		if (!isSymmetric) {
			printf("\nThe symmetric closure set for R is:\n{");
			bool first = true;
			for (int i = 0; i < relationsize; i++)
				for (int j = 0; j < relationsize; j++) {
					// Print (j, i) if (i, j) exists
					if (lsdp->getRelationElement(i, j) && !lsdp->getRelationElement(j, i)) {
						printf("%s(%s, %s)", !first ? ", " : " ", lsdp->getElement(j).c_str(), lsdp->getElement(i).c_str());
						first = false;
					}
				}
			printf(" }");
		}

		if (!isTransitive) {
    		printf("\nThe transitive closure set for R is:\n{");
    
    		// 1. Copy the relation matrix into a 2D boolean vector
    		vector<vector<bool>> closure(relationsize, vector<bool>(relationsize, false));
    		for (int i = 0; i < relationsize; i++)
        		for (int j = 0; j < relationsize; j++)
            		closure[i][j] = lsdp->getRelationElement(i, j);

    		// 2. Warshall's Algorithm -- Add a new (i, k) to the vector if (i, j) and (j, k) exists
    		for (int j = 0; j < relationsize; j++)
        		for (int i = 0; i < relationsize; i++)
            		for (int k = 0; k < relationsize; k++) {
                		if (closure[i][j] && closure[j][k])
                    		closure[i][k] = true;
            		}

    		// 3. Print only the newly added pairs
    		bool first = true;
    		for (int i = 0; i < relationsize; i++)
    		    for (int k = 0; k < relationsize; k++) {
    		        // Check if (i, k) is not in the original relation
    		        if (closure[i][k] && !lsdp->getRelationElement(i, k)) {
    		            printf("%s(%s, %s)", !first ? ", " : " ", lsdp->getElement(i).c_str(), lsdp->getElement(k).c_str());
    		            first = false;
    		        }
    		    }
    		printf(" }\n");
		}
		printf("\n");

	} // end for k loop for the input data files.
} // end main