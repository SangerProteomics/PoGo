#ifndef COORDINATEWRAPPER_H
#define COORDINATEWRAPPER_H

#include "ProteinEntry.h"


//forward declarations to break circular dependencies.
class KmerMap;
class ExistingPeptides;
class PeptideEntry;


class CoordinateWrapper {
public:
	//ctr / dtr
	CoordinateWrapper(void);
	~CoordinateWrapper(void);

	//looks up a ProteinEntry given a fasta header and returns a reference to that entry.
	ProteinEntry& lookup_entry(std::string fastaHeader);
	//adds a ProteinEntry.
	void add(ProteinEntry entry);
	//returns the number of ProteinEntry elements currently in the CorrdinateWrapper.
	int size() const;

	void renew();
	
	//reads and parses a fasta file and adds all of them to the CoordinateWrapper.
	void read_fasta_file(std::string file);
	//adds all previously added proteins to the given KmerMap. 
	void add_all_proteins_to_kmer_map(KmerMap& kmerMap);
	//adds a peptide to the existing peptides list. this is used in the ResultParser so 
	//that already found peptides dont have to be mapped again.
	void add_to_existing_peptides(std::string const& peptideSequence, PeptideEntry* peptideEntry) const;
	//returns true if the peptide was found before.
	bool peptide_already_exists(std::string const& peptideSequence) const;
	//gets a reference to the already existing peptides 
	//used for adding PTMs and tags.
	std::vector<PeptideEntry*>& get_existing_peptides_at(std::string const& peptideSequence) const;

private:
	//holds fasta headers and the associated ProteinEntry objects.
	std::map<std::string, ProteinEntry> m_map;
	//pointer to the existing_peptides
	//ExistingPeptides holds information about previously read peptides.
	ExistingPeptides* m_existing_peptides;

};

#endif
