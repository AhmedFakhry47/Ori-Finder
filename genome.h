#ifndef GENOME_H_
#define GENOME_H_


char *sliced_str(char *genome, int i, unsigned short k);
unsigned char find_freq(char *genome, char *kmer);
unsigned char highest_freq(char *genome, unsigned char kmer_length);
#endif