#ifndef GTFPARSER_H
#define GTFPARSER_H

#include "ResultParser.h"

class MappedPeptides;

class GTFParser {
public:
	~GTFParser(void);

	//singleton get_instance method.
	static GTFParser* get_instance();
	//reads a gtf file and parses it into CoordinateWrapper and MappedPeptides.
	assembly read(const std::string& file, CoordinateWrapper& coordwrapper, MappedPeptides& mapping);
private:
	//inputstream
	std::ifstream m_ifstream;
	//current line
	std::string m_line;
	//meyers singleton instance.
	static GTFParser* m_instance;
	//ctr andoverwritten methods for singleton.
	GTFParser();
	GTFParser(GTFParser const&);
	GTFParser& operator =(GTFParser const&);
	//end ctr.

	//opens filestream, returns true if sucessful
	bool open(std::string file);
	//closes the filestream
	void close();

	void protein_exons_combine(Coordinates & protein_coordinates, Coordinates & prev_proteint_coordinates, GenomeCoordinates & genCoord, CoordinateMapType & coordinates_map);
	void protein_exons_combine(CoordinateMapType & coordinates_map, std::list<GenomeCoordinates> & CDS_coords);

	//returns true if in the GTF at position 6 there is a + (plus strand)
	bool static is_first_strand(std::vector<std::string> const& tokens);
	//returns true if the token string is a + (plus strand)
	bool static is_first_strand(std::string const& token);
	//returns true if strand is fwd or 1
	bool static is_first_strand(Strand const& token);
	//returns true if position 2 in the GTF says "CDS"
	bool static is_cds(std::vector<std::string> const& tokens);
	//returns true if position 2 in the GTF says "exon"
	bool static is_exon(std::vector<std::string> const& tokens);
	//returns true if position 2 in the GTF says "transcript"
	bool static is_next_transcript(std::vector<std::string> const& tokens);
	//returns true if position 2 in the GTF says "gene"
	bool static is_next_gene(std::vector<std::string> const& tokens);
};

class GTFParser__file_not_found_exception : public std::runtime_error {
public:
	GTFParser__file_not_found_exception(std::string error = "") : std::runtime_error(error) {};
};

#endif
