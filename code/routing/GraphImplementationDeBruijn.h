/*
 	Ray
    Copyright (C) 2010, 2011  Sébastien Boisvert

	http://DeNovoAssembler.SourceForge.Net/

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 3 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You have received a copy of the GNU General Public License
    along with this program (COPYING).  
	see <http://www.gnu.org/licenses/>

*/

#ifndef _GraphImplementationDeBruijn_h
#define _GraphImplementationDeBruijn_h

#include <routing/GraphImplementation.h>
#include <vector>
#include <stdint.h>
using namespace std;

class DeBruijnVertex{
public:
	uint8_t m_digits[16];
};

/**
 * de Bruijn graph
 * n must be a power of something
 */
class GraphImplementationDeBruijn : public GraphImplementation{

	int m_base;

	int m_digits;

	int getPower(int base,int exponent);

/** convert a number to a de Bruijn vertex */
	void convertToDeBruijn(int i,DeBruijnVertex*tuple);

/** get the children of a de Bruijn vertex */
	void getChildren(DeBruijnVertex*vertex,vector<DeBruijnVertex>*children);
	void getParents(DeBruijnVertex*vertex,vector<DeBruijnVertex>*children);

/** convert a de Bruijn vertex to base 10 */
	int convertToBase10(DeBruijnVertex*vertex);

	void printVertex(DeBruijnVertex*a);
	bool isAPowerOf(int n,int base);

	int getMaximumOverlap(DeBruijnVertex*a,DeBruijnVertex*b);

protected:

	void computeRoute(Rank a,Rank b,vector<Rank>*route);
	Rank getNextRankInRoute(Rank source,Rank destination,Rank rank);
	bool isConnected(Rank source,Rank destination);
public:

	void makeConnections(int n);
	void makeRoutes();
};

#endif