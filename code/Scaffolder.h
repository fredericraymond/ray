/*
 	Ray
    Copyright (C) 2011  Sébastien Boisvert

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

#ifndef _Scaffolder
#define _Scaffolder

#include <Parameters.h>
#include <StaticVector.h>
#include <vector>
#include <RingAllocator.h>
#include <constants.h>
#include <VirtualCommunicator.h>
#include <ReadFetcher.h>
using namespace std;

/**
 * Scaffolder class, it uses MPI through the virtual communicator.
 *
 * \author Sébastien Boisvert
 */
class Scaffolder{
	// these are mostly flags for sends/receives
	bool m_forwardDirectionLengthRequested;
	bool m_forwardDirectionLengthReceived;
	int m_pairedForwardDirectionLength;
	bool m_forwardDirectionsRequested;
	bool m_forwardDirectionsReceived;
	int m_pairedForwardMarkerCoverage;
	bool m_pairedForwardHasDirection;
	uint64_t m_pairedForwardDirectionName;
	int m_pairedForwardDirectionPosition;
	bool m_reverseDirectionsRequested;
	int m_readLength;
	bool m_markersRequested;
	bool m_markersReceived;
	int m_pairedForwardOffset;
	int m_pairedReverseOffset;
	VERTEX_TYPE m_pairedForwardMarker;
	VERTEX_TYPE m_pairedReverseMarker;
	bool m_pairReceived;
	int m_pairedReadRank;
	int m_pairedReadIndex;
	int m_pairedReadLibrary;
	int m_pairedReadLength;
	bool m_pairRequested;
	bool m_hasPairReceived;
	bool m_hasPairRequested;
	bool m_hasPair;
	bool m_initialisedFetcher;
	int m_readAnnotationId;
	ReadFetcher m_readFetcher;
	vector<uint64_t> m_activeWorkers;
	uint64_t m_workerId;
	VirtualCommunicator*m_virtualCommunicator;
	bool m_coverageRequested;
	bool m_coverageReceived;
	int m_receivedCoverage;

	bool m_reverseDone;
	bool m_forwardDone;
	int m_contigId;
	int m_positionOnContig;
	vector<vector<VERTEX_TYPE> > m_contigs;
	vector<uint64_t> m_contigNames;

	Parameters*m_parameters;
	StaticVector*m_inbox;
	StaticVector*m_outbox;
	RingAllocator*m_outboxAllocator;
	bool m_initialised;
	int*m_slave_mode;
	bool m_ready;

	void processContig();
	void processContigPosition();
	void processVertex(VERTEX_TYPE vertex);
	void processAnnotations();
	void processAnnotation();
	
public:
	/**
 *	Number of ranks that have finished scaffolding
 */
	int m_numberOfRanksFinished;

	/**
 *	Constructor of the scaffolder
 */
	void constructor(StaticVector*outbox,StaticVector*inbox,RingAllocator*outboxAllocator,Parameters*parameters,
		int*slaveMode,VirtualCommunicator*vc);
	void run();
	void addContig(uint64_t name,vector<uint64_t>*vertices);
};

#endif

