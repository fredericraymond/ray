/*
Ray
Copyright (C)  2010, 2011  Sébastien Boisvert

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

#ifndef _common_functions
#define _common_functions

#include <Kmer.h>
#include <string>
#include <constants.h>
#include <slave_modes.h>
#include <master_modes.h>
#include <vector>
#include <mpi_tags.h>
using namespace std;


#if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
#define OS_WIN
#else
#define OS_POSIX
#endif

#define __max(a,b) (((a)>(b)) ? (a) : (b))

/*
 *  complement the sequence of a biological thing
 */
string reverseComplement(string a,char*rev);

/*
 * convert a char* to uint64_t
 * A=00, T=01, C=10, G=11
 */
Kmer wordId(const char*a);
Kmer wordId_Classic(const char*a);

/*
 * convert a 64-bit integer to a string
 */
string idToWord(const Kmer*i,int wordSize);

/*
 * verify that x has only A,T,C, and G
 */
bool isValidDNA(const char*x);

/*
 * get the first letter of a uint64_t
 */
char getFirstSymbol(Kmer i,int k);

/*
 * get the last letter of a uint64_t
 */
char getLastSymbol(Kmer*i,int w);

/*
 * output in stdout the binary view of a 64-bit integer.
 */
void coutBIN(uint64_t a);
void coutBIN8(uint8_t a);

/*
 * get the prefix
 */
uint64_t getKPrefix(uint64_t a,int k);

/*
 * get the suffix
 */
uint64_t getKSuffix(uint64_t a,int k);

/*
 * complement a vertex, and return another one
 */
Kmer complementVertex(Kmer*a,int m_wordSize,bool useColorSpace);

/*
 * add line breaks to a string
 */
string addLineBreaks(string sequence,int a);

void*__Malloc(int c,int mallocType);
void __Free(void*a,int mallocType);

/*
 * compute the reverse complement in color space (it is just the same, but reverse)
 */

Kmer complementVertex_colorSpace(Kmer*a,int b);

/*
 * complement vertex, normal.
 */
Kmer complementVertex_normal(Kmer*a,int m_wordSize);

/*
 * use mini distant segments here.
 */
uint64_t wordId_DistantSegments(const char*a);

uint8_t getFirstSegmentFirstCode(Kmer*v,int segmentLength,int totalLength);
uint8_t getSecondSegmentLastCode(Kmer*v,int segmentLength,int totalLength);

uint8_t charToCode(char a);

char codeToChar(uint8_t a);

string convertToString(vector<Kmer>*b,int m_wordSize);

int vertexRank(Kmer*a,int _size,int w);

Kmer kmerAtPosition(const char*string,int pos,int w,char strand,bool color);

int roundNumber(int number,int alignment);

uint64_t getMilliSeconds();

void showMemoryUsage(int rank);

vector<Kmer> _getOutgoingEdges(Kmer*a,uint8_t edges,int k);
vector<Kmer> _getIngoingEdges(Kmer*a,uint8_t edges,int k);

char complementNucleotide(char c);

uint64_t hash_function_1(Kmer*a,int w);
uint64_t hash_function_2(Kmer*a,int w,Kmer*b);

uint8_t invertEdges(uint8_t a);

uint64_t getPathUniqueId(int rank,int id);
int getIdFromPathUniqueId(uint64_t a);
int getRankFromPathUniqueId(uint64_t a);

void now();

string reverseComplement(string*a);

#endif


