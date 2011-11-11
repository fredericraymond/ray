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

#include <routing/GraphImplementationRandom.h>
#include <math.h> /* for log */
#include <algorithm> /* random_shuffle */

void GraphImplementationRandom::makeConnections(int n){
	m_size=n;

	for(int i=0;i<m_size;i++){
		set<Rank> b;
		m_connections.push_back(b);
	}

	// add self edges
	for(int i=0;i<m_size;i++){
		m_connections[i].insert(i);
	}

	// create a set of all edges
	vector<vector<Rank> > edges;
	vector<int> identifiers;
	int k=0;
	for(Rank i=0;i<m_size;i++){
		for(Rank j=0;j<m_size;j++){
			// don't generate a pair for (i,i)
			if(i==j)
				continue;
		
			// don't generate a pair for (i,j) if i<j because
			// (j,i) will be processed anyway
			if(i<j)
				continue;

			vector<Rank> pair;
			pair.push_back(i);
			pair.push_back(j);
			edges.push_back(pair);

			identifiers.push_back(k);

			k++;
		}
	}

	// shuffle the edges
	// we shuffle a lot
	for(int i=0;i<32;i++){
		srand(i*i*i+2*i);
		std::random_shuffle(identifiers.begin(),identifiers.end());
	}

	// add the edges
	int connectionsPerVertex=log(m_size)/log(2);
	int numberOfEdgesToAdd=m_size*connectionsPerVertex/2;

	// the first numberOfEdgesToAdd edges
	for(int i=0;i<numberOfEdgesToAdd;i++){
		int identifier=identifiers[i];
		Rank source=edges[identifier][0];
		Rank destination=edges[identifier][1];

		// add the edge in both directions
		m_connections[source].insert(destination);
		m_connections[destination].insert(source);
	}
}
