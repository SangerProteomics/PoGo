#include "Globals.h"

unsigned int GENOME_MAPPER_GLOBALS::PEPTIDE_MAPPER::KMER_LENGTH(5);
unsigned int GENOME_MAPPER_GLOBALS::PEPTIDE_MAPPER::ALLOWED_MISMATCHES(0);
std::vector<char> GENOME_MAPPER_GLOBALS::PEPTIDE_MAPPER::ALLOWED_AMINO_ACIDS = { 'A', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'Y' };
bool GENOME_MAPPER_GLOBALS::PEPTIDE_MAPPER::ONE_IN_FIVE_MODE(false);
bool GENOME_MAPPER_GLOBALS::PEPTIDE_MAPPER::CHR_FROM_GENOME_FASTA(false);

std::string GENOME_MAPPER_GLOBALS::ID::GTF_GENE_ID("gene_id \"");
std::string GENOME_MAPPER_GLOBALS::ID::GTF_TRANSCRIPT_ID("transcript_id \"");
std::string GENOME_MAPPER_GLOBALS::ID::GTF_EXON_ID("exon_id \"");
std::string GENOME_MAPPER_GLOBALS::ID::FASTA_GENE_ID("gene:");
std::string GENOME_MAPPER_GLOBALS::ID::FASTA_TRANSCRIPT_ID("transcript:");
